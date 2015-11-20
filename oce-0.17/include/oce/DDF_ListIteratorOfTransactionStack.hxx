// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _DDF_ListIteratorOfTransactionStack_HeaderFile
#define _DDF_ListIteratorOfTransactionStack_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Address.hxx>
#include <Handle_DDF_Transaction.hxx>
#include <Handle_DDF_ListNodeOfTransactionStack.hxx>
#include <Standard_Boolean.hxx>
class Standard_NoMoreObject;
class Standard_NoSuchObject;
class DDF_TransactionStack;
class DDF_Transaction;
class DDF_ListNodeOfTransactionStack;



class DDF_ListIteratorOfTransactionStack 
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT DDF_ListIteratorOfTransactionStack();
  
  Standard_EXPORT DDF_ListIteratorOfTransactionStack(const DDF_TransactionStack& L);
  
  Standard_EXPORT   void Initialize (const DDF_TransactionStack& L) ;
  
      Standard_Boolean More()  const;
  
  Standard_EXPORT   void Next() ;
  
  Standard_EXPORT   Handle(DDF_Transaction)& Value()  const;


friend class DDF_TransactionStack;


protected:





private:



  Standard_Address current;
  Standard_Address previous;


};

#define Item Handle(DDF_Transaction)
#define Item_hxx <DDF_Transaction.hxx>
#define TCollection_ListNode DDF_ListNodeOfTransactionStack
#define TCollection_ListNode_hxx <DDF_ListNodeOfTransactionStack.hxx>
#define TCollection_ListIterator DDF_ListIteratorOfTransactionStack
#define TCollection_ListIterator_hxx <DDF_ListIteratorOfTransactionStack.hxx>
#define Handle_TCollection_ListNode Handle_DDF_ListNodeOfTransactionStack
#define TCollection_ListNode_Type_() DDF_ListNodeOfTransactionStack_Type_()
#define TCollection_List DDF_TransactionStack
#define TCollection_List_hxx <DDF_TransactionStack.hxx>

#include <TCollection_ListIterator.lxx>

#undef Item
#undef Item_hxx
#undef TCollection_ListNode
#undef TCollection_ListNode_hxx
#undef TCollection_ListIterator
#undef TCollection_ListIterator_hxx
#undef Handle_TCollection_ListNode
#undef TCollection_ListNode_Type_
#undef TCollection_List
#undef TCollection_List_hxx




#endif // _DDF_ListIteratorOfTransactionStack_HeaderFile
