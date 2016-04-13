#include <STEPControl_Reader.hxx>
#include <Interface_Static.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <TopExp_Explorer.hxx>
#include <BRep_Builder.hxx>
#include <BRepTools.hxx>
#include <TopExp.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_ListIteratorOfListOfShape.hxx>
#include <GeomLProp_SLProps.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <TopoDS.hxx>

#include <chrono>
#include "occapi.h"

static TopoDS_Shape aResShape;

enum {
	CONCAVE = 1,
	CONVEX,
	TANGENTIAL,
	MIXED
};

/* Returns the orientation of a face within its parent body. */
int face_orientation(const TopoDS_Face &face, double *orientation)
{
	TopAbs_Orientation orient = face.Orientation();

	/*
		TopAbs_FORWARD
		TopAbs_REVERSED
		TopAbs_INTERNAL
		TopAbs_EXTERNAL
	*/

	if (TopAbs_FORWARD == orient) {
		printf("orient [%s]\n", "TopAbs_FORWARD");
	} else if (TopAbs_REVERSED == orient) {
		printf("orient [%s]\n", "TopAbs_REVERSED");
	} else if (TopAbs_INTERNAL == orient) {
		printf("orient [%s]\n", "TopAbs_INTERNAL");
	} else if (TopAbs_EXTERNAL == orient) {
		printf("orient [%s]\n", "TopAbs_EXTERNAL");
	} else {
		printf("orient [%s]\n", "TopAbs_XXX");
	}

	if (TopAbs_FORWARD == orient) {
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

int classify_at_t(const TopoDS_Face &face1,
                  const TopoDS_Face &face2,
                  const TopoDS_Edge &edge,
                  double orient_line_in_face1,
                  double t,
                  int *category)
{
	double *uv = NULL;
	double *normal1 = NULL;
	double *normal2 = NULL;
	double orient1;
	double orient2;
	double cross[3];
	// double tangent[3];
	// double dxtt, dytt, dztt;
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
	face_orientation(face1, &orient1);
	face_orientation(face2, &orient2);

	printf("face1 orient1 [%f]\n", orient1);
	printf("face2 orient2 [%f]\n", orient2);

	// {
	// 	int j;
	// 	for (j = 0; j < 3; ++j) {
	// 		normal1[j] *= orient1;
	// 		normal2[j] *= orient2;
	// 	}
	// }

	Standard_Real x1, y1, z1, x2, y2, z2;

	printf("norm1.X() [%f]\n", norm1.X());
	printf("norm1.Y() [%f]\n", norm1.Y());
	printf("norm1.Z() [%f]\n", norm1.Z());

	printf("norm2.Y() [%f]\n", norm2.Y());
	printf("norm2.X() [%f]\n", norm2.X());
	printf("norm2.Z() [%f]\n", norm2.Z());

	x1 = norm1.X() * orient1;
	y1 = norm1.Y() * orient1;
	z1 = norm1.Z() * orient1;

	x2 = norm2.X() * orient2;
	y2 = norm2.Y() * orient2;
	z2 = norm2.Z() * orient2;

	/* Find the cosine of the angle between the normals, to determine if the
	 * angle is flat. */
	cosine = dot_product(x1,
	                     y1,
	                     z1,
	                     x2,
	                     y2,
	                     z2);

	/* Take the cross-product of the two normals, and compare it with the line
	 * tangent, to see if it points in the same direction. This allows us to
	 * tell concavity from convexity.
	 * The sense of the line in the parent faces, and the orientation of the
	 * parent faces in the bodies, must be taken into account. */
	cross_product(x1,
	              y1,
	              z1,
	              x2,
	              y2,
	              z2,
	              cross);

	// cficCalcLineDerivAtT(line, t, tangent + 0, tangent + 1,
	//                      tangent + 2, &dxtt, &dytt, &dztt);

	// convex = dot_product(cross, tangent) * orient_line_in_face1 * orient1 < 0.0;

	BRepAdaptor_Curve curve;
	curve.Initialize(edge);

	gp_Pnt P;
	gp_Vec V1, V2;
	curve.D2(t, P, V1, V2);

	printf("cross [%f, %f, %f]\n", cross[0], cross[1], cross[2]);
	printf("V1 [%f, %f, %f]\n", V1.X(), V1.Y(), V1.Z());
	printf("orient_line_in_face1 [%f]\n", orient_line_in_face1);

	convex = dot_product(cross[0], cross[1], cross[2], V1.X(), V1.Y(), V1.Z()) * orient_line_in_face1 * orient1 < 0.0;

	printf("cosine [%f], cos(M_PI / 40.0) [%f]\n", cosine, cos(M_PI / 40.0));

	if (fabs(cosine) > cos(M_PI / 40.0)) {
		/* Angle < 4.5 degrees; call this flat. */
		*category = TANGENTIAL;
	} else if (convex) {
		*category = CONVEX;
	} else {
		*category = CONCAVE;
	}

// cleanup:
// 	if (uv) cficFree(uv);
// 	if (normal1) cficFree(normal1);
// 	if (normal2) cficFree(normal2);

	return 0;
}

/* Classifies a given line as CONCAVE, CONVEX, TANGENTIAL or MIXED. */
int classify(const TopoDS_Face &face1, const TopoDS_Face &face2,  const TopoDS_Edge &edge, int *category)
{
	// int num_parents;
	int *parent_types = NULL;
	// int *signed_parent_numbers = NULL;
	// int magic;
	// int num_parents2;
	double orient_line_in_face1;
	int i;

	*category = 0;

	orient_line_in_face1 = (face1.Orientation() == TopAbs_FORWARD) ? 1.0 : -1.0;
	if (face1.Orientation() != TopAbs_FORWARD && face1.Orientation() != TopAbs_REVERSED ) {
		printf("ERROR: face1.Orientation() => %d\n", face1.Orientation());
	}

	/* Check the classification at 11 points along the edge. */
	for (i = 0; i <= 10; ++i) {
		int class2;

		classify_at_t(face1, face2, edge, orient_line_in_face1, i * 0.1, &class2);

		/* If we have no classification for this edge yet, use this
		   classification. Otherwise, if the current classification is
		   tangential, override it with the new one, or if the current and new
		   classifications disagree, mark this edge as MIXED. */
		if (*category == 0) {
			*category = class2;
		} else if (*category == class2) {
			/* Do nothing. */
		} else if (*category == TANGENTIAL) {
			*category = class2;
		} else {
			*category = MIXED;
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
	int category;
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

		itFace.Initialize(aListOfFaces);

		const TopoDS_Face& face1 = TopoDS::Face(itFace.Value());
		Standard_Integer faceIndex1 = faceMap.FindIndex(face1);

		itFace.Next();
		const TopoDS_Face& face2 = TopoDS::Face(itFace.Value());
		Standard_Integer faceIndex2 = faceMap.FindIndex(face2);

		const TopoDS_Edge& edge = TopoDS::Edge(aEdgeFaceMap.FindKey(i));

		printf("face1 [%d], face2 [%d], edge [%d]\n", faceIndex1, faceIndex2, i);

		classify(face1, face2, edge, &category);
	}

	auto finish = std::chrono::high_resolution_clock::now();
	auto time_elapsed_nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
	printf("LOG: Time taken (nanoseconds): %ld\n", time_elapsed_nanos);

	fprintf (fs, "%ld\n", time_elapsed_nanos);
	return 0;
}

extern "C" int occ_write_edge_face_class(FILE *fs)
{
	int category;

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

		itFace.Initialize(aListOfFaces);

		const TopoDS_Face& face1 = TopoDS::Face(itFace.Value());
		Standard_Integer faceIndex1 = faceMap.FindIndex(face1);

		itFace.Next();
		const TopoDS_Face& face2 = TopoDS::Face(itFace.Value());
		Standard_Integer faceIndex2 = faceMap.FindIndex(face2);

		const TopoDS_Edge& edge = TopoDS::Edge(aEdgeFaceMap.FindKey(i));

		classify(face1, face2, edge, &category);

		fprintf (fs,
		         "%d,%d,%d,%d\n%d,%d,%d,%d\n",
		         i, faceIndex1, faceIndex2, category,
		         i, faceIndex2, faceIndex1, category);
	}

	return 0;
}