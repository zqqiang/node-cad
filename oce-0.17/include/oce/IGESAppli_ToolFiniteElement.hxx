// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESAppli_ToolFiniteElement_HeaderFile
#define _IGESAppli_ToolFiniteElement_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Handle_IGESAppli_FiniteElement.hxx>
#include <Handle_IGESData_IGESReaderData.hxx>
#include <Handle_Interface_Check.hxx>
#include <Handle_Message_Messenger.hxx>
#include <Standard_Integer.hxx>
class Standard_DomainError;
class IGESAppli_FiniteElement;
class IGESData_IGESReaderData;
class IGESData_ParamReader;
class IGESData_IGESWriter;
class Interface_EntityIterator;
class IGESData_DirChecker;
class Interface_ShareTool;
class Interface_Check;
class Interface_CopyTool;
class IGESData_IGESDumper;
class Message_Messenger;


//! Tool to work on a FiniteElement. Called by various Modules
//! (ReadWriteModule, GeneralModule, SpecificModule)
class IGESAppli_ToolFiniteElement 
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Returns a ToolFiniteElement, ready to work
  Standard_EXPORT IGESAppli_ToolFiniteElement();
  
  //! Reads own parameters from file. <PR> gives access to them,
  //! <IR> detains parameter types and values
  Standard_EXPORT   void ReadOwnParams (const Handle(IGESAppli_FiniteElement)& ent, const Handle(IGESData_IGESReaderData)& IR, IGESData_ParamReader& PR)  const;
  
  //! Writes own parameters to IGESWriter
  Standard_EXPORT   void WriteOwnParams (const Handle(IGESAppli_FiniteElement)& ent, IGESData_IGESWriter& IW)  const;
  
  //! Lists the Entities shared by a FiniteElement <ent>, from
  //! its specific (own) parameters
  Standard_EXPORT   void OwnShared (const Handle(IGESAppli_FiniteElement)& ent, Interface_EntityIterator& iter)  const;
  
  //! Returns specific DirChecker
  Standard_EXPORT   IGESData_DirChecker DirChecker (const Handle(IGESAppli_FiniteElement)& ent)  const;
  
  //! Performs Specific Semantic Check
  Standard_EXPORT   void OwnCheck (const Handle(IGESAppli_FiniteElement)& ent, const Interface_ShareTool& shares, Handle(Interface_Check)& ach)  const;
  
  //! Copies Specific Parameters
  Standard_EXPORT   void OwnCopy (const Handle(IGESAppli_FiniteElement)& entfrom, const Handle(IGESAppli_FiniteElement)& entto, Interface_CopyTool& TC)  const;
  
  //! Dump of Specific Parameters
  Standard_EXPORT   void OwnDump (const Handle(IGESAppli_FiniteElement)& ent, const IGESData_IGESDumper& dumper, const Handle(Message_Messenger)& S, const Standard_Integer own)  const;




protected:





private:





};







#endif // _IGESAppli_ToolFiniteElement_HeaderFile
