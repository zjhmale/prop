///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.6),
//  last updated on Nov 2, 1999.
//  The original source file is "listimpl.ph".
///////////////////////////////////////////////////////////////////////////////

#line 1 "listimpl.ph"
#ifndef list_operations_implementations_h
#define list_operations_himplementations_

#include "basics.h"

//#pragma interface

template <class T>
   int length (
#line 9 "listimpl.ph"
a_List<T> *  
#line 9 "listimpl.ph"
 l)
   {  int len = 0;
      
#line 12 "listimpl.ph"
{
   for (;;) {
      if (l) {
#line 12 "listimpl.ph"
        l = l->_2; len++; 
#line 12 "listimpl.ph"
      } else { goto L1; }
   }
   L1:;
}
#line 13 "listimpl.ph"
#line 13 "listimpl.ph"

      return len;
   }

template <class T>
   
#line 18 "listimpl.ph"
a_List<T> *  
#line 18 "listimpl.ph"
 append (a_List<T> *  
#line 18 "listimpl.ph"
 a, a_List<T> *  
#line 18 "listimpl.ph"
 b)
   {  
#line 21 "listimpl.ph"
{
   if (a) {
#line 21 "listimpl.ph"
     return 
#line 21 "listimpl.ph"
#line 21 "listimpl.ph"
      list_1_(a->_1,append(a->_2,b))
#line 21 "listimpl.ph"
#line 21 "listimpl.ph"
      ; 
#line 21 "listimpl.ph"
   } else {
#line 20 "listimpl.ph"
     return b; 
#line 20 "listimpl.ph"
   }
}
#line 22 "listimpl.ph"
#line 22 "listimpl.ph"

   }

template <class T>
   
#line 26 "listimpl.ph"
a_List<T> *  
#line 26 "listimpl.ph"
 rev (a_List<T> *  
#line 26 "listimpl.ph"
 a)
   {  a_List<T> *  
#line 27 "listimpl.ph"
 b = 
#line 27 "listimpl.ph"
nil_1_
#line 27 "listimpl.ph"
#line 27 "listimpl.ph"
;
      
#line 28 "listimpl.ph"
#line 29 "listimpl.ph"
{
   for (;;) {
      if (a) {
#line 29 "listimpl.ph"
        b = 
#line 29 "listimpl.ph"
#line 29 "listimpl.ph"
         list_1_(a->_1,b)
#line 29 "listimpl.ph"
#line 29 "listimpl.ph"
         ; a = a->_2; 
#line 29 "listimpl.ph"
      } else { goto L2; }
   }
   L2:;
}
#line 30 "listimpl.ph"
#line 30 "listimpl.ph"
 
      return b;
   } 


#endif
#line 36 "listimpl.ph"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 2
Number of ifs generated      = 3
Number of switches generated = 0
Number of labels             = 0
Number of gotos              = 0
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
