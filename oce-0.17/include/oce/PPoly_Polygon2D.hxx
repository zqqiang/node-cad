// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _PPoly_Polygon2D_HeaderFile
#define _PPoly_Polygon2D_HeaderFile

#include <Standard_Macro.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard.hxx>
#include <Handle_PPoly_Polygon2D.hxx>

#include <Standard_Real.hxx>
#include <Standard_Integer.hxx>
#include <Handle_PColgp_HArray1OfPnt2d.hxx>
#include <Standard_Persistent.hxx>
class PColgp_HArray1OfPnt2d;


class PPoly_Polygon2D : public Standard_Persistent
{

public:

  
  //! Defaults with allocation of nodes.
  Standard_EXPORT PPoly_Polygon2D(const Handle(PColgp_HArray1OfPnt2d)& Nodes, const Standard_Real Defl);
  
  Standard_EXPORT   Standard_Real Deflection()  const;
  
  Standard_EXPORT   void Deflection (const Standard_Real Defl) ;
  
  Standard_EXPORT   Standard_Integer NbNodes()  const;
  
  Standard_EXPORT   Handle(PColgp_HArray1OfPnt2d) Nodes()  const;
  
  Standard_EXPORT   void Nodes (const Handle(PColgp_HArray1OfPnt2d)& Nodes) ;

PPoly_Polygon2D( )
{
  
}
PPoly_Polygon2D(const Storage_stCONSTclCOM& a) : Standard_Persistent(a)
{
  
}
    Standard_Real _CSFDB_GetPPoly_Polygon2DmyDeflection() const { return myDeflection; }
    void _CSFDB_SetPPoly_Polygon2DmyDeflection(const Standard_Real p) { myDeflection = p; }
    Handle(PColgp_HArray1OfPnt2d) _CSFDB_GetPPoly_Polygon2DmyNodes() const { return myNodes; }
    void _CSFDB_SetPPoly_Polygon2DmyNodes(const Handle(PColgp_HArray1OfPnt2d)& p) { myNodes = p; }



  DEFINE_STANDARD_RTTI(PPoly_Polygon2D)

protected:




private: 


  Standard_Real myDeflection;
  Handle(PColgp_HArray1OfPnt2d) myNodes;


};







#endif // _PPoly_Polygon2D_HeaderFile
