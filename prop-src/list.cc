///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.6),
//  last updated on Nov 2, 1999.
//  The original source file is "list.pcc".
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
#pragma implementation "listimpl.h"
#endif
#define PROP_TUPLE2_USED
#include <propdefs.h>
#line 1 "list.pcc"

#include "basics.h"
#include "listimpl.h"
#include "ast.h"
#include "ir.h"
#include "parsegen.h"
//#include "logicgen.h"
//#include "constraint.h"

#define NO_TEMPLATE_KEYWORD
#ifndef NO_TEMPLATE_KEYWORD

template int length(
#line 16 "list.pcc"
a_List<Exp> *  
#line 16 "list.pcc"
);
template int length(a_List<Ty> *  
#line 17 "list.pcc"
);
template int length(a_List<Pat> *  
#line 18 "list.pcc"
);
template int length(a_List<Id> *  
#line 19 "list.pcc"
);
template int length(a_List<Inherit> *  
#line 20 "list.pcc"
);
template int length(a_List<ProductionSymbol> *  
#line 21 "list.pcc"
);
template int length(a_List<a_List<ProductionSymbol> * > *  
#line 22 "list.pcc"
);
template int length(a_List<LabPat> *  
#line 23 "list.pcc"
);
template int length(a_List<TermDef> *  
#line 24 "list.pcc"
);
template int length(a_List<DatatypeDef> *  
#line 25 "list.pcc"
);
template int length(a_List<MatchExp> *  
#line 26 "list.pcc"
);
template int length(a_List<InferenceRule> *  
#line 27 "list.pcc"
);
template int length(a_List<MatchRule> *  
#line 28 "list.pcc"
);

template a_List<Id> *  
#line 30 "list.pcc"
 append(a_List<Id> *  
#line 30 "list.pcc"
, a_List<Id> *  
#line 30 "list.pcc"
);
template a_List<Decl> *  
#line 31 "list.pcc"
 append(a_List<Decl> *  
#line 31 "list.pcc"
, a_List<Decl> *  
#line 31 "list.pcc"
);
template a_List<Inherit> *  
#line 32 "list.pcc"
 append(a_List<Inherit> *  
#line 32 "list.pcc"
, a_List<Inherit> *  
#line 32 "list.pcc"
);
template a_List<TermDef> *  
#line 33 "list.pcc"
 append(a_List<TermDef> *  
#line 33 "list.pcc"
, a_List<TermDef> *  
#line 33 "list.pcc"
);

template a_List<MatchRule> *  
#line 35 "list.pcc"
 rev (a_List<MatchRule> *  
#line 35 "list.pcc"
);
template a_List<Exp> *  
#line 36 "list.pcc"
 rev (a_List<Exp> *  
#line 36 "list.pcc"
);
template a_List<Tuple2<Id, Ty> > *  
#line 37 "list.pcc"
 rev (a_List<Tuple2<Id, Ty> > *  
#line 37 "list.pcc"
);
template a_List<Tuple2<Id, Pat> > *  
#line 38 "list.pcc"
 rev (a_List<Tuple2<Id, Pat> > *  
#line 38 "list.pcc"
);
//template List<.[Id, Pats, Determinism]> rev (List<.[Id, Pats, Determinism]>);
//template List<ConstraintRule> rev (List<ConstraintRule>);

#else

