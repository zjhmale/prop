///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.6),
//  last updated on Nov 2, 1999.
//  The original source file is "printing.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_STRCMP_USED
#define PROP_QUARK_USED
#include <propdefs.h>
///////////////////////////////////////////////////////////////////////////////
//  Quark literals
///////////////////////////////////////////////////////////////////////////////
static const Quark _p_r_i_n_t_i_n_gco_c_c_Q1("x_");
#line 1 "printing.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements various pretty printing and formating routines.
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <strstream>
#include <AD/contain/bitset.h>
#include <AD/strings/charesc.h>
#include <AD/strings/quark.h>
#include <stdio.h>
#include <ctype.h>
#include "ir.h"
#include "ast.h"
#include "matchcom.h"
#include "type.h"
#include "options.h"
#include "list.h"
#include "graphtype.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Flags controlling printing formats of types.
//
///////////////////////////////////////////////////////////////////////////////
Bool      pretty_print_ty      = true;
Bool      pretty_print_pattern = false;
Bool      pretty_print_exp     = false;
Bool      print_semantic_stack = false;
Bool      print_inner_action   = false;
Bool      print_default_value  = true;
Id        ty_id                = 0;
Parameter ty_parameter         = TYformal;

///////////////////////////////////////////////////////////////////////////////
//
//  Print an identifier list 
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& f, Ids vars)
{  for(Ids vs = vars; vs; vs = vs->_2)
   {  f << vs->_1; if (vs->_2) f << ", "; }
   return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print a scope
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& f, Scope s)
{  
#line 53 "printing.pcc"
#line 57 "printing.pcc"
{
   switch (s) {
      case PRIVATEscope: {
#line 56 "printing.pcc"
      f << "private"; 
         
#line 57 "printing.pcc"
         } break;
      case PROTECTEDscope: {
#line 55 "printing.pcc"
        f << "protected"; 
         
#line 56 "printing.pcc"
         } break;
      default: {
#line 54 "printing.pcc"
     f << "public";
         
#line 55 "printing.pcc"
         } break;
   }
}
#line 57 "printing.pcc"
#line 57 "printing.pcc"

   return f;
}

