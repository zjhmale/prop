///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.4),
//  last updated on Apr 3, 1997.
//  The original source file is "T10.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_GARBAGE_COLLECTION_USED
#include <propdefs.h>
#line 1 "T10.pcc"
#include <iostream>

struct IA { void hasIA() {} };
struct IB { void hasIB() {} };
struct IC { void hasIC() {} };
struct ID { void hasID() {} };
struct IE { void hasIE() {} };
struct I1 { void hasI1() {} };
struct I2 { void hasI2() {} };
struct I3 { void hasI3() {} };


#line 13 "T10.pcc"
#line 20 "T10.pcc"
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

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype T
//
///////////////////////////////////////////////////////////////////////////////
class a_T : public GCObject, public I1 {
public:
   enum Tag_T {
      tag_A = 0, tag_B = 1, tag_C = 2, 
      tag_D = 3
   };

public:
   const Tag_T tag__; // variant tag
protected:
   inline a_T(Tag_T t__) : tag__(t__) {}
public:
   inline virtual ~a_T()
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
#line 18 "T10.pcc"
   
   void test_T() {}
#line 20 "T10.pcc"
#line 29 "T10.pcc"
  virtual std::ostream& print(std::ostream&) = 0;
#line 29 "T10.pcc"
};
inline int boxed(const a_T *) { return 1; }
inline int untag(const a_T * x) { return x->tag__; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor T::A
//
///////////////////////////////////////////////////////////////////////////////
class T_A : public a_T, public IA, public I2 {
public:
#line 13 "T10.pcc"
   
   inline T_A ()
    : a_T(tag_A)
   {
   }
   inline ~T_A()
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
#line 13 "T10.pcc"
  void get_A(); 
#line 13 "T10.pcc"
#line 30 "T10.pcc"
  std::ostream& print(std::ostream&);
#line 30 "T10.pcc"
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor T::B
//
///////////////////////////////////////////////////////////////////////////////
class T_B : public a_T, public IB, public I2 {
public:
#line 13 "T10.pcc"
   
   inline T_B ()
    : a_T(tag_B)
   {
   }
   inline ~T_B()
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
#line 14 "T10.pcc"
  void get_B(); 
#line 14 "T10.pcc"
#line 30 "T10.pcc"
  std::ostream& print(std::ostream&);
#line 30 "T10.pcc"
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor T::C
//
///////////////////////////////////////////////////////////////////////////////
class T_C : public a_T, public IC, public I2 {
public:
#line 14 "T10.pcc"
   
   inline T_C ()
    : a_T(tag_C)
   {
   }
   inline ~T_C()
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
#line 15 "T10.pcc"
  void get_C(); 
#line 15 "T10.pcc"
#line 30 "T10.pcc"
  std::ostream& print(std::ostream&);
#line 30 "T10.pcc"
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor T::D
//
///////////////////////////////////////////////////////////////////////////////
class T_D : public a_T, public ID, public I2 {
public:
#line 15 "T10.pcc"
   
   inline T_D ()
    : a_T(tag_D)
   {
   }
   inline ~T_D()
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
#line 16 "T10.pcc"
  void get_D(); 
#line 16 "T10.pcc"
#line 30 "T10.pcc"
  std::ostream& print(std::ostream&);
#line 30 "T10.pcc"
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for T
//
///////////////////////////////////////////////////////////////////////////////
inline a_T * A ()
{
   return new T_A ;
}
inline a_T * B ()
{
   return new T_B ;
}
inline a_T * C ()
{
   return new T_C ;
}
inline a_T * D ()
{
   return new T_D ;
}
///////////////////////////////////////////////////////////////////////////////
//
// Downcasting functions for T
//
///////////////////////////////////////////////////////////////////////////////
inline T_A * _A(const a_T * _x_) { return (T_A *)_x_; }
inline T_B * _B(const a_T * _x_) { return (T_B *)_x_; }
inline T_C * _C(const a_T * _x_) { return (T_C *)_x_; }
inline T_D * _D(const a_T * _x_) { return (T_D *)_x_; }

#line 20 "T10.pcc"
#line 20 "T10.pcc"


#line 22 "T10.pcc"
#line 26 "T10.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for T2
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_T2_defined
#define datatype_T2_defined
   class a_T2;
   typedef a_T2 * T2;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor T2::E
//
///////////////////////////////////////////////////////////////////////////////
class a_T2 : public GCObject, public IE, public I3 {
public:
#line 22 "T10.pcc"
   
   inline a_T2 ()
   
   {
   }
   inline virtual ~a_T2()
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
#line 24 "T10.pcc"
   
   void test_T2() {}
#line 26 "T10.pcc"
#line 22 "T10.pcc"
  void get_E(); 
#line 22 "T10.pcc"
#line 31 "T10.pcc"
  virtual std::ostream& print(std::ostream&);
#line 31 "T10.pcc"
};
inline int boxed(const a_T2 *) { return 1; }
inline int untag(const a_T2 *) { return 0; }
///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for T2
//
///////////////////////////////////////////////////////////////////////////////
inline a_T2 * E ()
{
   return new a_T2 ;
}
///////////////////////////////////////////////////////////////////////////////
//
// Downcasting functions for T2
//
///////////////////////////////////////////////////////////////////////////////


#line 27 "T10.pcc"
#line 27 "T10.pcc"


#line 29 "T10.pcc"
#line 31 "T10.pcc"


#line 34 "T10.pcc"
#line 34 "T10.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype T
//
///////////////////////////////////////////////////////////////////////////////
#line 34 "T10.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype T2
//
///////////////////////////////////////////////////////////////////////////////
#line 34 "T10.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype T
//
///////////////////////////////////////////////////////////////////////////////
#line 34 "T10.pcc"
void a_T::trace(GC * gc__)
{
}

void T_A::trace(GC * gc__)
{
   // call to method a_T::trace() has been optimized out
}

void T_B::trace(GC * gc__)
{
   // call to method a_T::trace() has been optimized out
}

void T_C::trace(GC * gc__)
{
   // call to method a_T::trace() has been optimized out
}

void T_D::trace(GC * gc__)
{
   // call to method a_T::trace() has been optimized out
}



///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype T2
//
///////////////////////////////////////////////////////////////////////////////
#line 34 "T10.pcc"
void a_T2::trace(GC * gc__)
{
}



#line 34 "T10.pcc"
#line 34 "T10.pcc"


void 
#line 36 "T10.pcc"
T_A
#line 36 "T10.pcc"
::get_A() { hasIA(); hasI1(); hasI2(); }
void 
#line 37 "T10.pcc"
T_B
#line 37 "T10.pcc"
::get_B() { hasIB(); hasI1(); hasI2(); }
void 
#line 38 "T10.pcc"
T_C
#line 38 "T10.pcc"
::get_C() { hasIC(); hasI1(); hasI2(); }
void 
#line 39 "T10.pcc"
T_D
#line 39 "T10.pcc"
::get_D() { hasID(); hasI1(); hasI2(); }
void 
#line 40 "T10.pcc"
a_T2
#line 40 "T10.pcc"
::get_E() { hasIE(); hasI3(); }

std::ostream&
#line 42 "T10.pcc"
T_A
#line 42 "T10.pcc"
::print(std::ostream& s) { return s << "A"; }
std::ostream&
#line 43 "T10.pcc"
T_B
#line 43 "T10.pcc"
::print(std::ostream& s) { return s << "B"; }
std::ostream&
#line 44 "T10.pcc"
T_C
#line 44 "T10.pcc"
::print(std::ostream& s) { return s << "C"; }
std::ostream&
#line 45 "T10.pcc"
T_D
#line 45 "T10.pcc"
::print(std::ostream& s) { return s << "D"; }
std::ostream&
#line 46 "T10.pcc"
a_T2
#line 46 "T10.pcc"
::print(std::ostream& s) { return s << "E"; }

int main()
{  T x = A();
   x->test_T();
   x->print(cout) << '\n';
   T2 y = E();
   y->test_T2();
   y->print(cout) << '\n';
   return 0;
}
#line 57 "T10.pcc"
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
