///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.6),
//  last updated on Nov 2, 1999.
//  The original source file is "timespace.ph".
///////////////////////////////////////////////////////////////////////////////

#line 1 "timespace.ph"
///////////////////////////////////////////////////////////////////////////////
//
//  This file describes the structure of the time and space complexity
//  datatypes.  These datatypes are used to represent time and space
//  complexity in the SETL-like extension language. 
//
///////////////////////////////////////////////////////////////////////////////
#ifndef time_and_space_complexity_h
#define time_and_space_complexity_h

#include "basics.h"
#include <iostream>

///////////////////////////////////////////////////////////////////////////////
//
//  Complexity expression is represented by the datatype Complexity.
//
///////////////////////////////////////////////////////////////////////////////
#line 25 "timespace.ph"
#line 50 "timespace.ph"
///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Complexity
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Complexity_defined
#define datatype_Complexity_defined
   class a_Complexity;
   typedef a_Complexity * Complexity;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Time
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Time_defined
#define datatype_Time_defined
   class a_Time;
   typedef a_Time * Time;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Forward class definition for Space
//
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Space_defined
#define datatype_Space_defined
   class a_Space;
   typedef a_Space * Space;
#endif

///////////////////////////////////////////////////////////////////////////////
//
// Base class for datatype Complexity
//
///////////////////////////////////////////////////////////////////////////////
class a_Complexity : public MEM {
public:
   enum Tag_Complexity {
      tag_Var = 0, tag_Add = 1, tag_Mul = 2, 
      tag_Div = 3, tag_Power = 4, tag_Log = 5, 
      tag_Const = 6, tag_BigOh = 7, tag_Omega = 8, 
      tag_LittleOh = 9
   };

public:
   const Tag_Complexity tag__; // variant tag
protected:
   inline a_Complexity(Tag_Complexity t__) : tag__(t__) {}
public:
};
inline int boxed(const a_Complexity *) { return 1; }
inline int untag(const a_Complexity * x) { return x->tag__; }
///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Complexity::Var
//
///////////////////////////////////////////////////////////////////////////////
class Complexity_Var : public a_Complexity {
public:
#line 25 "timespace.ph"
   Id Var; 
   Complexity_Var (Id x_Var);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Complexity::Add
//
///////////////////////////////////////////////////////////////////////////////
class Complexity_Add : public a_Complexity {
public:
#line 27 "timespace.ph"
   Complexity _1; Complexity _2; 
   Complexity_Add (Complexity x_1, Complexity x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Complexity::Mul
//
///////////////////////////////////////////////////////////////////////////////
class Complexity_Mul : public a_Complexity {
public:
#line 28 "timespace.ph"
   Complexity _1; Complexity _2; 
   Complexity_Mul (Complexity x_1, Complexity x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Complexity::Div
//
///////////////////////////////////////////////////////////////////////////////
class Complexity_Div : public a_Complexity {
public:
#line 29 "timespace.ph"
   Complexity _1; Complexity _2; 
   Complexity_Div (Complexity x_1, Complexity x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Complexity::Power
//
///////////////////////////////////////////////////////////////////////////////
class Complexity_Power : public a_Complexity {
public:
#line 30 "timespace.ph"
   Complexity _1; Complexity _2; 
   Complexity_Power (Complexity x_1, Complexity x_2);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Complexity::Log
//
///////////////////////////////////////////////////////////////////////////////
class Complexity_Log : public a_Complexity {
public:
#line 31 "timespace.ph"
   Complexity Log; 
   Complexity_Log (Complexity x_Log);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Complexity::Const
//
///////////////////////////////////////////////////////////////////////////////
class Complexity_Const : public a_Complexity {
public:
#line 32 "timespace.ph"
   double Const; 
   Complexity_Const (double x_Const);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Complexity::BigOh
//
///////////////////////////////////////////////////////////////////////////////
class Complexity_BigOh : public a_Complexity {
public:
#line 33 "timespace.ph"
   Complexity BigOh; 
   Complexity_BigOh (Complexity x_BigOh);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Complexity::Omega
//
///////////////////////////////////////////////////////////////////////////////
class Complexity_Omega : public a_Complexity {
public:
#line 34 "timespace.ph"
   Complexity Omega; 
   Complexity_Omega (Complexity x_Omega);
};

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Complexity::LittleOh
//
///////////////////////////////////////////////////////////////////////////////
class Complexity_LittleOh : public a_Complexity {
public:
#line 35 "timespace.ph"
   Complexity LittleOh; 
   Complexity_LittleOh (Complexity x_LittleOh);
};

///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for Complexity
//
///////////////////////////////////////////////////////////////////////////////
extern a_Complexity * Var (Id x_Var);
extern a_Complexity * Add (Complexity x_1, Complexity x_2);
extern a_Complexity * Mul (Complexity x_1, Complexity x_2);
extern a_Complexity * Div (Complexity x_1, Complexity x_2);
extern a_Complexity * Power (Complexity x_1, Complexity x_2);
extern a_Complexity * Log (Complexity x_Log);
extern a_Complexity * Const (double x_Const);
extern a_Complexity * BigOh (Complexity x_BigOh);
extern a_Complexity * Omega (Complexity x_Omega);
extern a_Complexity * LittleOh (Complexity x_LittleOh);

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Time::TIME
//
///////////////////////////////////////////////////////////////////////////////
class a_Time : public MEM {
public:
#line 42 "timespace.ph"
   Complexity TIME; 
   a_Time (Complexity x_TIME);
};
inline int boxed(const a_Time *) { return 1; }
inline int untag(const a_Time *) { return 0; }
///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for Time
//
///////////////////////////////////////////////////////////////////////////////
extern a_Time * TIME (Complexity x_TIME);

///////////////////////////////////////////////////////////////////////////////
//
// Class for datatype constructor Space::SPACE
//
///////////////////////////////////////////////////////////////////////////////
class a_Space : public MEM {
public:
#line 49 "timespace.ph"
   Complexity SPACE; 
   a_Space (Complexity x_SPACE);
};
inline int boxed(const a_Space *) { return 1; }
inline int untag(const a_Space *) { return 0; }
///////////////////////////////////////////////////////////////////////////////
//
// Datatype constructor functions for Space
//
///////////////////////////////////////////////////////////////////////////////
extern a_Space * SPACE (Complexity x_SPACE);

#line 50 "timespace.ph"
#line 50 "timespace.ph"


///////////////////////////////////////////////////////////////////////////////
//
//  Pretty printing routines.
//
///////////////////////////////////////////////////////////////////////////////
extern std::ostream& operator << (std::ostream&, Complexity);
extern std::ostream& operator << (std::ostream&, Time);
extern std::ostream& operator << (std::ostream&, Space);

///////////////////////////////////////////////////////////////////////////////
//
//  Functions to simplify and manipulate complexity expressions.
//
///////////////////////////////////////////////////////////////////////////////
extern Complexity simplify (Complexity);

#endif
#line 69 "timespace.ph"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 0
Number of ifs generated      = 0
Number of switches generated = 0
Number of labels             = 0
Number of gotos              = 0
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
