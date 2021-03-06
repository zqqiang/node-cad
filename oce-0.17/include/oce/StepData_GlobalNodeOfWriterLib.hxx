// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepData_GlobalNodeOfWriterLib_HeaderFile
#define _StepData_GlobalNodeOfWriterLib_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_StepData_GlobalNodeOfWriterLib.hxx>

#include <Handle_StepData_ReadWriteModule.hxx>
#include <Handle_StepData_Protocol.hxx>
#include <Handle_StepData_GlobalNodeOfWriterLib.hxx>
#include <Standard_Transient.hxx>
#include <Handle_Standard_Transient.hxx>
#include <Handle_StepData_NodeOfWriterLib.hxx>
class StepData_ReadWriteModule;
class StepData_Protocol;
class Standard_Transient;
class StepData_WriterLib;
class StepData_NodeOfWriterLib;



class StepData_GlobalNodeOfWriterLib : public Standard_Transient
{

public:

  
  Standard_EXPORT StepData_GlobalNodeOfWriterLib();
  
  Standard_EXPORT   void Add (const Handle(StepData_ReadWriteModule)& amodule, const Handle(StepData_Protocol)& aprotocol) ;
  
  Standard_EXPORT  const  Handle(StepData_ReadWriteModule)& Module()  const;
  
  Standard_EXPORT  const  Handle(StepData_Protocol)& Protocol()  const;
  
  Standard_EXPORT  const  Handle(StepData_GlobalNodeOfWriterLib)& Next()  const;




  DEFINE_STANDARD_RTTI(StepData_GlobalNodeOfWriterLib)

protected:




private: 


  Handle(StepData_ReadWriteModule) themod;
  Handle(StepData_Protocol) theprot;
  Handle(StepData_GlobalNodeOfWriterLib) thenext;


};







#endif // _StepData_GlobalNodeOfWriterLib_HeaderFile
