// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepBasic_DateTimeRole_HeaderFile
#define _StepBasic_DateTimeRole_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_StepBasic_DateTimeRole.hxx>

#include <Handle_TCollection_HAsciiString.hxx>
#include <MMgt_TShared.hxx>
class TCollection_HAsciiString;



class StepBasic_DateTimeRole : public MMgt_TShared
{

public:

  
  //! Returns a DateTimeRole
  Standard_EXPORT StepBasic_DateTimeRole();
  
  Standard_EXPORT virtual   void Init (const Handle(TCollection_HAsciiString)& aName) ;
  
  Standard_EXPORT   void SetName (const Handle(TCollection_HAsciiString)& aName) ;
  
  Standard_EXPORT   Handle(TCollection_HAsciiString) Name()  const;




  DEFINE_STANDARD_RTTI(StepBasic_DateTimeRole)

protected:




private: 


  Handle(TCollection_HAsciiString) name;


};







#endif // _StepBasic_DateTimeRole_HeaderFile
