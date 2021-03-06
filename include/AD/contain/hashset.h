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

#ifndef hash_table_based_set_h
#define hash_table_based_set_h

/////////////////////////////////////////////////////////////////////////////
//  Class MapSet<T> implements a set derived from a hash table
/////////////////////////////////////////////////////////////////////////////

#include <AD/contain/set.h>  // Sets

/////////////////////////////////////////////////////////////////////////////
//  Class HashSet<T>
/////////////////////////////////////////////////////////////////////////////
template<class T, class H>
   class HashSet : public Set<T> {

      H set;

   public:
      ///////////////////////////////////////////////////////////////////////
      //  Inherit types
      ///////////////////////////////////////////////////////////////////////
      typedef Set<T>         Super;
      typedef typename Super::Element Element;

      ///////////////////////////////////////////////////////////////////////
      //  Constructors and destructor
      ///////////////////////////////////////////////////////////////////////
      HashSet(int size = Collection_default_size) : set(size) {}
      HashSet(const Collection<T>& C) : set(C.size()) { *this = C; }
      HashSet(const HashSet<T,H>& s) : set(s.set) {}
     ~HashSet() {}

      ///////////////////////////////////////////////////////////////////////
      // Assignment
      ///////////////////////////////////////////////////////////////////////
      // void operator = (const Collection<T>&); // inherited
      void operator = (const HashSet<T,H>& S) { *this = (Collection<T>&)S; }

      ///////////////////////////////////////////////////////////////////////
      //  Selectors
      ///////////////////////////////////////////////////////////////////////
      inline int  size()     const            { return set.size(); }
      inline int  capacity() const            { return set.capacity(); }
      inline Bool is_empty() const            { return set.is_empty(); }
      inline Bool is_full()  const            { return set.is_full(); }
      inline Bool contains (const T& e) const { return set.contains(e); }
      inline Ix   lookup   (const T& e) const { return set.lookup(e); }

      ///////////////////////////////////////////////////////////////////////
      //  In place set operations
      ///////////////////////////////////////////////////////////////////////
      inline void clear()             { set.clear(); }             // make
      inline Ix   insert (const T& e) { return set.insert(e,0); }  // add an element
      inline Bool remove (const T& e) { return set.remove(e); }    // remove an element
      // void Union        (const Set& s);  // inherited
      // void Difference   (const Set& s);  // inherited
      // void Intersection (const Set& s);  // inherited

      ///////////////////////////////////////////////////////////////////////
      //  Iteration
      ///////////////////////////////////////////////////////////////////////
      inline Ix       first()            const { return set.first(); }
      inline Ix       next(Ix i)         const { return set.next(i); }
      inline const T& operator () (Ix i) const { return (T&)set.key(i); }
      inline       T& operator () (Ix i)       { return (T&)set.key(i); }

      ///////////////////////////////////////////////////////////////////////
      // Class name
      ///////////////////////////////////////////////////////////////////////
      const char * myName() const { return "HashSet"; }
   };

#endif
