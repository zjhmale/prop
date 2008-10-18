///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.6),
//  last updated on Nov 2, 1999.
//  The original source file is "funmap.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_QUARK_USED
#include <propdefs.h>
///////////////////////////////////////////////////////////////////////////////
//  Quark literals
///////////////////////////////////////////////////////////////////////////////
static const Quark _f_u_n_m_a_pco_c_c_Q3("##");
static const Quark _f_u_n_m_a_pco_c_c_Q4("$$");
static const Quark _f_u_n_m_a_pco_c_c_Q1("#");
static const Quark _f_u_n_m_a_pco_c_c_Q2("$");
#line 1 "funmap.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements the FunctorMap data structure 
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream.h>
#include <strstream.h>
#include <AD/automata/treegram.h>
#include <AD/automata/treegen.h>
#include <AD/rewrite/burs_gen.h>
#include <AD/strings/quark.h>
#include "funmap.h"
#include "ir.h"
#include "ast.h"
#include "matchcom.h"
#include "type.h"
#include "hashtab.h"
#include "datagen.h"
#include "config.h"
#include "rwgen.h"
#include "options.h"
#include "list.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Import some type definitions from the tree grammar and hash table
//  classes.
//
///////////////////////////////////////////////////////////////////////////////
typedef TreeGrammar::TreeProduction TreeProduction;
typedef TreeGrammar::Cost           TreeCost;
typedef HashTable::Key              Key;
typedef HashTable::Value            Value;

///////////////////////////////////////////////////////////////////////////////
//
//  Instantiate the vector id type
//
///////////////////////////////////////////////////////////////////////////////
#line 40 "funmap.pcc"
#line 40 "funmap.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype VectorId
//
///////////////////////////////////////////////////////////////////////////////
#line 40 "funmap.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype VectorId
//
///////////////////////////////////////////////////////////////////////////////
#line 40 "funmap.pcc"
a_VectorId::a_VectorId (Cons x_cons, Ty x_ty, int x_arity)
 : cons(x_cons), ty(x_ty), arity(x_arity)
{
}
a_VectorId * vector_id (Cons x_cons, Ty x_ty, int x_arity)
{
   return new a_VectorId (x_cons, x_ty, x_arity);
}


#line 40 "funmap.pcc"
#line 40 "funmap.pcc"


