#include <STEPControl_Reader.hxx>

#include "occapi.h"

extern "C" int occ_get_line_number(char *filename)
{
	int n = 0;
	STEPControl_Reader aReader;

	Interface_Static::SetCVal("xstep.cascade.unit", "mm");
	Interface_Static::SetIVal("read.step.nonmanifold", 1);
	Interface_Static::SetIVal("read.step.product.mode", 1);
	Interface_Static::SetRVal("read.precision.val", 0.01);

	if (aReader.ReadFile(filename) != IFSelect_RetDone) {
		puts("LOG: open model failed");
	} else {
		puts("LOG: open model success");
	}

	// todo: better calculate line number method?
	TopoDS_Shape aResShape;
	TopExp_Explorer expEdge(aResShape, TopAbs_EDGE);
	while (expEdge.More()) {
		n++;
		expEdge.Next();
	}

	return n;
}