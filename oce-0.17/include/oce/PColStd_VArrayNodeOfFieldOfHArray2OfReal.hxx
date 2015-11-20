// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _PColStd_VArrayNodeOfFieldOfHArray2OfReal_HeaderFile
#define _PColStd_VArrayNodeOfFieldOfHArray2OfReal_HeaderFile

#include <Standard_Macro.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard.hxx>
#include <Handle_PColStd_VArrayNodeOfFieldOfHArray2OfReal.hxx>

#include <Standard_Address.hxx>
#include <Standard_Real.hxx>
#include <PStandard_ArrayNode.hxx>
class PColStd_FieldOfHArray2OfReal;
class PColStd_VArrayTNodeOfFieldOfHArray2OfReal;


class PColStd_VArrayNodeOfFieldOfHArray2OfReal : public PStandard_ArrayNode
{

public:

  
  Standard_EXPORT PColStd_VArrayNodeOfFieldOfHArray2OfReal();
  
  Standard_EXPORT PColStd_VArrayNodeOfFieldOfHArray2OfReal(const Standard_Real& aValue);
  
  Standard_EXPORT   void SetValue (const Standard_Real& aValue) ;
  
  Standard_EXPORT   Standard_Address Value()  const;

PColStd_VArrayNodeOfFieldOfHArray2OfReal(const Storage_stCONSTclCOM& a) : PStandard_ArrayNode(a)
{
  
}
    Standard_Real _CSFDB_GetPColStd_VArrayNodeOfFieldOfHArray2OfRealmyValue() const { return myValue; }
    void _CSFDB_SetPColStd_VArrayNodeOfFieldOfHArray2OfRealmyValue(const Standard_Real p) { myValue = p; }



  DEFINE_STANDARD_RTTI(PColStd_VArrayNodeOfFieldOfHArray2OfReal)

protected:




private: 


  Standard_Real myValue;


};







#endif // _PColStd_VArrayNodeOfFieldOfHArray2OfReal_HeaderFile
