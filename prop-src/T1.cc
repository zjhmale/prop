///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.3),
//  last updated on Mar 23, 1997.
//  The original source file is "T1.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_PRINTER_USED
#define PROP_PARSER_USED
#include <propdefs.h>
#line 6 "T1.pcc"
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
#line 1 "T1.pcc"
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
#line 1 "T1.pcc"
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
#line 2 "T1.pcc"
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
#line 3 "T1.pcc"
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
#line 4 "T1.pcc"
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

#line 6 "T1.pcc"
#line 6 "T1.pcc"


#line 8 "T1.pcc"
#line 8 "T1.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype Exp
//
///////////////////////////////////////////////////////////////////////////////
#line 8 "T1.pcc"
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
#line 8 "T1.pcc"
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



#line 8 "T1.pcc"
#line 8 "T1.pcc"


#line 10 "T1.pcc"
#line 12 "T1.pcc"
class Foo : public LR1Parser {
public:
   ////////////////////////////////////////////////////////////////////////////
   // Parser table type definitions
   ////////////////////////////////////////////////////////////////////////////
   typedef LR1Parser               Super;
   typedef Super::Offset           Offset;
   typedef Super::State            State;
   typedef Super::Rule             Rule;
   typedef Super::Symbol           Symbol;
   typedef Super::ProductionLength ProductionLength;
   typedef Super::ShortSymbol      ShortSymbol;
   typedef Super::EquivMap         EquivMap;
   enum { INITIAL_STACK_SIZE_ = 256,
          MAX_STACK_SIZE_     = 8192
        };
protected:
   ////////////////////////////////////////////////////////////////////////////
   // Semantic value stack
   ////////////////////////////////////////////////////////////////////////////
   union Foo_semantic_stack_type * t__, * bot__;
   int stack_size__;
   int heap_allocated__;
public:
   ////////////////////////////////////////////////////////////////////////////
   // Constructor and parsing method
   ////////////////////////////////////////////////////////////////////////////
   Foo();
   virtual void parse();
   void action_driver(const Rule);
private:
   void adjust_stack(int);
   void grow_semantic_stack();
#line 11 "T1.pcc"
   
#line 12 "T1.pcc"
};
#line 12 "T1.pcc"
#line 12 "T1.pcc"


#line 14 "T1.pcc"
#line 27 "T1.pcc"
///////////////////////////////////////////////////////////////////////////////
// Encoded parser tables for syntax class Foo
///////////////////////////////////////////////////////////////////////////////
static const DFATables::Offset Foo_base [ 15 ] = {
   0, 0, 8, 0, 5, 7, 6, 5, 3, 0, 0, 5, 0, 0, 0
};
static const DFATables::State Foo_check [ 19 ] = {
   0, 1, 0, 3, 3, 3, 3, 4, 3, 1, 11, 11, 8, 4, 7, 6, 
   5, 2, 0
};
static const DFATables::State Foo_next [ 19 ] = {
   0, 2, 0, 5, 6, 7, 8, 16394, 9, 3, 7, 8, 16398, 0, 16397, 12, 
   11, 4, 0
};
static const DFATables::State Foo_def [ 15 ] = {
   0, 0, 1, 0, 3, 1, 1, 1, 1, 0, 0, 0, 11, 0, 0
};
static const DFATables::State Foo_defact [ 15 ] = {
   0, 0, 0, 0, 0, 0, 0, 0, 0, 32773, 32768, 32769, 32770, 32771, 32772
};
static const DFATables::ProductionLength Foo_len [ 6 ] = {
   3, 3, 3, 3, 3, 2
};
static const DFATables::ProductionLength Foo_ncount [ 6 ] = {
   1, 2, 2, 2, 2, 1
};
static const DFATables::ShortSymbol Foo_lhs [ 6 ] = {
   9, 9, 9, 9, 9, 10
};
static const DFATables::EquivMap Foo_equiv [ 261 ] = {
   8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 5, 3, 0, 4, 0, 
   6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 9, 10
};
///////////////////////////////////////////////////////////////////////////////
// Debugging tables for syntax class Foo
///////////////////////////////////////////////////////////////////////////////

#ifdef DEBUG_Foo
static const int Foo_line[] =
{
   21, 22, 23, 24, 25, 0
};

static const char * const Foo_symbolname[] =
{
   "?", "\'(\'", "\')\'", "\'+\'", "\'-\'", "\'*\'", "\'/\'", "???", 
   "???", "exp", "???"
};

