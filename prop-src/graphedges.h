///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.6),
//  last updated on Nov 2, 1999.
//  The original source file is "graphedges.ph".
///////////////////////////////////////////////////////////////////////////////

#line 1 "graphedges.ph"
///////////////////////////////////////////////////////////////////////////////
//
// This file implements different kind of graph edges
//
///////////////////////////////////////////////////////////////////////////////
#ifndef graph_edges_h
#define graph_edges_h

#include "graphtype.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Class to represent an single valued map 
//
///////////////////////////////////////////////////////////////////////////////
class MapEdge : public EdgeDef 
{  MapEdge(const MapEdge&);
   void operator = (const MapEdge&);
public:
   typedef EdgeDef Super;
   MapEdge(GraphTypeDef *, Id, NodeDef*, NodeDef*, GraphIndexing, LabTys = 
#line 21 "graphedges.ph"
#line 21 "graphedges.ph"
nil_1_
#line 21 "graphedges.ph"
#line 21 "graphedges.ph"
);

protected:
   virtual void generate_dom_rep(CodeGen&);
   virtual void generate_ran_rep(CodeGen&);
   virtual void generate_interf (CodeGen&);
   virtual void generate_impl   (CodeGen&);
   virtual void choose_representation ();
   virtual void print_report(CodeGen&);

   virtual void gen_in (CodeGen&);
   virtual void gen_image (CodeGen&);
   virtual void gen_update_image (CodeGen&);
   virtual void gen_in_dom(CodeGen&);
};

///////////////////////////////////////////////////////////////////////////////
//
//  Class to represent an multivalued map 
//
///////////////////////////////////////////////////////////////////////////////
class MultiMapEdge : public EdgeDef 
{  MultiMapEdge(const MultiMapEdge&);
   void operator = (const MultiMapEdge&);
public:
   typedef EdgeDef Super;
   MultiMapEdge
      (GraphTypeDef *, Id, NodeDef*, NodeDef*, GraphIndexing, LabTys = 
#line 48 "graphedges.ph"
#line 48 "graphedges.ph"
nil_1_
#line 48 "graphedges.ph"
#line 48 "graphedges.ph"
);

protected:
   virtual void generate_dom_rep(CodeGen&);
   virtual void generate_ran_rep(CodeGen&);
   virtual void generate_interf (CodeGen&);
   virtual void generate_impl   (CodeGen&);
   virtual void choose_representation ();
   virtual void print_report(CodeGen&);

   virtual void gen_in (CodeGen&);
   virtual void gen_image (CodeGen&);
   virtual void gen_update_image (CodeGen&);
   virtual void gen_in_dom(CodeGen&);
};

///////////////////////////////////////////////////////////////////////////////
//
//  Class to represent an bijection
//
///////////////////////////////////////////////////////////////////////////////
class BijectionEdge : public MapEdge 
{  BijectionEdge(const BijectionEdge&);
   void operator = (const BijectionEdge&);
public:
   typedef MapEdge Super;
   BijectionEdge
      (GraphTypeDef *, Id, NodeDef*, NodeDef*, GraphIndexing, LabTys = 
#line 75 "graphedges.ph"
#line 75 "graphedges.ph"
nil_1_
#line 75 "graphedges.ph"
#line 75 "graphedges.ph"
);

protected:
   virtual void generate_dom_rep(CodeGen&);
   virtual void generate_ran_rep(CodeGen&);
   virtual void generate_interf (CodeGen&);
   virtual void generate_impl   (CodeGen&);
   virtual void choose_representation ();
   virtual void print_report(CodeGen&);
};

///////////////////////////////////////////////////////////////////////////////
//
//  Class to represent an equivalence relation 
//
///////////////////////////////////////////////////////////////////////////////
class EquivRelationEdge : public MapEdge 
{  EquivRelationEdge(const EquivRelationEdge&);
   void operator = (const EquivRelationEdge&);
public:
   typedef MapEdge Super;
   EquivRelationEdge
      (GraphTypeDef *, Id, NodeDef*, NodeDef*, GraphIndexing, LabTys = 
#line 97 "graphedges.ph"
#line 97 "graphedges.ph"
nil_1_
#line 97 "graphedges.ph"
#line 97 "graphedges.ph"
);

protected:
   virtual void generate_dom_rep (CodeGen&);
   virtual void generate_ran_rep (CodeGen&);
   virtual void generate_interf  (CodeGen&);
   virtual void generate_impl    (CodeGen&);
   virtual void choose_representation ();
   virtual void print_report(CodeGen&);
};

#endif
#line 109 "graphedges.ph"
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
