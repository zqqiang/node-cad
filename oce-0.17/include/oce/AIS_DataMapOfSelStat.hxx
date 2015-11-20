// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _AIS_DataMapOfSelStat_HeaderFile
#define _AIS_DataMapOfSelStat_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <TCollection_BasicMap.hxx>
#include <Handle_SelectMgr_SelectableObject.hxx>
#include <Handle_AIS_LocalStatus.hxx>
#include <Handle_AIS_DataMapNodeOfDataMapOfSelStat.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Address.hxx>
class Standard_DomainError;
class Standard_NoSuchObject;
class SelectMgr_SelectableObject;
class AIS_LocalStatus;
class TColStd_MapTransientHasher;
class AIS_DataMapNodeOfDataMapOfSelStat;
class AIS_DataMapIteratorOfDataMapOfSelStat;



class AIS_DataMapOfSelStat  : public TCollection_BasicMap
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT AIS_DataMapOfSelStat(const Standard_Integer NbBuckets = 1);
  
  Standard_EXPORT   AIS_DataMapOfSelStat& Assign (const AIS_DataMapOfSelStat& Other) ;
  AIS_DataMapOfSelStat& operator = (const AIS_DataMapOfSelStat& Other) 
{
  return Assign(Other);
}
  
  Standard_EXPORT   void ReSize (const Standard_Integer NbBuckets) ;
  
  Standard_EXPORT   void Clear() ;
~AIS_DataMapOfSelStat()
{
  Clear();
}
  
  Standard_EXPORT   Standard_Boolean Bind (const Handle(SelectMgr_SelectableObject)& K, const Handle(AIS_LocalStatus)& I) ;
  
  Standard_EXPORT   Standard_Boolean IsBound (const Handle(SelectMgr_SelectableObject)& K)  const;
  
  Standard_EXPORT   Standard_Boolean UnBind (const Handle(SelectMgr_SelectableObject)& K) ;
  
  Standard_EXPORT  const  Handle(AIS_LocalStatus)& Find (const Handle(SelectMgr_SelectableObject)& K)  const;
 const  Handle(AIS_LocalStatus)& operator() (const Handle(SelectMgr_SelectableObject)& K)  const
{
  return Find(K);
}
  
  Standard_EXPORT   Handle(AIS_LocalStatus)& ChangeFind (const Handle(SelectMgr_SelectableObject)& K) ;
  Handle(AIS_LocalStatus)& operator() (const Handle(SelectMgr_SelectableObject)& K) 
{
  return ChangeFind(K);
}
  
  Standard_EXPORT   Standard_Address Find1 (const Handle(SelectMgr_SelectableObject)& K)  const;
  
  Standard_EXPORT   Standard_Address ChangeFind1 (const Handle(SelectMgr_SelectableObject)& K) ;




protected:





private:

  
  Standard_EXPORT AIS_DataMapOfSelStat(const AIS_DataMapOfSelStat& Other);




};







#endif // _AIS_DataMapOfSelStat_HeaderFile
