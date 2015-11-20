// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Interface_GlobalNodeOfGeneralLib_HeaderFile
#define _Interface_GlobalNodeOfGeneralLib_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_Interface_GlobalNodeOfGeneralLib.hxx>

#include <Handle_Interface_GeneralModule.hxx>
#include <Handle_Interface_Protocol.hxx>
#include <Handle_Interface_GlobalNodeOfGeneralLib.hxx>
#include <Standard_Transient.hxx>
#include <Handle_Standard_Transient.hxx>
#include <Handle_Interface_NodeOfGeneralLib.hxx>
class Interface_GeneralModule;
class Interface_Protocol;
class Standard_Transient;
class Interface_GeneralLib;
class Interface_NodeOfGeneralLib;



class Interface_GlobalNodeOfGeneralLib : public Standard_Transient
{

public:

  
  Standard_EXPORT Interface_GlobalNodeOfGeneralLib();
  
  Standard_EXPORT   void Add (const Handle(Interface_GeneralModule)& amodule, const Handle(Interface_Protocol)& aprotocol) ;
  
  Standard_EXPORT  const  Handle(Interface_GeneralModule)& Module()  const;
  
  Standard_EXPORT  const  Handle(Interface_Protocol)& Protocol()  const;
  
  Standard_EXPORT  const  Handle(Interface_GlobalNodeOfGeneralLib)& Next()  const;




  DEFINE_STANDARD_RTTI(Interface_GlobalNodeOfGeneralLib)

protected:




private: 


  Handle(Interface_GeneralModule) themod;
  Handle(Interface_Protocol) theprot;
  Handle(Interface_GlobalNodeOfGeneralLib) thenext;


};







#endif // _Interface_GlobalNodeOfGeneralLib_HeaderFile
