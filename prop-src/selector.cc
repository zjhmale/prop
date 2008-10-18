///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.6),
//  last updated on Nov 2, 1999.
//  The original source file is "selector.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_QUARK_USED
#include <propdefs.h>
///////////////////////////////////////////////////////////////////////////////
//  Quark literals
///////////////////////////////////////////////////////////////////////////////
static const Quark _s_e_l_e_c_t_o_rco_c_c_Q1("deref_");
static const Quark _s_e_l_e_c_t_o_rco_c_c_Q2("derefp");
static const Quark _s_e_l_e_c_t_o_rco_c_c_Q6("tag__");
static const Quark _s_e_l_e_c_t_o_rco_c_c_Q5("untagp");
static const Quark _s_e_l_e_c_t_o_rco_c_c_Q3("_");
static const Quark _s_e_l_e_c_t_o_rco_c_c_Q4("untag");
#line 1 "selector.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements the selection/projection code generation.
//
///////////////////////////////////////////////////////////////////////////////

#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <AD/strings/quark.h>
#include "ir.h"
#include "ast.h"
#include "matchcom.h"
#include "type.h"
#include "options.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Method to compute the proper selector into a component argument 
//  of a constructor
//
///////////////////////////////////////////////////////////////////////////////
Exp select(Exp e, Cons c, Ty t) { return SELECTORexp(e,c,t); }

