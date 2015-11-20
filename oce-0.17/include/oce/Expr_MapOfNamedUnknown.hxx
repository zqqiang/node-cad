// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Expr_MapOfNamedUnknown_HeaderFile
#define _Expr_MapOfNamedUnknown_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <TCollection_BasicMap.hxx>
#include <Handle_Expr_NamedUnknown.hxx>
#include <Handle_Expr_IndexedMapNodeOfMapOfNamedUnknown.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
class Standard_DomainError;
class Standard_OutOfRange;
class Expr_NamedUnknown;
class TColStd_MapTransientHasher;
class Expr_IndexedMapNodeOfMapOfNamedUnknown;



class Expr_MapOfNamedUnknown  : public TCollection_BasicMap
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT Expr_MapOfNamedUnknown(const Standard_Integer NbBuckets = 1);
  
  Standard_EXPORT Expr_MapOfNamedUnknown(const Expr_MapOfNamedUnknown& Other);
  
  Standard_EXPORT   Expr_MapOfNamedUnknown& Assign (const Expr_MapOfNamedUnknown& Other) ;
  Expr_MapOfNamedUnknown& operator = (const Expr_MapOfNamedUnknown& Other) 
{
  return Assign(Other);
}
  
  Standard_EXPORT   void ReSize (const Standard_Integer NbBuckets) ;
  
  Standard_EXPORT   void Clear() ;
~Expr_MapOfNamedUnknown()
{
  Clear();
}
  
  Standard_EXPORT   Standard_Integer Add (const Handle(Expr_NamedUnknown)& K) ;
  
  Standard_EXPORT   void Substitute (const Standard_Integer I, const Handle(Expr_NamedUnknown)& K) ;
  
  Standard_EXPORT   void RemoveLast() ;
  
  Standard_EXPORT   Standard_Boolean Contains (const Handle(Expr_NamedUnknown)& K)  const;
  
  Standard_EXPORT  const  Handle(Expr_NamedUnknown)& FindKey (const Standard_Integer I)  const;
 const  Handle(Expr_NamedUnknown)& operator () (const Standard_Integer I)  const
{
  return FindKey(I);
}
  
  Standard_EXPORT   Standard_Integer FindIndex (const Handle(Expr_NamedUnknown)& K)  const;




protected:





private:





};







#endif // _Expr_MapOfNamedUnknown_HeaderFile
