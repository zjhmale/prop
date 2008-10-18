//////////////////////////////////////////////////////////////////////////////
// NOTICE:
//
// ADLib, Prop and their related set of tools and documentation are in the 
// public domain.   The author(s) of this software reserve no copyrights on 
// the source code and any code generated using the tools.  You are encouraged
// to use ADLib and Prop to develop software, in both academic and commercial
// settings, and are free to incorporate any part of ADLib and Prop into
// your programs.
//
// Although you are under no obligation to do so, we strongly recommend that 
// you give away all software developed using our tools.
//
// We also ask that credit be given to us when ADLib and/or Prop are used in 
// your programs, and that this notice be preserved intact in all the source 
// code.
//
// This software is still under development and we welcome any suggestions 
// and help from the users.
//
// Allen Leung 
// 1994
//////////////////////////////////////////////////////////////////////////////

#ifndef set_h
#define set_h

/////////////////////////////////////////////////////////////////////////////
//  Class Set<T> implements a set of T.
/////////////////////////////////////////////////////////////////////////////

#include <AD/contain/col.h>

/////////////////////////////////////////////////////////////////////////////
//  Class Set<T> is an abstract class
/////////////////////////////////////////////////////////////////////////////
template<class T>
   class Set : public Collection<T> { 
   public:
      ///////////////////////////////////////////////////////////////////////
      //  Inherit types
      ///////////////////////////////////////////////////////////////////////
      typedef Collection<T>  Super;
      typedef Super::Element Element; 

      ///////////////////////////////////////////////////////////////////////
      //  Constructors and destructor
      ///////////////////////////////////////////////////////////////////////
      Set() {} 
     ~Set() {} 

      ///////////////////////////////////////////////////////////////////////
      //  Assignment 
      ///////////////////////////////////////////////////////////////////////
      // virtual void operator = (const Collection<T>&); // inherited

      ///////////////////////////////////////////////////////////////////////
      //  Selectors
      ///////////////////////////////////////////////////////////////////////
      // virtual int  size()     const;            // inherited
      // virtual int  capacity() const;            // inherited
      // virtual Bool is_empty() const;            // inherited
      // virtual Bool is_full()  const;            // inherited
      // virtual Bool contains (const T& e) const; // inherited

      ///////////////////////////////////////////////////////////////////////
      //  In place set operations
      ///////////////////////////////////////////////////////////////////////
      // virtual void clear  ();                   // inherited
      // virtual void insert (const T& e);         // inherited
      // virtual void remove (const T& e);         // inherited
      Set& Union        (const Set& s);
      Set& Difference   (const Set& s);
      Set& Intersection (const Set& s);

      ///////////////////////////////////////////////////////////////////////
      //  Iteration
      ///////////////////////////////////////////////////////////////////////
      // virtual Ix       first()            const;  // inherited
      // virtual Ix       next(Ix i)         const;  // inherited
      // virtual const T& operator () (Ix i) const;  // inherited
      // virtual       T& operator () (Ix i);        // inherited
   };

///////////////////////////////////////////////////////////////////////
//  The following are the default implementation of set operations
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
//  In place union with a set
///////////////////////////////////////////////////////////////////////
template <class T>
   Set<T>& Set<T>::Union (const Set<T>& s)
   {  for (Ix i = s.first(); i; s.next(i)) this->insert(s(i)); 
      return *this;
   }

///////////////////////////////////////////////////////////////////////
//  In place difference with a set
///////////////////////////////////////////////////////////////////////
template <class T>
   Set<T>& Set<T>::Difference (const Set<T>& s)
   {  for (Ix i = s.first(); i; i = s.next(i)) this->remove(s(i)); 
      return *this;
   }

///////////////////////////////////////////////////////////////////////
//  In place intersection with a set
///////////////////////////////////////////////////////////////////////
template <class T>
   Set<T>& Set<T>::Intersection (const Set<T>& s)
   {  for (Ix i = this->first(); i; this->next(i)) 
         if (! s.contains((*this)(i))) this->remove((*this)(i));
      return *this;
   }  

#endif
