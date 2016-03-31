#include <STEPControl_Reader.hxx>
#include <Interface_Static.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <TopExp_Explorer.hxx>
#include <BRep_Builder.hxx>
#include <TopExp.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_ListIteratorOfListOfShape.hxx>

#include <chrono>
#include "occapi.h"

static TopoDS_Shape aResShape;


/* Returns the orientation of a face within its parent body. */
int face_orientation(TopoDS_Face &face, double *orientation)
{
	TopAbs_Orientation orient = face.Orientation();

	/*
		TopAbs_FORWARD
		TopAbs_REVERSED
		TopAbs_INTERNAL
		TopAbs_EXTERNAL
	*/

	if (orient > 0) {
		*orientation = 1.0;
	} else {
		*orientation = -1.0;
	}

	return 0;
}

double dot_product(Standard_Real v1_x,
                   Standard_Real v1_y,
                   Standard_Real v1_z,
                   Standard_Real v2_x,
                   Standard_Real v2_y,
                   Standard_Real v2_z)
{
	double dot = 0.0;

	dot += v1_x * v2_x;
	dot += v1_y * v2_y;
	dot += v1_z * v2_z;

	return dot;
}

void cross_product(Standard_Real v1_x,
                   Standard_Real v1_y,
                   Standard_Real v1_z,
                   Standard_Real v2_x,
                   Standard_Real v2_y,
                   Standard_Real v2_z,
                   double v[3]) {
	double vt[3];

	vt[0] = v1_y * v2_z - v1_z * v2_y;
	vt[1] = v1_z * v2_x - v1_x * v2_z;
	vt[2] = v1_x * v2_y - v1_y * v2_x;

	v[0] = vt[0];
	v[1] = vt[1];
	v[2] = vt[2];
}

int classify_at_t(TopoDS_Face &face1,
                  TopoDS_Face &face2,
                  TopoDS_Edge &edge,
                  double orient_line_in_face1,
                  double t,
                  int *class)
{
	double *uv = NULL;
	double *normal1 = NULL;
	double *normal2 = NULL;
	double orient1;
	double orient2;
	double cross[3];
	double tangent[3];
	double dxtt, dytt, dztt;
	double cosine;
	int convex;

	// ERR(cficCalcFaceUVFromEdgeT(face1, line, t, &uv));
	// ERR(cficCalcFaceNormalAtUV(face1, uv, &normal1));
	// cficFree(uv);
	// uv = NULL;
	// ERR(cficCalcFaceUVFromEdgeT(face2, line, t, &uv));
	// ERR(cficCalcFaceNormalAtUV(face2, uv, &normal2));

	// get bounds of face
	Standard_Real umin, umax, vmin, vmax;

	BRepTools::UVBounds(face1, edge, umin, umax, vmin, vmax);	// create surface
	Handle(Geom_Surface) surf1 = BRep_Tool::Surface(face1);	// get surface properties
	GeomLProp_SLProps props1(surf1, umin, vmin, 1, 0.01);	// get surface normal
	gp_Dir norm1 = props1.Normal();	// check orientation
	if (face1.Orientation() == TopAbs_REVERSED) norm1.Reverse();

	BRepTools::UVBounds(face2, edge, umin, umax, vmin, vmax);	// create surface
	Handle(Geom_Surface) surf2 = BRep_Tool::Surface(face2);	// get surface properties
	GeomLProp_SLProps props2(surf2, umin, vmin, 1, 0.01);	// get surface normal
	gp_Dir norm2 = props2.Normal();	// check orientation
	if (face2.Orientation() == TopAbs_REVERSED) norm2.Reverse();

	/* Take account of the orientations of the faces within their parent body -
	 * reverse the normal if the face is used in a negative sense. */
	ERR(face_orientation(face1, &orient1));
	ERR(face_orientation(face2, &orient2));

	// {
	// 	int j;
	// 	for (j = 0; j < 3; ++j) {
	// 		normal1[j] *= orient1;
	// 		normal2[j] *= orient2;
	// 	}
	// }

	norm1.X() *= orient1;
	norm1.Y() *= orient1;
	norm1.Z() *= orient1;

	norm2.X() *= orient2;
	norm2.Y() *= orient2;
	norm2.Z() *= orient2;

	/* Find the cosine of the angle between the normals, to determine if the
	 * angle is flat. */
	cosine = dot_product(norm1.X(),
	                     norm1.Y(),
	                     norm1.Z(),
	                     norm2.X(),
	                     norm2.Y(),
	                     norm2.Z());

	/* Take the cross-product of the two normals, and compare it with the line
	 * tangent, to see if it points in the same direction. This allows us to
	 * tell concavity from convexity.
	 * The sense of the line in the parent faces, and the orientation of the
	 * parent faces in the bodies, must be taken into account. */
	cross_product(norm1.X(),
	              norm1.Y(),
	              norm1.Z(),
	              norm2.X(),
	              norm2.Y(),
	              norm2.Z(),
	              cross);

	cficCalcLineDerivAtT(line, t, tangent + 0, tangent + 1,
	                     tangent + 2, &dxtt, &dytt, &dztt);

	// todo:
	convex = dot_product(cross[0], cross[1], cross[2], tangent) * orient_line_in_face1 * orient1 < 0.0;

	if (fabs(cosine) > cos(M_PI / 40.0)) {
		/* Angle < 4.5 degrees; call this flat. */
		*class = TANGENTIAL;
	} else if (convex) {
		*class = CONVEX;
	} else {
		*class = CONCAVE;
	}

// cleanup:
// 	if (uv) cficFree(uv);
// 	if (normal1) cficFree(normal1);
// 	if (normal2) cficFree(normal2);

	return result;
}

