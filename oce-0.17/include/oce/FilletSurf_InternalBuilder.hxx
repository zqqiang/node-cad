// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _FilletSurf_InternalBuilder_HeaderFile
#define _FilletSurf_InternalBuilder_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <ChFi3d_FilBuilder.hxx>
#include <ChFi3d_FilletShape.hxx>
#include <Standard_Real.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
#include <Handle_ChFiDS_HElSpine.hxx>
#include <Handle_ChFiDS_Spine.hxx>
#include <Handle_BRepAdaptor_HSurface.hxx>
#include <Handle_Adaptor3d_TopolTool.hxx>
#include <math_Vector.hxx>
#include <Handle_BRepAdaptor_HCurve2d.hxx>
#include <TopAbs_Orientation.hxx>
#include <Handle_Geom_Surface.hxx>
#include <Handle_Geom_Curve.hxx>
#include <Handle_Geom2d_Curve.hxx>
#include <FilletSurf_StatusType.hxx>
#include <Handle_Geom_TrimmedCurve.hxx>
class TopoDS_Shape;
class TopTools_ListOfShape;
class ChFiDS_SequenceOfSurfData;
class ChFiDS_HElSpine;
class ChFiDS_Spine;
class BRepAdaptor_HSurface;
class Adaptor3d_TopolTool;
class BRepAdaptor_HCurve2d;
class Geom_Surface;
class TopoDS_Face;
class Geom_Curve;
class Geom2d_Curve;
class Geom_TrimmedCurve;


//! This class is private. It is  used by the class Builder
//! from FilletSurf. It computes geometric information about fillets.
class FilletSurf_InternalBuilder  : public ChFi3d_FilBuilder
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT FilletSurf_InternalBuilder(const TopoDS_Shape& S, const ChFi3d_FilletShape FShape = ChFi3d_Polynomial, const Standard_Real Ta = 1.0e-2, const Standard_Real Tapp3d = 1.0e-4, const Standard_Real Tapp2d = 1.0e-5);
  
  //! Initializes the contour with a list of Edges
  //! 0 : no problem
  //! 1 : empty list
  //! 2 : the edges are not G1
  //! 3 : two connected faces on a same support are not G1
  //! 4 : the  edge   is  not on  shape
  //! 5 :  NotSharpEdge: the  edge is not sharp
  Standard_EXPORT   Standard_Integer Add (const TopTools_ListOfShape& E, const Standard_Real R) ;
  
  Standard_EXPORT   void Perform() ;
  
  Standard_EXPORT   Standard_Boolean Done()  const;
  
  //! gives the number of NUBS surfaces  of the Fillet.
  Standard_EXPORT   Standard_Integer NbSurface()  const;
  
  //! gives the NUBS surface of index Index.
  Standard_EXPORT  const  Handle(Geom_Surface)& SurfaceFillet (const Standard_Integer Index)  const;
  
  //! gives  the  3d  tolerance reached during approximation
  //! of the surface of index Index
  Standard_EXPORT   Standard_Real TolApp3d (const Standard_Integer Index)  const;
  
  //! gives the first support  face relative to SurfaceFillet(Index);
  Standard_EXPORT  const  TopoDS_Face& SupportFace1 (const Standard_Integer Index)  const;
  
  //! gives the second support  face relative to SurfaceFillet(Index);
  Standard_EXPORT  const  TopoDS_Face& SupportFace2 (const Standard_Integer Index)  const;
  
  //! gives  the 3d curve  of SurfaceFillet(Index)  on SupportFace1(Index)
  Standard_EXPORT  const  Handle(Geom_Curve)& CurveOnFace1 (const Standard_Integer Index)  const;
  
  //! gives the     3d  curve of  SurfaceFillet(Index) on SupportFace2(Index)
  Standard_EXPORT  const  Handle(Geom_Curve)& CurveOnFace2 (const Standard_Integer Index)  const;
  
  //! gives the  PCurve associated to CurvOnSup1(Index)  on the support face
  Standard_EXPORT  const  Handle(Geom2d_Curve)& PCurveOnFace1 (const Standard_Integer Index)  const;
  
  //! gives the PCurve associated to CurveOnFace1(Index) on the Fillet
  Standard_EXPORT  const  Handle(Geom2d_Curve)& PCurve1OnFillet (const Standard_Integer Index)  const;
  
  //! gives the PCurve  associated to CurveOnSup2(Index) on  the  support face
  Standard_EXPORT  const  Handle(Geom2d_Curve)& PCurveOnFace2 (const Standard_Integer Index)  const;
  
  //! gives the PCurve  associated to CurveOnSup2(Index) on  the  fillet
  Standard_EXPORT  const  Handle(Geom2d_Curve)& PCurve2OnFillet (const Standard_Integer Index)  const;
  
  //! gives the parameter of the fillet  on the first edge.
  Standard_EXPORT   Standard_Real FirstParameter()  const;
  
  //! gives the  parameter of the fillet  on the last edge
  Standard_EXPORT   Standard_Real LastParameter()  const;
  
  Standard_EXPORT   FilletSurf_StatusType StartSectionStatus()  const;
  
  Standard_EXPORT   FilletSurf_StatusType EndSectionStatus()  const;
  
  Standard_EXPORT   void Simulate() ;
  
  Standard_EXPORT   Standard_Integer NbSection (const Standard_Integer IndexSurf)  const;
  
  Standard_EXPORT   void Section (const Standard_Integer IndexSurf, const Standard_Integer IndexSec, Handle(Geom_TrimmedCurve)& Circ)  const;




