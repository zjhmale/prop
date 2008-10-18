///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.6),
//  last updated on Nov 2, 1999.
//  The original source file is "matchcom.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_QUARK_USED
#include <propdefs.h>
///////////////////////////////////////////////////////////////////////////////
//  Quark literals
///////////////////////////////////////////////////////////////////////////////
static const Quark _m_a_t_c_h_c_o_mco_c_c_Q1("?lexeme");
#line 1 "matchcom.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file contains the pattern matching compiler of the Prop -> C++
//  translator.  The following methods are implemented:
//
//    (i)   Variable bindings computation of patterns.
//    (ii)  Translation of patterns into decision trees.
//    (iii) Merging, transformation and minimization of decision trees/dags.
//
///////////////////////////////////////////////////////////////////////////////

#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <AD/contain/bitset.h>
#include <AD/generic/ordering.h>
#include <AD/strings/quark.h>
#include <AD/strings/charesc.h>
#include "ir.h"
#include "ast.h"
#include "matchcom.h"
#include "patenv.h"
#include "hashtab.h"
#include "config.h"
#include "type.h"
#include "options.h"
#include "list.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Constructor and destructor for class MatchCompiler
//
///////////////////////////////////////////////////////////////////////////////
MatchCompiler:: MatchCompiler()
   : vars("_X"), labels("L"),
     merges(0), ifs(0), switches(0), gotos(0), goto_labels(0),
     current_options(MATCHnone), current_rule(0)
     {}
MatchCompiler::~MatchCompiler() {}

MatchBase::MatchBase() : shared(0), label(0) {}

HashTable MatchCompiler::quark_map(string_hash,string_equal);
LabelGen MatchCompiler::quark_labels("_Q");

///////////////////////////////////////////////////////////////////////////////
//
//  Constructor for MatchRuleInfo
//
///////////////////////////////////////////////////////////////////////////////
MatchRuleInfo::MatchRuleInfo ()
  : used(false), ty(NOty), rule_number(0), negated(false), rewriting(false),
    is_chain_rule(false), mode(BOTTOMUP), option(NO_OPTIONS) {}

///////////////////////////////////////////////////////////////////////////////
//
//  Flag that makes all selectors refer to the same object.
//
///////////////////////////////////////////////////////////////////////////////
Bool same_selectors = false;

///////////////////////////////////////////////////////////////////////////////
//
//  Allocation routines
//
///////////////////////////////////////////////////////////////////////////////
Literal * MatchCompiler::Literals(int n) 
   { return (Literal *)mem_pool[n * sizeof(Literal)]; }
Match   * MatchCompiler::Matches(int n) 
   { return (Match *)mem_pool[n * sizeof(Match)]; }
static Literal * vec (Literal l)
   { Literal * L = (Literal *)mem_pool[sizeof(Literal)]; 
     L[0] = l;
     return L;
   }
static Match * vec (Match m)
   { Match * M = (Match *)mem_pool[sizeof(Match)]; 
     M[0] = m;
     return M;
   }

///////////////////////////////////////////////////////////////////////////////
//
//  The mapping from quark name to identifiers
//
///////////////////////////////////////////////////////////////////////////////
Id MatchCompiler::quark_name(Id id)
{  HashTable::Entry * e = quark_map.lookup(id);
   if (e)
   {  return (Id)e->v;
   } else
   {  Id name = Quark(options.mangled_file_name, quark_labels.new_label());
      quark_map.insert((HashTable::Key)id,(HashTable::Value)name);
      return name;
   }
} 

///////////////////////////////////////////////////////////////////////////////
//
//  Reverse the polarity of a pattern.
//
///////////////////////////////////////////////////////////////////////////////
#line 103 "matchcom.pcc"
#line 106 "matchcom.pcc"
Polarity rev (Polarity x_1);
Polarity rev (Polarity x_1)
{
   switch (x_1) {
      case ISpositive: {
#line 103 "matchcom.pcc"
         return ISnegative;
#line 104 "matchcom.pcc"
         } break;
      case ISnegative: {
#line 104 "matchcom.pcc"
         return ISpositive;
#line 105 "matchcom.pcc"
         } break;
      default: {
#line 105 "matchcom.pcc"
         return ISneither;
#line 106 "matchcom.pcc"
         } break;
   }
}
#line 106 "matchcom.pcc"
#line 106 "matchcom.pcc"


