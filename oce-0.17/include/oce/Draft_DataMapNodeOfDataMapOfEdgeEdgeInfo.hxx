// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Draft_DataMapNodeOfDataMapOfEdgeEdgeInfo_HeaderFile
#define _Draft_DataMapNodeOfDataMapOfEdgeEdgeInfo_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_Draft_DataMapNodeOfDataMapOfEdgeEdgeInfo.hxx>

#include <TopoDS_Edge.hxx>
#include <Draft_EdgeInfo.hxx>
#include <TCollection_MapNode.hxx>
#include <TCollection_MapNodePtr.hxx>
class TopoDS_Edge;
class Draft_EdgeInfo;
class TopTools_ShapeMapHasher;
class Draft_DataMapOfEdgeEdgeInfo;
class Draft_DataMapIteratorOfDataMapOfEdgeEdgeInfo;



class Draft_DataMapNodeOfDataMapOfEdgeEdgeInfo : public TCollection_MapNode
{

public:

  
    Draft_DataMapNodeOfDataMapOfEdgeEdgeInfo(const TopoDS_Edge& K, const Draft_EdgeInfo& I, const TCollection_MapNodePtr& n);
  
      TopoDS_Edge& Key()  const;
  
      Draft_EdgeInfo& Value()  const;




  DEFINE_STANDARD_RTTI(Draft_DataMapNodeOfDataMapOfEdgeEdgeInfo)

protected:




private: 


  TopoDS_Edge myKey;
  Draft_EdgeInfo myValue;


};

#define TheKey TopoDS_Edge
#define TheKey_hxx <TopoDS_Edge.hxx>
#define TheItem Draft_EdgeInfo
#define TheItem_hxx <Draft_EdgeInfo.hxx>
#define Hasher TopTools_ShapeMapHasher
#define Hasher_hxx <TopTools_ShapeMapHasher.hxx>
#define TCollection_DataMapNode Draft_DataMapNodeOfDataMapOfEdgeEdgeInfo
#define TCollection_DataMapNode_hxx <Draft_DataMapNodeOfDataMapOfEdgeEdgeInfo.hxx>
#define TCollection_DataMapIterator Draft_DataMapIteratorOfDataMapOfEdgeEdgeInfo
#define TCollection_DataMapIterator_hxx <Draft_DataMapIteratorOfDataMapOfEdgeEdgeInfo.hxx>
#define Handle_TCollection_DataMapNode Handle_Draft_DataMapNodeOfDataMapOfEdgeEdgeInfo
#define TCollection_DataMapNode_Type_() Draft_DataMapNodeOfDataMapOfEdgeEdgeInfo_Type_()
#define TCollection_DataMap Draft_DataMapOfEdgeEdgeInfo
#define TCollection_DataMap_hxx <Draft_DataMapOfEdgeEdgeInfo.hxx>

#include <TCollection_DataMapNode.lxx>

#undef TheKey
#undef TheKey_hxx
#undef TheItem
#undef TheItem_hxx
#undef Hasher
#undef Hasher_hxx
#undef TCollection_DataMapNode
#undef TCollection_DataMapNode_hxx
#undef TCollection_DataMapIterator
#undef TCollection_DataMapIterator_hxx
#undef Handle_TCollection_DataMapNode
#undef TCollection_DataMapNode_Type_
#undef TCollection_DataMap
#undef TCollection_DataMap_hxx




#endif // _Draft_DataMapNodeOfDataMapOfEdgeEdgeInfo_HeaderFile
