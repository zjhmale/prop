///////////////////////////////////////////////////////////////////////////////
//
//  This file contains the abstract syntax tree definitions for the
//  SETL-like extension language of Prop. 
//
///////////////////////////////////////////////////////////////////////////////
#ifndef setl_extension_abstract_syntax_tree_h
#define setl_extension_abstract_syntax_tree_h

#include "basics.ph"
#include "ir.ph"

///////////////////////////////////////////////////////////////////////////////
//
//  Forward AST declarations.
//
///////////////////////////////////////////////////////////////////////////////
datatype Exp    // expressions
     and Decl   // prop declarations
     and Time   // time complexity
     and Space  // space complexity
;

///////////////////////////////////////////////////////////////////////////////
//
//  AST for definitions, signatures, statements and bindings
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Type 'Def' represents definitions. 
//
///////////////////////////////////////////////////////////////////////////////
datatype Def : public Loc =
       NOdef
    |  VARdef       { id       : Id,         // variable name
                      ty       : Ty,         // type of variable
                      init_exp : Exp = NOexp // initial value
                    }
    |  FUNCTIONdef  { id         : Id,       // name of function
                      args       : LabTys,   // arguments
                      return_ty  : Ty,       // return type
                      local_defs : Defs,     // local defintions
                      body       : Stmts     // body of function
                    }
    |  MODULEdef    { id         : Id,       // name of module
                      args       : LabSigs,  // arguments
                      sig        : Sig,      // signature constraint
                      body       : Defs      // body of module
                    }
    |  SIGNATUREdef { id         : Id,       // name of signature
                      args       : LabSigs,  // arguments 
                      sig        : Sig       // body of signature
                    }
    |  TYPEdef      (Decl)                   // datatype/type definition
    |  LAMBDAdef    (LabTys, Defs)           // module abstraction

///////////////////////////////////////////////////////////////////////////////
//
//  Type 'Sig' represents signatures. 
//
///////////////////////////////////////////////////////////////////////////////
and Sig : public Loc =
       NOsig                        // no signature
    |  IDsig  (Id)                  // signature name
    |  DOTsig (Sig, Id)             // signature selection
    |  APPsig (Sig, Sigs)           // signature application
    |  DEFsig (Defs)                // definitions
    |  LAMBDAsig (LabSigs, Sig)     // signature abstraction

///////////////////////////////////////////////////////////////////////////////
//
//  Type 'Stmt' represents statements. 
//
///////////////////////////////////////////////////////////////////////////////
and Stmt : public Loc =
       NOstmt                                  // empty statement
    |  ASSIGNstmt      (Exp, Exp)              // assignment
    |  BLOCKstmt       (Defs, Stmts)           // statement block
    |  WHILEstmt       (Exp, Stmt)             // while loop
    |  IFstmt          (Exp, Stmt, Stmt)       // if/then/else
    |  MATCHstmt       (Decl)                  // match statement
    |  REWRITEstmt     (Decl)                  // rewriting statement
    |  REPLACEMENTstmt (Decl)                  // replacement statement
    |  FORALLstmt      (Generators, Stmt)      // iteration
    |  RETURNstmt      (Exp)                   // return statement

///////////////////////////////////////////////////////////////////////////////
//
//  Miscellaneous type abbreviations
//
///////////////////////////////////////////////////////////////////////////////
where type LabSig     = { id : Id, sig : Sig } // labeled signature
       and LabSigs    = List<LabSig>           // labeled signature list
       and Defs       = List<Def>              // list of definitions
       and Sigs       = List<Sig>              // list of signatures
       and Stmts      = List<Stmt>             // list of statements
       and Generators = List<Generator>        // list of generators
;

///////////////////////////////////////////////////////////////////////////////
//
//  Pretty printing routines for definitions, statements and generators
//
///////////////////////////////////////////////////////////////////////////////
extern ostream& operator << (ostream&, Def);
extern ostream& operator << (ostream&, Defs);
extern ostream& operator << (ostream&, Sig);
extern ostream& operator << (ostream&, Sigs);
extern ostream& operator << (ostream&, Stmt);
extern ostream& operator << (ostream&, Stmts);
extern ostream& operator << (ostream&, LabSig);
extern ostream& operator << (ostream&, LabSigs);
extern ostream& operator << (ostream&, Generator);
extern ostream& operator << (ostream&, Generators);

#endif
