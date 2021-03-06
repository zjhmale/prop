///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.6),
//  last updated on Nov 2, 1999.
//  The original source file is "trs.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_STRCMP_USED
#define PROP_TUPLE2_USED
#include <propdefs.h>
#line 1 "trs.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  These are the routines for building the data structure 
//  for partial evaluting a TRS
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string.h>
#include "trs.h"
#include "ir.h"
#include "ast.h"
#include "type.h"
#include "list.h"
#include "matchcom.h"
#include "datagen.h"
#include "rwgen.h"
#include "funmap.h"
#include "setlgen.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Constructors for represents a term
//
///////////////////////////////////////////////////////////////////////////////
#line 25 "trs.pcc"
#line 25 "trs.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Term
//
///////////////////////////////////////////////////////////////////////////////
#line 25 "trs.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Term
//
///////////////////////////////////////////////////////////////////////////////
#line 25 "trs.pcc"
Term_CONSterm::Term_CONSterm (TreeAutomaton::Functor x_1, Cons x_2, int x_3, Term * x_4)
 : a_Term(tag_CONSterm), _1(x_1), _2(x_2), _3(x_3), _4(x_4)
{
}
a_Term * CONSterm (TreeAutomaton::Functor x_1, Cons x_2, int x_3, Term * x_4)
{
   return new Term_CONSterm (x_1, x_2, x_3, x_4);
}
Term_VARterm::Term_VARterm (int x_1, Pat x_2, Exp x_3)
 : a_Term(tag_VARterm), _1(x_1), _2(x_2), _3(x_3)
{
}
a_Term * VARterm (int x_1, Pat x_2, Exp x_3)
{
   return new Term_VARterm (x_1, x_2, x_3);
}
Term_CODEterm::Term_CODEterm (Exp x_CODEterm)
 : a_Term(tag_CODEterm), CODEterm(x_CODEterm)
{
}
a_Term * CODEterm (Exp x_CODEterm)
{
   return new Term_CODEterm (x_CODEterm);
}
Term_OPAQUEterm::Term_OPAQUEterm (Decls x_OPAQUEterm)
 : a_Term(tag_OPAQUEterm), OPAQUEterm(x_OPAQUEterm)
{
}
a_Term * OPAQUEterm (Decls x_OPAQUEterm)
{
   return new Term_OPAQUEterm (x_OPAQUEterm);
}
Term_PATterm::Term_PATterm (Pat x_PATterm)
 : a_Term(tag_PATterm), PATterm(x_PATterm)
{
}
a_Term * PATterm (Pat x_PATterm)
{
   return new Term_PATterm (x_PATterm);
}


#line 25 "trs.pcc"
#line 25 "trs.pcc"


