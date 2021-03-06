// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _AIS_DimensionOwner_HeaderFile
#define _AIS_DimensionOwner_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_AIS_DimensionOwner.hxx>

#include <AIS_DimensionSelectionMode.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <Handle_SelectMgr_SelectableObject.hxx>
#include <Standard_Integer.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Quantity_NameOfColor.hxx>
#include <Standard_Boolean.hxx>
#include <Handle_PrsMgr_PresentationManager.hxx>
class SelectMgr_SelectableObject;
class PrsMgr_PresentationManager;


//! The owner is the entity which makes it possible to link
//! the sensitive primitives and the reference shapes that
//! you want to detect. It stocks the various pieces of
//! information which make it possible to find objects. An
//! owner has a priority which you can modulate, so as to
//! make one entity more selectable than another. You
//! might want to make edges more selectable than
//! faces, for example. In that case, you could attribute sa
//! higher priority to the one compared to the other. An
//! edge, could have priority 5, for example, and a face,
//! priority 4. The default priority is 5.
class AIS_DimensionOwner : public SelectMgr_EntityOwner
{

public:

  

  //! Initializes the dimension owner, theSO, and attributes it
  //! the priority, thePriority.
  Standard_EXPORT AIS_DimensionOwner(const Handle(SelectMgr_SelectableObject)& theSelObject, const AIS_DimensionSelectionMode theSelMode, const Standard_Integer thePriority = 0);
  
  Standard_EXPORT   AIS_DimensionSelectionMode SelectionMode()  const;
  
  Standard_EXPORT virtual   void HilightWithColor (const Handle(PrsMgr_PresentationManager3d)& thePM, const Quantity_NameOfColor theColor, const Standard_Integer theMode = 0) ;
  
  //! Returns true if an object with the selection mode
  //! aMode is highlighted in the presentation manager aPM.
  Standard_EXPORT virtual   Standard_Boolean IsHilighted (const Handle(PrsMgr_PresentationManager)& thePM, const Standard_Integer theMode = 0)  const;
  
  Standard_EXPORT virtual   void Hilight (const Handle(PrsMgr_PresentationManager)& thePM, const Standard_Integer theMode = 0) ;
  
  //! Removes highlighting from the selected part of dimension.
  Standard_EXPORT virtual   void Unhilight (const Handle(PrsMgr_PresentationManager)& thePM, const Standard_Integer theMode = 0) ;




  DEFINE_STANDARD_RTTI(AIS_DimensionOwner)

protected:




private: 


  AIS_DimensionSelectionMode mySelectionMode;


};







#endif // _AIS_DimensionOwner_HeaderFile
