///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.4),
//  last updated on Apr 3, 1997.
//  The original source file is "T5.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_REWRITING_USED
#define PROP_QUARK_USED
#include <propdefs.h>
#line 1 "T5.pcc"
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
inline int boxed(const a_T * x) { return (unsigned long)x >= 3; }
inline int untag(const a_T * x) { return boxed(x) ? x->tag__ + 3 : (int)x; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor T::f
//
///////////////////////////////////////////////////////////////////////////////
class T_f : public a_T {
public:
#line 1 "T5.pcc"
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
#line 1 "T5.pcc"
   T _1; T _2; 
   inline T_g (T x_1, T x_2)
    : a_T(tag_g), _1(x_1), _2(x_2)
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
inline a_T * g (T x_1, T x_2)
{
   return new T_g (x_1, x_2);
}
///////////////////////////////////////////////////////////////////////////////
//
// Downcasting functions for T
//
///////////////////////////////////////////////////////////////////////////////
inline T_f * _f(const a_T * _x_) { return (T_f *)_x_; }
inline T_g * _g(const a_T * _x_) { return (T_g *)_x_; }

#line 1 "T5.pcc"
#line 1 "T5.pcc"


T foo(T e)
{
   
#line 5 "T5.pcc"
#line 11 "T5.pcc"
   extern void  _T_5co_X1_rewrite(T & );
   _T_5co_X1_rewrite(e);
#line 11 "T5.pcc"
#line 11 "T5.pcc"

}
#line 13 "T5.pcc"
class _T_5co_X1 : public BURS {
private:
   _T_5co_X1(const _T_5co_X1&);               // no copy constructor
   void operator = (const _T_5co_X1&); // no assignment
public:
   struct _T_5co_X1_StateRec * stack__, * stack_top__;
public:
   void labeler(const char *, int&, int);
   void labeler(Quark, int&, int);
          void  labeler(T & redex, int&, int);
   inline virtual void  operator () (T & redex) { int s; labeler(redex,s,0); }
private: 
   public:
      inline _T_5co_X1() {}
};
void  _T_5co_X1_rewrite(T &  _x_) 
{  _T_5co_X1 _r_;
   _r_(_x_);
}

///////////////////////////////////////////////////////////////////////////////
//
// This macro can be redefined by the user for debugging
//
///////////////////////////////////////////////////////////////////////////////
#ifndef DEBUG__T_5co_X1
#define DEBUG__T_5co_X1(repl,redex,file,line,rule) repl
#else
static const char * _T_5co_X1_file_name = "T5.pcc";
#endif

inline void  _T_5co_X1::labeler(char const * redex,int& s__,int)
{
   {
s__ = 0;
   }
}

inline void  _T_5co_X1::labeler(Quark redex,int& s__,int)
{
   {
s__ = 0;
   }
}

void  _T_5co_X1::labeler (T & redex, int& s__, int r__)
{
replacement__:
   for (int topdown__ = 0; topdown__ <= 1; topdown__++) {
      {
         if (boxed(redex)) {
            if (redex->tag__) {
               
#line 10 "T5.pcc"
               { redex = DEBUG__T_5co_X1(f(_g(redex)->_1,_g(redex)->_2),redex,_T_5co_X1_file_name,10,"g (X, Y): ...");
                 r__ = 1; goto replacement__; }
#line 11 "T5.pcc"
            } else {
               
               if (boxed(_f(redex)->_1)) {} else {
                  switch ((int)_f(redex)->_1) {
                     case ((int)a): {
                        if (boxed(_f(redex)->_2)) {} else {
                           switch ((int)_f(redex)->_2) {
                              case ((int)a): {} break;
                              case ((int)b): {
#line 8 "T5.pcc"
                                 { redex = DEBUG__T_5co_X1(b,redex,_T_5co_X1_file_name,8,"f (a, b): ...");
                                   r__ = 1; goto replacement__; }
#line 9 "T5.pcc"
                                 } break;
                              default: {
#line 9 "T5.pcc"
                                 { redex = DEBUG__T_5co_X1(c,redex,_T_5co_X1_file_name,9,"f (a, c): ...");
                                   r__ = 1; goto replacement__; }
#line 10 "T5.pcc"
                                 } break;
                           }
                        }
                        } break;
                     default: {} break;
                  }
               }
            }
         } else {}
      }
      if (boxed(redex)) {
         if (redex->tag__) {
            int s0__;
            int s1__;
            labeler(_g(redex)->_1, s0__, r__);
            labeler(_g(redex)->_2, s1__, r__);
            s__ = 0;
         } else {
            int s0__;
            int s1__;
            labeler(_f(redex)->_1, s0__, r__);
            labeler(_f(redex)->_2, s1__, r__);
            s__ = 0;
         }
      } else {
         switch(((int)redex)) {
            case ((int)a): { s__ = 0;} break;
            case ((int)b): { s__ = 0;} break;
            default: { s__ = 0;} break;
         }
      }
   }
   
}

/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 15
Number of ifs generated      = 4
Number of switches generated = 2
Number of labels             = 0
Number of gotos              = 0
Adaptive matching            = disabled
Fast string matching         = disabled
Inline downcasts             = disabled
--------------------------------------------------------------------------
*/
