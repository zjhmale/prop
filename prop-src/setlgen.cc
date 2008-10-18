///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.6),
//  last updated on Nov 2, 1999.
//  The original source file is "setlgen.pcc".
///////////////////////////////////////////////////////////////////////////////

#line 1 "setlgen.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements the data structure mapping component of the
//  SETL sublanguage.
//
///////////////////////////////////////////////////////////////////////////////
#include "ir.h"
#include "ast.h"
#include "setl-ast.h"
#include "setlgen.h"
#include "type.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Constructor and destructor
//
///////////////////////////////////////////////////////////////////////////////
SETLCompiler:: SETLCompiler() {}
SETLCompiler::~SETLCompiler() {}

///////////////////////////////////////////////////////////////////////////////
//
//  Entry points of the SETL data structure mapping compiler
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Generate a SETL statement
//
///////////////////////////////////////////////////////////////////////////////
void SETLCompiler::gen_setl (Stmt stmt)
{  
   bug("SETL sublanguage is not implemented");
   gen_stmt(stmt);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Generate a SETL definition
//
///////////////////////////////////////////////////////////////////////////////
void SETLCompiler::gen_setl (Def def)
{  pr ("%^/*\n");
   gen_def(def);
   pr ("%^*/\n");
}

///////////////////////////////////////////////////////////////////////////////
//
//  Code generation method for definitions
//
///////////////////////////////////////////////////////////////////////////////
void SETLCompiler::gen_def (Def def)
{
}

///////////////////////////////////////////////////////////////////////////////
//
//  Code generation method for a list of definitions
//
///////////////////////////////////////////////////////////////////////////////
void SETLCompiler::gen_defs (Defs defs)
{  
#line 64 "setlgen.pcc"
#line 65 "setlgen.pcc"
{
   for (;;) {
      if (defs) {
#line 65 "setlgen.pcc"
        gen_def(defs->_1); defs = defs->_2; 
#line 65 "setlgen.pcc"
      } else { goto L1; }
   }
   L1:;
}
#line 66 "setlgen.pcc"
#line 66 "setlgen.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Code generation method for statements
//
///////////////////////////////////////////////////////////////////////////////
void SETLCompiler::gen_stmt (Stmt stmt)
{   
#line 75 "setlgen.pcc"
#line 85 "setlgen.pcc"
{
   if (stmt) {
      switch (stmt->tag__) {
         case a_Stmt::tag_ASSIGNstmt: {} break;
         case a_Stmt::tag_BLOCKstmt: {} break;
         case a_Stmt::tag_WHILEstmt: {} break;
         case a_Stmt::tag_IFstmt: {} break;
         case a_Stmt::tag_MATCHstmt: {
#line 81 "setlgen.pcc"
            pr("%D",((Stmt_MATCHstmt *)stmt)->MATCHstmt);
#line 81 "setlgen.pcc"
            } break;
         case a_Stmt::tag_REWRITEstmt: {
#line 82 "setlgen.pcc"
            pr("%D",((Stmt_REWRITEstmt *)stmt)->REWRITEstmt);
#line 82 "setlgen.pcc"
            } break;
         case a_Stmt::tag_REPLACEMENTstmt: {
#line 83 "setlgen.pcc"
            pr("%D",((Stmt_REPLACEMENTstmt *)stmt)->REPLACEMENTstmt);
#line 83 "setlgen.pcc"
            } break;
         case a_Stmt::tag_FORALLstmt: {} break;
         default: {
#line 85 "setlgen.pcc"
            pr("return %e;",((Stmt_RETURNstmt *)stmt)->RETURNstmt);
#line 85 "setlgen.pcc"
            } break;
      }
   } else {}
}
#line 86 "setlgen.pcc"
#line 86 "setlgen.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Code generation method for a list of statements
//
///////////////////////////////////////////////////////////////////////////////
void SETLCompiler::gen_stmts (Stmts stmts)
{  
#line 95 "setlgen.pcc"
#line 96 "setlgen.pcc"
{
   for (;;) {
      if (stmts) {
#line 96 "setlgen.pcc"
        gen_stmt(stmts->_1); stmts = stmts->_2; 
#line 96 "setlgen.pcc"
      } else { goto L2; }
   }
   L2:;
}
#line 97 "setlgen.pcc"
#line 97 "setlgen.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Code generation method for expressions
//
///////////////////////////////////////////////////////////////////////////////
void SETLCompiler::gen_exp (Exp exp)
{
}

///////////////////////////////////////////////////////////////////////////////
//
//  Code generation method for an expression list
//
///////////////////////////////////////////////////////////////////////////////
void SETLCompiler::gen_exps (Exps exps)
{  
#line 115 "setlgen.pcc"
#line 117 "setlgen.pcc"
{
   for (;;) {
      if (exps) {
         if (exps->_2) {
#line 117 "setlgen.pcc"
           gen_exp(exps->_1); exps = exps->_2; 
#line 117 "setlgen.pcc"
         } else {
#line 116 "setlgen.pcc"
           gen_exp(exps->_1); exps = 
#line 116 "setlgen.pcc"
#line 116 "setlgen.pcc"
            nil_1_
#line 116 "setlgen.pcc"
#line 116 "setlgen.pcc"
            ; 
#line 116 "setlgen.pcc"
         }
      } else { goto L3; }
   }
   L3:;
}
#line 118 "setlgen.pcc"
#line 118 "setlgen.pcc"

}
#line 120 "setlgen.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 4
Number of ifs generated      = 5
Number of switches generated = 1
Number of labels             = 0
Number of gotos              = 0
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
