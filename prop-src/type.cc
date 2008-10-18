///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.6),
//  last updated on Nov 2, 1999.
//  The original source file is "type.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_QUARK_USED
#include <propdefs.h>
///////////////////////////////////////////////////////////////////////////////
//  Quark literals
///////////////////////////////////////////////////////////////////////////////
static const Quark _t_y_p_eco_c_c_Q5("void");
static const Quark _t_y_p_eco_c_c_Q2("int");
static const Quark _t_y_p_eco_c_c_Q4("bool");
static const Quark _t_y_p_eco_c_c_Q6("Quark");
static const Quark _t_y_p_eco_c_c_Q1("char");
static const Quark _t_y_p_eco_c_c_Q7("BigInt");
static const Quark _t_y_p_eco_c_c_Q3("double");
#line 1 "type.pcc"
/////////////////////////////////////////////////////////////////////////////
//
//  This file implements the type analysis and type inference module
//  in the Prop -> C++ translator.
//
/////////////////////////////////////////////////////////////////////////////

#include <AD/strings/quark.h>
#include "hashtab.h"
#include "ir.h"
#include "ast.h"
#include "collection.h"
#include "type.h"
#include "datatype.h"
#include "list.h"
#include "options.h"

/////////////////////////////////////////////////////////////////////////////
//
//  Types for literals
//
/////////////////////////////////////////////////////////////////////////////
Ty string_ty    = NOty, 
   character_ty = NOty, 
   integer_ty   = NOty, 
   real_ty      = NOty,
   bool_ty      = NOty,
   void_ty      = NOty,
   quark_ty     = NOty,
   bigint_ty    = NOty;

/////////////////////////////////////////////////////////////////////////////
//
// Initialize the types
//
/////////////////////////////////////////////////////////////////////////////
void initialize_types()
{  character_ty = mkidty(
#line 38 "type.pcc"
#line 38 "type.pcc"
_t_y_p_eco_c_c_Q1
#line 38 "type.pcc"
#line 38 "type.pcc"
,
#line 38 "type.pcc"
#line 38 "type.pcc"
nil_1_
#line 38 "type.pcc"
#line 38 "type.pcc"
);
   string_ty    = mkptrty(QUALty(QUALconst,character_ty));
   integer_ty   = mkidty(
#line 40 "type.pcc"
#line 40 "type.pcc"
_t_y_p_eco_c_c_Q2
#line 40 "type.pcc"
#line 40 "type.pcc"
,
#line 40 "type.pcc"
#line 40 "type.pcc"
nil_1_
#line 40 "type.pcc"
#line 40 "type.pcc"
);
   real_ty      = mkidty(
#line 41 "type.pcc"
#line 41 "type.pcc"
_t_y_p_eco_c_c_Q3
#line 41 "type.pcc"
#line 41 "type.pcc"
,
#line 41 "type.pcc"
#line 41 "type.pcc"
nil_1_
#line 41 "type.pcc"
#line 41 "type.pcc"
);
   bool_ty      = mkidty(
#line 42 "type.pcc"
#line 42 "type.pcc"
_t_y_p_eco_c_c_Q4
#line 42 "type.pcc"
#line 42 "type.pcc"
,
#line 42 "type.pcc"
#line 42 "type.pcc"
nil_1_
#line 42 "type.pcc"
#line 42 "type.pcc"
);
   void_ty      = mkidty(
#line 43 "type.pcc"
#line 43 "type.pcc"
_t_y_p_eco_c_c_Q5
#line 43 "type.pcc"
#line 43 "type.pcc"
,
#line 43 "type.pcc"
#line 43 "type.pcc"
nil_1_
#line 43 "type.pcc"
#line 43 "type.pcc"
);
   quark_ty     = mkidty(
#line 44 "type.pcc"
#line 44 "type.pcc"
_t_y_p_eco_c_c_Q6
#line 44 "type.pcc"
#line 44 "type.pcc"
,
#line 44 "type.pcc"
#line 44 "type.pcc"
nil_1_
#line 44 "type.pcc"
#line 44 "type.pcc"
);  
   bigint_ty    = mkidty(
#line 45 "type.pcc"
#line 45 "type.pcc"
_t_y_p_eco_c_c_Q7
#line 45 "type.pcc"
#line 45 "type.pcc"
,
#line 45 "type.pcc"
#line 45 "type.pcc"
nil_1_
#line 45 "type.pcc"
#line 45 "type.pcc"
);
}

/////////////////////////////////////////////////////////////////////////////
//
//  Make a type variable
//
/////////////////////////////////////////////////////////////////////////////
Ty mkvar() { return VARty(NOty); }

/////////////////////////////////////////////////////////////////////////////
//
//  Constructors for some common types
//
/////////////////////////////////////////////////////////////////////////////
Ty mkptrty    (Ty ty)                { return TYCONty(POINTERtycon, 
#line 60 "type.pcc"
#line 60 "type.pcc"
list_1_(ty)
#line 60 "type.pcc"
#line 60 "type.pcc"
); }
Ty mkrefty    (Ty ty)                { return TYCONty(REFtycon, 
#line 61 "type.pcc"
#line 61 "type.pcc"
list_1_(ty)
#line 61 "type.pcc"
#line 61 "type.pcc"
); }
Ty mkfunty    (Ty a, Ty b)           { return TYCONty(FUNtycon, 
#line 62 "type.pcc"
#line 62 "type.pcc"
list_1_(a,list_1_(b))
#line 62 "type.pcc"
#line 62 "type.pcc"
); }
Ty mkarrayty  (Ty a, Exp e)          { return TYCONty(ARRAYtycon(e), 
#line 63 "type.pcc"
#line 63 "type.pcc"
list_1_(a)
#line 63 "type.pcc"
#line 63 "type.pcc"
); }
Ty mkidty     (Id id, Tys args)      { return TYCONty(IDtycon(id), args); }
Ty mkidvarty  (Id id, TyVars args)   { return TYCONty(IDtycon(id), tyvars_to_tys(args)); }
Ty mktuplety  (Tys tys)              { return TYCONty(TUPLEtycon, tys); }
Ty mkrecordty (Ids l, Tys t, Bool f) { return TYCONty(RECORDtycon(l,f), t); }
Ty mktypety   ()                     { return TYCONty(TYPEtycon,
#line 68 "type.pcc"
#line 68 "type.pcc"
nil_1_
#line 68 "type.pcc"
#line 68 "type.pcc"
); }
Tys tyvars_to_tys (TyVars a)
{  
#line 70 "type.pcc"
#line 72 "type.pcc"
{
   if (a) {
#line 72 "type.pcc"
     return 
#line 72 "type.pcc"
#line 72 "type.pcc"
      list_1_(mkidty(a->_1,nil_1_),tyvars_to_tys(a->_2))
#line 72 "type.pcc"
#line 72 "type.pcc"
      ; 
#line 72 "type.pcc"
   } else {
#line 71 "type.pcc"
     return 
#line 71 "type.pcc"
#line 71 "type.pcc"
      nil_1_
#line 71 "type.pcc"
#line 71 "type.pcc"
      ; 
#line 71 "type.pcc"
   }
}
#line 73 "type.pcc"
#line 73 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
// Return the representation tag of a constructor
//
/////////////////////////////////////////////////////////////////////////////
int tag_of(Cons cons)
{  
#line 82 "type.pcc"
#line 85 "type.pcc"
{
   if (cons) {
      if (cons->alg_ty) {
         switch (cons->alg_ty->tag__) {
            case a_Ty::tag_TYCONty: {
               if (boxed(((Ty_TYCONty *)cons->alg_ty)->_1)) {
                  switch (((Ty_TYCONty *)cons->alg_ty)->_1->tag__) {
                     case a_TyCon::tag_DATATYPEtycon: {
#line 84 "type.pcc"
                      return cons->tag + ((((TyCon_DATATYPEtycon *)((Ty_TYCONty *)cons->alg_ty)->_1)->qualifiers & QUALlexeme) ? 256 : 0); 
#line 84 "type.pcc"
                        } break;
                     default: {
                        L1:; 
#line 85 "type.pcc"
                       return 0; 
#line 85 "type.pcc"
                        } break;
                  }
               } else { goto L1; }
               } break;
            default: { goto L1; } break;
         }
      } else { goto L1; }
   } else { goto L1; }
}
#line 86 "type.pcc"
#line 86 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//  Convert type variables to a type list
/////////////////////////////////////////////////////////////////////////////
Tys tyvars_to_type_list(int i, TyVars tyvars)
{  
#line 93 "type.pcc"
#line 95 "type.pcc"
{
   if (tyvars) {
#line 95 "type.pcc"
     return 
#line 95 "type.pcc"
#line 95 "type.pcc"
      list_1_(INDty(tyvars->_1,i),tyvars_to_type_list((i + 1),tyvars->_2))
#line 95 "type.pcc"
#line 95 "type.pcc"
      ; 
#line 95 "type.pcc"
   } else {
#line 94 "type.pcc"
     return 
#line 94 "type.pcc"
#line 94 "type.pcc"
      nil_1_
#line 94 "type.pcc"
#line 94 "type.pcc"
      ; 
#line 94 "type.pcc"
   }
}
#line 96 "type.pcc"
#line 96 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Make a universally quantified type
//
/////////////////////////////////////////////////////////////////////////////
Ty mkpolyty(Ty ty, TyVars tyvars)
{  int arity = length(tyvars);
   if (arity == 0) return ty;
   Id * bound_vars = (Id *)mem_pool[arity * sizeof(Id)];
   int i = 0;
   for_each (TyVar, tv, tyvars)
      bound_vars[i++] = tv; 
   return POLYty(deref(ty),arity,bound_vars);
/*
   match (deref(ty))
   {  TYCONty(tycon,_):
      { return POLYty
          (TYCONty(tycon,tyvars_to_type_list(0,tyvars)), arity, bound_vars);
      }
   |  _: { bug("mkpolyty()"); }
   }
*/
}

/////////////////////////////////////////////////////////////////////////////
//
//  Dereference a type expression
//
/////////////////////////////////////////////////////////////////////////////
Ty deref_all(Ty ty)
{  
#line 129 "type.pcc"
#line 141 "type.pcc"
{
   for (;;) {
      if (ty) {
         switch (ty->tag__) {
            case a_Ty::tag_VARty: {
               if (((Ty_VARty *)ty)->VARty) {
#line 130 "type.pcc"
                 ty = ((Ty_VARty *)ty)->VARty; 
#line 130 "type.pcc"
               } else {
                  L3:; 
#line 141 "type.pcc"
                 return ty; 
#line 141 "type.pcc"
               }
               } break;
            case a_Ty::tag_QUALty: {
#line 131 "type.pcc"
              ty = ((Ty_QUALty *)ty)->_2; 
#line 131 "type.pcc"
               } break;
            case a_Ty::tag_TYCONty: {
               if (boxed(((Ty_TYCONty *)ty)->_1)) {
                  switch (((Ty_TYCONty *)ty)->_1->tag__) {
                     case a_TyCon::tag_IDtycon: {
                        if (((Ty_TYCONty *)ty)->_2) {
#line 136 "type.pcc"
                         
#line 136 "type.pcc"
#line 138 "type.pcc"
                           {
                              Ty _V1 = lookup_ty(((TyCon_IDtycon *)((Ty_TYCONty *)ty)->_1)->IDtycon);
                              if (_V1) {
                                 switch (_V1->tag__) {
                                    case a_Ty::tag_TYCONty: {
#line 137 "type.pcc"
                                      return TYCONty(((Ty_TYCONty *)_V1)->_1,((Ty_TYCONty *)ty)->_2); 
#line 137 "type.pcc"
                                       } break;
                                    default: {
                                       L4:; 
#line 138 "type.pcc"
                                      return ty; 
#line 138 "type.pcc"
                                       } break;
                                 }
                              } else { goto L4; }
                           }
#line 139 "type.pcc"
#line 139 "type.pcc"
                           
                           
#line 140 "type.pcc"
                        } else {
#line 134 "type.pcc"
                         Ty t = lookup_ty(((TyCon_IDtycon *)((Ty_TYCONty *)ty)->_1)->IDtycon); if (t != NOty) ty = t; else return ty; 
#line 134 "type.pcc"
                        }
                        } break;
                     default: { goto L3; } break;
                  }
               } else { goto L3; }
               } break;
            case a_Ty::tag_DEFVALty: {
#line 132 "type.pcc"
              ty = ((Ty_DEFVALty *)ty)->_1; 
#line 132 "type.pcc"
               } break;
            default: { goto L3; } break;
         }
      } else { goto L3; }
   }
}
#line 142 "type.pcc"
#line 142 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Dereference a type expression.
//
/////////////////////////////////////////////////////////////////////////////
Ty deref(Ty ty)
{  
#line 151 "type.pcc"
#line 151 "type.pcc"
{
   for (;;) {
      if (ty) {
         switch (ty->tag__) {
            case a_Ty::tag_VARty: {
               if (((Ty_VARty *)ty)->VARty) {
#line 151 "type.pcc"
                 ty = ((Ty_VARty *)ty)->VARty; 
#line 151 "type.pcc"
               } else { goto L5; }
               } break;
            default: { goto L5; } break;
         }
      } else { goto L5; }
   }
   L5:;
}
#line 151 "type.pcc"
#line 151 "type.pcc"

   return ty;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Get the default value of a type (if any)
//
/////////////////////////////////////////////////////////////////////////////
Exp default_val(Ty ty)
{  
#line 161 "type.pcc"
#line 163 "type.pcc"
{
   Ty _V2 = deref(ty);
   if (_V2) {
      switch (_V2->tag__) {
         case a_Ty::tag_DEFVALty: {
#line 162 "type.pcc"
           return ((Ty_DEFVALty *)_V2)->_2; 
#line 162 "type.pcc"
            } break;
         default: {
            L6:; 
#line 163 "type.pcc"
           return NOexp; 
#line 163 "type.pcc"
            } break;
      }
   } else { goto L6; }
}
#line 164 "type.pcc"
#line 164 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Test for qualifiers in a type
//
/////////////////////////////////////////////////////////////////////////////
Bool has_qual(TyQual q, Ty ty)
{  
#line 173 "type.pcc"
#line 178 "type.pcc"
{
   for (;;) {
      if (ty) {
         switch (ty->tag__) {
            case a_Ty::tag_VARty: {
#line 174 "type.pcc"
              ty = ((Ty_VARty *)ty)->VARty; 
#line 174 "type.pcc"
               } break;
            case a_Ty::tag_QUALty: {
#line 178 "type.pcc"
              if (q & ((Ty_QUALty *)ty)->_1) return true; ty = ((Ty_QUALty *)ty)->_2; 
#line 178 "type.pcc"
               } break;
            case a_Ty::tag_TYCONty: {
               if (boxed(((Ty_TYCONty *)ty)->_1)) {
                  switch (((Ty_TYCONty *)ty)->_1->tag__) {
                     case a_TyCon::tag_DATATYPEtycon: {
#line 177 "type.pcc"
                       return ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)ty)->_1)->qualifiers & q; 
#line 177 "type.pcc"
                        } break;
                     default: { goto L7; } break;
                  }
               } else { goto L7; }
               } break;
            case a_Ty::tag_DEFVALty: {
#line 176 "type.pcc"
              ty = ((Ty_DEFVALty *)ty)->_1; 
#line 176 "type.pcc"
               } break;
            case a_Ty::tag_NESTEDty: {
#line 175 "type.pcc"
              ty = ((Ty_NESTEDty *)ty)->_2; 
#line 175 "type.pcc"
               } break;
            default: { goto L7; } break;
         }
      } else { goto L7; }
   }
   L7:;
}
#line 179 "type.pcc"
#line 179 "type.pcc"

   return false;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Test if a type is grounded (i.e. contains no type variables.)
//
/////////////////////////////////////////////////////////////////////////////
Bool is_ground(Ty ty)
{  
#line 189 "type.pcc"
#line 195 "type.pcc"
{
   for (;;) {
      if (ty) {
         switch (ty->tag__) {
            case a_Ty::tag_VARty: {
#line 190 "type.pcc"
              ty = ((Ty_VARty *)ty)->VARty; 
#line 190 "type.pcc"
               } break;
            case a_Ty::tag_QUALty: {
#line 191 "type.pcc"
              ty = ((Ty_QUALty *)ty)->_2; 
#line 191 "type.pcc"
               } break;
            case a_Ty::tag_TYCONty: {
#line 194 "type.pcc"
              return is_ground(((Ty_TYCONty *)ty)->_2); 
#line 194 "type.pcc"
               } break;
            case a_Ty::tag_DEFVALty: {
#line 192 "type.pcc"
              ty = ((Ty_DEFVALty *)ty)->_1; 
#line 192 "type.pcc"
               } break;
            case a_Ty::tag_NESTEDty: {
#line 193 "type.pcc"
              if (! is_ground(((Ty_NESTEDty *)ty)->_1)) return false; ty = ((Ty_NESTEDty *)ty)->_2; 
#line 193 "type.pcc"
               } break;
            default: {
               L9:; 
#line 195 "type.pcc"
              return false; 
#line 195 "type.pcc"
               } break;
         }
      } else { goto L9; }
   }
}
#line 196 "type.pcc"
#line 196 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Test if a type list is grounded
//
/////////////////////////////////////////////////////////////////////////////
Bool is_ground(Tys tys)
{  for_each (Ty, t, tys) if (! is_ground(t)) return false;
   return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Test if a type is an array
//
/////////////////////////////////////////////////////////////////////////////
Bool is_array_ty(Ty ty)
{  
#line 215 "type.pcc"
#line 218 "type.pcc"
{
   Ty _V3 = deref_all(ty);
   if (_V3) {
      switch (_V3->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V3)->_1)) {
               switch (((Ty_TYCONty *)_V3)->_1->tag__) {
                  case a_TyCon::tag_ARRAYtycon: {
                     if (((TyCon_ARRAYtycon *)((Ty_TYCONty *)_V3)->_1)->ARRAYtycon) {
                        if (((Ty_TYCONty *)_V3)->_2) {
                           L10:; 
                           if (((Ty_TYCONty *)_V3)->_2->_2) {
                              L11:; 
#line 218 "type.pcc"
                             return false; 
#line 218 "type.pcc"
                           } else {
                              L12:; 
#line 216 "type.pcc"
                             return true; 
#line 216 "type.pcc"
                           }
                        } else { goto L11; }
                     } else { goto L11; }
                     } break;
                  default: { goto L11; } break;
               }
            } else { goto L11; }
            } break;
         case a_Ty::tag_NESTEDty: {
#line 217 "type.pcc"
           return is_array_ty(((Ty_NESTEDty *)_V3)->_2); 
#line 217 "type.pcc"
            } break;
         default: { goto L11; } break;
      }
   } else { goto L11; }
}
#line 219 "type.pcc"
#line 219 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Test if a type is a polymorphic datatype
//
/////////////////////////////////////////////////////////////////////////////
Bool is_poly_datatype(Ty ty)
{  
#line 228 "type.pcc"
#line 230 "type.pcc"
{
   Ty _V4 = deref_all(ty);
   if (_V4) {
      switch (_V4->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V4)->_1)) {
               switch (((Ty_TYCONty *)_V4)->_1->tag__) {
                  case a_TyCon::tag_DATATYPEtycon: {
#line 229 "type.pcc"
                    return ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V4)->_1)->tyvars != 
#line 229 "type.pcc"
#line 229 "type.pcc"
                     nil_1_
#line 229 "type.pcc"
#line 229 "type.pcc"
                     ; 
#line 229 "type.pcc"
                     } break;
                  default: {
                     L13:; 
#line 230 "type.pcc"
                    return false; 
#line 230 "type.pcc"
                     } break;
               }
            } else { goto L13; }
            } break;
         default: { goto L13; } break;
      }
   } else { goto L13; }
}
#line 231 "type.pcc"
#line 231 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Test if a type is a datatype.
//
/////////////////////////////////////////////////////////////////////////////
Bool is_datatype(Ty ty)
{  
#line 240 "type.pcc"
#line 242 "type.pcc"
{
   Ty _V5 = deref_all(ty);
   if (_V5) {
      switch (_V5->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V5)->_1)) {
               switch (((Ty_TYCONty *)_V5)->_1->tag__) {
                  case a_TyCon::tag_DATATYPEtycon: {
#line 241 "type.pcc"
                    return true; 
#line 241 "type.pcc"
                     } break;
                  default: {
                     L14:; 
#line 242 "type.pcc"
                    return false; 
#line 242 "type.pcc"
                     } break;
               }
            } else { goto L14; }
            } break;
         default: { goto L14; } break;
      }
   } else { goto L14; }
}
#line 243 "type.pcc"
#line 243 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
// Add a new class to an inheritance list
//
/////////////////////////////////////////////////////////////////////////////
Inherits add_inherit(Id id, TyVars p, Inherits i, Scope s, TyQual t)
{  Inherit inh = 
#line 252 "type.pcc"
#line 252 "type.pcc"
INHERIT(mkidty(id,tyvars_to_tys(p)), s, t)
#line 254 "type.pcc"
#line 254 "type.pcc"
;
   return 
#line 255 "type.pcc"
#line 255 "type.pcc"
list_1_(inh,i)
#line 255 "type.pcc"
#line 255 "type.pcc"
;
}


