// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepFEA_HSequenceOfCurve3dElementProperty_HeaderFile
#define _StepFEA_HSequenceOfCurve3dElementProperty_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_StepFEA_HSequenceOfCurve3dElementProperty.hxx>

#include <StepFEA_SequenceOfCurve3dElementProperty.hxx>
#include <MMgt_TShared.hxx>
#include <Handle_StepFEA_Curve3dElementProperty.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
class Standard_NoSuchObject;
class Standard_OutOfRange;
class StepFEA_Curve3dElementProperty;
class StepFEA_SequenceOfCurve3dElementProperty;



class StepFEA_HSequenceOfCurve3dElementProperty : public MMgt_TShared
{

public:

  
    StepFEA_HSequenceOfCurve3dElementProperty();
  
      Standard_Boolean IsEmpty()  const;
  
      Standard_Integer Length()  const;
  
  Standard_EXPORT   void Clear() ;
  
  Standard_EXPORT   void Append (const Handle(StepFEA_Curve3dElementProperty)& anItem) ;
  
  Standard_EXPORT   void Append (const Handle(StepFEA_HSequenceOfCurve3dElementProperty)& aSequence) ;
  
  Standard_EXPORT   void Prepend (const Handle(StepFEA_Curve3dElementProperty)& anItem) ;
  
  Standard_EXPORT   void Prepend (const Handle(StepFEA_HSequenceOfCurve3dElementProperty)& aSequence) ;
  
  Standard_EXPORT   void Reverse() ;
  
  Standard_EXPORT   void InsertBefore (const Standard_Integer anIndex, const Handle(StepFEA_Curve3dElementProperty)& anItem) ;
  
  Standard_EXPORT   void InsertBefore (const Standard_Integer anIndex, const Handle(StepFEA_HSequenceOfCurve3dElementProperty)& aSequence) ;
  
  Standard_EXPORT   void InsertAfter (const Standard_Integer anIndex, const Handle(StepFEA_Curve3dElementProperty)& anItem) ;
  
  Standard_EXPORT   void InsertAfter (const Standard_Integer anIndex, const Handle(StepFEA_HSequenceOfCurve3dElementProperty)& aSequence) ;
  
  Standard_EXPORT   void Exchange (const Standard_Integer anIndex, const Standard_Integer anOtherIndex) ;
  
  Standard_EXPORT   Handle(StepFEA_HSequenceOfCurve3dElementProperty) Split (const Standard_Integer anIndex) ;
  
  Standard_EXPORT   void SetValue (const Standard_Integer anIndex, const Handle(StepFEA_Curve3dElementProperty)& anItem) ;
  
  Standard_EXPORT  const  Handle(StepFEA_Curve3dElementProperty)& Value (const Standard_Integer anIndex)  const;
  
  Standard_EXPORT   Handle(StepFEA_Curve3dElementProperty)& ChangeValue (const Standard_Integer anIndex) ;
  
  Standard_EXPORT   void Remove (const Standard_Integer anIndex) ;
  
  Standard_EXPORT   void Remove (const Standard_Integer fromIndex, const Standard_Integer toIndex) ;
  
     const  StepFEA_SequenceOfCurve3dElementProperty& Sequence()  const;
  
      StepFEA_SequenceOfCurve3dElementProperty& ChangeSequence() ;
  
  Standard_EXPORT   Handle(StepFEA_HSequenceOfCurve3dElementProperty) ShallowCopy()  const;




  DEFINE_STANDARD_RTTI(StepFEA_HSequenceOfCurve3dElementProperty)

protected:




private: 


  StepFEA_SequenceOfCurve3dElementProperty mySequence;


};

#define Item Handle(StepFEA_Curve3dElementProperty)
#define Item_hxx <StepFEA_Curve3dElementProperty.hxx>
#define TheSequence StepFEA_SequenceOfCurve3dElementProperty
#define TheSequence_hxx <StepFEA_SequenceOfCurve3dElementProperty.hxx>
#define TCollection_HSequence StepFEA_HSequenceOfCurve3dElementProperty
#define TCollection_HSequence_hxx <StepFEA_HSequenceOfCurve3dElementProperty.hxx>
#define Handle_TCollection_HSequence Handle_StepFEA_HSequenceOfCurve3dElementProperty
#define TCollection_HSequence_Type_() StepFEA_HSequenceOfCurve3dElementProperty_Type_()

#include <TCollection_HSequence.lxx>

#undef Item
#undef Item_hxx
#undef TheSequence
#undef TheSequence_hxx
#undef TCollection_HSequence
#undef TCollection_HSequence_hxx
#undef Handle_TCollection_HSequence
#undef TCollection_HSequence_Type_


inline Handle(StepFEA_HSequenceOfCurve3dElementProperty) ShallowCopy(const Handle(StepFEA_HSequenceOfCurve3dElementProperty)& me) {
 return me->ShallowCopy();
}



#endif // _StepFEA_HSequenceOfCurve3dElementProperty_HeaderFile
