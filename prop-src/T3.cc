///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.4),
//  last updated on Mar 31, 1997.
//  The original source file is "T3.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_REWRITING_USED
#define PROP_QUARK_USED
#include <propdefs.h>
#line 1 "T3.pcc"
//
//  Test the view mechanism
//

#include <assert.h>
#include <istd::ostream.h>

enum exp_tag { Int = 1, Ident, Add, Sub, Mul, Div };

struct exp {
   enum exp_tag tag;
   union {
      int number;
      const char * ident;
      struct { struct exp * l, * r; } children;
   } u;
};

typedef struct exp * Exp;

Exp INT(int i) 
{  Exp e = new exp; e->tag = Int; e->u.number = i; return e; }

Exp ID(const char * id) 
{  Exp e = new exp; e->tag = Ident; e->u.ident = id; return e; }

Exp ADD(Exp a, Exp b)
{  Exp e = new exp; e->tag = Add; e->u.children.l = a; e->u.children.r = b;
   return e;
}
   
Exp SUB(Exp a, Exp b)
{  Exp e = new exp; e->tag = Sub; e->u.children.l = a; e->u.children.r = b;
   return e;
}
   
Exp MUL(Exp a, Exp b)
{  Exp e = new exp; e->tag = Mul; e->u.children.l = a; e->u.children.r = b;
   return e;
}
   
Exp DIV(Exp a, Exp b)
{  Exp e = new exp; e->tag = Div; e->u.children.l = a; e->u.children.r = b;
   return e;
}
   
#line 47 "T3.pcc"
#line 58 "T3.pcc"
#line 58 "T3.pcc"
#line 58 "T3.pcc"


std::ostream& operator << (std::ostream& s, const Exp& e)
{  
#line 61 "T3.pcc"
#line 68 "T3.pcc"
{
   switch ((e ? e->tag : 0)) {
      case 0: {
#line 62 "T3.pcc"
        return s << "NONE"; 
#line 62 "T3.pcc"
      } break;
      case Int: {
#line 63 "T3.pcc"
        return s << e->u.number; 
#line 63 "T3.pcc"
      } break;
      case Ident: {
#line 64 "T3.pcc"
        return s << e->u.ident; 
#line 64 "T3.pcc"
      } break;
      case Add: {
#line 65 "T3.pcc"
        return s << '(' << e->u.children.l << " + " << e->u.children.r << ')'; 
#line 65 "T3.pcc"
      } break;
      case Sub: {
#line 66 "T3.pcc"
        return s << '(' << e->u.children.l << " - " << e->u.children.r << ')'; 
#line 66 "T3.pcc"
      } break;
      case Mul: {
#line 67 "T3.pcc"
        return s << '(' << e->u.children.l << " * " << e->u.children.r << ')'; 
#line 67 "T3.pcc"
      } break;
      case Div: {
#line 68 "T3.pcc"
        return s << '(' << e->u.children.l << " / " << e->u.children.r << ')'; 
#line 68 "T3.pcc"
      } break;
      case 10: {} break;
   }
}
#line 69 "T3.pcc"
#line 69 "T3.pcc"

}

int eval(const Exp& e)
{  
#line 73 "T3.pcc"
#line 81 "T3.pcc"
{
   switch ((e ? e->tag : 0)) {
      case 0: {
#line 74 "T3.pcc"
        return 0; 
#line 74 "T3.pcc"
      } break;
      case Int: {
#line 75 "T3.pcc"
        return e->u.number; 
#line 75 "T3.pcc"
      } break;
      case Ident: {
#line 76 "T3.pcc"
        return 0; 
#line 76 "T3.pcc"
      } break;
      case Add: {
#line 77 "T3.pcc"
        return eval(e->u.children.l) + eval(e->u.children.r); 
#line 77 "T3.pcc"
      } break;
      case Sub: {
#line 78 "T3.pcc"
        return eval(e->u.children.l) - eval(e->u.children.r); 
#line 78 "T3.pcc"
      } break;
      case Mul: {
#line 79 "T3.pcc"
        return eval(e->u.children.l) * eval(e->u.children.r); 
#line 79 "T3.pcc"
      } break;
      case Div: {
         switch ((e->u.children.r ? e->u.children.r->tag : 0)) {
            case 0: {
               L1:; 
#line 81 "T3.pcc"
              return eval(e->u.children.l) / eval(e->u.children.r); 
#line 81 "T3.pcc"
            } break;
            case Int: {
               switch (e->u.children.r->u.number) {
                  case 0: {
                     if (
#line 80 "T3.pcc"
                     (e->u.children.l != NONE)
#line 80 "T3.pcc"
) {
                        
#line 80 "T3.pcc"
                       cerr << "Division by zero\n"; return 0; 
#line 80 "T3.pcc"
                     } else {
                         goto L1; }
                  } break;
                  default: { goto L1; }
               }
            } break;
            case Ident: { goto L1; } break;
            case Add: { goto L1; } break;
            case Sub: { goto L1; } break;
            case Mul: { goto L1; } break;
            case Div: { goto L1; } break;
            case 10: { goto L1; } break;
         }
      } break;
      case 10: {} break;
   }
}
#line 82 "T3.pcc"
#line 82 "T3.pcc"

}