///////////////////////////////////////////////////////////////////////////////
//
//  Method to compute the proper selector into a component argument 
//  of a constructor
//
///////////////////////////////////////////////////////////////////////////////
Exp MatchCompiler::make_select
    ( Exp  e,             // the expression
      Cons c,             // constructor
      Ty   expected_ty,   // expected type (if applicable)
      Id   component      // component to extract
    )
{  Exp  result         = e;
   Bool use_projection = component != 0;
   
#line 39 "selector.pcc"
#line 110 "selector.pcc"
{
   if (c) {
      if (c->alg_ty) {
         switch (c->alg_ty->tag__) {
            case a_Ty::tag_TYCONty: {
               if (boxed(((Ty_TYCONty *)c->alg_ty)->_1)) {
                  switch (((Ty_TYCONty *)c->alg_ty)->_1->tag__) {
                     case a_TyCon::tag_DATATYPEtycon: {
                        if (
#line 43 "selector.pcc"
                        (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)c->alg_ty)->_1)->qualifiers & QUALview)
#line 43 "selector.pcc"
) {
                           
#line 44 "selector.pcc"
                         Ty comp_ty = c->ty;
                           if (component) 
                           	 {  
#line 46 "selector.pcc"
#line 52 "selector.pcc"
                           {
                              Ty _V1 = c->ty;
                              if (_V1) {
                                 switch (_V1->tag__) {
                                    case a_Ty::tag_TYCONty: {
                                       if (boxed(((Ty_TYCONty *)_V1)->_1)) {
                                          switch (((Ty_TYCONty *)_V1)->_1->tag__) {
                                             case a_TyCon::tag_RECORDtycon: {
#line 50 "selector.pcc"
                                               use_projection = false;
                                                			     comp_ty = component_ty(c->ty,component); 
#line 51 "selector.pcc"
                                                } break;
                                             default: {
                                                L1:; 
#line 52 "selector.pcc"
                                               comp_ty = _V1; 
#line 52 "selector.pcc"
                                                } break;
                                          }
                                       } else {
                                          switch ((int)((Ty_TYCONty *)_V1)->_1) {
                                             case ((int)TUPLEtycon): {
#line 47 "selector.pcc"
                                               use_projection = false;
                                                			     comp_ty = component_ty(c->ty,atol(component+1)); 
#line 48 "selector.pcc"
                                                } break;
                                             default: { goto L1; } break;
                                          }
                                       }
                                       } break;
                                    default: { goto L1; } break;
                                 }
                              } else { goto L1; }
                           }
#line 53 "selector.pcc"
#line 53 "selector.pcc"
                           
                           }
                           Exp selector_exp = default_val(comp_ty);
                           if (selector_exp == NOexp)
                           {  error ("%Lview accessor is undefined for constructor %s\n", c->name); 
                              return NOexp; 
                           }
                           result = subst(selector_exp,&e);
                           
#line 61 "selector.pcc"
                        } else {
                           
#line 68 "selector.pcc"
                         Bool simple;
                           
                                    
#line 70 "selector.pcc"
#line 72 "selector.pcc"
                           {
                              Ty _V2 = c->ty;
                              if (_V2) {
                                 switch (_V2->tag__) {
                                    case a_Ty::tag_TYCONty: {
                                       if (boxed(((Ty_TYCONty *)_V2)->_1)) {
                                          switch (((Ty_TYCONty *)_V2)->_1->tag__) {
                                             case a_TyCon::tag_RECORDtycon: {
                                                L2:; 
#line 71 "selector.pcc"
                                               simple = false; 
#line 71 "selector.pcc"
                                                } break;
                                             default: {
                                                L3:; 
#line 72 "selector.pcc"
                                               simple = true; 
#line 72 "selector.pcc"
                                                } break;
                                          }
                                       } else {
                                          switch ((int)((Ty_TYCONty *)_V2)->_1) {
                                             case ((int)TUPLEtycon): { goto L2; } break;
                                             default: { goto L3; } break;
                                          }
                                       }
                                       } break;
                                    default: { goto L3; } break;
                                 }
                              } else { goto L3; }
                           }
#line 73 "selector.pcc"
#line 73 "selector.pcc"
                           
                           if (is_array_constructor(c->name)) simple = false;
                           
                           Id nm = mangle(c->name);
                           
                           if (c->opt & OPTunboxed) {
                              result = APPexp(IDexp(
#line 79 "selector.pcc"
#line 79 "selector.pcc"
                           _s_e_l_e_c_t_o_rco_c_c_Q1
#line 79 "selector.pcc"
#line 79 "selector.pcc"
                          + c->name), e); 
                           } else {
                              if ((((TyCon_DATATYPEtycon *)((Ty_TYCONty *)c->alg_ty)->_1)->opt & OPTtaggedpointer) && c->tag != 0)
                                 e = APPexp(IDexp(
#line 82 "selector.pcc"
#line 82 "selector.pcc"
                           _s_e_l_e_c_t_o_rco_c_c_Q2
#line 82 "selector.pcc"
#line 82 "selector.pcc"
                           ), e); 
                           if (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)c->alg_ty)->_1)->opt & OPTsubclassless) { // No subclass hierarchy
                              if (simple) result = ARROWexp(e,nm);
                              else        result = DEREFexp(e);
                           } else {                          // with subclass hierachy
                              // Dereference the pointer if the pointer needs to be stripped
                              // of the tag.
                              Exp downcast_exp = NOexp;
                              if (options.inline_casts && ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)c->alg_ty)->_1)->tyvars == 
#line 90 "selector.pcc"
#line 90 "selector.pcc"
                           nil_1_
#line 90 "selector.pcc"
#line 90 "selector.pcc"
                           ) {
                           downcast_exp = 
                              CASTexp(mkptrty(mkidty(((TyCon_DATATYPEtycon *)((Ty_TYCONty *)c->alg_ty)->_1)->id + 
#line 92 "selector.pcc"
#line 92 "selector.pcc"
                           _s_e_l_e_c_t_o_rco_c_c_Q3
#line 92 "selector.pcc"
#line 92 "selector.pcc"
                          + nm,
#line 92 "selector.pcc"
#line 92 "selector.pcc"
                           nil_1_
#line 92 "selector.pcc"
#line 92 "selector.pcc"
                           )),e);
                           } else if (options.inline_casts && expected_ty != NOty) {
                           		   
#line 94 "selector.pcc"
#line 99 "selector.pcc"
                           {
                              Ty _V3 = deref_all(expected_ty);
                              if (_V3) {
                                 switch (_V3->tag__) {
                                    case a_Ty::tag_TYCONty: {
#line 96 "selector.pcc"
                                     downcast_exp = 
                                       CASTexp(mkptrty(mkidty(((TyCon_DATATYPEtycon *)((Ty_TYCONty *)c->alg_ty)->_1)->id + 
#line 97 "selector.pcc"
#line 97 "selector.pcc"
                                       _s_e_l_e_c_t_o_rco_c_c_Q3
#line 97 "selector.pcc"
#line 97 "selector.pcc"
                                      + nm,((Ty_TYCONty *)_V3)->_2)),e);
                                       
#line 98 "selector.pcc"
                                       } break;
                                    default: {
                                       L4:; 
#line 99 "selector.pcc"
                                      bug("%Lmake_select"); 
#line 99 "selector.pcc"
                                       } break;
                                 }
                              } else { goto L4; }
                           }
#line 100 "selector.pcc"
#line 100 "selector.pcc"
                           
                           } else {
                              downcast_exp = APPexp(IDexp(
#line 102 "selector.pcc"
#line 102 "selector.pcc"
                           _s_e_l_e_c_t_o_rco_c_c_Q3
#line 102 "selector.pcc"
#line 102 "selector.pcc"
                          + nm),e);
                           }
                           if (simple) result = ARROWexp(downcast_exp,nm);
                           else        result = DEREFexp(downcast_exp);
                           }
                           }
                           
#line 108 "selector.pcc"
                        }
                        } break;
                     default: {
                        L5:; } break;
                  }
               } else { goto L5; }
               } break;
            default: { goto L5; } break;
         }
      } else { goto L5; }
   } else { goto L5; }
}
#line 110 "selector.pcc"
#line 110 "selector.pcc"
 
   return use_projection ? DOTexp(result,component) : result; 
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to compute the tag name of a constructor
//
///////////////////////////////////////////////////////////////////////////////
Exp MatchCompiler::tag_name_of(Cons cons, Bool normalized)
{
   
#line 121 "selector.pcc"
#line 145 "selector.pcc"
{
   if (cons) {
      if (cons->alg_ty) {
         switch (cons->alg_ty->tag__) {
            case a_Ty::tag_TYCONty: {
               if (cons->ty) {
                  L6:; 
                  if (boxed(((Ty_TYCONty *)cons->alg_ty)->_1)) {
                     switch (((Ty_TYCONty *)cons->alg_ty)->_1->tag__) {
                        case a_TyCon::tag_DATATYPEtycon: {
                           L7:; 
                           if (
#line 125 "selector.pcc"
                           (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)cons->alg_ty)->_1)->qualifiers & QUALview)
#line 125 "selector.pcc"
) {
                              
                              L8:; 
#line 126 "selector.pcc"
                            if (cons->view_predicate == NOexp)
                              {  error("%Lview case for constructor %s is undefined\n",cons->name);
                                 return NOexp;
                              	 }
                              	 return cons->view_predicate;
                              
#line 131 "selector.pcc"
                           } else {
                              
                              L9:; 
                              if (
#line 139 "selector.pcc"
                              (((! normalized) && (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)cons->alg_ty)->_1)->tyvars == nil_1_)) && (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)cons->alg_ty)->_1)->arg > 1))
#line 139 "selector.pcc"
) {
                                 
                                 L10:; 
#line 140 "selector.pcc"
                               return IDexp(Quark("a_",((TyCon_DATATYPEtycon *)((Ty_TYCONty *)cons->alg_ty)->_1)->id,"::tag_",mangle(cons->name))); 
                                 
#line 141 "selector.pcc"
                              } else {
                                 
                                 L11:; 
#line 143 "selector.pcc"
                               int this_tag = tag_of(cons) + (normalized ? ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)cons->alg_ty)->_1)->unit : 0); 
                                 return LITERALexp(INTlit(this_tag)); 