///////////////////////////////////////////////////////////////////////////////
//  Return the label for an tuple element index
///////////////////////////////////////////////////////////////////////////////
Id index_of(int i,Id prefix) 
{  if (prefix == 0) prefix = "";
   return Quark(Quark(prefix,"_"),i); 
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print a persistent id.
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& f, Pid pid)
{  
#line 75 "printing.pcc"
#line 78 "printing.pcc"
{
   if (pid) {
#line 76 "printing.pcc"
     f << pid->PERSISTid; 
#line 76 "printing.pcc"
   } else {}
}
#line 78 "printing.pcc"
#line 78 "printing.pcc"

   return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print a literal.
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& f, Literal l)
{  
#line 88 "printing.pcc"
#line 109 "printing.pcc"
{
   switch (l->tag__) {
      case a_Literal::tag_INTlit: {
#line 89 "printing.pcc"
        f << ((Literal_INTlit *)l)->INTlit; 
#line 89 "printing.pcc"
         } break;
      case a_Literal::tag_BOOLlit: {
#line 90 "printing.pcc"
        f << (((Literal_BOOLlit *)l)->BOOLlit ? "true" : "false"); 
#line 90 "printing.pcc"
         } break;
      case a_Literal::tag_CHARlit: {
#line 91 "printing.pcc"
        char b[32]; print_char(b,((Literal_CHARlit *)l)->CHARlit); f << '\'' << b << '\''; 
#line 91 "printing.pcc"
         } break;
      case a_Literal::tag_REALlit: {
#line 93 "printing.pcc"
       // use sprintf due to library problems in libg++ 2.5.8 on Linux
         char buf[256];
         sprintf(buf,"%lf", ((Literal_REALlit *)l)->REALlit);
         f << buf; 
         // ostrstream S(buf,sizeof(buf));
         // std::ostream& S2 = S;
         // S2 << r << ends;
         // f << S.str(); 
         
#line 101 "printing.pcc"
         } break;
      case a_Literal::tag_STRINGlit: {
#line 102 "printing.pcc"
        f << ((Literal_STRINGlit *)l)->STRINGlit; 
#line 102 "printing.pcc"
         } break;
      case a_Literal::tag_REGEXPlit: {
#line 103 "printing.pcc"
        f << ((Literal_REGEXPlit *)l)->REGEXPlit; 
#line 103 "printing.pcc"
         } break;
      case a_Literal::tag_QUARKlit: {
#line 104 "printing.pcc"
        if (pretty_print_pattern) f << '#' << ((Literal_QUARKlit *)l)->QUARKlit;
         else f << MatchCompiler::quark_name(((Literal_QUARKlit *)l)->QUARKlit); 
         
#line 106 "printing.pcc"
         } break;
      default: {
#line 107 "printing.pcc"
        if (pretty_print_pattern) f << "#" << ((Literal_BIGINTlit *)l)->BIGINTlit;
         else f << ((Literal_BIGINTlit *)l)->BIGINTlit; 
         
#line 109 "printing.pcc"
         } break;
   }
}
#line 110 "printing.pcc"
#line 110 "printing.pcc"

   return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print type list.
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& f, Tys tys)
{  for(Tys t = tys; t; t = t->_2) {  
      f << t->_1; 
      if (t->_2 != 
#line 122 "printing.pcc"
#line 122 "printing.pcc"
nil_1_
#line 122 "printing.pcc"
#line 122 "printing.pcc"
) f << ", "; 
   }
   return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print type variables (i.e. template actual arguments)
//
///////////////////////////////////////////////////////////////////////////////
void print_tyvars(std::ostream& f, Tys tys, Bool is_datatype)
{  if (tys != 
#line 133 "printing.pcc"
#line 133 "printing.pcc"
nil_1_
#line 133 "printing.pcc"
#line 133 "printing.pcc"
) 
      if (is_datatype) f << "(" << tys << ")";
      else             f << '<' << tys << "> ";
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print type variables (i.e. formal template arguments)
//
///////////////////////////////////////////////////////////////////////////////
void print_tyvars(std::ostream& f, TyVars tyvars, char open, char close, Bool header)
{  if (tyvars != 
#line 144 "printing.pcc"
#line 144 "printing.pcc"
nil_1_
#line 144 "printing.pcc"
#line 144 "printing.pcc"
) {
      if (header) f << "template ";
      f << open;
      for(TyVars t = tyvars; t; t = t->_2) {
         if (header) f << "class ";
         f << t->_1;
         if (t->_2) f << ", ";
      }
      f << close;
      if (header) f << ' ';
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print a tuple type.
//
///////////////////////////////////////////////////////////////////////////////
void print_tuple(std::ostream& f, Tys tys)
{  if (pretty_print_ty) {
      f << '(' << tys << ')';
   } else {
      f << "struct {";
      int i = 1;
      for (Tys t = tys; t; t = t->_2) {
         ty_id = index_of(i);
         f << t->_1 << "; ";
         ty_id = 
#line 171 "printing.pcc"
#line 171 "printing.pcc"
nil_1_
#line 171 "printing.pcc"
#line 171 "printing.pcc"
;
      }
      f << "} ";
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print a mktuple type
//
///////////////////////////////////////////////////////////////////////////////
void print_mktuple(std::ostream& f, Tys tys)
{  if (pretty_print_ty) {
      f << ".[" << tys << ']';
   } else {
      f << "Tuple" << length(tys); 
      print_tyvars(f,tys,false); 
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print a record type.
//
///////////////////////////////////////////////////////////////////////////////
void print_record(std::ostream& f, Ids labs, Tys tys, Bool flex)
{  if (! pretty_print_ty) f << "struct ";
   f << "{ ";
   Tys t; Ids l;
   for (t = tys, l = labs; t && l; t = t->_2, l = l->_2) {
      if (pretty_print_ty) {
         f << l->_1 << " : " << t->_1;
         if (t->_2) f << ", ";
      } else {
         ty_id = l->_1; f << t->_1 << "; ";
         ty_id = 
#line 206 "printing.pcc"
#line 206 "printing.pcc"
nil_1_
#line 206 "printing.pcc"
#line 206 "printing.pcc"
;
      }
   }
   if (pretty_print_ty && flex) f << " ... ";
   f << " }";
}

///////////////////////////////////////////////////////////////////////////////
//
//  Print a function parameter.
//
///////////////////////////////////////////////////////////////////////////////
void print_parameter (std::ostream& f, Ty ty, Id id, Parameter p)
{  Parameter save = ty_parameter;
   Bool      sp = pretty_print_ty;
   pretty_print_ty = false;
   ty_parameter = p;
   
#line 223 "printing.pcc"
#line 269 "printing.pcc"
{
   Ty _V1 = deref(ty);
   if (_V1) {
      switch (_V1->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V1)->_1)) {
               switch (((Ty_TYCONty *)_V1)->_1->tag__) {
                  case a_TyCon::tag_RECORDtycon: {
#line 241 "printing.pcc"
                   Ids l;
                     Tys t;
                     if (p == TYformal || p == TYsimpleformal ||
                     	     p == TYactual && ((Ty_TYCONty *)_V1)->_2 != 
#line 244 "printing.pcc"
#line 244 "printing.pcc"
                     nil_1_
#line 244 "printing.pcc"
#line 244 "printing.pcc"
                     ) f << '(';
                     for (l = ((TyCon_RECORDtycon *)((Ty_TYCONty *)_V1)->_1)->_1, t = ((Ty_TYCONty *)_V1)->_2; l && t; l = l->_2, t = t->_2) {
                        if (p != TYbody) 
                           ty_id = 
#line 247 "printing.pcc"
#line 247 "printing.pcc"
                     _p_r_i_n_t_i_n_gco_c_c_Q1
#line 247 "printing.pcc"
#line 247 "printing.pcc"
                    + l->_1;
                     else
                        ty_id = l->_1;
                     if (p != TYactual) f << t->_1;
                     else f << ty_id;
                     if (p != TYbody) { if (t->_2) f << ", "; }
                     else f << "; ";
                     ty_id = 
#line 254 "printing.pcc"
#line 254 "printing.pcc"
                     nil_1_
#line 254 "printing.pcc"
#line 254 "printing.pcc"
                     ;
                     }
                     if (p == TYformal || p == TYsimpleformal ||
                     	     p == TYactual && ((Ty_TYCONty *)_V1)->_2 != 
#line 257 "printing.pcc"
#line 257 "printing.pcc"
                     nil_1_
#line 257 "printing.pcc"
#line 257 "printing.pcc"
                     ) f << ')';
                     
#line 258 "printing.pcc"
                     } break;
                  default: {
                     L1:; 
#line 259 "printing.pcc"
                   if (p != TYbody) f << '(';
                     if (p != TYbody) 
                        ty_id = 
#line 261 "printing.pcc"
#line 261 "printing.pcc"
                     _p_r_i_n_t_i_n_gco_c_c_Q1
#line 261 "printing.pcc"
#line 261 "printing.pcc"
                    + id;
                     else
                        ty_id = id;
                     if (p != TYactual) f << _V1;
                     else f << ty_id;
                     if (p == TYbody) f << "; "; 
                     ty_id = 0;
                     if (p != TYbody) f << ')';
                     
#line 269 "printing.pcc"
                     } break;
               }
            } else {
               switch ((int)((Ty_TYCONty *)_V1)->_1) {
                  case ((int)TUPLEtycon): {
#line 225 "printing.pcc"
                   int i = 1;
                     if (p == TYformal || p == TYsimpleformal || 
                     	     p == TYactual && ((Ty_TYCONty *)_V1)->_2 != 
#line 227 "printing.pcc"
#line 227 "printing.pcc"
                     nil_1_
#line 227 "printing.pcc"
#line 227 "printing.pcc"
                     ) f << '(';
                     for (Tys ts = ((Ty_TYCONty *)_V1)->_2; ts; ts = ts->_2) {
                        ty_id = index_of(i,(p != TYbody ? "x" : ""));  
                        if (p != TYactual) f << ts->_1;
                        else f << ty_id;
                        if (p != TYbody) { if (ts->_2) f << ", "; }
                        else f << "; ";
                        i++;
                        ty_id = 
#line 235 "printing.pcc"
#line 235 "printing.pcc"
                     nil_1_
#line 235 "printing.pcc"
#line 235 "printing.pcc"
                     ;
                     } 
                     if (p == TYformal || p == TYsimpleformal ||
                     	     p == TYactual && ((Ty_TYCONty *)_V1)->_2 != 
#line 238 "printing.pcc"
#line 238 "printing.pcc"
                     nil_1_
#line 238 "printing.pcc"
#line 238 "printing.pcc"
                     ) f << ')';
                     
#line 239 "printing.pcc"
                     } break;
                  default: { goto L1; } break;
               }
            }
            } break;
         default: { goto L1; } break;
      }
   } else { goto L1; }
}
#line 270 "printing.pcc"
#line 270 "printing.pcc"

   ty_parameter = save;
   pretty_print_ty = sp;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print a type expression.
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& f, Ty ty)
{  Id this_id = 0;
   if (ty_id) { this_id = ty_id; ty_id = 0; }
   ty = deref(ty);
   
#line 284 "printing.pcc"
#line 350 "printing.pcc"
{
   if (ty) {
      switch (ty->tag__) {
         case a_Ty::tag_VARty: {
#line 286 "printing.pcc"
           f << "???"; 
#line 286 "printing.pcc"
            } break;
         case a_Ty::tag_INDty: {
#line 287 "printing.pcc"
           f << ((Ty_INDty *)ty)->_1; 
#line 287 "printing.pcc"
            } break;
         case a_Ty::tag_QUALty: {
#line 331 "printing.pcc"
          if (((Ty_QUALty *)ty)->_1 & QUALunsigned) f << "unsigned ";
            if (((Ty_QUALty *)ty)->_1 & QUALsigned)   f << "signed ";
            if ((ty_parameter == TYformal || ty_parameter == TYsimpleformal)
            	     && (((Ty_QUALty *)ty)->_1 & QUALclass)) 
               f << (TYCONty(REFtycon,
#line 335 "printing.pcc"
#line 335 "printing.pcc"
            list_1_(QUALty(QUALconst,((Ty_QUALty *)ty)->_2))
#line 335 "printing.pcc"
#line 335 "printing.pcc"
            ));
            else 
               f << ((Ty_QUALty *)ty)->_2; 
            if (((Ty_QUALty *)ty)->_1 & QUALconst)    f << " const";
            
#line 339 "printing.pcc"
            } break;
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)ty)->_1)) {
               switch (((Ty_TYCONty *)ty)->_1->tag__) {
                  case a_TyCon::tag_IDtycon: {
#line 300 "printing.pcc"
                   if (options.new_type_format && ((Ty_TYCONty *)ty)->_2 != 
#line 300 "printing.pcc"
#line 300 "printing.pcc"
                     nil_1_
#line 300 "printing.pcc"
#line 300 "printing.pcc"
                     )
                     {  
#line 301 "printing.pcc"
#line 310 "printing.pcc"
                     {
                        Ty _V2 = deref_all(ty);
                        if (_V2) {
                           switch (_V2->tag__) {
                              case a_Ty::tag_TYCONty: {
                                 if (boxed(((Ty_TYCONty *)_V2)->_1)) {
                                    switch (((Ty_TYCONty *)_V2)->_1->tag__) {
                                       case a_TyCon::tag_DATATYPEtycon: {
#line 303 "printing.pcc"
                                        if (! pretty_print_ty) f << "a_";
                                          f << ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V2)->_1)->id; print_tyvars(f,((Ty_TYCONty *)ty)->_2,false); 
                                          if (! pretty_print_ty) 
                                          {  if (((Ty_TYCONty *)ty)->_2 == 
#line 306 "printing.pcc"
#line 306 "printing.pcc"
                                          nil_1_
#line 306 "printing.pcc"
#line 306 "printing.pcc"
                                          ) f << ' ';
                                          f << "* ";
                                          }
                                          
#line 309 "printing.pcc"
                                          } break;
                                       default: {
                                          L2:; 
#line 310 "printing.pcc"
                                         f << ((TyCon_IDtycon *)((Ty_TYCONty *)ty)->_1)->IDtycon; print_tyvars(f,((Ty_TYCONty *)ty)->_2,false); 
#line 310 "printing.pcc"
                                          } break;
                                    }
                                 } else { goto L2; }
                                 } break;
                              default: { goto L2; } break;
                           }
                        } else { goto L2; }
                     }
#line 311 "printing.pcc"
#line 311 "printing.pcc"
                     
                     } else
                     {  f << ((TyCon_IDtycon *)((Ty_TYCONty *)ty)->_1)->IDtycon;
                        
#line 314 "printing.pcc"
#line 316 "printing.pcc"
                     {
                        Ty _V3 = deref_all(ty);
                        if (_V3) {
                           switch (_V3->tag__) {
                              case a_Ty::tag_TYCONty: {
                                 if (boxed(((Ty_TYCONty *)_V3)->_1)) {
                                    switch (((Ty_TYCONty *)_V3)->_1->tag__) {
                                       case a_TyCon::tag_DATATYPEtycon: {
#line 315 "printing.pcc"
                                         print_tyvars(f,((Ty_TYCONty *)ty)->_2,! pretty_print_ty); 
#line 315 "printing.pcc"
                                          } break;
                                       default: {
                                          L3:; 
#line 316 "printing.pcc"
                                         print_tyvars(f,((Ty_TYCONty *)ty)->_2,false); 
#line 316 "printing.pcc"
                                          } break;
                                    }
                                 } else { goto L3; }
                                 } break;
                              default: { goto L3; } break;
                           }
                        } else { goto L3; }
                     }
#line 317 "printing.pcc"
#line 317 "printing.pcc"
                     
                     }
                     
#line 319 "printing.pcc"
                     } break;
                  case a_TyCon::tag_RECORDtycon: {
#line 298 "printing.pcc"
                    print_record(f,((TyCon_RECORDtycon *)((Ty_TYCONty *)ty)->_1)->_1,((Ty_TYCONty *)ty)->_2,((TyCon_RECORDtycon *)((Ty_TYCONty *)ty)->_1)->_2); 
#line 298 "printing.pcc"
                     } break;
                  case a_TyCon::tag_ARRAYtycon: {
                     if (((Ty_TYCONty *)ty)->_2) {
                        if (((Ty_TYCONty *)ty)->_2->_2) {
                           L4:; 
#line 350 "printing.pcc"
                          bug ("operator << (std::ostream&, Ty)");
#line 350 "printing.pcc"
                        } else {
#line 321 "printing.pcc"
                         if (this_id) { ty_id = this_id; this_id = 0; }
                           f << ((Ty_TYCONty *)ty)->_2->_1 << '[' << ((TyCon_ARRAYtycon *)((Ty_TYCONty *)ty)->_1)->ARRAYtycon << ']'; 
                           
#line 323 "printing.pcc"
                        }
                     } else { goto L4; }
                     } break;
                  case a_TyCon::tag_DATATYPEtycon: {
                     if (((Ty_TYCONty *)ty)->_2) {
#line 342 "printing.pcc"
                      if (! pretty_print_ty) f << "a_";
                        f << ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)ty)->_1)->id; print_tyvars(f,((Ty_TYCONty *)ty)->_2,false); 
                        if (! pretty_print_ty) 
                        {  if (((Ty_TYCONty *)ty)->_2 == 
#line 345 "printing.pcc"
#line 345 "printing.pcc"
                        nil_1_
#line 345 "printing.pcc"
#line 345 "printing.pcc"
                        ) f << ' ';
                        f << "* ";
                        }
                        
#line 348 "printing.pcc"
                     } else {
#line 340 "printing.pcc"
                       f << ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)ty)->_1)->id; 
