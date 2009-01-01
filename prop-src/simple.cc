///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.7),
//  last updated on Oct 21, 2008.
//  The original source file is "simple.pcc".
///////////////////////////////////////////////////////////////////////////////

#line 1 "simple.pcc"
#include <iostream>
#include <memory>

#line 4 "simple.pcc"
#line 9 "simple.pcc"
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
// Class for datatype constructor Exp::INT
//
///////////////////////////////////////////////////////////////////////////////
class Exp_INT : public a_Exp {
public:
#line 4 "simple.pcc"
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
#line 5 "simple.pcc"
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
#line 6 "simple.pcc"
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
#line 7 "simple.pcc"
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
#line 8 "simple.pcc"
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

#line 9 "simple.pcc"
#line 9 "simple.pcc"


#line 11 "simple.pcc"
#line 11 "simple.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Q
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Q_defined
#define datatype_Q_defined
   class a_Q;
   typedef a_Q * Q;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype Q
//
///////////////////////////////////////////////////////////////////////////////
class a_Q {
public:
   enum Tag_Q {
      tag_Expr = 0, tag_Str = 1
   };

public:
   const Tag_Q tag__; // variant tag
protected:
   inline a_Q(Tag_Q t__) : tag__(t__) {}
public:
};
inline int boxed(const a_Q *) { return 1; }
inline int untag(const a_Q * x) { return x->tag__; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Q::Expr
//
///////////////////////////////////////////////////////////////////////////////
class Q_Expr : public a_Q {
public:
#line 11 "simple.pcc"
   Exp Expr; 
   inline Q_Expr (Exp x_Expr)
    : a_Q(tag_Expr), Expr(x_Expr)
   {
   }
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Q::Str
//
///////////////////////////////////////////////////////////////////////////////
class Q_Str : public a_Q {
public:
#line 11 "simple.pcc"
   std::string Str; 
   inline Q_Str (std::string x_Str)
    : a_Q(tag_Str), Str(x_Str)
   {
   }
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for Q
//
///////////////////////////////////////////////////////////////////////////////
inline a_Q * Expr (Exp x_Expr)
{
   return new Q_Expr (x_Expr);
}
inline a_Q * Str (std::string x_Str)
{
   return new Q_Str (x_Str);
}
///////////////////////////////////////////////////////////////////////////////
//
// Downcasting functions for Q
//
///////////////////////////////////////////////////////////////////////////////
inline Q_Expr * _Expr(const a_Q * _x_) { return (Q_Expr *)_x_; }
inline Q_Str * _Str(const a_Q * _x_) { return (Q_Str *)_x_; }

#line 11 "simple.pcc"
#line 11 "simple.pcc"


int main()
{
  std::auto_ptr<a_Q> q(Expr(ADD(INT(2),INT(3))));

  
#line 17 "simple.pcc"
#line 19 "simple.pcc"
{
   Q _V1 = q.get();
   if (_V1->tag__) {
      
#line 19 "simple.pcc"
     std::cout << _Str(_V1)->Str << std::endl; 
#line 19 "simple.pcc"
   } else {
      
#line 18 "simple.pcc"
     std::cout << "expr" << std::endl; 
#line 18 "simple.pcc"
   }
}
#line 20 "simple.pcc"
#line 20 "simple.pcc"


  return 0;
}
#line 24 "simple.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 0
Number of ifs generated      = 1
Number of switches generated = 0
Number of labels             = 0
Number of gotos              = 0
Adaptive matching            = disabled
Fast string matching         = disabled
Inline downcasts             = disabled
--------------------------------------------------------------------------
*/
