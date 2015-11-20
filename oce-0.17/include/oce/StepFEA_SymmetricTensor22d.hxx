// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepFEA_SymmetricTensor22d_HeaderFile
#define _StepFEA_SymmetricTensor22d_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <StepData_SelectType.hxx>
#include <Standard_Integer.hxx>
#include <Handle_Standard_Transient.hxx>
#include <Handle_TColStd_HArray1OfReal.hxx>
class Standard_Transient;
class TColStd_HArray1OfReal;


//! Representation of STEP SELECT type SymmetricTensor22d
class StepFEA_SymmetricTensor22d  : public StepData_SelectType
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Empty constructor
  Standard_EXPORT StepFEA_SymmetricTensor22d();
  
  //! Recognizes a kind of SymmetricTensor22d select type
  //! 1 -> HArray1OfReal from TColStd
  //! 0 else
  Standard_EXPORT   Standard_Integer CaseNum (const Handle(Standard_Transient)& ent)  const;
  
  //! Returns Value as AnisotropicSymmetricTensor22d (or Null if another type)
  Standard_EXPORT   Handle(TColStd_HArray1OfReal) AnisotropicSymmetricTensor22d()  const;




protected:





private:





};







#endif // _StepFEA_SymmetricTensor22d_HeaderFile