#line 340 "printing.pcc"
                     }
                     } break;
                  case a_TyCon::tag_GRAPHtycon: {
#line 293 "printing.pcc"
                    f << ((TyCon_GRAPHtycon *)((Ty_TYCONty *)ty)->_1)->GRAPHtycon->class_name; 
#line 293 "printing.pcc"
                     } break;
                  case a_TyCon::tag_NODEtycon: {
#line 294 "printing.pcc"
                    f << ((TyCon_NODEtycon *)((Ty_TYCONty *)ty)->_1)->NODEtycon->graph()->class_name <<"::"<< ((TyCon_NODEtycon *)((Ty_TYCONty *)ty)->_1)->NODEtycon->name(); 
#line 294 "printing.pcc"
                     } break;
                  case a_TyCon::tag_EDGEtycon: {
#line 295 "printing.pcc"
                    f << "edge " << ((TyCon_EDGEtycon *)((Ty_TYCONty *)ty)->_1)->EDGEtycon->name(); 
#line 295 "printing.pcc"
                     } break;
                  default: { goto L4; } break;
               }
            } else {
               switch ((int)((Ty_TYCONty *)ty)->_1) {
                  case ((int)POINTERtycon): {
                     if (((Ty_TYCONty *)ty)->_2) {
                        if (((Ty_TYCONty *)ty)->_2->_2) { goto L4; } else {
#line 290 "printing.pcc"
                          f << ((Ty_TYCONty *)ty)->_2->_1 << " *"; 
#line 290 "printing.pcc"
                        }
                     } else { goto L4; }
                     } break;
                  case ((int)REFtycon): {
                     if (((Ty_TYCONty *)ty)->_2) {
                        if (((Ty_TYCONty *)ty)->_2->_2) { goto L4; } else {
#line 291 "printing.pcc"
                          f << ((Ty_TYCONty *)ty)->_2->_1 << " &"; 
#line 291 "printing.pcc"
                        }
                     } else { goto L4; }
                     } break;
                  case ((int)TUPLEtycon): {
#line 296 "printing.pcc"
                    print_tuple(f,((Ty_TYCONty *)ty)->_2); 
#line 296 "printing.pcc"
                     } break;
                  case ((int)EXTUPLEtycon): {
#line 297 "printing.pcc"
                    print_mktuple(f,((Ty_TYCONty *)ty)->_2); 
#line 297 "printing.pcc"
                     } break;
                  case ((int)FUNtycon): {
                     if (((Ty_TYCONty *)ty)->_2) {
                        if (((Ty_TYCONty *)ty)->_2->_2) {
                           if (((Ty_TYCONty *)ty)->_2->_2->_2) { goto L4; } else {
#line 292 "printing.pcc"
                             f << ((Ty_TYCONty *)ty)->_2->_1 << " -> " << ((Ty_TYCONty *)ty)->_2->_2->_1; 
#line 292 "printing.pcc"
                           }
                        } else { goto L4; }
                     } else { goto L4; }
                     } break;
                  default: {
                     if (((Ty_TYCONty *)ty)->_2) { goto L4; } else {
#line 289 "printing.pcc"
                       f << "type"; 
#line 289 "printing.pcc"
                     }
                     } break;
               }
            }
            } break;
         case a_Ty::tag_POLYty: {
#line 288 "printing.pcc"
           f << ((Ty_POLYty *)ty)->_1; 
#line 288 "printing.pcc"
            } break;
         case a_Ty::tag_DEFVALty: {
#line 325 "printing.pcc"
          if (this_id) { ty_id = this_id; this_id = 0; }
            f << ((Ty_DEFVALty *)ty)->_1;
            if (ty_parameter != TYbody && ty_parameter != TYsimpleformal 
            	   && print_default_value) f << " = " << ((Ty_DEFVALty *)ty)->_2; 
            
#line 329 "printing.pcc"
            } break;
         default: {
#line 349 "printing.pcc"
           f << ((Ty_NESTEDty *)ty)->_1 << "::" << ((Ty_NESTEDty *)ty)->_2; 
#line 349 "printing.pcc"
            } break;
      }
   } else {
#line 285 "printing.pcc"
     f << "error"; 
#line 285 "printing.pcc"
   }
}
#line 351 "printing.pcc"
#line 351 "printing.pcc"

   if (this_id) f << ' ' << this_id; 
   return f;
}


