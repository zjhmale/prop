///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.4),
//  last updated on Apr 4, 1997.
//  The original source file is "T7.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_REWRITING_USED
#define PROP_QUARK_USED
#include <propdefs.h>
#line 7 "T7.pcc"
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
class a_Wff : public TermObj {
public:
   enum Tag_Wff {
      tag_VAR = 0, tag_NOT = 1, tag_AND = 2, 
      tag_OR = 3
   };

public:
   const Tag_Wff tag__; // variant tag
protected:
   inline a_Wff(Tag_Wff t__) : tag__(t__) {}
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
#line 3 "T7.pcc"
   Quark VAR; 
   inline Wff_VAR (Quark x_VAR)
    : a_Wff(tag_VAR), VAR(x_VAR)
   {
   }
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Wff::NOT
//
///////////////////////////////////////////////////////////////////////////////
class Wff_NOT : public a_Wff {
public:
#line 4 "T7.pcc"
   Wff NOT; 
   inline Wff_NOT (Wff x_NOT)
    : a_Wff(tag_NOT), NOT(x_NOT)
   {
   }
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Wff::AND
//
///////////////////////////////////////////////////////////////////////////////
class Wff_AND : public a_Wff {
public:
#line 5 "T7.pcc"
   Wff _1; Wff _2; 
   inline Wff_AND (Wff x_1, Wff x_2)
    : a_Wff(tag_AND), _1(x_1), _2(x_2)
   {
   }
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Wff::OR
//
///////////////////////////////////////////////////////////////////////////////
class Wff_OR : public a_Wff {
public:
#line 6 "T7.pcc"
   Wff _1; Wff _2; 
   inline Wff_OR (Wff x_1, Wff x_2)
    : a_Wff(tag_OR), _1(x_1), _2(x_2)
   {
   }
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

#line 7 "T7.pcc"
#line 7 "T7.pcc"


Wff dnf (Wff wff)
{
   
#line 11 "T7.pcc"
#line 30 "T7.pcc"
   extern void  _T_7co_X1_rewrite(Wff & );
   _T_7co_X1_rewrite(wff);
#line 30 "T7.pcc"
#line 30 "T7.pcc"

   return wff;
}
#line 33 "T7.pcc"
class _T_7co_X1 : public BURS {
private:
   _T_7co_X1(const _T_7co_X1&);               // no copy constructor
   void operator = (const _T_7co_X1&); // no assignment
public:
   struct _T_7co_X1_StateRec * stack__, * stack_top__;
public:
   void labeler(const char *, int&, int);
   void labeler(Quark, int&, int);
          void  labeler(Wff & redex, int&, int);
   inline virtual void  operator () (Wff & redex) { int s; labeler(redex,s,0); }
private: 
   public:
      inline _T_7co_X1() {}
};
void  _T_7co_X1_rewrite(Wff &  _x_) 
{  _T_7co_X1 _r_;
   _r_(_x_);
}

///////////////////////////////////////////////////////////////////////////////
//
// This macro can be redefined by the user for debugging
//
///////////////////////////////////////////////////////////////////////////////
#ifndef DEBUG__T_7co_X1
#define DEBUG__T_7co_X1(repl,redex,file,line,rule) repl
#else
static const char * _T_7co_X1_file_name = "T7.pcc";
#endif

static const TreeTables::ShortState _T_7co_X1_theta_3[5] = {
   3, 6, 13, 24, 28
};


static const TreeTables::ShortState _T_7co_X1_theta_4[5][4] = {
   { 4, 7, 14, 29 },
   { 9, 8, 16, 33 },
   { 17, 18, 15, 32 },
   { 25, 27, 26, 31 },
   { 34, 36, 35, 30 }
};


static const TreeTables::ShortState _T_7co_X1_theta_5[4][3] = {
   { 5, 10, 19 },
   { 12, 11, 21 },
   { 22, 23, 20 },
   { 37, 39, 38 }
};


static const TreeTables::ShortState _T_7co_X1_mu_3_0[40] = {
   0, 1, 2, 3, 0, 4, 3, 0, 0, 0, 4, 4, 4, 3, 0, 0, 
   0, 0, 0, 4, 4, 4, 4, 4, 3, 0, 0, 0, 3, 0, 0, 0, 
   0, 0, 0, 0, 0, 4, 4, 4
};


static const TreeTables::ShortState _T_7co_X1_mu_4_0[40] = {
   0, 1, 2, 0, 3, 4, 0, 3, 3, 3, 4, 4, 4, 0, 3, 3, 
   3, 3, 3, 4, 4, 4, 4, 4, 0, 3, 3, 3, 0, 3, 3, 3, 
   3, 3, 3, 3, 3, 4, 4, 4
};


static const TreeTables::ShortState _T_7co_X1_mu_4_1[40] = {
   0, 1, 2, 0, 0, 3, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 
   0, 0, 0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 3, 3, 3
};


static const TreeTables::ShortState _T_7co_X1_mu_5_0[40] = {
   0, 1, 2, 0, 0, 3, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 
   0, 0, 0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 3, 3, 3
};


static const TreeTables::ShortState _T_7co_X1_mu_5_1[40] = {
   0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0
};


inline void  _T_7co_X1::labeler(char const * redex,int& s__,int)
{
   {
s__ = 0;
   }
}

inline void  _T_7co_X1::labeler(Quark redex,int& s__,int)
{
   {
s__ = 0;
   }
}

void  _T_7co_X1::labeler (Wff & redex, int& s__, int r__)
{
replacement__:
   int cached__;
   if (r__ && boxed(redex) && (cached__ = redex->get_rewrite_state()) != BURS::undefined_state)
   { s__ = cached__; return; }
   if (boxed(redex)) {
      switch(redex->tag__) {
         case a_Wff::tag_VAR: { 
            int s0__;
            labeler(_VAR(redex)->VAR, s0__, r__);
            s__ = 0;} break;
         case a_Wff::tag_NOT: { 
            int s0__;
            labeler(_NOT(redex)->NOT, s0__, r__);
            s__ = _T_7co_X1_theta_3[_T_7co_X1_mu_3_0[s0__]]; } break;
         case a_Wff::tag_AND: { 
            int s0__;
            int s1__;
            labeler(_AND(redex)->_1, s0__, r__);
            labeler(_AND(redex)->_2, s1__, r__);
            s__ = _T_7co_X1_theta_4[_T_7co_X1_mu_4_0[s0__]][_T_7co_X1_mu_4_1[s1__]]; } break;
         default: { 
            int s0__;
            int s1__;
            labeler(_OR(redex)->_1, s0__, r__);
            labeler(_OR(redex)->_2, s1__, r__);
            s__ = _T_7co_X1_theta_5[_T_7co_X1_mu_5_0[s0__]][_T_7co_X1_mu_5_1[s1__]]; } break;
      }
   } else {
      if (((int)redex)) {s__ = 2;
      } else {s__ = 1;
      }
   }
   switch (s__) {
      case 25: {
#line 29 "T7.pcc"
         Wff  repl__;
         Wff  _X3 = _AND(_AND(redex)->_1)->_2;
         int _X2 = boxed(_X3) ? _X3->get_rewrite_state() : ((int)_X3 + 0);
         switch (_X2) {
            case 4: repl__ = AND(_AND(_AND(redex)->_1)->_1,AND(_AND(_AND(_AND(redex)->_1)->_2)->_1,AND(_AND(_AND(_AND(redex)->_1)->_2)->_2,_AND(redex)->_2))); break;
            default: 
            repl__ = AND(_AND(_AND(redex)->_1)->_1,AND(_AND(_AND(redex)->_1)->_2,_AND(redex)->_2)); break;
         }
         { redex = DEBUG__T_7co_X1(repl__,redex,_T_7co_X1_file_name,29,"AND (AND (X, Y), Z): ...");
           r__ = 1; goto replacement__; }
#line 30 "T7.pcc"
} break;
      case 37: {
#line 28 "T7.pcc"
         Wff  repl__;
         Wff  _X5 = _OR(_OR(redex)->_1)->_2;
         int _X4 = boxed(_X5) ? _X5->get_rewrite_state() : ((int)_X5 + 0);
         switch (_X4) {
            case 5: repl__ = OR(_OR(_OR(redex)->_1)->_1,OR(_OR(_OR(_OR(redex)->_1)->_2)->_1,OR(_OR(_OR(_OR(redex)->_1)->_2)->_2,_OR(redex)->_2))); break;
            default: 
            repl__ = OR(_OR(_OR(redex)->_1)->_1,OR(_OR(_OR(redex)->_1)->_2,_OR(redex)->_2)); break;
         }
         { redex = DEBUG__T_7co_X1(repl__,redex,_T_7co_X1_file_name,28,"OR (OR (X, Y), Z): ...");
           r__ = 1; goto replacement__; }
#line 29 "T7.pcc"
} break;
      case 31: 
      case 29: {
#line 27 "T7.pcc"
         Wff  repl__;
         Wff  _X7 = _AND(redex)->_1;
         int _X6 = boxed(_X7) ? _X7->get_rewrite_state() : ((int)_X7 + 0);
         switch (_X6) {
            case 4: repl__ = OR(AND(_AND(_AND(redex)->_1)->_1,AND(_AND(_AND(redex)->_1)->_2,_OR(_AND(redex)->_2)->_1)),AND(_AND(_AND(redex)->_1)->_1,AND(_AND(_AND(redex)->_1)->_2,_OR(_AND(redex)->_2)->_2))); break;
            default: 
            Wff  _X9 = _OR(_AND(redex)->_2)->_2;
            int _X8 = boxed(_X9) ? _X9->get_rewrite_state() : ((int)_X9 + 0);
            switch (_X8) {
               case 5: repl__ = OR(AND(_AND(redex)->_1,_OR(_AND(redex)->_2)->_1),OR(AND(_AND(redex)->_1,_OR(_OR(_AND(redex)->_2)->_2)->_1),AND(_AND(redex)->_1,_OR(_OR(_AND(redex)->_2)->_2)->_2))); break;
               default: 
               repl__ = OR(AND(_AND(redex)->_1,_OR(_AND(redex)->_2)->_1),AND(_AND(redex)->_1,_OR(_AND(redex)->_2)->_2)); break;
            }
         }
         { redex = DEBUG__T_7co_X1(repl__,redex,_T_7co_X1_file_name,27,"AND (X, OR (Y, Z)): ...");
           r__ = 1; goto replacement__; }
#line 28 "T7.pcc"
} break;
      case 34: 
      case 30: {
#line 26 "T7.pcc"
         Wff  repl__;
         Wff  _X11 = _OR(_AND(redex)->_1)->_1;
         int _X10 = boxed(_X11) ? _X11->get_rewrite_state() : ((int)_X11 + 0);
         switch (_X10) {
            case 4: repl__ = OR(AND(_AND(_OR(_AND(redex)->_1)->_1)->_1,AND(_AND(_OR(_AND(redex)->_1)->_1)->_2,_AND(redex)->_2)),AND(_OR(_AND(redex)->_1)->_2,_AND(redex)->_2)); break;
            default: 
            Wff  _X13 = _OR(_AND(redex)->_1)->_2;
            int _X12 = boxed(_X13) ? _X13->get_rewrite_state() : ((int)_X13 + 0);
            switch (_X12) {
               case 5: repl__ = OR(AND(_OR(_AND(redex)->_1)->_1,_AND(redex)->_2),OR(AND(_OR(_OR(_AND(redex)->_1)->_2)->_1,_AND(redex)->_2),AND(_OR(_OR(_AND(redex)->_1)->_2)->_2,_AND(redex)->_2))); break;
               case 4: repl__ = OR(AND(_OR(_AND(redex)->_1)->_1,_AND(redex)->_2),AND(_AND(_OR(_AND(redex)->_1)->_2)->_1,AND(_AND(_OR(_AND(redex)->_1)->_2)->_2,_AND(redex)->_2))); break;
               default: 
               Wff  _X15 = _AND(redex)->_2;
               int _X14 = boxed(_X15) ? _X15->get_rewrite_state() : ((int)_X15 + 0);
               switch (_X14) {
                  case 5: repl__ = OR(AND(_OR(_AND(redex)->_1)->_1,_OR(_AND(redex)->_2)->_1),OR(AND(_OR(_AND(redex)->_1)->_1,_OR(_AND(redex)->_2)->_2),OR(AND(_OR(_AND(redex)->_1)->_2,_OR(_AND(redex)->_2)->_1),AND(_OR(_AND(redex)->_1)->_2,_OR(_AND(redex)->_2)->_2)))); break;
                  default: 
                  repl__ = OR(AND(_OR(_AND(redex)->_1)->_1,_AND(redex)->_2),AND(_OR(_AND(redex)->_1)->_2,_AND(redex)->_2)); break;
               }
            }
         }
         { redex = DEBUG__T_7co_X1(repl__,redex,_T_7co_X1_file_name,26,"AND (OR (X, Y), Z): ...");
           r__ = 1; goto replacement__; }
#line 27 "T7.pcc"
} break;
      case 28: {
#line 24 "T7.pcc"
         Wff  repl__;
         Wff  _X17 = _OR(_NOT(redex)->NOT)->_1;
         int _X16 = boxed(_X17) ? _X17->get_rewrite_state() : ((int)_X17 + 0);
         switch (_X16) {
            case 3: repl__ = AND(_NOT(_OR(_NOT(redex)->NOT)->_1)->NOT,NOT(_OR(_NOT(redex)->NOT)->_2)); break;
            default: 
            Wff  _X19 = _OR(_NOT(redex)->NOT)->_2;
            int _X18 = boxed(_X19) ? _X19->get_rewrite_state() : ((int)_X19 + 0);
            switch (_X18) {
               case 5: repl__ = AND(NOT(_OR(_NOT(redex)->NOT)->_1),AND(NOT(_OR(_OR(_NOT(redex)->NOT)->_2)->_1),NOT(_OR(_OR(_NOT(redex)->NOT)->_2)->_2))); break;
               case 3: repl__ = AND(NOT(_OR(_NOT(redex)->NOT)->_1),_NOT(_OR(_NOT(redex)->NOT)->_2)->NOT); break;
               default: 
               repl__ = AND(NOT(_OR(_NOT(redex)->NOT)->_1),NOT(_OR(_NOT(redex)->NOT)->_2)); break;
            }
         }
         { redex = DEBUG__T_7co_X1(repl__,redex,_T_7co_X1_file_name,24,"NOT OR (X, Y): ...");
           r__ = 1; goto replacement__; }
#line 26 "T7.pcc"
} break;
      case 35: 
      case 26: 
      case 14: {
#line 22 "T7.pcc"
         { redex = DEBUG__T_7co_X1(F,redex,_T_7co_X1_file_name,22,"AND (_, F): ...");
           r__ = 1; goto replacement__; }
#line 24 "T7.pcc"
} break;
      case 32: 
      case 17: 
      case 15: {
#line 21 "T7.pcc"
         { redex = DEBUG__T_7co_X1(F,redex,_T_7co_X1_file_name,21,"AND (F, _): ...");
           r__ = 1; goto replacement__; }
#line 22 "T7.pcc"
} break;
      case 36: 
      case 27: 
      case 18: 
      case 7: {
#line 20 "T7.pcc"
         { redex = DEBUG__T_7co_X1(_AND(redex)->_1,redex,_T_7co_X1_file_name,20,"AND (X, T): ...");
           r__ = 1; goto replacement__; }
#line 21 "T7.pcc"
} break;
      case 33: 
      case 16: 
      case 9: 
      case 8: {
#line 19 "T7.pcc"
         { redex = DEBUG__T_7co_X1(_AND(redex)->_2,redex,_T_7co_X1_file_name,19,"AND (T, X): ...");
           r__ = 1; goto replacement__; }
#line 20 "T7.pcc"
} break;
      case 38: 
      case 19: {
#line 18 "T7.pcc"
         { redex = DEBUG__T_7co_X1(_OR(redex)->_1,redex,_T_7co_X1_file_name,18,"OR (X, F): ...");
           r__ = 1; goto replacement__; }
#line 19 "T7.pcc"
} break;
      case 22: 
      case 20: {
#line 17 "T7.pcc"
         { redex = DEBUG__T_7co_X1(_OR(redex)->_2,redex,_T_7co_X1_file_name,17,"OR (F, X): ...");
           r__ = 1; goto replacement__; }
#line 18 "T7.pcc"
} break;
      case 39: 
      case 23: 
      case 10: {
#line 16 "T7.pcc"
         { redex = DEBUG__T_7co_X1(T,redex,_T_7co_X1_file_name,16,"OR (_, T): ...");
           r__ = 1; goto replacement__; }
#line 17 "T7.pcc"
} break;
      case 21: 
      case 12: 
      case 11: {
#line 15 "T7.pcc"
         { redex = DEBUG__T_7co_X1(T,redex,_T_7co_X1_file_name,15,"OR (T, _): ...");
           r__ = 1; goto replacement__; }
#line 16 "T7.pcc"
} break;
      case 24: {
#line 14 "T7.pcc"
         { redex = DEBUG__T_7co_X1(_NOT(_NOT(redex)->NOT)->NOT,redex,_T_7co_X1_file_name,14,"NOT NOT X: ...");
           r__ = 1; goto replacement__; }
#line 15 "T7.pcc"
} break;
      case 13: {
#line 13 "T7.pcc"
         { redex = DEBUG__T_7co_X1(T,redex,_T_7co_X1_file_name,13,"NOT F: ...");
           r__ = 1; goto replacement__; }
#line 14 "T7.pcc"
} break;
      case 6: {
#line 12 "T7.pcc"
         { redex = DEBUG__T_7co_X1(F,redex,_T_7co_X1_file_name,12,"NOT T: ...");
           r__ = 1; goto replacement__; }
#line 13 "T7.pcc"
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
