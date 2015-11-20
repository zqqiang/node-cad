// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepLib_MakeShape_HeaderFile
#define _BRepLib_MakeShape_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepLib_Command.hxx>
#include <BRepLib_ShapeModification.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
class StdFail_NotDone;
class TopoDS_Shape;
class TopoDS_Face;
class TopTools_ListOfShape;
class TopoDS_Edge;


//! This    is  the  root     class for     all  shape
//! constructions.  It stores the result.
//!
//! It  provides deferred methods to trace the history
//! of sub-shapes.
class BRepLib_MakeShape  : public BRepLib_Command
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! This is  called by  Shape().  It does  nothing but
  //! may be redefined.
  Standard_EXPORT   void Build() ;
  
  Standard_EXPORT  const  TopoDS_Shape& Shape()  const;
Standard_EXPORT operator TopoDS_Shape() const;
  
  //! returns the status of the Face after
  //! the shape creation.
  Standard_EXPORT virtual   BRepLib_ShapeModification FaceStatus (const TopoDS_Face& F)  const;
  
  //! Returns True if the Face generates new topology.
  Standard_EXPORT virtual   Standard_Boolean HasDescendants (const TopoDS_Face& F)  const;
  
  //! returns the list of generated Faces.
  Standard_EXPORT virtual  const  TopTools_ListOfShape& DescendantFaces (const TopoDS_Face& F) ;
  
  //! returns the number of surfaces
  //! after the shape creation.
  Standard_EXPORT virtual   Standard_Integer NbSurfaces()  const;
  
  //! Return the faces created for surface I.
  Standard_EXPORT virtual  const  TopTools_ListOfShape& NewFaces (const Standard_Integer I) ;
  
  //! returns a list of the created faces
  //! from the edge <E>.
  Standard_EXPORT virtual  const  TopTools_ListOfShape& FacesFromEdges (const TopoDS_Edge& E) ;




protected:

  
  Standard_EXPORT BRepLib_MakeShape();


  TopoDS_Shape myShape;
  TopTools_ListOfShape myGenFaces;
  TopTools_ListOfShape myNewFaces;
  TopTools_ListOfShape myEdgFaces;


private:





};







#endif // _BRepLib_MakeShape_HeaderFile
