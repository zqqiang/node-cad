// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Geom2dGcc_FunctionTanCuPnt_HeaderFile
#define _Geom2dGcc_FunctionTanCuPnt_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Geom2dAdaptor_Curve.hxx>
#include <gp_Pnt2d.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Real.hxx>
class Geom2dAdaptor_Curve;
class gp_Pnt2d;


//! This abstract class describes a Function of 1 Variable
//! used to find a line tangent to a curve and passing
//! through a point.
class Geom2dGcc_FunctionTanCuPnt  : public math_FunctionWithDerivative
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT Geom2dGcc_FunctionTanCuPnt(const Geom2dAdaptor_Curve& C, const gp_Pnt2d& Point);
  
  //! Computes the value of the function F for the variable X.
  //! It returns True if the computation is successfully done,
  //! False otherwise.
  Standard_EXPORT   Standard_Boolean Value (const Standard_Real X, Standard_Real& F) ;
  
  //! Computes the derivative of the function F for the variable X.
  //! It returns True if the computation is successfully done,
  //! False otherwise.
  Standard_EXPORT   Standard_Boolean Derivative (const Standard_Real X, Standard_Real& Deriv) ;
  
  //! Computes the value and the derivative of the function F
  //! for the variable X.
  //! It returns True if the computation is successfully done,
  //! False otherwise.
  Standard_EXPORT   Standard_Boolean Values (const Standard_Real X, Standard_Real& F, Standard_Real& Deriv) ;




protected:





private:



  Geom2dAdaptor_Curve TheCurv;
  gp_Pnt2d ThePoint;


};







#endif // _Geom2dGcc_FunctionTanCuPnt_HeaderFile