/////////////////////////////////////////////////////////////////////////////
//
//  Test if a type is garbage collectable.
//
/////////////////////////////////////////////////////////////////////////////
Bool is_gc_ty(Ty ty)
{  
#line 265 "type.pcc"
#line 279 "type.pcc"
{
   for (;;) {
      if (ty) {
         switch (ty->tag__) {
            case a_Ty::tag_VARty: {
#line 272 "type.pcc"
              ty = ((Ty_VARty *)ty)->VARty; 
#line 272 "type.pcc"
               } break;
            case a_Ty::tag_QUALty: {
#line 273 "type.pcc"
              if (((Ty_QUALty *)ty)->_1 & QUALcollectable) return true; ty = ((Ty_QUALty *)ty)->_2; 
#line 273 "type.pcc"
               } break;
            case a_Ty::tag_TYCONty: {
               if (boxed(((Ty_TYCONty *)ty)->_1)) {
                  switch (((Ty_TYCONty *)ty)->_1->tag__) {
                     case a_TyCon::tag_IDtycon: {
#line 275 "type.pcc"
                      Ty t = deref_all(ty);
                        if (t == ty) return false;
                        ty = t;
                        
#line 278 "type.pcc"
                        } break;
                     case a_TyCon::tag_DATATYPEtycon: {
#line 267 "type.pcc"
                       return (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)ty)->_1)->qualifiers & QUALcollectable) && (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)ty)->_1)->arg > 0); 
#line 267 "type.pcc"
                        } break;
                     default: {
                        L16:; 
#line 279 "type.pcc"
                       return false; 
#line 279 "type.pcc"
                        } break;
                  }
               } else {
                  switch ((int)((Ty_TYCONty *)ty)->_1) {
                     case ((int)POINTERtycon): {
                        if (((Ty_TYCONty *)ty)->_2) {
                           if (((Ty_TYCONty *)ty)->_2->_2) { goto L16; } else {
#line 269 "type.pcc"
                             ty = ((Ty_TYCONty *)ty)->_2->_1; 
#line 269 "type.pcc"
                           }
                        } else { goto L16; }
                        } break;
                     case ((int)REFtycon): {
                        if (((Ty_TYCONty *)ty)->_2) {
                           if (((Ty_TYCONty *)ty)->_2->_2) { goto L16; } else {
#line 268 "type.pcc"
                             ty = ((Ty_TYCONty *)ty)->_2->_1; 
#line 268 "type.pcc"
                           }
                        } else { goto L16; }
                        } break;
                     default: { goto L16; } break;
                  }
               }
               } break;
            case a_Ty::tag_DEFVALty: {
#line 270 "type.pcc"
              ty = ((Ty_DEFVALty *)ty)->_1; 
#line 270 "type.pcc"
               } break;
            case a_Ty::tag_NESTEDty: {
#line 271 "type.pcc"
              ty = ((Ty_NESTEDty *)ty)->_2; 
#line 271 "type.pcc"
               } break;
            default: { goto L16; } break;
         }
      } else { goto L16; }
   }
}
#line 280 "type.pcc"
#line 280 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Test if type is a pointer.
//
/////////////////////////////////////////////////////////////////////////////
Bool is_pointer_ty(Ty ty)
{  
#line 289 "type.pcc"
#line 291 "type.pcc"
{
   Ty _V6 = deref_all(ty);
   if (_V6) {
      switch (_V6->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V6)->_1)) {
               switch (((Ty_TYCONty *)_V6)->_1->tag__) {
                  case a_TyCon::tag_DATATYPEtycon: {
                     L17:; 
#line 290 "type.pcc"
                    return true; 
#line 290 "type.pcc"
                     } break;
                  default: {
                     L18:; 
#line 291 "type.pcc"
                    return false; 
#line 291 "type.pcc"
                     } break;
               }
            } else {
               switch ((int)((Ty_TYCONty *)_V6)->_1) {
                  case ((int)POINTERtycon): { goto L17; } break;
                  default: { goto L18; } break;
               }
            }
            } break;
         default: { goto L18; } break;
      }
   } else { goto L18; }
}
#line 292 "type.pcc"
#line 292 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Test if type is embeddable into 1 word
//
/////////////////////////////////////////////////////////////////////////////
Bool is_embeddable_ty(Ty ty)
{  
#line 301 "type.pcc"
#line 309 "type.pcc"
{
   Ty _V7 = deref_all(ty);
   if (_V7) {
      switch (_V7->tag__) {
         case a_Ty::tag_TYCONty: {
            if (
#line 306 "type.pcc"
            ((ty_equal(_V7,integer_ty) || ty_equal(_V7,character_ty)) || ty_equal(_V7,bool_ty))
#line 308 "type.pcc"
) {
               
               if (boxed(((Ty_TYCONty *)_V7)->_1)) {
                  switch (((Ty_TYCONty *)_V7)->_1->tag__) {
                     case a_TyCon::tag_DATATYPEtycon: {
                        if (
#line 304 "type.pcc"
                        ((((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V7)->_1)->opt & OPTtaggedpointer) == 0)
#line 304 "type.pcc"
) {
                           
                           L19:; 
                           switch (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V7)->_1)->arg) {
                              case 0: {
                                 L20:; 
#line 302 "type.pcc"
                                return true; 
#line 302 "type.pcc"
                              } break;
                              default: {
                                 L21:; 
#line 304 "type.pcc"
                                return true; 
#line 304 "type.pcc"
                              }
                           }
                        } else {
                           
                           switch (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V7)->_1)->arg) {
                              case 0: { goto L20; } break;
                              default: {
                                 L22:; 
#line 308 "type.pcc"
                                return true; 
#line 308 "type.pcc"
                              }
                           }
                        }
                        } break;
                     default: { goto L22; } break;
                  }
               } else {
                  switch ((int)((Ty_TYCONty *)_V7)->_1) {
                     case ((int)POINTERtycon): {
                        if (((Ty_TYCONty *)_V7)->_2) {
                           if (((Ty_TYCONty *)_V7)->_2->_2) { goto L22; } else {
                              if (
#line 305 "type.pcc"
                              (((Ty_TYCONty *)_V7)->_2->_1 != character_ty)
#line 305 "type.pcc"
) {
                                 
                                 L23:; 
#line 305 "type.pcc"
                                return true; 
#line 305 "type.pcc"
                              } else {
                                  goto L22; }
                           }
                        } else { goto L22; }
                        } break;
                     default: { goto L22; } break;
                  }
               }
            } else {
               
               if (boxed(((Ty_TYCONty *)_V7)->_1)) {
                  switch (((Ty_TYCONty *)_V7)->_1->tag__) {
                     case a_TyCon::tag_DATATYPEtycon: {
                        if (
#line 304 "type.pcc"
                        ((((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V7)->_1)->opt & OPTtaggedpointer) == 0)
#line 304 "type.pcc"
) {
                            goto L19; } else {
                           
                           switch (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V7)->_1)->arg) {
                              case 0: { goto L20; } break;
                              default: {
                                 L24:; 
#line 309 "type.pcc"
                                return false; 
#line 309 "type.pcc"
                              }
                           }
                        }
                        } break;
                     default: { goto L24; } break;
                  }
               } else {
                  switch ((int)((Ty_TYCONty *)_V7)->_1) {
                     case ((int)POINTERtycon): {
                        if (((Ty_TYCONty *)_V7)->_2) {
                           if (((Ty_TYCONty *)_V7)->_2->_2) { goto L24; } else {
                              if (
#line 305 "type.pcc"
                              (((Ty_TYCONty *)_V7)->_2->_1 != character_ty)
#line 305 "type.pcc"
) {
                                  goto L23; } else {
                                  goto L24; }
                           }
                        } else { goto L24; }
                        } break;
                     default: { goto L24; } break;
                  }
               }
            }
            } break;
         default: {
            L25:; 
            if (
#line 306 "type.pcc"
            ((ty_equal(_V7,integer_ty) || ty_equal(_V7,character_ty)) || ty_equal(_V7,bool_ty))
#line 308 "type.pcc"
) {
                goto L22; } else {
                goto L24; }
            } break;
      }
   } else { goto L25; }
}
#line 310 "type.pcc"
#line 310 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Test if constructor is an array-style constructor
//
/////////////////////////////////////////////////////////////////////////////
Bool is_array_constructor(Id id) { return id[1] == '|'; }
Bool is_list_constructor(Id id) { return id[0] == '#' && 
				     (id[1] == '[' || 
				      id[1] == '(' ||
				      id[1] == '{'); }
