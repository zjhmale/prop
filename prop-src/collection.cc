///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.6),
//  last updated on Nov 2, 1999.
//  The original source file is "collection.pcc".
///////////////////////////////////////////////////////////////////////////////

#line 1 "collection.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements the analysis and type inference methods for
//  SETL-style collection types.
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "collection.h"
#include "type.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Instantiate the collection type descriptor.
//
///////////////////////////////////////////////////////////////////////////////
#line 16 "collection.pcc"
#line 16 "collection.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype CollectionDesc
//
///////////////////////////////////////////////////////////////////////////////
#line 16 "collection.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<CollectionDesc>
//
///////////////////////////////////////////////////////////////////////////////
#line 16 "collection.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype CollectionDesc
//
///////////////////////////////////////////////////////////////////////////////
#line 16 "collection.pcc"
a_CollectionDesc::a_CollectionDesc (Id x_name, CollectionAttrib x_attrib, CollectionRep x_rep)
 : name(x_name), attrib(x_attrib), rep(x_rep)
{
}
a_CollectionDesc * COLdesc (Id x_name, CollectionAttrib x_attrib, CollectionRep x_rep)
{
   return new a_CollectionDesc (x_name, x_attrib, x_rep);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<CollectionDesc>
//
///////////////////////////////////////////////////////////////////////////////
#line 16 "collection.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<CollectionDesc>;
template a_List<CollectionDesc> * list_1_(CollectionDesc x_1, a_List<CollectionDesc> *  x_2);
template a_List<CollectionDesc> * list_1_(CollectionDesc x_list_1_);
template int boxed(const a_List<CollectionDesc> *);
template int untag(const a_List<CollectionDesc> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

#line 16 "collection.pcc"
#line 16 "collection.pcc"


///////////////////////////////////////////////////////////////////////////////
//
//  Functions for constructing some SETL-like type constructors.
//
///////////////////////////////////////////////////////////////////////////////
Ty mklistty (Ty a)         
{  return TYCONty(COLtycon(
#line 24 "collection.pcc"
#line 24 "collection.pcc"
COLdesc("list", COLLECTION_NONE, REP_none)
#line 24 "collection.pcc"
#line 24 "collection.pcc"
), 
#line 24 "collection.pcc"
#line 24 "collection.pcc"
list_1_(a)
#line 24 "collection.pcc"
#line 24 "collection.pcc"
); }
                             
Ty mksetty (Ty a)         
{  return TYCONty(COLtycon(
#line 27 "collection.pcc"
#line 27 "collection.pcc"
COLdesc("set", COLLECTION_NONE, REP_none)
#line 27 "collection.pcc"
#line 27 "collection.pcc"
), 
#line 27 "collection.pcc"
#line 27 "collection.pcc"
list_1_(a)
#line 27 "collection.pcc"
#line 27 "collection.pcc"
); }

Ty mkbagty (Ty a)         
{  return TYCONty(COLtycon(
#line 30 "collection.pcc"
#line 30 "collection.pcc"
COLdesc("bag", COLLECTION_NONE, REP_none)
#line 30 "collection.pcc"
#line 30 "collection.pcc"
), 
#line 30 "collection.pcc"
#line 30 "collection.pcc"
list_1_(a)
#line 30 "collection.pcc"
#line 30 "collection.pcc"
); }

Ty mkmapty (Ty a, Ty b)   
{  return TYCONty(COLtycon(
#line 33 "collection.pcc"
#line 33 "collection.pcc"
COLdesc("bag", COLLECTION_NONE, REP_none)
#line 33 "collection.pcc"
#line 33 "collection.pcc"
), 
#line 33 "collection.pcc"
#line 33 "collection.pcc"
list_1_(a,list_1_(b))
#line 33 "collection.pcc"
#line 33 "collection.pcc"
); }

Ty mkmultimapty (Ty a, Ty b)   
{  return TYCONty(COLtycon(
#line 36 "collection.pcc"
#line 36 "collection.pcc"
COLdesc("bag", COLLECTION_NONE, REP_none)
#line 36 "collection.pcc"
#line 36 "collection.pcc"
), 
#line 36 "collection.pcc"
#line 36 "collection.pcc"
list_1_(a,list_1_(b))
#line 36 "collection.pcc"
#line 36 "collection.pcc"
); }

Ty mkqueuety (Ty a)         
{  return TYCONty(COLtycon(
#line 39 "collection.pcc"
#line 39 "collection.pcc"
COLdesc("bag", COLLECTION_NONE, REP_none)
#line 39 "collection.pcc"
#line 39 "collection.pcc"
), 
#line 39 "collection.pcc"
#line 39 "collection.pcc"
list_1_(a)
#line 39 "collection.pcc"
#line 39 "collection.pcc"
); }

Ty mkpriqueuety (Ty a)         
{  return TYCONty(COLtycon(
#line 42 "collection.pcc"
#line 42 "collection.pcc"
COLdesc("bag", COLLECTION_NONE, REP_none)
#line 42 "collection.pcc"
#line 42 "collection.pcc"
), 
#line 42 "collection.pcc"
#line 42 "collection.pcc"
list_1_(a)
#line 42 "collection.pcc"
#line 42 "collection.pcc"
); }

Ty mkdequety (Ty a)        
{  return TYCONty(COLtycon(
#line 45 "collection.pcc"
#line 45 "collection.pcc"
COLdesc("bag", COLLECTION_NONE, REP_none)
#line 45 "collection.pcc"
#line 45 "collection.pcc"
), 
#line 45 "collection.pcc"
#line 45 "collection.pcc"
list_1_(a)
#line 45 "collection.pcc"
#line 45 "collection.pcc"
); }

#line 47 "collection.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 0
Number of ifs generated      = 0
Number of switches generated = 0
Number of labels             = 0
Number of gotos              = 0
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
