///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.4),
//  last updated on Apr 3, 1997.
//  The original source file is "T6.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_REWRITING_USED
#define PROP_QUARK_USED
#include <propdefs.h>
#line 1 "T6.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for T
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_T_defined
#define datatype_T_defined
   class a_T;
   typedef a_T * T;
#endif

#  define a (T)0
#  define b (T)1
#  define c (T)2
#  define d (T)3

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype T
//
///////////////////////////////////////////////////////////////////////////////
class a_T {
public:
   enum Tag_T {
      tag_f = 0, tag_g = 1
   };

public:
   const Tag_T tag__; // variant tag
protected:
   inline a_T(Tag_T t__) : tag__(t__) {}
public:
};
inline int boxed(const a_T * x) { return (unsigned long)x >= 4; }
inline int untag(const a_T * x) { return boxed(x) ? x->tag__ + 4 : (int)x; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor T::f
//
///////////////////////////////////////////////////////////////////////////////
class T_f : public a_T {
public:
#line 1 "T6.pcc"
   T _1; T _2; 
   inline T_f (T x_1, T x_2)
    : a_T(tag_f), _1(x_1), _2(x_2)
   {
   }
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor T::g
//
///////////////////////////////////////////////////////////////////////////////
class T_g : public a_T {
public:
#line 1 "T6.pcc"
   T g; 
   inline T_g (T x_g)
    : a_T(tag_g), g(x_g)
   {
   }
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for T
//
///////////////////////////////////////////////////////////////////////////////
inline a_T * f (T x_1, T x_2)
{
   return new T_f (x_1, x_2);
}
inline a_T * g (T x_g)
{
   return new T_g (x_g);
}
///////////////////////////////////////////////////////////////////////////////
//
// Downcasting functions for T
//
///////////////////////////////////////////////////////////////////////////////
inline T_f * _f(const a_T * _x_) { return (T_f *)_x_; }
inline T_g * _g(const a_T * _x_) { return (T_g *)_x_; }

#line 1 "T6.pcc"
#line 1 "T6.pcc"


int main()
{  T e;
   
#line 5 "T6.pcc"
#line 12 "T6.pcc"
   extern void  _T_6co_X1_rewrite(T & );
   _T_6co_X1_rewrite(e);
#line 12 "T6.pcc"
#line 12 "T6.pcc"

}
#line 14 "T6.pcc"
class _T_6co_X1 : public BURS {
private:
   _T_6co_X1(const _T_6co_X1&);               // no copy constructor
   void operator = (const _T_6co_X1&); // no assignment
public:
   struct _T_6co_X1_StateRec * stack__, * stack_top__;
public:
   void labeler(const char *, int&, int);
   void labeler(Quark, int&, int);
          void  labeler(T & redex, int&, int);
   inline virtual void  operator () (T & redex) { int s; labeler(redex,s,0); }
private: 
   public:
      inline _T_6co_X1() {}
};
void  _T_6co_X1_rewrite(T &  _x_) 
{  _T_6co_X1 _r_;
   _r_(_x_);
}

///////////////////////////////////////////////////////////////////////////////
//
// This macro can be redefined by the user for debugging
//
///////////////////////////////////////////////////////////////////////////////
#ifndef DEBUG__T_6co_X1
#define DEBUG__T_6co_X1(repl,redex,file,line,rule) repl
#else
static const char * _T_6co_X1_file_name = "T6.pcc";
#endif

static const TreeTables::ShortState _T_6co_X1_theta_4[3][3] = {
   { 0, 6, 10 },
   { 5, 8, 12 },
   { 9, 7, 11 }
};


static const TreeTables::ShortState _T_6co_X1_mu_4_0[13] = {
   0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0
};


static const TreeTables::ShortState _T_6co_X1_mu_4_1[13] = {
   0, 0, 0, 1, 0, 0, 2, 2, 2, 0, 0, 0, 0
};


inline void  _T_6co_X1::labeler(char const * redex,int& s__,int)
{
   {
s__ = 0;
   }
}

inline void  _T_6co_X1::labeler(Quark redex,int& s__,int)
{
   {
s__ = 0;
   }
}

void  _T_6co_X1::labeler (T & redex, int& s__, int r__)
{
replacement__:
   if (boxed(redex)) {
      if (redex->tag__) {
         int s0__;
         labeler(_g(redex)->g, s0__, r__);
         s__ = 4;
      } else {
         int s0__;
         int s1__;
         labeler(_f(redex)->_1, s0__, r__);
         labeler(_f(redex)->_2, s1__, r__);
         s__ = _T_6co_X1_theta_4[_T_6co_X1_mu_4_0[s0__]][_T_6co_X1_mu_4_1[s1__]]; 
      }
   } else {
      switch(((int)redex)) {
         case ((int)a): { s__ = 1;} break;
         case ((int)b): { s__ = 2;} break;
         case ((int)c): { s__ = 3;} break;
         default: { s__ = 0;} break;
      }
   }
   switch (s__) {
      case 10: {
#line 11 "T6.pcc"
         { redex = DEBUG__T_6co_X1(f(d,g(_f(_f(redex)->_2)->_1)),redex,_T_6co_X1_file_name,11,"f (_, f (X, c)): ...");
           r__ = 1; goto replacement__; }
#line 12 "T6.pcc"
} break;
      case 4: {
#line 9 "T6.pcc"
         { redex = DEBUG__T_6co_X1(f(c,_g(redex)->g),redex,_T_6co_X1_file_name,9,"g X: ...");
           r__ = 1; goto replacement__; }
#line 10 "T6.pcc"
} break;
      case 11: 
      case 9: 
      case 7: {
#line 8 "T6.pcc"
         { redex = DEBUG__T_6co_X1(_f(redex)->_2,redex,_T_6co_X1_file_name,8,"f (c, X): ...");
           r__ = 1; goto replacement__; }
#line 9 "T6.pcc"
} break;
      case 12: 
      case 8: 
      case 5: {
#line 7 "T6.pcc"
         { redex = DEBUG__T_6co_X1(a,redex,_T_6co_X1_file_name,7,"f (b, X): ...");
           r__ = 1; goto replacement__; }
#line 8 "T6.pcc"
} break;
      case 1: {
#line 6 "T6.pcc"
         { redex = DEBUG__T_6co_X1(b,redex,_T_6co_X1_file_name,6,"a: ...");
           r__ = 1; goto replacement__; }
#line 7 "T6.pcc"
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