Bool is_list_constructor(Cons cons) 
{ return cons != NOcons && is_list_constructor(cons->name); }

/////////////////////////////////////////////////////////////////////////////
//
//  Returns the number of boxed variants.
//
/////////////////////////////////////////////////////////////////////////////
int boxed_variants(Ty ty)
{  
#line 332 "type.pcc"
#line 334 "type.pcc"
{
   Ty _V8 = deref_all(ty);
   if (_V8) {
      switch (_V8->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V8)->_1)) {
               switch (((Ty_TYCONty *)_V8)->_1->tag__) {
                  case a_TyCon::tag_DATATYPEtycon: {
#line 333 "type.pcc"
                    return ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V8)->_1)->arg; 
#line 333 "type.pcc"
                     } break;
                  default: {
                     L26:; 
#line 334 "type.pcc"
                    return 0; 
#line 334 "type.pcc"
                     } break;
               }
            } else { goto L26; }
            } break;
         default: { goto L26; } break;
      }
   } else { goto L26; }
}
#line 335 "type.pcc"
#line 335 "type.pcc"

}

int unboxed_variants(Ty ty)
{  
#line 339 "type.pcc"
#line 341 "type.pcc"
{
   Ty _V9 = deref_all(ty);
   if (_V9) {
      switch (_V9->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V9)->_1)) {
               switch (((Ty_TYCONty *)_V9)->_1->tag__) {
                  case a_TyCon::tag_DATATYPEtycon: {
#line 340 "type.pcc"
                    return ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V9)->_1)->unit; 
#line 340 "type.pcc"
                     } break;
                  default: {
                     L27:; 
#line 341 "type.pcc"
                    return 0; 
#line 341 "type.pcc"
                     } break;
               }
            } else { goto L27; }
            } break;
         default: { goto L27; } break;
      }
   } else { goto L27; }
}
#line 342 "type.pcc"
#line 342 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Returns the arity of a type
//
/////////////////////////////////////////////////////////////////////////////
int arity_of(Ty ty)
{  
#line 351 "type.pcc"
#line 355 "type.pcc"
{
   Ty _V10 = deref_all(ty);
   if (_V10) {
      switch (_V10->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V10)->_1)) {
               switch (((Ty_TYCONty *)_V10)->_1->tag__) {
                  case a_TyCon::tag_RECORDtycon: {
                     L28:; 
#line 353 "type.pcc"
                    return length(((Ty_TYCONty *)_V10)->_2); 
#line 353 "type.pcc"
                     } break;
                  default: {
                     L29:; 
#line 355 "type.pcc"
                    return 1; 
#line 355 "type.pcc"
                     } break;
               }
            } else {
               switch ((int)((Ty_TYCONty *)_V10)->_1) {
                  case ((int)TUPLEtycon): { goto L28; } break;
                  default: { goto L29; } break;
               }
            }
            } break;
         case a_Ty::tag_NESTEDty: {
#line 354 "type.pcc"
           return arity_of(((Ty_NESTEDty *)_V10)->_2); 
#line 354 "type.pcc"
            } break;
         default: { goto L29; } break;
      }
   } else {
#line 352 "type.pcc"
     return 0; 
#line 352 "type.pcc"
   }
}
#line 356 "type.pcc"
#line 356 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Instantiate a polymorphic type scheme
//
/////////////////////////////////////////////////////////////////////////////
Ty inst (Ty ty, int n, Id bound_vars[], Ty subst[])
{  
#line 365 "type.pcc"
#line 376 "type.pcc"
{
   Ty _V11 = deref(ty);
   if (_V11) {
      switch (_V11->tag__) {
         case a_Ty::tag_VARty: {
            L30:; 
#line 366 "type.pcc"
           return ty; 
#line 366 "type.pcc"
            } break;
         case a_Ty::tag_INDty: {
#line 368 "type.pcc"
           return subst[((Ty_INDty *)_V11)->_2] != NOty ? subst[((Ty_INDty *)_V11)->_2] : (subst[((Ty_INDty *)_V11)->_2] = mkvar()); 
#line 368 "type.pcc"
            } break;
         case a_Ty::tag_QUALty: {
#line 369 "type.pcc"
           return QUALty(((Ty_QUALty *)_V11)->_1,inst(((Ty_QUALty *)_V11)->_2,n,bound_vars,subst)); 
#line 369 "type.pcc"
            } break;
         case a_Ty::tag_TYCONty: {
#line 375 "type.pcc"
          return TYCONty(((Ty_TYCONty *)_V11)->_1, inst(((Ty_TYCONty *)_V11)->_2,n,bound_vars,subst)); 
#line 375 "type.pcc"
            } break;
         case a_Ty::tag_POLYty: {
#line 376 "type.pcc"
           bug("inst()"); return NOty; 
#line 376 "type.pcc"
            } break;
         case a_Ty::tag_DEFVALty: {
#line 370 "type.pcc"
           return DEFVALty(inst(((Ty_DEFVALty *)_V11)->_1,n,bound_vars,subst),((Ty_DEFVALty *)_V11)->_2); 
#line 370 "type.pcc"
            } break;
         default: {
#line 371 "type.pcc"
           return NESTEDty(inst(((Ty_NESTEDty *)_V11)->_1,n,bound_vars,subst),
            inst(((Ty_NESTEDty *)_V11)->_2,n,bound_vars,subst));
            
#line 373 "type.pcc"
            } break;
      }
   } else { goto L30; }
}
#line 377 "type.pcc"
#line 377 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Instantiate a type list
//
/////////////////////////////////////////////////////////////////////////////
Tys inst (Tys tys, int n, Id bound_vars[], Ty subst[])
{  
#line 386 "type.pcc"
#line 390 "type.pcc"
{
   if (tys) {
#line 388 "type.pcc"
     return 
#line 388 "type.pcc"
#line 388 "type.pcc"
      list_1_(inst(tys->_1,n,bound_vars,subst),inst(tys->_2,n,bound_vars,subst))
#line 389 "type.pcc"
#line 389 "type.pcc"
      ;
      
#line 390 "type.pcc"
   } else {
#line 387 "type.pcc"
     return 
#line 387 "type.pcc"
#line 387 "type.pcc"
      nil_1_
#line 387 "type.pcc"
#line 387 "type.pcc"
      ; 
#line 387 "type.pcc"
   }
}
#line 391 "type.pcc"
#line 391 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Instantiate a polymorphic type scheme
//
/////////////////////////////////////////////////////////////////////////////
Ty inst(Ty polyty)
{  
#line 400 "type.pcc"
#line 406 "type.pcc"
{
   if (polyty) {
      switch (polyty->tag__) {
         case a_Ty::tag_POLYty: {
#line 402 "type.pcc"
          Ty subst[256];
            for (int i = ((Ty_POLYty *)polyty)->_2 - 1; i >= 0; i--) subst[i] = NOty;
            return inst(((Ty_POLYty *)polyty)->_1, ((Ty_POLYty *)polyty)->_2, ((Ty_POLYty *)polyty)->_3, subst); 
            
#line 405 "type.pcc"
            } break;
         default: {
            L31:; 
#line 406 "type.pcc"
           return polyty; 
#line 406 "type.pcc"
            } break;
      }
   } else { goto L31; }
}
#line 407 "type.pcc"
#line 407 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Construct component types 
//
/////////////////////////////////////////////////////////////////////////////
Ty component_ty (Ty datatype_ty, Cons cons)
{  
#line 416 "type.pcc"
#line 420 "type.pcc"
{
   Ty _V12 = deref_all(datatype_ty);
   if (_V12) {
      switch (_V12->tag__) {
         case a_Ty::tag_TYCONty: {
            if (cons) {
               if (boxed(((Ty_TYCONty *)_V12)->_1)) {
                  switch (((Ty_TYCONty *)_V12)->_1->tag__) {
                     case a_TyCon::tag_DATATYPEtycon: {
                        if (((Ty_TYCONty *)_V12)->_2) {
                           if (cons) {
                              if (cons->ty) {
                                 L32:; 
#line 418 "type.pcc"
                               return apply_ty(cons->cons_ty,((Ty_TYCONty *)_V12)->_2); 
#line 418 "type.pcc"
                              } else {
                                 L33:; 
#line 419 "type.pcc"
                                return cons->ty; 
#line 419 "type.pcc"
                              }
                           } else { goto L33; }
                        } else { goto L33; }
                        } break;
                     default: { goto L33; } break;
                  }
               } else { goto L33; }
            } else {
               if (boxed(((Ty_TYCONty *)_V12)->_1)) {
                  switch (((Ty_TYCONty *)_V12)->_1->tag__) {
                     case a_TyCon::tag_DATATYPEtycon: {
                        if (((Ty_TYCONty *)_V12)->_2) {
                           if (cons) {
                              if (cons->ty) { goto L32; } else {
                                 L34:; 
#line 420 "type.pcc"
                                return NOty; 
#line 420 "type.pcc"
                              }
                           } else { goto L34; }
                        } else { goto L34; }
                        } break;
                     default: { goto L34; } break;
                  }
               } else { goto L34; }
            }
            } break;
         default: {
            L35:; 
            if (cons) { goto L33; } else { goto L34; }
            } break;
      }
   } else { goto L35; }
}
#line 421 "type.pcc"
#line 421 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Extract record type component 
//
/////////////////////////////////////////////////////////////////////////////
Ty component_ty (Ty record_ty, Id label)
{  
#line 430 "type.pcc"
#line 441 "type.pcc"
{
   Ty _V13 = deref_all(record_ty);
   if (_V13) {
      switch (_V13->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V13)->_1)) {
               switch (((Ty_TYCONty *)_V13)->_1->tag__) {
                  case a_TyCon::tag_RECORDtycon: {
#line 432 "type.pcc"
                   Ids ls; Tys ts;
                     for (ls = ((TyCon_RECORDtycon *)((Ty_TYCONty *)_V13)->_1)->_1, ts = ((Ty_TYCONty *)_V13)->_2; ls && ts; ls = ls->_2, ts = ts->_2)
                        if (ls->_1 == label) return ts->_1;
                     
#line 435 "type.pcc"
                     } break;
                  default: {
                     L36:; } break;
               }
            } else {
               switch ((int)((Ty_TYCONty *)_V13)->_1) {
                  case ((int)TUPLEtycon): {
                     if (
#line 436 "type.pcc"
                     (label[0] == '_')
#line 436 "type.pcc"
) {
                        
#line 437 "type.pcc"
                       int i = atol(label+1);
                        if (i > 0) return component_ty(_V13,i);
                        
#line 439 "type.pcc"
                     } else {
                         goto L36; }
                     } break;
                  default: { goto L36; } break;
               }
            }
            } break;
         default: { goto L36; } break;
      }
   } else { goto L36; }
}
#line 441 "type.pcc"
#line 441 "type.pcc"

   error("%Ltype %T does not have component %s\n",record_ty,label);
   return NOty;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Extract tuple type component 
//
/////////////////////////////////////////////////////////////////////////////
Ty component_ty (Ty tuple_ty, int n)
{  
#line 452 "type.pcc"
#line 459 "type.pcc"
{
   Ty _V14 = deref_all(tuple_ty);
   if (_V14) {
      switch (_V14->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V14)->_1)) {
               L37:; } else {
               switch ((int)((Ty_TYCONty *)_V14)->_1) {
                  case ((int)TUPLEtycon): {
#line 454 "type.pcc"
                   int i; Tys ts;
                     for (i = 1, ts = ((Ty_TYCONty *)_V14)->_2; ts; ts = ts->_2, i++)
                        if (i == n) return ts->_1;
                     
#line 457 "type.pcc"
                     } break;
                  default: { goto L37; } break;
               }
            }
            } break;
         default: { goto L37; } break;
      }
   } else { goto L37; }
}
#line 459 "type.pcc"
#line 459 "type.pcc"

   error("%Ltype %T does not have component #%i\n",tuple_ty,n);
   return NOty;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Apply type arguments to a ty_scheme.
