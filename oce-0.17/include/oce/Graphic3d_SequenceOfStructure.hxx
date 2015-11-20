// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Graphic3d_SequenceOfStructure_HeaderFile
#define _Graphic3d_SequenceOfStructure_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <TCollection_BaseSequence.hxx>
#include <Handle_Graphic3d_Structure.hxx>
#include <Handle_Graphic3d_SequenceNodeOfSequenceOfStructure.hxx>
#include <Standard_Integer.hxx>
class Standard_NoSuchObject;
class Standard_OutOfRange;
class Graphic3d_Structure;
class Graphic3d_SequenceNodeOfSequenceOfStructure;



class Graphic3d_SequenceOfStructure  : public TCollection_BaseSequence
{
public:

  DEFINE_STANDARD_ALLOC

  
    Graphic3d_SequenceOfStructure();
  
  Standard_EXPORT Graphic3d_SequenceOfStructure(const Graphic3d_SequenceOfStructure& Other);
  
  Standard_EXPORT   void Clear() ;
~Graphic3d_SequenceOfStructure()
{
  Clear();
}
  
  Standard_EXPORT  const  Graphic3d_SequenceOfStructure& Assign (const Graphic3d_SequenceOfStructure& Other) ;
 const  Graphic3d_SequenceOfStructure& operator = (const Graphic3d_SequenceOfStructure& Other) 
{
  return Assign(Other);
}
  
  Standard_EXPORT   void Append (const Handle(Graphic3d_Structure)& T) ;
  
      void Append (Graphic3d_SequenceOfStructure& S) ;
  
  Standard_EXPORT   void Prepend (const Handle(Graphic3d_Structure)& T) ;
  
      void Prepend (Graphic3d_SequenceOfStructure& S) ;
  
      void InsertBefore (const Standard_Integer Index, const Handle(Graphic3d_Structure)& T) ;
  
      void InsertBefore (const Standard_Integer Index, Graphic3d_SequenceOfStructure& S) ;
  
  Standard_EXPORT   void InsertAfter (const Standard_Integer Index, const Handle(Graphic3d_Structure)& T) ;
  
      void InsertAfter (const Standard_Integer Index, Graphic3d_SequenceOfStructure& S) ;
  
  Standard_EXPORT  const  Handle(Graphic3d_Structure)& First()  const;
  
  Standard_EXPORT  const  Handle(Graphic3d_Structure)& Last()  const;
  
      void Split (const Standard_Integer Index, Graphic3d_SequenceOfStructure& Sub) ;
  
  Standard_EXPORT  const  Handle(Graphic3d_Structure)& Value (const Standard_Integer Index)  const;
 const  Handle(Graphic3d_Structure)& operator() (const Standard_Integer Index)  const
{
  return Value(Index);
}
  
  Standard_EXPORT   void SetValue (const Standard_Integer Index, const Handle(Graphic3d_Structure)& I) ;
  
  Standard_EXPORT   Handle(Graphic3d_Structure)& ChangeValue (const Standard_Integer Index) ;
  Handle(Graphic3d_Structure)& operator() (const Standard_Integer Index) 
{
  return ChangeValue(Index);
}
  
  Standard_EXPORT   void Remove (const Standard_Integer Index) ;
  
  Standard_EXPORT   void Remove (const Standard_Integer FromIndex, const Standard_Integer ToIndex) ;




protected:





private:





};

#define SeqItem Handle(Graphic3d_Structure)
#define SeqItem_hxx <Graphic3d_Structure.hxx>
#define TCollection_SequenceNode Graphic3d_SequenceNodeOfSequenceOfStructure
#define TCollection_SequenceNode_hxx <Graphic3d_SequenceNodeOfSequenceOfStructure.hxx>
#define Handle_TCollection_SequenceNode Handle_Graphic3d_SequenceNodeOfSequenceOfStructure
#define TCollection_SequenceNode_Type_() Graphic3d_SequenceNodeOfSequenceOfStructure_Type_()
#define TCollection_Sequence Graphic3d_SequenceOfStructure
#define TCollection_Sequence_hxx <Graphic3d_SequenceOfStructure.hxx>

#include <TCollection_Sequence.lxx>

#undef SeqItem
#undef SeqItem_hxx
#undef TCollection_SequenceNode
#undef TCollection_SequenceNode_hxx
#undef Handle_TCollection_SequenceNode
#undef TCollection_SequenceNode_Type_
#undef TCollection_Sequence
#undef TCollection_Sequence_hxx




#endif // _Graphic3d_SequenceOfStructure_HeaderFile
