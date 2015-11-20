// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _XSDRAW_Functions_HeaderFile
#define _XSDRAW_Functions_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>



//! Defines additionnal commands for XSDRAW to :
//! - control of initialisation (xinit, xnorm, newmodel)
//! - analyse of the result of a transfer (recorded in a
//! TransientProcess for Read, FinderProcess for Write) :
//! statistics, various lists (roots,complete,abnormal), what
//! about one specific entity, producing a model with the
//! abnormal result
//!
//! This appendix of XSDRAW is compiled separately to distinguish
//! basic features from user callable forms
class XSDRAW_Functions 
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Defines and loads all basic functions for XSDRAW (as ActFunc)
  Standard_EXPORT static   void Init() ;




protected:





private:





};







#endif // _XSDRAW_Functions_HeaderFile