//
/////////////////////////////////////////////////////////////////////////////
Ty apply_ty (Ty cons_ty, Tys tys)
{  
#line 470 "type.pcc"
#line 495 "type.pcc"
{
   if (cons_ty) {
      switch (cons_ty->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)cons_ty)->_1)) {
               L38:; 
#line 495 "type.pcc"
              return cons_ty; 
#line 495 "type.pcc"
            } else {
               switch ((int)((Ty_TYCONty *)cons_ty)->_1) {
                  case ((int)FUNtycon): {
                     if (((Ty_TYCONty *)cons_ty)->_2) {
#line 494 "type.pcc"
                       return ((Ty_TYCONty *)cons_ty)->_2->_1; 
#line 494 "type.pcc"
                     } else { goto L38; }
                     } break;
                  default: { goto L38; } break;
               }
            }
            } break;
         case a_Ty::tag_POLYty: {
#line 472 "type.pcc"
          Ty subst[256]; int i; Tys ts;
            for (i = 0, ts = tys; i < ((Ty_POLYty *)cons_ty)->_2 && ts; i++, ts = ts->_2)
               subst[i] = ts->_1;
            if (ts != 
#line 475 "type.pcc"
#line 475 "type.pcc"
            nil_1_
#line 475 "type.pcc"
#line 475 "type.pcc"
            )
            {error("%Ltoo many arguments %P in instantiation of type scheme %T\n", 
                   tys, cons_ty);
              return NOty;
            }
            if (i != ((Ty_POLYty *)cons_ty)->_2)
            {error("%Ltoo few arguments %P in instantiation of type scheme %T\n", 
                   tys, cons_ty);
              return NOty;
            }
            Ty t = inst(((Ty_POLYty *)cons_ty)->_1, ((Ty_POLYty *)cons_ty)->_2, ((Ty_POLYty *)cons_ty)->_3, subst);
            
#line 486 "type.pcc"
#line 491 "type.pcc"
            {
               Ty _V15 = deref(t);
               if (_V15) {
                  switch (_V15->tag__) {
                     case a_Ty::tag_TYCONty: {
                        if (boxed(((Ty_TYCONty *)_V15)->_1)) {
                           L39:; 
#line 488 "type.pcc"
                          return _V15; 
#line 488 "type.pcc"
                        } else {
                           switch ((int)((Ty_TYCONty *)_V15)->_1) {
                              case ((int)FUNtycon): {
                                 if (((Ty_TYCONty *)_V15)->_2) {
                                    if (((Ty_TYCONty *)_V15)->_2->_2) {
                                       if (((Ty_TYCONty *)_V15)->_2->_2->_2) { goto L39; } else {
#line 487 "type.pcc"
                                         return ((Ty_TYCONty *)_V15)->_2->_1; 
#line 487 "type.pcc"
                                       }
                                    } else { goto L39; }
                                 } else { goto L39; }
                                 } break;
                              default: { goto L39; } break;
                           }
                        }
                        } break;
                     default: {
                        L40:; 
#line 489 "type.pcc"
                       error ("%Lbad constructor type %T\n",cons_ty); 
                        return NOty; 
                        
#line 491 "type.pcc"
                        } break;
                  }
               } else { goto L40; }
            }
#line 492 "type.pcc"
#line 492 "type.pcc"
            
            
#line 493 "type.pcc"
            } break;
         default: { goto L38; } break;
      }
   } else { goto L38; }
}
#line 496 "type.pcc"
#line 496 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Unify two type constructors
//
/////////////////////////////////////////////////////////////////////////////
Bool unify(TyCon a, TyCon b)
{  
#line 505 "type.pcc"
#line 520 "type.pcc"
{
   if (boxed(a)) {
      switch (a->tag__) {
         case a_TyCon::tag_IDtycon: {
            if (boxed(b)) {
               switch (b->tag__) {
                  case a_TyCon::tag_IDtycon: {
#line 509 "type.pcc"
                    return ((TyCon_IDtycon *)a)->IDtycon == ((TyCon_IDtycon *)b)->IDtycon; 
#line 509 "type.pcc"
                     } break;
                  default: {
                     L41:; 
#line 520 "type.pcc"
                    return false; 
#line 520 "type.pcc"
                     } break;
               }
            } else { goto L41; }
            } break;
         case a_TyCon::tag_ARRAYtycon: {
            L42:; 
            if (boxed(b)) {
               switch (b->tag__) {
                  case a_TyCon::tag_ARRAYtycon: {
                     L43:; 
#line 507 "type.pcc"
                    return true; 
#line 507 "type.pcc"
                     } break;
                  default: { goto L41; } break;
               }
            } else {
               switch ((int)b) {
                  case ((int)POINTERtycon): { goto L43; } break;
                  default: { goto L41; } break;
               }
            }
            } break;
         case a_TyCon::tag_BITFIELDtycon: {
            if (boxed(b)) {
               switch (b->tag__) {
                  case a_TyCon::tag_BITFIELDtycon: {
#line 519 "type.pcc"
                    return ((TyCon_BITFIELDtycon *)a)->width == ((TyCon_BITFIELDtycon *)b)->width && ((TyCon_BITFIELDtycon *)a)->is_signed == ((TyCon_BITFIELDtycon *)b)->is_signed; 
#line 519 "type.pcc"
                     } break;
                  default: { goto L41; } break;
               }
            } else { goto L41; }
            } break;
         case a_TyCon::tag_DATATYPEtycon: {
            if (boxed(b)) {
               switch (b->tag__) {
                  case a_TyCon::tag_DATATYPEtycon: {
#line 514 "type.pcc"
                    return a == b; 
#line 514 "type.pcc"
                     } break;
                  default: { goto L41; } break;
               }
            } else { goto L41; }
            } break;
         case a_TyCon::tag_COLtycon: {
            if (boxed(b)) {
               switch (b->tag__) {
                  case a_TyCon::tag_COLtycon: {
#line 516 "type.pcc"
                    return ((TyCon_COLtycon *)a)->COLtycon->name == ((TyCon_COLtycon *)b)->COLtycon->name; 
#line 516 "type.pcc"
                     } break;
                  default: { goto L41; } break;
               }
            } else { goto L41; }
            } break;
         default: { goto L41; } break;
      }
   } else {
      switch ((int)a) {
         case ((int)POINTERtycon): { goto L42; } break;
         case ((int)REFtycon): {
            if (boxed(b)) { goto L41; } else {
               switch ((int)b) {
                  case ((int)REFtycon): {
#line 508 "type.pcc"
                    return true; 
#line 508 "type.pcc"
                     } break;
                  default: { goto L41; } break;
               }
            }
            } break;
         case ((int)TUPLEtycon): {
            if (boxed(b)) { goto L41; } else {
               switch ((int)b) {
                  case ((int)TUPLEtycon): {
#line 510 "type.pcc"
                    return true; 
#line 510 "type.pcc"
                     } break;
                  default: { goto L41; } break;
               }
            }
            } break;
         case ((int)EXTUPLEtycon): {
            if (boxed(b)) { goto L41; } else {
               switch ((int)b) {
                  case ((int)EXTUPLEtycon): {
#line 511 "type.pcc"
                    return true; 
#line 511 "type.pcc"
                     } break;
                  default: { goto L41; } break;
               }
            }
            } break;
         case ((int)FUNtycon): {
            if (boxed(b)) { goto L41; } else {
               switch ((int)b) {
                  case ((int)FUNtycon): {
#line 513 "type.pcc"
                    return true; 
#line 513 "type.pcc"
                     } break;
                  default: { goto L41; } break;
               }
            }
            } break;
         default: {
            if (boxed(b)) { goto L41; } else {
               switch ((int)b) {
                  case ((int)TYPEtycon): {
#line 512 "type.pcc"
                    return true; 
#line 512 "type.pcc"
                     } break;
                  default: { goto L41; } break;
               }
            }
            } break;
      }
   }
}
#line 521 "type.pcc"
#line 521 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Unify two record types
//
/////////////////////////////////////////////////////////////////////////////
Bool unify_record
   (Ty u, Ids& x, Tys& a, Bool& f, 
    Ty v, Ids& y, Tys& b, Bool& g, Bool again = true)
{  Ids i, j;
   Tys p, q;
   Bool ok = true;

   for (i = x, p = a; i; i = i->_2, p = p->_2) {
      Bool b_found = false;
      for (j = y, q = b; j; j = j->_2, q = q->_2) {
         if (i->_1 == j->_1) {
            if (b_found) {
               error ("%Lduplicated label '%s' in type %T\n", i->_1, v);
               ok = false;
            }
            b_found = true;
            if (! unify(p->_1, q->_1)) ok = false;
         }
      }
      if (! b_found && ! g) {
         error ("%L%s label '%s' in type %T\n", 
                (again ? "missing" : "extra"), i->_1, v);
         ok = false;
      }
   }

   // unify in the other direction if not flexible
   if (again && ! f) unify_record(v,y,b,g,u,x,a,f,false);

   if (! f && g) { y = x; b = a; }
   if (! g && f) { x = y; a = b; }

   if (! f) g = false;
   if (! g) f = false;

   return ok;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Occurs check
//
/////////////////////////////////////////////////////////////////////////////
Bool occurs (Ty ty, Ty tyvar)
{  
#line 573 "type.pcc"
#line 579 "type.pcc"
{
   Ty _V16 = deref_all(ty);
   if (_V16) {
      switch (_V16->tag__) {
         case a_Ty::tag_VARty: {
            if (
#line 574 "type.pcc"
            (tyvar == _V16)
#line 574 "type.pcc"
) {
               
#line 574 "type.pcc"
              return true; 
#line 574 "type.pcc"
            } else {
               
               L44:; 
#line 579 "type.pcc"
              return false; 
#line 579 "type.pcc"
            }
            } break;
         case a_Ty::tag_TYCONty: {
#line 576 "type.pcc"
          for_each(Ty, t, ((Ty_TYCONty *)_V16)->_2) if (occurs(t,tyvar)) return true; 
            return false;
            
#line 578 "type.pcc"
            } break;
         default: { goto L44; } break;
      }
   } else { goto L44; }
}
#line 580 "type.pcc"
#line 580 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Unify two types.  Returns true iff unification succeeds.
//
/////////////////////////////////////////////////////////////////////////////
Bool unify (Ty t1, Ty t2)
{  
#line 589 "type.pcc"
#line 613 "type.pcc"
{
   Ty _V17 = deref(t1);
   Ty _V18 = deref(t2);
   if (
#line 591 "type.pcc"
   (_V17 == _V18)
#line 591 "type.pcc"
) {
      
      if (_V17) {
         if (_V18) {
            L45:; 
#line 591 "type.pcc"
           return true; 
#line 591 "type.pcc"
         } else {
            L46:; 
#line 590 "type.pcc"
           return false; 
#line 590 "type.pcc"
         }
      } else { goto L46; }
   } else {
      
      if (_V17) {
         switch (_V17->tag__) {
            case a_Ty::tag_VARty: {
               if (_V18) {
                  switch (_V18->tag__) {
                     case a_Ty::tag_VARty: {
                        L47:; 
#line 593 "type.pcc"
                      if (occurs(_V17,_V18)) {
                        error ("%Lunification fails occurs check with %T and %T\n",t1,t2);
                        return false;
                        } else { ((Ty_VARty *)_V18)->VARty = _V17; return true; } 
                        
#line 597 "type.pcc"
                        } break;
                     default: {
#line 599 "type.pcc"
                      if (occurs(_V18,_V17)) {
                        error ("%Lunification fails occurs check with %T and %T\n",t1,t2);
                        return false;
                        } else { ((Ty_VARty *)_V17)->VARty = _V18; return true; }
                        
#line 603 "type.pcc"
                        } break;
                  }
               } else { goto L46; }
               } break;
            default: {
               if (_V18) {
                  switch (_V18->tag__) {
                     case a_Ty::tag_VARty: { goto L47; } break;
                     default: {
                        L48:; 
#line 605 "type.pcc"
                      
#line 605 "type.pcc"
#line 611 "type.pcc"
                        {
                           Ty _V19 = deref_all(t1);
                           Ty _V20 = deref_all(t2);
                           if (
#line 606 "type.pcc"
                           (_V19 == _V20)
#line 606 "type.pcc"
) {
                              
#line 606 "type.pcc"
                             return true; 
#line 606 "type.pcc"
                           } else {
                              
                              if (_V19) {
                                 switch (_V19->tag__) {
                                    case a_Ty::tag_TYCONty: {
                                       if (_V20) {
                                          switch (_V20->tag__) {
                                             case a_Ty::tag_TYCONty: {
                                                if (boxed(((Ty_TYCONty *)_V19)->_1)) {
                                                   switch (((Ty_TYCONty *)_V19)->_1->tag__) {
                                                      case a_TyCon::tag_RECORDtycon: {
                                                         if (_V20) {
                                                            switch (_V20->tag__) {
                                                               case a_Ty::tag_TYCONty: {
                                                                  if (boxed(((Ty_TYCONty *)_V20)->_1)) {
                                                                     switch (((Ty_TYCONty *)_V20)->_1->tag__) {
                                                                        case a_TyCon::tag_RECORDtycon: {
                                                                           L49:; 
#line 608 "type.pcc"
                                                                          return unify_record(t1,((TyCon_RECORDtycon *)((Ty_TYCONty *)_V19)->_1)->_1,((Ty_TYCONty *)_V19)->_2,((TyCon_RECORDtycon *)((Ty_TYCONty *)_V19)->_1)->_2,t2,((TyCon_RECORDtycon *)((Ty_TYCONty *)_V20)->_1)->_1,((Ty_TYCONty *)_V20)->_2,((TyCon_RECORDtycon *)((Ty_TYCONty *)_V20)->_1)->_2); 
#line 608 "type.pcc"
                                                                           } break;
                                                                        default: {
                                                                           L50:; 
#line 609 "type.pcc"
                                                                          return unify(((Ty_TYCONty *)_V19)->_1,((Ty_TYCONty *)_V20)->_1) && unify(((Ty_TYCONty *)_V19)->_2,((Ty_TYCONty *)_V20)->_2); 
#line 609 "type.pcc"
                                                                           } break;
                                                                     }
                                                                  } else { goto L50; }
                                                                  } break;
                                                               default: { goto L50; } break;
                                                            }
                                                         } else { goto L50; }
                                                         } break;
                                                      default: { goto L50; } break;
                                                   }
                                                } else { goto L50; }
                                                } break;
                                             default: {
                                                L51:; 
                                                if (boxed(((Ty_TYCONty *)_V19)->_1)) {
                                                   switch (((Ty_TYCONty *)_V19)->_1->tag__) {
                                                      case a_TyCon::tag_RECORDtycon: {
                                                         L52:; 
                                                         if (_V20) {
                                                            switch (_V20->tag__) {
                                                               case a_Ty::tag_TYCONty: {
                                                                  L53:; 
                                                                  if (boxed(((Ty_TYCONty *)_V20)->_1)) {
                                                                     switch (((Ty_TYCONty *)_V20)->_1->tag__) {
                                                                        case a_TyCon::tag_RECORDtycon: { goto L49; } break;
                                                                        default: {
                                                                           L54:; 
#line 611 "type.pcc"
                                                                          return false; 
#line 611 "type.pcc"
                                                                           } break;
                                                                     }
                                                                  } else { goto L54; }
                                                                  } break;
                                                               default: { goto L54; } break;
                                                            }
                                                         } else { goto L54; }
                                                         } break;
                                                      default: { goto L54; } break;
                                                   }
                                                } else { goto L54; }
                                                } break;
                                          }
                                       } else { goto L51; }
                                       } break;
                                    case a_Ty::tag_NESTEDty: {
                                       if (_V20) {
                                          switch (_V20->tag__) {
                                             case a_Ty::tag_NESTEDty: {
#line 610 "type.pcc"
                                               return unify(((Ty_NESTEDty *)_V19)->_1,((Ty_NESTEDty *)_V20)->_1) && unify(((Ty_NESTEDty *)_V19)->_2,((Ty_NESTEDty *)_V20)->_2); 
#line 610 "type.pcc"
                                                } break;
                                             default: { goto L54; } break;
                                          }
                                       } else { goto L54; }
                                       } break;
                                    default: { goto L54; } break;
                                 }
                              } else { goto L54; }
                           }
                        }
#line 612 "type.pcc"
#line 612 "type.pcc"
                        
                        
#line 613 "type.pcc"
                        } break;
                  }
               } else { goto L46; }
               } break;
         }
      } else { goto L46; }
   }
}
#line 614 "type.pcc"
#line 614 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Unify two type lists.
//
/////////////////////////////////////////////////////////////////////////////
Bool unify(Tys xs, Tys ys)
{  Bool ok = true;
   
#line 624 "type.pcc"
#line 626 "type.pcc"
{
   for (;;) {
      if (xs) {
         if (ys) {
#line 626 "type.pcc"
          if (! unify(xs->_1, ys->_1)) ok = false; xs = xs->_2; ys = ys->_2; 
#line 626 "type.pcc"
         } else { goto L55; }
      } else { goto L55; }
   }
   L55:;
}
#line 627 "type.pcc"
#line 627 "type.pcc"

   return ok && xs == 
#line 628 "type.pcc"
#line 628 "type.pcc"
nil_1_
#line 628 "type.pcc"
#line 628 "type.pcc"
 && ys == 
#line 628 "type.pcc"
#line 628 "type.pcc"
nil_1_
#line 628 "type.pcc"
#line 628 "type.pcc"
;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Unify two types and print error message if fails.
//
/////////////////////////////////////////////////////////////////////////////
Bool unify(Pat p, Ty a, Ty b)
{  if (! unify(a,b)) 
   {  error ("%Ltype mismatch in pattern: %p\n"
             "%Lexpecting '%T' but found '%T'\n", p, a, b);
      return false;
   }
   return true;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Infer the type of literals
//
/////////////////////////////////////////////////////////////////////////////
Ty type_of (Literal l)
{  
#line 651 "type.pcc"
#line 658 "type.pcc"
{
   switch (l->tag__) {
      case a_Literal::tag_INTlit: {
#line 652 "type.pcc"
        return integer_ty; 
#line 652 "type.pcc"
         } break;
      case a_Literal::tag_BOOLlit: {
#line 654 "type.pcc"
        return bool_ty; 
#line 654 "type.pcc"
         } break;
      case a_Literal::tag_CHARlit: {
#line 653 "type.pcc"
        return character_ty; 
#line 653 "type.pcc"
         } break;
      case a_Literal::tag_REALlit: {
#line 655 "type.pcc"
        return real_ty; 
#line 655 "type.pcc"
         } break;
      case a_Literal::tag_QUARKlit: {
#line 656 "type.pcc"
        return quark_ty; 
#line 656 "type.pcc"
         } break;
      case a_Literal::tag_BIGINTlit: {
#line 657 "type.pcc"
        return bigint_ty; 
#line 657 "type.pcc"
         } break;
      default: {
#line 658 "type.pcc"
        return string_ty; 
#line 658 "type.pcc"
         } break;
   }
}
#line 659 "type.pcc"
#line 659 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Additional pattern variable type map. 
//
/////////////////////////////////////////////////////////////////////////////
HashTable * patvar_typemap = 0;

/////////////////////////////////////////////////////////////////////////////
//
//  Infer the type of a pattern.
//
/////////////////////////////////////////////////////////////////////////////
Ty type_of (Pat pat)
{  Ty t = NOty;
   
#line 676 "type.pcc"
#line 752 "type.pcc"
{
   if (pat) {
      switch (pat->tag__) {
         case a_Pat::tag_WILDpat: {
#line 678 "type.pcc"
           t = mkvar(); 
#line 678 "type.pcc"
            } break;
         case a_Pat::tag_INDpat: {
#line 679 "type.pcc"
           t = ((Pat_INDpat *)pat)->_3; 
#line 679 "type.pcc"
            } break;
         case a_Pat::tag_IDpat: {
#line 681 "type.pcc"
          t = ((Pat_IDpat *)pat)->_2; 
            // If we have a pattern variable type map
            // also use it.
            if (patvar_typemap)
            {  HashTable::Entry * e = patvar_typemap->lookup(((Pat_IDpat *)pat)->_1);
               if (e)
               {  Ty nonterm_ty = Ty(e->v);
                  if (!unify(nonterm_ty,((Pat_IDpat *)pat)->_2))
                  { error("%Lexpecting non-terminal %s to have type %T but found %T\n",
                          ((Pat_IDpat *)pat)->_1, nonterm_ty, ((Pat_IDpat *)pat)->_2);
                  }
               }
            }
            
#line 694 "type.pcc"
            } break;
         case a_Pat::tag_CONSpat: {
            if (((Pat_CONSpat *)pat)->CONSpat) {
#line 736 "type.pcc"
             t = inst(((Pat_CONSpat *)pat)->CONSpat->cons_ty); 
#line 736 "type.pcc"
            } else {
#line 737 "type.pcc"
             errors++; t = mkvar(); 
#line 737 "type.pcc"
            }
            } break;
         case a_Pat::tag_APPpat: {
#line 739 "type.pcc"
          Ty fun_ty = type_of(((Pat_APPpat *)pat)->_1);
            Ty range  = mkvar();
            unify(pat,fun_ty,mkfunty(type_of(((Pat_APPpat *)pat)->_2), range));
            t = deref(range);
            
#line 743 "type.pcc"
            } break;
         case a_Pat::tag_TYPEDpat: {
#line 734 "type.pcc"
          t = type_of(((Pat_TYPEDpat *)pat)->_1); unify(((Pat_TYPEDpat *)pat)->_1,((Pat_TYPEDpat *)pat)->_2,t); 
#line 734 "type.pcc"
            } break;
         case a_Pat::tag_ASpat: {
#line 695 "type.pcc"
           t = type_of(((Pat_ASpat *)pat)->_2); unify(pat,((Pat_ASpat *)pat)->_3,t); 
#line 695 "type.pcc"
            } break;
         case a_Pat::tag_LITERALpat: {
#line 697 "type.pcc"
           t = type_of(((Pat_LITERALpat *)pat)->LITERALpat); 
#line 697 "type.pcc"
            } break;
         case a_Pat::tag_CONTEXTpat: {
#line 702 "type.pcc"
           t = type_of(((Pat_CONTEXTpat *)pat)->_2); 
#line 702 "type.pcc"
            } break;
         case a_Pat::tag_LEXEMEpat: {
#line 698 "type.pcc"
           t = string_ty; 
#line 698 "type.pcc"
            } break;
         case a_Pat::tag_ARRAYpat: {
#line 711 "type.pcc"
          Ty ty = mkvar();
            for_each(Pat,p,((Pat_ARRAYpat *)pat)->_1) unify(pat,ty,type_of(p));
            t = mkptrty(QUALty(QUALconst,ty));
            
#line 714 "type.pcc"
            } break;
         case a_Pat::tag_TUPLEpat: {
#line 699 "type.pcc"
           t = mktuplety(type_of(((Pat_TUPLEpat *)pat)->TUPLEpat)); 
#line 699 "type.pcc"
            } break;
         case a_Pat::tag_EXTUPLEpat: {
#line 700 "type.pcc"
           t = TYCONty(EXTUPLEtycon,type_of(((Pat_EXTUPLEpat *)pat)->EXTUPLEpat)); 
#line 700 "type.pcc"
            } break;
         case a_Pat::tag_RECORDpat: {
#line 703 "type.pcc"
           t = mkrecordty(labels_of(((Pat_RECORDpat *)pat)->_1),type_of(((Pat_RECORDpat *)pat)->_1),((Pat_RECORDpat *)pat)->_2); 
#line 703 "type.pcc"
            } break;
         case a_Pat::tag_LISTpat: {
            if (((Pat_LISTpat *)pat)->head) {
#line 749 "type.pcc"
             t = type_of(APPpat(CONSpat(((Pat_LISTpat *)pat)->cons),
               TUPLEpat(
#line 750 "type.pcc"
#line 750 "type.pcc"
               list_1_(((Pat_LISTpat *)pat)->head->_1,list_1_(LISTpat(((Pat_LISTpat *)pat)->cons,((Pat_LISTpat *)pat)->nil,((Pat_LISTpat *)pat)->head->_2,((Pat_LISTpat *)pat)->tail)))
#line 750 "type.pcc"
#line 750 "type.pcc"
               )));
               
#line 751 "type.pcc"
            } else {
               if (((Pat_LISTpat *)pat)->tail) {
#line 747 "type.pcc"
                t = type_of(((Pat_LISTpat *)pat)->tail); 
#line 747 "type.pcc"
               } else {
#line 745 "type.pcc"
                t = type_of(CONSpat(((Pat_LISTpat *)pat)->nil)); 
#line 745 "type.pcc"
               }
            }
            } break;
         case a_Pat::tag_VECTORpat: {
#line 716 "type.pcc"
          Ty arg_ty = mkvar();
            for_each(Pat,p,((Pat_VECTORpat *)pat)->elements) unify(pat,arg_ty,type_of(p));
            Ty vec_ty   = type_of(CONSpat(((Pat_VECTORpat *)pat)->cons));
            Ty range_ty = mkvar();
            if (((Pat_VECTORpat *)pat)->len != NOpat) 
               unify(pat,integer_ty,type_of(((Pat_VECTORpat *)pat)->len));
            if (((Pat_VECTORpat *)pat)->array != NOpat)
               unify(pat,mkptrty(arg_ty),type_of(((Pat_VECTORpat *)pat)->array));
            unify(pat,vec_ty,mkfunty(arg_ty, range_ty));
            t = deref(range_ty);
            
#line 726 "type.pcc"
            } break;
         case a_Pat::tag_APPENDpat: {
#line 705 "type.pcc"
          Ty t1 = type_of(((Pat_APPENDpat *)pat)->_1);
            Ty t2 = type_of(((Pat_APPENDpat *)pat)->_2);
            t = ((Pat_APPENDpat *)pat)->_3 = t1;
            unify(pat,t1,t2);
            
#line 709 "type.pcc"
            } break;
         case a_Pat::tag_GUARDpat: {
#line 701 "type.pcc"
           t = type_of(((Pat_GUARDpat *)pat)->_1); 
#line 701 "type.pcc"
            } break;
         case a_Pat::tag_LOGICALpat: {
            switch (((Pat_LOGICALpat *)pat)->_1) {
               case NOTpat: {
#line 727 "type.pcc"
                 t = type_of(((Pat_LOGICALpat *)pat)->_2); 
#line 727 "type.pcc"
                  } break;
               default: {
#line 728 "type.pcc"
                 Ty ty1 = type_of(((Pat_LOGICALpat *)pat)->_2); 
                  Ty ty2 = type_of(((Pat_LOGICALpat *)pat)->_3);
                  unify(pat,ty1,ty2);
                  t = ty1;
                  
#line 732 "type.pcc"
                  } break;
            }
            } break;
         case a_Pat::tag_UNIFYpat: {
#line 696 "type.pcc"
           t = type_of(((Pat_UNIFYpat *)pat)->_1); 
#line 696 "type.pcc"
            } break;
         case a_Pat::tag_MARKEDpat: {
#line 735 "type.pcc"
           t = type_of(((Pat_MARKEDpat *)pat)->_2); 
#line 735 "type.pcc"
            } break;
         default: {
#line 752 "type.pcc"
           bug("type_of(Pat)"); 
#line 752 "type.pcc"
            } break;
      }
   } else {
#line 677 "type.pcc"
     t = NOty; 
#line 677 "type.pcc"
   }
}
#line 753 "type.pcc"
#line 753 "type.pcc"

   if (boxed(pat)) pat->ty = t;
   return t;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Infer the type of a pattern list.
//
/////////////////////////////////////////////////////////////////////////////
Tys type_of(Pats ps)
{  
#line 764 "type.pcc"
#line 766 "type.pcc"
{
   if (ps) {
#line 766 "type.pcc"
     return 
#line 766 "type.pcc"
#line 766 "type.pcc"
      list_1_(type_of(ps->_1),type_of(ps->_2))
#line 766 "type.pcc"
#line 766 "type.pcc"
      ; 
#line 766 "type.pcc"
   } else {
#line 765 "type.pcc"
     return 
#line 765 "type.pcc"
#line 765 "type.pcc"
      nil_1_
#line 765 "type.pcc"
#line 765 "type.pcc"
      ; 
#line 765 "type.pcc"
   }
}
#line 767 "type.pcc"
#line 767 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Infer the type of a labeled pattern list.
//
/////////////////////////////////////////////////////////////////////////////
Tys type_of(LabPats ps)
{  
#line 776 "type.pcc"
#line 778 "type.pcc"
{
   if (ps) {
#line 778 "type.pcc"
     return 
#line 778 "type.pcc"
#line 778 "type.pcc"
      list_1_(type_of(ps->_1.pat),type_of(ps->_2))
#line 778 "type.pcc"
#line 778 "type.pcc"
      ; 
#line 778 "type.pcc"
   } else {
#line 777 "type.pcc"
     return 
#line 777 "type.pcc"
#line 777 "type.pcc"
      nil_1_
#line 777 "type.pcc"
#line 777 "type.pcc"
      ; 
#line 777 "type.pcc"
   }
}
#line 779 "type.pcc"
#line 779 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Get the list of labels from a labeled pattern list.
//
/////////////////////////////////////////////////////////////////////////////
Ids labels_of(LabPats ps)
{  
#line 788 "type.pcc"
#line 790 "type.pcc"
{
   if (ps) {
#line 790 "type.pcc"
     return 
#line 790 "type.pcc"
#line 790 "type.pcc"
      list_1_(ps->_1.label,labels_of(ps->_2))
#line 790 "type.pcc"
#line 790 "type.pcc"
      ; 
#line 790 "type.pcc"
   } else {
#line 789 "type.pcc"
     return 
#line 789 "type.pcc"
#line 789 "type.pcc"
      nil_1_
#line 789 "type.pcc"
#line 789 "type.pcc"
      ; 
#line 789 "type.pcc"
   }
}
#line 791 "type.pcc"
#line 791 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Infer the type of a set of pattern rules.
//
/////////////////////////////////////////////////////////////////////////////
Ty type_match_rules(MatchRules rules)
{  Bool ok = true;
   MEM::use_global_pools();
   Ty ty = mkvar();
   for_each(MatchRule, r, rules) 
   {  
#line 804 "type.pcc"
#line 813 "type.pcc"
{
#line 806 "type.pcc"
 r->set_loc();
   Ty this_ty = type_of(r->_2); 
   if (this_ty == NOty) 
   {  error ("%!type error in pattern %p: %T\n", 
             r->loc(), r->_2, this_ty);
      ok = false;
   } else if (! unify(r->_2,ty,this_ty)) ok = false;
   
#line 813 "type.pcc"
}
#line 814 "type.pcc"
#line 814 "type.pcc"

   }
   MEM::use_local_pools();
   return ok ? ty : NOty;
}

/////////////////////////////////////////////////////////////////////////////
//
//  The type and constructor environments (both are flat for now.)
//
/////////////////////////////////////////////////////////////////////////////
HashTable ty_env(string_hash,string_equal,91);
HashTable cons_env(string_hash,string_equal,129);
HashTable token_env(string_hash,string_equal,129);

/////////////////////////////////////////////////////////////////////////////
//
//  Lookup the type from its name.
//
/////////////////////////////////////////////////////////////////////////////
Ty lookup_ty(Id id)
{  HashTable::Entry * i = ty_env.lookup(id);
   return i ? inst(value_of(Ty,ty_env,i)) : NOty;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Lookup the constructor from its name.
//
/////////////////////////////////////////////////////////////////////////////
Cons lookup_cons(Id id)
{  Cons c = find_cons(id);
   if (c == NOcons)
   {  error ("%Lconstructor '%s' is undefined\n", id);
   }
   return c;
}

Cons lookup_token (Id id)
{  Cons c = NOcons;
   HashTable::Entry * i = token_env.lookup(id);
   if (i) return (Cons)i->v; 
   c = find_cons(id);
   if (c == NOcons)
   {  if (id[0] == '"')
         error ("%Llexeme %s is undefined\n", id);
      else
         error ("%Lconstructor '%s' is undefined\n", id); 
   }
   return c;
}

Cons find_cons(Id id)
{  HashTable::Entry * i = cons_env.lookup(id);
   return i ? value_of(Cons,cons_env,i) : NOcons;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Add a new type to the environment.
//
/////////////////////////////////////////////////////////////////////////////
void add_type(Id id, TyVars tyvars, Ty ty)
{  HashTable::Entry * i = ty_env.lookup(id);
   if (i) {  
      error("%Ltype %s has already been defined as %T\n",
            id, value_of(Ty,ty_env,i));
   } else {
      
#line 882 "type.pcc"
#line 886 "type.pcc"
{
   Ty _V21 = deref_all(ty);
   if (_V21) {
      switch (_V21->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V21)->_1)) {
               switch (((Ty_TYCONty *)_V21)->_1->tag__) {
                  case a_TyCon::tag_IDtycon: {
                     if (
#line 883 "type.pcc"
                     (((TyCon_IDtycon *)((Ty_TYCONty *)_V21)->_1)->IDtycon == id)
#line 883 "type.pcc"
) {
                        
#line 884 "type.pcc"
                      error("%Lcyclic type definition in type %s%V = %T\n",id,tyvars,ty); 
                        
#line 885 "type.pcc"
                     } else {
                        
                        L56:; 
#line 886 "type.pcc"
                       ty_env.insert(id,mkpolyty(ty,tyvars)); 
#line 886 "type.pcc"
                     }
                     } break;
                  default: { goto L56; } break;
               }
            } else { goto L56; }
            } break;
         default: { goto L56; } break;
      }
   } else { goto L56; }
}
#line 887 "type.pcc"
#line 887 "type.pcc"

   }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Method to add a new datatype to the environment.
//
/////////////////////////////////////////////////////////////////////////////
void add_datatype( const Loc *     location,
                   Id              id, 
                   TyVars          tyvars, 
                   Inherits        inherit,
                   TyQual          qual,
                   Exp             view_match,
                   TermDefs        terms,
                   Decls           body
                 )
{  HashTable::Entry * i = ty_env.lookup(id);
   if (i) {
      Ty ty = (Ty)ty_env.value(i);
      
#line 908 "type.pcc"
#line 915 "type.pcc"
{
   Ty _V22 = deref_all(ty);
   if (_V22) {
      switch (_V22->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V22)->_1)) {
               switch (((Ty_TYCONty *)_V22)->_1->tag__) {
                  case a_TyCon::tag_DATATYPEtycon: {
#line 910 "type.pcc"
                   error("%Lredefinition of datatype %s\n"
                     "%!this is where datatype %s was previously defined\n",
                     id, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V22)->_1)->location, id);
                     
#line 913 "type.pcc"
                     } break;
                  default: {
                     L57:; 
#line 915 "type.pcc"
                   error("%Lredefinition of datatype %s\n", id); 
#line 915 "type.pcc"
                     } break;
               }
            } else { goto L57; }
            } break;
         default: { goto L57; } break;
      }
   } else { goto L57; }
}
#line 916 "type.pcc"
#line 916 "type.pcc"

   } else {
      TyCon  tycon      = 
#line 918 "type.pcc"
#line 918 "type.pcc"
DATATYPEtycon(id, 0, 0, 0, tyvars, NOty, inherit, qual, 0, body, view_match, location, 0)
#line 930 "type.pcc"
#line 930 "type.pcc"
;
      Ty     this_ty       = TYCONty(tycon, tyvars_to_type_list(0,tyvars));
      int    variants      = length(terms);
      int    arg_count     = 0;     
      int    unit_count    = 0;
      Cons * all_conses    = (Cons *)mem_pool[variants * sizeof(Cons)];
      int    units         = 0;
      int    args          = 0;
      int    optimizations = 0;
      int    arity         = length(tyvars);
      Id * bound_vars = (Id *)mem_pool[arity * sizeof(Id)];
      {  int i = 0;
         for_each (TyVar, tv, tyvars)
            bound_vars[i++] = tv; 
      }

      {  for_each(TermDef, t, terms)
            
#line 947 "type.pcc"
#line 949 "type.pcc"
{
   if (t->ty) {
#line 949 "type.pcc"
     args++; 
#line 949 "type.pcc"
   } else {
#line 948 "type.pcc"
     units++; 
#line 948 "type.pcc"
   }
}
#line 950 "type.pcc"
#line 950 "type.pcc"

      }

      Ty poly = mkpolyty(this_ty, tyvars);

      // compute optimizations.
      if (args == 1) optimizations |= OPTsubclassless | OPTtagless;
      if (args > 1 && args <= options.max_embedded_tags 
          && (qual & QUALvirtual) == 0
          && (options.tagged_pointer || (qual & QUALtaggedpointer)))
         optimizations |= OPTtaggedpointer | OPTtagless;
      else if (args <= 1) 
         optimizations |= OPTtagless;

      int actual_boxed = 0;
      for_each(TermDef, t, terms)
      {  
#line 966 "type.pcc"
#line 1034 "type.pcc"
{
   if (
#line 967 "type.pcc"
   (t->id == 0)
#line 967 "type.pcc"
) {
      
#line 968 "type.pcc"
    qual |= QUALextensible; 
#line 968 "type.pcc"
   } else {
      
#line 972 "type.pcc"
    int tag;
      Pat lexeme_pat = 
         (qual & QUALlexeme) && t->id[0] == '"' 
          ? LITERALpat(STRINGlit(t->id)) : t->pat;
      Cons last_cons = find_cons(t->id);
      if (last_cons != NOcons) {
         error ("%!redefinition of constructor '%s'\n"
                "%!this is where '%s' was last defined.\n",
                t->loc(), t->id, last_cons->location, t->id);
      }
      if (t->ty == NOty) tag = unit_count++; else tag = arg_count++;
      if (t->print_formats != 
#line 983 "type.pcc"
#line 983 "type.pcc"
      nil_1_
#line 983 "type.pcc"
#line 983 "type.pcc"
      ) qual |= QUALprintable;
      Ty cons_ty = t->ty == NOty 
          ? poly 
          : POLYty(mkfunty(t->ty, this_ty), arity, bound_vars);
      
      // Use unboxed optimization 
      // only if we are also using the tagged pointer rep.
      // Make sure (1) the type is embeddable into 1 word.
      //           (2) We are monomorphic.
      //           (3) We are not using any inheritance.
      int this_opt = OPTnone;
      if ((optimizations & OPTtaggedpointer) &&
           tyvars == 
#line 995 "type.pcc"
#line 995 "type.pcc"
      nil_1_
#line 995 "type.pcc"
#line 995 "type.pcc"
               && 
      t->inherits == 
#line 996 "type.pcc"
#line 996 "type.pcc"
      nil_1_
#line 996 "type.pcc"
#line 996 "type.pcc"
       &&
      t->opt == OPTunboxed              &&
      (qual & (QUALrewritable | QUALcollectable | 
               QUALrelation | QUALpersistent)) 
         == 0 &&
      is_embeddable_ty(t->ty))
      this_opt = OPTunboxed;
      
      Exp * view_selectors =
      (qual & QUALview) ? 
       (Exp*)mem_pool.c_alloc(arity_of(t->ty) * sizeof(Exp)) : 0;
      Cons cons = 
#line 1007 "type.pcc"
#line 1007 "type.pcc"
      ONEcons(t->id, this_ty, cons_ty, t->ty, tag, t->print_formats, t->loc(), t->inherits, t->decls, this_opt, t->qual, t->view_predicate, view_selectors, lexeme_pat, 0)
#line 1021 "type.pcc"
#line 1021 "type.pcc"
      ;
      all_conses[t->ty == NOty ? tag : tag + units] = cons;
      if (t->ty != NOty && (this_opt & OPTunboxed) == 0) 
         actual_boxed++;
      
      // update the constructor environment
      cons_env.insert(t->id, cons);
      
      // update the token environment
      
#line 1030 "type.pcc"
#line 1033 "type.pcc"
      {
         if (lexeme_pat) {
            switch (lexeme_pat->tag__) {
               case a_Pat::tag_LITERALpat: {
                  switch (((Pat_LITERALpat *)lexeme_pat)->LITERALpat->tag__) {
                     case a_Literal::tag_STRINGlit: {
#line 1031 "type.pcc"
                       token_env.insert(((Literal_STRINGlit *)((Pat_LITERALpat *)lexeme_pat)->LITERALpat)->STRINGlit, cons); 
#line 1031 "type.pcc"
                        } break;
                     default: {
                        L58:; } break;
                  }
                  } break;
               default: { goto L58; } break;
            }
         } else { goto L58; }
      }
#line 1033 "type.pcc"
#line 1033 "type.pcc"
      
      
#line 1034 "type.pcc"
   }
}
#line 1035 "type.pcc"
#line 1035 "type.pcc"

      } 

      if (actual_boxed <= 1) optimizations |= OPTsubclassless | OPTtagless;

      if (tyvars && unit_count > 1)
         error("%Lmultiple unit constructors in polymorphic type %s%V"
	       " is not supported\n",
               id, tyvars);

      
#line 1045 "type.pcc"
#line 1050 "type.pcc"
{
   if (boxed(tycon)) {
      switch (tycon->tag__) {
         case a_TyCon::tag_DATATYPEtycon: {
#line 1047 "type.pcc"
           ((TyCon_DATATYPEtycon *)tycon)->unit = unit_count; ((TyCon_DATATYPEtycon *)tycon)->arg = arg_count; ((TyCon_DATATYPEtycon *)tycon)->terms = all_conses; 
            ((TyCon_DATATYPEtycon *)tycon)->polyty = poly; ((TyCon_DATATYPEtycon *)tycon)->opt = optimizations; ((TyCon_DATATYPEtycon *)tycon)->qualifiers = qual;
            
#line 1049 "type.pcc"
            } break;
         default: {
            L59:; } break;
      }
   } else { goto L59; }
}
#line 1051 "type.pcc"
#line 1051 "type.pcc"


      ty_env.insert(id, poly);
      if (qual & QUALlexeme) update_lexeme_class(id, terms);

      // Create new type hierarchy
      new DatatypeHierarchy(id,tyvars,inherit,qual,terms,body);
   }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Method to refine the implementation of a datatype.
//
/////////////////////////////////////////////////////////////////////////////
void update_datatype (Id id, TyVars tyvars, Inherits superclasses,
                      TyQual qual, Decls decls)
{
   
#line 1069 "type.pcc"
#line 1080 "type.pcc"
{
   Ty _V23 = lookup_ty(id);
   if (_V23) {
      switch (_V23->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V23)->_1)) {
               switch (((Ty_TYCONty *)_V23)->_1->tag__) {
                  case a_TyCon::tag_DATATYPEtycon: {
                     if (
#line 1070 "type.pcc"
                     (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V23)->_1)->hierarchy != 0)
#line 1070 "type.pcc"
) {
                        
#line 1071 "type.pcc"
                      if (superclasses)
                        	   ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V23)->_1)->hierarchy->inherited_classes = 
                        	     append(((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V23)->_1)->hierarchy->inherited_classes,superclasses);
                                 ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V23)->_1)->hierarchy->qualifiers |= qual;
                                 ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V23)->_1)->qualifiers |= qual;
                        	 if (decls)
                                   ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V23)->_1)->hierarchy->class_body = append(((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V23)->_1)->hierarchy->class_body,decls);
                              