void simplify(Exp& e)
{
   
#line 87 "T3.pcc"
#line 92 "T3.pcc"
   extern void  _T_3co_X1_rewrite(Exp & );
   _T_3co_X1_rewrite(e);
#line 92 "T3.pcc"
#line 92 "T3.pcc"

}

int main()
{  Exp e = ADD(MUL(INT(5),INT(2)),DIV(INT(30),INT(6)));
   cout << "Expression = " << e << endl;
   cout << "Eval(" << e << ") = " << eval(e) << endl;
   simplify(e);
   cout << "Simplified = " << e << endl;
   assert(eval(e) == 15);
   return 0;
}

Exp e = 
#line 105 "T3.pcc"
#line 105 "T3.pcc"
CALL(INT(1), INT(2))
#line 105 "T3.pcc"
#line 105 "T3.pcc"
;
#line 106 "T3.pcc"
class _T_3co_X1 : public BURS {
private:
   _T_3co_X1(const _T_3co_X1&);               // no copy constructor
   void operator = (const _T_3co_X1&); // no assignment
public:
   struct _T_3co_X1_StateRec * stack__, * stack_top__;
public:
   void labeler(const char *, int&, int);
   void labeler(Quark, int&, int);
          void  labeler(Exp & redex, int&, int);
   inline virtual void  operator () (Exp & redex) { int s; labeler(redex,s,0); }
private: 
   public:
      inline _T_3co_X1() {}
};
void  _T_3co_X1_rewrite(Exp &  _x_) 
{  _T_3co_X1 _r_;
   _r_(_x_);
}

///////////////////////////////////////////////////////////////////////////////
//
// This macro can be redefined by the user for debugging
//
///////////////////////////////////////////////////////////////////////////////
#ifndef DEBUG__T_3co_X1
#define DEBUG__T_3co_X1(repl,redex,file,line,rule) repl
#else
static const char * _T_3co_X1_file_name = "T3.pcc";
#endif

static const TreeTables::State _T_3co_X1_theta_3[2][2] = {
   { 0, 0 },
   { 0, 2 }
};


static const TreeTables::State _T_3co_X1_theta_4[2][2] = {
   { 0, 0 },
   { 0, 3 }
};


static const TreeTables::State _T_3co_X1_theta_5[2][2] = {
   { 0, 0 },
   { 0, 4 }
};


static const TreeTables::State _T_3co_X1_theta_6[2][2] = {
   { 0, 0 },
   { 0, 5 }
};


static const TreeTables::State _T_3co_X1_mu_3_0[6] = {
   0, 1, 0, 0, 0, 0
};


static const TreeTables::State _T_3co_X1_mu_3_1[6] = {
   0, 1, 0, 0, 0, 0
};


static const TreeTables::State _T_3co_X1_mu_4_0[6] = {
   0, 1, 0, 0, 0, 0
};


static const TreeTables::State _T_3co_X1_mu_4_1[6] = {
   0, 1, 0, 0, 0, 0
};


static const TreeTables::State _T_3co_X1_mu_5_0[6] = {
   0, 1, 0, 0, 0, 0
};


static const TreeTables::State _T_3co_X1_mu_5_1[6] = {
   0, 1, 0, 0, 0, 0
};