///////////////////////////////////////////////////////////////////////////////
//
//  Constructor for TRS 
//
///////////////////////////////////////////////////////////////////////////////
TRS::TRS(RewritingCompiler& C)
   : compiler(C), Fmap(*C.Fmap), treeauto(*C.Fmap->tree_gen), 
     count_redex(false)
{  
   MatchRules rules = Fmap.bottomup_rules;
   number_of_rules  = length(rules);
   rule_map    = new MatchRule [number_of_rules];
   guard_map   = new Exp       [number_of_rules];
   lhs_map     = new Term      [number_of_rules];
   rhs_map     = new Term      [number_of_rules];
   num_var_map = new int       [number_of_rules];
   var_map     = new Exp *     [number_of_rules];
   var_pat_map = new Pat *     [number_of_rules];
   residue_map = new Residues *[number_of_rules];
   literal_map = new Literal   [Fmap.G.functors()];
   optimized_map = new Exp     [number_of_rules];

   clear_statistics();

   int i = 0;
   for_each(MatchRule, r, rules)
   {  
#line 53 "trs.pcc"
#line 63 "trs.pcc"
{
#line 55 "trs.pcc"
 if (r->rule_number != i) bug("%LTRS::TRS()"); 
   rule_map[i]  = r;
   guard_map[i] = r->_3;
   	    make_lhs(i,r->_2);
   
#line 59 "trs.pcc"
#line 61 "trs.pcc"
   {
      a_List<Decl> *  _V1 = r->_5;
      if (_V1) {
         if (_V1->_1) {
            switch (_V1->_1->tag__) {
               case a_Decl::tag_MARKEDdecl: {
                  if (((Decl_MARKEDdecl *)_V1->_1)->_2) {
                     switch (((Decl_MARKEDdecl *)_V1->_1)->_2->tag__) {
                        case a_Decl::tag_REPLACEMENTdecl: {
                           if (_V1->_2) {
                              L1:; 
#line 61 "trs.pcc"
                             rhs_map[i] = OPAQUEterm(r->_5); 
#line 61 "trs.pcc"
                           } else {
#line 60 "trs.pcc"
                             make_rhs(i,((Decl_REPLACEMENTdecl *)((Decl_MARKEDdecl *)_V1->_1)->_2)->_1); 
#line 60 "trs.pcc"
                           }
                           } break;
                        default: { goto L1; } break;
                     }
                  } else { goto L1; }
                  } break;
               default: { goto L1; } break;
            }
         } else { goto L1; }
      } else { goto L1; }
   }
#line 62 "trs.pcc"
#line 62 "trs.pcc"
  
   
#line 63 "trs.pcc"
}
#line 64 "trs.pcc"
#line 64 "trs.pcc"

      i++;
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Destructor for TRS
//
///////////////////////////////////////////////////////////////////////////////
TRS::~TRS() 
{  delete [] rule_map;
   delete [] guard_map;
   delete [] lhs_map;
   delete [] rhs_map;
   delete [] num_var_map;
   delete [] var_map;
   delete [] var_pat_map;
   delete [] residue_map;
   delete [] literal_map;
   delete [] optimized_map;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to determine if any expression is a pattern variable.
//
///////////////////////////////////////////////////////////////////////////////
Bool is_pattern_var(Exp exp)
{  
#line 93 "trs.pcc"
#line 98 "trs.pcc"
{
   for (;;) {
      if (exp) {
         switch (exp->tag__) {
            case a_Exp::tag_DOTexp: {
               if (((Exp_DOTexp *)exp)->_1) {
                  switch (((Exp_DOTexp *)exp)->_1->tag__) {
                     case a_Exp::tag_SELECTORexp: {
                        if (((Exp_SELECTORexp *)((Exp_DOTexp *)exp)->_1)->_1) {
                           switch (((Exp_SELECTORexp *)((Exp_DOTexp *)exp)->_1)->_1->tag__) {
                              case a_Exp::tag_IDexp: {
                                 if (_equal_string(((Exp_IDexp *)((Exp_SELECTORexp *)((Exp_DOTexp *)exp)->_1)->_1)->IDexp,"redex")) {
#line 95 "trs.pcc"
                                return true; 
#line 95 "trs.pcc"
}
                                 else {
                                 L3:; 
#line 96 "trs.pcc"
                                exp = ((Exp_SELECTORexp *)((Exp_DOTexp *)exp)->_1)->_1; 
#line 96 "trs.pcc"
}
                                 } break;
                              default: { goto L3; } break;
                           }
                        } else { goto L3; }
                        } break;
                     default: {
                        L4:; 
#line 98 "trs.pcc"
                       return false; 
#line 98 "trs.pcc"
                        } break;
                  }
               } else { goto L4; }
               } break;
            case a_Exp::tag_SELECTORexp: {
               if (((Exp_SELECTORexp *)exp)->_1) {
                  switch (((Exp_SELECTORexp *)exp)->_1->tag__) {
                     case a_Exp::tag_IDexp: {
                        if (_equal_string(((Exp_IDexp *)((Exp_SELECTORexp *)exp)->_1)->IDexp,"redex")) {
#line 94 "trs.pcc"
                       return true; 
#line 94 "trs.pcc"
}
                        else {
                        L5:; 
#line 97 "trs.pcc"
                       exp = ((Exp_SELECTORexp *)exp)->_1; 
#line 97 "trs.pcc"
}
                        } break;
                     default: { goto L5; } break;
                  }
               } else { goto L5; }
               } break;
            default: { goto L4; } break;
         }
      } else { goto L4; }
   }
}
#line 99 "trs.pcc"
#line 99 "trs.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to create the lhs
//
///////////////////////////////////////////////////////////////////////////////
void TRS::make_lhs(Rule r, Pat pat)
{  num_vars = 0;
   lhs_map[r] = make_term(pat);

   num_var_map[r] = num_vars;
   var_map[r]     = (Exp*)mem_pool.m_alloc(sizeof(Exp)*num_vars);
   var_pat_map[r] = (Pat*)mem_pool.m_alloc(sizeof(Pat)*num_vars);
   residue_map[r] = (Residues*)mem_pool.c_alloc(sizeof(Residues)*num_vars);
   optimized_map[r] = NOexp;

   memcpy(var_map[r],    vars,    sizeof(Exp)*num_vars);
   memcpy(var_pat_map[r],var_pats,sizeof(Pat)*num_vars);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to create the lhs for rule r
//
///////////////////////////////////////////////////////////////////////////////
Term TRS::make_term(Pat pat)
{  
#line 127 "trs.pcc"
#line 148 "trs.pcc"
{
   for (;;) {
      if (pat) {
         switch (pat->tag__) {
            case a_Pat::tag_IDpat: {
#line 130 "trs.pcc"
              return make_term_var(pat,pat->selector); 
#line 130 "trs.pcc"
               } break;
            case a_Pat::tag_CONSpat: {
#line 133 "trs.pcc"
              return make_term(pat,((Pat_CONSpat *)pat)->CONSpat,
#line 133 "trs.pcc"
#line 133 "trs.pcc"
               nil_1_
#line 133 "trs.pcc"
#line 133 "trs.pcc"
               ); 
#line 133 "trs.pcc"
               } break;
            case a_Pat::tag_APPpat: {
               if (((Pat_APPpat *)pat)->_1) {
                  switch (((Pat_APPpat *)pat)->_1->tag__) {
                     case a_Pat::tag_CONSpat: {
                        if (((Pat_APPpat *)pat)->_2) {
                           switch (((Pat_APPpat *)pat)->_2->tag__) {
                              case a_Pat::tag_TUPLEpat: {
#line 131 "trs.pcc"
                                return make_term(pat,((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat,((Pat_TUPLEpat *)((Pat_APPpat *)pat)->_2)->TUPLEpat); 
#line 131 "trs.pcc"
                                 } break;
                              default: {
                                 L7:; 
#line 132 "trs.pcc"
                                return make_term(pat,((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat,
#line 132 "trs.pcc"
#line 132 "trs.pcc"
                                 list_1_(((Pat_APPpat *)pat)->_2)
#line 132 "trs.pcc"
#line 132 "trs.pcc"
                                 ); 
#line 132 "trs.pcc"
                                 } break;
                           }
                        } else { goto L7; }
                        } break;
                     default: {
                        L8:; 
#line 148 "trs.pcc"
                       return PATterm(pat); 
#line 148 "trs.pcc"
                        } break;
                  }
               } else { goto L8; }
               } break;
            case a_Pat::tag_ASpat: {
#line 129 "trs.pcc"
              pat = ((Pat_ASpat *)pat)->_2; 
#line 129 "trs.pcc"
               } break;
            case a_Pat::tag_LITERALpat: {
               if (
#line 143 "trs.pcc"
               Fmap.literal_map.contains(((Pat_LITERALpat *)pat)->LITERALpat)
#line 143 "trs.pcc"
) {
                  
#line 144 "trs.pcc"
                Functor f = Fmap.literal_map[((Pat_LITERALpat *)pat)->LITERALpat];
                  	 literal_map[f] = ((Pat_LITERALpat *)pat)->LITERALpat; 
                  	 return CONSterm(f,NOcons,0,0); 
                        
#line 147 "trs.pcc"
               } else {
                   goto L8; }
               } break;
            case a_Pat::tag_LISTpat: {
               if (((Pat_LISTpat *)pat)->head) {
#line 139 "trs.pcc"
                Pat tl_pat = 
#line 139 "trs.pcc"
#line 139 "trs.pcc"
                  LISTpat(((Pat_LISTpat *)pat)->cons, ((Pat_LISTpat *)pat)->nil, ((Pat_LISTpat *)pat)->head->_2, ((Pat_LISTpat *)pat)->tail)
#line 139 "trs.pcc"
#line 139 "trs.pcc"
                  ;
                  	 tl_pat->ty = pat->ty;
                  	 return make_term(pat,((Pat_LISTpat *)pat)->cons,
#line 141 "trs.pcc"
#line 141 "trs.pcc"
                  list_1_(((Pat_LISTpat *)pat)->head->_1,list_1_(tl_pat))
#line 141 "trs.pcc"
#line 141 "trs.pcc"
                  );
                  
#line 142 "trs.pcc"
               } else {
                  if (((Pat_LISTpat *)pat)->tail) {
#line 137 "trs.pcc"
                   pat = ((Pat_LISTpat *)pat)->tail; 
#line 137 "trs.pcc"
                  } else {
#line 135 "trs.pcc"
                   return make_term(pat,((Pat_LISTpat *)pat)->nil,
#line 135 "trs.pcc"
#line 135 "trs.pcc"
                     nil_1_
#line 135 "trs.pcc"
#line 135 "trs.pcc"
                     ); 
#line 135 "trs.pcc"
                  }
               }
               } break;
            case a_Pat::tag_MARKEDpat: {
#line 128 "trs.pcc"
              pat = ((Pat_MARKEDpat *)pat)->_2; 
#line 128 "trs.pcc"
               } break;
            default: { goto L8; } break;
         }
      } else { goto L8; }
   }
}
#line 149 "trs.pcc"
#line 149 "trs.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to create the lhs for rule r
//
///////////////////////////////////////////////////////////////////////////////
Term TRS::make_term(Pat pat, Cons cons, Pats pats)
{  int n       = length(pats);
   FunctorTable::Entry * E = Fmap.type_map.lookup(pat->ty);
   if (E == 0) { return PATterm(pat); }
   
#line 161 "trs.pcc"
#line 167 "trs.pcc"
{
   Ty _V2 = cons->alg_ty;
   if (_V2) {
      switch (_V2->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V2)->_1)) {
               switch (((Ty_TYCONty *)_V2)->_1->tag__) {
                  case a_TyCon::tag_DATATYPEtycon: {
#line 163 "trs.pcc"
                   Functor f = Fmap.type_map.value(E) + cons->tag + 
                     		       (cons->ty == NOty ? 0 : ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V2)->_1)->unit);
                     	 return CONSterm(f,cons,n,make_term(pats));
                           
#line 166 "trs.pcc"
                     } break;
                  default: {
                     L9:; 
#line 167 "trs.pcc"
                    bug("TRS::make_term"); return PATterm(pat); 
#line 167 "trs.pcc"
                     } break;
               }
            } else { goto L9; }
            } break;
         default: { goto L9; } break;
      }
   } else { goto L9; }
}
#line 168 "trs.pcc"
#line 168 "trs.pcc"
 
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to create the lhs for rule r
//
///////////////////////////////////////////////////////////////////////////////
Term * TRS::make_term(Pats pats)
{  int n = length(pats);
   Term * args = (Term *)mem_pool.m_alloc(sizeof(Term) * n);
   int i = 0;
   for_each(Pat, p, pats) args[i++] = make_term(p);
   return args; 
}

///////////////////////////////////////////////////////////////////////////////
//
//  Return the type of an expression
//
///////////////////////////////////////////////////////////////////////////////
Ty type_of(Exp e) { return type_of(e,Env()); }

///////////////////////////////////////////////////////////////////////////////
//
//  Method to create the rhs for rule r
//
///////////////////////////////////////////////////////////////////////////////
void TRS::make_rhs(Rule r, Exp exp)
{  type_of(exp);
   rhs_map[r] = make_term(exp);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to create the rhs
//
///////////////////////////////////////////////////////////////////////////////
Term TRS::make_term(Exp exp)
{  Exp law_exp;
   
#line 208 "trs.pcc"
#line 242 "trs.pcc"
{
   for (;;) {
      if (exp) {
         switch (exp->tag__) {
            case a_Exp::tag_LITERALexp: {
               if (
#line 239 "trs.pcc"
               Fmap.literal_map.contains(((Exp_LITERALexp *)exp)->LITERALexp)
#line 239 "trs.pcc"
) {
                  
#line 240 "trs.pcc"
                 return CONSterm(Fmap.literal_map[((Exp_LITERALexp *)exp)->LITERALexp],0,0,0); 
#line 240 "trs.pcc"
               } else {
                  
                  L11:; 
                  if (
#line 241 "trs.pcc"
                  is_pattern_var(exp)
#line 241 "trs.pcc"
) {
                     
                     L12:; 
#line 241 "trs.pcc"
                    return make_term_var(NOpat,exp); 
#line 241 "trs.pcc"
                  } else {
                     
                     L13:; 
#line 242 "trs.pcc"
                    return CODEterm(exp); 
#line 242 "trs.pcc"
                  }
               }
               } break;
            case a_Exp::tag_IDexp: {
#line 210 "trs.pcc"
              return make_term(exp,((Exp_IDexp *)exp)->IDexp,
#line 210 "trs.pcc"
#line 210 "trs.pcc"
               nil_1_
#line 210 "trs.pcc"
#line 210 "trs.pcc"
               ); 
#line 210 "trs.pcc"
               } break;
            case a_Exp::tag_APPexp: {
               if (
#line 241 "trs.pcc"
               is_pattern_var(exp)
#line 241 "trs.pcc"
) {
                  
                  if (((Exp_APPexp *)exp)->_1) {
                     switch (((Exp_APPexp *)exp)->_1->tag__) {
                        case a_Exp::tag_IDexp: {
                           L14:; 
                           if (((Exp_APPexp *)exp)->_2) {
                              switch (((Exp_APPexp *)exp)->_2->tag__) {
                                 case a_Exp::tag_TUPLEexp: {
                                    L15:; 
#line 228 "trs.pcc"
                                   law_exp = DatatypeCompiler::lookup_law(((Exp_IDexp *)((Exp_APPexp *)exp)->_1)->IDexp,((Exp_TUPLEexp *)((Exp_APPexp *)exp)->_2)->TUPLEexp);
                                    	if (law_exp == NOexp) return make_term(exp,((Exp_IDexp *)((Exp_APPexp *)exp)->_1)->IDexp,((Exp_TUPLEexp *)((Exp_APPexp *)exp)->_2)->TUPLEexp); 
                                    	type_of(law_exp);
                                    	exp = law_exp; 
                                          
#line 232 "trs.pcc"
                                    } break;
                                 default: {
                                    L16:; 
#line 234 "trs.pcc"
                                   law_exp = DatatypeCompiler::lookup_law(((Exp_IDexp *)((Exp_APPexp *)exp)->_1)->IDexp,
#line 234 "trs.pcc"
#line 234 "trs.pcc"
                                    list_1_(((Exp_APPexp *)exp)->_2)
#line 234 "trs.pcc"
#line 234 "trs.pcc"
                                    );
                                    	if (law_exp == NOexp) return make_term(exp,((Exp_IDexp *)((Exp_APPexp *)exp)->_1)->IDexp,
#line 235 "trs.pcc"
#line 235 "trs.pcc"
                                    list_1_(((Exp_APPexp *)exp)->_2)
#line 235 "trs.pcc"
#line 235 "trs.pcc"
                                    ); 
                                    	type_of(law_exp);
                                    	exp = law_exp; 
                                          
#line 238 "trs.pcc"
                                    } break;
                              }
                           } else { goto L16; }
                           } break;
                        default: { goto L12; } break;
                     }
                  } else { goto L12; }
               } else {
                  
                  if (((Exp_APPexp *)exp)->_1) {
                     switch (((Exp_APPexp *)exp)->_1->tag__) {
                        case a_Exp::tag_IDexp: { goto L14; } break;
                        default: { goto L13; } break;
                     }
                  } else { goto L13; }
               }
               } break;
            case a_Exp::tag_LISTexp: {
               if (
#line 241 "trs.pcc"
               is_pattern_var(exp)
#line 241 "trs.pcc"
) {
                  
                  if (((Exp_LISTexp *)exp)->_3) {
                     L17:; 
                     if (((Exp_LISTexp *)exp)->_3->_2) {
                        L18:; 
#line 223 "trs.pcc"
                       Exp e2 = LISTexp(((Exp_LISTexp *)exp)->_1, ((Exp_LISTexp *)exp)->_2, ((Exp_LISTexp *)exp)->_3->_2, ((Exp_LISTexp *)exp)->_4);
                        	e2->ty = exp->ty;
                                return make_term(exp,((Exp_LISTexp *)exp)->_1->name,
#line 225 "trs.pcc"
#line 225 "trs.pcc"
                        list_1_(((Exp_LISTexp *)exp)->_3->_1,list_1_(e2))
#line 225 "trs.pcc"
#line 225 "trs.pcc"
                        );
                        
#line 226 "trs.pcc"
                     } else {
                        L19:; 
#line 218 "trs.pcc"
                       Exp nil_exp = ((Exp_LISTexp *)exp)->_4 == NOexp ? CONSexp(((Exp_LISTexp *)exp)->_2,
#line 218 "trs.pcc"
#line 218 "trs.pcc"
                        nil_1_
#line 218 "trs.pcc"
#line 218 "trs.pcc"
                        ,NOexp) : ((Exp_LISTexp *)exp)->_4;
                        	nil_exp->ty = exp->ty;
                        	return make_term(exp,((Exp_LISTexp *)exp)->_1->name,
#line 220 "trs.pcc"
#line 220 "trs.pcc"
                        list_1_(((Exp_LISTexp *)exp)->_3->_1,list_1_(nil_exp))
#line 220 "trs.pcc"
#line 220 "trs.pcc"
                        );
                        
#line 221 "trs.pcc"
                     }
                  } else { goto L12; }
               } else {
                  
                  if (((Exp_LISTexp *)exp)->_3) { goto L17; } else { goto L13; }
               }
               } break;
            case a_Exp::tag_CONSexp: {
               if (
#line 241 "trs.pcc"
               is_pattern_var(exp)
#line 241 "trs.pcc"
) {
                  
                  if (((Exp_CONSexp *)exp)->_3) {
                     switch (((Exp_CONSexp *)exp)->_3->tag__) {
                        case a_Exp::tag_TUPLEexp: {
                           if (((Exp_CONSexp *)exp)->_2) { goto L12; } else {
                              L20:; 
#line 214 "trs.pcc"
                             return make_term(exp,((Exp_CONSexp *)exp)->_1->name,((Exp_TUPLEexp *)((Exp_CONSexp *)exp)->_3)->TUPLEexp); 
#line 214 "trs.pcc"
                           }
                           } break;
                        default: {
                           if (((Exp_CONSexp *)exp)->_2) { goto L12; } else {
                              L21:; 
#line 216 "trs.pcc"
                             return make_term(exp,((Exp_CONSexp *)exp)->_1->name,
#line 216 "trs.pcc"
#line 216 "trs.pcc"
                              list_1_(((Exp_CONSexp *)exp)->_3)
#line 216 "trs.pcc"
#line 216 "trs.pcc"
                              ); 
#line 216 "trs.pcc"
                           }
                           } break;
                     }
                  } else {
                     if (((Exp_CONSexp *)exp)->_2) { goto L12; } else {
                        L22:; 
#line 212 "trs.pcc"
                       return make_term(exp,((Exp_CONSexp *)exp)->_1->name,
#line 212 "trs.pcc"
#line 212 "trs.pcc"
                        nil_1_
#line 212 "trs.pcc"
#line 212 "trs.pcc"
                        ); 
#line 212 "trs.pcc"
                     }
                  }
               } else {
                  
                  if (((Exp_CONSexp *)exp)->_3) {
                     switch (((Exp_CONSexp *)exp)->_3->tag__) {
                        case a_Exp::tag_TUPLEexp: {
                           if (((Exp_CONSexp *)exp)->_2) { goto L13; } else { goto L20; }
                           } break;
                        default: {
                           if (((Exp_CONSexp *)exp)->_2) { goto L13; } else { goto L21; }
                           } break;
                     }
                  } else {
                     if (((Exp_CONSexp *)exp)->_2) { goto L13; } else { goto L22; }
                  }
               }
               } break;
            case a_Exp::tag_MARKEDexp: {
#line 209 "trs.pcc"
              exp = ((Exp_MARKEDexp *)exp)->_2; 
#line 209 "trs.pcc"
               } break;
            default: { goto L11; } break;
         }
      } else { goto L11; }
   }
}
#line 243 "trs.pcc"
#line 243 "trs.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to create the rhs 
//
///////////////////////////////////////////////////////////////////////////////
Term TRS::make_term(Exp exp, Id id, Exps exps)
{  int n = length(exps);
   Cons cons = find_cons(id);
   if (cons == NOcons) { return CODEterm(exp); }
   FunctorTable::Entry * E = Fmap.type_map.lookup(exp->ty);
   if (E == 0) { return CODEterm(exp); }
   
#line 257 "trs.pcc"
#line 263 "trs.pcc"
{
   Ty _V3 = cons->alg_ty;
   if (_V3) {
      switch (_V3->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V3)->_1)) {
               switch (((Ty_TYCONty *)_V3)->_1->tag__) {
                  case a_TyCon::tag_DATATYPEtycon: {
#line 259 "trs.pcc"
                   Functor f = Fmap.type_map.value(E) + cons->tag + 
                     			 (cons->ty == NOty ? 0 : ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V3)->_1)->unit);
                     	 return CONSterm(f,cons,n,make_term(exps));
                           
#line 262 "trs.pcc"
                     } break;
                  default: {
                     L23:; 
#line 263 "trs.pcc"
                    bug("TRS::make_term"); return CODEterm(exp); 
#line 263 "trs.pcc"
                     } break;
               }
            } else { goto L23; }
            } break;
         default: { goto L23; } break;
      }
   } else { goto L23; }
}
#line 264 "trs.pcc"
#line 264 "trs.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to create the term variable 
//
///////////////////////////////////////////////////////////////////////////////
Term TRS::make_term_var(Pat pat, Exp exp)
{  for (int i = 0; i < num_vars; i++)
   {  if (equal(exp,vars[i])) return VARterm(i,var_pats[i],vars[i]); }
   if (pat == NOpat) { return CODEterm(exp); }
   if (num_vars == MAX_VARS) 
      bug("%LTRS::make_term_var() too many variables");
   vars[num_vars] = exp;
   var_pats[num_vars] = pat;
   return VARterm(num_vars++,pat,exp); 
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to create the term from a list of expressions
//
///////////////////////////////////////////////////////////////////////////////
Term * TRS::make_term(Exps exps)
{  int n = length(exps);
   Term * args = (Term *)mem_pool.m_alloc(sizeof(Term) * n);
   int i = 0;
   for_each(Exp, e, exps) args[i++] = make_term(e);
   return args; 
}

/////////////////////////////////////////////////////////////////////////////// //
//
//  Method to print a term 
//
///////////////////////////////////////////////////////////////////////////////
void TRS::print (std::ostream& s, Term term) const
{  
#line 302 "trs.pcc"
#line 336 "trs.pcc"
{
   switch (term->tag__) {
      case a_Term::tag_CONSterm: {
         switch (((Term_CONSterm *)term)->_3) {
            case 2: {
               if (
#line 303 "trs.pcc"
               is_list_constructor(((Term_CONSterm *)term)->_2)
#line 303 "trs.pcc"
) {
                  
#line 304 "trs.pcc"
                s << '#' << ((Term_CONSterm *)term)->_2->name[1];
                  	 Term t = term;
                  	 Id comma = "";
                  	 
#line 307 "trs.pcc"
#line 309 "trs.pcc"
                  {
                     for (;;) {
                        switch (t->tag__) {
                           case a_Term::tag_CONSterm: {
                              switch (((Term_CONSterm *)t)->_3) {
                                 case 2: {
                                    if (
#line 308 "trs.pcc"
                                    (((Term_CONSterm *)t)->_1 == ((Term_CONSterm *)term)->_1)
#line 308 "trs.pcc"
) {
                                       
#line 309 "trs.pcc"
                                     s << comma; print(s,((Term_CONSterm *)t)->_4[0]); t = ((Term_CONSterm *)t)->_4[1]; comma = ", "; 
#line 309 "trs.pcc"
                                    } else {
                                        goto L24; }
                                 } break;
                                 default: { goto L24; }
                              }
                              } break;
                           default: { goto L24; } break;
                        }
                     }
                     L24:;
                  }
#line 310 "trs.pcc"
#line 310 "trs.pcc"
                  
                  	 
#line 311 "trs.pcc"
#line 314 "trs.pcc"
                  {
                     switch (t->tag__) {
                        case a_Term::tag_CONSterm: {
                           switch (((Term_CONSterm *)t)->_3) {
                              case 0: {
                                 if (
#line 313 "trs.pcc"
                                 (((Term_CONSterm *)term)->_2 && is_list_constructor(((Term_CONSterm *)t)->_2))
#line 313 "trs.pcc"
) {
                                    } else {
                                    
                                    L25:; 
#line 314 "trs.pcc"
                                   s << comma; print(s,t); 
#line 314 "trs.pcc"
                                 }
                              } break;
                              default: { goto L25; }
                           }
                           } break;
                        default: { goto L25; } break;
                     }
                  }
#line 315 "trs.pcc"
#line 315 "trs.pcc"
                  
                  	 s << ((Term_CONSterm *)term)->_2->name[5];
                        
#line 317 "trs.pcc"
               } else {
                  
                  L26:; 
#line 319 "trs.pcc"
                s << (((Term_CONSterm *)term)->_2 != NOcons ? ((Term_CONSterm *)term)->_2->name : Fmap.G.functor_name(((Term_CONSterm *)term)->_1));
                  if (((Term_CONSterm *)term)->_3 > 0)
                  {  s << '(';
                     for (int i = 0; i < ((Term_CONSterm *)term)->_3; i++)
                     {  print(s,((Term_CONSterm *)term)->_4[i]);
                        if (i < ((Term_CONSterm *)term)->_3 - 1) s << ", ";
                     }
                     s << ')';
                  }
                  
#line 328 "trs.pcc"
               }
            } break;
            default: { goto L26; }
         }
         } break;
      case a_Term::tag_VARterm: {
#line 329 "trs.pcc"
        s << ((Term_VARterm *)term)->_2; 
#line 329 "trs.pcc"
         } break;
      case a_Term::tag_CODEterm: {
#line 330 "trs.pcc"
        Bool save = pretty_print_exp;
         			  pretty_print_exp = true;
         			  s << "[[" << ((Term_CODEterm *)term)->CODEterm << "]]"; 
         			  pretty_print_exp = save;
                                 
#line 334 "trs.pcc"
         } break;
      case a_Term::tag_OPAQUEterm: {
#line 335 "trs.pcc"
        s << "..."; 
#line 335 "trs.pcc"
         } break;
      default: {
#line 336 "trs.pcc"
        s << "[[" << ((Term_PATterm *)term)->PATterm << "]]"; 
#line 336 "trs.pcc"
         } break;
   }
}
#line 337 "trs.pcc"
#line 337 "trs.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to print a TRS 
//
///////////////////////////////////////////////////////////////////////////////
void TRS::print (std::ostream& s) const
{  s << "\n\nBottom-up term rewriting system:\n";
   Bool save = pretty_print_exp;
   pretty_print_exp = true;
   for (Rule r = 0; r < number_of_rules; r++)
   {  MatchRule rule = rule_map[r];
      s << "line " << rule->begin_line << ": ";
      print(s,lhs_map[r]); 
      if (guard_map[r] != NOexp) s << " | " << guard_map[r]; 
      s << ":\n\t"; print(s,rhs_map[r]); s << '\n';
      for (int i = 0; i < num_var_map[r]; i++)
      {  Pat pat_var = var_pat_map[r][i];
         Ty pat_ty   = pat_var->ty;
	 s << "\tvariable " << pat_var << " : " << pat_ty;
         if (! compiler.has_index(pat_ty)) s << " has no index"; 
	 s << '\n';
      }
      s << '\n';
   }
   s << '\n';
   pretty_print_exp = save;
}
#line 367 "trs.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 903
Number of ifs generated      = 43
Number of switches generated = 25
Number of labels             = 22
Number of gotos              = 46
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
