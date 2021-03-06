#ifndef prop_tuple5_h
#define prop_tuple5_h

template <class T1, class T2, class T3, class T4, class T5>
   class Tuple5 {
   public:
      T1 _1;
      T2 _2;
      T3 _3;
      T4 _4;
      T5 _5;

      inline Tuple5() {}
      inline Tuple5(   
         const T1& x1,
         const T2& x2,
         const T3& x3,
         const T4& x4,
         const T5& x5
      ) : 
         _1(x1),
         _2(x2),
         _3(x3),
         _4(x4),
         _5(x5) 
      {}
   };

template <class T1, class T2, class T3, class T4, class T5>
   inline Tuple5<T1, T2, T3, T4, T5> mkTuple5(
         const T1& x1,
         const T2& x2,
         const T3& x3,
         const T4& x4,
         const T5& x5
      ) 
   { return Tuple5<T1, T2, T3, T4, T5>(x1, x2, x3, x4, x5); }

#endif