static void dummy()
{
length((a_List<Exp> *  
#line 46 "list.pcc"
)
#line 46 "list.pcc"
nil_1_
#line 46 "list.pcc"
#line 46 "list.pcc"
);
length((
#line 47 "list.pcc"
a_List<Ty> *  
#line 47 "list.pcc"
)
#line 47 "list.pcc"
nil_1_
#line 47 "list.pcc"
#line 47 "list.pcc"
);
length((
#line 48 "list.pcc"
a_List<Pat> *  
#line 48 "list.pcc"
)
#line 48 "list.pcc"
nil_1_
#line 48 "list.pcc"
#line 48 "list.pcc"
);
length((
#line 49 "list.pcc"
a_List<Id> *  
#line 49 "list.pcc"
)
#line 49 "list.pcc"
nil_1_
#line 49 "list.pcc"
#line 49 "list.pcc"
);
length((
#line 50 "list.pcc"
a_List<Inherit> *  
#line 50 "list.pcc"
)
#line 50 "list.pcc"
nil_1_
#line 50 "list.pcc"
#line 50 "list.pcc"
);
length((
#line 51 "list.pcc"
a_List<ProductionSymbol> *  
#line 51 "list.pcc"
)
#line 51 "list.pcc"
nil_1_
#line 51 "list.pcc"
#line 51 "list.pcc"
);
length((
#line 52 "list.pcc"
a_List<a_List<ProductionSymbol> * > *  
#line 52 "list.pcc"
)
#line 52 "list.pcc"
nil_1_
#line 52 "list.pcc"
#line 52 "list.pcc"
);
length((
#line 53 "list.pcc"
a_List<LabPat> *  
#line 53 "list.pcc"
)
#line 53 "list.pcc"
nil_1_
#line 53 "list.pcc"
#line 53 "list.pcc"
);
length((
#line 54 "list.pcc"
a_List<TermDef> *  
#line 54 "list.pcc"
)
#line 54 "list.pcc"
nil_1_
#line 54 "list.pcc"
#line 54 "list.pcc"
);
length((
#line 55 "list.pcc"
a_List<DatatypeDef> *  
#line 55 "list.pcc"
)
#line 55 "list.pcc"
nil_1_
#line 55 "list.pcc"
#line 55 "list.pcc"
);
length((
#line 56 "list.pcc"
a_List<MatchExp> *  
#line 56 "list.pcc"
)
#line 56 "list.pcc"
nil_1_
#line 56 "list.pcc"
#line 56 "list.pcc"
);
length((
#line 57 "list.pcc"
a_List<InferenceRule> *  
#line 57 "list.pcc"
)
#line 57 "list.pcc"
nil_1_
#line 57 "list.pcc"
#line 57 "list.pcc"
);
length((
#line 58 "list.pcc"
a_List<MatchRule> *  
#line 58 "list.pcc"
)
#line 58 "list.pcc"
nil_1_
#line 58 "list.pcc"
#line 58 "list.pcc"
);

append((
#line 60 "list.pcc"
a_List<Id> *  
#line 60 "list.pcc"
)
#line 60 "list.pcc"
nil_1_
#line 60 "list.pcc"
#line 60 "list.pcc"
,      (
#line 60 "list.pcc"
a_List<Id> *  
#line 60 "list.pcc"
)
#line 60 "list.pcc"
nil_1_
#line 60 "list.pcc"
#line 60 "list.pcc"
);
append((
#line 61 "list.pcc"
a_List<Decl> *  
#line 61 "list.pcc"
)
#line 61 "list.pcc"
nil_1_
#line 61 "list.pcc"
#line 61 "list.pcc"
,    (
#line 61 "list.pcc"
a_List<Decl> *  
#line 61 "list.pcc"
)
#line 61 "list.pcc"
nil_1_
#line 61 "list.pcc"
#line 61 "list.pcc"
);
append((
#line 62 "list.pcc"
a_List<Inherit> *  
#line 62 "list.pcc"
)
#line 62 "list.pcc"
nil_1_
#line 62 "list.pcc"
#line 62 "list.pcc"
, (
#line 62 "list.pcc"
a_List<Inherit> *  
#line 62 "list.pcc"
)
#line 62 "list.pcc"
nil_1_
#line 62 "list.pcc"
#line 62 "list.pcc"
);
append((
#line 63 "list.pcc"
a_List<TermDef> *  
#line 63 "list.pcc"
)
#line 63 "list.pcc"
nil_1_
#line 63 "list.pcc"
#line 63 "list.pcc"
, (
#line 63 "list.pcc"
a_List<TermDef> *  
#line 63 "list.pcc"
)
#line 63 "list.pcc"
nil_1_
#line 63 "list.pcc"
#line 63 "list.pcc"
);

rev ((
#line 65 "list.pcc"
a_List<MatchRule> *  
#line 65 "list.pcc"
)
#line 65 "list.pcc"
nil_1_
#line 65 "list.pcc"
#line 65 "list.pcc"
);
rev ((
#line 66 "list.pcc"
a_List<Exp> *  
#line 66 "list.pcc"
)
#line 66 "list.pcc"
nil_1_
#line 66 "list.pcc"
#line 66 "list.pcc"
);
rev ((
#line 67 "list.pcc"
a_List<ProductionSymbol> *  
#line 67 "list.pcc"
)
#line 67 "list.pcc"
nil_1_
#line 67 "list.pcc"
#line 67 "list.pcc"
);
rev ((
#line 68 "list.pcc"
a_List<Tuple2<Id, Ty> > *  
#line 68 "list.pcc"
)
#line 68 "list.pcc"
nil_1_
#line 68 "list.pcc"
#line 68 "list.pcc"
);
rev ((
#line 69 "list.pcc"
a_List<Tuple2<Id, Pat> > *  
#line 69 "list.pcc"
)
#line 69 "list.pcc"
nil_1_
#line 69 "list.pcc"
#line 69 "list.pcc"
);
//rev ((List<ConstraintRule>)#[]);
//rev ((List<.[Id, Pats, Determinism]>)#[]);
}
#endif
#line 74 "list.pcc"
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