///////////////////////////////////////////////////////////////////////////////
//
//  Method to perform substitution on a pattern.
//
///////////////////////////////////////////////////////////////////////////////
Pat subst(Pat pat, Pat env[], Bool copy)
{  
#line 114 "matchcom.pcc"
#line 147 "matchcom.pcc"
{
   for (;;) {
      if (pat) {
         switch (pat->tag__) {
            case a_Pat::tag_INDpat: {
               if (
#line 120 "matchcom.pcc"
               copy
#line 120 "matchcom.pcc"
) {
                  
#line 120 "matchcom.pcc"
                 return INDpat(((Pat_INDpat *)pat)->_1,((Pat_INDpat *)pat)->_2,((Pat_INDpat *)pat)->_3); 
#line 120 "matchcom.pcc"
               } else {
                  
#line 121 "matchcom.pcc"
                 return subst(env[((Pat_INDpat *)pat)->_2], env, true); 
#line 121 "matchcom.pcc"
               }
               } break;
            case a_Pat::tag_IDpat: {
#line 116 "matchcom.pcc"
              return IDpat(((Pat_IDpat *)pat)->_1,((Pat_IDpat *)pat)->_2,((Pat_IDpat *)pat)->_3); 
#line 116 "matchcom.pcc"
               } break;
            case a_Pat::tag_CONSpat: {
#line 118 "matchcom.pcc"
              return CONSpat(((Pat_CONSpat *)pat)->CONSpat); 
#line 118 "matchcom.pcc"
               } break;
            case a_Pat::tag_APPpat: {
#line 122 "matchcom.pcc"
              return APPpat(subst(((Pat_APPpat *)pat)->_1,env,copy),subst(((Pat_APPpat *)pat)->_2,env,copy)); 
#line 122 "matchcom.pcc"
               } break;
            case a_Pat::tag_TYPEDpat: {
#line 123 "matchcom.pcc"
              return TYPEDpat(subst(((Pat_TYPEDpat *)pat)->_1,env,copy),((Pat_TYPEDpat *)pat)->_2); 
#line 123 "matchcom.pcc"
               } break;
            case a_Pat::tag_ASpat: {
#line 124 "matchcom.pcc"
              return ASpat(((Pat_ASpat *)pat)->_1,subst(((Pat_ASpat *)pat)->_2,env,copy),((Pat_ASpat *)pat)->_3,((Pat_ASpat *)pat)->_4); 
#line 124 "matchcom.pcc"
               } break;
            case a_Pat::tag_LITERALpat: {
#line 117 "matchcom.pcc"
              return LITERALpat(((Pat_LITERALpat *)pat)->LITERALpat); 
#line 117 "matchcom.pcc"
               } break;
            case a_Pat::tag_CONTEXTpat: {
#line 119 "matchcom.pcc"
              return CONTEXTpat(((Pat_CONTEXTpat *)pat)->_1,subst(((Pat_CONTEXTpat *)pat)->_2,env,copy)); 
#line 119 "matchcom.pcc"
               } break;
            case a_Pat::tag_ARRAYpat: {
#line 127 "matchcom.pcc"
              return ARRAYpat(subst(((Pat_ARRAYpat *)pat)->_1,env,copy),((Pat_ARRAYpat *)pat)->_2); 
#line 127 "matchcom.pcc"
               } break;
            case a_Pat::tag_TUPLEpat: {
#line 125 "matchcom.pcc"
              return TUPLEpat(subst(((Pat_TUPLEpat *)pat)->TUPLEpat,env,copy)); 
#line 125 "matchcom.pcc"
               } break;
            case a_Pat::tag_EXTUPLEpat: {
#line 126 "matchcom.pcc"
              return EXTUPLEpat(subst(((Pat_EXTUPLEpat *)pat)->EXTUPLEpat,env,copy)); 
#line 126 "matchcom.pcc"
               } break;
            case a_Pat::tag_RECORDpat: {
#line 138 "matchcom.pcc"
              return RECORDpat(subst(((Pat_RECORDpat *)pat)->_1,env,copy),((Pat_RECORDpat *)pat)->_2); 
#line 138 "matchcom.pcc"
               } break;
            case a_Pat::tag_LISTpat: {
#line 139 "matchcom.pcc"
              return 
#line 139 "matchcom.pcc"
#line 139 "matchcom.pcc"
               LISTpat(((Pat_LISTpat *)pat)->cons, ((Pat_LISTpat *)pat)->nil, subst(((Pat_LISTpat *)pat)->head,env,copy), subst(((Pat_LISTpat *)pat)->tail,env,copy))
#line 142 "matchcom.pcc"
#line 142 "matchcom.pcc"
               ; 
               
#line 143 "matchcom.pcc"
               } break;
            case a_Pat::tag_VECTORpat: {
#line 129 "matchcom.pcc"
              return 
#line 129 "matchcom.pcc"
#line 129 "matchcom.pcc"
               VECTORpat(((Pat_VECTORpat *)pat)->cons, subst(((Pat_VECTORpat *)pat)->len,env,copy), subst(((Pat_VECTORpat *)pat)->array,env,copy), subst(((Pat_VECTORpat *)pat)->elements,env,copy), ((Pat_VECTORpat *)pat)->head_flex, ((Pat_VECTORpat *)pat)->tail_flex)
#line 136 "matchcom.pcc"
#line 136 "matchcom.pcc"
               ; 
               
#line 137 "matchcom.pcc"
               } break;
            case a_Pat::tag_GUARDpat: {
#line 146 "matchcom.pcc"
              return GUARDpat(subst(((Pat_GUARDpat *)pat)->_1,env,copy),((Pat_GUARDpat *)pat)->_2); 
#line 146 "matchcom.pcc"
               } break;
            case a_Pat::tag_LOGICALpat: {
#line 144 "matchcom.pcc"
              return LOGICALpat(((Pat_LOGICALpat *)pat)->_1,subst(((Pat_LOGICALpat *)pat)->_2,env,copy),subst(((Pat_LOGICALpat *)pat)->_3,env,copy)); 
#line 144 "matchcom.pcc"
               } break;
            case a_Pat::tag_MARKEDpat: {
#line 145 "matchcom.pcc"
              pat = ((Pat_MARKEDpat *)pat)->_2; 
#line 145 "matchcom.pcc"
               } break;
            case a_Pat::tag_WILDpat:
            case a_Pat::tag_LEXEMEpat: {
               L2:; 
#line 115 "matchcom.pcc"
              return pat; 
#line 115 "matchcom.pcc"
               } break;
            default: {
#line 147 "matchcom.pcc"
              bug("subst()"); 
#line 147 "matchcom.pcc"
               } break;
         }
      } else { goto L2; }
   }
}
#line 148 "matchcom.pcc"
#line 148 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to perform substitution on a pattern list.
//
///////////////////////////////////////////////////////////////////////////////
Pats subst(Pats pats, Pat env[], Bool copy)
{  
#line 157 "matchcom.pcc"
#line 159 "matchcom.pcc"
{
   if (pats) {
#line 159 "matchcom.pcc"
     return 
#line 159 "matchcom.pcc"
#line 159 "matchcom.pcc"
      list_1_(subst(pats->_1,env,copy),subst(pats->_2,env,copy))
#line 159 "matchcom.pcc"
#line 159 "matchcom.pcc"
      ; 
#line 159 "matchcom.pcc"
   } else {
#line 158 "matchcom.pcc"
     return 
#line 158 "matchcom.pcc"
#line 158 "matchcom.pcc"
      nil_1_
#line 158 "matchcom.pcc"
#line 158 "matchcom.pcc"
      ; 
#line 158 "matchcom.pcc"
   }
}
#line 160 "matchcom.pcc"
#line 160 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to perform substitution on a labeled pattern list.
//
///////////////////////////////////////////////////////////////////////////////
LabPats subst(LabPats pats, Pat env[], Bool copy)
{  
#line 169 "matchcom.pcc"
#line 175 "matchcom.pcc"
{
   if (pats) {
#line 171 "matchcom.pcc"
     LabPat l;
      l.label = pats->_1.label;
      l.pat   = subst(pats->_1.pat,env,copy);
      return 
#line 174 "matchcom.pcc"
#line 174 "matchcom.pcc"
      list_1_(l,subst(pats->_2,env,copy))
#line 174 "matchcom.pcc"
#line 174 "matchcom.pcc"
      ; 
      
#line 175 "matchcom.pcc"
   } else {
#line 170 "matchcom.pcc"
     return 
#line 170 "matchcom.pcc"
#line 170 "matchcom.pcc"
      nil_1_
#line 170 "matchcom.pcc"
#line 170 "matchcom.pcc"
      ; 
#line 170 "matchcom.pcc"
   }
}
#line 176 "matchcom.pcc"
#line 176 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Pattern application.
//
///////////////////////////////////////////////////////////////////////////////
Pat apply_pat (Pat scheme, Pat arg)
{  
#line 185 "matchcom.pcc"
#line 198 "matchcom.pcc"
{
   if (scheme) {
      switch (scheme->tag__) {
         case a_Pat::tag_POLYpat: {
            if (arg) {
               switch (arg->tag__) {
                  case a_Pat::tag_TUPLEpat: {
                     if (
#line 188 "matchcom.pcc"
                     (length(((Pat_TUPLEpat *)arg)->TUPLEpat) == ((Pat_POLYpat *)scheme)->_2)
#line 188 "matchcom.pcc"
) {
                        
                        switch (((Pat_POLYpat *)scheme)->_2) {
                           case 0: {
                              if (arg) {
                                 L3:; 
#line 189 "matchcom.pcc"
                               Pat env[256]; 
                                 int i = 0;
                                 for_each (Pat, p, ((Pat_TUPLEpat *)arg)->TUPLEpat) env[i++] = p;
                                 return subst(((Pat_POLYpat *)scheme)->_4,env,false);
                                 
#line 193 "matchcom.pcc"
                              } else {
                                 L4:; 
#line 186 "matchcom.pcc"
                                return subst(((Pat_POLYpat *)scheme)->_4,0,false); 
#line 186 "matchcom.pcc"
                              }
                           } break;
                           case 1: {
                              L5:; 
#line 187 "matchcom.pcc"
                             return subst(((Pat_POLYpat *)scheme)->_4,&arg,false); 
#line 187 "matchcom.pcc"
                           } break;
                           default: { goto L3; }
                        }
                     } else {
                        
                        L6:; 
                        switch (((Pat_POLYpat *)scheme)->_2) {
                           case 0: {
                              L7:; 
                              if (arg) {
                                 L8:; 
#line 195 "matchcom.pcc"
                               error ("%Lunable to apply pattern scheme %p\n"
                                 "%Lwith argument %p\n", scheme, arg);
                                 return NOpat; 
                                 
#line 198 "matchcom.pcc"
                              } else { goto L4; }
                           } break;
                           case 1: { goto L5; } break;
                           default: { goto L8; }
                        }
                     }
                     } break;
                  default: { goto L6; } break;
               }
            } else { goto L6; }
            } break;
         default: { goto L8; } break;
      }
   } else { goto L8; }
}
#line 199 "matchcom.pcc"
#line 199 "matchcom.pcc"

}

////////////////////////////////////////////////////////////////////////////////
//
//  Substitution on expressions.
//
///////////////////////////////////////////////////////////////////////////////
Exp subst (Exp exp, Exp s[])
{  
#line 208 "matchcom.pcc"
#line 233 "matchcom.pcc"
{
   for (;;) {
      if (exp) {
         switch (exp->tag__) {
            case a_Exp::tag_RELexp: {
#line 210 "matchcom.pcc"
              return s[((Exp_RELexp *)exp)->RELexp]; 
#line 210 "matchcom.pcc"
               } break;
            case a_Exp::tag_DOTexp: {
#line 209 "matchcom.pcc"
              return DOTexp(subst(((Exp_DOTexp *)exp)->_1,s),((Exp_DOTexp *)exp)->_2); 
#line 209 "matchcom.pcc"
               } break;
            case a_Exp::tag_SELECTORexp: {
#line 211 "matchcom.pcc"
              return SELECTORexp(subst(((Exp_SELECTORexp *)exp)->_1,s),((Exp_SELECTORexp *)exp)->_2,((Exp_SELECTORexp *)exp)->_3); 
#line 211 "matchcom.pcc"
               } break;
            case a_Exp::tag_DEREFexp: {
#line 212 "matchcom.pcc"
              return DEREFexp(subst(((Exp_DEREFexp *)exp)->DEREFexp,s)); 
#line 212 "matchcom.pcc"
               } break;
            case a_Exp::tag_ARROWexp: {
#line 213 "matchcom.pcc"
              return ARROWexp(subst(((Exp_ARROWexp *)exp)->_1,s),((Exp_ARROWexp *)exp)->_2); 
#line 213 "matchcom.pcc"
               } break;
            case a_Exp::tag_INDEXexp: {
#line 214 "matchcom.pcc"
              return INDEXexp(subst(((Exp_INDEXexp *)exp)->_1,s), subst(((Exp_INDEXexp *)exp)->_2,s)); 
#line 214 "matchcom.pcc"
               } break;
            case a_Exp::tag_BINOPexp: {
#line 215 "matchcom.pcc"
              return BINOPexp(((Exp_BINOPexp *)exp)->_1,subst(((Exp_BINOPexp *)exp)->_2,s),subst(((Exp_BINOPexp *)exp)->_3,s)); 
#line 215 "matchcom.pcc"
               } break;
            case a_Exp::tag_PREFIXexp: {
#line 216 "matchcom.pcc"
              return PREFIXexp(((Exp_PREFIXexp *)exp)->_1,subst(((Exp_PREFIXexp *)exp)->_2,s)); 
#line 216 "matchcom.pcc"
               } break;
            case a_Exp::tag_POSTFIXexp: {
#line 217 "matchcom.pcc"
              return POSTFIXexp(((Exp_POSTFIXexp *)exp)->_1,subst(((Exp_POSTFIXexp *)exp)->_2,s)); 
#line 217 "matchcom.pcc"
               } break;
            case a_Exp::tag_APPexp: {
#line 218 "matchcom.pcc"
              return APPexp(subst(((Exp_APPexp *)exp)->_1,s), subst(((Exp_APPexp *)exp)->_2,s)); 
#line 218 "matchcom.pcc"
               } break;
            case a_Exp::tag_ASSIGNexp: {
#line 219 "matchcom.pcc"
              return ASSIGNexp(subst(((Exp_ASSIGNexp *)exp)->_1,s), subst(((Exp_ASSIGNexp *)exp)->_2,s)); 
#line 219 "matchcom.pcc"
               } break;
            case a_Exp::tag_IFexp: {
#line 220 "matchcom.pcc"
              return IFexp(subst(((Exp_IFexp *)exp)->_1,s), subst(((Exp_IFexp *)exp)->_2,s), subst(((Exp_IFexp *)exp)->_3,s)); 
#line 220 "matchcom.pcc"
               } break;
            case a_Exp::tag_TUPLEexp: {
#line 221 "matchcom.pcc"
              return TUPLEexp(subst(((Exp_TUPLEexp *)exp)->TUPLEexp,s)); 
#line 221 "matchcom.pcc"
               } break;
            case a_Exp::tag_RECORDexp: {
#line 222 "matchcom.pcc"
              return RECORDexp(subst(((Exp_RECORDexp *)exp)->RECORDexp,s)); 
#line 222 "matchcom.pcc"
               } break;
            case a_Exp::tag_LISTexp: {
#line 224 "matchcom.pcc"
              return LISTexp(((Exp_LISTexp *)exp)->_1,((Exp_LISTexp *)exp)->_2,subst(((Exp_LISTexp *)exp)->_3,s),subst(((Exp_LISTexp *)exp)->_4,s)); 
#line 224 "matchcom.pcc"
               } break;
            case a_Exp::tag_CONSexp: {
#line 225 "matchcom.pcc"
              return CONSexp(((Exp_CONSexp *)exp)->_1,subst(((Exp_CONSexp *)exp)->_2,s),subst(((Exp_CONSexp *)exp)->_3,s)); 
#line 225 "matchcom.pcc"
               } break;
            case a_Exp::tag_CASTexp: {
#line 226 "matchcom.pcc"
              return CASTexp(((Exp_CASTexp *)exp)->_1,subst(((Exp_CASTexp *)exp)->_2,s)); 
#line 226 "matchcom.pcc"
               } break;
            case a_Exp::tag_EQexp: {
#line 227 "matchcom.pcc"
              return EQexp(((Exp_EQexp *)exp)->_1,subst(((Exp_EQexp *)exp)->_2,s),subst(((Exp_EQexp *)exp)->_3,s)); 
#line 227 "matchcom.pcc"
               } break;
            case a_Exp::tag_UNIFYexp: {
#line 228 "matchcom.pcc"
              return UNIFYexp(((Exp_UNIFYexp *)exp)->_1,subst(((Exp_UNIFYexp *)exp)->_2,s),subst(((Exp_UNIFYexp *)exp)->_3,s)); 
#line 228 "matchcom.pcc"
               } break;
            case a_Exp::tag_LTexp: {
#line 229 "matchcom.pcc"
              return LTexp(((Exp_LTexp *)exp)->_1,subst(((Exp_LTexp *)exp)->_2,s),subst(((Exp_LTexp *)exp)->_3,s)); 
#line 229 "matchcom.pcc"
               } break;
            case a_Exp::tag_HASHexp: {
#line 230 "matchcom.pcc"
              return HASHexp(((Exp_HASHexp *)exp)->_1,subst(((Exp_HASHexp *)exp)->_2,s)); 
#line 230 "matchcom.pcc"
               } break;
            case a_Exp::tag_SENDexp: {
#line 223 "matchcom.pcc"
              return SENDexp(((Exp_SENDexp *)exp)->_1,subst(((Exp_SENDexp *)exp)->_2,s)); 
#line 223 "matchcom.pcc"
               } break;
            case a_Exp::tag_SETLexp: {
#line 231 "matchcom.pcc"
              return SETLexp(((Exp_SETLexp *)exp)->_1,subst(((Exp_SETLexp *)exp)->_2,s)); 
#line 231 "matchcom.pcc"
               } break;
            case a_Exp::tag_MARKEDexp: {
#line 232 "matchcom.pcc"
              exp = ((Exp_MARKEDexp *)exp)->_2; 
#line 232 "matchcom.pcc"
               } break;
            default: {
               L10:; 
#line 233 "matchcom.pcc"
              return exp; 
#line 233 "matchcom.pcc"
               } break;
         }
      } else { goto L10; }
   }
}
#line 234 "matchcom.pcc"
#line 234 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Substitution on expression lists.
//
///////////////////////////////////////////////////////////////////////////////
Exps subst(Exps es, Exp s[])
{  
#line 243 "matchcom.pcc"
#line 245 "matchcom.pcc"
{
   if (es) {
#line 245 "matchcom.pcc"
     return 
#line 245 "matchcom.pcc"
#line 245 "matchcom.pcc"
      list_1_(subst(es->_1,s),subst(es->_2,s))
#line 245 "matchcom.pcc"
#line 245 "matchcom.pcc"
      ; 
#line 245 "matchcom.pcc"
   } else {
#line 244 "matchcom.pcc"
     return 
#line 244 "matchcom.pcc"
#line 244 "matchcom.pcc"
      nil_1_
#line 244 "matchcom.pcc"
#line 244 "matchcom.pcc"
      ; 
#line 244 "matchcom.pcc"
   }
}
#line 246 "matchcom.pcc"
#line 246 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Substitution on labeled expression lists.
//
///////////////////////////////////////////////////////////////////////////////
LabExps subst(LabExps es, Exp s[])
{  
#line 255 "matchcom.pcc"
#line 261 "matchcom.pcc"
{
   if (es) {
#line 257 "matchcom.pcc"
     LabExp e;
      e.label = es->_1.label;
      e.exp   = subst(es->_1.exp,s); 
      return 
#line 260 "matchcom.pcc"
#line 260 "matchcom.pcc"
      list_1_(e,subst(es->_2,s))
#line 260 "matchcom.pcc"
#line 260 "matchcom.pcc"
      ; 
      
#line 261 "matchcom.pcc"
   } else {
#line 256 "matchcom.pcc"
     return 
#line 256 "matchcom.pcc"
#line 256 "matchcom.pcc"
      nil_1_
#line 256 "matchcom.pcc"
#line 256 "matchcom.pcc"
      ; 
#line 256 "matchcom.pcc"
   }
}
#line 262 "matchcom.pcc"
#line 262 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Compute the view selector given the type
//
///////////////////////////////////////////////////////////////////////////////
Exp view_selector_of(Cons cons, Pat pat, Exp e, Ty ty)
{  Exp selector_exp = default_val(ty);
   if (selector_exp == NOexp)
   {  error ("%Laccessor is undefined for view pattern: %s %p\n", 
             (cons != NOcons ? cons->name : "???"), pat); 
      return NOexp; 
   } else
   {  return subst(selector_exp,&e);
   }   
}

///////////////////////////////////////////////////////////////////////////////
//
//  Decorate selector bindings for a view constructor
//
///////////////////////////////////////////////////////////////////////////////
void decor_view
   (Cons cons, Pat pat, Exp sel, 
    Polarity polarity, Bool visible, PatternVarEnv& E, int& match_rule) 
{
   if (boxed(pat)) pat->selector = sel; // annotate selector
   
#line 291 "matchcom.pcc"
#line 331 "matchcom.pcc"
{
   if (cons) {
      if (
#line 292 "matchcom.pcc"
      (cons->view_selectors != 0)
#line 292 "matchcom.pcc"
) {
         
#line 293 "matchcom.pcc"
       
#line 293 "matchcom.pcc"
#line 325 "matchcom.pcc"
         {
            int _V1 = arity_of(cons->ty);
            Ty _V2 = deref(cons->ty);
            switch (_V1) {
               case 0: {
#line 294 "matchcom.pcc"
                 bug ("decor_view()"); 
#line 294 "matchcom.pcc"
               } break;
               case 1: {
#line 296 "matchcom.pcc"
                 decor(pat,view_selector_of(cons,pat,sel,cons->ty),
                  polarity,visible,E,match_rule); 
#line 297 "matchcom.pcc"
               } break;
               default: {
                  if (pat) {
                     switch (pat->tag__) {
                        case a_Pat::tag_TUPLEpat: {
                           if (_V2) {
                              switch (_V2->tag__) {
                                 case a_Ty::tag_TYCONty: {
                                    if (boxed(((Ty_TYCONty *)_V2)->_1)) {
                                       L11:; 
#line 325 "matchcom.pcc"
                                      error ("%Lbad view constructor pattern: %p", pat); 
#line 325 "matchcom.pcc"
                                    } else {
                                       switch ((int)((Ty_TYCONty *)_V2)->_1) {
                                          case ((int)TUPLEtycon): {
#line 299 "matchcom.pcc"
                                           int i;
                                             
#line 300 "matchcom.pcc"
a_List<Pat> *  
#line 300 "matchcom.pcc"
                                            pat_list;
                                             a_List<Ty> *  
#line 301 "matchcom.pcc"
                                           ty_list;
                                             for (i = 0, pat_list = ((Pat_TUPLEpat *)pat)->TUPLEpat, ty_list = ((Ty_TYCONty *)_V2)->_2; 
                                                  pat_list && ty_list;
                                                  pat_list = pat_list->_2, ty_list = ty_list->_2)
                                             {  decor(pat_list->_1,view_selector_of(cons,pat,sel,ty_list->_1),
                                                      polarity,visible,E,match_rule);
                                                i++;
                                             }
                                             } break;
                                          default: { goto L11; } break;
                                       }
                                    }
                                    } break;
                                 default: { goto L11; } break;
                              }
                           } else { goto L11; }
                           } break;
                        case a_Pat::tag_RECORDpat: {
                           if (_V2) {
                              switch (_V2->tag__) {
                                 case a_Ty::tag_TYCONty: {
                                    if (boxed(((Ty_TYCONty *)_V2)->_1)) {
                                       switch (((Ty_TYCONty *)_V2)->_1->tag__) {
                                          case a_TyCon::tag_RECORDtycon: {
#line 311 "matchcom.pcc"
                                           for_each (LabPat, p, ((Pat_RECORDpat *)pat)->_1)
                                             {  int i;
                                                
#line 313 "matchcom.pcc"
a_List<Id> *  
#line 313 "matchcom.pcc"
                                            lab_list;
                                             a_List<Ty> *  
#line 314 "matchcom.pcc"
                                            ty_list;
                                             for (i = 0, lab_list = ((TyCon_RECORDtycon *)((Ty_TYCONty *)_V2)->_1)->_1, ty_list = ((Ty_TYCONty *)_V2)->_2; 
                                                  lab_list && ty_list;
                                                  lab_list = lab_list->_2, ty_list = ty_list->_2, i++)
                                             {  if (lab_list->_1 == p.label) 
                                                   decor(p.pat,view_selector_of(cons,pat,sel,ty_list->_1),
                                                         polarity,visible,E,match_rule);
                                             }
                                             }
                                             } break;
                                          default: { goto L11; } break;
                                       }
                                    } else { goto L11; }
                                    } break;
                                 default: { goto L11; } break;
                              }
                           } else { goto L11; }
                           } break;
                        default: { goto L11; } break;
                     }
                  } else { goto L11; }
               }
            }
         }
#line 326 "matchcom.pcc"
#line 326 "matchcom.pcc"
         
         
#line 327 "matchcom.pcc"
      } else {
         
#line 329 "matchcom.pcc"
        error ("%Lmissing view selector for pattern: %p", pat); 
#line 329 "matchcom.pcc"
      }
   } else {}
}
#line 331 "matchcom.pcc"
#line 331 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Decorate patterns with selector bindings.
//
///////////////////////////////////////////////////////////////////////////////
void decor
   (Pat pat, Exp sel, Polarity polarity, Bool visible, PatternVarEnv& E,
    int& match_rule) 
{  for(;;) {
      if (! boxed(pat)) return;
      pat->selector = sel; // annotate selector
      
#line 345 "matchcom.pcc"
#line 457 "matchcom.pcc"
{
   if (pat) {
      switch (pat->tag__) {
         case a_Pat::tag_IDpat: {
#line 361 "matchcom.pcc"
          if (visible) 
            {  Exp exp = E.add(((Pat_IDpat *)pat)->_1,sel,((Pat_IDpat *)pat)->_2,polarity); 
               if (E.separate_guard() && ! E.tree_grammar() && exp != NOexp) 
                  E.add_guard(EQexp(((Pat_IDpat *)pat)->_2,sel,exp));
               else 
                  ((Pat_IDpat *)pat)->_3 = exp;
            }
            return; 
            
#line 369 "matchcom.pcc"
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
                                          if (
#line 435 "matchcom.pcc"
                                          (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty)->_1)->qualifiers & QUALview)
#line 435 "matchcom.pcc"
) {
                                             
#line 436 "matchcom.pcc"
                                           decor_view (((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat,((Pat_APPpat *)pat)->_2,sel,polarity,visible,E,match_rule); return; 
#line 436 "matchcom.pcc"
                                          } else {
                                             
                                             L12:; 
#line 438 "matchcom.pcc"
                                           decor(((Pat_APPpat *)pat)->_2,select(sel,((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat),polarity,visible,E,match_rule); return; 
#line 438 "matchcom.pcc"
                                          }
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
                  default: {
                     L13:; 
#line 457 "matchcom.pcc"
                    bug("decor()"); 
#line 457 "matchcom.pcc"
                     } break;
               }
            } else { goto L13; }
            } break;
         case a_Pat::tag_TYPEDpat: {
#line 383 "matchcom.pcc"
           pat = ((Pat_TYPEDpat *)pat)->_1; 
#line 383 "matchcom.pcc"
            } break;
         case a_Pat::tag_ASpat: {
#line 371 "matchcom.pcc"
          if (visible) 
            {  Exp exp = E.add(((Pat_ASpat *)pat)->_1,sel,((Pat_ASpat *)pat)->_3,polarity); 
               if (E.separate_guard() && ! E.tree_grammar() && exp != NOexp) 
                  E.add_guard(EQexp(((Pat_ASpat *)pat)->_3,sel,exp));
               else 
                  ((Pat_ASpat *)pat)->_4 = exp;
            }
            pat = ((Pat_ASpat *)pat)->_2; 
            
#line 379 "matchcom.pcc"
            } break;
         case a_Pat::tag_CONTEXTpat: {
#line 382 "matchcom.pcc"
           pat = ((Pat_CONTEXTpat *)pat)->_2; 
#line 382 "matchcom.pcc"
            } break;
         case a_Pat::tag_LEXEMEpat: {
            if (
#line 347 "matchcom.pcc"
            ((Pat_LEXEMEpat *)pat)->_4
#line 347 "matchcom.pcc"
) {
               
#line 349 "matchcom.pcc"
             if (visible)
               {  Ty t = NOty;
                  Exp binding =
                     CASTexp(((Pat_LEXEMEpat *)pat)->_2, BINOPexp("+",IDexp("rule__"),
                             LITERALexp(INTlit(((Pat_LEXEMEpat *)pat)->_4[0]->tag + 256 - 1 - match_rule))));
                  E.add(
#line 354 "matchcom.pcc"
#line 354 "matchcom.pcc"
               _m_a_t_c_h_c_o_mco_c_c_Q1
#line 354 "matchcom.pcc"
#line 354 "matchcom.pcc"
               , binding, t, polarity); 
               match_rule += ((Pat_LEXEMEpat *)pat)->_3 - 1;
               }
               return;
               
#line 358 "matchcom.pcc"
            } else {
               
#line 359 "matchcom.pcc"
              return; 
#line 359 "matchcom.pcc"
            }
            } break;
         case a_Pat::tag_ARRAYpat: {
#line 402 "matchcom.pcc"
          int i = 0;
            for_each (Pat,p,((Pat_ARRAYpat *)pat)->_1)
            {  decor(p,INDEXexp(sel,LITERALexp(INTlit(i))),polarity,visible,E,
                     match_rule);
               i++;
            }
            return;
            
#line 409 "matchcom.pcc"
            } break;
         case a_Pat::tag_TUPLEpat: {
#line 386 "matchcom.pcc"
          int i = 1;
            for_each (Pat,p,((Pat_TUPLEpat *)pat)->TUPLEpat)
            {  decor(p,DOTexp(sel,index_of(i)),polarity,visible,E,match_rule);
               i++;
            }
            return;
            
#line 392 "matchcom.pcc"
            } break;
         case a_Pat::tag_EXTUPLEpat: {
#line 394 "matchcom.pcc"
          int i = 1;
            for_each (Pat,p,((Pat_EXTUPLEpat *)pat)->EXTUPLEpat)
            {  decor(p,DOTexp(sel,index_of(i)),polarity,visible,E,match_rule);
               i++;
            }
            return;
            
#line 400 "matchcom.pcc"
            } break;
         case a_Pat::tag_RECORDpat: {
#line 428 "matchcom.pcc"
          for_each (LabPat,lab_pat,((Pat_RECORDpat *)pat)->_1)
            decor(lab_pat.pat, DOTexp(sel,lab_pat.label),
                  polarity, visible, E, match_rule);
            return;
            
#line 432 "matchcom.pcc"
            } break;
         case a_Pat::tag_LISTpat: {
#line 450 "matchcom.pcc"
          for_each (Pat, apat, ((Pat_LISTpat *)pat)->head)
            {  decor(apat,DOTexp(select(sel,((Pat_LISTpat *)pat)->cons),"_1"),polarity,visible,
                     E,match_rule);
               sel = DOTexp(select(sel,((Pat_LISTpat *)pat)->cons),"_2");
            }
            pat = ((Pat_LISTpat *)pat)->tail;
            
#line 456 "matchcom.pcc"
            } break;
         case a_Pat::tag_VECTORpat: {
#line 411 "matchcom.pcc"
          int i       = 0;
            Exp s       = select(sel,((Pat_VECTORpat *)pat)->cons);
            Exp len_exp = DOTexp(s,"len()");
            int n       = length(((Pat_VECTORpat *)pat)->elements);
            for_each (Pat,p,((Pat_VECTORpat *)pat)->elements)
            {  Exp index_exp = 
                 ((Pat_VECTORpat *)pat)->head_flex ? BINOPexp("-",len_exp,LITERALexp(INTlit(n-i)))
                           : LITERALexp(INTlit(i));
               decor(p,APPexp(DOTexp(s,"at"),index_exp),polarity,visible,E,
                     match_rule);
               i++;
            }
            decor(((Pat_VECTORpat *)pat)->len,len_exp,polarity,visible,E,match_rule);
            decor(((Pat_VECTORpat *)pat)->array,DOTexp(s,"array()"),polarity,visible,E,match_rule);
            return;
            
#line 426 "matchcom.pcc"
            } break;
         case a_Pat::tag_GUARDpat: {
#line 384 "matchcom.pcc"
           pat = ((Pat_GUARDpat *)pat)->_1; 
#line 384 "matchcom.pcc"
            } break;
         case a_Pat::tag_LOGICALpat: {
            switch (((Pat_LOGICALpat *)pat)->_1) {
               case NOTpat: {
#line 439 "matchcom.pcc"
                 polarity = rev(polarity); pat = ((Pat_LOGICALpat *)pat)->_2; 
#line 439 "matchcom.pcc"
                  } break;
               case ANDpat: {
#line 441 "matchcom.pcc"
                 decor(((Pat_LOGICALpat *)pat)->_2,sel,polarity,visible,E,match_rule); pat = ((Pat_LOGICALpat *)pat)->_3; 
#line 441 "matchcom.pcc"
                  } break;
               case ORpat: {
#line 442 "matchcom.pcc"
                 decor(((Pat_LOGICALpat *)pat)->_2,sel,polarity,false,E,match_rule);
                  pat = ((Pat_LOGICALpat *)pat)->_3; visible = false;
                  
#line 444 "matchcom.pcc"
                  } break;
               default: {
#line 446 "matchcom.pcc"
                decor(((Pat_LOGICALpat *)pat)->_2,sel,ISneither,false,E,match_rule);
                  pat = ((Pat_LOGICALpat *)pat)->_3; visible = false; polarity = ISneither;
                  
#line 448 "matchcom.pcc"
                  } break;
            }
            } break;
         case a_Pat::tag_UNIFYpat: {
#line 381 "matchcom.pcc"
           pat = ((Pat_UNIFYpat *)pat)->_1; 
#line 381 "matchcom.pcc"
            } break;
         case a_Pat::tag_MARKEDpat: {
#line 380 "matchcom.pcc"
           pat = ((Pat_MARKEDpat *)pat)->_2; 
#line 380 "matchcom.pcc"
            } break;
         case a_Pat::tag_WILDpat:
         case a_Pat::tag_CONSpat:
         case a_Pat::tag_LITERALpat: {
            L14:; 
#line 346 "matchcom.pcc"
           return; 
#line 346 "matchcom.pcc"
            } break;
         default: { goto L13; } break;
      }
   } else { goto L14; }
}
#line 458 "matchcom.pcc"
#line 458 "matchcom.pcc"

   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Decorate a pattern list with bindings.
//
///////////////////////////////////////////////////////////////////////////////
void decor
   (MatchExps exps, Pat pat, Polarity polarity, Bool visible, 
    PatternVarEnv& E, int& match_rule)
{ 
   int arity = length(exps);
   if (arity == 1) {  
      
#line 473 "matchcom.pcc"
#line 475 "matchcom.pcc"
{
   MatchExp _V3 = exps->_1;
#line 475 "matchcom.pcc"
 decor(pat,_V3->_2 ? IDexp(_V3->_2) : _V3->_1, polarity, visible, E, match_rule); 
#line 475 "matchcom.pcc"
}
#line 476 "matchcom.pcc"
#line 476 "matchcom.pcc"

   } else {
      
#line 478 "matchcom.pcc"
#line 509 "matchcom.pcc"
{
   if (pat) {
      switch (pat->tag__) {
         case a_Pat::tag_WILDpat: {
#line 479 "matchcom.pcc"
           /* skip */ 
#line 479 "matchcom.pcc"
            } break;
         case a_Pat::tag_CONTEXTpat: {
#line 481 "matchcom.pcc"
           decor(exps,((Pat_CONTEXTpat *)pat)->_2,polarity,visible,E,match_rule); 
#line 481 "matchcom.pcc"
            } break;
         case a_Pat::tag_TUPLEpat: {
            if (
#line 482 "matchcom.pcc"
            (length(((Pat_TUPLEpat *)pat)->TUPLEpat) == arity)
#line 482 "matchcom.pcc"
) {
               
#line 483 "matchcom.pcc"
             Pats      ps;
               MatchExps es;
               for (ps = ((Pat_TUPLEpat *)pat)->TUPLEpat, es = exps; ps; ps = ps->_2, es = es->_2) 
               {  
#line 486 "matchcom.pcc"
#line 490 "matchcom.pcc"
               {
                  MatchExp _V4 = es->_1;
#line 488 "matchcom.pcc"
                 decor(ps->_1,_V4->_2 ? IDexp(_V4->_2) : _V4->_1, polarity, 
                  visible, E, match_rule); 
                  
#line 490 "matchcom.pcc"
               }
#line 491 "matchcom.pcc"
#line 491 "matchcom.pcc"
               
               }
               
#line 493 "matchcom.pcc"
            } else {
               
               L15:; 
#line 508 "matchcom.pcc"
              error ("%Larity mismatch (expecting %i) in pattern: %p\n",
               arity, pat); 
#line 509 "matchcom.pcc"
            }
            } break;
         case a_Pat::tag_LOGICALpat: {
            switch (((Pat_LOGICALpat *)pat)->_1) {
               case NOTpat: {
#line 495 "matchcom.pcc"
                decor(exps,((Pat_LOGICALpat *)pat)->_2,rev(polarity),false,E,match_rule); 
#line 495 "matchcom.pcc"
                  } break;
               case ANDpat: {
#line 497 "matchcom.pcc"
                decor(exps,((Pat_LOGICALpat *)pat)->_2,polarity,visible,E,match_rule); 
                  decor(exps,((Pat_LOGICALpat *)pat)->_3,polarity,visible,E,match_rule); 
                  
#line 499 "matchcom.pcc"
                  } break;
               case ORpat: {
#line 501 "matchcom.pcc"
                decor(exps,((Pat_LOGICALpat *)pat)->_2,polarity,false,E,match_rule); 
                  decor(exps,((Pat_LOGICALpat *)pat)->_3,polarity,false,E,match_rule); 
                  
#line 503 "matchcom.pcc"
                  } break;
               default: {
#line 505 "matchcom.pcc"
                decor(exps,((Pat_LOGICALpat *)pat)->_2,ISneither,false,E,match_rule); 
                  decor(exps,((Pat_LOGICALpat *)pat)->_3,ISneither,false,E,match_rule); 
                  
#line 507 "matchcom.pcc"
                  } break;
            }
            } break;
         case a_Pat::tag_MARKEDpat: {
#line 480 "matchcom.pcc"
           decor(exps,((Pat_MARKEDpat *)pat)->_2,polarity,visible,E,match_rule); 
#line 480 "matchcom.pcc"
            } break;
         default: { goto L15; } break;
      }
   } else { goto L15; }
}
#line 510 "matchcom.pcc"
#line 510 "matchcom.pcc"

   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Return the arity of a pattern
//
///////////////////////////////////////////////////////////////////////////////
#line 519 "matchcom.pcc"
#line 533 "matchcom.pcc"
int arity_of (Pat x_1);
int arity_of (Pat x_1)
{
   if (x_1) {
      switch (x_1->tag__) {
         case a_Pat::tag_CONTEXTpat: {
#line 523 "matchcom.pcc"
            return arity_of(((Pat_CONTEXTpat *)x_1)->_2);
#line 524 "matchcom.pcc"
            } break;
         case a_Pat::tag_TUPLEpat: {
#line 519 "matchcom.pcc"
            return length(((Pat_TUPLEpat *)x_1)->TUPLEpat);
#line 520 "matchcom.pcc"
            } break;
         case a_Pat::tag_RECORDpat: {
            if ((! ((Pat_RECORDpat *)x_1)->_2)) {
               
#line 520 "matchcom.pcc"
               return length(((Pat_RECORDpat *)x_1)->_1);
#line 521 "matchcom.pcc"
            } else {
               
#line 531 "matchcom.pcc"
              error ("%Lillegal incomplete record pattern: %p\n",x_1); return 0; 
#line 531 "matchcom.pcc"
            }
            } break;
         case a_Pat::tag_LOGICALpat: {
            switch (((Pat_LOGICALpat *)x_1)->_1) {
               case NOTpat: {
#line 522 "matchcom.pcc"
                  return arity_of(((Pat_LOGICALpat *)x_1)->_2);
#line 523 "matchcom.pcc"
                  } break;
               default: {
#line 525 "matchcom.pcc"
                int i = arity_of(((Pat_LOGICALpat *)x_1)->_2); 
                  int j = arity_of(((Pat_LOGICALpat *)x_1)->_3); 
                  if (i != j) error ("%Larity mismatch in logical pattern: %p\n",x_1);
                  return i;
                  
#line 529 "matchcom.pcc"
                  } break;
            }
            } break;
         case a_Pat::tag_MARKEDpat: {
#line 521 "matchcom.pcc"
            return arity_of(((Pat_MARKEDpat *)x_1)->_2);
#line 522 "matchcom.pcc"
            } break;
         default: {
            L16:; 
#line 532 "matchcom.pcc"
           return 1; 
#line 532 "matchcom.pcc"
            } break;
      }
   } else { goto L16; }
}
#line 533 "matchcom.pcc"
#line 533 "matchcom.pcc"


///////////////////////////////////////////////////////////////////////////////
//
//  Make a list of match expressions
//
///////////////////////////////////////////////////////////////////////////////
MatchExps make_match_exps(int i, int n, int j)
{  if (i > n) return 
#line 541 "matchcom.pcc"
#line 541 "matchcom.pcc"
nil_1_
#line 541 "matchcom.pcc"
#line 541 "matchcom.pcc"
;
   else {
      Exp e = j < 0 ? IDexp(index_of(i,"x")) : RELexp(j);
      return 
#line 544 "matchcom.pcc"
#line 544 "matchcom.pcc"
list_1_(MATCHexp(e,nil_1_),make_match_exps((i + 1),n,j))
#line 544 "matchcom.pcc"
#line 544 "matchcom.pcc"
;
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Main decoration routine
//
///////////////////////////////////////////////////////////////////////////////
void decor(MatchExps& exps, Pat pat, PatternVarEnv& E, int& match_rule, int i)
{  if (exps == 
#line 554 "matchcom.pcc"
#line 554 "matchcom.pcc"
nil_1_
#line 554 "matchcom.pcc"
#line 554 "matchcom.pcc"
)  // create default match expressions if there are none
      exps = make_match_exps(1,arity_of(pat), i);
   decor(exps,pat,ISpositive,true,E,match_rule); 
}

///////////////////////////////////////////////////////////////////////////////
//
//  Translate a string literal into a character array pattern. 
//
///////////////////////////////////////////////////////////////////////////////
#line 564 "matchcom.pcc"
a_List<Pat> *  
#line 564 "matchcom.pcc"
 make_string_pattern (const char * string)
{  if (string[0] == '\"' && string[1] == '\0') {
      return 
#line 566 "matchcom.pcc"
list_1_(LITERALpat(CHARlit('\000')))
#line 566 "matchcom.pcc"
#line 566 "matchcom.pcc"
;
   } else {
      char c;
      const char * next_pos = parse_char(string,c);
      
#line 570 "matchcom.pcc"
a_List<Pat> *  
#line 570 "matchcom.pcc"
 pats        = make_string_pattern(next_pos);
      return 
#line 571 "matchcom.pcc"
list_1_(LITERALpat(CHARlit(c)),pats)
#line 571 "matchcom.pcc"
#line 571 "matchcom.pcc"
;
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Translate a pattern into a matching tree.
//
///////////////////////////////////////////////////////////////////////////////
Match MatchCompiler::trans(Pat pat, Pos pos, Bool neg, Match yes, Match no)
{  
#line 581 "matchcom.pcc"
#line 697 "matchcom.pcc"
{
   for (;;) {
      if (pat) {
         switch (pat->tag__) {
            case a_Pat::tag_WILDpat: {
               L18:; 
#line 582 "matchcom.pcc"
              return neg ? no : yes; 
#line 582 "matchcom.pcc"
               } break;
            case a_Pat::tag_IDpat: {
               if (((Pat_IDpat *)pat)->_3) {
#line 589 "matchcom.pcc"
                return GUARDmatch(EQexp(((Pat_IDpat *)pat)->_2,pat->selector,((Pat_IDpat *)pat)->_3),
                  neg ? no : yes, neg ? yes : no); 
#line 590 "matchcom.pcc"
               } else { goto L18; }
               } break;
            case a_Pat::tag_CONSpat: {
               if (((Pat_CONSpat *)pat)->CONSpat) {
                  if (((Pat_CONSpat *)pat)->CONSpat->alg_ty) {
                     switch (((Pat_CONSpat *)pat)->CONSpat->alg_ty->tag__) {
                        case a_Ty::tag_TYCONty: {
                           if (boxed(((Ty_TYCONty *)((Pat_CONSpat *)pat)->CONSpat->alg_ty)->_1)) {
                              switch (((Ty_TYCONty *)((Pat_CONSpat *)pat)->CONSpat->alg_ty)->_1->tag__) {
                                 case a_TyCon::tag_DATATYPEtycon: {
#line 652 "matchcom.pcc"
                                  int arity = ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)pat)->CONSpat->alg_ty)->_1)->unit + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)pat)->CONSpat->alg_ty)->_1)->arg;
                                    Match * m = Matches(arity);
                                    for (int i = arity - 1; i >= 0; i--) m[i] = neg ? yes : no;
                                    m[((Pat_CONSpat *)pat)->CONSpat->tag] = neg ? no : yes;
                                    return CONSmatch(pos,pat->selector,pat->ty,((Pat_CONSpat *)pat)->CONSpat->alg_ty,arity,m,neg ? yes : no);
                                    
#line 657 "matchcom.pcc"
                                    } break;
                                 default: {
                                    L19:; 
#line 697 "matchcom.pcc"
                                   bug("MatchCompiler::trans(): %p", pat); 
#line 697 "matchcom.pcc"
                                    } break;
                              }
                           } else { goto L19; }
                           } break;
                        default: { goto L19; } break;
                     }
                  } else { goto L19; }
               } else {
                  L20:; 
#line 696 "matchcom.pcc"
                 return neg ? no : yes; 
#line 696 "matchcom.pcc"
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
#line 640 "matchcom.pcc"
                                           int arity = ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty)->_1)->unit + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty)->_1)->arg;
                                             Match * m = Matches(arity);
                                             int i;
                                             for (i = arity - 1; i >= 0; i--) m[i] = neg ? yes : no;
                                             i = ((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->tag + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty)->_1)->unit;
                                             m[i] = trans(((Pat_APPpat *)pat)->_2,POSint(i,pos),neg,yes,no);
                                             return CONSmatch(pos,pat->selector,pat->ty,((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat->alg_ty,arity,m,neg ? yes : no);
                                             
#line 647 "matchcom.pcc"
                                             } break;
                                          default: { goto L19; } break;
                                       }
                                    } else { goto L19; }
                                    } break;
                                 default: { goto L19; } break;
                              }
                           } else { goto L19; }
                        } else { goto L20; }
                        } break;
                     default: { goto L19; } break;
                  }
               } else { goto L19; }
               } break;
            case a_Pat::tag_TYPEDpat: {
#line 584 "matchcom.pcc"
              pat = ((Pat_TYPEDpat *)pat)->_1; 
#line 584 "matchcom.pcc"
               } break;
            case a_Pat::tag_ASpat: {
               if (((Pat_ASpat *)pat)->_4) {
#line 596 "matchcom.pcc"
                Exp guard = EQexp(((Pat_ASpat *)pat)->_3,pat->selector,((Pat_ASpat *)pat)->_4);
                  if (neg) no  = GUARDmatch(guard,no,yes); 
                  else     yes = GUARDmatch(guard,yes,no);
                  pat = ((Pat_ASpat *)pat)->_2;
                  
#line 600 "matchcom.pcc"
               } else {
#line 583 "matchcom.pcc"
                 pat = ((Pat_ASpat *)pat)->_2; 
#line 583 "matchcom.pcc"
               }
               } break;
            case a_Pat::tag_LITERALpat: {
#line 602 "matchcom.pcc"
              return LITERALmatch(pos,pat->selector,vec(((Pat_LITERALpat *)pat)->LITERALpat),1,vec(neg ? no : yes),
               neg ? yes : no); 
               
#line 604 "matchcom.pcc"
               } break;
            case a_Pat::tag_CONTEXTpat: {
#line 586 "matchcom.pcc"
              pat = add_contexts(((Pat_CONTEXTpat *)pat)->_1,((Pat_CONTEXTpat *)pat)->_2); 
#line 586 "matchcom.pcc"
               } break;
            case a_Pat::tag_LEXEMEpat: {
#line 587 "matchcom.pcc"
              pat = expand_lexeme_pat(pat,((Pat_LEXEMEpat *)pat)->_2,((Pat_LEXEMEpat *)pat)->_3,((Pat_LEXEMEpat *)pat)->_4); 
#line 587 "matchcom.pcc"
               } break;
            case a_Pat::tag_ARRAYpat: {
#line 623 "matchcom.pcc"
              return trans(((Pat_ARRAYpat *)pat)->_1,0,pos,neg,yes,no); 
#line 623 "matchcom.pcc"
               } break;
            case a_Pat::tag_TUPLEpat: {
#line 606 "matchcom.pcc"
             if (current_index_map) {
               HashTable::Entry * e = current_index_map->lookup(pos);
               if (e) 
                  return trans(((Pat_TUPLEpat *)pat)->TUPLEpat,pos,neg,yes,no, 
                               (int *)current_index_map->value(e)); 
               }
               return trans(((Pat_TUPLEpat *)pat)->TUPLEpat,0,pos,neg,yes,no); 
               
#line 613 "matchcom.pcc"
               } break;
            case a_Pat::tag_EXTUPLEpat: {
#line 615 "matchcom.pcc"
             if (current_index_map) {
               HashTable::Entry * e = current_index_map->lookup(pos);
               if (e) 
                  return trans(((Pat_EXTUPLEpat *)pat)->EXTUPLEpat,pos,neg,yes,no, 
                               (int *)current_index_map->value(e)); 
               }
               return trans(((Pat_EXTUPLEpat *)pat)->EXTUPLEpat,0,pos,neg,yes,no); 
               
#line 622 "matchcom.pcc"
               } break;
            case a_Pat::tag_RECORDpat: {
#line 634 "matchcom.pcc"
              return trans(((Pat_RECORDpat *)pat)->_1,pos,neg,yes,no); 
#line 634 "matchcom.pcc"
               } break;
            case a_Pat::tag_LISTpat: {
               if (((Pat_LISTpat *)pat)->cons) {
                  if (((Pat_LISTpat *)pat)->head) {
                     L21:; 
#line 685 "matchcom.pcc"
                   Pat new_tail   = 
#line 685 "matchcom.pcc"
#line 685 "matchcom.pcc"
                     LISTpat(((Pat_LISTpat *)pat)->cons, ((Pat_LISTpat *)pat)->nil, ((Pat_LISTpat *)pat)->head->_2, ((Pat_LISTpat *)pat)->tail)
#line 685 "matchcom.pcc"
#line 685 "matchcom.pcc"
                     ; 
                     Pat list_pat   = APPpat(CONSpat(((Pat_LISTpat *)pat)->cons),TUPLEpat(
#line 686 "matchcom.pcc"
#line 686 "matchcom.pcc"
                     list_1_(((Pat_LISTpat *)pat)->head->_1,list_1_(new_tail))
#line 686 "matchcom.pcc"
#line 686 "matchcom.pcc"
                     ));
                     new_tail->selector = DOTexp(select(pat->selector,((Pat_LISTpat *)pat)->cons),"_2"); 
                     list_pat->selector = pat->selector;
                     pat = list_pat;
                     
#line 690 "matchcom.pcc"
                  } else {
                     L22:; 
                     if (((Pat_LISTpat *)pat)->tail) {
                        L23:; 
#line 683 "matchcom.pcc"
                       pat = ((Pat_LISTpat *)pat)->tail; 
#line 683 "matchcom.pcc"
                     } else {
                        L24:; 
#line 682 "matchcom.pcc"
                      Pat p = CONSpat(((Pat_LISTpat *)pat)->nil); p->selector = pat->selector; pat = p; 
#line 682 "matchcom.pcc"
                     }
                  }
               } else {
                  if (((Pat_LISTpat *)pat)->head) { goto L21; } else { goto L22; }
               }
               } break;
            case a_Pat::tag_VECTORpat: {
#line 625 "matchcom.pcc"
             int low   = length(((Pat_VECTORpat *)pat)->elements);
               int high  = (((Pat_VECTORpat *)pat)->head_flex || ((Pat_VECTORpat *)pat)->tail_flex) ? INT_MAX : low; 
               int start = ((Pat_VECTORpat *)pat)->head_flex ? (INT_MAX - length(((Pat_VECTORpat *)pat)->elements)) : 0;
               Match p1 = trans(((Pat_VECTORpat *)pat)->elements,start,pos,neg,yes,no);
               Match p2 = trans(((Pat_VECTORpat *)pat)->array,pos,neg,(neg ? no : p1),(neg ? p1 : no));
               Match p3 = trans(((Pat_VECTORpat *)pat)->len,pos,neg,(neg ? no : p2),(neg ? p3 : no));
               return RANGEmatch(pos,ARROWexp(pat->selector,"len()"),low,high,
                                 (neg ? no : p3), (neg ? p3 : no)); 
               
#line 633 "matchcom.pcc"
               } break;
            case a_Pat::tag_GUARDpat: {
#line 592 "matchcom.pcc"
             Match m = trans(((Pat_GUARDpat *)pat)->_1,pos,neg,yes,no);
               return GUARDmatch(((Pat_GUARDpat *)pat)->_2, neg ? no : m, neg ? m : no); 
               
#line 594 "matchcom.pcc"
               } break;
            case a_Pat::tag_LOGICALpat: {
               switch (((Pat_LOGICALpat *)pat)->_1) {
                  case NOTpat: {
#line 659 "matchcom.pcc"
                    return trans(((Pat_LOGICALpat *)pat)->_2, pos,! neg, yes, no); 
#line 659 "matchcom.pcc"
                     } break;
                  case ANDpat: {
#line 661 "matchcom.pcc"
                    return neg ? merge(trans(((Pat_LOGICALpat *)pat)->_2,pos,neg,yes,no),trans(((Pat_LOGICALpat *)pat)->_3,pos,neg,yes,no))
                     : trans(((Pat_LOGICALpat *)pat)->_2, pos, neg, trans(((Pat_LOGICALpat *)pat)->_3, pos, neg, yes, no), no);
                     
#line 663 "matchcom.pcc"
                     } break;
                  case ORpat: {
#line 665 "matchcom.pcc"
                    return neg ? trans(((Pat_LOGICALpat *)pat)->_2, pos, neg, trans(((Pat_LOGICALpat *)pat)->_3, pos, neg, yes, no), no)
                     : merge(trans(((Pat_LOGICALpat *)pat)->_2,pos,neg,yes,no),trans(((Pat_LOGICALpat *)pat)->_3,pos,neg,yes,no));
                     
#line 667 "matchcom.pcc"
                     } break;
                  case EQUIVpat: {
#line 671 "matchcom.pcc"
                    pat = LOGICALpat(ORpat, 
                     LOGICALpat(ANDpat, ((Pat_LOGICALpat *)pat)->_2, ((Pat_LOGICALpat *)pat)->_3),
                     LOGICALpat(ANDpat, LOGICALpat(NOTpat,((Pat_LOGICALpat *)pat)->_2,NOpat),
                                        LOGICALpat(NOTpat,((Pat_LOGICALpat *)pat)->_3,NOpat)));
                     
#line 675 "matchcom.pcc"
                     } break;
                  case XORpat: {
#line 677 "matchcom.pcc"
                    pat = LOGICALpat(ORpat, 
                     LOGICALpat(ANDpat, ((Pat_LOGICALpat *)pat)->_2, LOGICALpat(NOTpat,((Pat_LOGICALpat *)pat)->_3,NOpat)),
                     LOGICALpat(ANDpat, LOGICALpat(NOTpat,((Pat_LOGICALpat *)pat)->_2,NOpat), ((Pat_LOGICALpat *)pat)->_3));
                     
#line 680 "matchcom.pcc"
                     } break;
                  default: {
#line 669 "matchcom.pcc"
                    pat = LOGICALpat(ORpat, LOGICALpat(NOTpat,((Pat_LOGICALpat *)pat)->_2,NOpat), ((Pat_LOGICALpat *)pat)->_3); 
#line 669 "matchcom.pcc"
                     } break;
               }
               } break;
            case a_Pat::tag_MARKEDpat: {
#line 585 "matchcom.pcc"
              pat = ((Pat_MARKEDpat *)pat)->_2; 
#line 585 "matchcom.pcc"
               } break;
            default: { goto L19; } break;
         }
      } else { goto L18; }
   }
}
#line 698 "matchcom.pcc"
#line 698 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Translate a pattern list into a matching tree using ranking function.
//
///////////////////////////////////////////////////////////////////////////////
Match MatchCompiler::trans
   (Pats ps, Pos pos, Bool neg, Match yes, Match no, int rank[])
{  Pat Ps[256];
   int i = 0;
   for_each (Pat, p, ps) Ps[i++] = p;
   int n = i;
   Match m = yes;
   for (i = n - 1; i >= 0; i--)
      m = trans(Ps[rank[i]], POSint(i, pos), neg, m, no);
   return m;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Translate a pattern list into a matching tree.
//
///////////////////////////////////////////////////////////////////////////////
Match MatchCompiler::trans
   (Pats ps, int i, Pos pos, Bool neg, Match yes, Match no)
{  
#line 725 "matchcom.pcc"
#line 729 "matchcom.pcc"
{
   if (ps) {
#line 727 "matchcom.pcc"
     return trans(ps->_1, POSint(i, pos), neg,
      trans(ps->_2, i+1, pos, neg, yes, no), no);
      
#line 729 "matchcom.pcc"
   } else {
#line 726 "matchcom.pcc"
     return yes; 
#line 726 "matchcom.pcc"
   }
}
#line 730 "matchcom.pcc"
#line 730 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Translate a labeled pattern list into a matching tree.
//
///////////////////////////////////////////////////////////////////////////////
Match MatchCompiler::trans
   (LabPats ps, Pos pos, Bool neg, Match yes, Match no)
{  
#line 740 "matchcom.pcc"
#line 744 "matchcom.pcc"
{
   if (ps) {
#line 742 "matchcom.pcc"
     return trans(ps->_1.pat, POSlabel(ps->_1.label, pos), neg,
      trans(ps->_2, pos, neg, yes, no), no);
      
#line 744 "matchcom.pcc"
   } else {
#line 741 "matchcom.pcc"
     return yes; 
#line 741 "matchcom.pcc"
   }
}
#line 745 "matchcom.pcc"
#line 745 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Get the position list of a matching tree node.
//
///////////////////////////////////////////////////////////////////////////////
#line 753 "matchcom.pcc"
#line 759 "matchcom.pcc"
Pos get_pos (Match x_1);
Pos get_pos (Match x_1)
{
   if (boxed(x_1)) {
      switch (x_1->tag__) {
         case a_Match::tag_LITERALmatch: {
#line 753 "matchcom.pcc"
           return ((Match_LITERALmatch *)x_1)->_1; 
#line 753 "matchcom.pcc"
            } break;
         case a_Match::tag_RANGEmatch: {
#line 754 "matchcom.pcc"
           return ((Match_RANGEmatch *)x_1)->_1; 
#line 754 "matchcom.pcc"
            } break;
         case a_Match::tag_CONSmatch: {
#line 755 "matchcom.pcc"
           return ((Match_CONSmatch *)x_1)->_1; 
#line 755 "matchcom.pcc"
            } break;
         case a_Match::tag_SUCCESSmatch:
         case a_Match::tag_SUCCESSESmatch:
         case a_Match::tag_COSTmatch: {
#line 757 "matchcom.pcc"
           return POSinfinity; 
#line 757 "matchcom.pcc"
            } break;
         default: {
            L25:; 
#line 758 "matchcom.pcc"
           return POSzero; 
#line 758 "matchcom.pcc"
            } break;
      }
   } else { goto L25; }
}
#line 759 "matchcom.pcc"
#line 759 "matchcom.pcc"


///////////////////////////////////////////////////////////////////////////////
//
//  Position list comparison result.
//
///////////////////////////////////////////////////////////////////////////////
#line 766 "matchcom.pcc"
#line 766 "matchcom.pcc"
enum CompareResult {
   LESS = 0, SAME = 1, MORE = 2, 
   NEITHER = 3
};




#line 766 "matchcom.pcc"
#line 766 "matchcom.pcc"


///////////////////////////////////////////////////////////////////////////////
//
//  Compare two position lists lexicographically.
//
///////////////////////////////////////////////////////////////////////////////
CompareResult compare_pos(Pos a, Pos b)
{  Pos u, v;
   
#line 775 "matchcom.pcc"
#line 808 "matchcom.pcc"
{
   if (
#line 776 "matchcom.pcc"
   (a == b)
#line 776 "matchcom.pcc"
) {
      
#line 776 "matchcom.pcc"
     return SAME; 
#line 776 "matchcom.pcc"
   } else {
      
      if (boxed(a)) {
         switch (untagp(a)) {
            case a_Pos::tag_POSint: {
               if (boxed(b)) {
                  switch (untagp(b)) {
                     case a_Pos::tag_POSint: {
#line 788 "matchcom.pcc"
                      CompareResult r = compare_pos(((Pos_POSint *)a)->_2,((Pos_POSint *)b)->_2);
                        if (r != SAME) return r; 
                        if (((Pos_POSint *)a)->_1 == ((Pos_POSint *)b)->_1) return SAME;
                        if (((Pos_POSint *)a)->_1 <  ((Pos_POSint *)b)->_1)  return LESS;
                        return MORE;
                        
#line 793 "matchcom.pcc"
                        } break;
                     case a_Pos::tag_POSlabel: {
#line 781 "matchcom.pcc"
                       u = ((Pos_POSint *)a)->_2; v = ((Pos_POSlabel *)derefp(b))->_2; 
#line 781 "matchcom.pcc"
                        } break;
                     default: {
#line 782 "matchcom.pcc"
                       u = ((Pos_POSint *)a)->_2; v = ((Pos_POSadaptive *)derefp(b))->_3; 
#line 782 "matchcom.pcc"
                        } break;
                  }
               } else {
                  if (b) {
                     
                     L26:; 
#line 780 "matchcom.pcc"
                    return LESS; 
#line 780 "matchcom.pcc"
                  } else {
                     
                     L27:; 
#line 778 "matchcom.pcc"
                    return MORE; 
#line 778 "matchcom.pcc"
                  }
               }
               } break;
            case a_Pos::tag_POSlabel: {
               if (boxed(b)) {
                  switch (untagp(b)) {
                     case a_Pos::tag_POSint: {
#line 783 "matchcom.pcc"
                       u = ((Pos_POSlabel *)derefp(a))->_2; v = ((Pos_POSint *)b)->_2; 
#line 783 "matchcom.pcc"
                        } break;
                     case a_Pos::tag_POSlabel: {
#line 795 "matchcom.pcc"
                      CompareResult r = compare_pos(((Pos_POSlabel *)derefp(a))->_2,((Pos_POSlabel *)derefp(b))->_2);
                        if (r != SAME) return r; 
                        int s = strcmp(((Pos_POSlabel *)derefp(a))->_1,((Pos_POSlabel *)derefp(b))->_1);
                        if (s == 0) return SAME;
                        if (s < 0)  return LESS;
                        return MORE;
                        
#line 801 "matchcom.pcc"
                        } break;
                     default: {
#line 784 "matchcom.pcc"
                       u = ((Pos_POSlabel *)derefp(a))->_2; v = ((Pos_POSadaptive *)derefp(b))->_3; 
#line 784 "matchcom.pcc"
                        } break;
                  }
               } else {
                  if (b) {
                      goto L26; } else {
                      goto L27; }
               }
               } break;
            default: {
               if (boxed(b)) {
                  switch (untagp(b)) {
                     case a_Pos::tag_POSint: {
#line 785 "matchcom.pcc"
                       u = ((Pos_POSint *)b)->_2; v = ((Pos_POSadaptive *)derefp(a))->_3; 
#line 785 "matchcom.pcc"
                        } break;
                     case a_Pos::tag_POSlabel: {
#line 786 "matchcom.pcc"
                       u = ((Pos_POSlabel *)derefp(b))->_2; v = ((Pos_POSadaptive *)derefp(a))->_3; 
#line 786 "matchcom.pcc"
                        } break;
                     default: {
#line 803 "matchcom.pcc"
                      CompareResult r = compare_pos(((Pos_POSadaptive *)derefp(a))->_3,((Pos_POSadaptive *)derefp(b))->_3);
                        if (r != SAME) return r; 
                        if (((Pos_POSadaptive *)derefp(a))->_2[((Pos_POSadaptive *)derefp(a))->_1] == ((Pos_POSadaptive *)derefp(b))->_2[((Pos_POSadaptive *)derefp(b))->_1]) return SAME;
                        if (((Pos_POSadaptive *)derefp(a))->_2[((Pos_POSadaptive *)derefp(a))->_1] <  ((Pos_POSadaptive *)derefp(b))->_2[((Pos_POSadaptive *)derefp(b))->_1]) return LESS;
                        return MORE;
                        
#line 808 "matchcom.pcc"
                        } break;
                  }
               } else {
                  if (b) {
                      goto L26; } else {
                      goto L27; }
               }
               } break;
         }
      } else {
         if (a) {
            
            if (boxed(b)) {
               L28:; 
#line 779 "matchcom.pcc"
              return MORE; 
#line 779 "matchcom.pcc"
            } else {
               if (b) {
                   goto L28; } else {
                   goto L27; }
            }
         } else {
            
#line 777 "matchcom.pcc"
           return LESS; 
#line 777 "matchcom.pcc"
         }
      }
   }
}
#line 809 "matchcom.pcc"
#line 809 "matchcom.pcc"

   
   CompareResult r = compare_pos(u,v);
   if (r != SAME) return r; 
   return NEITHER;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Compare two position lists lexicographically.
//
///////////////////////////////////////////////////////////////////////////////
Bool pos_equal(HashTable::Key p, HashTable::Key q)
{  return compare_pos((Pos)p, (Pos)q) == SAME; }

///////////////////////////////////////////////////////////////////////////////
//
//  Compare two literals.
//
///////////////////////////////////////////////////////////////////////////////
#line 829 "matchcom.pcc"
#line 838 "matchcom.pcc"
int compare_literals (Literal x_1, Literal x_2);
int compare_literals (Literal x_1, Literal x_2)
{
   switch (x_1->tag__) {
      case a_Literal::tag_INTlit: {
         switch (x_2->tag__) {
            case a_Literal::tag_INTlit: {
#line 829 "matchcom.pcc"
              return ((Literal_INTlit *)x_1)->INTlit - ((Literal_INTlit *)x_2)->INTlit; 
#line 829 "matchcom.pcc"
               } break;
            default: {
               L29:; 
#line 837 "matchcom.pcc"
              return 1; 
#line 837 "matchcom.pcc"
               } break;
         }
         } break;
      case a_Literal::tag_BOOLlit: {
         switch (x_2->tag__) {
            case a_Literal::tag_BOOLlit: {
#line 832 "matchcom.pcc"
              return ((Literal_BOOLlit *)x_1)->BOOLlit - ((Literal_BOOLlit *)x_2)->BOOLlit; 
#line 832 "matchcom.pcc"
               } break;
            default: { goto L29; } break;
         }
         } break;
      case a_Literal::tag_CHARlit: {
         switch (x_2->tag__) {
            case a_Literal::tag_CHARlit: {
#line 831 "matchcom.pcc"
              return (int)((Literal_CHARlit *)x_1)->CHARlit - (int)((Literal_CHARlit *)x_2)->CHARlit; 
#line 831 "matchcom.pcc"
               } break;
            default: { goto L29; } break;
         }
         } break;
      case a_Literal::tag_REALlit: {
         switch (x_2->tag__) {
            case a_Literal::tag_REALlit: {
#line 830 "matchcom.pcc"
              return ((Literal_REALlit *)x_1)->REALlit < ((Literal_REALlit *)x_2)->REALlit ? -1 : (((Literal_REALlit *)x_1)->REALlit > ((Literal_REALlit *)x_2)->REALlit ? 1 : 0); 
#line 830 "matchcom.pcc"
               } break;
            default: { goto L29; } break;
         }
         } break;
      case a_Literal::tag_STRINGlit: {
         switch (x_2->tag__) {
            case a_Literal::tag_STRINGlit: {
#line 833 "matchcom.pcc"
              return strcmp(((Literal_STRINGlit *)x_1)->STRINGlit,((Literal_STRINGlit *)x_2)->STRINGlit); 
#line 833 "matchcom.pcc"
               } break;
            default: { goto L29; } break;
         }
         } break;
      case a_Literal::tag_REGEXPlit: {
         switch (x_2->tag__) {
            case a_Literal::tag_REGEXPlit: {
#line 834 "matchcom.pcc"
              return strcmp(((Literal_REGEXPlit *)x_1)->REGEXPlit,((Literal_REGEXPlit *)x_2)->REGEXPlit); 
#line 834 "matchcom.pcc"
               } break;
            default: { goto L29; } break;
         }
         } break;
      case a_Literal::tag_QUARKlit: {
         switch (x_2->tag__) {
            case a_Literal::tag_QUARKlit: {
#line 835 "matchcom.pcc"
              return strcmp(((Literal_QUARKlit *)x_1)->QUARKlit,((Literal_QUARKlit *)x_2)->QUARKlit); 
#line 835 "matchcom.pcc"
               } break;
            default: { goto L29; } break;
         }
         } break;
      default: {
         switch (x_2->tag__) {
            case a_Literal::tag_BIGINTlit: {
#line 836 "matchcom.pcc"
              return strcmp(((Literal_BIGINTlit *)x_1)->BIGINTlit,((Literal_BIGINTlit *)x_2)->BIGINTlit); 
#line 836 "matchcom.pcc"
               } break;
            default: { goto L29; } break;
         }
         } break;
   }
}
#line 838 "matchcom.pcc"
#line 838 "matchcom.pcc"


///////////////////////////////////////////////////////////////////////////////
//
//  Compare two expressions.
//
///////////////////////////////////////////////////////////////////////////////
Bool equal (Exp a, Exp b)
{  
#line 846 "matchcom.pcc"
#line 881 "matchcom.pcc"
{
   for (;;) {
      if (
#line 847 "matchcom.pcc"
      (a == b)
#line 847 "matchcom.pcc"
) {
         
#line 847 "matchcom.pcc"
        return true; 
#line 847 "matchcom.pcc"
      } else {
         
         if (a) {
            switch (a->tag__) {
               case a_Exp::tag_LITERALexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_LITERALexp: {
#line 848 "matchcom.pcc"
                          return compare_literals(((Exp_LITERALexp *)a)->LITERALexp,((Exp_LITERALexp *)b)->LITERALexp)==0; 
#line 848 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: {
                           L31:; 
#line 880 "matchcom.pcc"
                          b = ((Exp_MARKEDexp *)b)->_2; 
#line 880 "matchcom.pcc"
                           } break;
                        default: {
                           L32:; 
#line 881 "matchcom.pcc"
                          return false; 
#line 881 "matchcom.pcc"
                           } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_IDexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_IDexp: {
#line 849 "matchcom.pcc"
                          return ((Exp_IDexp *)a)->IDexp == ((Exp_IDexp *)b)->IDexp; 
#line 849 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_RELexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_RELexp: {
#line 850 "matchcom.pcc"
                          return same_selectors || ((Exp_RELexp *)a)->RELexp == ((Exp_RELexp *)b)->RELexp; 
#line 850 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_DOTexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_DOTexp: {
#line 851 "matchcom.pcc"
                          return ((Exp_DOTexp *)a)->_2 == ((Exp_DOTexp *)b)->_2 && equal(((Exp_DOTexp *)a)->_1,((Exp_DOTexp *)b)->_1); 
#line 851 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_SELECTORexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_SELECTORexp: {
#line 853 "matchcom.pcc"
                          return ((Exp_SELECTORexp *)a)->_2 == ((Exp_SELECTORexp *)b)->_2 && equal(((Exp_SELECTORexp *)a)->_1,((Exp_SELECTORexp *)b)->_1); 
#line 853 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_DEREFexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_DEREFexp: {
#line 854 "matchcom.pcc"
                          return equal(((Exp_DEREFexp *)a)->DEREFexp,((Exp_DEREFexp *)b)->DEREFexp); 
#line 854 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_ARROWexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_ARROWexp: {
#line 855 "matchcom.pcc"
                          return ((Exp_ARROWexp *)a)->_2 == ((Exp_ARROWexp *)b)->_2 && equal(((Exp_ARROWexp *)a)->_1,((Exp_ARROWexp *)b)->_1); 
#line 855 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_INDEXexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_INDEXexp: {
#line 856 "matchcom.pcc"
                          return equal(((Exp_INDEXexp *)a)->_1,((Exp_INDEXexp *)b)->_1) && equal(((Exp_INDEXexp *)a)->_2,((Exp_INDEXexp *)b)->_2); 
#line 856 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_BINOPexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_BINOPexp: {
#line 858 "matchcom.pcc"
                          return strcmp(((Exp_BINOPexp *)a)->_1,((Exp_BINOPexp *)b)->_1) == 0 && equal(((Exp_BINOPexp *)a)->_2,((Exp_BINOPexp *)b)->_2) && equal(((Exp_BINOPexp *)a)->_3,((Exp_BINOPexp *)b)->_3); 
#line 858 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_PREFIXexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_PREFIXexp: {
#line 859 "matchcom.pcc"
                          return !strcmp(((Exp_PREFIXexp *)a)->_1,((Exp_PREFIXexp *)b)->_1) && equal(((Exp_PREFIXexp *)a)->_2,((Exp_PREFIXexp *)b)->_2);
#line 859 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_POSTFIXexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_POSTFIXexp: {
#line 860 "matchcom.pcc"
                          return !strcmp(((Exp_POSTFIXexp *)a)->_1,((Exp_POSTFIXexp *)b)->_1) && equal(((Exp_POSTFIXexp *)a)->_2,((Exp_POSTFIXexp *)b)->_2);
#line 860 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_APPexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_APPexp: {
#line 861 "matchcom.pcc"
                          return equal(((Exp_APPexp *)a)->_1,((Exp_APPexp *)b)->_1) && equal(((Exp_APPexp *)a)->_2,((Exp_APPexp *)b)->_2); 
#line 861 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_ASSIGNexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_ASSIGNexp: {
#line 862 "matchcom.pcc"
                          return equal(((Exp_ASSIGNexp *)a)->_1,((Exp_ASSIGNexp *)b)->_1) && equal(((Exp_ASSIGNexp *)a)->_2,((Exp_ASSIGNexp *)b)->_2); 
#line 862 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_IFexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_IFexp: {
#line 864 "matchcom.pcc"
                          return equal(((Exp_IFexp *)a)->_1,((Exp_IFexp *)b)->_1) && equal(((Exp_IFexp *)a)->_2,((Exp_IFexp *)b)->_2) && equal(((Exp_IFexp *)a)->_3,((Exp_IFexp *)b)->_3); 
#line 864 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_TUPLEexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_TUPLEexp: {
#line 865 "matchcom.pcc"
                          return equal(((Exp_TUPLEexp *)a)->TUPLEexp,((Exp_TUPLEexp *)b)->TUPLEexp); 
#line 865 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_RECORDexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_RECORDexp: {
#line 866 "matchcom.pcc"
                          return equal(((Exp_RECORDexp *)a)->RECORDexp,((Exp_RECORDexp *)b)->RECORDexp); 
#line 866 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_LISTexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_LISTexp: {
#line 869 "matchcom.pcc"
                          return ((Exp_LISTexp *)a)->_1 == ((Exp_LISTexp *)b)->_1 && equal(((Exp_LISTexp *)a)->_3,((Exp_LISTexp *)b)->_3) && equal(((Exp_LISTexp *)a)->_4,((Exp_LISTexp *)b)->_4); 
#line 869 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_CONSexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_CONSexp: {
#line 870 "matchcom.pcc"
                          return ((Exp_CONSexp *)a)->_1 == ((Exp_CONSexp *)b)->_1 && equal(((Exp_CONSexp *)a)->_2,((Exp_CONSexp *)b)->_2) && equal(((Exp_CONSexp *)a)->_3,((Exp_CONSexp *)b)->_3); 
#line 870 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_EQexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_EQexp: {
#line 871 "matchcom.pcc"
                          return equal(((Exp_EQexp *)a)->_2,((Exp_EQexp *)b)->_2) && equal(((Exp_EQexp *)a)->_3,((Exp_EQexp *)b)->_3); 
#line 871 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_UNIFYexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_UNIFYexp: {
#line 872 "matchcom.pcc"
                          return equal(((Exp_UNIFYexp *)a)->_2,((Exp_UNIFYexp *)b)->_2) && equal(((Exp_UNIFYexp *)a)->_3,((Exp_UNIFYexp *)b)->_3); 
#line 872 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_LTexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_LTexp: {
#line 873 "matchcom.pcc"
                          return equal(((Exp_LTexp *)a)->_2,((Exp_LTexp *)b)->_2) && equal(((Exp_LTexp *)a)->_3,((Exp_LTexp *)b)->_3); 
#line 873 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_HASHexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_HASHexp: {
#line 874 "matchcom.pcc"
                          a = ((Exp_HASHexp *)a)->_2; b = ((Exp_HASHexp *)b)->_2; 
#line 874 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_THISCOSTexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_THISCOSTexp: {
#line 875 "matchcom.pcc"
                          return true; 
#line 875 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_COSTexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_COSTexp: {
#line 876 "matchcom.pcc"
                          return ((Exp_COSTexp *)a)->COSTexp == ((Exp_COSTexp *)b)->COSTexp; 
#line 876 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_THISSYNexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_THISSYNexp: {
#line 878 "matchcom.pcc"
                          return ((Exp_THISSYNexp *)a)->_1 == ((Exp_THISSYNexp *)b)->_1; 
#line 878 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_SYNexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_SYNexp: {
#line 877 "matchcom.pcc"
                          return ((Exp_SYNexp *)a)->_1 == ((Exp_SYNexp *)b)->_1 && ((Exp_SYNexp *)a)->_2 == ((Exp_SYNexp *)b)->_2; 
#line 877 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_SENDexp: {
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_SENDexp: {
#line 867 "matchcom.pcc"
                          return ((Exp_SENDexp *)a)->_1 == ((Exp_SENDexp *)b)->_1 && equal(((Exp_SENDexp *)a)->_2,((Exp_SENDexp *)b)->_2); 
#line 867 "matchcom.pcc"
                           } break;
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
               case a_Exp::tag_MARKEDexp: {
#line 879 "matchcom.pcc"
                 a = ((Exp_MARKEDexp *)a)->_2; 
#line 879 "matchcom.pcc"
                  } break;
               default: {
                  L33:; 
                  if (b) {
                     switch (b->tag__) {
                        case a_Exp::tag_MARKEDexp: { goto L31; } break;
                        default: { goto L32; } break;
                     }
                  } else { goto L32; }
                  } break;
            }
         } else { goto L33; }
      }
   }
}
#line 882 "matchcom.pcc"
#line 882 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Equality between two expression lists
//
///////////////////////////////////////////////////////////////////////////////
Bool equal (Exps a, Exps b)
{  
#line 891 "matchcom.pcc"
#line 893 "matchcom.pcc"
{
   for (;;) {
      if (a) {
         if (b) {
#line 893 "matchcom.pcc"
           if (! equal(a->_1, b->_1)) return false; a = a->_2; b = b->_2; 
#line 893 "matchcom.pcc"
         } else { goto L34; }
      } else { goto L34; }
   }
   L34:;
}
#line 894 "matchcom.pcc"
#line 894 "matchcom.pcc"

   return a == 
#line 895 "matchcom.pcc"
#line 895 "matchcom.pcc"
nil_1_
#line 895 "matchcom.pcc"
#line 895 "matchcom.pcc"
 && b == 
#line 895 "matchcom.pcc"
#line 895 "matchcom.pcc"
nil_1_
#line 895 "matchcom.pcc"
#line 895 "matchcom.pcc"
;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Equality between two labeled expression lists
//
///////////////////////////////////////////////////////////////////////////////
Bool equal (LabExps a, LabExps b)
{  
#line 904 "matchcom.pcc"
#line 906 "matchcom.pcc"
{
   for (;;) {
      if (a) {
         if (b) {
#line 906 "matchcom.pcc"
          if (! equal(a->_1.exp, b->_1.exp)) return false; a = a->_2; b = b->_2; 
#line 906 "matchcom.pcc"
         } else { goto L35; }
      } else { goto L35; }
   }
   L35:;
}
#line 907 "matchcom.pcc"
#line 907 "matchcom.pcc"
 
   return a == 
#line 908 "matchcom.pcc"
#line 908 "matchcom.pcc"
nil_1_
#line 908 "matchcom.pcc"
#line 908 "matchcom.pcc"
 && b == 
#line 908 "matchcom.pcc"
#line 908 "matchcom.pcc"
nil_1_
#line 908 "matchcom.pcc"
#line 908 "matchcom.pcc"
;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Check to see if we have a regular expression.
//
///////////////////////////////////////////////////////////////////////////////
Bool has_regexp(int n, Literal l[])
{  for (int i = n - 1; i >= 0; i--) 
   {  
#line 918 "matchcom.pcc"
#line 918 "matchcom.pcc"
{
   Literal _V5 = l[i];
   switch (_V5->tag__) {
      case a_Literal::tag_REGEXPlit: {
#line 918 "matchcom.pcc"
        return true; 
#line 918 "matchcom.pcc"
         } break;
      default: {
#line 918 "matchcom.pcc"
        /* skip */ 
#line 918 "matchcom.pcc"
         } break;
   }
}
#line 918 "matchcom.pcc"
#line 918 "matchcom.pcc"
 }
   return false;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Convert all string literals into regular expression literals.
//
///////////////////////////////////////////////////////////////////////////////
void convert_regexp(int n, Literal l[])
{  for (int i = n-1; i >= 0; i--) 
   {  
#line 929 "matchcom.pcc"
#line 931 "matchcom.pcc"
{
   Literal _V6 = l[i];
   switch (_V6->tag__) {
      case a_Literal::tag_STRINGlit: {
#line 930 "matchcom.pcc"
        l[i] = REGEXPlit(convert_regexp(((Literal_STRINGlit *)_V6)->STRINGlit)); 
#line 930 "matchcom.pcc"
         } break;
      default: {
#line 931 "matchcom.pcc"
        /* skip */ 
#line 931 "matchcom.pcc"
         } break;
   }
}
#line 932 "matchcom.pcc"
#line 932 "matchcom.pcc"

   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Compose two matching trees.
//
///////////////////////////////////////////////////////////////////////////////
Match MatchCompiler::compose (Match a, Match b)
{  
#line 942 "matchcom.pcc"
#line 981 "matchcom.pcc"
{
   if (boxed(a)) {
      switch (a->tag__) {
         case a_Match::tag_SUCCESSESmatch: {
            if (boxed(b)) {
               switch (b->tag__) {
                  case a_Match::tag_SUCCESSESmatch: {
#line 944 "matchcom.pcc"
                   BitSet * c = new (mem_pool, ((Match_SUCCESSESmatch *)a)->_1) BitSet;
                     c->Union(*((Match_SUCCESSESmatch *)a)->_2,*((Match_SUCCESSESmatch *)b)->_2); 
                     return SUCCESSESmatch(((Match_SUCCESSESmatch *)a)->_1,c,((Match_SUCCESSESmatch *)a)->_3);
                     
#line 947 "matchcom.pcc"
                     } break;
                  default: {
                     L36:; 
#line 981 "matchcom.pcc"
                    /* skip */ 
#line 981 "matchcom.pcc"
                     } break;
               }
            } else { goto L36; }
            } break;
         case a_Match::tag_COSTmatch: {
            if (boxed(b)) {
               switch (b->tag__) {
                  case a_Match::tag_COSTmatch: {
#line 950 "matchcom.pcc"
                   register BitSet * set = new (mem_pool, ((Match_COSTmatch *)a)->_1) BitSet;
                     set->Union (*((Match_COSTmatch *)a)->_3, *((Match_COSTmatch *)b)->_3);
                     register int min_cost = MAX_COST;
                     register int r;
                     
                     // Find the minimal known cost
                     for (r = 0; r < ((Match_COSTmatch *)a)->_1; r++) {
                        if (set->contains(r)) {  
                           
#line 958 "matchcom.pcc"
#line 962 "matchcom.pcc"
                     {
                        Cost _V7 = ((Match_COSTmatch *)a)->_2[r];
                        if (_V7) {
                           if (untagp(_V7)) {
                              
                              if (
#line 960 "matchcom.pcc"
                              (((Cost_INTcost *)derefp(_V7))->INTcost < min_cost)
#line 960 "matchcom.pcc"
) {
                                 
#line 960 "matchcom.pcc"
                                min_cost = ((Cost_INTcost *)derefp(_V7))->INTcost; 
#line 960 "matchcom.pcc"
                              } else {
                                 
                                 L37:; }
                           } else {
                               goto L37; }
                        } else {
#line 959 "matchcom.pcc"
                          min_cost = 0; 
#line 959 "matchcom.pcc"
                        }
                     }
#line 962 "matchcom.pcc"
#line 962 "matchcom.pcc"
                     
                     }
                     }
                     
                     // Prune away all the rules with higher or equal cost than min_cost.
                     Bool found = false;
                     for (r = 0; r < ((Match_COSTmatch *)a)->_1; r++) {
                     if (set->contains(r)) {
                        
#line 970 "matchcom.pcc"
#line 975 "matchcom.pcc"
                     {
                        Cost _V8 = ((Match_COSTmatch *)a)->_2[r];
                        if (_V8) {
                           if (untagp(_V8)) {
                              
#line 972 "matchcom.pcc"
                             if (((Cost_INTcost *)derefp(_V8))->INTcost > min_cost || found) set->remove(r);
                              found = true; 
#line 973 "matchcom.pcc"
                           } else {
                              }
                        } else {
#line 971 "matchcom.pcc"
                          if (! found) set->remove(r); found = true; 
#line 971 "matchcom.pcc"
                        }
                     }
#line 975 "matchcom.pcc"
#line 975 "matchcom.pcc"
                     
                     }
                     }
                     
                     return COSTmatch (((Match_COSTmatch *)a)->_1, ((Match_COSTmatch *)a)->_2, set, ((Match_COSTmatch *)a)->_4);
                     
#line 980 "matchcom.pcc"
                     } break;
                  default: { goto L36; } break;
               }
            } else { goto L36; }
            } break;
         default: { goto L36; } break;
      }
   } else { goto L36; }
}
#line 982 "matchcom.pcc"
#line 982 "matchcom.pcc"


   
#line 984 "matchcom.pcc"
#line 1004 "matchcom.pcc"
{
   if (boxed(a)) {
      switch (a->tag__) {
         case a_Match::tag_SUCCESSmatch: {
#line 988 "matchcom.pcc"
           return a; 
#line 988 "matchcom.pcc"
            } break;
         case a_Match::tag_GUARDmatch: {
#line 990 "matchcom.pcc"
           return GUARDmatch(((Match_GUARDmatch *)a)->_1,merge(((Match_GUARDmatch *)a)->_2,b),merge(((Match_GUARDmatch *)a)->_3,b)); 
#line 990 "matchcom.pcc"
            } break;
         case a_Match::tag_LITERALmatch: {
#line 992 "matchcom.pcc"
          Match * br = Matches(((Match_LITERALmatch *)a)->_4);
            for (int i = ((Match_LITERALmatch *)a)->_4 - 1; i >= 0; i--) br[i] = merge(((Match_LITERALmatch *)a)->_5[i],b);
            return LITERALmatch(((Match_LITERALmatch *)a)->_1,((Match_LITERALmatch *)a)->_2,((Match_LITERALmatch *)a)->_3,((Match_LITERALmatch *)a)->_4,br,merge(((Match_LITERALmatch *)a)->_6,b));
            
#line 995 "matchcom.pcc"
            } break;
         case a_Match::tag_RANGEmatch: {
#line 1002 "matchcom.pcc"
          return RANGEmatch(((Match_RANGEmatch *)a)->_1,((Match_RANGEmatch *)a)->_2,((Match_RANGEmatch *)a)->_3,((Match_RANGEmatch *)a)->_4,merge(((Match_RANGEmatch *)a)->_5,b),merge(((Match_RANGEmatch *)a)->_6,b)); 
#line 1002 "matchcom.pcc"
            } break;
         case a_Match::tag_CONSmatch: {
#line 997 "matchcom.pcc"
          Match * br = Matches(((Match_CONSmatch *)a)->_5);
            for (int i = ((Match_CONSmatch *)a)->_5 - 1; i >= 0; i--) br[i] = merge(((Match_CONSmatch *)a)->_6[i],b);
            return CONSmatch(((Match_CONSmatch *)a)->_1,((Match_CONSmatch *)a)->_2,((Match_CONSmatch *)a)->_3,((Match_CONSmatch *)a)->_4,((Match_CONSmatch *)a)->_5,br,merge(((Match_CONSmatch *)a)->_7,b));
            
#line 1000 "matchcom.pcc"
            } break;
         case a_Match::tag_BACKEDGEmatch: {
#line 987 "matchcom.pcc"
           return a; 
#line 987 "matchcom.pcc"
            } break;
         case a_Match::tag_SUCCESSESmatch:
         case a_Match::tag_COSTmatch: {
#line 989 "matchcom.pcc"
           return compose(b,a); 
#line 989 "matchcom.pcc"
            } break;
         default: {
#line 1004 "matchcom.pcc"
          bug("MatchCompiler::compose: %m, %m",a,b); return a; 
#line 1004 "matchcom.pcc"
            } break;
      }
   } else {
      if (a) {
         
#line 986 "matchcom.pcc"
        return a; 
#line 986 "matchcom.pcc"
      } else {
         
#line 985 "matchcom.pcc"
        return b; 
#line 985 "matchcom.pcc"
      }
   }
}
#line 1005 "matchcom.pcc"
#line 1005 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Merge two matching trees.
//
///////////////////////////////////////////////////////////////////////////////
Match MatchCompiler::merge (Match a, Match b)
{  
#line 1014 "matchcom.pcc"
#line 1024 "matchcom.pcc"
{
   if (boxed(a)) {
      switch (a->tag__) {
         case a_Match::tag_SUCCESSmatch: {
            if (boxed(b)) {
               L38:; 
#line 1017 "matchcom.pcc"
              return a; 
#line 1017 "matchcom.pcc"
            } else {
               if (b) {
                   goto L38; } else {
                  
                  L39:; 
#line 1016 "matchcom.pcc"
                 return a; 
#line 1016 "matchcom.pcc"
               }
            }
            } break;
         case a_Match::tag_SUCCESSESmatch:
         case a_Match::tag_COSTmatch: {
            if (boxed(b)) {
               L40:; 
#line 1022 "matchcom.pcc"
              return compose(a,b); 
#line 1022 "matchcom.pcc"
            } else {
               if (b) {
                   goto L40; } else {
                   goto L39; }
            }
            } break;
         default: {
            L41:; 
            if (boxed(b)) {
               switch (b->tag__) {
                  case a_Match::tag_SUCCESSmatch:
                  case a_Match::tag_SUCCESSESmatch:
                  case a_Match::tag_COSTmatch: { goto L40; } break;
                  default: {
                     L42:; } break;
               }
            } else {
               if (b) {
                   goto L42; } else {
                   goto L39; }
            }
            } break;
      }
   } else {
      if (a) {
          goto L41; } else {
         
#line 1015 "matchcom.pcc"
        return b; 
#line 1015 "matchcom.pcc"
      }
   }
}
#line 1024 "matchcom.pcc"
#line 1024 "matchcom.pcc"


   
#line 1026 "matchcom.pcc"
#line 1097 "matchcom.pcc"
{
   CompareResult _V9 = compare_pos(get_pos(a),get_pos(b));
   switch (_V9) {
      case LESS: {
         if (boxed(a)) {
            switch (a->tag__) {
               case a_Match::tag_GUARDmatch: {
#line 1074 "matchcom.pcc"
                return GUARDmatch(((Match_GUARDmatch *)a)->_1, merge(((Match_GUARDmatch *)a)->_2,b), merge(((Match_GUARDmatch *)a)->_3,b)); 
#line 1074 "matchcom.pcc"
                  } break;
               case a_Match::tag_LITERALmatch: {
#line 1076 "matchcom.pcc"
                Match * br = Matches(((Match_LITERALmatch *)a)->_4);
                  for (int i = ((Match_LITERALmatch *)a)->_4 - 1; i >= 0; i--) br[i] = merge(((Match_LITERALmatch *)a)->_5[i],b);
                  return LITERALmatch(((Match_LITERALmatch *)a)->_1,((Match_LITERALmatch *)a)->_2,((Match_LITERALmatch *)a)->_3,((Match_LITERALmatch *)a)->_4,br,merge(((Match_LITERALmatch *)a)->_6,b)); 
                  
#line 1079 "matchcom.pcc"
                  } break;
               case a_Match::tag_CONSmatch: {
#line 1081 "matchcom.pcc"
                Match * br = Matches(((Match_CONSmatch *)a)->_5);
                  for (int i = ((Match_CONSmatch *)a)->_5 - 1; i >= 0; i--) br[i] = merge(((Match_CONSmatch *)a)->_6[i],b);
                  return CONSmatch (((Match_CONSmatch *)a)->_1,((Match_CONSmatch *)a)->_2,((Match_CONSmatch *)a)->_3,((Match_CONSmatch *)a)->_4,((Match_CONSmatch *)a)->_5,br,merge(((Match_CONSmatch *)a)->_7,b));
                  
#line 1084 "matchcom.pcc"
                  } break;
               default: {
                  L43:; 
#line 1097 "matchcom.pcc"
                 return compose(a,b); 
#line 1097 "matchcom.pcc"
                  } break;
            }
         } else { goto L43; }
         } break;
      case SAME: {
         if (boxed(a)) {
            switch (a->tag__) {
               case a_Match::tag_GUARDmatch: {
                  if (boxed(b)) {
                     switch (b->tag__) {
                        case a_Match::tag_GUARDmatch: {
#line 1028 "matchcom.pcc"
                          if (equal(((Match_GUARDmatch *)a)->_1,((Match_GUARDmatch *)b)->_1)) 
                           return GUARDmatch(((Match_GUARDmatch *)a)->_1,merge(((Match_GUARDmatch *)a)->_2,((Match_GUARDmatch *)b)->_2), merge(((Match_GUARDmatch *)a)->_3,((Match_GUARDmatch *)b)->_3));
                           else return GUARDmatch(((Match_GUARDmatch *)a)->_1,merge(((Match_GUARDmatch *)a)->_2,b),merge(((Match_GUARDmatch *)a)->_3,b));
                           
#line 1031 "matchcom.pcc"
                           } break;
                        default: { goto L43; } break;
                     }
                  } else { goto L43; }
                  } break;
               case a_Match::tag_LITERALmatch: {
                  if (boxed(b)) {
                     switch (b->tag__) {
                        case a_Match::tag_LITERALmatch: {
#line 1041 "matchcom.pcc"
                         int i, n = ((Match_LITERALmatch *)a)->_4 + ((Match_LITERALmatch *)b)->_4;
                           Match   * br = Matches(n);
                           Literal * ls = Literals(n);
                           
                           if (has_regexp(((Match_LITERALmatch *)a)->_4,((Match_LITERALmatch *)a)->_3) || has_regexp(((Match_LITERALmatch *)b)->_4,((Match_LITERALmatch *)b)->_3)) {
                              for (i = 0; i < ((Match_LITERALmatch *)a)->_4; i++) { br[i] = ((Match_LITERALmatch *)a)->_5[i]; ls[i] = ((Match_LITERALmatch *)a)->_3[i]; }
                              for (i = 0; i < ((Match_LITERALmatch *)b)->_4; i++) { br[((Match_LITERALmatch *)a)->_4+i] = ((Match_LITERALmatch *)b)->_5[i]; ls[((Match_LITERALmatch *)a)->_4+i] = ((Match_LITERALmatch *)b)->_3[i]; }
                              convert_regexp(n,ls);
                           } else {
                              // merge and eliminate duplicates 
                              int i, j, k;
                              for (i = 0, j = 0, k = 0; i < ((Match_LITERALmatch *)a)->_4 && j < ((Match_LITERALmatch *)b)->_4; )
                              {  int dir = compare_literals(((Match_LITERALmatch *)a)->_3[i],((Match_LITERALmatch *)b)->_3[j]);
                                 if (dir == 0)     
                                    { ls[k] = ((Match_LITERALmatch *)a)->_3[i]; br[k] = merge(((Match_LITERALmatch *)a)->_5[i],((Match_LITERALmatch *)b)->_5[j]); i++; j++; }
                                 else if (dir < 0) 
                                    { ls[k] = ((Match_LITERALmatch *)a)->_3[i]; br[k] = merge(((Match_LITERALmatch *)a)->_5[i],((Match_LITERALmatch *)b)->_6); i++; }
                                 else              
                                    { ls[k] = ((Match_LITERALmatch *)b)->_3[j]; br[k] = merge(((Match_LITERALmatch *)a)->_6,((Match_LITERALmatch *)b)->_5[j]); j++; }
                                 k++;
                              }
                              while (i < ((Match_LITERALmatch *)a)->_4) { ls[k] = ((Match_LITERALmatch *)a)->_3[i]; br[k++] = merge(((Match_LITERALmatch *)a)->_5[i++],((Match_LITERALmatch *)b)->_6); }
                              while (j < ((Match_LITERALmatch *)b)->_4) { ls[k] = ((Match_LITERALmatch *)b)->_3[j]; br[k++] = merge(((Match_LITERALmatch *)a)->_6,((Match_LITERALmatch *)b)->_5[j++]); }
                              n = k;
                           }
                           return LITERALmatch(((Match_LITERALmatch *)a)->_1,((Match_LITERALmatch *)a)->_2,ls,n,br,merge(((Match_LITERALmatch *)a)->_6,((Match_LITERALmatch *)b)->_6));
                           
#line 1067 "matchcom.pcc"
                           } break;
                        default: { goto L43; } break;
                     }
                  } else { goto L43; }
                  } break;
               case a_Match::tag_RANGEmatch: {
                  if (boxed(b)) {
                     switch (b->tag__) {
                        case a_Match::tag_RANGEmatch: {
#line 1033 "matchcom.pcc"
                         if (((Match_RANGEmatch *)a)->_3 == 0 && ((Match_RANGEmatch *)a)->_4 == INT_MAX)
                           return merge(((Match_RANGEmatch *)a)->_5,b);
                           else if (((Match_RANGEmatch *)a)->_3 <= ((Match_RANGEmatch *)b)->_3 && ((Match_RANGEmatch *)a)->_4 >= ((Match_RANGEmatch *)b)->_4)
                           return RANGEmatch(((Match_RANGEmatch *)a)->_1,((Match_RANGEmatch *)a)->_2,((Match_RANGEmatch *)a)->_3,((Match_RANGEmatch *)a)->_4,merge(((Match_RANGEmatch *)a)->_5,((Match_RANGEmatch *)b)->_5),merge(((Match_RANGEmatch *)a)->_6,((Match_RANGEmatch *)b)->_6));
                           else 
                           return RANGEmatch(((Match_RANGEmatch *)a)->_1,((Match_RANGEmatch *)b)->_2,((Match_RANGEmatch *)a)->_3,((Match_RANGEmatch *)a)->_4,merge(((Match_RANGEmatch *)a)->_5,b),merge(((Match_RANGEmatch *)a)->_6,b));
                           
#line 1039 "matchcom.pcc"
                           } break;
                        default: { goto L43; } break;
                     }
                  } else { goto L43; }
                  } break;
               case a_Match::tag_CONSmatch: {
                  if (boxed(b)) {
                     switch (b->tag__) {
                        case a_Match::tag_CONSmatch: {
#line 1069 "matchcom.pcc"
                         Match * br = Matches(((Match_CONSmatch *)a)->_5);
                           for (int i = ((Match_CONSmatch *)a)->_5 - 1; i >= 0; i--) br[i] = merge(((Match_CONSmatch *)a)->_6[i],((Match_CONSmatch *)b)->_6[i]);
                           return CONSmatch (((Match_CONSmatch *)a)->_1,((Match_CONSmatch *)a)->_2,((Match_CONSmatch *)a)->_3,((Match_CONSmatch *)a)->_4,((Match_CONSmatch *)a)->_5,br,merge(((Match_CONSmatch *)a)->_7,((Match_CONSmatch *)b)->_7));
                           
#line 1072 "matchcom.pcc"
                           } break;
                        default: { goto L43; } break;
                     }
                  } else { goto L43; }
                  } break;
               default: { goto L43; } break;
            }
         } else { goto L43; }
         } break;
      case MORE: {
         if (boxed(b)) {
            switch (b->tag__) {
               case a_Match::tag_GUARDmatch: {
#line 1086 "matchcom.pcc"
                return GUARDmatch(((Match_GUARDmatch *)b)->_1, merge(a,((Match_GUARDmatch *)b)->_2), merge(a,((Match_GUARDmatch *)b)->_3)); 
#line 1086 "matchcom.pcc"
                  } break;
               case a_Match::tag_LITERALmatch: {
#line 1088 "matchcom.pcc"
                Match * br = Matches(((Match_LITERALmatch *)b)->_4);
                  for (int i = ((Match_LITERALmatch *)b)->_4 - 1; i >= 0; i--) br[i] = merge(a,((Match_LITERALmatch *)b)->_5[i]);
                  return LITERALmatch(((Match_LITERALmatch *)b)->_1,((Match_LITERALmatch *)b)->_2,((Match_LITERALmatch *)b)->_3,((Match_LITERALmatch *)b)->_4,br,merge(a,((Match_LITERALmatch *)b)->_6)); 
                  
#line 1091 "matchcom.pcc"
                  } break;
               case a_Match::tag_CONSmatch: {
#line 1093 "matchcom.pcc"
                Match * br = Matches(((Match_CONSmatch *)b)->_5);
                  for (int i = ((Match_CONSmatch *)b)->_5 - 1; i >= 0; i--) br[i] = merge(a,((Match_CONSmatch *)b)->_6[i]);
                  return CONSmatch (((Match_CONSmatch *)b)->_1,((Match_CONSmatch *)b)->_2,((Match_CONSmatch *)b)->_3,((Match_CONSmatch *)b)->_4,((Match_CONSmatch *)b)->_5,br,merge(a,((Match_CONSmatch *)b)->_7));
                  
#line 1096 "matchcom.pcc"
                  } break;
               default: { goto L43; } break;
            }
         } else { goto L43; }
         } break;
      default: { goto L43; } break;
   }
}
#line 1098 "matchcom.pcc"
#line 1098 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Equality between two matching tree.
//
///////////////////////////////////////////////////////////////////////////////
Bool match_equal (HashTable::Key a, HashTable::Key b)
{  
#line 1107 "matchcom.pcc"
#line 1132 "matchcom.pcc"
{
   Match _V10 = Match(a);
   Match _V11 = Match(b);
   if (boxed(_V10)) {
      switch (_V10->tag__) {
         case a_Match::tag_SUCCESSmatch: {
            if (boxed(_V11)) {
               switch (_V11->tag__) {
                  case a_Match::tag_SUCCESSmatch: {
#line 1109 "matchcom.pcc"
                    return a == b; 
#line 1109 "matchcom.pcc"
                     } break;
                  default: {
                     L44:; 
#line 1132 "matchcom.pcc"
                    return false; 
#line 1132 "matchcom.pcc"
                     } break;
               }
            } else { goto L44; }
            } break;
         case a_Match::tag_SUCCESSESmatch: {
            if (boxed(_V11)) {
               switch (_V11->tag__) {
                  case a_Match::tag_SUCCESSESmatch: {
#line 1110 "matchcom.pcc"
                    return equal(((Match_SUCCESSESmatch *)_V10)->_2,((Match_SUCCESSESmatch *)_V11)->_2); 
#line 1110 "matchcom.pcc"
                     } break;
                  default: { goto L44; } break;
               }
            } else { goto L44; }
            } break;
         case a_Match::tag_COSTmatch: {
            if (boxed(_V11)) {
               switch (_V11->tag__) {
                  case a_Match::tag_COSTmatch: {
#line 1111 "matchcom.pcc"
                    return equal(((Match_COSTmatch *)_V10)->_3,((Match_COSTmatch *)_V11)->_3); 
#line 1111 "matchcom.pcc"
                     } break;
                  default: { goto L44; } break;
               }
            } else { goto L44; }
            } break;
         case a_Match::tag_GUARDmatch: {
            if (boxed(_V11)) {
               switch (_V11->tag__) {
                  case a_Match::tag_GUARDmatch: {
#line 1113 "matchcom.pcc"
                   return equal(((Match_GUARDmatch *)_V10)->_1,((Match_GUARDmatch *)_V11)->_1) && ((Match_GUARDmatch *)_V10)->_2 == ((Match_GUARDmatch *)_V11)->_2 && ((Match_GUARDmatch *)_V10)->_3 == ((Match_GUARDmatch *)_V11)->_3; 
#line 1113 "matchcom.pcc"
                     } break;
                  default: { goto L44; } break;
               }
            } else { goto L44; }
            } break;
         case a_Match::tag_LITERALmatch: {
            if (boxed(_V11)) {
               switch (_V11->tag__) {
                  case a_Match::tag_LITERALmatch: {
                     if (
#line 1118 "matchcom.pcc"
                     (((Match_LITERALmatch *)_V10)->_4 == ((Match_LITERALmatch *)_V11)->_4)
#line 1118 "matchcom.pcc"
) {
                        
#line 1119 "matchcom.pcc"
                      if (compare_pos(((Match_LITERALmatch *)_V10)->_1,((Match_LITERALmatch *)_V11)->_1) != SAME) return false;
                        for (int k = ((Match_LITERALmatch *)_V10)->_4-1; k >= 0; k--) if (((Match_LITERALmatch *)_V10)->_5[k] != ((Match_LITERALmatch *)_V11)->_5[k]) return false;
                        return ((Match_LITERALmatch *)_V10)->_6 == ((Match_LITERALmatch *)_V11)->_6;
                        
#line 1122 "matchcom.pcc"
                     } else {
                         goto L44; }
                     } break;
                  default: { goto L44; } break;
               }
            } else { goto L44; }
            } break;
         case a_Match::tag_RANGEmatch: {
            if (boxed(_V11)) {
               switch (_V11->tag__) {
                  case a_Match::tag_RANGEmatch: {
#line 1129 "matchcom.pcc"
                   return compare_pos(((Match_RANGEmatch *)_V10)->_1,((Match_RANGEmatch *)_V11)->_1) == SAME &&
                     ((Match_RANGEmatch *)_V10)->_3 == ((Match_RANGEmatch *)_V11)->_3 && ((Match_RANGEmatch *)_V10)->_4 == ((Match_RANGEmatch *)_V11)->_4 && ((Match_RANGEmatch *)_V10)->_5 == ((Match_RANGEmatch *)_V11)->_5 && ((Match_RANGEmatch *)_V10)->_6 == ((Match_RANGEmatch *)_V11)->_6; 
                     
#line 1131 "matchcom.pcc"
                     } break;
                  default: { goto L44; } break;
               }
            } else { goto L44; }
            } break;
         case a_Match::tag_CONSmatch: {
            if (boxed(_V11)) {
               switch (_V11->tag__) {
                  case a_Match::tag_CONSmatch: {
                     if (
#line 1123 "matchcom.pcc"
                     ((((Match_CONSmatch *)_V10)->_4 == ((Match_CONSmatch *)_V11)->_4) && (((Match_CONSmatch *)_V10)->_5 == ((Match_CONSmatch *)_V11)->_5))
#line 1123 "matchcom.pcc"
) {
                        
#line 1124 "matchcom.pcc"
                      if (compare_pos(((Match_CONSmatch *)_V10)->_1,((Match_CONSmatch *)_V11)->_1) != SAME) return false;
                        for (int k = ((Match_CONSmatch *)_V10)->_5-1; k >= 0; k--) if (((Match_CONSmatch *)_V10)->_6[k] != ((Match_CONSmatch *)_V11)->_6[k]) return false;
                        return ((Match_CONSmatch *)_V10)->_7 == ((Match_CONSmatch *)_V11)->_7;
                        
#line 1127 "matchcom.pcc"
                     } else {
                         goto L44; }
                     } break;
                  default: { goto L44; } break;
               }
            } else { goto L44; }
            } break;
         case a_Match::tag_TREECOSTmatch: {
            if (boxed(_V11)) {
               switch (_V11->tag__) {
                  case a_Match::tag_TREECOSTmatch: {
#line 1115 "matchcom.pcc"
                   return ((Match_TREECOSTmatch *)_V10)->_1 == ((Match_TREECOSTmatch *)_V11)->_1 && equal(((Match_TREECOSTmatch *)_V10)->_2,((Match_TREECOSTmatch *)_V11)->_2); 
#line 1115 "matchcom.pcc"
                     } break;
                  default: { goto L44; } break;
               }
            } else { goto L44; }
            } break;
         case a_Match::tag_TREELABELmatch: {
            if (boxed(_V11)) {
               switch (_V11->tag__) {
                  case a_Match::tag_TREELABELmatch: {
#line 1117 "matchcom.pcc"
                   return ((Match_TREELABELmatch *)_V10)->_1 == ((Match_TREELABELmatch *)_V11)->_1 && ty_equal(((Match_TREELABELmatch *)_V10)->_2,((Match_TREELABELmatch *)_V11)->_2) && ty_equal(((Match_TREELABELmatch *)_V10)->_3,((Match_TREELABELmatch *)_V11)->_3) && ((Match_TREELABELmatch *)_V10)->_4 == ((Match_TREELABELmatch *)_V11)->_4; 
#line 1117 "matchcom.pcc"
                     } break;
                  default: { goto L44; } break;
               }
            } else { goto L44; }
            } break;
         default: { goto L44; } break;
      }
   } else {
      if (_V10) {
          goto L44; } else {
         
         if (boxed(_V11)) { goto L44; } else {
            if (_V11) {
                goto L44; } else {
               
#line 1108 "matchcom.pcc"
              return true; 
#line 1108 "matchcom.pcc"
            }
         }
      }
   }
}
#line 1133 "matchcom.pcc"
#line 1133 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Hashing function on a literal.
//
///////////////////////////////////////////////////////////////////////////////
unsigned int literal_hash (HashTable::Key k)
{  
#line 1142 "matchcom.pcc"
#line 1150 "matchcom.pcc"
{
   Literal _V12 = Literal(k);
   switch (_V12->tag__) {
      case a_Literal::tag_INTlit: {
#line 1143 "matchcom.pcc"
        return ((Literal_INTlit *)_V12)->INTlit; 
#line 1143 "matchcom.pcc"
         } break;
      case a_Literal::tag_BOOLlit: {
#line 1144 "matchcom.pcc"
        return ((Literal_BOOLlit *)_V12)->BOOLlit; 
#line 1144 "matchcom.pcc"
         } break;
      case a_Literal::tag_CHARlit: {
#line 1148 "matchcom.pcc"
        return ((Literal_CHARlit *)_V12)->CHARlit; 
#line 1148 "matchcom.pcc"
         } break;
      case a_Literal::tag_REALlit: {
#line 1145 "matchcom.pcc"
        return (unsigned int)((Literal_REALlit *)_V12)->REALlit; 
#line 1145 "matchcom.pcc"
         } break;
      case a_Literal::tag_STRINGlit: {
#line 1146 "matchcom.pcc"
        return hash(((Literal_STRINGlit *)_V12)->STRINGlit); 
#line 1146 "matchcom.pcc"
         } break;
      case a_Literal::tag_REGEXPlit: {
#line 1147 "matchcom.pcc"
        return hash(((Literal_REGEXPlit *)_V12)->REGEXPlit); 
#line 1147 "matchcom.pcc"
         } break;
      case a_Literal::tag_QUARKlit: {
#line 1149 "matchcom.pcc"
        return hash(((Literal_QUARKlit *)_V12)->QUARKlit); 
#line 1149 "matchcom.pcc"
         } break;
      default: {
#line 1150 "matchcom.pcc"
        return hash(((Literal_BIGINTlit *)_V12)->BIGINTlit); 
#line 1150 "matchcom.pcc"
         } break;
   }
}
#line 1151 "matchcom.pcc"
#line 1151 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Equality function on literals.
//
///////////////////////////////////////////////////////////////////////////////
Bool literal_equal (HashTable::Key a, HashTable::Key b)
{  return compare_literals((Literal)a, (Literal)b) == 0; }

///////////////////////////////////////////////////////////////////////////////
//
//  Hashing function on a matching tree.
//
///////////////////////////////////////////////////////////////////////////////
unsigned int match_hash (HashTable::Key m)
{  
#line 1168 "matchcom.pcc"
#line 1191 "matchcom.pcc"
{
   Match _V13 = Match(m);
   if (boxed(_V13)) {
      switch (_V13->tag__) {
         case a_Match::tag_SUCCESSmatch: {
#line 1172 "matchcom.pcc"
           return (unsigned int)m; 
#line 1172 "matchcom.pcc"
            } break;
         case a_Match::tag_SUCCESSESmatch: {
#line 1173 "matchcom.pcc"
           return 93 + hash (((Match_SUCCESSESmatch *)_V13)->_2); 
#line 1173 "matchcom.pcc"
            } break;
         case a_Match::tag_COSTmatch: {
#line 1174 "matchcom.pcc"
           return 457 + hash (((Match_COSTmatch *)_V13)->_3); 
#line 1174 "matchcom.pcc"
            } break;
         case a_Match::tag_GUARDmatch: {
#line 1177 "matchcom.pcc"
           return (unsigned int)((Match_GUARDmatch *)_V13)->_2 + (unsigned int)((Match_GUARDmatch *)_V13)->_3;
#line 1177 "matchcom.pcc"
            } break;
         case a_Match::tag_LITERALmatch: {
#line 1181 "matchcom.pcc"
          unsigned h = 117 + ((Match_LITERALmatch *)_V13)->_4 + (unsigned int)((Match_LITERALmatch *)_V13)->_6;
            for (int i = ((Match_LITERALmatch *)_V13)->_4 - 1; i >= 0; i--) 
               h += literal_hash(((Match_LITERALmatch *)_V13)->_3[i]) + (unsigned int)((Match_LITERALmatch *)_V13)->_5[i];
            return h;
            
#line 1185 "matchcom.pcc"
            } break;
         case a_Match::tag_RANGEmatch: {
#line 1179 "matchcom.pcc"
          return 235 + ((Match_RANGEmatch *)_V13)->_3 + ((Match_RANGEmatch *)_V13)->_4 + (unsigned int)((Match_RANGEmatch *)_V13)->_5 + (unsigned int)((Match_RANGEmatch *)_V13)->_6; 
#line 1179 "matchcom.pcc"
            } break;
         case a_Match::tag_CONSmatch: {
#line 1187 "matchcom.pcc"
          unsigned h = 657 + ((Match_CONSmatch *)_V13)->_5 + (unsigned int)((Match_CONSmatch *)_V13)->_7;
            for (int i = ((Match_CONSmatch *)_V13)->_5 - 1; i >= 0; i--) 
               h += (unsigned int)((Match_CONSmatch *)_V13)->_6[i];
            return h;
            
#line 1191 "matchcom.pcc"
            } break;
         case a_Match::tag_TREECOSTmatch: {
#line 1175 "matchcom.pcc"
           return hash(((Match_TREECOSTmatch *)_V13)->_2) + (unsigned int)((Match_TREECOSTmatch *)_V13)->_1; 
#line 1175 "matchcom.pcc"
            } break;
         case a_Match::tag_TREELABELmatch: {
#line 1176 "matchcom.pcc"
           return ty_hash(((Match_TREELABELmatch *)_V13)->_2) + ty_hash(((Match_TREELABELmatch *)_V13)->_3) + ((Match_TREELABELmatch *)_V13)->_4 + (unsigned int)((Match_TREELABELmatch *)_V13)->_1; 
#line 1176 "matchcom.pcc"
            } break;
         default: {
#line 1171 "matchcom.pcc"
           return ((Match_BACKEDGEmatch *)_V13)->_1 + 1249; 
#line 1171 "matchcom.pcc"
            } break;
      }
   } else {
      if (_V13) {
         
#line 1170 "matchcom.pcc"
        return 179; 
#line 1170 "matchcom.pcc"
      } else {
         
#line 1169 "matchcom.pcc"
        return 0; 
#line 1169 "matchcom.pcc"
      }
   }
}
#line 1192 "matchcom.pcc"
#line 1192 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Tree to dag conversion for a matching tree. 
//
///////////////////////////////////////////////////////////////////////////////
Match make_dag (Match m, HashTable& map, int& merges)
{  int i;
   if (boxed(m)) { m->shared = 0; m->label = 0; }
   
#line 1203 "matchcom.pcc"
#line 1237 "matchcom.pcc"
{
   if (boxed(m)) {
      switch (m->tag__) {
         case a_Match::tag_GUARDmatch: {
#line 1228 "matchcom.pcc"
          if ((((Match_GUARDmatch *)m)->_2 = make_dag(((Match_GUARDmatch *)m)->_2,map,merges)) == (((Match_GUARDmatch *)m)->_3 = make_dag(((Match_GUARDmatch *)m)->_3,map,merges))) 
            { merges++; return ((Match_GUARDmatch *)m)->_2; }
            
#line 1230 "matchcom.pcc"
            } break;
         case a_Match::tag_LITERALmatch: {
#line 1205 "matchcom.pcc"
          for (i = ((Match_LITERALmatch *)m)->_4 - 1; i >= 0; i--) ((Match_LITERALmatch *)m)->_5[i] = make_dag (((Match_LITERALmatch *)m)->_5[i], map, merges);
            ((Match_LITERALmatch *)m)->_6 = make_dag(((Match_LITERALmatch *)m)->_6, map, merges);
            // Eliminate the node if every branch is the same.
            for (i = ((Match_LITERALmatch *)m)->_4 - 1; i >= 1; i--) if (((Match_LITERALmatch *)m)->_5[i] != ((Match_LITERALmatch *)m)->_5[i-1]) break;
            if (i == 0 && ((Match_LITERALmatch *)m)->_5[0] == ((Match_LITERALmatch *)m)->_6) { merges++; return ((Match_LITERALmatch *)m)->_6; }
            // Eliminate all branches that are the same as the default
            for (i = 0; i < ((Match_LITERALmatch *)m)->_4; i++)
            {  if (((Match_LITERALmatch *)m)->_5[i] == ((Match_LITERALmatch *)m)->_6)
               {  // shift one over
                  for (int j = i+1; j < ((Match_LITERALmatch *)m)->_4; j++)
                  {  ((Match_LITERALmatch *)m)->_5[j-1] = ((Match_LITERALmatch *)m)->_5[j]; ((Match_LITERALmatch *)m)->_3[j-1] = ((Match_LITERALmatch *)m)->_3[j]; }
                  ((Match_LITERALmatch *)m)->_4--;
               }
            }
            
#line 1219 "matchcom.pcc"
            } break;
         case a_Match::tag_RANGEmatch: {
#line 1232 "matchcom.pcc"
          if ((((Match_RANGEmatch *)m)->_5 = make_dag(((Match_RANGEmatch *)m)->_5,map,merges)) == (((Match_RANGEmatch *)m)->_6 = make_dag(((Match_RANGEmatch *)m)->_6,map,merges)))
            { merges++; return ((Match_RANGEmatch *)m)->_5; }
            
#line 1234 "matchcom.pcc"
            } break;
         case a_Match::tag_CONSmatch: {
#line 1221 "matchcom.pcc"
          for (i = ((Match_CONSmatch *)m)->_5 - 1; i >= 0; i--) ((Match_CONSmatch *)m)->_6[i] = make_dag (((Match_CONSmatch *)m)->_6[i], map, merges);
            ((Match_CONSmatch *)m)->_7 = make_dag(((Match_CONSmatch *)m)->_7, map, merges);
            // Eliminate the node if every branch is the same.
            for (i = ((Match_CONSmatch *)m)->_5 - 1; i >= 1; i--) if (((Match_CONSmatch *)m)->_6[i] != ((Match_CONSmatch *)m)->_6[i-1]) break;
            if (i == 0 && ((Match_CONSmatch *)m)->_6[0] == ((Match_CONSmatch *)m)->_7) { merges++; return ((Match_CONSmatch *)m)->_7; }
            
#line 1226 "matchcom.pcc"
            } break;
         case a_Match::tag_TREECOSTmatch: {
#line 1235 "matchcom.pcc"
          ((Match_TREECOSTmatch *)m)->_1 = make_dag(((Match_TREECOSTmatch *)m)->_1,map,merges); 
#line 1235 "matchcom.pcc"
            } break;
         case a_Match::tag_TREELABELmatch: {
#line 1236 "matchcom.pcc"
          ((Match_TREELABELmatch *)m)->_1 = make_dag(((Match_TREELABELmatch *)m)->_1,map,merges); 
#line 1236 "matchcom.pcc"
            } break;
         default: {
            L45:; 
#line 1237 "matchcom.pcc"
           /* skip */ 
#line 1237 "matchcom.pcc"
            } break;
      }
   } else { goto L45; }
}
#line 1238 "matchcom.pcc"
#line 1238 "matchcom.pcc"


   HashTable::Entry * found = map.lookup(m);
   if (found) {
      merges++;
      return (Match)found->v;
   } else {
      map.insert(m,m);
      return m;
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Mark all sharing
//
///////////////////////////////////////////////////////////////////////////////
void mark(Match m)
{  if (boxed(m)) m->shared++;
   
#line 1257 "matchcom.pcc"
#line 1284 "matchcom.pcc"
{
   if (boxed(m)) {
      switch (m->tag__) {
         case a_Match::tag_SUCCESSmatch: {
#line 1258 "matchcom.pcc"
           ((Match_SUCCESSmatch *)m)->_2->used = true; 
#line 1258 "matchcom.pcc"
            } break;
         case a_Match::tag_GUARDmatch: {
#line 1261 "matchcom.pcc"
           mark(((Match_GUARDmatch *)m)->_2); mark(((Match_GUARDmatch *)m)->_3); 
#line 1261 "matchcom.pcc"
            } break;
         case a_Match::tag_LITERALmatch: {
#line 1262 "matchcom.pcc"
           for (int i = ((Match_LITERALmatch *)m)->_4-1; i >= 0; i--) mark(((Match_LITERALmatch *)m)->_5[i]);
            mark(((Match_LITERALmatch *)m)->_6);
            
#line 1264 "matchcom.pcc"
            } break;
         case a_Match::tag_RANGEmatch: {
#line 1265 "matchcom.pcc"
           mark(((Match_RANGEmatch *)m)->_5); mark(((Match_RANGEmatch *)m)->_6); 
#line 1265 "matchcom.pcc"
            } break;
         case a_Match::tag_CONSmatch: {
            if (((Match_CONSmatch *)m)->_4) {
               switch (((Match_CONSmatch *)m)->_4->tag__) {
                  case a_Ty::tag_TYCONty: {
                     if (boxed(((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1)) {
                        switch (((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1->tag__) {
                           case a_TyCon::tag_DATATYPEtycon: {
#line 1269 "matchcom.pcc"
                            for (int i = ((Match_CONSmatch *)m)->_5-1; i >= 0; i--) mark(((Match_CONSmatch *)m)->_6[i]);
                              // if (unit > 0)
                              // {  int i;
                              //    for (i = unit - 2; i >= 0; i--) if (a[i] != a[i+1]) break;
                              //    if (i < 0) mark(a[0]);
                              //    else       for (i = unit - 1; i >= 0; i--) mark(a[i]);
                              // }
                              // if (arg > 0)
                              // {  int i;
                              //    for (i = n - 2; i >= unit; i--) if (a[i] != a[i+1]) break;
                              //    if (i < unit) mark(a[unit]);
                              //    else          for (i = n - 1; i >= unit; i--) mark(a[i]);
                              // } 
                              if (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1)->qualifiers & QUALextensible) mark(((Match_CONSmatch *)m)->_7);
                              
#line 1283 "matchcom.pcc"
                              } break;
                           default: {
                              L46:; 
#line 1284 "matchcom.pcc"
                             bug ("mark()"); 
#line 1284 "matchcom.pcc"
                              } break;
                        }
                     } else { goto L46; }
                     } break;
                  default: { goto L46; } break;
               }
            } else { goto L46; }
            } break;
         case a_Match::tag_TREECOSTmatch: {
#line 1266 "matchcom.pcc"
           mark(((Match_TREECOSTmatch *)m)->_1); 
#line 1266 "matchcom.pcc"
            } break;
         case a_Match::tag_TREELABELmatch: {
#line 1267 "matchcom.pcc"
           mark(((Match_TREELABELmatch *)m)->_1); 
#line 1267 "matchcom.pcc"
            } break;
         case a_Match::tag_BACKEDGEmatch: { goto L46; } break;
         default: {
            L47:; 
#line 1260 "matchcom.pcc"
           /* skip */ 
#line 1260 "matchcom.pcc"
            } break;
      }
   } else {
      if (m) {
          goto L46; } else {
          goto L47; }
   }
}
#line 1285 "matchcom.pcc"
#line 1285 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Top level tree to dag conversion.
//
///////////////////////////////////////////////////////////////////////////////
Match MatchCompiler::make_dag (Match m, MatchOptions options, MatchRules rules)
{  HashTable map(match_hash, match_equal, 257);
   m = ::make_dag(m,map,merges);
   if (options & MATCHwithtreecost)
      m = translate_treecost(m,rules);
   mark(m);
   return m;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Check to see if a matching tree is refutable (i.e. can fail.)
//
///////////////////////////////////////////////////////////////////////////////
Bool refutable (Match m)
{  
#line 1308 "matchcom.pcc"
#line 1327 "matchcom.pcc"
{
   for (;;) {
      if (boxed(m)) {
         switch (m->tag__) {
            case a_Match::tag_GUARDmatch: {
#line 1311 "matchcom.pcc"
              return refutable(((Match_GUARDmatch *)m)->_2) || refutable(((Match_GUARDmatch *)m)->_3); 
#line 1311 "matchcom.pcc"
               } break;
            case a_Match::tag_LITERALmatch: {
#line 1314 "matchcom.pcc"
             for (int i = ((Match_LITERALmatch *)m)->_4 - 1; i >= 0; i--) if (refutable(((Match_LITERALmatch *)m)->_5[i])) return true;
               
#line 1315 "matchcom.pcc"
#line 1317 "matchcom.pcc"
               {
                  Literal _V14 = ((Match_LITERALmatch *)m)->_3[0];
                  switch (_V14->tag__) {
                     case a_Literal::tag_BOOLlit: {
                        if (
#line 1316 "matchcom.pcc"
                        (((Match_LITERALmatch *)m)->_4 >= 2)
#line 1316 "matchcom.pcc"
) {
                           
#line 1316 "matchcom.pcc"
                          return false; 
#line 1316 "matchcom.pcc"
                        } else {
                           
                           L49:; 
#line 1317 "matchcom.pcc"
                          m = ((Match_LITERALmatch *)m)->_6; 
#line 1317 "matchcom.pcc"
                        }
                        } break;
                     default: { goto L49; } break;
                  }
               }
#line 1318 "matchcom.pcc"
#line 1318 "matchcom.pcc"
               
               
#line 1319 "matchcom.pcc"
               } break;
            case a_Match::tag_RANGEmatch: {
#line 1312 "matchcom.pcc"
              return refutable(((Match_RANGEmatch *)m)->_5) || refutable(((Match_RANGEmatch *)m)->_6); 
#line 1312 "matchcom.pcc"
               } break;
            case a_Match::tag_CONSmatch: {
               if (((Match_CONSmatch *)m)->_4) {
                  switch (((Match_CONSmatch *)m)->_4->tag__) {
                     case a_Ty::tag_TYCONty: {
                        if (boxed(((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1)) {
                           switch (((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1->tag__) {
                              case a_TyCon::tag_DATATYPEtycon: {
#line 1321 "matchcom.pcc"
                               for (int i = ((Match_CONSmatch *)m)->_5 - 1; i >= 0; i--) if (refutable(((Match_CONSmatch *)m)->_6[i])) return true;
                                 if (! (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1)->qualifiers & QUALextensible)) return false;
                                 m = ((Match_CONSmatch *)m)->_7;
                                 
#line 1324 "matchcom.pcc"
                                 } break;
                              default: {
                                 L50:; 
#line 1327 "matchcom.pcc"
                                bug ("refutable()"); 
#line 1327 "matchcom.pcc"
                                 } break;
                           }
                        } else { goto L50; }
                        } break;
                     default: { goto L50; } break;
                  }
               } else { goto L50; }
               } break;
            case a_Match::tag_TREECOSTmatch: {
#line 1325 "matchcom.pcc"
              m = ((Match_TREECOSTmatch *)m)->_1; 
#line 1325 "matchcom.pcc"
               } break;
            case a_Match::tag_TREELABELmatch: {
#line 1326 "matchcom.pcc"
              m = ((Match_TREELABELmatch *)m)->_1; 
#line 1326 "matchcom.pcc"
               } break;
            case a_Match::tag_BACKEDGEmatch: { goto L50; } break;
            default: {
#line 1310 "matchcom.pcc"
              return false; 
#line 1310 "matchcom.pcc"
               } break;
         }
      } else {
         if (m) {
             goto L50; } else {
            
#line 1309 "matchcom.pcc"
           return true; 
#line 1309 "matchcom.pcc"
         }
      }
   }
}
#line 1328 "matchcom.pcc"
#line 1328 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Compute the set of rules that can possibly match as a bitset.
//
///////////////////////////////////////////////////////////////////////////////
void matchables (Match m, BitSet& set)
{  
#line 1337 "matchcom.pcc"
#line 1355 "matchcom.pcc"
{
   for (;;) {
      if (boxed(m)) {
         switch (m->tag__) {
            case a_Match::tag_SUCCESSmatch: {
#line 1341 "matchcom.pcc"
              set.add(((Match_SUCCESSmatch *)m)->_1); return; 
#line 1341 "matchcom.pcc"
               } break;
            case a_Match::tag_SUCCESSESmatch: {
#line 1339 "matchcom.pcc"
              set.Union(*((Match_SUCCESSESmatch *)m)->_2); return; 
#line 1339 "matchcom.pcc"
               } break;
            case a_Match::tag_COSTmatch: {
#line 1340 "matchcom.pcc"
              set.Union(*((Match_COSTmatch *)m)->_3); return; 
#line 1340 "matchcom.pcc"
               } break;
            case a_Match::tag_GUARDmatch: {
#line 1342 "matchcom.pcc"
              matchables(((Match_GUARDmatch *)m)->_2,set); m = ((Match_GUARDmatch *)m)->_3; 
#line 1342 "matchcom.pcc"
               } break;
            case a_Match::tag_LITERALmatch: {
#line 1345 "matchcom.pcc"
             for (int i = ((Match_LITERALmatch *)m)->_4 - 1; i >= 0; i--) matchables(((Match_LITERALmatch *)m)->_5[i],set);
               m = ((Match_LITERALmatch *)m)->_6; 
               
#line 1347 "matchcom.pcc"
               } break;
            case a_Match::tag_RANGEmatch: {
#line 1343 "matchcom.pcc"
              matchables(((Match_RANGEmatch *)m)->_5,set); m = ((Match_RANGEmatch *)m)->_6; 
#line 1343 "matchcom.pcc"
               } break;
            case a_Match::tag_CONSmatch: {
               if (((Match_CONSmatch *)m)->_4) {
                  switch (((Match_CONSmatch *)m)->_4->tag__) {
                     case a_Ty::tag_TYCONty: {
                        if (boxed(((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1)) {
                           switch (((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1->tag__) {
                              case a_TyCon::tag_DATATYPEtycon: {
#line 1349 "matchcom.pcc"
                               for (int i = ((Match_CONSmatch *)m)->_5 - 1; i >= 0; i--) matchables(((Match_CONSmatch *)m)->_6[i],set);
                                 if (! (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1)->qualifiers & QUALextensible)) return;
                                 m = ((Match_CONSmatch *)m)->_7;
                                 
#line 1352 "matchcom.pcc"
                                 } break;
                              default: {
                                 L52:; 
#line 1355 "matchcom.pcc"
                                bug("matchables()"); 
#line 1355 "matchcom.pcc"
                                 } break;
                           }
                        } else { goto L52; }
                        } break;
                     default: { goto L52; } break;
                  }
               } else { goto L52; }
               } break;
            case a_Match::tag_TREECOSTmatch: {
#line 1353 "matchcom.pcc"
              set.Union(*((Match_TREECOSTmatch *)m)->_2); m = ((Match_TREECOSTmatch *)m)->_1; 
#line 1353 "matchcom.pcc"
               } break;
            case a_Match::tag_TREELABELmatch: {
#line 1354 "matchcom.pcc"
              m = ((Match_TREELABELmatch *)m)->_1; 
#line 1354 "matchcom.pcc"
               } break;
            default: { goto L52; } break;
         }
      } else {
         if (m) {
             goto L52; } else {
            
#line 1338 "matchcom.pcc"
           return; 
#line 1338 "matchcom.pcc"
         }
      }
   }
}
#line 1356 "matchcom.pcc"
#line 1356 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Compute the set of rules that can always match as a bitset.
//
///////////////////////////////////////////////////////////////////////////////
void always_matchables (Match m, BitSet& set)
{  
#line 1365 "matchcom.pcc"
#line 1380 "matchcom.pcc"
{
   for (;;) {
      if (boxed(m)) {
         switch (m->tag__) {
            case a_Match::tag_SUCCESSESmatch: {
#line 1366 "matchcom.pcc"
              set.Intersect(*((Match_SUCCESSESmatch *)m)->_2); return; 
#line 1366 "matchcom.pcc"
               } break;
            case a_Match::tag_COSTmatch: {
#line 1367 "matchcom.pcc"
              set.Intersect(*((Match_COSTmatch *)m)->_3); return; 
#line 1367 "matchcom.pcc"
               } break;
            case a_Match::tag_GUARDmatch: {
#line 1368 "matchcom.pcc"
              always_matchables(((Match_GUARDmatch *)m)->_2,set); m = ((Match_GUARDmatch *)m)->_3; 
#line 1368 "matchcom.pcc"
               } break;
            case a_Match::tag_LITERALmatch: {
#line 1371 "matchcom.pcc"
             for (int i = ((Match_LITERALmatch *)m)->_4 - 1; i >= 0; i--) always_matchables(((Match_LITERALmatch *)m)->_5[i],set);
               m = ((Match_LITERALmatch *)m)->_6; 
               
#line 1373 "matchcom.pcc"
               } break;
            case a_Match::tag_RANGEmatch: {
#line 1369 "matchcom.pcc"
              always_matchables(((Match_RANGEmatch *)m)->_5,set); m = ((Match_RANGEmatch *)m)->_6; 
#line 1369 "matchcom.pcc"
               } break;
            case a_Match::tag_CONSmatch: {
               if (((Match_CONSmatch *)m)->_4) {
                  switch (((Match_CONSmatch *)m)->_4->tag__) {
                     case a_Ty::tag_TYCONty: {
                        if (boxed(((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1)) {
                           switch (((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1->tag__) {
                              case a_TyCon::tag_DATATYPEtycon: {
#line 1375 "matchcom.pcc"
                               for (int i = ((Match_CONSmatch *)m)->_5 - 1; i >= 0; i--) always_matchables(((Match_CONSmatch *)m)->_6[i],set);
                                 if (! (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)m)->_4)->_1)->qualifiers & QUALextensible)) return;
                                 m = ((Match_CONSmatch *)m)->_7;
                                 
#line 1378 "matchcom.pcc"
                                 } break;
                              default: { goto L53; } break;
                           }
                        } else { goto L53; }
                        } break;
                     default: { goto L53; } break;
                  }
               } else { goto L53; }
               } break;
            case a_Match::tag_TREECOSTmatch: {
#line 1379 "matchcom.pcc"
              set.Intersect(*((Match_TREECOSTmatch *)m)->_2); m = ((Match_TREECOSTmatch *)m)->_1; 
#line 1379 "matchcom.pcc"
               } break;
            case a_Match::tag_TREELABELmatch: {
#line 1380 "matchcom.pcc"
              m = ((Match_TREELABELmatch *)m)->_1; 
#line 1380 "matchcom.pcc"
               } break;
            default: { goto L53; } break;
         }
      } else { goto L53; }
   }
   L53:;
}
#line 1381 "matchcom.pcc"
#line 1381 "matchcom.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Top level routine to call the above
//
///////////////////////////////////////////////////////////////////////////////
const BitSet& always_matchables(Match m, int n)
{  BitSet * set = new (mem_pool, n) BitSet;
   set->complement();
   always_matchables(m, *set);
   return *set;
}
#line 1395 "matchcom.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 3366
Number of ifs generated      = 151
Number of switches generated = 114
Number of labels             = 44
Number of gotos              = 210
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
