// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TopOpeBRepDS_Edge3dInterferenceTool_HeaderFile
#define _TopOpeBRepDS_Edge3dInterferenceTool_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Integer.hxx>
#include <TopTrans_SurfaceTransition.hxx>
#include <Standard_Real.hxx>
#include <Standard_Boolean.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Handle_TopOpeBRepDS_Interference.hxx>
class TopoDS_Shape;
class TopOpeBRepDS_Interference;


//! a tool computing edge / face complex transition,
//! Interferences of edge reference are given by
//! I = (T on face, G = point or vertex, S = edge)
class TopOpeBRepDS_Edge3dInterferenceTool 
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT TopOpeBRepDS_Edge3dInterferenceTool();
  
  Standard_EXPORT   void InitPointVertex (const Standard_Integer IsVertex, const TopoDS_Shape& VonOO) ;
  
  Standard_EXPORT   void Init (const TopoDS_Shape& Eref, const TopoDS_Shape& E, const TopoDS_Shape& F, const Handle(TopOpeBRepDS_Interference)& I) ;
  
  Standard_EXPORT   void Add (const TopoDS_Shape& Eref, const TopoDS_Shape& E, const TopoDS_Shape& F, const Handle(TopOpeBRepDS_Interference)& I) ;
  
  Standard_EXPORT   void Transition (const Handle(TopOpeBRepDS_Interference)& I)  const;




protected:





private:



  Standard_Integer myFaceOriented;
  TopTrans_SurfaceTransition myTool;
  Standard_Real myTole;
  Standard_Boolean myrefdef;
  Standard_Integer myIsVertex;
  TopoDS_Shape myVonOO;
  gp_Pnt myP3d;
  gp_Dir myTgtref;


};







#endif // _TopOpeBRepDS_Edge3dInterferenceTool_HeaderFile