protected:

  
  //! This  method calculates the elements of construction of the
  //! fillet (constant or evolutive).
  Standard_EXPORT virtual   Standard_Boolean PerformSurf (ChFiDS_SequenceOfSurfData& SeqData, const Handle(ChFiDS_HElSpine)& Guide, const Handle(ChFiDS_Spine)& Spine, const Standard_Integer Choix, const Handle(BRepAdaptor_HSurface)& S1, const Handle(Adaptor3d_TopolTool)& I1, const Handle(BRepAdaptor_HSurface)& S2, const Handle(Adaptor3d_TopolTool)& I2, const Standard_Real MaxStep, const Standard_Real Fleche, const Standard_Real TolGuide, Standard_Real& First, Standard_Real& Last, const Standard_Boolean Inside, const Standard_Boolean Appro, const Standard_Boolean Forward, const Standard_Boolean RecOnS1, const Standard_Boolean RecOnS2, const math_Vector& Soldep, Standard_Integer& Intf, Standard_Integer& Intl) ;
  
  Standard_EXPORT virtual   void PerformSurf (ChFiDS_SequenceOfSurfData& SeqData, const Handle(ChFiDS_HElSpine)& Guide, const Handle(ChFiDS_Spine)& Spine, const Standard_Integer Choix, const Handle(BRepAdaptor_HSurface)& S1, const Handle(Adaptor3d_TopolTool)& I1, const Handle(BRepAdaptor_HCurve2d)& PC1, const Handle(BRepAdaptor_HSurface)& Sref1, const Handle(BRepAdaptor_HCurve2d)& PCref1, Standard_Boolean& Decroch1, const Handle(BRepAdaptor_HSurface)& S2, const Handle(Adaptor3d_TopolTool)& I2, const TopAbs_Orientation Or2, const Standard_Real MaxStep, const Standard_Real Fleche, const Standard_Real TolGuide, Standard_Real& First, Standard_Real& Last, const Standard_Boolean Inside, const Standard_Boolean Appro, const Standard_Boolean Forward, const Standard_Boolean RecP, const Standard_Boolean RecS, const Standard_Boolean RecRst, const math_Vector& Soldep) ;
  
  Standard_EXPORT virtual   void PerformSurf (ChFiDS_SequenceOfSurfData& SeqData, const Handle(ChFiDS_HElSpine)& Guide, const Handle(ChFiDS_Spine)& Spine, const Standard_Integer Choix, const Handle(BRepAdaptor_HSurface)& S1, const Handle(Adaptor3d_TopolTool)& I1, const TopAbs_Orientation Or1, const Handle(BRepAdaptor_HSurface)& S2, const Handle(Adaptor3d_TopolTool)& I2, const Handle(BRepAdaptor_HCurve2d)& PC2, const Handle(BRepAdaptor_HSurface)& Sref2, const Handle(BRepAdaptor_HCurve2d)& PCref2, Standard_Boolean& Decroch2, const Standard_Real MaxStep, const Standard_Real Fleche, const Standard_Real TolGuide, Standard_Real& First, Standard_Real& Last, const Standard_Boolean Inside, const Standard_Boolean Appro, const Standard_Boolean Forward, const Standard_Boolean RecP, const Standard_Boolean RecS, const Standard_Boolean RecRst, const math_Vector& Soldep) ;
  
  Standard_EXPORT virtual   void PerformSurf (ChFiDS_SequenceOfSurfData& Data, const Handle(ChFiDS_HElSpine)& Guide, const Handle(ChFiDS_Spine)& Spine, const Standard_Integer Choix, const Handle(BRepAdaptor_HSurface)& S1, const Handle(Adaptor3d_TopolTool)& I1, const Handle(BRepAdaptor_HCurve2d)& PC1, const Handle(BRepAdaptor_HSurface)& Sref1, const Handle(BRepAdaptor_HCurve2d)& PCref1, Standard_Boolean& Decroch1, const TopAbs_Orientation Or1, const Handle(BRepAdaptor_HSurface)& S2, const Handle(Adaptor3d_TopolTool)& I2, const Handle(BRepAdaptor_HCurve2d)& PC2, const Handle(BRepAdaptor_HSurface)& Sref2, const Handle(BRepAdaptor_HCurve2d)& PCref2, Standard_Boolean& Decroch2, const TopAbs_Orientation Or2, const Standard_Real MaxStep, const Standard_Real Fleche, const Standard_Real TolGuide, Standard_Real& First, Standard_Real& Last, const Standard_Boolean Inside, const Standard_Boolean Appro, const Standard_Boolean Forward, const Standard_Boolean RecP1, const Standard_Boolean RecRst1, const Standard_Boolean RecP2, const Standard_Boolean RecRst2, const math_Vector& Soldep) ;




private:





};







#endif // _FilletSurf_InternalBuilder_HeaderFile
