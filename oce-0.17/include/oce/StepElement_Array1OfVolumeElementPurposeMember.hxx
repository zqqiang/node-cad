// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepElement_Array1OfVolumeElementPurposeMember_HeaderFile
#define _StepElement_Array1OfVolumeElementPurposeMember_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Integer.hxx>
#include <Standard_Address.hxx>
#include <Standard_Boolean.hxx>
#include <Handle_StepElement_VolumeElementPurposeMember.hxx>
class Standard_RangeError;
class Standard_DimensionMismatch;
class Standard_OutOfRange;
class Standard_OutOfMemory;
class StepElement_VolumeElementPurposeMember;



class StepElement_Array1OfVolumeElementPurposeMember 
{
public:

  DEFINE_STANDARD_ALLOC

  
    StepElement_Array1OfVolumeElementPurposeMember(const Standard_Integer Low, const Standard_Integer Up);
  
    StepElement_Array1OfVolumeElementPurposeMember(const Handle(StepElement_VolumeElementPurposeMember)& Item, const Standard_Integer Low, const Standard_Integer Up);
  
  Standard_EXPORT   void Init (const Handle(StepElement_VolumeElementPurposeMember)& V) ;
  
      void Destroy() ;
~StepElement_Array1OfVolumeElementPurposeMember()
{
  Destroy();
}
  
      Standard_Boolean IsAllocated()  const;
  
  Standard_EXPORT  const  StepElement_Array1OfVolumeElementPurposeMember& Assign (const StepElement_Array1OfVolumeElementPurposeMember& Other) ;
 const  StepElement_Array1OfVolumeElementPurposeMember& operator = (const StepElement_Array1OfVolumeElementPurposeMember& Other) 
{
  return Assign(Other);
}
  
      Standard_Integer Length()  const;
  
      Standard_Integer Lower()  const;
  
      Standard_Integer Upper()  const;
  
      void SetValue (const Standard_Integer Index, const Handle(StepElement_VolumeElementPurposeMember)& Value) ;
  
     const  Handle(StepElement_VolumeElementPurposeMember)& Value (const Standard_Integer Index)  const;
   const  Handle(StepElement_VolumeElementPurposeMember)& operator () (const Standard_Integer Index)  const
{
  return Value(Index);
}
  
      Handle(StepElement_VolumeElementPurposeMember)& ChangeValue (const Standard_Integer Index) ;
    Handle(StepElement_VolumeElementPurposeMember)& operator () (const Standard_Integer Index) 
{
  return ChangeValue(Index);
}




protected:





private:

  
  Standard_EXPORT StepElement_Array1OfVolumeElementPurposeMember(const StepElement_Array1OfVolumeElementPurposeMember& AnArray);


  Standard_Integer myLowerBound;
  Standard_Integer myUpperBound;
  Standard_Address myStart;
  Standard_Boolean isAllocated;


};

#define Array1Item Handle(StepElement_VolumeElementPurposeMember)
#define Array1Item_hxx <StepElement_VolumeElementPurposeMember.hxx>
#define TCollection_Array1 StepElement_Array1OfVolumeElementPurposeMember
#define TCollection_Array1_hxx <StepElement_Array1OfVolumeElementPurposeMember.hxx>

#include <TCollection_Array1.lxx>

#undef Array1Item
#undef Array1Item_hxx
#undef TCollection_Array1
#undef TCollection_Array1_hxx




#endif // _StepElement_Array1OfVolumeElementPurposeMember_HeaderFile