static const TreeTables::State _T_3co_X1_mu_6_0[6] = {
   0, 1, 0, 0, 0, 0
};


static const TreeTables::State _T_3co_X1_mu_6_1[6] = {
   0, 1, 0, 0, 0, 0
};


inline void  _T_3co_X1::labeler(char const * redex,int& s__,int)
{
   {
s__ = 0;
   }
}

inline void  _T_3co_X1::labeler(Quark redex,int& s__,int)
{
   {
s__ = 0;
   }
}

void  _T_3co_X1::labeler (Exp & redex, int& s__, int r__)
{
replacement__:
   switch((redex ? redex->tag : 0)) {
      case 0: { s__ = 0;} break;
      case Int: { 
         int s0__;
         s0__ = 0; // int = _0->u.number
         s__ = 1;} break;
      case Ident: { 
         int s0__;
         labeler(redex->u.ident, s0__, r__);
         s__ = 0;} break;
      case Add: { 
         int s0__;
         int s1__;
         labeler(redex->u.children.l, s0__, r__);
         labeler(redex->u.children.r, s1__, r__);
         s__ = _T_3co_X1_theta_3[_T_3co_X1_mu_3_0[s0__]][_T_3co_X1_mu_3_1[s1__]]; } break;
      case Sub: { 
         int s0__;
         int s1__;
         labeler(redex->u.children.l, s0__, r__);
         labeler(redex->u.children.r, s1__, r__);
         s__ = _T_3co_X1_theta_4[_T_3co_X1_mu_4_0[s0__]][_T_3co_X1_mu_4_1[s1__]]; } break;
      case Mul: { 
         int s0__;
         int s1__;
         labeler(redex->u.children.l, s0__, r__);
         labeler(redex->u.children.r, s1__, r__);
         s__ = _T_3co_X1_theta_5[_T_3co_X1_mu_5_0[s0__]][_T_3co_X1_mu_5_1[s1__]]; } break;
      case Div: { 
         int s0__;
         int s1__;
         labeler(redex->u.children.l, s0__, r__);
         labeler(redex->u.children.r, s1__, r__);
         s__ = _T_3co_X1_theta_6[_T_3co_X1_mu_6_0[s0__]][_T_3co_X1_mu_6_1[s1__]]; } break;
      default: { 
         int s0__;
         int s1__;
         labeler(redex->u.children.l,s0__,r__);
         labeler(redex->u.children.r,s1__,r__);
         s__ = 0;} break;
   }
   switch (s__) {
      case 5: {
#line 91 "T3.pcc"
         { redex = DEBUG__T_3co_X1(INT((redex->u.children.l->u.number / redex->u.children.r->u.number)),redex,_T_3co_X1_file_name,91,"DIV (INT i, INT j): ...");
           r__ = 1; goto replacement__; }
#line 92 "T3.pcc"
} break;
      case 4: {
#line 90 "T3.pcc"
         { redex = DEBUG__T_3co_X1(INT((redex->u.children.l->u.number * redex->u.children.r->u.number)),redex,_T_3co_X1_file_name,90,"MUL (INT i, INT j): ...");
           r__ = 1; goto replacement__; }
#line 91 "T3.pcc"
} break;
      case 3: {
#line 89 "T3.pcc"
         { redex = DEBUG__T_3co_X1(INT((redex->u.children.l->u.number - redex->u.children.r->u.number)),redex,_T_3co_X1_file_name,89,"SUB (INT i, INT j): ...");
           r__ = 1; goto replacement__; }
#line 90 "T3.pcc"
} break;
      case 2: {
#line 88 "T3.pcc"
         { redex = DEBUG__T_3co_X1(INT((redex->u.children.l->u.number + redex->u.children.r->u.number)),redex,_T_3co_X1_file_name,88,"ADD (INT i, INT j): ...");
           r__ = 1; goto replacement__; }
#line 89 "T3.pcc"
} break;
   }
   
}

/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 11
Number of ifs generated      = 1
Number of switches generated = 4
Number of labels             = 1
Number of gotos              = 8
Adaptive matching            = disabled
Fast string matching         = disabled
Inline downcasts             = disabled
--------------------------------------------------------------------------
*/