#line 144 "selector.pcc"
                              }
                           }
                           } break;
                        default: {
                           L12:; 
#line 145 "selector.pcc"
                          return NOexp; 
#line 145 "selector.pcc"
                           } break;
                     }
                  } else { goto L12; }
               } else {
                  if (cons->alg_ty) {
                     switch (cons->alg_ty->tag__) {
                        case a_Ty::tag_TYCONty: {
                           if (boxed(((Ty_TYCONty *)cons->alg_ty)->_1)) {
                              switch (((Ty_TYCONty *)cons->alg_ty)->_1->tag__) {
                                 case a_TyCon::tag_DATATYPEtycon: {
                                    if (
#line 125 "selector.pcc"
                                    (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)cons->alg_ty)->_1)->qualifiers & QUALview)
#line 125 "selector.pcc"
) {
                                        goto L8; } else {
                                       
                                       L13:; 
                                       if (
#line 133 "selector.pcc"
                                       (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)cons->alg_ty)->_1)->arg == 0)
#line 133 "selector.pcc"
) {
                                          
                                          L14:; 
#line 134 "selector.pcc"
                                        return IDexp(mangle(cons->name)); 
#line 134 "selector.pcc"
                                       } else {
                                          
                                          L15:; 
#line 136 "selector.pcc"
                                        return CASTexp(integer_ty,IDexp(mangle(cons->name))); 
#line 136 "selector.pcc"
                                       }
                                    }
                                    } break;
                                 default: { goto L12; } break;
                              }
                           } else { goto L12; }
                           } break;
                        default: { goto L6; } break;
                     }
                  } else { goto L6; }
               }
               } break;
            default: {
               L16:; 
               if (cons->ty) { goto L12; } else {
                  L17:; 
                  if (cons->alg_ty) {
                     switch (cons->alg_ty->tag__) {
                        case a_Ty::tag_TYCONty: {
                           L18:; 
                           if (boxed(((Ty_TYCONty *)cons->alg_ty)->_1)) {
                              switch (((Ty_TYCONty *)cons->alg_ty)->_1->tag__) {
                                 case a_TyCon::tag_DATATYPEtycon: { goto L13; } break;
                                 default: { goto L12; } break;
                              }
                           } else { goto L12; }
                           } break;
                        default: { goto L12; } break;
                     }
                  } else { goto L12; }
               }
               } break;
         }
      } else { goto L16; }
   } else { goto L12; }
}
#line 146 "selector.pcc"
#line 146 "selector.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to extract the tag from a term 
//
///////////////////////////////////////////////////////////////////////////////
Exp MatchCompiler::untag(Exp e, Ty ty)
{  
#line 155 "selector.pcc"
#line 166 "selector.pcc"
{
   Ty _V4 = deref(ty);
   if (_V4) {
      switch (_V4->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V4)->_1)) {
               switch (((Ty_TYCONty *)_V4)->_1->tag__) {
                  case a_TyCon::tag_DATATYPEtycon: {
                     if (
#line 157 "selector.pcc"
                     (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V4)->_1)->qualifiers & QUALview)
#line 157 "selector.pcc"
) {
                        
#line 158 "selector.pcc"
                      if (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V4)->_1)->view_match == NOexp)
                        {  error("%Lview test for datatype %T is undefined\n", ty);
                           return NOexp;
                        }
                        return subst(((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V4)->_1)->view_match,&e);
                        
#line 163 "selector.pcc"
                     } else {
                        
                        if (
#line 164 "selector.pcc"
                        (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V4)->_1)->arg > 0)
