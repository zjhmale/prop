///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.6),
//  last updated on Nov 2, 1999.
//  The original source file is "matchgen.pcc".
///////////////////////////////////////////////////////////////////////////////

#line 1 "matchgen.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements the backend for pattern matching,
//  string matching, and lexical scanning constructs.  C++ code is
//  emitted in this file.
//
///////////////////////////////////////////////////////////////////////////////

#include <limits.h>
#include <iostream>
#include <strstream>
#include <AD/contain/bitset.h>
#include <AD/automata/lexergen.h>
#include <AD/strings/charesc.h>
#include <AD/memory/mempool.h>
#include <AD/sort/heapsort.h>
#include <AD/sort/heapsrt2.h>
#include "ir.h"
#include "ast.h"
#include "matchcom.h"
#include "type.h"
#include "labelgen.h"
#include "hashtab.h"
#include "config.h"
#include "options.h"
#include "list.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Class to mark the current rule.
//
///////////////////////////////////////////////////////////////////////////////
MarkCurrentRule::MarkCurrentRule(MatchRule& c, MatchRule n) 
   : current_rule(c), old_rule(c) { c = n; }
MarkCurrentRule::~MarkCurrentRule() { current_rule = old_rule; }

///////////////////////////////////////////////////////////////////////////////
//
//  Method to extract the line number of the current rule
//
///////////////////////////////////////////////////////////////////////////////
int MatchCompiler::current_rule_line() const
{  if (current_rule == 0) bug("MatchCompiler::current_rule_line()\n");
   return current_rule->begin_line;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to extract the text of the current rule
//
///////////////////////////////////////////////////////////////////////////////
const char * MatchCompiler::current_rule_text() const
{  if (current_rule == 0) bug("MatchCompiler::current_rule_text()\n");
   char buffer[4096];
   std::ostrstream stream(buffer,sizeof(buffer));
   std::ostream& s = stream;
   s << current_rule << std::ends;
   buffer[sizeof(buffer)-1] = '\0';
   return make_quoted_string(buffer);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Current index map.
//
///////////////////////////////////////////////////////////////////////////////
HashTable * current_index_map = 0;      
Bool        merge_match       = true;  // should we merge the DFAs?
Id          current_failure   = 0;     // jump label for failure     

///////////////////////////////////////////////////////////////////////////////
//
//  Is the expression simple?
//
///////////////////////////////////////////////////////////////////////////////
Bool is_simple_exp (Exp exp)
{  
#line 77 "matchgen.pcc"
#line 80 "matchgen.pcc"
{
   for (;;) {
      if (exp) {
         switch (exp->tag__) {
            case a_Exp::tag_MARKEDexp: {
#line 79 "matchgen.pcc"
              exp = ((Exp_MARKEDexp *)exp)->_2; 
#line 79 "matchgen.pcc"
               } break;
            case a_Exp::tag_LITERALexp:
            case a_Exp::tag_IDexp: {
#line 78 "matchgen.pcc"
              return true; 
#line 78 "matchgen.pcc"
               } break;
            default: {
               L2:; 
#line 80 "matchgen.pcc"
              return false; 
#line 80 "matchgen.pcc"
               } break;
         }
      } else { goto L2; }
   }
}
#line 81 "matchgen.pcc"
#line 81 "matchgen.pcc"

}


///////////////////////////////////////////////////////////////////////////////
//
//  Generate match variable bindings for complex match expressions. 
//
///////////////////////////////////////////////////////////////////////////////
void compute_match_variables(MatchExps exps)
{  static LabelGen vars("_V");
   for_each (MatchExp, me, exps) 
   {  
#line 93 "matchgen.pcc"
#line 96 "matchgen.pcc"
{
   if (
#line 94 "matchgen.pcc"
   ((me->_2 == 0) && (! is_simple_exp(me->_1)))
#line 94 "matchgen.pcc"
) {
      
#line 95 "matchgen.pcc"
    me->_2 = vars.new_label(); 
#line 95 "matchgen.pcc"
   } else {
      
#line 96 "matchgen.pcc"
     /* skip */ 
#line 96 "matchgen.pcc"
   }
}
#line 97 "matchgen.pcc"
#line 97 "matchgen.pcc"

   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate pattern matching code from a match dag
//
///////////////////////////////////////////////////////////////////////////////
void MatchCompiler::gen(Match mt, MatchOptions match_options, Ty match_ty)
{  
   if (mt == FAILmatch) {
      if (current_failure) pr ("%? goto %s; ", current_failure);
      return;
   }
  
   // check for duplicates
   if (mt->label)      { pr ("%? goto %s; ", mt->label); gotos++; return; }
   if (mt->shared > 1) { goto_labels++; 
                        pr ("%^%s:; ", mt->label = labels.new_label()); }
   
#line 117 "matchgen.pcc"
#line 190 "matchgen.pcc"
{
   if (boxed(mt)) {
      switch (mt->tag__) {
         case a_Match::tag_SUCCESSmatch: {
#line 120 "matchgen.pcc"
           MarkCurrentRule mark(current_rule,((Match_SUCCESSmatch *)mt)->_2); pr ("%&", ((Match_SUCCESSmatch *)mt)->_2->_5); 
#line 120 "matchgen.pcc"
            } break;
         case a_Match::tag_SUCCESSESmatch: {
#line 125 "matchgen.pcc"
           if (current_options & MATCHwithtreecost)
            gen_treecost_match(FAILmatch,((Match_SUCCESSESmatch *)mt)->_2,((Match_SUCCESSESmatch *)mt)->_3); 
            else
            gen_success_match(((Match_SUCCESSESmatch *)mt)->_1,((Match_SUCCESSESmatch *)mt)->_2,((Match_SUCCESSESmatch *)mt)->_3); 
            
#line 129 "matchgen.pcc"
            } break;
         case a_Match::tag_COSTmatch: {
#line 121 "matchgen.pcc"
           gen_cost_success_match(((Match_COSTmatch *)mt)->_1,((Match_COSTmatch *)mt)->_3,((Match_COSTmatch *)mt)->_4); 
#line 121 "matchgen.pcc"
            } break;
         case a_Match::tag_GUARDmatch: {
#line 132 "matchgen.pcc"
          ifs++; pr ("%^if (%E) {%+%^%m%-%?} else {%+%^%m%-%?}\n",((Match_GUARDmatch *)mt)->_1,((Match_GUARDmatch *)mt)->_2,((Match_GUARDmatch *)mt)->_3); 
#line 132 "matchgen.pcc"
            } break;
         case a_Match::tag_LITERALmatch: {
            switch (((Match_LITERALmatch *)mt)->_3[0]->tag__) {
               case a_Literal::tag_REGEXPlit: {
#line 185 "matchgen.pcc"
                 if (options.generate_report) open_logfile() << mt << '\n';
                  gen_regexp_match(((Match_LITERALmatch *)mt)->_2,((Match_LITERALmatch *)mt)->_4,((Match_LITERALmatch *)mt)->_3,((Match_LITERALmatch *)mt)->_5,((Match_LITERALmatch *)mt)->_6,match_options,match_ty); 
                  
#line 187 "matchgen.pcc"
                  } break;
               case a_Literal::tag_QUARKlit: {
#line 189 "matchgen.pcc"
                 gen_quark_match(((Match_LITERALmatch *)mt)->_2,((Match_LITERALmatch *)mt)->_4,((Match_LITERALmatch *)mt)->_3,((Match_LITERALmatch *)mt)->_5,((Match_LITERALmatch *)mt)->_6,match_options); 
#line 189 "matchgen.pcc"
                  } break;
               case a_Literal::tag_BIGINTlit: {
                  L3:; 
#line 190 "matchgen.pcc"
                 bug ("gen(Match)"); 
#line 190 "matchgen.pcc"
                  } break;
               case a_Literal::tag_REALlit:
               case a_Literal::tag_STRINGlit: {
#line 183 "matchgen.pcc"
                 gen_binary_search_on_literals(((Match_LITERALmatch *)mt)->_2,((Match_LITERALmatch *)mt)->_4,((Match_LITERALmatch *)mt)->_3,((Match_LITERALmatch *)mt)->_5,((Match_LITERALmatch *)mt)->_6); 
#line 183 "matchgen.pcc"
                  } break;
               default: {
#line 158 "matchgen.pcc"
                Bool is_boolean;
                  
#line 159 "matchgen.pcc"
#line 161 "matchgen.pcc"
                  {
                     Literal _V1 = ((Match_LITERALmatch *)mt)->_3[0];
                     switch (_V1->tag__) {
                        case a_Literal::tag_BOOLlit: {
#line 160 "matchgen.pcc"
                          is_boolean = true; 
#line 160 "matchgen.pcc"
                           } break;
                        default: {
#line 161 "matchgen.pcc"
                          is_boolean = false; 
#line 161 "matchgen.pcc"
                           } break;
                     }
                  }
#line 162 "matchgen.pcc"
#line 162 "matchgen.pcc"
                  
                  switches++;
                  pr ("%^switch (%e) {\n%+", ((Match_LITERALmatch *)mt)->_2);
                  for (int i = 0; i < ((Match_LITERALmatch *)mt)->_4; ) {
                     int j;
                     for (j = i+1; j < ((Match_LITERALmatch *)mt)->_4; j++) if (((Match_LITERALmatch *)mt)->_5[i] != ((Match_LITERALmatch *)mt)->_5[j]) break;
                     int k = i;
                     if (is_boolean && j == ((Match_LITERALmatch *)mt)->_4 && ((Match_LITERALmatch *)mt)->_4 == 2) {
                        pr ("%^default:"); i = ((Match_LITERALmatch *)mt)->_4;
                     } else {
                        for ( ; i < j; i++) {
                           pr ("%^case %l:", ((Match_LITERALmatch *)mt)->_3[i]);
                           if (i != j - 1) pr ("\n");
                        }         
                     }
                     pr(" {%+%m%-%?} break;\n", ((Match_LITERALmatch *)mt)->_5[k]);
                  }
                  if (! is_boolean || ((Match_LITERALmatch *)mt)->_4 < 2) pr ("%^default: {%+%m%-%?}", ((Match_LITERALmatch *)mt)->_6);
                  pr("%-%^}\n");
                  
#line 181 "matchgen.pcc"
                  } break;
            }
            } break;
         case a_Match::tag_RANGEmatch: {
#line 130 "matchgen.pcc"
           gen_range_match(((Match_RANGEmatch *)mt)->_1,((Match_RANGEmatch *)mt)->_2,((Match_RANGEmatch *)mt)->_3,((Match_RANGEmatch *)mt)->_4,((Match_RANGEmatch *)mt)->_5,((Match_RANGEmatch *)mt)->_6,mt); 
#line 130 "matchgen.pcc"
            } break;
         case a_Match::tag_CONSmatch: {
            if (((Match_CONSmatch *)mt)->_4) {
               switch (((Match_CONSmatch *)mt)->_4->tag__) {
                  case a_Ty::tag_TYCONty: {
                     if (boxed(((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)) {
                        switch (((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1->tag__) {
                           case a_TyCon::tag_DATATYPEtycon: {
                              if (
#line 135 "matchgen.pcc"
                              (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->qualifiers & QUALview)
#line 135 "matchgen.pcc"
) {
                                 
#line 136 "matchgen.pcc"
                                gen_view_match (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->id, ((Match_CONSmatch *)mt)->_2, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->view_match, ((Match_CONSmatch *)mt)->_5, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->terms, ((Match_CONSmatch *)mt)->_6, ((Match_CONSmatch *)mt)->_7,
                                 ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->opt, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->qualifiers & QUALextensible); 
#line 137 "matchgen.pcc"
                              } else {
                                 
                                 switch (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->arg) {
                                    case 0: {
#line 140 "matchgen.pcc"
                                      gen_switch (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->id, ((Match_CONSmatch *)mt)->_2, ((Match_CONSmatch *)mt)->_3, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->unit, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->terms, ((Match_CONSmatch *)mt)->_6, ((Match_CONSmatch *)mt)->_7, mt->shared,
                                       false, false, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->opt, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->qualifiers & QUALextensible); 
#line 141 "matchgen.pcc"
                                    } break;
                                    default: {
                                       switch (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->unit) {
                                          case 0: {
#line 144 "matchgen.pcc"
                                            gen_switch (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->id, ((Match_CONSmatch *)mt)->_2, ((Match_CONSmatch *)mt)->_3, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->arg, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->terms, ((Match_CONSmatch *)mt)->_6, ((Match_CONSmatch *)mt)->_7, mt->shared,
                                             false, true, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->opt, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->qualifiers & QUALextensible); 
#line 145 "matchgen.pcc"
                                          } break;
                                          default: {
#line 148 "matchgen.pcc"
                                           ifs++;
                                             pr ((((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->unit > 1 ? "%^if (boxed(%e)) {%+" : "%^if (%e) {%+"), ((Match_CONSmatch *)mt)->_2);
                                             gen_switch (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->id, ((Match_CONSmatch *)mt)->_2, ((Match_CONSmatch *)mt)->_3, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->arg, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->terms + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->unit, ((Match_CONSmatch *)mt)->_6 + ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->unit, ((Match_CONSmatch *)mt)->_7, mt->shared,
                                                         true, true, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->opt, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->qualifiers & QUALextensible);
                                             pr ("%-%?} else {%+");
                                             gen_switch (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->id, ((Match_CONSmatch *)mt)->_2, ((Match_CONSmatch *)mt)->_3, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->unit, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->terms, ((Match_CONSmatch *)mt)->_6, ((Match_CONSmatch *)mt)->_7, mt->shared,
                                                         true, false, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->opt, ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)((Match_CONSmatch *)mt)->_4)->_1)->qualifiers & QUALextensible);
                                             pr ("%-%?}\n");
                                             
#line 156 "matchgen.pcc"
                                          }
                                       }
                                    }
                                 }
                              }
                              } break;
                           default: { goto L3; } break;
                        }
                     } else { goto L3; }
                     } break;
                  default: { goto L3; } break;
               }
            } else { goto L3; }
            } break;
         case a_Match::tag_TREECOSTmatch: {
#line 122 "matchgen.pcc"
           gen_treecost_match(((Match_TREECOSTmatch *)mt)->_1,((Match_TREECOSTmatch *)mt)->_2,((Match_TREECOSTmatch *)mt)->_3); 
#line 122 "matchgen.pcc"
            } break;
         case a_Match::tag_TREELABELmatch: {
#line 123 "matchgen.pcc"
           gen_treelabel_match(((Match_TREELABELmatch *)mt)->_1,((Match_TREELABELmatch *)mt)->_2,((Match_TREELABELmatch *)mt)->_3,((Match_TREELABELmatch *)mt)->_4); 
#line 123 "matchgen.pcc"
            } break;
         default: { goto L3; } break;
      }
   } else {
      if (mt) {
          goto L3; } else {
         }
   }
}
#line 191 "matchgen.pcc"
#line 191 "matchgen.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate a bitmap of all the successful matching rules.
//
///////////////////////////////////////////////////////////////////////////////
void MatchCompiler::gen_success_match(int n, const BitSet * set, MatchRules)
{  pr ("%^{%+  static const unsigned char matched_set__[%i] =\n%^{  %+",
       (n + 7) / 8
      );
   for(int i = 0; i < (n + 7) / 8; i++) {
      if (i > 0) pr (", ");
      if (i != 0 && (i % 8) == 0) pr ("%^");
      pr ("%i ", (int)set->byte(i));
   }
   pr ("%-};\n"
       "%^m__ = matched_set__;\n"
       "%-%^}\n"
      );
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate code for cost minimalization.
//
///////////////////////////////////////////////////////////////////////////////
void MatchCompiler::gen_cost_success_match(int n, const BitSet * set, 
                                           MatchRules rules)
{  int rule_no = 0;
   
#line 222 "matchgen.pcc"
#line 237 "matchgen.pcc"
{
   for (;;) {
      if (rules) {
#line 224 "matchgen.pcc"
       if ((*set)[rule_no])
         {  
#line 225 "matchgen.pcc"
#line 232 "matchgen.pcc"
         {
            MatchRule _V2 = rules->_1;
#line 227 "matchgen.pcc"
          
#line 227 "matchgen.pcc"
#line 231 "matchgen.pcc"
            {
               Cost _V3 = _V2->_4;
               if (_V3) {
                  if (untagp(_V3)) {
                     } else {
                     }
               } else {}
            }
#line 231 "matchgen.pcc"
#line 231 "matchgen.pcc"
            
            
#line 232 "matchgen.pcc"
         }
#line 233 "matchgen.pcc"
#line 233 "matchgen.pcc"
         
         }
         rules = rules->_2;
         rule_no++;
         
#line 237 "matchgen.pcc"
      } else { goto L4; }
   }
   L4:;
}
#line 238 "matchgen.pcc"
#line 238 "matchgen.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate a switch statement for pattern matching.
//  This method is responsible for generating optimized code for a one-level
//  match using C++'s "switch" statement.
//
///////////////////////////////////////////////////////////////////////////////
void MatchCompiler::gen_switch 
   (Id id, Exp e, Ty ty, int n, Cons terms[], Match m[], Match def, int shared,
    Bool variant, Bool boxed, TyOpt optimizations, Bool is_refutable)
{  
   if (n == 1) {          // only one arm
      gen(m[0]); 
   } else if (n == 2) {   // two arms, use "if"
      if (m[0] == m[1]) {
         merges++; if (m[0] != FAILmatch) m[0]->shared -= shared; gen(m[0]); 
      } else {
         ifs++;
         Id prefix, suffix;
         if (boxed) {
            if (optimizations & OPTtaggedpointer) 
            { prefix = "untagp("; suffix = ")"; } 
            else 
            { prefix = ""; suffix = "->tag__"; }
         } else { prefix = suffix = ""; }
          
         pr ("%^if (%s%e%s) {%+%^%m%-%?} else {%+%^%m%-%?}\n",
             prefix, e, suffix, m[1], m[0]);
      }
   } else {   
      /////////////////////////////////////////////////////////////////////////
      //  The following is the general case for handling n-ary branches. 
      /////////////////////////////////////////////////////////////////////////
      int i, j;

      /////////////////////////////////////////////////////////////////////////
      // If all n branches are the same, eliminate the match
      /////////////////////////////////////////////////////////////////////////
      for (i = n - 1; i > 0; i--) if (m[i] != m[i-1]) break;
      if (i == 0) { if (m[0] != FAILmatch) m[0]->shared -= (n-1) * shared;
                    merges++; gen(m[0]); return; 
                  }

      switches++;
      Id prefix, suffix;

      /////////////////////////////////////////////////////////////////////////
      // Generate the "switch" expression.
      /////////////////////////////////////////////////////////////////////////
      if (boxed) {
         if (optimizations & OPTtaggedpointer) 
         { prefix = "untagp("; suffix = ")"; } 
         else 
         { prefix = ""; suffix = "->tag__"; }
      } else { 
         if (variant) 
         { prefix = "(int)"; suffix = ""; }
         else 
         { prefix = suffix = ""; }
      }
      pr ("%^switch (%s%e%s) {\n%+", prefix, e, suffix);

      /////////////////////////////////////////////////////////////////////////
      //  Partition the arms of the matches into alternatives with the
      //  same actions.  Sort the partitions in increasing sizes.
      /////////////////////////////////////////////////////////////////////////
      struct ConsMatch
      { Cons term; Match action; int tag; };
      struct MatchPartition 
      { int count; Conses terms; Match action; int first_tag; };
      ConsMatch      * sorted  = (ConsMatch *)mem_pool.c_alloc
                                     (sizeof(ConsMatch) * n);
      MatchPartition * parts   = (MatchPartition *)mem_pool.c_alloc
                                     (sizeof(MatchPartition) * n);
      int number_of_parts = 0;
      {  for (i = 0; i < n; i++)
         {  sorted[i].term      = terms[i];
            sorted[i].action    = m[i]; 
            if (terms[i] != NOcons) sorted[i].tag = terms[i]->tag;
         }

         // sort branches according the actions
         heapSort(ConsMatch, sorted, n,
                  (key.action < sorted[i].action || 
                   key.action == sorted[i].action && 
                   key.tag < sorted[i].tag));

         // partition each branch by action 
         for (i = n - 1; i >= 0; i--)
         {  if (i == n-1 || sorted[i].action != sorted[i+1].action) 
            {  parts[number_of_parts].terms  = 
#line 331 "matchgen.pcc"
#line 331 "matchgen.pcc"
list_1_(sorted[i].term)
#line 331 "matchgen.pcc"
#line 331 "matchgen.pcc"
;
               parts[number_of_parts].action = sorted[i].action;
               parts[number_of_parts].count  = 1;
               parts[number_of_parts].first_tag = sorted[i].tag;
               number_of_parts++; 
            } else {
               parts[number_of_parts-1].terms = 
                   
#line 338 "matchgen.pcc"
#line 338 "matchgen.pcc"
list_1_(sorted[i].term,parts[(number_of_parts - 1)].terms)
#line 338 "matchgen.pcc"
#line 338 "matchgen.pcc"
;
               parts[number_of_parts-1].count++;
               if (parts[number_of_parts-1].first_tag > sorted[i].tag)  
                  parts[number_of_parts-1].first_tag = sorted[i].tag;
            }
         }

         // Sort partitions in order of frequency; so that
         // the most frequent case becomes the "default" inside
         // the "switch" statement.  
         heapSort(MatchPartition, parts, number_of_parts, 
                  (key.count < parts[i].count || 
                   key.count == parts[i].count &&
                   key.first_tag < parts[i].first_tag));
      }

      /////////////////////////////////////////////////////////////////////////
      // Generate the arms of the "switch".
      // We try to combine the arms that are the same together into
      // one rule to help the compiler.
      /////////////////////////////////////////////////////////////////////////
      for (i = 0; i < number_of_parts; i++)
      {  if (i == number_of_parts - 1) {
            pr ("%^default:"); 
         } else {
            Conses tags = parts[i].terms; 
            
#line 364 "matchgen.pcc"
#line 369 "matchgen.pcc"
{
   for (;;) {
      if (tags) {
#line 366 "matchgen.pcc"
       pr ("%^case %*:", tags->_1, false);
         if (tags->_2 != 
#line 367 "matchgen.pcc"
#line 367 "matchgen.pcc"
         nil_1_
#line 367 "matchgen.pcc"
#line 367 "matchgen.pcc"
         ) pr ("\n");
         tags = tags->_2;
         
#line 369 "matchgen.pcc"
      } else { goto L5; }
   }
   L5:;
}
#line 370 "matchgen.pcc"
#line 370 "matchgen.pcc"

         }
         if (parts[i].action != FAILmatch)
            parts[i].action->shared -= (parts[i].count - 1) * shared;
         pr (" {%+%?%m%?} break;\n%-", parts[i].action);
      }

      pr ("%-%^}\n");
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate binary search for testing literals
//
///////////////////////////////////////////////////////////////////////////////
void MatchCompiler::gen_binary_search_on_literals
   (Exp e, int n, Literal l[], Match m[], Match d)
{  if (n <= 4) { 
      /////////////////////////////////////////////////////////////////////////
      //  Generate linear tests for simple literal tests.
      /////////////////////////////////////////////////////////////////////////
      for (int i = 0; i < n; i++) {  
         ifs++;
         if (i > 0) pr("%^else "); else pr ("%^");
         pr ("if (%=(%e,%l)) {%m}\n",l[i], e, l[i], m[i]);
      }
      if (d != FAILmatch) pr ("%^else {%m}\n", d);
      else if (current_failure) pr ("%^else goto %s;\n", current_failure);
   } else { 
      /////////////////////////////////////////////////////////////////////////
      //  Generate binary search for tests containing many alternatives.
      /////////////////////////////////////////////////////////////////////////
      int k = (n+1)/2;
      ifs++;
      pr ("%^if (%<(%e,%l)) {\n%+", l[k], e, l[k]);
      gen_binary_search_on_literals(e,k,l,m,d);
      pr ("%-%^} else {\n%+");
      gen_binary_search_on_literals(e,n-k,l+k,m+k,d);
      pr ("%-%^}\n");
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate range matching
//
///////////////////////////////////////////////////////////////////////////////
void MatchCompiler::gen_range_match
   (Pos pos, Exp e, int lo, int hi, Match a, Match b, Match m)
{  if (lo == hi)
   {  switches++;
      pr ("%^switch (%e) {%+",e);
      
#line 423 "matchgen.pcc"
#line 425 "matchgen.pcc"
{
   for (;;) {
      if (boxed(m)) {
         switch (m->tag__) {
            case a_Match::tag_RANGEmatch: {
               if (
#line 424 "matchgen.pcc"
               ((((Match_RANGEmatch *)m)->_3 == ((Match_RANGEmatch *)m)->_4) && pos_equal(pos,((Match_RANGEmatch *)m)->_1))
#line 424 "matchgen.pcc"
) {
                  
#line 425 "matchgen.pcc"
                 pr ("%^case %i: {%+%m%-%?} break;", ((Match_RANGEmatch *)m)->_3, ((Match_RANGEmatch *)m)->_5); m = ((Match_RANGEmatch *)m)->_6; 
#line 425 "matchgen.pcc"
               } else {
                   goto L6; }
               } break;
            default: { goto L6; } break;
         }
      } else { goto L6; }
   }
   L6:;
}
#line 426 "matchgen.pcc"
#line 426 "matchgen.pcc"

      pr ("%^default: {%+%m%-%?}"
          "%-%^}\n", m
         );
   } else 
   {  ifs++;
      if (lo == 0) {
         pr ("%^if (%e <= %i) {%+%^%m%-%?} else {%+%^%m%-%?}\n",e,hi,a,b); 
      } else if (hi == INT_MAX) {
         pr ("%^if (%e >= %i) {%+%^%m%-%?} else {%+%^%m%-%?}\n",e,lo,a,b); 
      } else {
         pr ("%^if (%i <= %e && %e <= %i) {%+%^%m%-%?} else {%+%^%m%-%?}\n",
             lo,e,e,hi,a,b); 
      }
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate view matching 
//
///////////////////////////////////////////////////////////////////////////////
void MatchCompiler::gen_view_match  
   (Id id, Exp e, Exp view_match, int n, Cons terms [], Match m[], Match d,
    TyOpt opt, TyQual qual)
{  if (view_match != NOexp)
   {  switches++;
      pr ("%^switch (%e) {%+", subst(view_match,&e));
      for (int i = 0; i < n; i++)
      {  pr ("%^case %e: {%+%m%-%?} break;", terms[i]->view_predicate, m[i]);
      }
      pr ("%-%^}\n");
   } else 
   {  int i;
      for (i = 0; i < n; i++)
      {  int j;
         for (j = i + 1; j < n; j++) if (m[i] != m[j]) break;
         if (j == n) break;
         Exp predicate_fun = terms[i]->view_predicate;
         Exp predicate     = subst(predicate_fun,&e);
         ifs++;
         pr("%^%sif (%e) {%+%^%m%-%?} ", 
            (i > 0 ? "else " : ""), predicate, m[i]);
      }
      if (i < n)
         pr ("%^%s{%+%^%m%-%?}\n", (i > 0 ? "else " : ""), m[i]);
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate regular expression matching as a DFA.
//
///////////////////////////////////////////////////////////////////////////////
void MatchCompiler::gen_regexp_match
   (Exp e, int n, Literal l[], Match m[], Match d, 
    MatchOptions options, Ty match_ty)
{  LexerGen lexerGen;
   const char ** regexps = (const char **)mem_pool[n * sizeof(const char *)];
   const char ** contexts = 0;

   ////////////////////////////////////////////////////////////////////////////
   //  If we have a match type, locate the set of contexts.
   ////////////////////////////////////////////////////////////////////////////
   if (options & MATCHscanner) 
   {  
#line 491 "matchgen.pcc"
#line 505 "matchgen.pcc"
{
   Ty _V4 = deref_all(match_ty);
   if (_V4) {
      switch (_V4->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V4)->_1)) {
               switch (((Ty_TYCONty *)_V4)->_1->tag__) {
                  case a_TyCon::tag_DATATYPEtycon: {
#line 494 "matchgen.pcc"
                   contexts = (const char **)mem_pool[(((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V4)->_1)->unit+1)*sizeof(const char *)];
                     if (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V4)->_1)->unit <= 1)
                        msg("%L%wdatatype has less than 2 unit constructors for contexts");
                     for (int i = 1; i < ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V4)->_1)->unit; i++)
                     {  
#line 498 "matchgen.pcc"
#line 501 "matchgen.pcc"
                     {
                        Cons _V5 = ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V4)->_1)->terms[i];
                        if (_V5) {
#line 499 "matchgen.pcc"
                          contexts[i-1] = _V5->name; 
#line 499 "matchgen.pcc"
                        } else {}
                     }
#line 501 "matchgen.pcc"
#line 501 "matchgen.pcc"
                     
                     }
                     contexts[((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V4)->_1)->unit-1] = 0;
                     
#line 504 "matchgen.pcc"
                     } break;
                  default: {
                     L7:; 
#line 505 "matchgen.pcc"
                    error ("%Lillegal context type: %T\n", match_ty); 
#line 505 "matchgen.pcc"
                     } break;
               }
            } else { goto L7; }
            } break;
         default: { goto L7; } break;
      }
   } else {}
}
#line 506 "matchgen.pcc"
#line 506 "matchgen.pcc"

   }
   
   ////////////////////////////////////////////////////////////////////////////
   //  Allocate a regexp array 
   ////////////////////////////////////////////////////////////////////////////
   for (int i = 0; i < n; i++) 
   {  
#line 513 "matchgen.pcc"
#line 520 "matchgen.pcc"
{
   Literal _V6 = l[i];
   switch (_V6->tag__) {
      case a_Literal::tag_REGEXPlit: {
#line 515 "matchgen.pcc"
       int len           = strlen(((Literal_REGEXPlit *)_V6)->REGEXPlit);
         char * regexp     = str_pool(((Literal_REGEXPlit *)_V6)->REGEXPlit+1,len-1); 
         regexp[len-2]     = '\0';
         regexps[i]        = regexp;
         
#line 519 "matchgen.pcc"
         } break;
      default: {
#line 520 "matchgen.pcc"
        bug("gen_regexp_match"); 
#line 520 "matchgen.pcc"
         } break;
   }
}
#line 521 "matchgen.pcc"
#line 521 "matchgen.pcc"

   }

   int opt = LexerGen::None;
   if (options & MATCHscanner) 
   {  opt |= LexerGen::Backtracking;
      debug_msg("%Lgenerating backtracking scanner\n");
   }
   if (options & MATCHcaseinsensitive) opt |= LexerGen::CaseInsensitive;

   lexerGen.compile(n, regexps, contexts, 255, opt);

   if (! lexerGen.ok()) {
      error ("%L%s in: %l\n", lexerGen.error_message(), l[lexerGen.bad()]);
   } else {
      /////////////////////////////////////////////////////////////////////////
      //  Generate the action code
      /////////////////////////////////////////////////////////////////////////
      Id id = vars.new_label();
      pr ("%^{\n%+");   
      lexerGen.gen_code(*output, id);
      switches++;
      pr ("%^static const RegexMatch %s"
          "%^                 ( %s_base,"
          "%^                   %s_check,"
          "%^                   %s_def,"
          "%^                   %s_next,"
          "%^                   %s_accept_rule,"
          "%^                   %s_equiv_classes );\n",
          id, id, id, id, id, id, id); 
      Id rule_binding = "";
      if (options & MATCHlexemepat)
      {  pr ("%^int rule__;"); 
         rule_binding = "rule__ = ";
      }
      if (options & MATCHscanner) {
         pr ("%^const char * next;\n"
             "%^switch(%s%s.MatchText(RegexMatch::start_state,%e,next)) {%+", 
             rule_binding, id, e);
      } else {
         pr ("%^switch(%s%s.MatchText(%e)) {%+", rule_binding, id, e);
      }
      for (int i = 0; i < n; i++) 
         pr ("%^case %i: {%+%m%-%?} break;", i+1, m[i]);
      pr ("%^default: {%+%m%-%?}", d); 
      pr ("%-%^}\n"
          "%-%^}\n");
       
      /////////////////////////////////////////////////////////////////////////
      //  Generate a report
      /////////////////////////////////////////////////////////////////////////
      if (::options.generate_report) lexerGen.print_report(open_logfile());
   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate quark pattern matching 
//
///////////////////////////////////////////////////////////////////////////////
void MatchCompiler::gen_quark_match
   (Exp e, int n, Literal l[], Match m[], Match d, MatchOptions options)
{  for (int i = 0; i < n; i++)
   {  ifs++;
      pr ("%^%sif (%e == %l) {%+%^%m%-%?} ",
          (i > 0 ? "else " : ""), e, l[i], m[i]);
   }
   pr ("%^%s{%+%^%m%-%?}\n", (n > 0 ? "else " : ""), d);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to translate and merge a set of patterns
//
///////////////////////////////////////////////////////////////////////////////
Match MatchCompiler::trans_merge
   (int n, MatchRules rules, int match_options, Cost * costs)
{  Match m = FAILmatch;
   int rule_no = 0;
   for_each(MatchRule, r, rules)
   {  
#line 601 "matchgen.pcc"
#line 621 "matchgen.pcc"
{
#line 603 "matchgen.pcc"
 if (! r->is_chain_rule)
   {  Match rhs;
      if (match_options & (MATCHall | MATCHwithcost)) {
         BitSet * set = new (mem_pool,n) BitSet;
         set->add(rule_no);
         if (costs && ! (match_options & MATCHwithtreecost)) 
             rhs = COSTmatch(n,costs,set,rules);
         else
             rhs = SUCCESSESmatch(n,set,rules);
      } else {
         r->used = false; rhs = SUCCESSmatch(rule_no,r);
      }
      if (r->_3 != NOexp) rhs = GUARDmatch(r->_3,rhs,FAILmatch);
      rhs = trans(r->_2, POSzero, false, rhs, FAILmatch);
      debug_msg("%r => %M\n", r, rhs);
      m = merge (m, rhs);
   }
   rule_no++;
   
#line 621 "matchgen.pcc"
}
#line 622 "matchgen.pcc"
#line 622 "matchgen.pcc"

   }
   return m;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to translate but do not merge a set of patterns.
//  Use Wadler's algorithm.
//
///////////////////////////////////////////////////////////////////////////////
Match MatchCompiler::trans_no_merge
   (int n, int rule_no, MatchRules rules, int match_options, Cost * costs)
{
   if (rules == 
#line 636 "matchgen.pcc"
#line 636 "matchgen.pcc"
nil_1_
#line 636 "matchgen.pcc"
#line 636 "matchgen.pcc"
) return FAILmatch;
   else {
      
#line 638 "matchgen.pcc"
#line 653 "matchgen.pcc"
{
   MatchRule _V7 = rules->_1;
#line 640 "matchgen.pcc"
 Match rhs;
   if (match_options & (MATCHall | MATCHwithcost)) {
      BitSet * set = new (mem_pool,n) BitSet;
      set->add(rule_no);
      if (costs) rhs = COSTmatch(n,costs,set,rules);
      else       rhs = SUCCESSESmatch(n,set,rules);
   } else {
      _V7->used = false; rhs = SUCCESSmatch(rule_no,_V7);
   }
   Match no = 
      trans_no_merge(n, rule_no+1, rules->_2, match_options, costs);
   if (_V7->_3 != NOexp) rhs = GUARDmatch(_V7->_3,rhs,no);
   return trans(_V7->_2, POSzero, false, rhs, no);
   
#line 653 "matchgen.pcc"
}
#line 654 "matchgen.pcc"
#line 654 "matchgen.pcc"

   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Instrument the matching code if tracing is on
//
///////////////////////////////////////////////////////////////////////////////
void MatchCompiler::instrument_trace(MatchRules rules)
{  for_each(MatchRule, r, rules)
   {  
#line 665 "matchgen.pcc"
#line 682 "matchgen.pcc"
{
#line 667 "matchgen.pcc"
 char buffer[4096];
   std::ostrstream stream(buffer, sizeof(buffer));
   std::ostream& s = stream;
   s << r << std::ends;
   r->_5 =
     
#line 672 "matchgen.pcc"
#line 672 "matchgen.pcc"
   list_1_(EXPdecl(APPexp(IDexp("PROP_TRACE"),TUPLEexp(list_1_(LITERALexp(STRINGlit(make_quoted_string(buffer))),list_1_(LITERALexp(STRINGlit(make_quoted_string(r->file_name))),list_1_(LITERALexp(INTlit(r->begin_line)))))))),list_1_(OPAQUEdecl(";"),r->_5))
#line 681 "matchgen.pcc"
#line 681 "matchgen.pcc"
   ;
   
#line 682 "matchgen.pcc"
}
#line 683 "matchgen.pcc"
#line 683 "matchgen.pcc"

   }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Compute the match dag from a set of pattern matching rules.
//
///////////////////////////////////////////////////////////////////////////////
Match MatchCompiler::match_of
   (int n, MatchRules rules, MatchOptions match_options)
{  Match m;

   ////////////////////////////////////////////////////////////////////////////
   //  Save the last index map.
   ////////////////////////////////////////////////////////////////////////////
   HashTable * last_index_map = current_index_map;

   ////////////////////////////////////////////////////////////////////////////
   //  Create index map for this pattern set if necessary.
   ////////////////////////////////////////////////////////////////////////////
   if (options.adaptive_matching) {
      debug_msg("Creating index map\n");
      current_index_map = new HashTable(pos_hash, pos_equal, 129);
      indexing(rules, *current_index_map);
      debug_msg("Finished indexing\n");
   } else {
      current_index_map = 0;
   }

   ////////////////////////////////////////////////////////////////////////////
   //  If tracing is on, instrument the code.
   ////////////////////////////////////////////////////////////////////////////
   if (options.trace && (match_options & MATCHnotrace) == 0) 
      instrument_trace(rules);

   ////////////////////////////////////////////////////////////////////////////
   //  Make a cost vector if cost minimization is in effect
   ////////////////////////////////////////////////////////////////////////////
   Cost * cost_vector = 0;
   if (match_options & MATCHwithintcost)
   {  cost_vector = (Cost*)mem_pool[n * sizeof(Cost)];
      int i = 0;
      for_each(MatchRule, r, rules)
      {  
#line 727 "matchgen.pcc"
#line 728 "matchgen.pcc"
{
#line 728 "matchgen.pcc"
  cost_vector[i] = r->_4; i++; 
#line 728 "matchgen.pcc"
}
#line 728 "matchgen.pcc"
#line 728 "matchgen.pcc"

      }
   }

   ////////////////////////////////////////////////////////////////////////////
   //  Translate each pattern into a matching tree and merge them together.
   ////////////////////////////////////////////////////////////////////////////
   if (merge_match)
      m = trans_merge(n, rules, match_options, cost_vector);
   else
      m = trans_no_merge(n, 0, rules, match_options, cost_vector);

   m = make_dag (m, match_options, rules);
   debug_msg("Matching DFA: %M\n", m);

   ////////////////////////////////////////////////////////////////////////////
   // Error checking.
   ////////////////////////////////////////////////////////////////////////////
   // BUG 3/6/97: Always check for selectability!!!
   if (true || (match_options & MATCHnocheck) == 0) {      
      if (match_options & (MATCHall | MATCHwithcost)) {
         BitSet * may_match = new (mem_pool,n) BitSet;
         matchables(m,*may_match);
         int i = 0;
         for_each (MatchRule, r, rules)
         {  if (! may_match->contains(i) && ! r->is_chain_rule) 
               error("%!this rule is never selected: %r\n", r->loc(), r); 
            i++;
         }
      } else {
         {  for_each (MatchRule,r,rules) 
            {  if (! r->used) 
                  error ("%!this rule is never used: %r\n", r->loc(), r); 
            }
         }
      } 
   }

   ////////////////////////////////////////////////////////////////////////////
   //  Clean up the index map
   ////////////////////////////////////////////////////////////////////////////
   if (current_index_map) delete current_index_map;
   current_index_map = last_index_map;
   return m;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Returns true if the set of rules involve cost expressions.
//
///////////////////////////////////////////////////////////////////////////////
int involve_cost(MatchRules rules)
{  int options = MATCHnone;
   for_each(MatchRule, r, rules)
   {  
#line 782 "matchgen.pcc"
#line 788 "matchgen.pcc"
{
   if (r->_4) {
      if (untagp(r->_4)) {
         
#line 784 "matchgen.pcc"
        options |= MATCHwithcost | MATCHwithintcost; 
#line 784 "matchgen.pcc"
      } else {
         
#line 786 "matchgen.pcc"
        options |= MATCHwithcost | MATCHwithexpcost; 
#line 786 "matchgen.pcc"
      }
   } else {}
}
#line 788 "matchgen.pcc"
#line 788 "matchgen.pcc"

   }
   return options;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to check for refutable set of rules and print out
//  warning/error messages.
//
///////////////////////////////////////////////////////////////////////////////
static Bool check_refutable
   (Match m, MatchRules rules, MatchOptions match_options)
{   Bool is_refutable = refutable(m);            // error checking
    if (! (match_options & MATCHnocheck) &&
        ! (match_options & MATCHwhile) && is_refutable) {
      msg ("%!%wpatterns are not exhaustive:\n", rules->_1->loc());
      for_each(MatchRule,r,rules) msg("%!\t%r\n", r->loc(), r);
    }
    return is_refutable;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Compile a match/matchall statement.
//
///////////////////////////////////////////////////////////////////////////////
void MatchCompiler::gen_match_stmt
   (MatchExps exps, MatchRules rules, MatchOptions match_options, Ty match_ty)
{  MemPoolMark marker = mem_pool.getMark();     // set heap marker
   int n              = length(rules);
   Ty pattern_tys     = type_match_rules(rules);    // type inference
   Id save_failure    = current_failure; 
   current_failure    = 0;
   MatchOptions save  = current_options;
   current_options    = match_options;

   if (pattern_tys != NOty) {
      pr ("%^{\n%+");
      if (match_options & MATCHwhile) {
         pr ("%^for (;;) {%+"); current_failure = labels.new_label();
      }

      // check for cost expressions
      int cost_opts = involve_cost(rules);      
      if (cost_opts & MATCHwithcost) {
         if (match_options & MATCHall)
            if (! (match_options & MATCHwithtreecost))
               msg ("%L%wmatching costs are ignored.\n");
         else
            match_options |= cost_opts;
      }

      Match m = match_of(n, rules, match_options); // compile patterns
      Bool is_refutable = check_refutable(m, rules, match_options); 

      // prefix code for matchall
      if ((match_options & (MATCHall | MATCHwithcost)) &&
          ! (match_options & MATCHwithtreecost))
         pr ("%^const unsigned char * m__%s;\n", (is_refutable ? " = 0" : ""));

      gen_match_variables(exps, pattern_tys);
      gen(m, match_options, match_ty);

      // suffix code for cost minimization
      if (! (match_options & MATCHwithtreecost))
      {  if (match_options & MATCHwithexpcost)
            gen_match_cost_minimization(n, m, rules, is_refutable);

         // suffix code for matchall
         else if (match_options & MATCHall) 
            gen_matchall_suffix(n, m, rules, is_refutable);
      }

      if (match_options & MATCHwhile) 
      {  pr ("%-%^}");
         if (is_refutable) pr("%^%s:;", current_failure);
      }
      pr ("%-%^}");
   }
   mem_pool.setMark(marker); // release all memory used
   current_failure = save_failure; 
   current_options = save;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate suffix code for a matchall statement.
//  The suffix code goes thru the bitmap and select all rule with
//  its bit set.
//
///////////////////////////////////////////////////////////////////////////////
void MatchCompiler::gen_matchall_suffix
   (int n, Match m, MatchRules rules, Bool is_refutable)
{  int index = 0; int bit = 0; 
   const BitSet& always_match = always_matchables(m,n);
   if (is_refutable) { ifs++; pr ("%^if (m__) {%+"); }

   for_each (MatchRule, r, rules) 
   {  
#line 887 "matchgen.pcc"
#line 898 "matchgen.pcc"
{
#line 889 "matchgen.pcc"
 if (! always_match.contains(index * 8 + bit)) {
   ifs++;
   pr ("%^if (m__[%i] & %i) ", index, 1 << bit);
   } else {
   pr ("%^");
   }
   	    MarkCurrentRule mark(current_rule,r);
   pr ("{%+%&%-%?}\n", r->_5);
   if (++bit == 8) { bit = 0; index++; }
   
#line 898 "matchgen.pcc"
}
#line 899 "matchgen.pcc"
#line 899 "matchgen.pcc"

   }
   if (is_refutable) pr ("%-%^}");
}  

///////////////////////////////////////////////////////////////////////////////
//
//  Generate suffix code for a match statement with cost minimization.
//  The bitmap selected with determine which cost function to execute.
//  When all the appropriate cost functions are executed, we choose the
//  matched rule with the lowest cost.  Ties are broken by the lexical
//  order of the rules.
//
///////////////////////////////////////////////////////////////////////////////
void MatchCompiler::gen_match_cost_minimization
   (int n, Match m, MatchRules rules, Bool is_refutable)
{  int index, bit;
   const BitSet& always_match = always_matchables(m,n);

   pr ("%^do {%+"
       "%^int tmp_cost__, cost__ = %i, rule__ = -1;", MAX_COST);
   if (is_refutable) { ifs++; pr ("%^if (m__) {%+"); }
   {  index = bit = 0;
      for_each (MatchRule, r, rules) 
      {  pr ("%^");
         if (! always_match.contains(index * 8 + bit)) {
            ifs++;
            pr ("if (m__[%i] & %i) ", index, 1 << bit);
         } 
         int rule_no = index * 8 + bit;
         
#line 929 "matchgen.pcc"
#line 937 "matchgen.pcc"
{
   if (r->_4) {
      if (untagp(r->_4)) {
         
#line 937 "matchgen.pcc"
       pr ("if (cost__ > %i) { cost__ = %i; rule__ = %i; }", ((Cost_INTcost *)derefp(r->_4))->INTcost, ((Cost_INTcost *)derefp(r->_4))->INTcost, rule_no); 
#line 937 "matchgen.pcc"
      } else {
         
#line 931 "matchgen.pcc"
       pr ("if ((tmp_cost__ = %e) < cost__) { cost__ = tmp_cost__; rule_ = %i; }",
         ((Cost_EXPcost *)r->_4)->_1, rule_no);
         
#line 933 "matchgen.pcc"
      }
   } else {
#line 935 "matchgen.pcc"
    pr ("{ rule__ = %i; break; }", rule_no);  
#line 935 "matchgen.pcc"
   }
}
#line 938 "matchgen.pcc"
#line 938 "matchgen.pcc"

         if (++bit == 8) { bit = 0; index++; }
      }
   }
   if (is_refutable) pr ("%-%^}");
   pr ("%-%^} while (0);"
       "%^switch (rule__) {%+");
   {  int i = 0;
      for_each(MatchRule, r, rules)
      {  
#line 947 "matchgen.pcc"
#line 952 "matchgen.pcc"
{
#line 949 "matchgen.pcc"
 MarkCurrentRule mark(current_rule,r);
   pr ("%^case %i: {%+%&%-%?} break;", i, r->_5); 
   	       i++; 
   	    
#line 952 "matchgen.pcc"
}
#line 953 "matchgen.pcc"
#line 953 "matchgen.pcc"

      }
   }
   pr ("%-%^}");
}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate code that binds match variables.
//
///////////////////////////////////////////////////////////////////////////////
void MatchCompiler::gen_match_variables(MatchExps es, Ty ty)
{  Tys tys;
   if (length(es) > 1) {
      
#line 967 "matchgen.pcc"
#line 969 "matchgen.pcc"
{
   Ty _V8 = deref(ty);
   if (_V8) {
      switch (_V8->tag__) {
         case a_Ty::tag_TYCONty: {
            if (boxed(((Ty_TYCONty *)_V8)->_1)) {
               L8:; 
#line 969 "matchgen.pcc"
              bug("gen_match_variables()"); 
#line 969 "matchgen.pcc"
            } else {
               switch ((int)((Ty_TYCONty *)_V8)->_1) {
                  case ((int)TUPLEtycon): {
#line 968 "matchgen.pcc"
                    tys = ((Ty_TYCONty *)_V8)->_2; 
#line 968 "matchgen.pcc"
                     } break;
                  default: { goto L8; } break;
               }
            }
            } break;
         default: { goto L8; } break;
      }
   } else { goto L8; }
}
#line 970 "matchgen.pcc"
#line 970 "matchgen.pcc"

   } else {
      tys = 
#line 972 "matchgen.pcc"
#line 972 "matchgen.pcc"
list_1_(ty)
#line 972 "matchgen.pcc"
#line 972 "matchgen.pcc"
;
   }
   for ( ; es && tys; es = es->_2, tys = tys->_2) {
      
#line 975 "matchgen.pcc"
#line 982 "matchgen.pcc"
{
   MatchExp _V9 = es->_1;
   if (
#line 976 "matchgen.pcc"
   (_V9->_2 != 0)
#line 976 "matchgen.pcc"
) {
      
#line 977 "matchgen.pcc"
    if (! is_ground(tys->_1))
      error ("%!missing type info in expression %e : %T\n", 
             _V9->loc(), _V9->_1, tys->_1);
      pr ("%^%t = %e;\n", tys->_1, _V9->_2, _V9->_1);
      
#line 981 "matchgen.pcc"
   } else {
      
#line 982 "matchgen.pcc"
     /* skip */ 
#line 982 "matchgen.pcc"
   }
}
#line 983 "matchgen.pcc"
#line 983 "matchgen.pcc"

   } 
}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate code for a set of function definitions.
//
///////////////////////////////////////////////////////////////////////////////
void MatchCompiler::gen_fun_def (FunDefs fundefs)
{  // Generate the prototype first (to deal with recursive definitions).
   MemPoolMark marker = mem_pool.getMark();     // set heap marker
   {  for_each (FunDef, f, fundefs)
      {  
#line 996 "matchgen.pcc"
#line 1009 "matchgen.pcc"
{
#line 998 "matchgen.pcc"
 f->_2 = type_match_rules(f->_4);
   char buf[1024];
   std::ostrstream b(buf,sizeof(buf));
   std::ostream& s = b;
   s << f->_1 << std::ends;
   Ty ret_ty = f->_3 == NOty ? void_ty : f->_3;
   pr ("%^%t %b;\n", 
       ret_ty, buf, f->_2, "1", TYformal);
   if (! is_ground(f->_2))
      error ("%!missing type info in function %q %T\n", 
             f->loc(), f->_1, f->_2);
   
#line 1009 "matchgen.pcc"
}
#line 1010 "matchgen.pcc"
#line 1010 "matchgen.pcc"

      }
   }

   // Then generate the body of the functions.
   {  for_each (FunDef, f, fundefs)
      {  
#line 1016 "matchgen.pcc"
#line 1030 "matchgen.pcc"
{
#line 1018 "matchgen.pcc"
 int n = length(f->_4);
   Match m = match_of(n, f->_4, MATCHnone);
   check_refutable(m, f->_4, MATCHnone);
   Ty ret_ty = f->_3 == NOty ? void_ty : f->_3;
   char buf[1024];
   std::ostrstream b(buf,sizeof(buf));
   std::ostream& s = b;
   s << f->_1 << std::ends;
   pr ("%^%t %b\n{\n%+", 
       ret_ty, buf, f->_2, "1", TYformal);
   gen(m);
   pr ("%-%^}\n");
   
#line 1030 "matchgen.pcc"
}
#line 1031 "matchgen.pcc"
#line 1031 "matchgen.pcc"

      }
   }
   mem_pool.setMark(marker); // release all memory used
}
#line 1036 "matchgen.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 147
Number of ifs generated      = 23
Number of switches generated = 14
Number of labels             = 4
Number of gotos              = 12
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
