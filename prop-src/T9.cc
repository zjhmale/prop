///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.4),
//  last updated on Mar 31, 1997.
//  The original source file is "T9.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_REWRITING_USED
#define PROP_GARBAGE_COLLECTION_USED
#define PROP_PRINTER_USED
#define PROP_QUARK_USED
#include <propdefs.h>
#line 1 "T9.pcc"
//////////////////////////////////////////////////////////////////////////////
//  This program tests rewriting and garbage collection by using 
//  the rewriting mechanism to compute the Fibonacci number the hard way. 
//////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <AD/gc/gcobject.h>

//////////////////////////////////////////////////////////////////////////////
//  Datatype EXP denotes an expression. 
//////////////////////////////////////////////////////////////////////////////
#line 11 "T9.pcc"
#line 15 "T9.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for EXP
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_EXP_defined
#define datatype_EXP_defined
   class a_EXP;
   typedef a_EXP * EXP;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype EXP
//
///////////////////////////////////////////////////////////////////////////////
class a_EXP : public GCObject {
public:
   enum Tag_EXP {
      tag_num = 0, tag_fib = 1, tag_add = 2
   };

public:
   const Tag_EXP tag__; // variant tag
protected:
   inline a_EXP(Tag_EXP t__) : tag__(t__) {}
public:
   inline virtual ~a_EXP()
   {
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
inline int boxed(const a_EXP *) { return 1; }
inline int untag(const a_EXP * x) { return x->tag__; }
///////////////////////////////////////////////////////////////////////////////
//
//  Pretty printing methods for EXP
//
///////////////////////////////////////////////////////////////////////////////
class PrettyOStream;
extern std::ostream& operator<<(std::ostream&, EXP);
extern PrettyOStream& operator<<(PrettyOStream&, EXP);
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor EXP::num
//
///////////////////////////////////////////////////////////////////////////////
class EXP_num : public a_EXP {
public:
#line 11 "T9.pcc"
   int num; 
   inline EXP_num (int x_num)
    : a_EXP(tag_num), num(x_num)
   {
   }
   inline ~EXP_num()
   {
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
// Class for datatype constructor EXP::fib
//
///////////////////////////////////////////////////////////////////////////////
class EXP_fib : public a_EXP {
public:
#line 12 "T9.pcc"
   EXP fib; 
   inline EXP_fib (EXP x_fib)
    : a_EXP(tag_fib), fib(x_fib)
   {
   }
   inline ~EXP_fib()
   {
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
// Class for datatype constructor EXP::add
//
///////////////////////////////////////////////////////////////////////////////
class EXP_add : public a_EXP {
public:
#line 13 "T9.pcc"
   EXP _1; EXP _2; 
   inline EXP_add (EXP x_1, EXP x_2)
    : a_EXP(tag_add), _1(x_1), _2(x_2)
   {
   }
   inline ~EXP_add()
   {
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
// Datatype constructor functions for EXP
//
///////////////////////////////////////////////////////////////////////////////
inline a_EXP * num (int x_num)
{
   return new EXP_num (x_num);
}
inline a_EXP * fib (EXP x_fib)
{
   return new EXP_fib (x_fib);
}
inline a_EXP * add (EXP x_1, EXP x_2)
{
   return new EXP_add (x_1, x_2);
}
///////////////////////////////////////////////////////////////////////////////
//
// Downcasting functions for EXP
//
///////////////////////////////////////////////////////////////////////////////
inline EXP_num * _num(const a_EXP * _x_) { return (EXP_num *)_x_; }
inline EXP_fib * _fib(const a_EXP * _x_) { return (EXP_fib *)_x_; }
inline EXP_add * _add(const a_EXP * _x_) { return (EXP_add *)_x_; }

#line 15 "T9.pcc"
#line 15 "T9.pcc"


//////////////////////////////////////////////////////////////////////////////
//  Defines the interface to a rewrite class.
//  A private counter ``rewrite_count'' is encapsulated by the class
//  mechanism.
//////////////////////////////////////////////////////////////////////////////
#line 22 "T9.pcc"
#line 29 "T9.pcc"
class Fib : public BURS {
private:
   Fib(const Fib&);               // no copy constructor
   void operator = (const Fib&); // no assignment
public:
   struct Fib_StateRec * stack__, * stack_top__;
public:
   void labeler(const char *, int&, int);
   void labeler(Quark, int&, int);
          void  labeler(EXP & redex, int&, int);
   inline virtual void  operator () (EXP & redex) { int s; labeler(redex,s,0); }
private:
#line 22 "T9.pcc"
  
   int rewrites;  // number of replacements performed during rewriting
   public:
   Fib() : rewrites(0) {}
   ~Fib() {}
   
   inline int number_of_rewrites() const { return rewrites; }
#line 29 "T9.pcc"
};
#line 29 "T9.pcc"
#line 29 "T9.pcc"



//////////////////////////////////////////////////////////////////////////////
//  Specifies the rewrite rules.  We'll use rewriting to compute 
//  addition also.  The algorithm is exponential in time and generates
//  a lot of garbage in the process. 
//
//  Notice that all private data within the rewrite class is visible within
//  the rewrite rules.
//////////////////////////////////////////////////////////////////////////////
#line 40 "T9.pcc"
#line 45 "T9.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// This macro can be redefined by the user for debugging
//
///////////////////////////////////////////////////////////////////////////////
#ifndef DEBUG_Fib
#define DEBUG_Fib(repl,redex,file,line,rule) repl
#else
static const char * Fib_file_name = "T9.pcc";
#endif

static const TreeTables::Offset Fib_accept_base [ 4 ] = {
   0, 0, 1, 5
};
static const TreeTables::ShortRule Fib_accept_vector [ 7 ] = {
   -1, 0, 1, 2, -1, 3, -1
};
static const TreeTables::ShortState Fib_theta_1[2] = {
   0, 2
};


static const TreeTables::ShortState Fib_theta_2[2][2] = {
   { 0, 0 },
   { 0, 3 }
};


static const TreeTables::ShortState Fib_mu_1_0[4] = {
   0, 1, 0, 0
};


static const TreeTables::ShortState Fib_mu_2_0[4] = {
   0, 1, 0, 0
};


static const TreeTables::ShortState Fib_mu_2_1[4] = {
   0, 1, 0, 0
};


inline void  Fib::labeler(char const * redex,int& s__,int)
{
   {
s__ = 0;
   }
}

inline void  Fib::labeler(Quark redex,int& s__,int)
{
   {
s__ = 0;
   }
}

void  Fib::labeler (EXP & redex, int& s__, int r__)
{
replacement__:
   switch(redex->tag__) {
      case a_EXP::tag_num: { 
         int s0__;
         s0__ = 0; // int
         s__ = 1;} break;
      case a_EXP::tag_fib: { 
         int s0__;
         labeler(_fib(redex)->fib, s0__, r__);
         s__ = Fib_theta_1[Fib_mu_1_0[s0__]]; } break;
      default: { 
         int s0__;
         int s1__;
         labeler(_add(redex)->_1, s0__, r__);
         labeler(_add(redex)->_2, s1__, r__);
         s__ = Fib_theta_2[Fib_mu_2_0[s0__]][Fib_mu_2_1[s1__]]; } break;
   }
   const TreeTables::ShortRule * o__ = Fib_accept_vector + Fib_accept_base[s__];
accept__:
   switch (*o__) {
      case 3: {
#line 44 "T9.pcc"
         { redex = DEBUG_Fib(num((_num(_add(redex)->_1)->num + _num(_add(redex)->_2)->num)),redex,Fib_file_name,44,"add (num x, num y): ...");
           r__ = 1; goto replacement__; }
#line 45 "T9.pcc"
} break;
      case 2: {
#line 43 "T9.pcc"
         { redex = DEBUG_Fib(add(fib(num((_num(_fib(redex)->fib)->num - 1))),fib(num((_num(_fib(redex)->fib)->num - 2)))),redex,Fib_file_name,43,"fib num n: ...");
           r__ = 1; goto replacement__; }
#line 44 "T9.pcc"
} break;
      case 1: if ((_num(_fib(redex)->fib)->num == 1))
      {
#line 42 "T9.pcc"
         { redex = DEBUG_Fib(_fib(redex)->fib,redex,Fib_file_name,42,"fib x as num _ | (_num(_fib(redex)->fib)->num == 1): ...");
           r__ = 1; goto replacement__; }
#line 43 "T9.pcc"
}
      else { ++o__; goto accept__; } break;
      case 0: if ((_num(_fib(redex)->fib)->num == 0))
      {
#line 41 "T9.pcc"
         { redex = DEBUG_Fib(_fib(redex)->fib,redex,Fib_file_name,41,"fib x as num _ | (_num(_fib(redex)->fib)->num == 0): ...");
           r__ = 1; goto replacement__; }
#line 42 "T9.pcc"
}
      else { ++o__; goto accept__; } break;
   }
   
}

#line 45 "T9.pcc"
#line 45 "T9.pcc"


//////////////////////////////////////////////////////////////////////////////
//  Instantiate the datatype
//////////////////////////////////////////////////////////////////////////////
#line 50 "T9.pcc"
#line 50 "T9.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype EXP
//
///////////////////////////////////////////////////////////////////////////////
#line 50 "T9.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Pretty printing methods for EXP
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& strm__, EXP  obj__);
PrettyOStream& operator << (PrettyOStream& strm__, EXP  obj__);

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype EXP
//
///////////////////////////////////////////////////////////////////////////////
#line 50 "T9.pcc"
void a_EXP::trace(GC * gc__)
{
}

///////////////////////////////////////////////////////////////////////////////
//
// Pretty printing methods for EXP
//
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator << (std::ostream& strm__, EXP  obj__)
{  PrettyOStream S(strm__); S << obj__; return strm__; }

PrettyOStream& operator << (PrettyOStream& strm__, EXP  obj__)
{
   switch (untag(obj__))
   {
      case 0: 
         strm__ << _num(obj__)->num; // int
         break;
      case 1: 
         strm__ << "fib ";
         strm__ << _fib(obj__)->fib; // EXP
         break;
      case 2: 
         strm__ << '(';
         strm__ << _add(obj__)->_1; // EXP
         strm__ << '+';
         strm__ << _add(obj__)->_2; // EXP
         strm__ << ')';
         break;
   }
   return strm__;
}

void EXP_num::trace(GC * gc__)
{
   // call to method a_EXP::trace() has been optimized out
   // omitted int
}

void EXP_fib::trace(GC * gc__)
{
   // call to method a_EXP::trace() has been optimized out
   this->fib = (EXP )gc__->trace(this->fib); // EXP
}

void EXP_add::trace(GC * gc__)
{
   // call to method a_EXP::trace() has been optimized out
   this->_1 = (EXP )gc__->trace(this->_1); // EXP
   this->_2 = (EXP )gc__->trace(this->_2); // EXP
}



#line 50 "T9.pcc"
#line 50 "T9.pcc"


//////////////////////////////////////////////////////////////////////////////
//  Input a number and test the rewrite rules.
//////////////////////////////////////////////////////////////////////////////
int main()
{  
   ///////////////////////////////////////////////////////////////////////////
   //  Give ourselves some more memory (2Meg) to work with.
   //  The default heap size is only 128K.   Using a larger heap
   //  can drastically cut down the overhead of GC since almost all
   //  intermediate terms generated can be reclaimed.  With the copying 
   //  garbage collecting scheme that we are using, the overhead of GC
   //  is proportional to the amount of live data, not the total heap size.
   ///////////////////////////////////////////////////////////////////////////
   GC::get_default_gc().set_initial_heap_size(2*1024*1024);

   int n;
   cout << "This simple benchmark tests the efficiency of rewriting\n"
           "by computing the Fibonacci numbers with a naive, exponential\n"
           "algorithm.  The goal is to stress the pattern matching and\n"
           "term replacement facilities.\n" 
           "Please input a small non-negative number(0-25): " << flush;
   cin >> n;
   Fib F;
   EXP x = fib(num(n));
   F(x);
   cout << "fib(" << n << ") = " << x << '\n'; 
   cout << "Number of replacements = " << F.number_of_rewrites() << '\n';
   return 0;
}
#line 81 "T9.pcc"
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