///////////////////////////////////////////////////////////////////////////////
//
//  Hashing and equality on vector id's
//
///////////////////////////////////////////////////////////////////////////////
unsigned int vector_id_hash(HashTable::Key k)
{  VectorId id = (VectorId)k;
   return (unsigned int)id->cons + ty_hash(id->ty) + id->arity;
}
Bool vector_id_equal(HashTable::Key a, HashTable::Key b)
{  VectorId x = (VectorId)a;
   VectorId y = (VectorId)b;
   return x->cons == y->cons && x->arity == y->arity && ty_equal(x->ty,y->ty); 
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to decorate cost expression and attribute bindings for
//  a pattern.
//
///////////////////////////////////////////////////////////////////////////////
int decor_rewrite (Pat pat, int rule, int kid, PatternVarEnv& E)
{  
#line 64 "funmap.pcc"
#line 91 "funmap.pcc"
{
   for (;;) {
      if (pat) {
         switch (pat->tag__) {
            case a_Pat::tag_APPpat: {
#line 69 "funmap.pcc"
              pat = ((Pat_APPpat *)pat)->_2; 
#line 69 "funmap.pcc"
               } break;
            case a_Pat::tag_TYPEDpat: {
#line 67 "funmap.pcc"
              pat = ((Pat_TYPEDpat *)pat)->_1; 
#line 67 "funmap.pcc"
               } break;
            case a_Pat::tag_ASpat: {
#line 83 "funmap.pcc"
             Id attrib_name = 
#line 83 "funmap.pcc"
#line 83 "funmap.pcc"
               _f_u_n_m_a_pco_c_c_Q1
#line 83 "funmap.pcc"
#line 83 "funmap.pcc"
              + ((Pat_ASpat *)pat)->_1;
               Id cost_name   = 
#line 84 "funmap.pcc"
#line 84 "funmap.pcc"
               _f_u_n_m_a_pco_c_c_Q2
#line 84 "funmap.pcc"
#line 84 "funmap.pcc"
              + ((Pat_ASpat *)pat)->_1;
               Ty ty = mkvar();
               E.add (attrib_name, SYNexp(kid, rule, mkvar(),true), ty, ISpositive);
               E.add (cost_name, COSTexp(kid),  ty, ISpositive);
               kid = kid+1;
               pat = ((Pat_ASpat *)pat)->_2; 
               
#line 90 "funmap.pcc"
               } break;
            case a_Pat::tag_CONTEXTpat: {
#line 70 "funmap.pcc"
              pat = ((Pat_CONTEXTpat *)pat)->_2; 
#line 70 "funmap.pcc"
               } break;
            case a_Pat::tag_TUPLEpat: {
#line 72 "funmap.pcc"
             return decor_rewrite(((Pat_TUPLEpat *)pat)->TUPLEpat, rule, kid, E); 
#line 72 "funmap.pcc"
               } break;
            case a_Pat::tag_LISTpat: {
#line 74 "funmap.pcc"
             kid = decor_rewrite(((Pat_LISTpat *)pat)->head, rule, kid, E); pat = ((Pat_LISTpat *)pat)->tail; 
#line 74 "funmap.pcc"
               } break;
            case a_Pat::tag_VECTORpat: {
#line 76 "funmap.pcc"
             kid = decor_rewrite(((Pat_VECTORpat *)pat)->elements, rule, 
               decor_rewrite(((Pat_VECTORpat *)pat)->array, rule, kid, E), E); 
               if (((Pat_VECTORpat *)pat)->head_flex || ((Pat_VECTORpat *)pat)->tail_flex)
               error("%Lflexible vector pattern currently not supported in rewriting: %p\n", pat); 
               pat = ((Pat_VECTORpat *)pat)->len;
               
#line 81 "funmap.pcc"
               } break;
            case a_Pat::tag_GUARDpat: {
#line 68 "funmap.pcc"
              pat = ((Pat_GUARDpat *)pat)->_1; 
#line 68 "funmap.pcc"
               } break;
            case a_Pat::tag_MARKEDpat: {
#line 66 "funmap.pcc"
              pat = ((Pat_MARKEDpat *)pat)->_2; 
#line 66 "funmap.pcc"
               } break;
            case a_Pat::tag_CONSpat:
            case a_Pat::tag_LITERALpat: {
               L2:; 
#line 65 "funmap.pcc"
              return kid; 
#line 65 "funmap.pcc"
               } break;
            default: {
#line 91 "funmap.pcc"
              return kid; 
#line 91 "funmap.pcc"
               } break;
         }
      } else { goto L2; }
   }
}
#line 92 "funmap.pcc"
#line 92 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Decorate a pattern list.
//
///////////////////////////////////////////////////////////////////////////////
int decor_rewrite (Pats pats, int rule, int kid, PatternVarEnv& E)
{  for_each (Pat, p, pats) kid = decor_rewrite(p, rule, kid, E);
   return kid;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Decorate rewriting patterns.
//
///////////////////////////////////////////////////////////////////////////////
int decor_rewrite (Pat pat, int rule, PatternVarEnv& E)
{  Ty ty = mkvar();
   E.add (
#line 112 "funmap.pcc"
#line 112 "funmap.pcc"
_f_u_n_m_a_pco_c_c_Q3
#line 112 "funmap.pcc"
#line 112 "funmap.pcc"
, THISSYNexp(rule,mkvar(),true), ty, ISpositive);
   E.add (
#line 113 "funmap.pcc"
#line 113 "funmap.pcc"
_f_u_n_m_a_pco_c_c_Q4
#line 113 "funmap.pcc"
#line 113 "funmap.pcc"
, THISCOSTexp(), ty, ISpositive);
   return decor_rewrite (pat, rule, 0, E);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Constructor of the functor mapping table.
//
///////////////////////////////////////////////////////////////////////////////
FunctorMap::FunctorMap(Id name, MatchRules rules) 
  : literal_map(literal_hash,literal_equal,129), 
    var_map    (string_hash,string_equal),
    type_map   (ty_hash,ty_equal),
    vector_map (vector_id_hash,vector_id_equal),
    rule_map   (ty_hash,ty_equal),
    topdown_rule_map (ty_hash,ty_equal),
    before_rule_map (ty_hash,ty_equal),
    preorder_rule_map (ty_hash,ty_equal),
    postorder_rule_map (ty_hash,ty_equal),
    protocols  (ty_hash,ty_equal),
    nonterm_map(string_hash,string_equal),
    nonterm_rules(string_hash,string_equal),
    nonterm_rules_bits(string_hash,string_equal),
    chain_rules(string_hash,string_equal),
    bottomup_rules(
#line 137 "funmap.pcc"
#line 137 "funmap.pcc"
nil_1_
#line 137 "funmap.pcc"
#line 137 "funmap.pcc"
)
{  
    ///////////////////////////////////////////////////////////////////////////
    //
    //  Initialize the internals.
    //
    ///////////////////////////////////////////////////////////////////////////
    class_name      = name; 
    N               = length(rules);
    functors        = 0;
    variables       = 0;
    tree_gen        = 0;
    topdown_gen     = 0;
    use_compression = true;
    has_guard       = false;
    has_replacement = false;
    has_cost        = false;
    has_cost_exp    = false;
    has_syn_attrib  = false;
    is_applicative  = false;
    gen_reducers    = false;
    dynamic_search  = false;
    max_arity       = 1;
    functor_names   = 0;
    variable_names  = 0;
    is_ok           = true;

    rule_maps[MatchRuleInfo::BOTTOMUP]  = &rule_map;
    rule_maps[MatchRuleInfo::TOPDOWN]   = &topdown_rule_map;
    rule_maps[MatchRuleInfo::BEFORE]    = &before_rule_map;
    rule_maps[MatchRuleInfo::PREORDER]  = &preorder_rule_map;
    rule_maps[MatchRuleInfo::POSTORDER] = &postorder_rule_map;

    TyQual qual = RewritingCompiler::lookup_qual(class_name); 
    if (qual & QUALtreeparser)  gen_reducers = true;
    if (qual & QUALapplicative) is_applicative = true;

    int last_errors = errors;
    enter_protocols();             // enter the protocols
          // partition rule by type
    bottomup_rules = partition_rules(rules); 
    check_for_missing_protocols();
    if (errors != last_errors) { is_ok = false; return; }
    build_tree_grammar(bottomup_rules);

    // BUG fix, always use dynamic search algorithm when treeparser
    // mode is on, since the class interface has to match.
    //dynamic_search = gen_reducers && (has_cost || has_cost_exp);
    dynamic_search = gen_reducers;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to enter the protocols into the protocol map
//
///////////////////////////////////////////////////////////////////////////////
void FunctorMap::enter_protocols ()
{  Protocols Ps = RewritingCompiler::lookup_protocols(class_name);
   {  for_each (Protocol, p, Ps)
      {  
#line 196 "funmap.pcc"
#line 200 "funmap.pcc"
{
#line 198 "funmap.pcc"
 encode(p->ty);  protocols.insert(p->ty,p); 
   if (p->syn != NOty) has_syn_attrib = true;
   
#line 200 "funmap.pcc"
}
#line 201 "funmap.pcc"
#line 201 "funmap.pcc"

      }
   }
}
    
     
///////////////////////////////////////////////////////////////////////////////
//
//  Checks for missing protocol
//
///////////////////////////////////////////////////////////////////////////////
void FunctorMap::check_for_missing_protocols()
{  foreach_entry (e, type_map)
   {  Ty ty = Ty(type_map.key(e));
      if (! protocols.contains(ty))
      {  error("%Lmissing type %T in the traversal list of rewrite class %s\n",
               ty, class_name);
      }
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Otherwise, build the tree grammar and the functor/variable name maps.
//
///////////////////////////////////////////////////////////////////////////////
void FunctorMap::build_tree_grammar (MatchRules rules)
{
   N = length(rules);
   TreeProduction * Ps = 
       (TreeProduction *)mem_pool.c_alloc(sizeof(TreeProduction) * N);

   ////////////////////////////////////////////////////////////////////////////
   //
   //  Translate patterns into terms
   //
   ////////////////////////////////////////////////////////////////////////////
   {  int i = 0;
      for_each (MatchRule, r, rules)
      {  
#line 240 "funmap.pcc"
#line 255 "funmap.pcc"
{
#line 242 "funmap.pcc"
 int rule_no = r->_1 ? var_map[r->_1] : 0; 
   int cst;
   
#line 244 "funmap.pcc"
#line 247 "funmap.pcc"
   {
      Cost _V1 = r->_4;
      if (_V1) {
         if (untagp(_V1)) {
            
#line 246 "funmap.pcc"
           cst = ((Cost_INTcost *)derefp(_V1))->INTcost; has_cost = true; 
#line 246 "funmap.pcc"
         } else {
            
#line 247 "funmap.pcc"
           cst = 0; has_cost_exp = true; 
#line 247 "funmap.pcc"
         }
      } else {
#line 245 "funmap.pcc"
        cst = 0; 
#line 245 "funmap.pcc"
      }
   }
#line 248 "funmap.pcc"
#line 248 "funmap.pcc"
   
   Ps[i] = TreeProduction(rule_no,trans(r->_2),cst);
   if (r->_3 != NOexp || (r->option & MatchRuleInfo::FAILREWRITE))
   		   has_guard = true;
   if (r->option & MatchRuleInfo::REPLACEMENT)
   		   has_replacement = true;
   i++;
   
#line 255 "funmap.pcc"
}
#line 256 "funmap.pcc"
#line 256 "funmap.pcc"

      }
   }
   
   ////////////////////////////////////////////////////////////////////////////
   //
   //  Compute the functor/variable names
   //
   ////////////////////////////////////////////////////////////////////////////
   compute_names(); 

   ////////////////////////////////////////////////////////////////////////////
   //
   //  Compile the tree grammar
   //
   ////////////////////////////////////////////////////////////////////////////
   G.compile (N, Ps, functor_names, variable_names, 0, functors - 1, 0);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to convert literal patterns inside a set of matching rules
//  into guards
//
///////////////////////////////////////////////////////////////////////////////
void FunctorMap::make_guard (MatchRules rules)
{  
#line 282 "funmap.pcc"
#line 286 "funmap.pcc"
{
   for (;;) {
      if (rules) {
#line 284 "funmap.pcc"
       rules->_1->_2   = make_guard(rules->_1->_2, rules->_1->_3); 
         rules = rules->_2;
         
#line 286 "funmap.pcc"
      } else { goto L3; }
   }
   L3:;
}
#line 287 "funmap.pcc"
#line 287 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to convert literal patterns into guards.
//
///////////////////////////////////////////////////////////////////////////////
Pat FunctorMap::make_guard (Pat pat, Exp& e)
{  Pat new_pat;
   // return pat; // BUG fix
   
#line 298 "funmap.pcc"
#line 323 "funmap.pcc"
{
   if (pat) {
      switch (pat->tag__) {
         case a_Pat::tag_APPpat: {
#line 304 "funmap.pcc"
           new_pat = APPpat(make_guard(((Pat_APPpat *)pat)->_1,e),make_guard(((Pat_APPpat *)pat)->_2,e)); 
#line 304 "funmap.pcc"
            } break;
         case a_Pat::tag_TYPEDpat: {
#line 300 "funmap.pcc"
           new_pat = TYPEDpat(make_guard(((Pat_TYPEDpat *)pat)->_1,e),((Pat_TYPEDpat *)pat)->_2); 
#line 300 "funmap.pcc"
            } break;
         case a_Pat::tag_ASpat: {
#line 299 "funmap.pcc"
           new_pat = ASpat(((Pat_ASpat *)pat)->_1,make_guard(((Pat_ASpat *)pat)->_2,e),((Pat_ASpat *)pat)->_3,((Pat_ASpat *)pat)->_4); 
#line 299 "funmap.pcc"
            } break;
         case a_Pat::tag_LITERALpat: {
            switch (((Pat_LITERALpat *)pat)->LITERALpat->tag__) {
               case a_Literal::tag_INTlit:
               case a_Literal::tag_BOOLlit:
               case a_Literal::tag_CHARlit:
               case a_Literal::tag_REALlit: {
#line 306 "funmap.pcc"
                Exp guard_exp = BINOPexp("==",pat->selector,LITERALexp(((Pat_LITERALpat *)pat)->LITERALpat));
                  e = e == NOexp ? guard_exp : BINOPexp("&&",e,guard_exp);
                  new_pat = WILDpat();
                  
#line 309 "funmap.pcc"
                  } break;
               default: {
                  L4:; 
#line 323 "funmap.pcc"
                 new_pat = pat; 
#line 323 "funmap.pcc"
                  } break;
            }
            } break;
         case a_Pat::tag_TUPLEpat: {
#line 302 "funmap.pcc"
           new_pat = TUPLEpat(make_guard(((Pat_TUPLEpat *)pat)->TUPLEpat,e)); 
#line 302 "funmap.pcc"
            } break;
         case a_Pat::tag_RECORDpat: {
#line 303 "funmap.pcc"
           new_pat = RECORDpat(make_guard(((Pat_RECORDpat *)pat)->_1,e),((Pat_RECORDpat *)pat)->_2); 
#line 303 "funmap.pcc"
            } break;
         case a_Pat::tag_LISTpat: {
#line 311 "funmap.pcc"
          new_pat = 
#line 311 "funmap.pcc"
#line 311 "funmap.pcc"
            LISTpat(((Pat_LISTpat *)pat)->cons, ((Pat_LISTpat *)pat)->nil, make_guard(((Pat_LISTpat *)pat)->head,e), make_guard(((Pat_LISTpat *)pat)->tail,e))
#line 312 "funmap.pcc"
#line 312 "funmap.pcc"
            ;
            
#line 313 "funmap.pcc"
            } break;
         case a_Pat::tag_VECTORpat: {
#line 315 "funmap.pcc"
          new_pat = 
#line 315 "funmap.pcc"
#line 315 "funmap.pcc"
            VECTORpat(((Pat_VECTORpat *)pat)->cons, make_guard(((Pat_VECTORpat *)pat)->len,e), make_guard(((Pat_VECTORpat *)pat)->array,e), make_guard(((Pat_VECTORpat *)pat)->elements,e), ((Pat_VECTORpat *)pat)->head_flex, ((Pat_VECTORpat *)pat)->tail_flex)
#line 321 "funmap.pcc"
#line 321 "funmap.pcc"
            ;
            
#line 322 "funmap.pcc"
            } break;
         case a_Pat::tag_MARKEDpat: {
#line 301 "funmap.pcc"
           new_pat = MARKEDpat(((Pat_MARKEDpat *)pat)->_1,make_guard(((Pat_MARKEDpat *)pat)->_2,e)); 
#line 301 "funmap.pcc"
            } break;
         default: { goto L4; } break;
      }
   } else { goto L4; }
}
#line 324 "funmap.pcc"
#line 324 "funmap.pcc"

   if (new_pat != pat && boxed(new_pat))
   {  new_pat->ty = pat->ty;
      new_pat->selector = pat->selector;
   }  
   return new_pat;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Unguard a pattern list
//
///////////////////////////////////////////////////////////////////////////////
Pats FunctorMap::make_guard (Pats ps, Exp& e)
{  
#line 338 "funmap.pcc"
#line 340 "funmap.pcc"
{
   if (ps) {
#line 340 "funmap.pcc"
     return 
#line 340 "funmap.pcc"
#line 340 "funmap.pcc"
      list_1_(make_guard(ps->_1,e),make_guard(ps->_2,e))
#line 340 "funmap.pcc"
#line 340 "funmap.pcc"
      ; 
#line 340 "funmap.pcc"
   } else {
#line 339 "funmap.pcc"
     return 
#line 339 "funmap.pcc"
#line 339 "funmap.pcc"
      nil_1_
#line 339 "funmap.pcc"
#line 339 "funmap.pcc"
      ; 
#line 339 "funmap.pcc"
   }
}
#line 341 "funmap.pcc"
#line 341 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Unguard a labeled pattern list
//
///////////////////////////////////////////////////////////////////////////////
LabPats FunctorMap::make_guard (LabPats ps, Exp& e)
{  
#line 350 "funmap.pcc"
#line 356 "funmap.pcc"
{
   if (ps) {
#line 352 "funmap.pcc"
     LabPat lab_pat;
      lab_pat.label = ps->_1.label;
      lab_pat.pat   = make_guard(ps->_1.pat,e);
      return 
#line 355 "funmap.pcc"
#line 355 "funmap.pcc"
      list_1_(lab_pat,make_guard(ps->_2,e))
#line 355 "funmap.pcc"
#line 355 "funmap.pcc"
      ; 
      
#line 356 "funmap.pcc"
   } else {
#line 351 "funmap.pcc"
     return 
#line 351 "funmap.pcc"
#line 351 "funmap.pcc"
      nil_1_
#line 351 "funmap.pcc"
#line 351 "funmap.pcc"
      ; 
#line 351 "funmap.pcc"
   }
}
#line 357 "funmap.pcc"
#line 357 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Check whether we know of the type
//
///////////////////////////////////////////////////////////////////////////////
Bool FunctorMap::is_known_type(Ty ty)
{  return type_map.contains(ty)      ||
          ty_equal(ty, string_ty)    ||
          ty_equal(ty, quark_ty) 
//        ty_equal(ty, integer_ty)   ||
//        ty_equal(ty, bool_ty)      ||
//        ty_equal(ty, real_ty)      ||
//        ty_equal(ty, character_ty)
   ;
} 

///////////////////////////////////////////////////////////////////////////////
//
//  Check whether we the type is rewritable.
//
///////////////////////////////////////////////////////////////////////////////
Bool FunctorMap::is_rewritable_type(Ty ty) { return type_map.contains(ty); } 

///////////////////////////////////////////////////////////////////////////////
//
//  Method to assign variable encoding to a non-terminal
//
///////////////////////////////////////////////////////////////////////////////
void FunctorMap::encode (Id id)
{  if (! var_map.contains(id))
   {  ++variables; var_map.insert(id,variables);
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to assign functor encoding to a type
//
///////////////////////////////////////////////////////////////////////////////
void FunctorMap::encode (Ty ty)
{  
#line 400 "funmap.pcc"
#line 409 "funmap.pcc"
{
   Ty _V2 = deref_all(ty);
   if (_V2) {
      switch (_V2->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V2)->_1)) {
               switch (((Ty_TYCONty *)_V2)->_1->tag__) {
                  case a_TyCon::tag_DATATYPEtycon: {
#line 402 "funmap.pcc"
                   if (! type_map.contains(_V2)) 
                     {  type_map.insert(_V2, functors);
                        functors += ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V2)->_1)->unit + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V2)->_1)->arg;
                     }
                     
#line 406 "funmap.pcc"
                     } break;
                  default: {
                     L5:; 
#line 407 "funmap.pcc"
                   for_each(Ty, ty, ((Ty_TYCONty *)_V2)->_2) encode(ty); 
#line 407 "funmap.pcc"
                     } break;
               }
            } else { goto L5; }
            } break;
         default: {
            L6:; } break;
      }
   } else { goto L6; }
}
#line 409 "funmap.pcc"
#line 409 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to assign functor encoding to a pattern.
//  Assign a functor value to each distinct literal and pattern constructor.
//
///////////////////////////////////////////////////////////////////////////////
void FunctorMap::encode(Pat pat)
{  
#line 419 "funmap.pcc"
#line 480 "funmap.pcc"
{
   for (;;) {
      if (pat) {
         switch (pat->tag__) {
            case a_Pat::tag_CONSpat: {
               if (((Pat_CONSpat *)pat)->CONSpat) {
                  if (((Pat_CONSpat *)pat)->CONSpat->alg_ty) {
                     switch (((Pat_CONSpat *)pat)->CONSpat->alg_ty->tag__) {
                        case a_Ty::tag_TYCONty: {
                           if (boxed(((Ty_TYCONty *)((Pat_CONSpat *)pat)->CONSpat->alg_ty)->_1)) {
                              switch (((Ty_TYCONty *)((Pat_CONSpat *)pat)->CONSpat->alg_ty)->_1->tag__) {
                                 case a_TyCon::tag_DATATYPEtycon: {
#line 449 "funmap.pcc"
                                  if (pat->ty != NOty && ! type_map.contains(pat->ty)) 
                                    {  type_map.insert(pat->ty, functors);
                                       functors += ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)pat)->CONSpat->alg_ty)->_1)->unit + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)pat)->CONSpat->alg_ty)->_1)->arg;
                                    }
                                    return;
                                    
#line 454 "funmap.pcc"
                                    } break;
                                 default: {
                                    L8:; 
#line 480 "funmap.pcc"
                                   error ("%LSorry: pattern not supported in rewriting: %p\n", pat); return; 
#line 480 "funmap.pcc"
                                    } break;
                              }
                           } else { goto L8; }
                           } break;
                        default: { goto L8; } break;
                     }
                  } else { goto L8; }
               } else { goto L8; }
               } break;
            case a_Pat::tag_APPpat: {
#line 455 "funmap.pcc"
              encode(pat->ty); pat = ((Pat_APPpat *)pat)->_2; 
#line 455 "funmap.pcc"
               } break;
            case a_Pat::tag_TYPEDpat: {
#line 422 "funmap.pcc"
              pat = ((Pat_TYPEDpat *)pat)->_1; 
#line 422 "funmap.pcc"
               } break;
            case a_Pat::tag_ASpat: {
#line 421 "funmap.pcc"
              pat = ((Pat_ASpat *)pat)->_2; 
#line 421 "funmap.pcc"
               } break;
            case a_Pat::tag_LITERALpat: {
               switch (((Pat_LITERALpat *)pat)->LITERALpat->tag__) {
                  case a_Literal::tag_BIGINTlit: { goto L8; } break;
                  case a_Literal::tag_STRINGlit:
                  case a_Literal::tag_REGEXPlit:
                  case a_Literal::tag_QUARKlit: {
#line 437 "funmap.pcc"
                   if (! literal_map.contains(((Pat_LITERALpat *)pat)->LITERALpat)) 
                     {  literal_map.insert(((Pat_LITERALpat *)pat)->LITERALpat,functors); 
                        functors++; 
                     }
                     return;
                     
#line 442 "funmap.pcc"
                     } break;
                  default: {
#line 444 "funmap.pcc"
                    bug ("%Luntransformed literal pattern %p found in rewriting\n",pat); 
#line 444 "funmap.pcc"
                     } break;
               }
               } break;
            case a_Pat::tag_TUPLEpat: {
#line 425 "funmap.pcc"
             int i = 0; 
               for_each (Pat, p, ((Pat_TUPLEpat *)pat)->TUPLEpat) { i++; encode(p); }
               if (max_arity < i) max_arity = i;
               return; 
               
#line 429 "funmap.pcc"
               } break;
            case a_Pat::tag_RECORDpat: {
#line 431 "funmap.pcc"
             for_each (LabPat, p, ((Pat_RECORDpat *)pat)->_1) { encode(p.pat); }
               int arity = arity_of(pat->ty);
               if (max_arity < arity) max_arity = arity;
               return;
               
#line 435 "funmap.pcc"
               } break;
            case a_Pat::tag_LISTpat: {
#line 457 "funmap.pcc"
             Pat new_pat = CONSpat(((Pat_LISTpat *)pat)->nil);
               new_pat->ty = pat->ty;
               encode(new_pat);
               for_each (Pat, i, ((Pat_LISTpat *)pat)->head) encode(i);
               if (max_arity < 2) max_arity = 2;
               pat = ((Pat_LISTpat *)pat)->tail;
               
#line 463 "funmap.pcc"
               } break;
            case a_Pat::tag_VECTORpat: {
#line 465 "funmap.pcc"
             Pat new_pat = CONSpat(((Pat_VECTORpat *)pat)->cons);
               new_pat->ty = pat->ty;
               encode(new_pat);
               for_each (Pat, p, ((Pat_VECTORpat *)pat)->elements) encode(p); 
               int l = length(((Pat_VECTORpat *)pat)->elements);
               if (max_arity < l) max_arity = l;
               if (pat->ty != NOty)
               {  VectorId vec_id = vector_id(((Pat_VECTORpat *)pat)->cons,pat->ty,l);
                  if ( ! vector_map.contains(vec_id))
                  {  vector_map.insert(vec_id, functors);
                     functors++;
                  }
               }
               return;
               
#line 479 "funmap.pcc"
               } break;
            case a_Pat::tag_MARKEDpat: {
#line 423 "funmap.pcc"
              pat = ((Pat_MARKEDpat *)pat)->_2; 
#line 423 "funmap.pcc"
               } break;
            case a_Pat::tag_WILDpat:
            case a_Pat::tag_IDpat: {
               L9:; 
#line 420 "funmap.pcc"
              return; 
#line 420 "funmap.pcc"
               } break;
            default: { goto L8; } break;
         }
      } else { goto L9; }
   }
}
#line 481 "funmap.pcc"
#line 481 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to translate a pattern into a term.
//
///////////////////////////////////////////////////////////////////////////////
TreeTerm FunctorMap::trans(Pat pat)
{  
#line 490 "funmap.pcc"
#line 575 "funmap.pcc"
{
   for (;;) {
      if (pat) {
         switch (pat->tag__) {
            case a_Pat::tag_WILDpat: {
               L11:; 
#line 491 "funmap.pcc"
              return wild_term; 
#line 491 "funmap.pcc"
               } break;
            case a_Pat::tag_IDpat: {
#line 500 "funmap.pcc"
             return var_map.contains(((Pat_IDpat *)pat)->_1) ? var_term(var_map[((Pat_IDpat *)pat)->_1]) : wild_term; 
               
#line 501 "funmap.pcc"
               } break;
            case a_Pat::tag_CONSpat: {
               if (((Pat_CONSpat *)pat)->CONSpat) {
#line 553 "funmap.pcc"
                return new_term(mem_pool, type_map[pat->ty]+((Pat_CONSpat *)pat)->CONSpat->tag); 
#line 553 "funmap.pcc"
               } else {
                  L12:; 
#line 575 "funmap.pcc"
                 error ("%LSorry: pattern not supported: %p\n", pat); return wild_term; 
#line 575 "funmap.pcc"
               }
               } break;
            case a_Pat::tag_APPpat: {
               if (((Pat_APPpat *)pat)->_1) {
                  switch (((Pat_APPpat *)pat)->_1->tag__) {
                     case a_Pat::tag_CONSpat: {
                        if (((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat) {
                           if (((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty) {
                              switch (((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty->tag__) {
                                 case a_Ty::tag_TYCONty: {
                                    if (boxed(((Ty_TYCONty *)((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty)->_1)) {
                                       switch (((Ty_TYCONty *)((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty)->_1->tag__) {
                                          case a_TyCon::tag_DATATYPEtycon: {
#line 540 "funmap.pcc"
                                           TreeTerm a = trans(((Pat_APPpat *)pat)->_2);
                                             
#line 541 "funmap.pcc"
#line 549 "funmap.pcc"
                                             {
                                                int _V4 = arity_of(((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->ty);
                                                switch (_V4) {
                                                   case 1: {
#line 543 "funmap.pcc"
                                                    return new_term(mem_pool,type_map[pat->ty]+((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty)->_1)->unit+((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->tag,1,&a); 
                                                      
#line 544 "funmap.pcc"
                                                   } break;
                                                   default: {
                                                      if (a) {
                                                         switch (a->tag__) {
                                                            case a_TreeTerm::tag_tree_term: {
#line 546 "funmap.pcc"
                                                             ((TreeTerm_tree_term *)a)->_1 = type_map[pat->ty]+((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty)->_1)->unit+((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->tag; return a; 
#line 546 "funmap.pcc"
                                                               } break;
                                                            default: {
                                                               L13:; 
#line 548 "funmap.pcc"
                                                             return new_term(mem_pool, type_map[pat->ty]+((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty)->_1)->unit+((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->tag, _V4);
                                                               
#line 549 "funmap.pcc"
                                                               } break;
                                                         }
                                                      } else { goto L13; }
                                                   }
                                                }
                                             }
#line 550 "funmap.pcc"
#line 550 "funmap.pcc"
                                             
                                             
#line 551 "funmap.pcc"
                                             } break;
                                          default: { goto L12; } break;
                                       }
                                    } else { goto L12; }
                                    } break;
                                 default: { goto L12; } break;
                              }
                           } else { goto L12; }
                        } else { goto L12; }
                        } break;
                     default: { goto L12; } break;
                  }
               } else { goto L12; }
               } break;
            case a_Pat::tag_TYPEDpat: {
#line 493 "funmap.pcc"
              pat = ((Pat_TYPEDpat *)pat)->_1; 
#line 493 "funmap.pcc"
               } break;
            case a_Pat::tag_ASpat: {
#line 492 "funmap.pcc"
              pat = ((Pat_ASpat *)pat)->_2; 
#line 492 "funmap.pcc"
               } break;
            case a_Pat::tag_LITERALpat: {
               switch (((Pat_LITERALpat *)pat)->LITERALpat->tag__) {
                  case a_Literal::tag_STRINGlit:
                  case a_Literal::tag_REGEXPlit:
                  case a_Literal::tag_QUARKlit: {
#line 496 "funmap.pcc"
                   return new_term(mem_pool,literal_map[((Pat_LITERALpat *)pat)->LITERALpat]); 
#line 496 "funmap.pcc"
                     } break;
                  default: {
#line 498 "funmap.pcc"
                   return wild_term; 
#line 498 "funmap.pcc"
                     } break;
               }
               } break;
            case a_Pat::tag_TUPLEpat: {
#line 503 "funmap.pcc"
             int arity = length (((Pat_TUPLEpat *)pat)->TUPLEpat);
               TreeTerm * subterms = 
                  (TreeTerm *)mem_pool.c_alloc(sizeof(TreeTerm) * arity);
               int i = 0; 
               for_each (Pat, p, ((Pat_TUPLEpat *)pat)->TUPLEpat)
               {  subterms[i++] = trans(p); }
               return new_term(mem_pool,0,arity,subterms);
               
#line 510 "funmap.pcc"
               } break;
            case a_Pat::tag_RECORDpat: {
#line 512 "funmap.pcc"
             
#line 512 "funmap.pcc"
#line 533 "funmap.pcc"
               {
                  Ty _V3 = deref(pat->ty);
                  if (_V3) {
                     switch (_V3->tag__) {
                        case a_Ty::tag_TYCONty: {
                           if (boxed(((Ty_TYCONty *)_V3)->_1)) {
                              switch (((Ty_TYCONty *)_V3)->_1->tag__) {
                                 case a_TyCon::tag_RECORDtycon: {
#line 514 "funmap.pcc"
                                  Bool relevant[256]; int i; int arity;
                                    i = arity = 0;
                                    for_each(Ty, t, ((Ty_TYCONty *)_V3)->_2) 
                                    {  if (relevant[i++] = is_known_type(t)) arity++; }
                                    TreeTerm * subterms = 
                                       (TreeTerm *)mem_pool.c_alloc(sizeof(TreeTerm) * arity);
                                    for (i = 0; i < arity; i++)
                                       subterms[i] = wild_term;
                                    for_each (LabPat, p, ((Pat_RECORDpat *)pat)->_1)
                                    {  Ids labs; Tys ts;
                                       for (i = 0, labs = ((TyCon_RECORDtycon *)((Ty_TYCONty *)_V3)->_1)->_1, ts = ((Ty_TYCONty *)_V3)->_2; 
                                            labs && ts; labs = labs->_2, ts = ts->_2)
                                       {  if (p.label == labs->_1)
                                          {  subterms[i] = trans(p.pat); break; }
                                          if (is_known_type(ts->_1)) i++;
                                       }
                                    }
                                    return new_term(mem_pool,0,arity,subterms);
                                    
#line 532 "funmap.pcc"
                                    } break;
                                 default: {
                                    L14:; 
#line 533 "funmap.pcc"
                                   bug("%Lillegal record pattern %p\n", pat); 
#line 533 "funmap.pcc"
                                    } break;
                              }
                           } else { goto L14; }
                           } break;
                        default: { goto L14; } break;
                     }
                  } else { goto L14; }
               }
#line 534 "funmap.pcc"
#line 534 "funmap.pcc"
               
               
#line 535 "funmap.pcc"
               } break;
            case a_Pat::tag_LISTpat: {
               if (((Pat_LISTpat *)pat)->head) {
#line 558 "funmap.pcc"
                Pat new_tail = 
#line 558 "funmap.pcc"
#line 558 "funmap.pcc"
                  LISTpat(((Pat_LISTpat *)pat)->cons, ((Pat_LISTpat *)pat)->nil, ((Pat_LISTpat *)pat)->head->_2, ((Pat_LISTpat *)pat)->tail)
#line 558 "funmap.pcc"
#line 558 "funmap.pcc"
                  ;
                  Pat new_p    = APPpat(CONSpat(((Pat_LISTpat *)pat)->cons),TUPLEpat(
#line 559 "funmap.pcc"
#line 559 "funmap.pcc"
                  list_1_(((Pat_LISTpat *)pat)->head->_1,list_1_(new_tail))
#line 559 "funmap.pcc"
#line 559 "funmap.pcc"
                  ));
                  new_p->ty    = new_tail->ty = pat->ty;
                  pat = new_p;
                  
#line 562 "funmap.pcc"
               } else {
                  if (((Pat_LISTpat *)pat)->tail) {
#line 556 "funmap.pcc"
                   pat = ((Pat_LISTpat *)pat)->tail; 
#line 556 "funmap.pcc"
                  } else {
#line 555 "funmap.pcc"
                   Pat p = CONSpat(((Pat_LISTpat *)pat)->nil); p->ty = pat->ty; pat = p; 
#line 555 "funmap.pcc"
                  }
               }
               } break;
            case a_Pat::tag_VECTORpat: {
#line 564 "funmap.pcc"
             TreeTerm a     = trans(TUPLEpat(((Pat_VECTORpat *)pat)->elements));
               int      arity = length(((Pat_VECTORpat *)pat)->elements);
               
#line 566 "funmap.pcc"
#line 572 "funmap.pcc"
               {
                  if (a) {
                     switch (a->tag__) {
                        case a_TreeTerm::tag_tree_term: {
#line 568 "funmap.pcc"
                         ((TreeTerm_tree_term *)a)->_1 = vector_map[vector_id(((Pat_VECTORpat *)pat)->cons,pat->ty,arity)]; 
                           return a; 
                           
#line 570 "funmap.pcc"
                           } break;
                        default: {
                           L15:; 
#line 572 "funmap.pcc"
                          bug ("%Lillegal pattern: %p\n", pat); return wild_term; 
#line 572 "funmap.pcc"
                           } break;
                     }
                  } else { goto L15; }
               }
#line 573 "funmap.pcc"
#line 573 "funmap.pcc"
               
               
#line 574 "funmap.pcc"
               } break;
            case a_Pat::tag_MARKEDpat: {
#line 494 "funmap.pcc"
              pat = ((Pat_MARKEDpat *)pat)->_2; 
#line 494 "funmap.pcc"
               } break;
            default: { goto L12; } break;
         }
      } else { goto L11; }
   }
}
#line 576 "funmap.pcc"
#line 576 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Compute ceil(ln(2))
//
///////////////////////////////////////////////////////////////////////////////
int ln2 (int n)
{  int bits = 0;
   while (n > 0) { n >>= 1; bits++; }
   return bits;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to compute the rhs non-terminal (if it is a chain rule)
//  Otherwise, returns NIL.
//
///////////////////////////////////////////////////////////////////////////////
Id FunctorMap::chain_rule_rhs (Pat pat)
{  
#line 597 "funmap.pcc"
#line 602 "funmap.pcc"
{
   if (pat) {
      switch (pat->tag__) {
         case a_Pat::tag_IDpat: {
#line 598 "funmap.pcc"
           return var_map.contains(((Pat_IDpat *)pat)->_1) ? ((Pat_IDpat *)pat)->_1 : 0; 
#line 598 "funmap.pcc"
            } break;
         case a_Pat::tag_TYPEDpat: {
#line 601 "funmap.pcc"
           return chain_rule_rhs(((Pat_TYPEDpat *)pat)->_1); 
#line 601 "funmap.pcc"
            } break;
         case a_Pat::tag_ASpat: {
#line 599 "funmap.pcc"
           return chain_rule_rhs(((Pat_ASpat *)pat)->_2); 
#line 599 "funmap.pcc"
            } break;
         case a_Pat::tag_MARKEDpat: {
#line 600 "funmap.pcc"
           return chain_rule_rhs(((Pat_MARKEDpat *)pat)->_2); 
#line 600 "funmap.pcc"
            } break;
         default: {
            L16:; 
#line 602 "funmap.pcc"
           return 0; 
#line 602 "funmap.pcc"
            } break;
      }
   } else { goto L16; }
}
#line 603 "funmap.pcc"
#line 603 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to partition the set of rules according to the types of the
//  patterns.  Also encode the patterns in the process.
//
///////////////////////////////////////////////////////////////////////////////
MatchRules FunctorMap::partition_rules (MatchRules rules)
{  bottomup_rules = 
#line 613 "funmap.pcc"
#line 613 "funmap.pcc"
nil_1_
#line 613 "funmap.pcc"
#line 613 "funmap.pcc"
;
   // First, we assign a new type variable for each lhs non-terminal.
   {  for_each (MatchRule, r, rules)
      {  
#line 616 "funmap.pcc"
#line 634 "funmap.pcc"
{
#line 618 "funmap.pcc"
 if (r->mode == MatchRuleInfo::BOTTOMUP)
   {  bottomup_rules = 
#line 619 "funmap.pcc"
#line 619 "funmap.pcc"
   list_1_(r,bottomup_rules)
#line 619 "funmap.pcc"
#line 619 "funmap.pcc"
   ;
   if (r->_1)
   {  HashTable::Entry * lhs_entry = nonterm_map.lookup(r->_1);
      if (! lhs_entry) nonterm_map.insert(r->_1,mkvar());
      encode(r->_1);  // compute encoding for the variable
      HashTable::Entry * e = nonterm_rules.lookup(r->_1);
      if (! e) nonterm_rules.insert(r->_1,
#line 625 "funmap.pcc"
#line 625 "funmap.pcc"
   list_1_(r)
#line 625 "funmap.pcc"
#line 625 "funmap.pcc"
   );
   else { e->v = 
#line 626 "funmap.pcc"
#line 626 "funmap.pcc"
   list_1_(r,MatchRules(e->v))
#line 626 "funmap.pcc"
#line 626 "funmap.pcc"
   ; }
   } else if (dynamic_search)
      error("%!missing non-terminal in tree grammar rule: %r\n",
            r->loc(), r); 
   } else if (r->_1)
   {  error("%!illegal non-terminal in non bottom-up rule: %r\n",
         r->loc(), r); 
   }
   
#line 634 "funmap.pcc"
}
#line 635 "funmap.pcc"
#line 635 "funmap.pcc"

      }
   }

   bottomup_rules = rev(bottomup_rules);

   // Compute the size needed to encode each non-terminal
   {  foreach_entry (e, nonterm_rules)
      {  int bits = ln2(length(MatchRules(e->v))+1);
         nonterm_rules_bits.insert(e->k,HashTable::Value(bits));
      }
   }

   // Type check all the rules next.
   // We have to also compute the type map for each lhs non-terminal.
   // Of course, a non-terminal but have only one single type.
   // This is done by unifying all occurances of a non-terminal.

   patvar_typemap = &nonterm_map; // set the pattern variable type map

   for_each (MatchRule, r, bottomup_rules)
   {  
#line 656 "funmap.pcc"
#line 683 "funmap.pcc"
{
#line 658 "funmap.pcc"
 r->set_loc();
   Ty ty = r->ty = type_of(r->_2); 
   
   // Check the type of the non-terminal (if any).
   if (r->_1)
   {  Ty lhs_ty = Ty(nonterm_map.lookup(r->_1)->v);
      if (! unify(lhs_ty, ty))
      {  error("%!type mismatch between nonterminal %s(type %T) and rule %r(type %T)\n",
               r->loc(),r->_1,lhs_ty,r,ty);
      }
   }
   
   if (! is_datatype(ty))
      error ("%!rule %r is of a non datatype: %T\n",r->loc(),r,ty); 
   
   // Collect chain rules.
   if (r->_1)
   {  Id rhs = chain_rule_rhs(r->_2);
      if (rhs)
      {  HashTable::Entry * cr = chain_rules.lookup(rhs);
         if (! cr) chain_rules.insert(rhs, 
#line 678 "funmap.pcc"
#line 678 "funmap.pcc"
   list_1_(r)
#line 678 "funmap.pcc"
#line 678 "funmap.pcc"
   );
   else { cr->v = 
#line 679 "funmap.pcc"
#line 679 "funmap.pcc"
   list_1_(r,MatchRules(cr->v))
#line 679 "funmap.pcc"
#line 679 "funmap.pcc"
   ; }
   r->is_chain_rule = true;
   }
   }
   
#line 683 "funmap.pcc"
}
#line 684 "funmap.pcc"
#line 684 "funmap.pcc"

   }

   patvar_typemap = 0; // reset the pattern variable type map

   // Now partition rules by type and assign functor encoding.
   // Since we have also typed the rules, this is quite simple: just
   // another pass.  We have to make sure that after the type inference
   // we don't have any more polymorphic types inside the patterns.
   int rule_num = 0;
   for_each (MatchRule, R, rules)
   {  
#line 695 "funmap.pcc"
#line 720 "funmap.pcc"
{
   if (
#line 696 "funmap.pcc"
   (R->mode != MatchRuleInfo::BOTTOMUP)
#line 696 "funmap.pcc"
) {
      
#line 697 "funmap.pcc"
    R->set_loc();
      R->ty = type_of(R->_2); 
      HashTable::Entry * e = rule_maps[R->mode]->lookup(R->ty);
      if (e) e->v = 
#line 700 "funmap.pcc"
#line 700 "funmap.pcc"
      list_1_(R,MatchRules(e->v))
#line 700 "funmap.pcc"
#line 700 "funmap.pcc"
      ;
      else rule_maps[R->mode]->insert(R->ty,
#line 701 "funmap.pcc"
#line 701 "funmap.pcc"
      list_1_(R)
#line 701 "funmap.pcc"
#line 701 "funmap.pcc"
      );
      
#line 702 "funmap.pcc"
   } else {
      
#line 704 "funmap.pcc"
    if (! is_ground(R->ty))
      error ("%!rule %r has incomplete type %T\n",R->loc(),R,R->ty); 
      
      HashTable::Entry * e = rule_map.lookup(R->ty);
      if (e) e->v = 
#line 708 "funmap.pcc"
#line 708 "funmap.pcc"
      list_1_(R,MatchRules(e->v))
#line 708 "funmap.pcc"
#line 708 "funmap.pcc"
      ;
      else rule_map.insert(R->ty,
#line 709 "funmap.pcc"
#line 709 "funmap.pcc"
      list_1_(R)
#line 709 "funmap.pcc"
#line 709 "funmap.pcc"
      );
      
                  // convert literals into guards
                  // BUG: 2-6-97  This doesn't work right since
                  // the guard testing is not prioritized properly !!!
                  R->_2 = make_guard (R->_2, R->_3);   
      
                  // assign functor encoding
                  encode(R->_2);
      
                  R->rule_number = rule_num++;
               
#line 720 "funmap.pcc"
   }
}
#line 721 "funmap.pcc"
#line 721 "funmap.pcc"

   }

   return bottomup_rules;
} 

///////////////////////////////////////////////////////////////////////////////
//
//  Method to compute the functor and variable table.
//
///////////////////////////////////////////////////////////////////////////////
void FunctorMap::compute_names ()
{ 
   functor_names  = (Id *)mem_pool.c_alloc(sizeof(Id) * functors);
   variable_names = (Id *)mem_pool.c_alloc(sizeof(Id) * (variables + N + 4));
 
   {  for (int i = N + variables - 1; i >= 0; i--) variable_names[i] = 0; }
   {  for (int i = functors - 1; i >= 0; i--)  functor_names[i] = "???"; }
   variable_names[0] = "_";

   // Compute variable names
   {  foreach_entry (i,var_map) 
        variable_names[var_map.value(i)] = (Id)var_map.key(i);
   }

   // Compute literal names
   {  foreach_entry (i,literal_map) 
      {  Literal l = (Literal)literal_map.key(i); 
         Functor f = literal_map.value(i);
         char buf[1024];
         ostrstream b(buf,sizeof(buf));
         ostream& s = b;
         s << l << ends;
         functor_names[f] = Quark(buf); 
      }
   }

   // Compute constructor names
   {  foreach_entry (i,type_map) 
      {  Ty      t = (Ty)type_map.key(i); 
         Functor f = type_map.value(i);
         
#line 762 "funmap.pcc"
#line 775 "funmap.pcc"
{
   Ty _V5 = deref(t);
   if (_V5) {
      switch (_V5->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V5)->_1)) {
               switch (((Ty_TYCONty *)_V5)->_1->tag__) {
                  case a_TyCon::tag_DATATYPEtycon: {
#line 764 "funmap.pcc"
                   int arity = ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V5)->_1)->unit + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V5)->_1)->arg;
                     for (int j = 0; j < arity; j++)
                     {  
#line 766 "funmap.pcc"
#line 772 "funmap.pcc"
                     {
                        Cons _V6 = ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V5)->_1)->terms[j];
                        if (_V6) {
#line 768 "funmap.pcc"
                         functor_names[f + (_V6->ty == NOty ? _V6->tag : _V6->tag + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V5)->_1)->unit)] =
                           _V6->name;
                           
#line 770 "funmap.pcc"
                        } else {}
                     }
#line 772 "funmap.pcc"
#line 772 "funmap.pcc"
                     
                     }
                     
#line 774 "funmap.pcc"
                     } break;
                  default: {
                     L17:; 
#line 775 "funmap.pcc"
                    bug ("compute_names()"); 
#line 775 "funmap.pcc"
                     } break;
               }
            } else { goto L17; }
            } break;
         default: { goto L17; } break;
      }
   } else { goto L17; }
}
#line 776 "funmap.pcc"
#line 776 "funmap.pcc"

      }
   }

   // Compute vector constructor names
   {  foreach_entry (i, vector_map)
      {  VectorId id = (VectorId)vector_map.key(i);
         Functor  f  = vector_map.value(i);
         if (id->cons) functor_names[f] = id->cons->name;
      }
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print a report detailing the functor/variable encoding,
//  the tree grammar and the generated table size.
//
///////////////////////////////////////////////////////////////////////////////
void FunctorMap::print_report (ostream& log)
{ 
   if (var_map.size() > 0) 
   {  log << "Variable encoding:\n";
      foreach_entry (e, var_map)
      {  log << "\tnon-terminal \"" << (Id)var_map.key(e) << "\"\t=\t"
             << var_map.value(e) << '\n';
      } 
   }

   if (literal_map.size() > 0) 
   {  log << "\nFunctor encoding for literals:\n";
      foreach_entry (e, literal_map)
      {  log << "literal " << (Literal)literal_map.key(e) << "\t=\t"
             << literal_map.value(e) << '\n';
      }
   }

   log << "\nFunctor encoding for constructors:\n";

   {  foreach_entry (e, type_map)
      {  Ty      t = (Ty)type_map.key(e);
         Functor f = type_map.value(e);
         log << "datatype " << t << ":\n"; 
         
#line 819 "funmap.pcc"
#line 833 "funmap.pcc"
{
   Ty _V7 = deref(t);
   if (_V7) {
      switch (_V7->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V7)->_1)) {
               switch (((Ty_TYCONty *)_V7)->_1->tag__) {
                  case a_TyCon::tag_DATATYPEtycon: {
#line 821 "funmap.pcc"
                   int arity = ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V7)->_1)->unit + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V7)->_1)->arg;
                     for (int i = 0; i < arity; i++)
                     {  
#line 823 "funmap.pcc"
#line 829 "funmap.pcc"
                     {
                        Cons _V8 = ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V7)->_1)->terms[i];
                        if (_V8) {
#line 825 "funmap.pcc"
                         log << '\t' << _V8->name << "\t=\t" 
                           << f + (_V8->ty == NOty ? _V8->tag : _V8->tag + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V7)->_1)->unit) << '\n';
                           
#line 827 "funmap.pcc"
                        } else {}
                     }
#line 829 "funmap.pcc"
#line 829 "funmap.pcc"
                     
                     }
                     
#line 831 "funmap.pcc"
                     } break;
                  default: {
                     L18:; } break;
               }
            } else { goto L18; }
            } break;
         default: { goto L18; } break;
      }
   } else { goto L18; }
}
#line 833 "funmap.pcc"
#line 833 "funmap.pcc"

      }
   }

   if (tree_gen)
   {
      log << "\nIndex compression is " 
          << (use_compression ? "enabled" : "disabled")
          << "\nAlgorithm is " << tree_gen->algorithm();
      tree_gen->print_report(log);
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to return the cost expression for a pattern.
//
///////////////////////////////////////////////////////////////////////////////
Exp FunctorMap::cost_expr (Id lhs, Pat pat)
{  
#line 852 "funmap.pcc"
#line 854 "funmap.pcc"
{
   if (pat) {
#line 854 "funmap.pcc"
     return cost_expr(lhs,pat,LITERALexp(INTlit(1))); 
#line 854 "funmap.pcc"
   } else {
#line 853 "funmap.pcc"
     return LITERALexp(INTlit(0)); 
#line 853 "funmap.pcc"
   }
}
#line 855 "funmap.pcc"
#line 855 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to compute the cost expression for a pattern
//
///////////////////////////////////////////////////////////////////////////////
Exp FunctorMap::cost_expr (Id lhs, Pat pat, Exp exp)
{  
#line 864 "funmap.pcc"
#line 883 "funmap.pcc"
{
   if (pat) {
      switch (pat->tag__) {
         case a_Pat::tag_WILDpat: {} break;
         case a_Pat::tag_IDpat: {} break;
         case a_Pat::tag_APPpat: {
#line 870 "funmap.pcc"
           return cost_expr(lhs,((Pat_APPpat *)pat)->_2,exp); 
#line 870 "funmap.pcc"
            } break;
         case a_Pat::tag_TYPEDpat: {
#line 868 "funmap.pcc"
           return cost_expr(lhs,((Pat_TYPEDpat *)pat)->_1,exp); 
#line 868 "funmap.pcc"
            } break;
         case a_Pat::tag_ASpat: {
#line 866 "funmap.pcc"
           return cost_expr(lhs,((Pat_ASpat *)pat)->_2,exp); 
#line 866 "funmap.pcc"
            } break;
         case a_Pat::tag_CONTEXTpat: {
#line 871 "funmap.pcc"
           return cost_expr(lhs,((Pat_CONTEXTpat *)pat)->_2,exp); 
#line 871 "funmap.pcc"
            } break;
         case a_Pat::tag_ARRAYpat: {
#line 874 "funmap.pcc"
           return cost_expr(lhs,((Pat_ARRAYpat *)pat)->_1,exp); 
#line 874 "funmap.pcc"
            } break;
         case a_Pat::tag_TUPLEpat: {
#line 872 "funmap.pcc"
           return cost_expr(lhs,((Pat_TUPLEpat *)pat)->TUPLEpat,exp); 
#line 872 "funmap.pcc"
            } break;
         case a_Pat::tag_EXTUPLEpat: {
#line 873 "funmap.pcc"
           return cost_expr(lhs,((Pat_EXTUPLEpat *)pat)->EXTUPLEpat,exp); 
#line 873 "funmap.pcc"
            } break;
         case a_Pat::tag_RECORDpat: {
#line 875 "funmap.pcc"
           return cost_expr(lhs,((Pat_RECORDpat *)pat)->_1,exp); 
#line 875 "funmap.pcc"
            } break;
         case a_Pat::tag_LISTpat: {
#line 877 "funmap.pcc"
           return cost_expr(lhs,((Pat_LISTpat *)pat)->head,cost_expr(lhs,((Pat_LISTpat *)pat)->tail,exp)); 
#line 877 "funmap.pcc"
            } break;
         case a_Pat::tag_VECTORpat: {
#line 879 "funmap.pcc"
           return cost_expr(lhs,((Pat_VECTORpat *)pat)->len,cost_expr(lhs,((Pat_VECTORpat *)pat)->array,
            cost_expr(lhs,((Pat_VECTORpat *)pat)->elements,exp))); 
#line 880 "funmap.pcc"
            } break;
         case a_Pat::tag_GUARDpat: {
#line 869 "funmap.pcc"
           return cost_expr(lhs,((Pat_GUARDpat *)pat)->_1,exp); 
#line 869 "funmap.pcc"
            } break;
         case a_Pat::tag_MARKEDpat: {
#line 867 "funmap.pcc"
           return cost_expr(lhs,((Pat_MARKEDpat *)pat)->_2,exp); 
#line 867 "funmap.pcc"
            } break;
         case a_Pat::tag_CONSpat:
         case a_Pat::tag_LITERALpat: {
            L19:; 
#line 865 "funmap.pcc"
           return exp; 
#line 865 "funmap.pcc"
            } break;
         default: {
#line 883 "funmap.pcc"
           return exp; 
#line 883 "funmap.pcc"
            } break;
      }
   } else { goto L19; }
}
#line 884 "funmap.pcc"
#line 884 "funmap.pcc"


   // BUG fix: if the argument type is not a datatype or 
   // not rewritable, then there is no cost to consider.
   if (! is_datatype(pat->ty) || ! is_rewritable_type(pat->ty))
      return exp; 
  
   Ty state_rec_ty = mkptrty(mkidty(Quark(class_name,"_StateRec"),
#line 891 "funmap.pcc"
#line 891 "funmap.pcc"
nil_1_
#line 891 "funmap.pcc"
#line 891 "funmap.pcc"
));
   Exp cost_e = 
      INDEXexp(
        ARROWexp(
           CASTexp(state_rec_ty,
               APPexp(ARROWexp(pat->selector,"get_state_rec"), TUPLEexp(
#line 896 "funmap.pcc"
#line 896 "funmap.pcc"
nil_1_
#line 896 "funmap.pcc"
#line 896 "funmap.pcc"
))),
               "cost"), LITERALexp(INTlit(int(var_map[lhs]))));
   return exp == NOexp ? cost_e : BINOPexp("+",cost_e,exp);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to compute the cost expression for a pattern list
//
///////////////////////////////////////////////////////////////////////////////
Exp FunctorMap::cost_expr (Id lhs, Pats pats, Exp exp)
{  
#line 907 "funmap.pcc"
#line 909 "funmap.pcc"
{
   if (pats) {
#line 909 "funmap.pcc"
     return cost_expr(lhs,pats->_1,cost_expr(lhs,pats->_2,exp)); 
#line 909 "funmap.pcc"
   } else {
#line 908 "funmap.pcc"
     return exp; 
#line 908 "funmap.pcc"
   }
}
#line 910 "funmap.pcc"
#line 910 "funmap.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to compute the cost expression for a labeled pattern list
//
///////////////////////////////////////////////////////////////////////////////
Exp FunctorMap::cost_expr (Id lhs, LabPats pats, Exp exp)
{  
#line 919 "funmap.pcc"
#line 921 "funmap.pcc"
{
   if (pats) {
#line 921 "funmap.pcc"
     return cost_expr(lhs,pats->_1.pat,cost_expr(lhs,pats->_2,exp)); 
#line 921 "funmap.pcc"
   } else {
#line 920 "funmap.pcc"
     return exp; 
#line 920 "funmap.pcc"
   }
}
#line 922 "funmap.pcc"
#line 922 "funmap.pcc"

}

#line 925 "funmap.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 352
Number of ifs generated      = 37
Number of switches generated = 25
Number of labels             = 15
Number of gotos              = 34
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
