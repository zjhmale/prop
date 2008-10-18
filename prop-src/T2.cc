///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.3),
//  last updated on Mar 23, 1997.
//  The original source file is "T2.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_PRINTER_USED
#define PROP_GRAPHTYPE_USED
#include <propdefs.h>
#line 6 "T2.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Exp
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Exp_defined
#define datatype_Exp_defined
   class a_Exp;
   typedef a_Exp * Exp;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype Exp
//
///////////////////////////////////////////////////////////////////////////////
class a_Exp {
public:
   enum Tag_Exp {
      tag_INT = 0, tag_ADD = 1, tag_SUB = 2, 
      tag_MUL = 3, tag_DIV = 4
   };

public:
   const Tag_Exp tag__; // variant tag
protected:
   inline a_Exp(Tag_Exp t__) : tag__(t__) {}
public:
};
inline int boxed(const a_Exp *) { return 1; }
inline int untag(const a_Exp * x) { return x->tag__; }
///////////////////////////////////////////////////////////////////////////////
//
//  Pretty printing methods for Exp
//
///////////////////////////////////////////////////////////////////////////////
class PrettyOStream;
extern ostream& operator<<(ostream&, Exp);
extern PrettyOStream& operator<<(PrettyOStream&, Exp);
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Exp::INT
//
///////////////////////////////////////////////////////////////////////////////
class Exp_INT : public a_Exp {
public:
#line 1 "T2.pcc"
   int INT; 
   inline Exp_INT (int x_INT)
    : a_Exp(tag_INT), INT(x_INT)
   {
   }
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Exp::ADD
//
///////////////////////////////////////////////////////////////////////////////
class Exp_ADD : public a_Exp {
public:
#line 1 "T2.pcc"
   Exp _1; Exp _2; 
   inline Exp_ADD (Exp x_1, Exp x_2)
    : a_Exp(tag_ADD), _1(x_1), _2(x_2)
   {
   }
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Exp::SUB
//
///////////////////////////////////////////////////////////////////////////////
class Exp_SUB : public a_Exp {
public:
#line 2 "T2.pcc"
   Exp _1; Exp _2; 
   inline Exp_SUB (Exp x_1, Exp x_2)
    : a_Exp(tag_SUB), _1(x_1), _2(x_2)
   {
   }
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Exp::MUL
//
///////////////////////////////////////////////////////////////////////////////
class Exp_MUL : public a_Exp {
public:
#line 3 "T2.pcc"
   Exp _1; Exp _2; 
   inline Exp_MUL (Exp x_1, Exp x_2)
    : a_Exp(tag_MUL), _1(x_1), _2(x_2)
   {
   }
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Exp::DIV
//
///////////////////////////////////////////////////////////////////////////////
class Exp_DIV : public a_Exp {
public:
#line 4 "T2.pcc"
   Exp _1; Exp _2; 
   inline Exp_DIV (Exp x_1, Exp x_2)
    : a_Exp(tag_DIV), _1(x_1), _2(x_2)
   {
   }
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for Exp
//
///////////////////////////////////////////////////////////////////////////////
inline a_Exp * INT (int x_INT)
{
   return new Exp_INT (x_INT);
}
inline a_Exp * ADD (Exp x_1, Exp x_2)
{
   return new Exp_ADD (x_1, x_2);
}
inline a_Exp * SUB (Exp x_1, Exp x_2)
{
   return new Exp_SUB (x_1, x_2);
}
inline a_Exp * MUL (Exp x_1, Exp x_2)
{
   return new Exp_MUL (x_1, x_2);
}
inline a_Exp * DIV (Exp x_1, Exp x_2)
{
   return new Exp_DIV (x_1, x_2);
}
///////////////////////////////////////////////////////////////////////////////
//
// Downcasting functions for Exp
//
///////////////////////////////////////////////////////////////////////////////
inline Exp_INT * _INT(const a_Exp * _x_) { return (Exp_INT *)_x_; }
inline Exp_ADD * _ADD(const a_Exp * _x_) { return (Exp_ADD *)_x_; }
inline Exp_SUB * _SUB(const a_Exp * _x_) { return (Exp_SUB *)_x_; }
inline Exp_MUL * _MUL(const a_Exp * _x_) { return (Exp_MUL *)_x_; }
inline Exp_DIV * _DIV(const a_Exp * _x_) { return (Exp_DIV *)_x_; }

#line 6 "T2.pcc"
#line 6 "T2.pcc"


#line 8 "T2.pcc"
#line 13 "T2.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  Internal representation of nodes in graphtype Foo
//
///////////////////////////////////////////////////////////////////////////////
class Foo_Node_node;
///////////////////////////////////////////////////////////////////////////////
//
//  Representation of node Foo::Node(Exp)
//
///////////////////////////////////////////////////////////////////////////////
class Foo_Node_node {
   // no copy constructor or assignment
   Foo_Node_node(const Foo_Node_node&);
   void operator = (const Foo_Node_node&);
   Exp the_label;
public:
   Exp label() const { return the_label; }
   operator Exp () const { return the_label; }
   friend class Foo;
   struct {
      GraphType::Link dom_link;
      Foo_Node_node * image;
      GraphType::Link ran_link;
      int ran_count;
   } edge;
public:
   Foo_Node_node();
   ~Foo_Node_node();
};

///////////////////////////////////////////////////////////////////////////////
//
//  Definition of graphtype Foo
//
///////////////////////////////////////////////////////////////////////////////
class Foo : public GraphType {
public:
   typedef Foo_Node_node * Node;
   class Node_set {
   public:
      friend class Node_iterator;
      const GraphType::Link& link;
      long offset;
      Node_set(const GraphType::Link& l, long n = 0)
         : link(l), offset(n) {}
      Bool is_empty() const { return link.is_empty(); }
      operator Bool () const { return link.is_empty(); }
   };
   class Node_iterator {
      long offset;
      const GraphType::Link * cursor, * sentinel;
   public:
      Node_iterator(const Node_set& s) : 
         offset(s.offset), cursor(s.link.next),
             sentinel(&s.link) {}
      operator Bool () const { return cursor != sentinel; }
      Node operator * () const
          { return (Node)(((char *)cursor) - offset); }
      Node operator -> () const
          { return (Node)(((char *)cursor) - offset); }
      void operator ++ () { cursor = cursor->next; }
      void operator ++ (int) { cursor = cursor->next; }
   };
public:
   ////////////////////////////////////////////////////////////////////////////
   //
   // Interface to node Node(Exp)
   //
   ////////////////////////////////////////////////////////////////////////////
protected:
   // HashTable< Exp, Node, hash< Exp >, equal< Exp > > Node_table;
public:
   // Create a new node, or lookup an existing node.
   // The node is now attached to the graph.
   virtual Node create_Node(Exp);
   
