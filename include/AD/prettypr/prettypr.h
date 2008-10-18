//////////////////////////////////////////////////////////////////////////////
// NOTICE:
//
// ADLib, Prop and their related set of tools and documentation are in the 
// public domain.   The author(s) of this software reserve no copyrights on 
// the source code and any code generated using the tools.  You are encouraged
// to use ADLib and Prop to develop software, in both academic and commercial
// settings, and are welcomed to incorporate any part of ADLib and Prop into
// your programs.
//
// Although you are under no obligation to do so, we strongly recommend that 
// you give away all software developed using our tools.
//
// We also ask that credit be given to us when ADLib and/or Prop are used in 
// your programs, and that this notice be preserved intact in all the source 
// code.
//
// This software is still under development and we welcome(read crave for)
// any suggestions and help from the users.
//
// Allen Leung (leunga@cs.nyu.edu)
// 1994-1995
//////////////////////////////////////////////////////////////////////////////

#ifndef Prop_pretty_printer_h
#define Prop_pretty_printer_h

#include <iostream.h>

inline ostream& pretty_print(ostream& f, char x, int = 0, int = 0)           { return f << x; }
inline ostream& pretty_print(ostream& f, unsigned char x, int = 0, int = 0)  { return f << x; }
inline ostream& pretty_print(ostream& f, short x, int = 0, int = 0)          { return f << x; }
inline ostream& pretty_print(ostream& f, unsigned short x, int = 0, int = 0) { return f << x; }
inline ostream& pretty_print(ostream& f, int x, int = 0, int = 0)            { return f << x; }
inline ostream& pretty_print(ostream& f, unsigned int x, int = 0, int = 0)   { return f << x; }
inline ostream& pretty_print(ostream& f, long x, int = 0, int = 0)           { return f << x; }
inline ostream& pretty_print(ostream& f, unsigned long x, int = 0, int = 0)  { return f << x; }
inline ostream& pretty_print(ostream& f, float x, int = 0, int = 0)          { return f << x; }
inline ostream& pretty_print(ostream& f, double x, int = 0, int = 0)         { return f << x; }
inline ostream& pretty_print(ostream& f, const char * x, int = 0, int = 0)   { return f << x; }
inline ostream& pretty_print(ostream& f, const unsigned char * x, int = 0, int = 0) { return f << (const char *)x; }
//inline ostream& pretty_print(ostream& f, const void * x, int = 0, int = 0)   { return f << x; }

class PrettyPrinter {
   PrettyPrinter(const PrettyPrinter&);
   void operator = (const PrettyPrinter&);
public:
            PrettyPrinter();
   virtual ~PrettyPrinter();

   static ostream& print_tabs(ostream&, int);
};

#endif
