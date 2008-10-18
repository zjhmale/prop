///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.6),
//  last updated on Nov 2, 1999.
//  The original source file is "rwgen2.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_QUARK_USED
#include <propdefs.h>
///////////////////////////////////////////////////////////////////////////////
//  Quark literals
///////////////////////////////////////////////////////////////////////////////
static const Quark _r_w_g_e_n_2co_c_c_Q2("() {}\n");
static const Quark _r_w_g_e_n_2co_c_c_Q1("\npublic:\n   inline ");
#line 1 "rwgen2.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements the 'rewrite (x) { ... }' construct.
//  We'll transform this construct into the equivalent 'rewrite class ...'
//  and 'rewrite id { ... };' statements.
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream.h>
#include "ir.h"
#include "ast.h"
#include "type.h"
#include "rwgen.h"
#include "options.h"

///////////////////////////////////////////////////////////////////////////////
//
//   Method for compiling a 'rewrite (x) { ... }' statement.
//
///////////////////////////////////////////////////////////////////////////////
void RewritingCompiler::gen_rewriting 
   ( Protocols        protocols,
     Exp              exp,
     Exp              dest,
     RewriteIndexings Is,
     MatchRules       rules,
     TyQual           qualifiers 
   )
{  MEM::use_global_pools();
   Id rewriter_name = Quark(options.mangled_file_prefix,vars.new_label());
   Ty exp_ty        = NOty;
   Ty ret_ty        = NOty;
   TyQual qual = 
      (qualifiers & ~QUALapplicative) | 
      (dest == NOexp ? QUALnone : QUALapplicative);

   // Get the return and argument types
   
#line 37 "rwgen2.pcc"
#line 40 "rwgen2.pcc"
{
   if (dest) {
      if (protocols) {
         L1:; 
         L2:; 
#line 39 "rwgen2.pcc"
        exp_ty = ret_ty = protocols->_1->ty; 
#line 39 "rwgen2.pcc"
      } else {
         L3:; 
#line 40 "rwgen2.pcc"
        error("%Lempty type list in rewrite (...) ..."); 
#line 40 "rwgen2.pcc"
      }
   } else {
      if (protocols) {
#line 38 "rwgen2.pcc"
        exp_ty = protocols->_1->ty; ret_ty = void_ty; 
#line 38 "rwgen2.pcc"
      } else { goto L3; }
   }
}
#line 41 "rwgen2.pcc"
#line 41 "rwgen2.pcc"


   // If it is destructive, use call by reference
   if (! (qual & QUALapplicative)) exp_ty = mkrefty(exp_ty);

   // Print the interface to the auxiliary function
   pr("%+%^extern %t %s_rewrite(%t);", ret_ty, "", rewriter_name, exp_ty, "");

   // Generate the rewriting call
   
#line 50 "rwgen2.pcc"
#line 52 "rwgen2.pcc"
{
   if (dest) {
#line 52 "rwgen2.pcc"
     pr("%^%e = %s_rewrite(%e);", dest, rewriter_name, exp); 
#line 52 "rwgen2.pcc"
   } else {
#line 51 "rwgen2.pcc"
     pr("%^%s_rewrite(%e);", rewriter_name, exp); 
#line 51 "rwgen2.pcc"
   }
}
#line 53 "rwgen2.pcc"
#line 53 "rwgen2.pcc"


   pr("%-");
   
   // Add to the list of outstanding rewriting classes
   Decl   body = OPAQUEdecl(
       
#line 59 "rwgen2.pcc"
#line 59 "rwgen2.pcc"
_r_w_g_e_n_2co_c_c_Q1
#line 59 "rwgen2.pcc"
#line 59 "rwgen2.pcc"
 + rewriter_name + 
#line 59 "rwgen2.pcc"
#line 59 "rwgen2.pcc"
_r_w_g_e_n_2co_c_c_Q2
#line 59 "rwgen2.pcc"
#line 59 "rwgen2.pcc"
);
   Decl new_def =
      CLASSDEFdecl(new RewriteClass(rewriter_name,protocols,
#line 61 "rwgen2.pcc"
#line 61 "rwgen2.pcc"
nil_1_
#line 61 "rwgen2.pcc"
#line 61 "rwgen2.pcc"
,qual,
#line 61 "rwgen2.pcc"
#line 61 "rwgen2.pcc"
list_1_(body)
#line 61 "rwgen2.pcc"
#line 61 "rwgen2.pcc"
));
   rewriters = 
#line 62 "rwgen2.pcc"
#line 62 "rwgen2.pcc"
list_1_(new_def,list_1_(REWRITEdecl(rewriter_name,Is,rules),rewriters))
#line 62 "rwgen2.pcc"
#line 62 "rwgen2.pcc"
;
   MEM::use_local_pools();
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method for compiling rewrite classes for the 'rewrite (...) { ... }'
//  construct.
//
///////////////////////////////////////////////////////////////////////////////
void RewritingCompiler::gen_rewriters()
{  
   debug_msg("[Generating the rewriters in this file]\n");
   for_each (Decl, d, rewriters)
   {  pr ("%D", d);
      
#line 77 "rwgen2.pcc"
#line 111 "rwgen2.pcc"
{
   if (d) {
      switch (d->tag__) {
         case a_Decl::tag_CLASSDEFdecl: {
            if (
#line 78 "rwgen2.pcc"
            ((((Decl_CLASSDEFdecl *)d)->CLASSDEFdecl->class_type == ClassDefinition::REWRITE_CLASS) && ((Decl_CLASSDEFdecl *)d)->CLASSDEFdecl->protocols)
#line 80 "rwgen2.pcc"
) {
               
#line 81 "rwgen2.pcc"
             Id id       = ((Decl_CLASSDEFdecl *)d)->CLASSDEFdecl->class_name;
               Ty ty       = ((Decl_CLASSDEFdecl *)d)->CLASSDEFdecl->protocols->_1->ty;
               TyQual qual = ((Decl_CLASSDEFdecl *)d)->CLASSDEFdecl->qualifiers; 
               // If it is destructive, use call by reference
               Bool is_applicative = qual & QUALapplicative;
               Bool do_traversal   = qual & QUALtreeparser;
               Ty exp_ty = is_applicative ? ty : mkrefty(ty);
               Ty ret_ty = is_applicative ? ty : void_ty;
               
               // protocol
               pr ("%^%t %s_rewrite(%t _x_) ", ret_ty, "", id, exp_ty, "");
               // declare the rewriter
               pr ("%^{  %s _r_;", id);
               // call the labeler
               if (do_traversal)
               {  if (is_applicative)
                  {  pr ("%^   return _r_.reduce(_r_(_x_));"); }
                  else
                  {  pr ("%^   _r_(_x_); %s_r_.reduce(_x_);",
                         ret_ty == void_ty ? "" : "return "); 
                  }
               } else
               {  if (is_applicative)
                  {  pr ("%^   return _r_(_x_);"); }
                  else 
                  {  pr ("%^   _r_(_x_);"); }
               }   
               pr ("%^}\n\n");
               
#line 109 "rwgen2.pcc"
            } else {
               
               L4:; }
            } break;
         default: { goto L4; } break;
      }
   } else { goto L4; }
}
#line 111 "rwgen2.pcc"
#line 111 "rwgen2.pcc"

   }    
   debug_msg("[Finished generating the rewriters in this file]\n");
}
#line 115 "rwgen2.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 287
Number of ifs generated      = 6
Number of switches generated = 1
Number of labels             = 4
Number of gotos              = 3
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
