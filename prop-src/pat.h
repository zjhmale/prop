///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.6),
//  last updated on Nov 2, 1999.
//  The original source file is "pat.ph".
///////////////////////////////////////////////////////////////////////////////

#line 1 "pat.ph"
///////////////////////////////////////////////////////////////////////////////
//
//  This file describes the analysis routines for patterns and match
//  decision trees.  These are used for mode analysis and determinism
//  analysis for logic clauses compilation.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef patterns_h
#define patterns_h

#include "ir.h"
#include "ast.h"
#include "matchcom.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Tests whether a pattern is subsumed by another.  Call the
//  error handler if false.
//
///////////////////////////////////////////////////////////////////////////////
extern Bool subsumes (Pat,     Pat,     Bool verbose);
extern Bool subsumes (Pats,    Pats,    Bool verbose);
extern Bool subsumes (LabPats, LabPats, Bool verbose);

///////////////////////////////////////////////////////////////////////////////
//
//  Convert a simple pattern into an unification pattern, i.e. one in
//  which pattern matching of the variable is explicitly modeled.
//
///////////////////////////////////////////////////////////////////////////////
extern Pat     unifier_of (Pat);
extern Pats    unifier_of (Pats);
extern LabPats unifier_of (LabPats);

///////////////////////////////////////////////////////////////////////////////
//
//  Thin a matching tree by discarding unreachable branches.
//
///////////////////////////////////////////////////////////////////////////////
extern Match   thin (Match,    Pat);
extern Match * thin (int, Match [], Pats);

///////////////////////////////////////////////////////////////////////////////
//
//  Routine to invert a pattern into a constructor expression.
//  If 'write mode' is on then convert pattern identifiers and wild cards
//  into logical variable constructors.
//
///////////////////////////////////////////////////////////////////////////////
extern Exp pat2exp         (Pat);
extern Exp pat2constructor (Pat);
extern Exp pat2unifier     (Pat);
extern Bool write_mode;    // write mode during unification

#endif
#line 56 "pat.ph"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 0
Number of ifs generated      = 0
Number of switches generated = 0
Number of labels             = 0
Number of gotos              = 0
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