///////////////////////////////////////////////////////////////////////////////
//
//  Method to print a pattern list.
//
///////////////////////////////////////////////////////////////////////////////
void print (std::ostream& f, Pats pats, Id open, Id close,
            Bool flex1, Pat p, Bool flex2 = false, 
            Pat len = NOpat, Pat array = NOpat)
{  f << open;
   if (len != NOpat)   
   {  f << " |" << len;
      if (array != NOpat) f << " : " << array; 
      f << " |";
   }
   if (flex2) f << " ... ";
   for (Pats ps = pats; ps; ps = ps->_2) {
      f << ps->_1;
      if (ps->_2) f << ", ";
   }
   if (flex1 && pats != 
#line 376 "printing.pcc"
#line 376 "printing.pcc"
nil_1_
#line 376 "printing.pcc"
#line 376 "printing.pcc"
 && p != NOpat) f << " ... ";
   if (p != NOpat) f << p;
   f << close;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print a labeled pattern list.
//
///////////////////////////////////////////////////////////////////////////////
void print (std::ostream& f, LabPats lab_pats, Bool flex)
{  f << '{';
   for (LabPats ps = lab_pats; ps; ps = ps->_2) {
      f << ps->_1.label << " = " << ps->_1.pat;
      if (ps->_2) f << ", ";
   }
   f << '}';
}

///////////////////////////////////////////////////////////////////////////////
//
//  Methods extract the open and close brace of a list.
//
///////////////////////////////////////////////////////////////////////////////
Id open_of(Cons c) 
{  
#line 401 "printing.pcc"
#line 406 "printing.pcc"
{
   if (c) {
#line 402 "printing.pcc"
     char s[3]; 
      s[0] = c->name[0]; s[1] = c->name[1]; s[2] = '\0';
      return Quark(s); 
      
#line 405 "printing.pcc"
   } else {
#line 406 "printing.pcc"
     return "<??>["; 
#line 406 "printing.pcc"
   }
}
#line 407 "printing.pcc"
#line 407 "printing.pcc"
 
}

Id close_of(Cons c)
{  
#line 411 "printing.pcc"
#line 413 "printing.pcc"
{
   if (c) {
#line 412 "printing.pcc"
     return c->name+2; 
#line 412 "printing.pcc"
   } else {
#line 413 "printing.pcc"
     return "]"; 
#line 413 "printing.pcc"
   }
}
#line 414 "printing.pcc"
#line 414 "printing.pcc"
 
}

Id close_of2(Cons c)
{  
#line 418 "printing.pcc"
#line 420 "printing.pcc"
{
   if (c) {
#line 419 "printing.pcc"
     return c->name+strlen(c->name)-2; 
#line 419 "printing.pcc"
   } else {
#line 420 "printing.pcc"
     return "]"; 
#line 420 "printing.pcc"
   }
}
#line 421 "printing.pcc"
#line 421 "printing.pcc"
 
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print a pattern list.
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& f, Pats ps)
{  print(f,ps,"","",false,NOpat); return f; }

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print a pattern.
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& f, Pat p)
{  
#line 438 "printing.pcc"
#line 486 "printing.pcc"
{
   if (p) {
      switch (p->tag__) {
         case a_Pat::tag_WILDpat: {
#line 440 "printing.pcc"
           f << '_'; 
#line 440 "printing.pcc"
            } break;
         case a_Pat::tag_INDpat: {
#line 443 "printing.pcc"
           f << '?' << ((Pat_INDpat *)p)->_1; 
#line 443 "printing.pcc"
            } break;
         case a_Pat::tag_POLYpat: {
            if (((Pat_POLYpat *)p)->_3) {
#line 468 "printing.pcc"
              f << ((Pat_POLYpat *)p)->_1 << '(' << ((Pat_POLYpat *)p)->_3 << ") = " << ((Pat_POLYpat *)p)->_4; 
#line 468 "printing.pcc"
            } else {
#line 467 "printing.pcc"
              f << ((Pat_POLYpat *)p)->_1 << " = " << ((Pat_POLYpat *)p)->_4; 
#line 467 "printing.pcc"
            }
            } break;
         case a_Pat::tag_IDpat: {
#line 442 "printing.pcc"
           f << ((Pat_IDpat *)p)->_1; 
#line 442 "printing.pcc"
            } break;
         case a_Pat::tag_CONSpat: {
            if (((Pat_CONSpat *)p)->CONSpat) {
               if (((Pat_CONSpat *)p)->CONSpat->alg_ty) {
                  switch (((Pat_CONSpat *)p)->CONSpat->alg_ty->tag__) {
                     case a_Ty::tag_TYCONty: {
                        if (boxed(((Ty_TYCONty *)((Pat_CONSpat *)p)->CONSpat->alg_ty)->_1)) {
                           switch (((Ty_TYCONty *)((Pat_CONSpat *)p)->CONSpat->alg_ty)->_1->tag__) {
                              case a_TyCon::tag_DATATYPEtycon: {
                                 if (
#line 461 "printing.pcc"
                                 (((Pat_CONSpat *)p)->CONSpat->qual & QUALvariable)
#line 461 "printing.pcc"
) {
                                    
#line 462 "printing.pcc"
                                   f << ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)p)->CONSpat->alg_ty)->_1)->id << "?"; 
#line 462 "printing.pcc"
                                 } else {
                                    
                                    L5:; 
#line 463 "printing.pcc"
                                   f << ((Pat_CONSpat *)p)->CONSpat->name; 
#line 463 "printing.pcc"
                                 }
                                 } break;
                              default: { goto L5; } break;
                           }
                        } else { goto L5; }
                        } break;
                     default: { goto L5; } break;
                  }
               } else { goto L5; }
            } else {
#line 464 "printing.pcc"
              f << "<none>"; 
#line 464 "printing.pcc"
            }
            } break;
         case a_Pat::tag_APPpat: {
#line 465 "printing.pcc"
           f << ((Pat_APPpat *)p)->_1 << ' ' << ((Pat_APPpat *)p)->_2; 
#line 465 "printing.pcc"
            } break;
         case a_Pat::tag_TYPEDpat: {
#line 445 "printing.pcc"
           f << ((Pat_TYPEDpat *)p)->_1 << " : " << ((Pat_TYPEDpat *)p)->_2; 
#line 445 "printing.pcc"
            } break;
         case a_Pat::tag_ASpat: {
#line 444 "printing.pcc"
           f << ((Pat_ASpat *)p)->_1 << " as " << ((Pat_ASpat *)p)->_2; 
#line 444 "printing.pcc"
            } break;
         case a_Pat::tag_LITERALpat: {
#line 482 "printing.pcc"
          Bool save = pretty_print_pattern;
            pretty_print_pattern = true;
            f << ((Pat_LITERALpat *)p)->LITERALpat;
            pretty_print_pattern = save;
            
#line 486 "printing.pcc"
            } break;
         case a_Pat::tag_CONTEXTpat: {
#line 474 "printing.pcc"
          f << "<<";
            for (Conses ids = ((Pat_CONTEXTpat *)p)->_1; ids; ids = ids->_2)
            {  if (ids->_1 != NOcons) f << ids->_1->name; 
               if (ids->_2) f << ", "; 
            }
            f << ">>" << ((Pat_CONTEXTpat *)p)->_2;
            
#line 480 "printing.pcc"
            } break;
         case a_Pat::tag_LEXEMEpat: {
#line 466 "printing.pcc"
           f << "lexeme class " << ((Pat_LEXEMEpat *)p)->_1; 
#line 466 "printing.pcc"
            } break;
         case a_Pat::tag_ARRAYpat: {
#line 448 "printing.pcc"
           print(f,((Pat_ARRAYpat *)p)->_1,"[","]",((Pat_ARRAYpat *)p)->_2,NOpat); 
#line 448 "printing.pcc"
            } break;
         case a_Pat::tag_TUPLEpat: {
#line 446 "printing.pcc"
           print(f,((Pat_TUPLEpat *)p)->TUPLEpat,"(",")",false,NOpat); 
#line 446 "printing.pcc"
            } break;
         case a_Pat::tag_EXTUPLEpat: {
#line 447 "printing.pcc"
           print(f,((Pat_EXTUPLEpat *)p)->EXTUPLEpat,".(",")",false,NOpat); 
#line 447 "printing.pcc"
            } break;
         case a_Pat::tag_RECORDpat: {
#line 449 "printing.pcc"
           print(f,((Pat_RECORDpat *)p)->_1,((Pat_RECORDpat *)p)->_2); 
#line 449 "printing.pcc"
            } break;
         case a_Pat::tag_LISTpat: {
#line 472 "printing.pcc"
           print(f,((Pat_LISTpat *)p)->head,open_of(((Pat_LISTpat *)p)->nil),close_of(((Pat_LISTpat *)p)->nil),true,((Pat_LISTpat *)p)->tail); 
#line 472 "printing.pcc"
            } break;
         case a_Pat::tag_VECTORpat: {
#line 470 "printing.pcc"
           print(f,((Pat_VECTORpat *)p)->elements,open_of(((Pat_VECTORpat *)p)->cons),close_of2(((Pat_VECTORpat *)p)->cons),((Pat_VECTORpat *)p)->tail_flex,NOpat,((Pat_VECTORpat *)p)->head_flex,((Pat_VECTORpat *)p)->len,((Pat_VECTORpat *)p)->array); 
#line 470 "printing.pcc"
            } break;
         case a_Pat::tag_APPENDpat: {
#line 457 "printing.pcc"
           f << '(' << ((Pat_APPENDpat *)p)->_1 << " ; " << ((Pat_APPENDpat *)p)->_2 << ')'; 
#line 457 "printing.pcc"
            } break;
         case a_Pat::tag_GUARDpat: {
#line 456 "printing.pcc"
           f << ((Pat_GUARDpat *)p)->_1 << " | " << ((Pat_GUARDpat *)p)->_2; 
#line 456 "printing.pcc"
            } break;
         case a_Pat::tag_LOGICALpat: {
            switch (((Pat_LOGICALpat *)p)->_1) {
               case NOTpat: {
#line 450 "printing.pcc"
                 f << "(! " << ((Pat_LOGICALpat *)p)->_2 << ")"; 
#line 450 "printing.pcc"
                  } break;
               case ANDpat: {
#line 451 "printing.pcc"
                 f << '(' << ((Pat_LOGICALpat *)p)->_2 << " && " << ((Pat_LOGICALpat *)p)->_3 << ')'; 
#line 451 "printing.pcc"
                  } break;
               case ORpat: {
#line 452 "printing.pcc"
                 f << '(' << ((Pat_LOGICALpat *)p)->_2 << " || " << ((Pat_LOGICALpat *)p)->_3 << ')'; 
#line 452 "printing.pcc"
                  } break;
               case EQUIVpat: {
#line 454 "printing.pcc"
                 f << '(' << ((Pat_LOGICALpat *)p)->_2 << " equiv: " << ((Pat_LOGICALpat *)p)->_3 << ')'; 
#line 454 "printing.pcc"
                  } break;
               case XORpat: {
#line 455 "printing.pcc"
                 f << '(' << ((Pat_LOGICALpat *)p)->_2 << " xor: " << ((Pat_LOGICALpat *)p)->_3 << ')'; 
#line 455 "printing.pcc"
                  } break;
               default: {
#line 453 "printing.pcc"
                 f << '(' << ((Pat_LOGICALpat *)p)->_2 << " implies: " << ((Pat_LOGICALpat *)p)->_3 << ')'; 
#line 453 "printing.pcc"
                  } break;
            }
            } break;
         case a_Pat::tag_BACKEDGEpat: {
#line 441 "printing.pcc"
           f << '<' << ((Pat_BACKEDGEpat *)p)->_2 << '>'; 
#line 441 "printing.pcc"
            } break;
         case a_Pat::tag_UNIFYpat: {
#line 458 "printing.pcc"
           f << '(' << ((Pat_UNIFYpat *)p)->_1 << " := " << ((Pat_UNIFYpat *)p)->_2 << ")"; 
#line 458 "printing.pcc"
            } break;
         default: {
#line 459 "printing.pcc"
           f << ((Pat_MARKEDpat *)p)->_2; 
#line 459 "printing.pcc"
            } break;
      }
   } else {}
}
#line 487 "printing.pcc"
#line 487 "printing.pcc"

   return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Convert a string into a suitable encoding