#line 1078 "type.pcc"
                     } else {
                        
                        L60:; 
#line 1080 "type.pcc"
                       error ("%Ltype %s = %T is not a datatype\n",id, _V23); 
#line 1080 "type.pcc"
                     }
                     } break;
                  default: { goto L60; } break;
               }
            } else { goto L60; }
            } break;
         default: { goto L60; } break;
      }
   } else {
#line 1079 "type.pcc"
     /* skip */ 
#line 1079 "type.pcc"
   }
}
#line 1081 "type.pcc"
#line 1081 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Method to refine the implementation of a datatype constructor.
//
/////////////////////////////////////////////////////////////////////////////
void update_constructor 
   (Id id, Tys ty_args, Inherits inh, PrintFormats pf, Decls decls)
{  
#line 1091 "type.pcc"
#line 1108 "type.pcc"
{
   Cons _V24 = lookup_cons(id);
   if (_V24) {
      if (_V24->alg_ty) {
         switch (_V24->alg_ty->tag__) {
            case a_Ty::tag_TYCONty: {
               if (boxed(((Ty_TYCONty *)_V24->alg_ty)->_1)) {
                  switch (((Ty_TYCONty *)_V24->alg_ty)->_1->tag__) {
                     case a_TyCon::tag_DATATYPEtycon: {
#line 1095 "type.pcc"
                      if (pf) {
                        if (_V24->print_formats) 
                           error("%Lconstructor %s already has print formats\n",id); 
                        else
                           _V24->print_formats = pf;
                        ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V24->alg_ty)->_1)->qualifiers |= QUALprintable;
                        }
                        	 if (decls)
                        _V24->class_def->class_body = append(_V24->class_def->class_body,decls);
                        	 if (inh)
                        	   _V24->class_def->inherited_classes = append(_V24->class_def->inherited_classes,
                        	   				       inh);
                        
#line 1107 "type.pcc"
                        } break;
                     default: {
                        L61:; 
#line 1108 "type.pcc"
                       /* skip */ 
#line 1108 "type.pcc"
                        } break;
                  }
               } else { goto L61; }
               } break;
            default: { goto L61; } break;
         }
      } else { goto L61; }
   } else { goto L61; }
}
#line 1109 "type.pcc"
#line 1109 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Hashing function on types
//
/////////////////////////////////////////////////////////////////////////////
unsigned int ty_hash(HashTable::Key k)
{  Ty ty = (Ty)k;
   
#line 1119 "type.pcc"
#line 1144 "type.pcc"
{
   Ty _V25 = deref_all(ty);
   if (_V25) {
      switch (_V25->tag__) {
         case a_Ty::tag_VARty: {
#line 1121 "type.pcc"
           return (unsigned int)_V25; 
#line 1121 "type.pcc"
            } break;
         case a_Ty::tag_TYCONty: {
#line 1123 "type.pcc"
          unsigned int h;
            
#line 1124 "type.pcc"
#line 1139 "type.pcc"
            {
               TyCon _V26 = ((Ty_TYCONty *)_V25)->_1;
               if (boxed(_V26)) {
                  switch (_V26->tag__) {
                     case a_TyCon::tag_IDtycon: {
#line 1132 "type.pcc"
                       h = string_hash(((TyCon_IDtycon *)_V26)->IDtycon) + 89; 
#line 1132 "type.pcc"
                        } break;
                     case a_TyCon::tag_RECORDtycon: {
#line 1128 "type.pcc"
                       h = 129; 
#line 1128 "type.pcc"
                        } break;
                     case a_TyCon::tag_ARRAYtycon: {
#line 1131 "type.pcc"
                       h = 569; 
#line 1131 "type.pcc"
                        } break;
                     case a_TyCon::tag_BITFIELDtycon: {
#line 1134 "type.pcc"
                       h = 733 + ((TyCon_BITFIELDtycon *)_V26)->width; 
#line 1134 "type.pcc"
                        } break;
                     case a_TyCon::tag_DATATYPEtycon: {
#line 1133 "type.pcc"
                       h = string_hash(((TyCon_DATATYPEtycon *)_V26)->id) + 431; 
#line 1133 "type.pcc"
                        } break;
                     case a_TyCon::tag_COLtycon: {
#line 1136 "type.pcc"
                       h = string_hash(((TyCon_COLtycon *)_V26)->COLtycon->name) + 1345; 
#line 1136 "type.pcc"
                        } break;
                     case a_TyCon::tag_GRAPHtycon: {
#line 1137 "type.pcc"
                       h = (int)((TyCon_GRAPHtycon *)_V26)->GRAPHtycon; 
#line 1137 "type.pcc"
                        } break;
                     case a_TyCon::tag_NODEtycon: {
#line 1138 "type.pcc"
                       h = (int)((TyCon_NODEtycon *)_V26)->NODEtycon; 
#line 1138 "type.pcc"
                        } break;
                     default: {
#line 1139 "type.pcc"
                       h = (int)((TyCon_EDGEtycon *)_V26)->EDGEtycon; 
#line 1139 "type.pcc"
                        } break;
                  }
               } else {
                  switch ((int)_V26) {
                     case ((int)POINTERtycon): {
#line 1125 "type.pcc"
                       h = 37; 
#line 1125 "type.pcc"
                        } break;
                     case ((int)REFtycon): {
#line 1126 "type.pcc"
                       h = 47; 
#line 1126 "type.pcc"
                        } break;
                     case ((int)TUPLEtycon): {
#line 1129 "type.pcc"
                       h = 173; 
#line 1129 "type.pcc"
                        } break;
                     case ((int)EXTUPLEtycon): {
#line 1130 "type.pcc"
                       h = 467; 
#line 1130 "type.pcc"
                        } break;
                     case ((int)FUNtycon): {
#line 1127 "type.pcc"
                       h = 79; 
#line 1127 "type.pcc"
                        } break;
                     default: {
#line 1135 "type.pcc"
                       h = 1235; 
#line 1135 "type.pcc"
                        } break;
                  }
               }
            }
#line 1140 "type.pcc"
#line 1140 "type.pcc"
            
            return h + tys_hash(((Ty_TYCONty *)_V25)->_2);
            
#line 1142 "type.pcc"
            } break;
         case a_Ty::tag_NESTEDty: {
#line 1143 "type.pcc"
           return ty_hash(((Ty_NESTEDty *)_V25)->_1) + ty_hash(((Ty_NESTEDty *)_V25)->_2); 
#line 1143 "type.pcc"
            } break;
         default: {
#line 1144 "type.pcc"
           return 0; 
#line 1144 "type.pcc"
            } break;
      }
   } else {
#line 1120 "type.pcc"
     return 0; 
#line 1120 "type.pcc"
   }
}
#line 1145 "type.pcc"
#line 1145 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Hashing function on type list
//
/////////////////////////////////////////////////////////////////////////////
unsigned int tys_hash(HashTable::Key k)
{  Tys tys = (Tys)k;
   unsigned int h = 0;
   for_each (Ty, t, tys) h += ty_hash(t);
   return h;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Equality function on types
//
/////////////////////////////////////////////////////////////////////////////
Bool ty_equal(HashTable::Key a, HashTable::Key b)
{  Ty u = (Ty)a, v = (Ty)b;
   
#line 1167 "type.pcc"
#line 1194 "type.pcc"
{
   Ty _V27 = deref_all(u);
   Ty _V28 = deref_all(v);
   if (
#line 1168 "type.pcc"
   (_V27 == _V28)
#line 1168 "type.pcc"
) {
      
#line 1168 "type.pcc"
     return true; 
#line 1168 "type.pcc"
   } else {
      
      if (_V27) {
         switch (_V27->tag__) {
            case a_Ty::tag_VARty: {
               if (_V28) {
                  switch (_V28->tag__) {
                     case a_Ty::tag_VARty: {
#line 1169 "type.pcc"
                       return _V27 == _V28; 
#line 1169 "type.pcc"
                        } break;
                     default: {
                        L62:; 
#line 1194 "type.pcc"
                       return false; 
#line 1194 "type.pcc"
                        } break;
                  }
               } else { goto L62; }
               } break;
            case a_Ty::tag_TYCONty: {
               if (_V28) {
                  switch (_V28->tag__) {
                     case a_Ty::tag_TYCONty: {
                        if (boxed(((Ty_TYCONty *)_V27)->_1)) {
                           switch (((Ty_TYCONty *)_V27)->_1->tag__) {
                              case a_TyCon::tag_RECORDtycon: {
                                 if (_V28) {
                                    switch (_V28->tag__) {
                                       case a_Ty::tag_TYCONty: {
                                          if (boxed(((Ty_TYCONty *)_V28)->_1)) {
                                             switch (((Ty_TYCONty *)_V28)->_1->tag__) {
                                                case a_TyCon::tag_RECORDtycon: {
                                                   L63:; 
#line 1174 "type.pcc"
                                                 Ids i, j; Tys t, u;
                                                   if (length(((Ty_TYCONty *)_V27)->_2) != length(((Ty_TYCONty *)_V28)->_2)) return false;
                                                   for (i = ((TyCon_RECORDtycon *)((Ty_TYCONty *)_V27)->_1)->_1, t = ((Ty_TYCONty *)_V27)->_2; i; i = i->_2, t = t->_2) 
                                                   {  Bool found = false;
                                                      for (j = ((TyCon_RECORDtycon *)((Ty_TYCONty *)_V28)->_1)->_1, u = ((Ty_TYCONty *)_V28)->_2; j; j = j->_2, u = u->_2) 
                                                      {  if (i->_1 == j->_1) {
                                                            if (! ty_equal(t->_1, u->_2)) return false;
                                                            found = true; break;
                                                         }
                                                      }
                                                      if (! found) return false;
                                                   }
                                                   return true;
                                                   
#line 1187 "type.pcc"
                                                   } break;
                                                default: {
                                                   L64:; 
#line 1189 "type.pcc"
                                                 if (! unify(((Ty_TYCONty *)_V27)->_1,((Ty_TYCONty *)_V28)->_1)) return false;
                                                   return tys_equal(((Ty_TYCONty *)_V27)->_2,((Ty_TYCONty *)_V28)->_2);
                                                   
#line 1191 "type.pcc"
                                                   } break;
                                             }
                                          } else { goto L64; }
                                          } break;
                                       default: { goto L64; } break;
                                    }
                                 } else { goto L64; }
                                 } break;
                              case a_TyCon::tag_GRAPHtycon: {
                                 if (_V28) {
                                    switch (_V28->tag__) {
                                       case a_Ty::tag_TYCONty: {
                                          if (boxed(((Ty_TYCONty *)_V28)->_1)) {
                                             switch (((Ty_TYCONty *)_V28)->_1->tag__) {
                                                case a_TyCon::tag_GRAPHtycon: {
                                                   L65:; 
#line 1170 "type.pcc"
                                                  return ((TyCon_GRAPHtycon *)((Ty_TYCONty *)_V27)->_1)->GRAPHtycon == ((TyCon_GRAPHtycon *)((Ty_TYCONty *)_V28)->_1)->GRAPHtycon; 
#line 1170 "type.pcc"
                                                   } break;
                                                default: { goto L64; } break;
                                             }
                                          } else { goto L64; }
                                          } break;
                                       default: { goto L64; } break;
                                    }
                                 } else { goto L64; }
                                 } break;
                              case a_TyCon::tag_NODEtycon: {
                                 if (_V28) {
                                    switch (_V28->tag__) {
                                       case a_Ty::tag_TYCONty: {
                                          if (boxed(((Ty_TYCONty *)_V28)->_1)) {
                                             switch (((Ty_TYCONty *)_V28)->_1->tag__) {
                                                case a_TyCon::tag_NODEtycon: {
                                                   L66:; 
#line 1171 "type.pcc"
                                                  return ((TyCon_NODEtycon *)((Ty_TYCONty *)_V27)->_1)->NODEtycon == ((TyCon_NODEtycon *)((Ty_TYCONty *)_V28)->_1)->NODEtycon; 
#line 1171 "type.pcc"
                                                   } break;
                                                default: { goto L64; } break;
                                             }
                                          } else { goto L64; }
                                          } break;
                                       default: { goto L64; } break;
                                    }
                                 } else { goto L64; }
                                 } break;
                              case a_TyCon::tag_EDGEtycon: {
                                 if (_V28) {
                                    switch (_V28->tag__) {
                                       case a_Ty::tag_TYCONty: {
                                          if (boxed(((Ty_TYCONty *)_V28)->_1)) {
                                             switch (((Ty_TYCONty *)_V28)->_1->tag__) {
                                                case a_TyCon::tag_EDGEtycon: {
                                                   L67:; 
#line 1172 "type.pcc"
                                                  return ((TyCon_EDGEtycon *)((Ty_TYCONty *)_V27)->_1)->EDGEtycon == ((TyCon_EDGEtycon *)((Ty_TYCONty *)_V28)->_1)->EDGEtycon; 
#line 1172 "type.pcc"
                                                   } break;
                                                default: { goto L64; } break;
                                             }
                                          } else { goto L64; }
                                          } break;
                                       default: { goto L64; } break;
                                    }
                                 } else { goto L64; }
                                 } break;
                              default: { goto L64; } break;
                           }
                        } else { goto L64; }
                        } break;
                     default: {
                        L68:; 
                        if (boxed(((Ty_TYCONty *)_V27)->_1)) {
                           switch (((Ty_TYCONty *)_V27)->_1->tag__) {
                              case a_TyCon::tag_RECORDtycon: {
                                 L69:; 
                                 if (_V28) {
                                    switch (_V28->tag__) {
                                       case a_Ty::tag_TYCONty: {
                                          L70:; 
                                          if (boxed(((Ty_TYCONty *)_V28)->_1)) {
                                             switch (((Ty_TYCONty *)_V28)->_1->tag__) {
                                                case a_TyCon::tag_RECORDtycon: { goto L63; } break;
                                                default: { goto L62; } break;
                                             }
                                          } else { goto L62; }
                                          } break;
                                       default: { goto L62; } break;
                                    }
                                 } else { goto L62; }
                                 } break;
                              case a_TyCon::tag_GRAPHtycon: {
                                 L71:; 
                                 if (_V28) {
                                    switch (_V28->tag__) {
                                       case a_Ty::tag_TYCONty: {
                                          L72:; 
                                          if (boxed(((Ty_TYCONty *)_V28)->_1)) {
                                             switch (((Ty_TYCONty *)_V28)->_1->tag__) {
                                                case a_TyCon::tag_GRAPHtycon: { goto L65; } break;
                                                default: { goto L62; } break;
                                             }
                                          } else { goto L62; }
                                          } break;
                                       default: { goto L62; } break;
                                    }
                                 } else { goto L62; }
                                 } break;
                              case a_TyCon::tag_NODEtycon: {
                                 L73:; 
                                 if (_V28) {
                                    switch (_V28->tag__) {
                                       case a_Ty::tag_TYCONty: {
                                          L74:; 
                                          if (boxed(((Ty_TYCONty *)_V28)->_1)) {
                                             switch (((Ty_TYCONty *)_V28)->_1->tag__) {
                                                case a_TyCon::tag_NODEtycon: { goto L66; } break;
                                                default: { goto L62; } break;
                                             }
                                          } else { goto L62; }
                                          } break;
                                       default: { goto L62; } break;
                                    }
                                 } else { goto L62; }
                                 } break;
                              case a_TyCon::tag_EDGEtycon: {
                                 L75:; 
                                 if (_V28) {
                                    switch (_V28->tag__) {
                                       case a_Ty::tag_TYCONty: {
                                          L76:; 
                                          if (boxed(((Ty_TYCONty *)_V28)->_1)) {
                                             switch (((Ty_TYCONty *)_V28)->_1->tag__) {
                                                case a_TyCon::tag_EDGEtycon: { goto L67; } break;
                                                default: { goto L62; } break;
                                             }
                                          } else { goto L62; }
                                          } break;
                                       default: { goto L62; } break;
                                    }
                                 } else { goto L62; }
                                 } break;
                              default: { goto L62; } break;
                           }
                        } else { goto L62; }
                        } break;
                  }
               } else { goto L68; }
               } break;
            case a_Ty::tag_NESTEDty: {
               if (_V28) {
                  switch (_V28->tag__) {
                     case a_Ty::tag_NESTEDty: {
#line 1193 "type.pcc"
                      return ty_equal(((Ty_NESTEDty *)_V27)->_1,((Ty_NESTEDty *)_V28)->_1) && ty_equal(((Ty_NESTEDty *)_V27)->_2,((Ty_NESTEDty *)_V28)->_2); 
#line 1193 "type.pcc"
                        } break;
                     default: { goto L62; } break;
                  }
               } else { goto L62; }
               } break;
            default: { goto L62; } break;
         }
      } else { goto L62; }
   }
}
#line 1195 "type.pcc"
#line 1195 "type.pcc"

}

/////////////////////////////////////////////////////////////////////////////
//
//  Equality function on type lists
//
/////////////////////////////////////////////////////////////////////////////
Bool tys_equal(HashTable::Key a, HashTable::Key b)
{  Tys u = (Tys)a, v = (Tys)b;
   
#line 1205 "type.pcc"
#line 1207 "type.pcc"
{
   for (;;) {
      if (u) {
         if (v) {
#line 1207 "type.pcc"
          if (!ty_equal(u->_1,v->_1)) return false; u = u->_2; v = v->_2; 
#line 1207 "type.pcc"
         } else { goto L77; }
      } else { goto L77; }
   }
   L77:;
}
#line 1208 "type.pcc"
#line 1208 "type.pcc"

   return u == 
#line 1209 "type.pcc"
#line 1209 "type.pcc"
nil_1_
#line 1209 "type.pcc"
#line 1209 "type.pcc"
 && v == 
#line 1209 "type.pcc"
#line 1209 "type.pcc"
nil_1_
#line 1209 "type.pcc"
#line 1209 "type.pcc"
;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Equality on qualified identifiers.
//
/////////////////////////////////////////////////////////////////////////////
#line 1217 "type.pcc"
#line 1221 "type.pcc"
Bool qualid_equal (QualId x_1, QualId x_2);
Bool qualid_equal (QualId x_1, QualId x_2)
{
   if (untagp(x_1)) {
      
      if (untagp(x_2)) {
         
#line 1217 "type.pcc"
        return ((QualId_SIMPLEid *)derefp(x_1))->SIMPLEid == ((QualId_SIMPLEid *)derefp(x_2))->SIMPLEid; 
#line 1217 "type.pcc"
      } else {
         
         L78:; 
#line 1220 "type.pcc"
        return false; 
#line 1220 "type.pcc"
      }
   } else {
      
      if (untagp(x_2)) {
          goto L78; } else {
         
#line 1219 "type.pcc"
        return ty_equal(((QualId_NESTEDid *)x_1)->_1,((QualId_NESTEDid *)x_2)->_1) && qualid_equal(((QualId_NESTEDid *)x_1)->_2,((QualId_NESTEDid *)x_2)->_2); 
#line 1219 "type.pcc"
      }
   }
}
#line 1221 "type.pcc"
#line 1221 "type.pcc"

#line 1222 "type.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 2865
Number of ifs generated      = 162
Number of switches generated = 116
Number of labels             = 71
Number of gotos              = 198
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
