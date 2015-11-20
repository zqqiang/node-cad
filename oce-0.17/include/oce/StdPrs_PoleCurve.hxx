// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StdPrs_PoleCurve_HeaderFile
#define _StdPrs_PoleCurve_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Prs3d_Root.hxx>
#include <Handle_Prs3d_Presentation.hxx>
#include <Handle_Prs3d_Drawer.hxx>
#include <Standard_Boolean.hxx>
#include <Quantity_Length.hxx>
#include <Standard_Integer.hxx>
class Prs3d_Presentation;
class Adaptor3d_Curve;
class Prs3d_Drawer;


//! A framework to provide display of Bezier or BSpline curves
//! (by drawing a broken line linking the poles of the curve).
class StdPrs_PoleCurve  : public Prs3d_Root
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Defines display of BSpline and Bezier curves.
  //! Adds the 3D curve aCurve to the
  //! StdPrs_PoleCurve algorithm. This shape is found in
  //! the presentation object aPresentation, and its display
  //! attributes are set in the attribute manager aDrawer.
  //! The curve object from Adaptor3d provides data from
  //! a Geom curve. This makes it possible to use the
  //! surface in a geometric algorithm.
  Standard_EXPORT static   void Add (const Handle(Prs3d_Presentation)& aPresentation, const Adaptor3d_Curve& aCurve, const Handle(Prs3d_Drawer)& aDrawer) ;
  
  //! returns true if the distance between the point (X,Y,Z) and the
  //! broken line made of the poles is less then aDistance.
  Standard_EXPORT static   Standard_Boolean Match (const Quantity_Length X, const Quantity_Length Y, const Quantity_Length Z, const Quantity_Length aDistance, const Adaptor3d_Curve& aCurve, const Handle(Prs3d_Drawer)& aDrawer) ;
  
  //! returns the pole  the most near of the point (X,Y,Z) and
  //! returns its range. The distance between the pole and
  //! (X,Y,Z) must be less then aDistance. If no pole corresponds, 0 is returned.
  Standard_EXPORT static   Standard_Integer Pick (const Quantity_Length X, const Quantity_Length Y, const Quantity_Length Z, const Quantity_Length aDistance, const Adaptor3d_Curve& aCurve, const Handle(Prs3d_Drawer)& aDrawer) ;




protected:





private:





};







#endif // _StdPrs_PoleCurve_HeaderFile