/* Classifies a given line as CONCAVE, CONVEX, TANGENTIAL or MIXED. */
int classify(TopoDS_Face &Face1, TopoDS_Face &Face2,  TopoDS_Edge &edge, int *class)
{
	int num_parents;
	int *parent_types = NULL;
	int *signed_parent_numbers = NULL;
	int magic;
	int num_parents2;
	int orient_line_in_face1;
	int i;

	*class = 0;

	/* Check the classification at 11 points along the edge. */
	for (i = 0; i <= 10; ++i) {
		int class2;

		classify_at_t(face1, face2, edge, orient_line_in_face1, i * 0.1, &class2);

		/* If we have no classification for this edge yet, use this
		   classification. Otherwise, if the current classification is
		   tangential, override it with the new one, or if the current and new
		   classifications disagree, mark this edge as MIXED. */
		if (*class == 0) {
			*class = class2;
		} else if (*class == class2) {
			/* Do nothing. */
		} else if (*class == TANGENTIAL) {
			*class = class2;
		} else {
			*class = MIXED;
		}
	}

	return 0;
}

extern "C" int occ_get_line_number(char *filename)
{
	int n = 0;
	STEPControl_Reader aReader;

	Interface_Static::SetCVal("xstep.cascade.unit", "mm");
	Interface_Static::SetIVal("read.step.nonmanifold", 1);
	Interface_Static::SetIVal("read.step.product.mode", 1);
	Interface_Static::SetRVal("read.precision.val", 0.01);

	if (aReader.ReadFile(filename) != IFSelect_RetDone) {
		printf("ERROR: open model [%s] failed\n", filename);
	} else {
		printf("LOG: open model [%s] success\n", filename);
	}

	int nbr = aReader.NbRootsForTransfer();
	printf("LOG: aReader.NbRootsForTransfer() [%d]\n", nbr);

	int mod = nbr / 10 + 1;
	for (int n = 1; n <= nbr; n++) {
		Standard_Boolean ok = aReader.TransferRoot(n);
		Standard_Integer nbs = aReader.NbShapes();
		if (!ok || nbs == 0) {
			continue; // skip empty root
		}
	}

	BRep_Builder B;
	TopoDS_Compound compound;
	B.MakeCompound(compound);

	int nbs = aReader.NbShapes();
	printf("LOG: aReader.NbShapes() [%d]\n", nbs);

	for (int i = 1; i <= nbs; i++) {
		const TopoDS_Shape& aShape = aReader.Shape(i);
		B.Add(compound, aShape);
	}

	aResShape = compound;

	// todo: better calculate line number method?
	TopExp_Explorer expEdge(aResShape, TopAbs_EDGE);
	while (expEdge.More()) {
		n++;
		expEdge.Next();
	}

	return n;
}


extern "C" int occ_write_edge_face_class_evaluate(FILE *fs)
{
	auto start = std::chrono::high_resolution_clock::now();

	TopTools_IndexedDataMapOfShapeListOfShape aEdgeFaceMap;
	TopExp::MapShapesAndAncestors(aResShape, TopAbs_EDGE, TopAbs_FACE, aEdgeFaceMap);

	TopTools_IndexedMapOfShape faceMap;
	TopExp::MapShapes(aResShape, TopAbs_FACE, faceMap);

	Standard_Integer i, nE = aEdgeFaceMap.Extent();
	printf("Log: Face Edge map number => %d\n", nE);

	for (i = 1; i <= nE; ++i) {
		const TopTools_ListOfShape& aListOfFaces = aEdgeFaceMap.FindFromIndex(i);

		Standard_Integer numOfFace = aListOfFaces.Extent();
		if (2 != numOfFace) {
			printf("ERROR: index [%d] parent face number is [%d]\n", i, numOfFace);
			continue;
		}

		TopTools_ListIteratorOfListOfShape itFace;
		for (itFace.Initialize(aListOfFaces); itFace.More(); itFace.Next()) {
			const TopoDS_Shape& shapeFace = itFace.Value();
			Standard_Integer faceIndex = faceMap.FindIndex(shapeFace);
		}
	}

	auto finish = std::chrono::high_resolution_clock::now();
	auto time_elapsed_nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
	printf("LOG: Time taken (nanoseconds): %ld\n", time_elapsed_nanos);

	return 0;
}

extern "C" int occ_write_edge_face_class(FILE *fs)
{
	return 0;
}