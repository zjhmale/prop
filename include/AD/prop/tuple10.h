#ifndef prop_tuple10_h
#define prop_tuple10_h

template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10>
   class Tuple10 {
   public:
      T1 _1;
      T2 _2;
      T3 _3;
      T4 _4;
      T5 _5;
      T6 _6;
      T7 _7;
      T8 _8;
      T9 _9;
      T10 _10;

      inline Tuple10() {}
      inline Tuple10(   
         const T1& x1,
         const T2& x2,
         const T3& x3,
         const T4& x4,
         const T5& x5,
         const T6& x6,
         const T7& x7,
         const T8& x8,
         const T9& x9,
         const T10& x10
      ) : 
         _1(x1),
         _2(x2),
         _3(x3),
         _4(x4),
         _5(x5),
         _6(x6),
         _7(x7),
         _8(x8),
         _9(x9),
         _10(x10) 
      {}
   };

template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10>
   inline Tuple10<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> mkTuple10(
         const T1& x1,
         const T2& x2,
         const T3& x3,
         const T4& x4,
         const T5& x5,
         const T6& x6,
         const T7& x7,
         const T8& x8,
         const T9& x9,
         const T10& x10
      ) 
   { return Tuple10<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10); }

#endif