#line 164 "selector.pcc"
) {
                           
#line 165 "selector.pcc"
                          return APPexp(IDexp(
#line 165 "selector.pcc"
#line 165 "selector.pcc"
                           _s_e_l_e_c_t_o_rco_c_c_Q4
#line 165 "selector.pcc"
#line 165 "selector.pcc"
                           ),e); 
#line 165 "selector.pcc"
                        } else {
                           
                           L19:; 
#line 166 "selector.pcc"
                          return e; 
#line 166 "selector.pcc"
                        }
                     }
                     } break;
                  default: { goto L19; } break;
               }
            } else { goto L19; }
            } break;
         default: { goto L19; } break;
      }
   } else { goto L19; }
}
#line 167 "selector.pcc"
#line 167 "selector.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to extract the tag from a term (optimized for arg/unit constructors)
//
///////////////////////////////////////////////////////////////////////////////
Exp MatchCompiler::untag_one (Exp e, Cons c)
{  
#line 176 "selector.pcc"
#line 197 "selector.pcc"
{
   if (c) {
      if (c->alg_ty) {
         switch (c->alg_ty->tag__) {
            case a_Ty::tag_TYCONty: {
               if (c->ty) {
                  if (boxed(((Ty_TYCONty *)c->alg_ty)->_1)) {
                     switch (((Ty_TYCONty *)c->alg_ty)->_1->tag__) {
                        case a_TyCon::tag_DATATYPEtycon: {
                           L20:; 
                           if (
#line 179 "selector.pcc"
                           (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)c->alg_ty)->_1)->qualifiers & QUALview)
#line 179 "selector.pcc"
) {
                              
                              L21:; 
#line 180 "selector.pcc"
                            if (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)c->alg_ty)->_1)->view_match == NOexp)
                              {  error("%Lview test for constructor %s is undefined\n",c->name);
                                 return NOexp;
                              }
                              return subst(((TyCon_DATATYPEtycon *)((Ty_TYCONty *)c->alg_ty)->_1)->view_match,&e);
                              
#line 185 "selector.pcc"
                           } else {
                              
                              L22:; 
#line 192 "selector.pcc"
                            if (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)c->alg_ty)->_1)->opt & OPTtaggedpointer) e = APPexp(IDexp(
#line 192 "selector.pcc"
#line 192 "selector.pcc"
                              _s_e_l_e_c_t_o_rco_c_c_Q5
#line 192 "selector.pcc"
#line 192 "selector.pcc"
                              ),e); 
                              else if (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)c->alg_ty)->_1)->opt & OPTtagless) e = LITERALexp(INTlit(0));
                              else e = ARROWexp(e,
#line 194 "selector.pcc"
#line 194 "selector.pcc"
                              _s_e_l_e_c_t_o_rco_c_c_Q6
#line 194 "selector.pcc"
#line 194 "selector.pcc"
                              );
                              return e;
                              
