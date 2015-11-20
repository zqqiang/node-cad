// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepGeom_Axis1Placement_HeaderFile
#define _StepGeom_Axis1Placement_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_StepGeom_Axis1Placement.hxx>

#include <Handle_StepGeom_Direction.hxx>
#include <Standard_Boolean.hxx>
#include <StepGeom_Placement.hxx>
#include <Handle_TCollection_HAsciiString.hxx>
#include <Handle_StepGeom_CartesianPoint.hxx>
class StepGeom_Direction;
class TCollection_HAsciiString;
class StepGeom_CartesianPoint;



class StepGeom_Axis1Placement : public StepGeom_Placement
{

public:

  
  //! Returns a Axis1Placement
  Standard_EXPORT StepGeom_Axis1Placement();
  
  Standard_EXPORT virtual   void Init (const Handle(TCollection_HAsciiString)& aName, const Handle(StepGeom_CartesianPoint)& aLocation) ;
  
  Standard_EXPORT virtual   void Init (const Handle(TCollection_HAsciiString)& aName, const Handle(StepGeom_CartesianPoint)& aLocation, const Standard_Boolean hasAaxis, const Handle(StepGeom_Direction)& aAxis) ;
  
  Standard_EXPORT   void SetAxis (const Handle(StepGeom_Direction)& aAxis) ;
  
  Standard_EXPORT   void UnSetAxis() ;
  
  Standard_EXPORT   Handle(StepGeom_Direction) Axis()  const;
  
  Standard_EXPORT   Standard_Boolean HasAxis()  const;




  DEFINE_STANDARD_RTTI(StepGeom_Axis1Placement)

protected:




private: 


  Handle(StepGeom_Direction) axis;
  Standard_Boolean hasAxis;


};







#endif // _StepGeom_Axis1Placement_HeaderFile
