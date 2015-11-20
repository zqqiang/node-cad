# - Config file for the OCE package
# It defines the following variables
#  OCE_INCLUDE_DIRS - include directory for OCE
#  OCE_LIBRARIES    - all libraries to link against (warning, may be slower than just specify the used libs)
#  OCE_ALL_FOUND    - set to TRUE if all requested COMPONENTS are specified (see below), false otherwise
#  OCE_MISSING_TOOLKITS - when OCE_ALL_FOUND is FALSE, contains a list of missing toolkits
#  OCE_ALL_BUILT_MODULES - the list of source directories compiled (mostly useful when running swig to generate wrappers)
#
# If COMPONENTS is specified in the find_package() commands, it contains
# a list of toolkit modules which are requested.  For each component,
# OCE_<toolkit>_FOUND is set to TRUE or FALSE.
# Warning: <toolkit> is case-sensitive, for instance TKernel.
# For convenience, OCE_ALL_FOUND is set to TRUE if all
# toolkits are found, otherwise FALSE.  In the latter case,
# OCE_MISSING_TOOLKITS contains the list of missing toolkits.

# Tell the user project where to find our headers and libraries
get_filename_component(SELF_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)

set(OCE_INCLUDE_DIRS "${SELF_DIR}/../include/oce")
set(OCE_LIBRARIES "TKernel;TKMath;TKG2d;TKG3d;TKGeomBase;TKBRep;TKGeomAlgo;TKTopAlgo;TKPrim;TKBO;TKHLR;TKMesh;TKShHealing;TKXMesh;TKBool;TKFillet;TKFeat;TKOffset;TKCDF;PTKernel;TKLCAF;FWOSPlugin;TKPShape;TKBinL;TKXmlL;TKPLCAF;TKTObj;TKShapeSchema;TKStdLSchema;TKSTL;TKXSBase;TKSTEPBase;TKIGES;TKSTEPAttr;TKSTEP209;TKSTEP")
set(OCE_ALL_BUILT_MODULES "FSD;MMgt;OSD;Plugin;Quantity;Resource;SortTools;Standard;StdFail;Storage;TColStd;TCollection;TShort;Units;UnitsAPI;IncludeLibrary;Dico;NCollection;Message;math;ElCLib;ElSLib;BSplCLib;BSplSLib;PLib;Precision;GeomAbs;Poly;CSLib;Convert;Bnd;BVH;gp;TColgp;TopLoc;Expr;ExprIntrp;Geom2d;LProp;TColGeom2d;Adaptor2d;Geom2dLProp;Geom2dAdaptor;GProp;Geom;TColGeom;GeomAdaptor;AdvApprox;GeomLProp;Adaptor3d;LProp3d;TopAbs;ProjLib;GeomProjLib;GCPnts;CPnts;Approx;AppParCurves;FEmTool;AppCont;Extrema;IntAna;IntAna2d;GeomConvert;AdvApp2Var;GeomLib;Geom2dConvert;Hermit;BndLib;AppDef;GeomTools;GC;GCE2d;gce;TopoDS;TopExp;TopTools;BRep;BRepLProp;BRepAdaptor;BRepTools;Hatch;GeomInt;IntStart;IntWalk;IntImp;IntCurveSurface;IntSurf;IntPatch;Geom2dInt;IntImpParGen;IntRes2d;IntCurve;TopTrans;Intf;ApproxInt;GccAna;GccEnt;GccInt;GccIter;GccGeo;HatchGen;Geom2dHatch;Law;AppBlend;Plate;GeomPlate;LocalAnalysis;GeomAPI;GeomFill;Geom2dAPI;Geom2dGcc;FairCurve;NLPlate;IntPolyh;TopClass;IntCurvesFace;MAT;MAT2d;Bisector;BRepMAT2d;BRepCheck;BRepBndLib;BRepExtrema;BRepClass;BRepClass3d;BRepLib;BRepGProp;BRepIntCurveSurface;BRepTopAdaptor;BRepBuilderAPI;BRepApprox;BRepPrim;Primitives;BRepSweep;Sweep;BRepPrimAPI;IntTools;BRepAlgoAPI;BOPCol;BOPInt;BOPDS;BOPAlgo;BOPTools;HLRTopoBRep;HLRBRep;HLRAlgo;HLRAppli;Intrv;TopBas;TopCnx;Contap;BRepMesh;ShapeBuild;ShapeExtend;ShapeConstruct;ShapeCustom;ShapeAnalysis;ShapeFix;ShapeUpgrade;ShapeAlgo;ShapeProcess;ShapeProcessAPI;XBRepMesh;TopOpeBRep;TopOpeBRepDS;TopOpeBRepBuild;TopOpeBRepTool;BRepAlgo;BRepFill;BRepProj;ChFiDS;ChFi2d;ChFi3d;ChFiKPart;Blend;BRepBlend;BlendFunc;BRepFilletAPI;FilletSurf;LocOpe;BRepFeat;BRepOffsetAPI;Draft;BRepOffset;BiTgte;CDM;PCDM;CDF;UTL;LDOM;DBC;PCollection;PColStd;PMMgt;PShort;PStandard;PTColStd;ObjMgt;TDF;TDataStd;TFunction;TDocStd;AppStdL;FWOSDriver;PBRep;PTopoDS;PGeom;PGeom2d;PPoly;PColgp;PTopLoc;PColPGeom;PColPGeom2d;MgtBRep;MgtGeom;MgtGeom2d;MgtPoly;MgtTopLoc;MgtTopoDS;BinMDF;BinMDataStd;BinMFunction;BinMDocStd;BinObjMgt;BinLDrivers;XmlLDrivers;XmlMDF;XmlMDataStd;XmlMDocStd;XmlMFunction;XmlObjMgt;PDF;PDataStd;PFunction;PDocStd;MDF;MDataStd;MFunction;MDocStd;TObj;ShapeSchema;PCDMShape;StdLSchema;StdLDrivers;StlMesh;StlAPI;StlTransfer;RWStl;Interface;Transfer;IFGraph;IFSelect;TransferBRep;XSControl;StepData;StepFile;HeaderSection;RWHeaderSection;APIHeaderSection;StepSelect;UnitsMethods;XSAlgo;LibCtl;MoniTool;StepBasic;RWStepBasic;StepRepr;RWStepRepr;StepGeom;RWStepGeom;StepShape;RWStepShape;IGESData;IGESFile;IGESBasic;IGESGraph;IGESGeom;IGESDimen;IGESDraw;IGESSolid;IGESDefs;IGESAppli;IGESConvGeom;IGESSelect;IGESToBRep;GeomToIGES;Geom2dToIGES;BRepToIGES;BRepToIGESBRep;IGESControl;StepVisual;RWStepVisual;StepDimTol;RWStepDimTol;StepElement;StepFEA;RWStepElement;RWStepFEA;StepAP214;RWStepAP214;StepAP203;RWStepAP203;STEPConstruct;STEPEdit;GeomToStep;StepToGeom;StepToTopoDS;TopoDSToStep;STEPControl;STEPSelections;StepAP209")
include("${SELF_DIR}/OCE-libraries.cmake")

set(OCE_ALL_FOUND true)
if(OCE_FIND_COMPONENTS)
	foreach(toolkit ${OCE_FIND_COMPONENTS})
		if(TARGET ${toolkit})
			set(OCE_${toolkit}_FOUND true)
		else(TARGET ${toolkit})
			set(OCE_ALL_FOUND false)
			set(OCE_${toolkit}_FOUND false)
			set(OCE_MISSING_TOOLKITS ${OCE_MISSING_TOOLKITS} ${toolkit})
			if(OCE_FIND_REQUIRED)
				message(FATAL_ERROR "OCE ${toolkit} not available.")
			endif(OCE_FIND_REQUIRED)
		endif(TARGET ${toolkit})
	endforeach(toolkit ${OCE_FIND_COMPONENTS})
endif(OCE_FIND_COMPONENTS)
