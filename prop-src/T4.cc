///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.4),
//  last updated on Apr 4, 1997.
//  The original source file is "T4.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_REWRITING_USED
#define PROP_QUARK_USED
#include <propdefs.h>
#line 1 "T4.pcc"
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

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor T::f
//
///////////////////////////////////////////////////////////////////////////////
class a_T : public TermObj {
public:
#line 1 "T4.pcc"
   T _1; T _2; 
   inline a_T (T x_1, T x_2)
    : _1(x_1), _2(x_2)
   {
   }
};
inline int boxed(const a_T * x) { return (unsigned long)x >= 2; }
inline int untag(const a_T * x) { return boxed(x) ? 3 : (int)x; }
///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for T
//
///////////////////////////////////////////////////////////////////////////////
inline a_T * f (T x_1, T x_2)
{
   return new a_T (x_1, x_2);
}
///////////////////////////////////////////////////////////////////////////////
//
// Downcasting functions for T
//
///////////////////////////////////////////////////////////////////////////////


#line 1 "T4.pcc"
#line 1 "T4.pcc"


T foo(T e)
{
   
#line 5 "T4.pcc"
#line 10 "T4.pcc"
   extern void  _T_4co_X1_rewrite(T & );
   _T_4co_X1_rewrite(e);
#line 10 "T4.pcc"
#line 10 "T4.pcc"

}
#line 12 "T4.pcc"
class _T_4co_X1 : public BURS {
private:
   _T_4co_X1(const _T_4co_X1&);               // no copy constructor
   void operator = (const _T_4co_X1&); // no assignment
public:
   struct _T_4co_X1_StateRec * stack__, * stack_top__;
public:
   void labeler(const char *, int&, int);
   void labeler(Quark, int&, int);
          void  labeler(T & redex, int&, int);
   inline virtual void  operator () (T & redex) { int s; labeler(redex,s,0); }
private: 
   public:
      inline _T_4co_X1() {}
};
void  _T_4co_X1_rewrite(T &  _x_) 
{  _T_4co_X1 _r_;
   _r_(_x_);
}

///////////////////////////////////////////////////////////////////////////////
//
// This macro can be redefined by the user for debugging
//
///////////////////////////////////////////////////////////////////////////////
#ifndef DEBUG__T_4co_X1
#define DEBUG__T_4co_X1(repl,redex,file,line,rule) repl
#else
static const char * _T_4co_X1_file_name = "T4.pcc";
#endif

static const TreeTables::ShortState _T_4co_X1_theta_2[3][3] = {
   { 0, 3, 0 },
   { 0, 4, 6 },
   { 5, 7, 5 }
};


static const TreeTables::ShortState _T_4co_X1_mu_2_0[8] = {
   0, 1, 2, 0, 0, 0, 0, 0
};


static const TreeTables::ShortState _T_4co_X1_mu_2_1[8] = {
   0, 1, 2, 0, 0, 0, 0, 0
};


inline void  _T_4co_X1::labeler(char const * redex,int& s__,int)
{
   {
s__ = 0;
   }
}

inline void  _T_4co_X1::labeler(Quark redex,int& s__,int)
{
   {
s__ = 0;
   }
}

void  _T_4co_X1::labeler (T & redex, int& s__, int r__)
{
replacement__:
   int cached__;
   if (r__ && boxed(redex) && (cached__ = redex->get_rewrite_state()) != BURS::undefined_state)
   { s__ = cached__; return; }
   if (boxed(redex)) {
      int s0__;
      int s1__;
      labeler(redex->_1, s0__, r__);
      labeler(redex->_2, s1__, r__);
      s__ = _T_4co_X1_theta_2[_T_4co_X1_mu_2_0[s0__]][_T_4co_X1_mu_2_1[s1__]]; 
   } else {
      if (((int)redex)) {s__ = 2;
      } else {s__ = 1;
      }
   }
   switch (s__) {
      case 3: {
#line 9 "T4.pcc"
         T  repl__ = a;
         { redex = DEBUG__T_4co_X1(repl__,redex,_T_4co_X1_file_name,9,"f (X, a): ...");
           r__ = 1; goto replacement__; }
#line 10 "T4.pcc"
} break;
      case 4: {
#line 8 "T4.pcc"
         T  repl__ = b;
         { redex = DEBUG__T_4co_X1(repl__,redex,_T_4co_X1_file_name,8,"f (a, a): ...");
           r__ = 1; goto replacement__; }
#line 9 "T4.pcc"
} break;
      case 7: 
      case 5: {
#line 7 "T4.pcc"
         { redex = DEBUG__T_4co_X1(redex->_2,redex,_T_4co_X1_file_name,7,"f (b, X): ...");
           r__ = 1; goto replacement__; }
#line 8 "T4.pcc"
} break;
      case 6: {
#line 6 "T4.pcc"
         { redex = DEBUG__T_4co_X1(b,redex,_T_4co_X1_file_name,6,"f (a, b): ...");
           r__ = 1; goto replacement__; }
#line 7 "T4.pcc"
} break;
   }
   if (boxed(redex)) {
      redex->set_rewrite_state(s__);
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
