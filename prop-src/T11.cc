///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.4),
//  last updated on Apr 3, 1997.
//  The original source file is "T11.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_REWRITING_USED
#define PROP_GARBAGE_COLLECTION_USED
#define PROP_QUARK_USED
#include <propdefs.h>
#line 7 "T11.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Wff
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Wff_defined
#define datatype_Wff_defined
   class a_Wff;
   typedef a_Wff * Wff;
#endif

#  define T (Wff)0
#  define F (Wff)1

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype Wff
//
///////////////////////////////////////////////////////////////////////////////
class a_Wff : public GCObject {
public:
   enum Tag_Wff {
      tag_VAR = 0, tag_NOT = 1, tag_AND = 2, 
      tag_OR = 3
   };

public:
   const Tag_Wff tag__; // variant tag
protected:
   inline a_Wff(Tag_Wff t__) : tag__(t__) {
#line 9 "T11.pcc"
  cerr << "this"; 
#line 9 "T11.pcc"
}
public:
   inline virtual ~a_Wff()
   {
      
#line 14 "T11.pcc"
     cerr << "~wff"; 
#line 14 "T11.pcc"
   }
   ////////////////////////////////////////////////////////////////////////////
   //
   // Method for garbage collection tracing
   //
   ////////////////////////////////////////////////////////////////////////////
protected:
   virtual void trace(GC *);
public:
};
inline int boxed(const a_Wff * x) { return (unsigned long)x >= 2; }
inline int untag(const a_Wff * x) { return boxed(x) ? x->tag__ + 2 : (int)x; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Wff::VAR
//
///////////////////////////////////////////////////////////////////////////////
class Wff_VAR : public a_Wff {
public:
#line 3 "T11.pcc"
   Quark VAR; 
   inline Wff_VAR (Quark x_VAR)
    : a_Wff(tag_VAR), VAR(x_VAR)
   {
      
#line 10 "T11.pcc"
     cerr << "var"; 
#line 10 "T11.pcc"
   }
   inline ~Wff_VAR()
   {
      
#line 15 "T11.pcc"
     cerr << "~var"; 
#line 15 "T11.pcc"
   }
   ////////////////////////////////////////////////////////////////////////////
   //
   // Method for garbage collection tracing
   //
   ////////////////////////////////////////////////////////////////////////////
protected:
   virtual void trace(GC *);
public:
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Wff::NOT
//
///////////////////////////////////////////////////////////////////////////////
class Wff_NOT : public a_Wff {
public:
#line 4 "T11.pcc"
   Wff NOT; 
   inline Wff_NOT (Wff x_NOT)
    : a_Wff(tag_NOT), NOT(x_NOT)
   {
      
#line 11 "T11.pcc"
     cerr << "not"; 
#line 11 "T11.pcc"
   }
   inline ~Wff_NOT()
   {
      
#line 16 "T11.pcc"
     cerr << "~not"; 
#line 16 "T11.pcc"
   }
   ////////////////////////////////////////////////////////////////////////////
   //
   // Method for garbage collection tracing
   //
   ////////////////////////////////////////////////////////////////////////////
protected:
   virtual void trace(GC *);
public:
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Wff::AND
//
///////////////////////////////////////////////////////////////////////////////
class Wff_AND : public a_Wff {
public:
#line 5 "T11.pcc"
   Wff _1; Wff _2; 
   inline Wff_AND (Wff x_1, Wff x_2)
    : a_Wff(tag_AND), _1(x_1), _2(x_2)
   {
      
#line 12 "T11.pcc"
     cerr << "and"; 
#line 12 "T11.pcc"
   }
   inline ~Wff_AND()
   {
      
#line 17 "T11.pcc"
     cerr << "~and"; 
#line 17 "T11.pcc"
   }
   ////////////////////////////////////////////////////////////////////////////
   //
   // Method for garbage collection tracing
   //
   ////////////////////////////////////////////////////////////////////////////
protected:
   virtual void trace(GC *);
public:
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Wff::OR
//
///////////////////////////////////////////////////////////////////////////////
class Wff_OR : public a_Wff {
public:
#line 6 "T11.pcc"
   Wff _1; Wff _2; 
   inline Wff_OR (Wff x_1, Wff x_2)
    : a_Wff(tag_OR), _1(x_1), _2(x_2)
   {
      
#line 13 "T11.pcc"
     cerr << "or"; 
#line 13 "T11.pcc"
   }
   inline ~Wff_OR()
   {
      
#line 18 "T11.pcc"
     cerr << "~or"; 
#line 18 "T11.pcc"
   }
   ////////////////////////////////////////////////////////////////////////////
   //
   // Method for garbage collection tracing
   //
   ////////////////////////////////////////////////////////////////////////////
protected:
   virtual void trace(GC *);
public:
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for Wff
//
///////////////////////////////////////////////////////////////////////////////
inline a_Wff * VAR (Quark x_VAR)
{
   return new Wff_VAR (x_VAR);
}
inline a_Wff * NOT (Wff x_NOT)
{
   return new Wff_NOT (x_NOT);
}
inline a_Wff * AND (Wff x_1, Wff x_2)
{
   return new Wff_AND (x_1, x_2);
}
inline a_Wff * OR (Wff x_1, Wff x_2)
{
   return new Wff_OR (x_1, x_2);
}
///////////////////////////////////////////////////////////////////////////////
//
// Downcasting functions for Wff
//
///////////////////////////////////////////////////////////////////////////////
inline Wff_VAR * _VAR(const a_Wff * _x_) { return (Wff_VAR *)_x_; }
inline Wff_NOT * _NOT(const a_Wff * _x_) { return (Wff_NOT *)_x_; }
inline Wff_AND * _AND(const a_Wff * _x_) { return (Wff_AND *)_x_; }
inline Wff_OR * _OR(const a_Wff * _x_) { return (Wff_OR *)_x_; }

#line 7 "T11.pcc"
#line 7 "T11.pcc"


#line 9 "T11.pcc"
#line 18 "T11.pcc"


#line 21 "T11.pcc"
#line 21 "T11.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Wff
//
///////////////////////////////////////////////////////////////////////////////
#line 21 "T11.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype Wff
//
///////////////////////////////////////////////////////////////////////////////
#line 21 "T11.pcc"
void a_Wff::trace(GC * gc__)
{
}

void Wff_VAR::trace(GC * gc__)
{
   // call to method a_Wff::trace() has been optimized out
   // omitted Quark
}

void Wff_NOT::trace(GC * gc__)
{
   // call to method a_Wff::trace() has been optimized out
   this->NOT = (Wff )gc__->trace(this->NOT); // Wff
}

void Wff_AND::trace(GC * gc__)
{
   // call to method a_Wff::trace() has been optimized out
   this->_1 = (Wff )gc__->trace(this->_1); // Wff
   this->_2 = (Wff )gc__->trace(this->_2); // Wff
}

void Wff_OR::trace(GC * gc__)
{
   // call to method a_Wff::trace() has been optimized out
   this->_1 = (Wff )gc__->trace(this->_1); // Wff
   this->_2 = (Wff )gc__->trace(this->_2); // Wff
}



#line 21 "T11.pcc"
#line 21 "T11.pcc"


Wff dnf (Wff wff)
{
   
#line 25 "T11.pcc"
#line 44 "T11.pcc"
   extern void  _T_1_1co_X1_rewrite(Wff & );
   _T_1_1co_X1_rewrite(wff);
#line 44 "T11.pcc"
#line 44 "T11.pcc"

   return wff;
}
#line 47 "T11.pcc"
class _T_1_1co_X1 : public BURS {
private:
   _T_1_1co_X1(const _T_1_1co_X1&);               // no copy constructor
   void operator = (const _T_1_1co_X1&); // no assignment
public:
   struct _T_1_1co_X1_StateRec * stack__, * stack_top__;
public:
   void labeler(const char *, int&, int);
   void labeler(Quark, int&, int);
          void  labeler(Wff & redex, int&, int);
   inline virtual void  operator () (Wff & redex) { int s; labeler(redex,s,0); }
private: 
   public:
      inline _T_1_1co_X1() {}
};
void  _T_1_1co_X1_rewrite(Wff &  _x_) 
{  _T_1_1co_X1 _r_;
   _r_(_x_);
}

///////////////////////////////////////////////////////////////////////////////
//
// This macro can be redefined by the user for debugging
//
///////////////////////////////////////////////////////////////////////////////
#ifndef DEBUG__T_1_1co_X1
#define DEBUG__T_1_1co_X1(repl,redex,file,line,rule) repl
#else
static const char * _T_1_1co_X1_file_name = "T11.pcc";
#endif

static const TreeTables::ShortState _T_1_1co_X1_theta_3[5] = {
   3, 6, 13, 24, 28
};


static const TreeTables::ShortState _T_1_1co_X1_theta_4[5][4] = {
   { 4, 7, 14, 29 },
   { 9, 8, 16, 33 },
   { 17, 18, 15, 32 },
   { 25, 27, 26, 31 },
   { 34, 36, 35, 30 }
};


static const TreeTables::ShortState _T_1_1co_X1_theta_5[4][3] = {
   { 5, 10, 19 },
   { 12, 11, 21 },
   { 22, 23, 20 },
   { 37, 39, 38 }
};


static const TreeTables::ShortState _T_1_1co_X1_mu_3_0[40] = {
   0, 1, 2, 3, 0, 4, 3, 0, 0, 0, 4, 4, 4, 3, 0, 0, 
   0, 0, 0, 4, 4, 4, 4, 4, 3, 0, 0, 0, 3, 0, 0, 0, 
   0, 0, 0, 0, 0, 4, 4, 4
};


static const TreeTables::ShortState _T_1_1co_X1_mu_4_0[40] = {
   0, 1, 2, 0, 3, 4, 0, 3, 3, 3, 4, 4, 4, 0, 3, 3, 
   3, 3, 3, 4, 4, 4, 4, 4, 0, 3, 3, 3, 0, 3, 3, 3, 
   3, 3, 3, 3, 3, 4, 4, 4
};


static const TreeTables::ShortState _T_1_1co_X1_mu_4_1[40] = {
   0, 1, 2, 0, 0, 3, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 
   0, 0, 0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 3, 3, 3
};


static const TreeTables::ShortState _T_1_1co_X1_mu_5_0[40] = {
   0, 1, 2, 0, 0, 3, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 
   0, 0, 0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 3, 3, 3
};


static const TreeTables::ShortState _T_1_1co_X1_mu_5_1[40] = {
   0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0
};


inline void  _T_1_1co_X1::labeler(char const * redex,int& s__,int)
{
   {
s__ = 0;
   }
}

inline void  _T_1_1co_X1::labeler(Quark redex,int& s__,int)
{
   {
s__ = 0;
   }
}

void  _T_1_1co_X1::labeler (Wff & redex, int& s__, int r__)
{
replacement__:
   if (boxed(redex)) {
      switch(redex->tag__) {
         case a_Wff::tag_VAR: { 
            int s0__;
            labeler(_VAR(redex)->VAR, s0__, r__);
            s__ = 0;} break;
         case a_Wff::tag_NOT: { 
            int s0__;
            labeler(_NOT(redex)->NOT, s0__, r__);
            s__ = _T_1_1co_X1_theta_3[_T_1_1co_X1_mu_3_0[s0__]]; } break;
         case a_Wff::tag_AND: { 
            int s0__;
            int s1__;
            labeler(_AND(redex)->_1, s0__, r__);
            labeler(_AND(redex)->_2, s1__, r__);
            s__ = _T_1_1co_X1_theta_4[_T_1_1co_X1_mu_4_0[s0__]][_T_1_1co_X1_mu_4_1[s1__]]; } break;
         default: { 
            int s0__;
            int s1__;
            labeler(_OR(redex)->_1, s0__, r__);
            labeler(_OR(redex)->_2, s1__, r__);
            s__ = _T_1_1co_X1_theta_5[_T_1_1co_X1_mu_5_0[s0__]][_T_1_1co_X1_mu_5_1[s1__]]; } break;
      }
   } else {
      if (((int)redex)) {s__ = 2;
      } else {s__ = 1;
      }
   }
   switch (s__) {
      case 25: {
#line 43 "T11.pcc"
         { redex = DEBUG__T_1_1co_X1(AND(_AND(_AND(redex)->_1)->_1,AND(_AND(_AND(redex)->_1)->_2,_AND(redex)->_2)),redex,_T_1_1co_X1_file_name,43,"AND (AND (X, Y), Z): ...");
           r__ = 1; goto replacement__; }
#line 44 "T11.pcc"
} break;
      case 37: {
#line 42 "T11.pcc"
         { redex = DEBUG__T_1_1co_X1(OR(_OR(_OR(redex)->_1)->_1,OR(_OR(_OR(redex)->_1)->_2,_OR(redex)->_2)),redex,_T_1_1co_X1_file_name,42,"OR (OR (X, Y), Z): ...");
           r__ = 1; goto replacement__; }
#line 43 "T11.pcc"
} break;
      case 31: 
      case 29: {
#line 41 "T11.pcc"
         { redex = DEBUG__T_1_1co_X1(OR(AND(_AND(redex)->_1,_OR(_AND(redex)->_2)->_1),AND(_AND(redex)->_1,_OR(_AND(redex)->_2)->_2)),redex,_T_1_1co_X1_file_name,41,"AND (X, OR (Y, Z)): ...");
           r__ = 1; goto replacement__; }
#line 42 "T11.pcc"
} break;
      case 34: 
      case 30: {
#line 40 "T11.pcc"
         { redex = DEBUG__T_1_1co_X1(OR(AND(_OR(_AND(redex)->_1)->_1,_AND(redex)->_2),AND(_OR(_AND(redex)->_1)->_2,_AND(redex)->_2)),redex,_T_1_1co_X1_file_name,40,"AND (OR (X, Y), Z): ...");
           r__ = 1; goto replacement__; }
#line 41 "T11.pcc"
} break;
      case 28: {
#line 38 "T11.pcc"
         { redex = DEBUG__T_1_1co_X1(AND(NOT(_OR(_NOT(redex)->NOT)->_1),NOT(_OR(_NOT(redex)->NOT)->_2)),redex,_T_1_1co_X1_file_name,38,"NOT OR (X, Y): ...");
           r__ = 1; goto replacement__; }
#line 40 "T11.pcc"
} break;
      case 35: 
      case 26: 
      case 14: {
#line 36 "T11.pcc"
         { redex = DEBUG__T_1_1co_X1(F,redex,_T_1_1co_X1_file_name,36,"AND (_, F): ...");
           r__ = 1; goto replacement__; }
#line 38 "T11.pcc"
} break;
      case 32: 
      case 17: 
      case 15: {
#line 35 "T11.pcc"
         { redex = DEBUG__T_1_1co_X1(F,redex,_T_1_1co_X1_file_name,35,"AND (F, _): ...");
           r__ = 1; goto replacement__; }
#line 36 "T11.pcc"
} break;
      case 36: 
      case 27: 
      case 18: 
      case 7: {
#line 34 "T11.pcc"
         { redex = DEBUG__T_1_1co_X1(_AND(redex)->_1,redex,_T_1_1co_X1_file_name,34,"AND (X, T): ...");
           r__ = 1; goto replacement__; }
#line 35 "T11.pcc"
} break;
      case 33: 
      case 16: 
      case 9: 
      case 8: {
#line 33 "T11.pcc"
         { redex = DEBUG__T_1_1co_X1(_AND(redex)->_2,redex,_T_1_1co_X1_file_name,33,"AND (T, X): ...");
           r__ = 1; goto replacement__; }
#line 34 "T11.pcc"
} break;
      case 38: 
      case 19: {
#line 32 "T11.pcc"
         { redex = DEBUG__T_1_1co_X1(_OR(redex)->_1,redex,_T_1_1co_X1_file_name,32,"OR (X, F): ...");
           r__ = 1; goto replacement__; }
#line 33 "T11.pcc"
} break;
      case 22: 
      case 20: {
#line 31 "T11.pcc"
         { redex = DEBUG__T_1_1co_X1(_OR(redex)->_2,redex,_T_1_1co_X1_file_name,31,"OR (F, X): ...");
           r__ = 1; goto replacement__; }
#line 32 "T11.pcc"
} break;
      case 39: 
      case 23: 
      case 10: {
#line 30 "T11.pcc"
         { redex = DEBUG__T_1_1co_X1(T,redex,_T_1_1co_X1_file_name,30,"OR (_, T): ...");
           r__ = 1; goto replacement__; }
#line 31 "T11.pcc"
} break;
      case 21: 
      case 12: 
      case 11: {
#line 29 "T11.pcc"
         { redex = DEBUG__T_1_1co_X1(T,redex,_T_1_1co_X1_file_name,29,"OR (T, _): ...");
           r__ = 1; goto replacement__; }
#line 30 "T11.pcc"
} break;
      case 24: {
#line 28 "T11.pcc"
         { redex = DEBUG__T_1_1co_X1(_NOT(_NOT(redex)->NOT)->NOT,redex,_T_1_1co_X1_file_name,28,"NOT NOT X: ...");
           r__ = 1; goto replacement__; }
#line 29 "T11.pcc"
} break;
      case 13: {
#line 27 "T11.pcc"
         { redex = DEBUG__T_1_1co_X1(T,redex,_T_1_1co_X1_file_name,27,"NOT F: ...");
           r__ = 1; goto replacement__; }
#line 28 "T11.pcc"
} break;
      case 6: {
#line 26 "T11.pcc"
         { redex = DEBUG__T_1_1co_X1(F,redex,_T_1_1co_X1_file_name,26,"NOT T: ...");
           r__ = 1; goto replacement__; }
#line 27 "T11.pcc"
} break;
   }
   
}

/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 0
Number of ifs generated      = 0
Number of switches generated = 0
Number of labels             = 0
Number of gotos              = 0
Adaptive matching            = disabled
Fast string matching         = disabled
Inline downcasts             = disabled
--------------------------------------------------------------------------
*/
