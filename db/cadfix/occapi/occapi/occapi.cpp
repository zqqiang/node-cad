#include <STEPControl_Reader.hxx>
#include <Interface_Static.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <TopExp_Explorer.hxx>
#include <BRep_Builder.hxx>

#include "occapi.h"

static TopoDS_Shape aResShape;

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
	TopTools_IndexedDataMapOfShapeListOfShape aEdgeFaceMap;
	TopExp::MapShapesAndAncestors(aResShape, TopAbs_EDGE, TopAbs_FACE, aEdgeFaceMap);

	Standard_Integer i, nE = aEdgeFaceMap.Extent();
	for (int i = 1; i <= nE; ++i) {
		const TopTools_ListOfShape& aListOfFaces = aEdgeFaceMap.FindFromIndex(i);

		Standard_Integer numOfFace = aListOfFaces.Extent();
		if (2 != numOfFace) {
			printf("index [%d] parent face number is [%d]\n", i, numOfFace);
		}

		TopTools_ListIteratorOfListOfShape itFace;
		for (itFace.Initialize(aListOfFaces); itFace.More(); itFace.Next()) {
			const TopoDS_Shape& shapeFace = itFace.value();

		}
	}

	return 0;
}

extern "C" int occ_write_edge_face_class(FILE *fs)
{
	return 0;
}