///////////////////////////////////////////////////////////////////////////////
//
//  This file describes the structure of the time and space complexity
//  datatypes.  These datatypes are used to represent time and space
//  complexity in the SETL-like extension language. 
//
///////////////////////////////////////////////////////////////////////////////
#ifndef time_and_space_complexity_h
#define time_and_space_complexity_h

#include "basics.ph"

///////////////////////////////////////////////////////////////////////////////
//
//  Forward type declaration
//
///////////////////////////////////////////////////////////////////////////////
class ostream;

///////////////////////////////////////////////////////////////////////////////
//
//  Complexity expression is represented by the datatype Complexity.
//
///////////////////////////////////////////////////////////////////////////////
datatype Complexity : MEM =
     Var      Id                           // variable
   | Add      (Complexity, Complexity)     // f(x) + g(x)
   | Mul      (Complexity, Complexity)     // f(x) * g(x)
   | Div      (Complexity, Complexity)     // f(x) / g(x)
   | Power    (Complexity, Complexity)     // f(x) ^ g(x)
   | Log      (Complexity)                 // log f(x)
   | Const    (double)                     // constant
   | BigOh    Complexity                   // O(f(x))
   | Omega    Complexity                   // Omega(f(x))
   | LittleOh Complexity                   // o(f(x))

///////////////////////////////////////////////////////////////////////////////
//
//  Time complexity is represented by the datatype Time.
//
///////////////////////////////////////////////////////////////////////////////
and      Time  : MEM = TIME Complexity

///////////////////////////////////////////////////////////////////////////////
//
//  Similarly, space complexity is represented by the datatype Space.
//
///////////////////////////////////////////////////////////////////////////////
and      Space : MEM = SPACE Complexity
;

///////////////////////////////////////////////////////////////////////////////
//
//  Pretty printing routines.
//
///////////////////////////////////////////////////////////////////////////////
extern ostream& operator << (ostream&, Complexity);
extern ostream& operator << (ostream&, Time);
extern ostream& operator << (ostream&, Space);

///////////////////////////////////////////////////////////////////////////////
//
//  Functions to simplify and manipulate complexity expressions.
//
///////////////////////////////////////////////////////////////////////////////
extern Complexity simplify (Complexity);

#endif
