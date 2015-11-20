// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _SelectMgr_EntityOwner_HeaderFile
#define _SelectMgr_EntityOwner_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_SelectMgr_EntityOwner.hxx>

#include <SelectMgr_SOPtr.hxx>
#include <Standard_Boolean.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <Standard_Integer.hxx>
#include <Handle_SelectMgr_SelectableObject.hxx>
#include <Handle_PrsMgr_PresentationManager.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Quantity_NameOfColor.hxx>
class Standard_NoSuchObject;
class SelectMgr_SelectableObject;
class PrsMgr_PresentationManager;
class TopLoc_Location;


//! A framework to define classes of owners of sensitive primitives.
//! The owner is the link between application and
//! selection data structures.
//! For the application to make its own objects selectable,
//! it must define owner classes inheriting this framework.
class SelectMgr_EntityOwner : public SelectBasics_EntityOwner
{

public:

  
  //! Initializes the selection priority aPriority.
  Standard_EXPORT SelectMgr_EntityOwner(const Standard_Integer aPriority = 0);
  
  //! Constructs a framework with the selectable object
  //! anSO being attributed the selection priority aPriority.
  Standard_EXPORT SelectMgr_EntityOwner(const Handle(SelectMgr_SelectableObject)& aSO, const Standard_Integer aPriority = 0);
  
  //! Constructs a framework from existing one
  //! anSO being attributed the selection priority aPriority.
  Standard_EXPORT SelectMgr_EntityOwner(const Handle(SelectMgr_EntityOwner)& theOwner, const Standard_Integer aPriority = 0);
  
  //! Returns true if there is a selectable object to serve as an owner.
  Standard_EXPORT   Standard_Boolean HasSelectable()  const;
  
  //! Returns a selectable object detected in the working context.
  Standard_EXPORT virtual   Handle(SelectMgr_SelectableObject) Selectable()  const;
  
  //! Sets the selectable object anSO to be used by the
  //! second constructor above.
  Standard_EXPORT   void Set (const Handle(SelectMgr_SelectableObject)& aSO) ;
  
  //! Provides a framework to highlight any selectable
  //! object found subsequently which can serve as an
  //! owner of a sensitive primitive.
  Standard_EXPORT virtual   void Hilight() ;
  
  //! Returns true if the presentation manager aPM
  //! highlights selections corresponding to the selection mode aMode.
  Standard_EXPORT virtual   Standard_Boolean IsHilighted (const Handle(PrsMgr_PresentationManager)& aPM, const Standard_Integer aMode = 0)  const;
  
  //! Highlights the owner of a detected selectable object in
  //! the presentation manager aPM. This object could be
  //! the owner of a sensitive primitive.
  //! The display mode for the highlight is aMode; this has
  //! the default value of 0, that is, wireframe mode.
  Standard_EXPORT virtual   void Hilight (const Handle(PrsMgr_PresentationManager)& aPM, const Standard_Integer aMode = 0) ;
  
  Standard_EXPORT virtual   void HilightWithColor (const Handle(PrsMgr_PresentationManager3d)& aPM, const Quantity_NameOfColor aColor, const Standard_Integer aMode = 0) ;
  
  //! Removes highlighting from the owner of a detected
  //! selectable object in the presentation manager aPM.
  //! This object could be the owner of a sensitive primitive.
  //! The display mode for the highlight is aMode; this has
  //! the default value of 0, that is, wireframe mode.
  Standard_EXPORT virtual   void Unhilight (const Handle(PrsMgr_PresentationManager)& aPM, const Standard_Integer aMode = 0) ;
  
  //! Clears the owners matching the value of the selection
  //! mode aMode from the presentation manager object aPM.
  Standard_EXPORT virtual   void Clear (const Handle(PrsMgr_PresentationManager)& aPM, const Standard_Integer aMode = 0) ;
  
  Standard_EXPORT virtual   Standard_Boolean HasLocation()  const;
  
  Standard_EXPORT virtual   void SetLocation (const TopLoc_Location& aLoc) ;
  
  Standard_EXPORT virtual   void ResetLocation() ;
  
  Standard_EXPORT virtual   TopLoc_Location Location()  const;
  
  //! Set the state of the owner.
  //! @param theIsSelected [in] shows if owner is selected.
      void SetSelected (const Standard_Boolean theIsSelected) ;
  
  //! @return Standard_True if the owner is selected.
      Standard_Boolean IsSelected()  const;
  
  //! Set the state of the owner.
  //! The method is deprecated. Use SetSelected() instead.
      void State (const Standard_Integer aStatus) ;
  
      Standard_Integer State()  const;
  
  //! if owner is not auto hilighted, for group contains many such owners
  //! will be called one method HilightSelected of SelectableObject
  Standard_EXPORT virtual   Standard_Boolean IsAutoHilight()  const;
  
  //! if this method returns TRUE the owner will allways call method
  //! Hilight for SelectableObject when the owner is detected. By default
  //! it always return FALSE.
  Standard_EXPORT virtual   Standard_Boolean IsForcedHilight()  const;
  
  //! Set Z layer ID and update all presentations.
  Standard_EXPORT virtual   void SetZLayer (const Handle(PrsMgr_PresentationManager)& thePrsMgr, const Standard_Integer theLayerId) ;




  DEFINE_STANDARD_RTTI(SelectMgr_EntityOwner)

protected:




private: 


  SelectMgr_SOPtr mySelectable;
  Standard_Boolean myIsSelected;


};


#include <SelectMgr_EntityOwner.lxx>





#endif // _SelectMgr_EntityOwner_HeaderFile