//
///////////////////////////////////////////////////////////////////////////////
void encode_string(char * buf, const char * s)
{  while (*s)
   {  unsigned char c = *s++;
      if (c == '"')
      {  *buf++ = 'X'; *buf++ = 'X';
      } else if (isalnum(c) || c == '_')
      {  *buf++ = '_'; *buf++ = c; 
      } else      
      {
         int lo = c % 16, hi = c / 16;
         *buf++ = hi + 'a';
         *buf++ = lo + 'a';
      }
   }
   *buf++ = '\0';  
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print the mangled name of list constructors.
//
///////////////////////////////////////////////////////////////////////////////
#line 518 "printing.pcc"
#line 532 "printing.pcc"
Id mangle (char const * x_1);
Id mangle (char const * x_1)
{
   if ((x_1 == 0)) {
      
#line 518 "printing.pcc"
     return "(null)"; 
#line 518 "printing.pcc"
   } else {
      
      if (_less_string(x_1,"#{}")) {
         if (_less_string(x_1,"#[]")) {
            if (_equal_string(x_1,"#()")) {
#line 523 "printing.pcc"
           return "nil_2_"; 
#line 523 "printing.pcc"
}
            else if (_equal_string(x_1,"#(...)")) {
#line 520 "printing.pcc"
           return "list_2_"; 
#line 520 "printing.pcc"
}
            else if (_equal_string(x_1,"#[...]")) {
#line 519 "printing.pcc"
           return "list_1_"; 
#line 519 "printing.pcc"
}
            else {
            if ((x_1[0] == '\"')) {
               
#line 529 "printing.pcc"
              char buf[256]; encode_string(buf,x_1); 
               return Quark(buf); 
#line 530 "printing.pcc"
            } else {
               
#line 531 "printing.pcc"
              return x_1; 
#line 531 "printing.pcc"
            }
}
         } else {
            if (_equal_string(x_1,"#[]")) {
#line 522 "printing.pcc"
           return "nil_1_"; 
#line 522 "printing.pcc"
}
            else if (_equal_string(x_1,"#{...}")) {
#line 521 "printing.pcc"
           return "list_3_"; 
#line 521 "printing.pcc"
}
            else {
            if ((x_1[0] == '\"')) {
               
#line 529 "printing.pcc"
              char buf[256]; encode_string(buf,x_1); 
               return Quark(buf); 
#line 530 "printing.pcc"
            } else {
               
#line 531 "printing.pcc"
              return x_1; 
#line 531 "printing.pcc"
            }
}
         }
      } else {
         if (_equal_string(x_1,"#{}")) {
#line 524 "printing.pcc"
        return "nil_3_"; 
#line 524 "printing.pcc"
}
         else if (_equal_string(x_1,"(|...|)")) {
#line 526 "printing.pcc"
        return "vector_2_"; 
#line 526 "printing.pcc"
}
         else if (_equal_string(x_1,"[|...|]")) {
#line 525 "printing.pcc"
        return "vector_1_"; 
#line 525 "printing.pcc"
}
         else if (_equal_string(x_1,"{|...|}")) {
#line 527 "printing.pcc"
        return "vector_3_"; 
#line 527 "printing.pcc"
}
         else {
         if ((x_1[0] == '\"')) {
            
#line 529 "printing.pcc"
           char buf[256]; encode_string(buf,x_1); 
            return Quark(buf); 
#line 530 "printing.pcc"
         } else {
            
#line 531 "printing.pcc"
           return x_1; 
#line 531 "printing.pcc"
         }
}
      }
   }
}
#line 532 "printing.pcc"
#line 532 "printing.pcc"


///////////////////////////////////////////////////////////////////////////////
//
//  Method to print the name of a constructor
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& print_cons (std::ostream& f, Cons cons)
{  
#line 540 "printing.pcc"
#line 548 "printing.pcc"
{
   if (cons) {
      if (cons->alg_ty) {
         switch (cons->alg_ty->tag__) {
            case a_Ty::tag_TYCONty: {
               if (cons->ty) {
                  if (boxed(((Ty_TYCONty *)cons->alg_ty)->_1)) {
                     switch (((Ty_TYCONty *)cons->alg_ty)->_1->tag__) {
                        case a_TyCon::tag_DATATYPEtycon: {
                           L6:; 
#line 543 "printing.pcc"
                         if (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)cons->alg_ty)->_1)->opt & OPTsubclassless)
                           f << "a_" << ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)cons->alg_ty)->_1)->id;
                           else
                           f << ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)cons->alg_ty)->_1)->id << "_" << mangle(cons->name);
                           
#line 547 "printing.pcc"
                           } break;
                        default: {
                           L7:; 
#line 548 "printing.pcc"
                         bug("print_cons()"); 
#line 548 "printing.pcc"
                           } break;
                     }
                  } else { goto L7; }
               } else {
                  L8:; 
#line 541 "printing.pcc"
                f << mangle(cons->name); 
#line 541 "printing.pcc"
               }
               } break;
            default: {
               L9:; 
               if (cons->ty) { goto L7; } else { goto L8; }
               } break;
         }
      } else { goto L9; }
   } else { goto L7; }
}
#line 549 "printing.pcc"
#line 549 "printing.pcc"
 
   return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print an expression list
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& f, Exps es)
{  for (Exps l = es; l; l = l->_2) {
      f << l->_1; if (l->_2) f << ',';
   }
   return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print an expression.
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& f, Exp e)
{  
#line 571 "printing.pcc"
#line 725 "printing.pcc"
{
   if (e) {
      switch (e->tag__) {
         case a_Exp::tag_LITERALexp: {
#line 577 "printing.pcc"
           f << ((Exp_LITERALexp *)e)->LITERALexp; 
#line 577 "printing.pcc"
            } break;
         case a_Exp::tag_IDexp: {
#line 573 "printing.pcc"
           f << ((Exp_IDexp *)e)->IDexp; 
#line 573 "printing.pcc"
            } break;
         case a_Exp::tag_RELexp: {
            if (
#line 574 "printing.pcc"
            same_selectors
#line 574 "printing.pcc"
) {
               
#line 574 "printing.pcc"
              f << "_0"; 
#line 574 "printing.pcc"
            } else {
               
#line 575 "printing.pcc"
              f << '_' << ((Exp_RELexp *)e)->RELexp; 
#line 575 "printing.pcc"
            }
            } break;
         case a_Exp::tag_DOTexp: {
            if (((Exp_DOTexp *)e)->_1) {
               switch (((Exp_DOTexp *)e)->_1->tag__) {
                  case a_Exp::tag_SELECTORexp: {
                     if (
#line 579 "printing.pcc"
                     pretty_print_exp
#line 579 "printing.pcc"
) {
                        
#line 580 "printing.pcc"
                       f << ((Exp_SELECTORexp *)((Exp_DOTexp *)e)->_1)->_1 << '!' << ((Exp_SELECTORexp *)((Exp_DOTexp *)e)->_1)->_2->name << '.';
                        	int n = atol(((Exp_DOTexp *)e)->_2+1);
                        	if (n > 0) f << n; else f << ((Exp_DOTexp *)e)->_2; 
                              
#line 583 "printing.pcc"
                     } else {
                        
#line 587 "printing.pcc"
                       f << MatchCompiler::make_select(((Exp_SELECTORexp *)((Exp_DOTexp *)e)->_1)->_1,((Exp_SELECTORexp *)((Exp_DOTexp *)e)->_1)->_2,((Exp_SELECTORexp *)((Exp_DOTexp *)e)->_1)->_3,((Exp_DOTexp *)e)->_2); 
#line 587 "printing.pcc"
                     }
                     } break;
                  case a_Exp::tag_DEREFexp: {
#line 589 "printing.pcc"
                    f << ((Exp_DEREFexp *)((Exp_DOTexp *)e)->_1)->DEREFexp << "->" << ((Exp_DOTexp *)e)->_2; 
#line 589 "printing.pcc"
                     } break;
                  default: {
                     L10:; 
#line 590 "printing.pcc"
                    f << ((Exp_DOTexp *)e)->_1 << '.' << ((Exp_DOTexp *)e)->_2; 
#line 590 "printing.pcc"
                     } break;
               }
            } else { goto L10; }
            } break;
         case a_Exp::tag_SELECTORexp: {
            if (
#line 584 "printing.pcc"
            pretty_print_exp
#line 584 "printing.pcc"
) {
               
#line 585 "printing.pcc"
              f << ((Exp_SELECTORexp *)e)->_1 << '!' << ((Exp_SELECTORexp *)e)->_2->name; 
#line 585 "printing.pcc"
            } else {
               
#line 588 "printing.pcc"
              f << MatchCompiler::make_select(((Exp_SELECTORexp *)e)->_1,((Exp_SELECTORexp *)e)->_2,((Exp_SELECTORexp *)e)->_3); 
#line 588 "printing.pcc"
            }
            } break;
         case a_Exp::tag_DEREFexp: {
#line 591 "printing.pcc"
           f << "(*" << ((Exp_DEREFexp *)e)->DEREFexp << ')'; 
#line 591 "printing.pcc"
            } break;
         case a_Exp::tag_ARROWexp: {
#line 592 "printing.pcc"
           f << ((Exp_ARROWexp *)e)->_1 << "->" << ((Exp_ARROWexp *)e)->_2; 
#line 592 "printing.pcc"
            } break;
         case a_Exp::tag_INDEXexp: {
#line 594 "printing.pcc"
           f << ((Exp_INDEXexp *)e)->_1 << '[' << ((Exp_INDEXexp *)e)->_2 << ']'; 
#line 594 "printing.pcc"
            } break;
         case a_Exp::tag_BINOPexp: {
#line 595 "printing.pcc"
           f << '(' << ((Exp_BINOPexp *)e)->_2 << ' ' << ((Exp_BINOPexp *)e)->_1 << ' ' << ((Exp_BINOPexp *)e)->_3 << ')'; 
#line 595 "printing.pcc"
            } break;
         case a_Exp::tag_PREFIXexp: {
#line 596 "printing.pcc"
           f << '(' << ((Exp_PREFIXexp *)e)->_1 << ' ' << ((Exp_PREFIXexp *)e)->_2 << ')'; 
#line 596 "printing.pcc"
            } break;
         case a_Exp::tag_POSTFIXexp: {
#line 597 "printing.pcc"
           f << '(' << ((Exp_POSTFIXexp *)e)->_2 << ' ' << ((Exp_POSTFIXexp *)e)->_1 << ')'; 
#line 597 "printing.pcc"
            } break;
         case a_Exp::tag_APPexp: {
#line 593 "printing.pcc"
           f << ((Exp_APPexp *)e)->_1 << '(' << ((Exp_APPexp *)e)->_2 << ')'; 
#line 593 "printing.pcc"
            } break;
         case a_Exp::tag_ASSIGNexp: {
#line 578 "printing.pcc"
           f << '(' << ((Exp_ASSIGNexp *)e)->_1 << " = " << ((Exp_ASSIGNexp *)e)->_2 << ')'; 
#line 578 "printing.pcc"
            } break;
         case a_Exp::tag_IFexp: {
#line 610 "printing.pcc"
           f << '(' << ((Exp_IFexp *)e)->_1 << " ? " << ((Exp_IFexp *)e)->_2 << " : " << ((Exp_IFexp *)e)->_3 <<')';
#line 610 "printing.pcc"
            } break;
         case a_Exp::tag_TUPLEexp: {
#line 608 "printing.pcc"
           f << ((Exp_TUPLEexp *)e)->TUPLEexp; 
#line 608 "printing.pcc"
            } break;
         case a_Exp::tag_EXTUPLEexp: {
#line 609 "printing.pcc"
           f << "mkTuple" << length(((Exp_EXTUPLEexp *)e)->EXTUPLEexp) << '(' << ((Exp_EXTUPLEexp *)e)->EXTUPLEexp << ')'; 
#line 609 "printing.pcc"
            } break;
         case a_Exp::tag_RECORDexp: {
#line 685 "printing.pcc"
          f << "{ ";
            for (LabExps l = ((Exp_RECORDexp *)e)->RECORDexp; l; l = l->_2) {
               f << l->_1.label << " = " << l->_1.exp; 
               if (l->_2) f << ", ";
            } 
            f << " }";
            
#line 691 "printing.pcc"
            } break;
         case a_Exp::tag_LISTexp: {
            if (
#line 692 "printing.pcc"
            pretty_print_exp
#line 692 "printing.pcc"
) {
               
#line 693 "printing.pcc"
             f << open_of(((Exp_LISTexp *)e)->_2);
               	 for(Exps exp_list = ((Exp_LISTexp *)e)->_3; exp_list; exp_list = exp_list->_2) 
               	 {  f << exp_list->_1;
               	    if (exp_list->_2) f << ", ";
                        }
               	 if (((Exp_LISTexp *)e)->_4 != NOexp)
               	 {  f << " ... " << ((Exp_LISTexp *)e)->_4; }
                        f << close_of(((Exp_LISTexp *)e)->_2);
                     
#line 701 "printing.pcc"
            } else {
               
               if (((Exp_LISTexp *)e)->_1) {
                  if (((Exp_LISTexp *)e)->_2) {
#line 703 "printing.pcc"
                   int i = 0;
                     for(Exps exp_list = ((Exp_LISTexp *)e)->_3; exp_list; exp_list = exp_list->_2) 
                     	 {  Exp exp = exp_list->_1;
                        f << mangle(((Exp_LISTexp *)e)->_1->name) << '(' << exp;
                     	    if (exp_list->_2) f << ','; 
                     	    i++;
                     }
                     if (((Exp_LISTexp *)e)->_4 != NOexp) f << ',' << ((Exp_LISTexp *)e)->_4; 
                     	 else if (((Exp_LISTexp *)e)->_3 == 
#line 711 "printing.pcc"
#line 711 "printing.pcc"
                     nil_1_
#line 711 "printing.pcc"
#line 711 "printing.pcc"
                     ) f << mangle(((Exp_LISTexp *)e)->_2->name);
                     while (i-- > 0) f << ')';
                     
#line 713 "printing.pcc"
                  } else {
                     L11:; }
               } else { goto L11; }
            }
            } break;
         case a_Exp::tag_VECTORexp: {
            if (((Exp_VECTORexp *)e)->_1) {
#line 716 "printing.pcc"
             f << mangle(((Exp_VECTORexp *)e)->_1->name) << '(';
               {  for(Exps exps = ((Exp_VECTORexp *)e)->_2; exps; exps = exps->_2) 
                  {  f << exps->_1;
                     if (exps->_2 != 
#line 719 "printing.pcc"
#line 719 "printing.pcc"
               nil_1_
#line 719 "printing.pcc"
#line 719 "printing.pcc"
               ) f << ',';
               }
               }
               f << ')';
               
#line 723 "printing.pcc"
            } else {}
            } break;
         case a_Exp::tag_CONSexp: {
            if (((Exp_CONSexp *)e)->_1) {
               if (((Exp_CONSexp *)e)->_3) {
                  switch (((Exp_CONSexp *)e)->_3->tag__) {
                     case a_Exp::tag_RECORDexp: {
                        if (((Exp_CONSexp *)e)->_1->ty) {
                           switch (((Exp_CONSexp *)e)->_1->ty->tag__) {
                              case a_Ty::tag_TYCONty: {
                                 if (boxed(((Ty_TYCONty *)((Exp_CONSexp *)e)->_1->ty)->_1)) {
                                    switch (((Ty_TYCONty *)((Exp_CONSexp *)e)->_1->ty)->_1->tag__) {
                                       case a_TyCon::tag_RECORDtycon: {
                                          if (((Exp_CONSexp *)e)->_3) {
                                             switch (((Exp_CONSexp *)e)->_3->tag__) {
                                                case a_Exp::tag_RECORDexp: {
                                                   L12:; 
#line 632 "printing.pcc"
                                                 // rearrange arguments to 
                                                   if (((Exp_CONSexp *)e)->_2)
                                                   {  f << "new (" << ((Exp_CONSexp *)e)->_2 << ") "; print_cons(f,((Exp_CONSexp *)e)->_1); }
                                                   else
                                                   {  f << mangle(((Exp_CONSexp *)e)->_1->name); }
                                                   
                                                   f << '(';
                                                   {  for_each (LabExp, i, ((Exp_RECORDexp *)((Exp_CONSexp *)e)->_3)->RECORDexp) {
                                                         for_each (Id, j, ((TyCon_RECORDtycon *)((Ty_TYCONty *)((Exp_CONSexp *)e)->_1->ty)->_1)->_1) if (i.label == j) goto next;
                                                         error ("%Lillegal record label '%s' in expression: %s%e\n", 
                                                                i.label,((Exp_CONSexp *)e)->_1->name,((Exp_CONSexp *)e)->_3);
                                                         next: ;
                                                      }
                                                   }
                                                   {  Bool comma = false;
                                                      Ids is; Tys ts;
                                                      for(is = ((TyCon_RECORDtycon *)((Ty_TYCONty *)((Exp_CONSexp *)e)->_1->ty)->_1)->_1, ts = ((Ty_TYCONty *)((Exp_CONSexp *)e)->_1->ty)->_2; is; is = is->_2, ts = ts->_2) {
                                                         Id i = is->_1;
                                                         Bool found = false;
                                                         for_each (LabExp, j, ((Exp_RECORDexp *)((Exp_CONSexp *)e)->_3)->RECORDexp) {
                                                            if (i == j.label) {
                                                               if (found)
                                                                  error ("%Lduplicated label '%s' in expression: %s%e\n", 
                                                                         j.label,((Exp_CONSexp *)e)->_1->name,((Exp_CONSexp *)e)->_3);
                                                               found = true;
                                                               if (comma) f << ", "; comma = true;
                                                               f << j.exp;
                                                            } 
                                                         }
                                                         if (! found) {
                                                            
#line 662 "printing.pcc"
#line 665 "printing.pcc"
                                                   {
                                                      Exp _V4 = default_val(ts->_1);
                                                      if (_V4) {
#line 665 "printing.pcc"
                                                        if (comma) f << ", "; comma = true; f << _V4; 
#line 665 "printing.pcc"
                                                      } else {
#line 663 "printing.pcc"
                                                        error ("%Lmissing label '%s' in expression: %s%e\n",
                                                         i, ((Exp_CONSexp *)e)->_1->name, ((Exp_CONSexp *)e)->_3); 
#line 664 "printing.pcc"
                                                      }
                                                   }
#line 666 "printing.pcc"
#line 666 "printing.pcc"
                                                 
                                                   }
                                                   } 
                                                   }
                                                   f << ')';
                                                   
#line 671 "printing.pcc"
                                                   } break;
                                                default: {
                                                   L13:; 
#line 673 "printing.pcc"
                                                 error("%Lconstructor '%s' doesn't take labeled arguments\n", ((Exp_CONSexp *)e)->_1->name);
                                                   
#line 674 "printing.pcc"
                                                   } break;
                                             }
                                          } else { goto L13; }
                                          } break;
                                       default: { goto L13; } break;
                                    }
                                 } else { goto L13; }
                                 } break;
                              default: { goto L13; } break;
                           }
                        } else { goto L13; }
                        } break;
                     default: {
                        L14:; 
                        if (((Exp_CONSexp *)e)->_1->ty) {
                           switch (((Exp_CONSexp *)e)->_1->ty->tag__) {
                              case a_Ty::tag_TYCONty: {
                                 L15:; 
                                 if (boxed(((Ty_TYCONty *)((Exp_CONSexp *)e)->_1->ty)->_1)) {
                                    switch (((Ty_TYCONty *)((Exp_CONSexp *)e)->_1->ty)->_1->tag__) {
                                       case a_TyCon::tag_RECORDtycon: {
                                          L16:; 
                                          if (((Exp_CONSexp *)e)->_3) {
                                             switch (((Exp_CONSexp *)e)->_3->tag__) {
                                                case a_Exp::tag_RECORDexp: { goto L12; } break;
                                                default: {
                                                   L17:; 
#line 678 "printing.pcc"
                                                 if (((Exp_CONSexp *)e)->_2)
                                                   {  f << "new (" << ((Exp_CONSexp *)e)->_2 << ") "; print_cons(f,((Exp_CONSexp *)e)->_1); }
                                                   else
                                                   {  f << mangle(((Exp_CONSexp *)e)->_1->name); }
                                                   f << '(' << ((Exp_CONSexp *)e)->_3 << ')';
                                                   
#line 683 "printing.pcc"
                                                   } break;
                                             }
                                          } else { goto L17; }
                                          } break;
                                       default: { goto L17; } break;
                                    }
                                 } else { goto L17; }
                                 } break;
                              default: { goto L17; } break;
                           }
                        } else {
                           L18:; 
                           if (((Exp_CONSexp *)e)->_3) { goto L17; } else {
                              L19:; 
                              if (((Exp_CONSexp *)e)->_2) { goto L17; } else {
                                 L20:; 
#line 676 "printing.pcc"
                               f << mangle(((Exp_CONSexp *)e)->_1->name); 
#line 676 "printing.pcc"
                              }
                           }
                        }
                        } break;
                  }
               } else { goto L14; }
            } else {
               L21:; 
#line 725 "printing.pcc"
              bug("operator << (std::ostream&, Exp);");
#line 725 "printing.pcc"
            }
            } break;
         case a_Exp::tag_CASTexp: {
#line 598 "printing.pcc"
           Bool save = pretty_print_ty;
            			      pretty_print_ty = false;
            			      f << "((" << ((Exp_CASTexp *)e)->_1 << ')' << ((Exp_CASTexp *)e)->_2 << ')'; 
            			      pretty_print_ty = save;
            			    
#line 602 "printing.pcc"
            } break;
         case a_Exp::tag_QUALexp: {
#line 603 "printing.pcc"
           f << ((Exp_QUALexp *)e)->_1 << "::" << ((Exp_QUALexp *)e)->_2; 
#line 603 "printing.pcc"
            } break;
         case a_Exp::tag_EQexp: {
#line 604 "printing.pcc"
           f << "equality_of(" << ((Exp_EQexp *)e)->_2 << ',' << ((Exp_EQexp *)e)->_3 << ')'; 
#line 604 "printing.pcc"
            } break;
         case a_Exp::tag_UNIFYexp: {
#line 605 "printing.pcc"
           f << "unify(" << ((Exp_UNIFYexp *)e)->_2 << ',' << ((Exp_UNIFYexp *)e)->_3 << ')'; 
#line 605 "printing.pcc"
            } break;
         case a_Exp::tag_LTexp: {
#line 606 "printing.pcc"
           f << '(' << ((Exp_LTexp *)e)->_2 << " < " << ((Exp_LTexp *)e)->_3 << ')'; 
#line 606 "printing.pcc"
            } break;
         case a_Exp::tag_HASHexp: {
#line 607 "printing.pcc"
           f << "hash(" << ((Exp_HASHexp *)e)->_2 << ')'; 
#line 607 "printing.pcc"
            } break;
         case a_Exp::tag_THISCOSTexp: {
#line 628 "printing.pcc"
           f << "t__->cost"; 
#line 628 "printing.pcc"
            } break;
         case a_Exp::tag_COSTexp: {
#line 627 "printing.pcc"
           f << "t__->kids[" << ((Exp_COSTexp *)e)->COSTexp << "]->cost"; 
#line 627 "printing.pcc"
            } break;
         case a_Exp::tag_THISSYNexp: {
#line 622 "printing.pcc"
           if (((Exp_THISSYNexp *)e)->_3)
            f << "__";
            else // in parser
            f << "t__->u._" << ((Exp_THISSYNexp *)e)->_1; 
            
#line 626 "printing.pcc"
            } break;
         case a_Exp::tag_SYNexp: {
#line 612 "printing.pcc"
           if (((Exp_SYNexp *)e)->_4)
            f << '_' << ((Exp_SYNexp *)e)->_1 << "__";
            else if (((Exp_SYNexp *)e)->_2 < 0) // parser semantic action
            {  if (((Exp_SYNexp *)e)->_1 == 0) f << "syn_" << "._" << -((Exp_SYNexp *)e)->_2;
            else f << "t__[" << ((Exp_SYNexp *)e)->_1 << "+to__]._" << -((Exp_SYNexp *)e)->_2; 
            }
            else
            f << "t__->kids[" << ((Exp_SYNexp *)e)->_1 << "]->u._" << ((Exp_SYNexp *)e)->_2; 
            
#line 620 "printing.pcc"
            } break;
         case a_Exp::tag_MARKEDexp: {
#line 576 "printing.pcc"
           f << ((Exp_MARKEDexp *)e)->_2; 
#line 576 "printing.pcc"
            } break;
         default: { goto L21; } break;
      }
   } else {
#line 572 "printing.pcc"
     
#line 572 "printing.pcc"
   }
}
#line 726 "printing.pcc"
#line 726 "printing.pcc"

   return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print an inheritance type.
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& f, Inherit i)
{  if (i->qualifiers & QUALvirtual) f << "virtual ";
   return f << i->scope << ' ' << i->super_class;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print a class inheritance list.
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& f, Inherits i)
{  for ( ;i; i = i->_2) {
      f << i->_1;
      if (i->_2) f << ", ";
   }
   return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print a cost expression
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& f, Cost c)
{  
#line 759 "printing.pcc"
#line 762 "printing.pcc"
{
   if (c) {
      if (untagp(c)) {
         
#line 762 "printing.pcc"
        f << " \\ " << ((Cost_INTcost *)derefp(c))->INTcost; 
#line 762 "printing.pcc"
      } else {
         
#line 761 "printing.pcc"
        f << " \\ " << ((Cost_EXPcost *)c)->_1; 
#line 761 "printing.pcc"
      }
   } else {}
}
#line 763 "printing.pcc"
#line 763 "printing.pcc"

   return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print a qualified identifier.
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& f, QualId id)
{  
#line 773 "printing.pcc"
#line 776 "printing.pcc"
{
   if (untagp(id)) {
      
      if (
#line 775 "printing.pcc"
      isalpha(((QualId_SIMPLEid *)derefp(id))->SIMPLEid[0])
#line 775 "printing.pcc"
) {
         
#line 775 "printing.pcc"
        f << ((QualId_SIMPLEid *)derefp(id))->SIMPLEid; 
#line 775 "printing.pcc"
      } else {
         
#line 776 "printing.pcc"
        f << "operator " << ((QualId_SIMPLEid *)derefp(id))->SIMPLEid; 
#line 776 "printing.pcc"
      }
   } else {
      
#line 774 "printing.pcc"
     f << ((QualId_NESTEDid *)id)->_1 << "::" << ((QualId_NESTEDid *)id)->_2; 
#line 774 "printing.pcc"
   }
}
#line 777 "printing.pcc"
#line 777 "printing.pcc"

   return f;
}

