// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TColStd_StdMapNodeOfMapOfReal_HeaderFile
#define _TColStd_StdMapNodeOfMapOfReal_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_TColStd_StdMapNodeOfMapOfReal.hxx>

#include <Standard_Real.hxx>
#include <TCollection_MapNode.hxx>
#include <TCollection_MapNodePtr.hxx>
class TColStd_MapRealHasher;
class TColStd_MapOfReal;
class TColStd_MapIteratorOfMapOfReal;



class TColStd_StdMapNodeOfMapOfReal : public TCollection_MapNode
{

public:

  
    TColStd_StdMapNodeOfMapOfReal(const Standard_Real& K, const TCollection_MapNodePtr& n);
  
      Standard_Real& Key()  const;




  DEFINE_STANDARD_RTTI(TColStd_StdMapNodeOfMapOfReal)

protected:




private: 


  Standard_Real myKey;


};

#define TheKey Standard_Real
#define TheKey_hxx <Standard_Real.hxx>
#define Hasher TColStd_MapRealHasher
#define Hasher_hxx <TColStd_MapRealHasher.hxx>
#define TCollection_StdMapNode TColStd_StdMapNodeOfMapOfReal
#define TCollection_StdMapNode_hxx <TColStd_StdMapNodeOfMapOfReal.hxx>
#define TCollection_MapIterator TColStd_MapIteratorOfMapOfReal
#define TCollection_MapIterator_hxx <TColStd_MapIteratorOfMapOfReal.hxx>
#define Handle_TCollection_StdMapNode Handle_TColStd_StdMapNodeOfMapOfReal
#define TCollection_StdMapNode_Type_() TColStd_StdMapNodeOfMapOfReal_Type_()
#define TCollection_Map TColStd_MapOfReal
#define TCollection_Map_hxx <TColStd_MapOfReal.hxx>

#include <TCollection_StdMapNode.lxx>

#undef TheKey
#undef TheKey_hxx
#undef Hasher
#undef Hasher_hxx
#undef TCollection_StdMapNode
#undef TCollection_StdMapNode_hxx
#undef TCollection_MapIterator
#undef TCollection_MapIterator_hxx
#undef Handle_TCollection_StdMapNode
#undef TCollection_StdMapNode_Type_
#undef TCollection_Map
#undef TCollection_Map_hxx




#endif // _TColStd_StdMapNodeOfMapOfReal_HeaderFile
