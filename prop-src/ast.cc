///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.6),
//  last updated on Nov 2, 1999.
//  The original source file is "ast.pcc".
///////////////////////////////////////////////////////////////////////////////

#line 1 "ast.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements some basic AST manipulation routines
//
///////////////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include "basics.h"
#include "ast.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Select the ith component from an expression list
//
///////////////////////////////////////////////////////////////////////////////
Exp component_exp(Exps exps, int n)
{  Exps es = exps;
   int  i  = n;
   
#line 18 "ast.pcc"
#line 20 "ast.pcc"
{
   for (;;) {
      if (es) {
         if (
#line 19 "ast.pcc"
         (i == 1)
#line 19 "ast.pcc"
) {
            
#line 19 "ast.pcc"
           return es->_1; 
#line 19 "ast.pcc"
         } else {
            
#line 20 "ast.pcc"
           es = es->_2; i--; 
#line 20 "ast.pcc"
         }
      } else { goto L1; }
   }
   L1:;
}
#line 21 "ast.pcc"
#line 21 "ast.pcc"

   error("%Lexpression %e does not have component %i\n",
	 TUPLEexp(exps), n);
   return NOexp;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Select the ith component from an expression list
//
///////////////////////////////////////////////////////////////////////////////
Exp component_exp(Exps exps, Id n)
{  return component_exp(exps,atol(n+1)); }

///////////////////////////////////////////////////////////////////////////////
//
//  Select the ith component from a labeled expression list
//
///////////////////////////////////////////////////////////////////////////////
Exp component_exp(LabExps labeled_exps, Id n)
{  LabExps les = labeled_exps;
   
#line 42 "ast.pcc"
#line 44 "ast.pcc"
{
   for (;;) {
      if (les) {
         if (
#line 43 "ast.pcc"
         (les->_1.label == n)
#line 43 "ast.pcc"
) {
            
#line 43 "ast.pcc"
           return les->_1.exp; 
#line 43 "ast.pcc"
         } else {
            
#line 44 "ast.pcc"
           les = les->_2; 
#line 44 "ast.pcc"
         }
      } else { goto L2; }
   }
   L2:;
}
#line 45 "ast.pcc"
#line 45 "ast.pcc"

   error("%Lexpression %e does not have component %s\n",
	 RECORDexp(labeled_exps), n);
   return NOexp;
}
#line 50 "ast.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 2
Number of ifs generated      = 4
Number of switches generated = 0
Number of labels             = 0
Number of gotos              = 0
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