///////////////////////////////////////////////////////////////////////////////
//  Method to print a pattern match rule.
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& f, MatchRule mr)
{  
#line 785 "printing.pcc"
#line 794 "printing.pcc"
{
#line 787 "printing.pcc"
 Bool save = pretty_print_exp;
   	 pretty_print_exp = true;
   	 if (mr->_1) f << mr->_1 << " -> ";
            f << mr->_2;
            if (mr->_3 != NOexp) f << " | " << mr->_3;
            f << mr->_4 << ": ...";
   	 pretty_print_exp = save;
         
#line 794 "printing.pcc"
}
#line 795 "printing.pcc"
#line 795 "printing.pcc"

   return f;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to pretty print a decision tree.
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& f, Match m)
{  
#line 805 "printing.pcc"
#line 861 "printing.pcc"
{
   if (boxed(m)) {
      switch (m->tag__) {
         case a_Match::tag_SUCCESSmatch: {
#line 809 "printing.pcc"
           f << ((Match_SUCCESSmatch *)m)->_1; 
#line 809 "printing.pcc"
            } break;
         case a_Match::tag_SUCCESSESmatch: {
#line 812 "printing.pcc"
          f << '{';
            Bool comma = false;
            for (int i = 0; i < ((Match_SUCCESSESmatch *)m)->_1; i++)
               if ((*((Match_SUCCESSESmatch *)m)->_2)[i]) {
                  if (comma) f << ", ";
                  f << i;
                  comma = true;
               }
            f << '}';
            
#line 821 "printing.pcc"
            } break;
         case a_Match::tag_COSTmatch: {
#line 823 "printing.pcc"
          f << '{';
            Bool comma = false;
            for (int i = 0; i < ((Match_COSTmatch *)m)->_1; i++)
               if ((*((Match_COSTmatch *)m)->_3)[i]) {
                  if (comma) f << ", ";
                  f << ((Match_COSTmatch *)m)->_2[i] << " = " << i;
                  comma = true;
               }
            f << '}';
            
#line 832 "printing.pcc"
            } break;
         case a_Match::tag_GUARDmatch: {
#line 810 "printing.pcc"
           f << ((Match_GUARDmatch *)m)->_1 << '(' << ((Match_GUARDmatch *)m)->_2 << ',' << ((Match_GUARDmatch *)m)->_3 << ')'; 
#line 810 "printing.pcc"
            } break;
         case a_Match::tag_LITERALmatch: {
            switch (((Match_LITERALmatch *)m)->_3[0]->tag__) {
               case a_Literal::tag_REGEXPlit: {
#line 838 "printing.pcc"
                f << "[\n"; 
                  for (int i = 0; i < ((Match_LITERALmatch *)m)->_4; i++) 
                  {  f << "   {" << i << "}" << ((Match_LITERALmatch *)m)->_3[i] << " => " << ((Match_LITERALmatch *)m)->_5[i] << ",\n"; 
                  }
                  f << ((Match_LITERALmatch *)m)->_6 << ']';
                  
#line 843 "printing.pcc"
                  } break;
               default: {
#line 845 "printing.pcc"
                f << '['; 
                  for (int i = 0; i < ((Match_LITERALmatch *)m)->_4; i++) 
                     {  f << ((Match_LITERALmatch *)m)->_3[i] << ':' << ((Match_LITERALmatch *)m)->_5[i] << ", "; }
                  f << ((Match_LITERALmatch *)m)->_6 << ']';
                  
#line 849 "printing.pcc"
                  } break;
            }
            } break;
         case a_Match::tag_RANGEmatch: {
#line 860 "printing.pcc"
          f << '[' << ((Match_RANGEmatch *)m)->_3 << ".." << ((Match_RANGEmatch *)m)->_4 << ": " << ((Match_RANGEmatch *)m)->_5 << ", " << ((Match_RANGEmatch *)m)->_6 << ']'; 
#line 860 "printing.pcc"
            } break;
         case a_Match::tag_CONSmatch: {
            if (((Match_CONSmatch *)m)->_4) {
               switch (((Match_CONSmatch *)m)->_4->tag__) {
                  case a_Ty::tag_TYCONty: {
                     if (boxed(((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1)) {
                        switch (((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1->tag__) {
                           case a_TyCon::tag_DATATYPEtycon: {
#line 851 "printing.pcc"
                            f << ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1)->id << '['; 
                              for (int i = 0; i < ((Match_CONSmatch *)m)->_5; i++) {
                                 f << ((Match_CONSmatch *)m)->_6[i];
                                 if (i < ((Match_CONSmatch *)m)->_5 - 1) f << ", ";
                              }
                              if (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1)->qualifiers & QUALextensible) f << ", " << ((Match_CONSmatch *)m)->_7;
                              f << ']';
                              
#line 858 "printing.pcc"
                              } break;
                           default: {
                              L22:; 
#line 861 "printing.pcc"
                             bug("operator << (std::ostream&, Match);");
#line 861 "printing.pcc"
                              } break;
                        }
                     } else { goto L22; }
                     } break;
                  default: { goto L22; } break;
               }
            } else { goto L22; }
            } break;
         case a_Match::tag_TREECOSTmatch: {
#line 834 "printing.pcc"
          f << "TREE{" << *((Match_TREECOSTmatch *)m)->_2 << "} => " << ((Match_TREECOSTmatch *)m)->_1; 
#line 834 "printing.pcc"
            } break;
         case a_Match::tag_TREELABELmatch: {
#line 836 "printing.pcc"
          f << "LABEL{" << ((Match_TREELABELmatch *)m)->_2 << "(" << ((Match_TREELABELmatch *)m)->_4 << ")} => " << ((Match_TREELABELmatch *)m)->_1; 
#line 836 "printing.pcc"
            } break;
         default: {
#line 808 "printing.pcc"
           f << '<' << ((Match_BACKEDGEmatch *)m)->_2 << '>'; 
#line 808 "printing.pcc"
            } break;
      }
   } else {
      if (m) {
         
#line 807 "printing.pcc"
        f << '-'; 
#line 807 "printing.pcc"
      } else {
         
#line 806 "printing.pcc"
        f << '_'; 
#line 806 "printing.pcc"
      }
   }
}
#line 862 "printing.pcc"
#line 862 "printing.pcc"

   return f;
}
#line 865 "printing.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 4392
Number of ifs generated      = 77
Number of switches generated = 31
Number of labels             = 22
Number of gotos              = 47
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
