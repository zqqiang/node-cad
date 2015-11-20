// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepVisual_HArray1OfSurfaceStyleElementSelect_HeaderFile
#define _StepVisual_HArray1OfSurfaceStyleElementSelect_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_StepVisual_HArray1OfSurfaceStyleElementSelect.hxx>

#include <StepVisual_Array1OfSurfaceStyleElementSelect.hxx>
#include <MMgt_TShared.hxx>
#include <Standard_Integer.hxx>
class Standard_RangeError;
class Standard_DimensionMismatch;
class Standard_OutOfRange;
class Standard_OutOfMemory;
class StepVisual_SurfaceStyleElementSelect;
class StepVisual_Array1OfSurfaceStyleElementSelect;



class StepVisual_HArray1OfSurfaceStyleElementSelect : public MMgt_TShared
{

public:

  
    StepVisual_HArray1OfSurfaceStyleElementSelect(const Standard_Integer Low, const Standard_Integer Up);
  
    StepVisual_HArray1OfSurfaceStyleElementSelect(const Standard_Integer Low, const Standard_Integer Up, const StepVisual_SurfaceStyleElementSelect& V);
  
      void Init (const StepVisual_SurfaceStyleElementSelect& V) ;
  
      Standard_Integer Length()  const;
  
      Standard_Integer Lower()  const;
  
      Standard_Integer Upper()  const;
  
      void SetValue (const Standard_Integer Index, const StepVisual_SurfaceStyleElementSelect& Value) ;
  
     const  StepVisual_SurfaceStyleElementSelect& Value (const Standard_Integer Index)  const;
  
      StepVisual_SurfaceStyleElementSelect& ChangeValue (const Standard_Integer Index) ;
  
     const  StepVisual_Array1OfSurfaceStyleElementSelect& Array1()  const;
  
      StepVisual_Array1OfSurfaceStyleElementSelect& ChangeArray1() ;




  DEFINE_STANDARD_RTTI(StepVisual_HArray1OfSurfaceStyleElementSelect)

protected:




private: 


  StepVisual_Array1OfSurfaceStyleElementSelect myArray;


};

#define ItemHArray1 StepVisual_SurfaceStyleElementSelect
#define ItemHArray1_hxx <StepVisual_SurfaceStyleElementSelect.hxx>
#define TheArray1 StepVisual_Array1OfSurfaceStyleElementSelect
#define TheArray1_hxx <StepVisual_Array1OfSurfaceStyleElementSelect.hxx>
#define TCollection_HArray1 StepVisual_HArray1OfSurfaceStyleElementSelect
#define TCollection_HArray1_hxx <StepVisual_HArray1OfSurfaceStyleElementSelect.hxx>
#define Handle_TCollection_HArray1 Handle_StepVisual_HArray1OfSurfaceStyleElementSelect
#define TCollection_HArray1_Type_() StepVisual_HArray1OfSurfaceStyleElementSelect_Type_()

#include <TCollection_HArray1.lxx>

#undef ItemHArray1
#undef ItemHArray1_hxx
#undef TheArray1
#undef TheArray1_hxx
#undef TCollection_HArray1
#undef TCollection_HArray1_hxx
#undef Handle_TCollection_HArray1
#undef TCollection_HArray1_Type_




#endif // _StepVisual_HArray1OfSurfaceStyleElementSelect_HeaderFile