static const DFATables::ShortSymbol Foo_rhs_0[] = { 1, 9, 2,  -1 };
static const DFATables::ShortSymbol Foo_rhs_1[] = { 9, 3, 9,  -1 };
static const DFATables::ShortSymbol Foo_rhs_2[] = { 9, 4, 9,  -1 };
static const DFATables::ShortSymbol Foo_rhs_3[] = { 9, 5, 9,  -1 };
static const DFATables::ShortSymbol Foo_rhs_4[] = { 9, 6, 9,  -1 };
static const DFATables::ShortSymbol Foo_rhs_5[] = { 9, 8,  -1 };
static const DFATables::ShortSymbol * Foo_rhs[] =
{
   Foo_rhs_0, 
   Foo_rhs_1, 
   Foo_rhs_2, 
   Foo_rhs_3, 
   Foo_rhs_4, 
   Foo_rhs_5
};


#endif

///////////////////////////////////////////////////////////////////////////////
// Semantic value stack for syntax class Foo
///////////////////////////////////////////////////////////////////////////////
union Foo_semantic_stack_type {
   int dummy;
#line 20 "T1.pcc"
   typedef struct { int value;  } ATTRIBUTE_0;
   ATTRIBUTE_0 _24, _22, _21, _19, _17, _16, _14, _12, _11, _9, _7, _6, _3, _1;
};


///////////////////////////////////////////////////////////////////////////////
// Parser driver for syntax class Foo
///////////////////////////////////////////////////////////////////////////////
inline void Foo::action_driver(const Rule _r_)
{
   Foo_semantic_stack_type syn_;
   ////////////////////////////////////////////////////////////////////////////
   // Tracing code for syntax class Foo
   ////////////////////////////////////////////////////////////////////////////
#ifdef DEBUG_Foo
   {  cerr << "Reducing via rule " << _r_ << " at line "
           << Foo_line[_r_] << ", "
           << Foo_symbolname[Foo_lhs[_r_]] << " <- ";
      for (const DFATables::ShortSymbol * _p_ = Foo_rhs[_r_]; *_p_ >= 0; _p_++)
         cerr << Foo_symbolname[*_p_] << ' ';
      cerr << '\n';
   }
#endif

   ////////////////////////////////////////////////////////////////////////////
   // Actions for syntax class Foo
   ////////////////////////////////////////////////////////////////////////////
   t__ -= Foo_ncount[_r_];
   switch (_r_) {

#undef to__
#define to__ 0
      case 0: {
#line 21 "T1.pcc"
        syn_._1.value = t__[1+to__]._3.value; 
#line 21 "T1.pcc"
} break;
      case 1: {
#line 22 "T1.pcc"
        syn_._6.value = t__[1+to__]._7.value + t__[2+to__]._9.value; 
#line 22 "T1.pcc"
} break;
      case 2: {
#line 23 "T1.pcc"
        syn_._11.value = t__[1+to__]._12.value - t__[2+to__]._14.value; 
#line 23 "T1.pcc"
} break;
      case 3: {
#line 24 "T1.pcc"
        syn_._16.value = t__[1+to__]._17.value * t__[2+to__]._19.value; 
#line 24 "T1.pcc"
} break;
      case 4: {
#line 25 "T1.pcc"
        syn_._21.value = t__[1+to__]._22.value / t__[2+to__]._24.value; 
#line 25 "T1.pcc"
} break;
   }
   if (t__ >= bot__ + stack_size__) grow_semantic_stack();
   *++t__ = syn_;
}

///////////////////////////////////////////////////////////////////////////////
// Parsing method for parser class Foo
///////////////////////////////////////////////////////////////////////////////
void Foo::parse()
{
   Foo_semantic_stack_type stack__[INITIAL_STACK_SIZE_];
   t__ = bot__ = stack__;
   stack_size__ = sizeof(stack__)/sizeof(stack__[0]) - 1;
   heap_allocated__ = 0;
   parser_prefix();
   LR1ParserDriver<Foo,(LR1Parser::State)9> drv;
   drv.driver(*this);
   parser_suffix();
   if (bot__ != stack__) delete [] bot__;
}

void Foo::adjust_stack(int offset) { t__ += offset; }

void Foo::grow_semantic_stack()
{
   int N = (stack_size__ + 1) * 2;
   Foo_semantic_stack_type * S = new Foo_semantic_stack_type [N];
   if (N >= LR1Parser::SEMANTIC_STACK_SIZE) 
      error_report("Warning: semantic stack overflow");
   memcpy(S, bot__, sizeof(Foo_semantic_stack_type) * (stack_size__ + 1));
   if (heap_allocated__) delete [] bot__;
   t__ = S + (t__ - bot__);
   bot__ = S;
   stack_size__ = N - 1;
   heap_allocated__ = 1;
}

Foo::Foo ()
  : Super(Foo_base,Foo_check,Foo_def,Foo_defact,Foo_next,
          Foo_len,Foo_ncount,Foo_lhs,Foo_equiv,256,256,258)
{
}
#line 27 "T1.pcc"
#line 27 "T1.pcc"



int main()
{
   //Exp e = `?x+?y`;
}
#line 34 "T1.pcc"
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