   // Lookup a node by its label.
   // Returns nil if no such node exists.
   Node lookup_Node(Exp) const;
   
   // Does a node of a certain label exists?
   Bool has_Node(Exp l) const { return lookup_Node(l) != 0; }
   
   // Insert a new node into the graph by label.
   // A no-op if the graph with the label already exists
   Node insert_Node(Exp l) { return create_Node(l); }
   
   // Remove a node by label.
   // Returns true if the graph is changed.
   Bool remove_Node(Exp l) { return remove(lookup_Node(l)); }
   
   // Insert a node into the graph.
   // Returns true if the graph is changed.
   virtual Bool insert(Node);
   
   // Remove a node from the graph.
   // The node is destroyed.
   // Returns true if the graph is changed.
   virtual Bool remove(Node);
   class edge_record {
   protected:
      friend class Foo;
      int count;              // number of edges 
      GraphType::Link domset; // the domain
      int dom_count;          // size of domain
      GraphType::Link ranset; // the range
      int ran_count;          // size of range
   public:
      Node_set domain() const { return Node_set(domset); }
      Node_set range() const { return Node_set(ranset); }
      Bool domain_has (Node x) const
         { return x->edge.dom_link.non_nil(); }
      Bool has (Node x, Node y) const
         { return x->edge.image && x->edge.image == y; }
      int size () const { return count; }
      int domain_size () const { return dom_count; }
      int range_size () const { return ran_count; }
      Node operator () (Node x) const
         { return x->edge.image; }
      Bool update(Node x, Node y)
      {
         Node z = x->edge.image;
         if (z == y) return false;
         if (z)
         {
            if(--z->edge.ran_count == 0)
            {  z->edge.ran_link.unlink();
               --ran_count;
            }
         }
         else
         {
            ++count;
            ++dom_count;
            domset.link(x->edge.dom_link);
         }
         x->edge.image = y;
         if (++y->edge.ran_count == 1)
         {  ranset.link(y->edge.ran_link);
            ++ran_count;
         }
         return true;
      }
   } edge;
   
#line 12 "T2.pcc"
   
#line 13 "T2.pcc"
};
#line 13 "T2.pcc"
#line 13 "T2.pcc"


#line 15 "T2.pcc"
#line 15 "T2.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Exp
//
///////////////////////////////////////////////////////////////////////////////
#line 15 "T2.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Pretty printing methods for Exp
//
///////////////////////////////////////////////////////////////////////////////
ostream& operator << (ostream& strm__, Exp  obj__);
PrettyOStream& operator << (PrettyOStream& strm__, Exp  obj__);

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Exp
//
///////////////////////////////////////////////////////////////////////////////
#line 15 "T2.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Pretty printing methods for Exp
//
///////////////////////////////////////////////////////////////////////////////
ostream& operator << (ostream& strm__, Exp  obj__)
{  PrettyOStream S(strm__); S << obj__; return strm__; }

PrettyOStream& operator << (PrettyOStream& strm__, Exp  obj__)
{
   switch (untag(obj__))
   {
      case a_Exp::tag_INT: 
         strm__ << _INT(obj__)->INT; // int
         break;
      case a_Exp::tag_ADD: 
         strm__ << _ADD(obj__)->_1; // Exp
         strm__ << '+';
         strm__ << _ADD(obj__)->_2; // Exp
         break;
      case a_Exp::tag_SUB: 
         strm__ << _SUB(obj__)->_1; // Exp
         strm__ << '-';
         strm__ << _SUB(obj__)->_2; // Exp
         break;
      case a_Exp::tag_MUL: 
         strm__ << _MUL(obj__)->_1; // Exp
         strm__ << '*';
         strm__ << _MUL(obj__)->_2; // Exp
         break;
      case a_Exp::tag_DIV: 
         strm__ << _DIV(obj__)->_1; // Exp
         strm__ << '/';
         strm__ << _DIV(obj__)->_2; // Exp
         break;
   }
   return strm__;
}



#line 15 "T2.pcc"
#line 15 "T2.pcc"


#line 17 "T2.pcc"
#line 21 "T2.pcc"
