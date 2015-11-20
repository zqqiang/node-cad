// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _MMgt_TShared_HeaderFile
#define _MMgt_TShared_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_MMgt_TShared.hxx>

#include <Standard_Transient.hxx>
class Standard_OutOfMemory;



//! Intermediate class between Standard_Transient
//! and descendants.
//! The abstract class TShared is the root class of
//! managed objects. TShared objects are managed
//! by a memory manager based on reference
//! counting. They have handle semantics. In other
//! words, the reference counter is transparently
//! incremented and decremented according to the
//! scope of handles. When all handles, which
//! reference a single object are out of scope, the
//! reference counter becomes null and the object is
//! automatically deleted. The deallocated memory is
//! not given back to the system though. It is
//! reclaimed for new objects of the same size.
//! Warning
//! This memory management scheme does not
//! work for cyclic data structures. In such cases
//! (with back pointers for example), you should
//! interrupt the cycle in a class by using a full C++
//! pointer instead of a handle.
class MMgt_TShared : public Standard_Transient
{

public:

  
  Standard_EXPORT virtual   void Delete()  const;




  DEFINE_STANDARD_RTTI(MMgt_TShared)

protected:




private: 




};







#endif // _MMgt_TShared_HeaderFile