#line 196 "selector.pcc"
                           }
                           } break;
                        default: {
                           L23:; 
#line 197 "selector.pcc"
                          return NOexp; 
#line 197 "selector.pcc"
                           } break;
                     }
                  } else { goto L23; }
               } else {
                  if (c->alg_ty) {
                     switch (c->alg_ty->tag__) {
                        case a_Ty::tag_TYCONty: {
                           if (boxed(((Ty_TYCONty *)c->alg_ty)->_1)) {
                              switch (((Ty_TYCONty *)c->alg_ty)->_1->tag__) {
                                 case a_TyCon::tag_DATATYPEtycon: {
                                    if (
#line 179 "selector.pcc"
                                    (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)c->alg_ty)->_1)->qualifiers & QUALview)
#line 179 "selector.pcc"
) {
                                        goto L21; } else {
                                       
                                       L24:; 
                                       if (
#line 187 "selector.pcc"
                                       (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)c->alg_ty)->_1)->arg == 0)
#line 187 "selector.pcc"
) {
                                          
                                          L25:; 
#line 188 "selector.pcc"
                                         return e; 
#line 188 "selector.pcc"
                                       } else {
                                          
                                          L26:; 
#line 190 "selector.pcc"
                                         return CASTexp(integer_ty,e); 
#line 190 "selector.pcc"
                                       }
                                    }
                                    } break;
                                 default: { goto L26; } break;
                              }
                           } else { goto L26; }
                           } break;
                        default: {
                           L27:; 
                           if (boxed(((Ty_TYCONty *)c->alg_ty)->_1)) {
                              switch (((Ty_TYCONty *)c->alg_ty)->_1->tag__) {
                                 case a_TyCon::tag_DATATYPEtycon: {
                                    L28:; 
                                    if (
#line 179 "selector.pcc"
                                    (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)c->alg_ty)->_1)->qualifiers & QUALview)
#line 179 "selector.pcc"
) {
                                        goto L21; } else {
                                        goto L26; }
                                    } break;
                                 default: { goto L26; } break;
                              }
                           } else { goto L26; }
                           } break;
                     }
                  } else { goto L27; }
               }
               } break;
            default: {
               L29:; 
               if (c->ty) { goto L23; } else {
                  L30:; 
                  if (c->alg_ty) {
                     switch (c->alg_ty->tag__) {
                        case a_Ty::tag_TYCONty: {
                           L31:; 
                           if (boxed(((Ty_TYCONty *)c->alg_ty)->_1)) {
                              switch (((Ty_TYCONty *)c->alg_ty)->_1->tag__) {
                                 case a_TyCon::tag_DATATYPEtycon: { goto L24; } break;
                                 default: { goto L26; } break;
                              }
                           } else { goto L26; }
                           } break;
                        default: { goto L26; } break;
                     }
                  } else { goto L26; }
               }
               } break;
         }
      } else { goto L29; }
   } else { goto L23; }
}
#line 198 "selector.pcc"
#line 198 "selector.pcc"

}
#line 200 "selector.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 1358
Number of ifs generated      = 40
Number of switches generated = 24
Number of labels             = 31
Number of gotos              = 47
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
