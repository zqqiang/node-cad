// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESDraw_SpecificModule_HeaderFile
#define _IGESDraw_SpecificModule_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_IGESDraw_SpecificModule.hxx>

#include <IGESData_SpecificModule.hxx>
#include <Standard_Integer.hxx>
#include <Handle_IGESData_IGESEntity.hxx>
#include <Handle_Message_Messenger.hxx>
#include <Standard_Boolean.hxx>
class IGESData_IGESEntity;
class IGESData_IGESDumper;
class Message_Messenger;


//! Defines Services attached to IGES Entities :
//! Dump & OwnCorrect, for IGESDraw
class IGESDraw_SpecificModule : public IGESData_SpecificModule
{

public:

  
  //! Creates a SpecificModule from IGESDraw & puts it into SpecificLib
  Standard_EXPORT IGESDraw_SpecificModule();
  
  //! Specific Dump (own parameters) for IGESDraw
  Standard_EXPORT   void OwnDump (const Standard_Integer CN, const Handle(IGESData_IGESEntity)& ent, const IGESData_IGESDumper& dumper, const Handle(Message_Messenger)& S, const Standard_Integer own)  const;
  
  //! Performs non-ambiguous Corrections on Entities which support
  //! them (Planar)
  Standard_EXPORT virtual   Standard_Boolean OwnCorrect (const Standard_Integer CN, const Handle(IGESData_IGESEntity)& ent)  const;




  DEFINE_STANDARD_RTTI(IGESDraw_SpecificModule)

protected:




private: 




};







#endif // _IGESDraw_SpecificModule_HeaderFile
