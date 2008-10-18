#ifndef boolean_unification_h
#define boolean_unification_h

#include <AD/generic/generic.h>

///////////////////////////////////////////////////////////////////////////////
//  Boolean unification (on a boolean ring) algorithms.
///////////////////////////////////////////////////////////////////////////////
class BooleanUnification {
   BooleanUnification(const BooleanUnification&);  // no copy constructor
   void operator = (const BooleanUnification&);    // no assignment
public:
   ////////////////////////////////////////////////////////////////////////////
   //  Constructor and destructor
   ////////////////////////////////////////////////////////////////////////////
            BooleanUnification();
   virtual ~BooleanUnification();

};

#endif
