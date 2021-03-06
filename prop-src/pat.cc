///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.6),
//  last updated on Nov 2, 1999.
//  The original source file is "pat.pcc".
///////////////////////////////////////////////////////////////////////////////

#line 1 "pat.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements the analysis routines for patterns and match
//  decision trees.  These are used for mode analysis and determinism
//  analysis for logic clauses compilation.
//
///////////////////////////////////////////////////////////////////////////////
#include "ir.h"
#include "matchcom.h"
#include "pat.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Convert a pattern into an unifier if the constructor is part of
//  an unifiable type.
//
///////////////////////////////////////////////////////////////////////////////
Pat mkunifier (Cons cons, Pat pat, Pat transformed_pat)
{  
#line 19 "pat.pcc"
#line 31 "pat.pcc"
{
   if (cons) {
      if (cons->alg_ty) {
         switch (cons->alg_ty->tag__) {
            case a_Ty::tag_TYCONty: {
               if (boxed(((Ty_TYCONty *)cons->alg_ty)->_1)) {
                  switch (((Ty_TYCONty *)cons->alg_ty)->_1->tag__) {
                     case a_TyCon::tag_DATATYPEtycon: {
                        if (
#line 21 "pat.pcc"
                        (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)cons->alg_ty)->_1)->qualifiers & QUALunifiable)
#line 21 "pat.pcc"
) {
                           
#line 22 "pat.pcc"
                         Cons unifier_cons = ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)cons->alg_ty)->_1)->terms[((TyCon_DATATYPEtycon *)((Ty_TYCONty *)cons->alg_ty)->_1)->unit];
                           Bool mode_save = write_mode;
                           write_mode = true;
                           Pat new_p = LOGICALpat(ORpat,transformed_pat,
                                          UNIFYpat(APPpat(CONSpat(unifier_cons),WILDpat()),
                                                   pat2unifier(pat)));
                           write_mode = mode_save;
                           return new_p;
                           
#line 30 "pat.pcc"
                        } else {
                           
                           L1:; 
#line 31 "pat.pcc"
                          return pat; 
#line 31 "pat.pcc"
                        }
                        } break;
                     default: { goto L1; } break;
                  }
               } else { goto L1; }
               } break;
            default: { goto L1; } break;
         }
      } else { goto L1; }
   } else { goto L1; }
}
#line 32 "pat.pcc"
#line 32 "pat.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Convert a simple pattern into an unifier.
//
///////////////////////////////////////////////////////////////////////////////
Pat unifier_of (Pat pat)
{  Pat new_p = pat;
   
#line 42 "pat.pcc"
#line 72 "pat.pcc"
{
   if (pat) {
      switch (pat->tag__) {
         case a_Pat::tag_CONSpat: {
#line 45 "pat.pcc"
           new_p = mkunifier(((Pat_CONSpat *)pat)->CONSpat,pat,pat); 
#line 45 "pat.pcc"
            } break;
         case a_Pat::tag_APPpat: {
            if (((Pat_APPpat *)pat)->_1) {
               switch (((Pat_APPpat *)pat)->_1->tag__) {
                  case a_Pat::tag_CONSpat: {
#line 47 "pat.pcc"
                    new_p = mkunifier(((Pat_CONSpat *)((Pat_APPpat *)pat)->_1)->CONSpat,pat,APPpat(((Pat_APPpat *)pat)->_1,unifier_of(((Pat_APPpat *)pat)->_2))); 
#line 47 "pat.pcc"
                     } break;
                  default: {
                     L2:; 
#line 72 "pat.pcc"
                    bug ("%Lunsupported unifier: %p", pat); 
#line 72 "pat.pcc"
                     } break;
               }
            } else { goto L2; }
            } break;
         case a_Pat::tag_TYPEDpat: {
#line 48 "pat.pcc"
           new_p = TYPEDpat(unifier_of(((Pat_TYPEDpat *)pat)->_1),((Pat_TYPEDpat *)pat)->_2); 
#line 48 "pat.pcc"
            } break;
         case a_Pat::tag_ASpat: {
#line 49 "pat.pcc"
           new_p = ASpat(((Pat_ASpat *)pat)->_1,unifier_of(((Pat_ASpat *)pat)->_2),((Pat_ASpat *)pat)->_3,((Pat_ASpat *)pat)->_4); 
#line 49 "pat.pcc"
            } break;
         case a_Pat::tag_ARRAYpat: {
#line 50 "pat.pcc"
           new_p = ARRAYpat(unifier_of(((Pat_ARRAYpat *)pat)->_1),((Pat_ARRAYpat *)pat)->_2); 
#line 50 "pat.pcc"
            } break;
         case a_Pat::tag_TUPLEpat: {
#line 51 "pat.pcc"
           new_p = TUPLEpat(unifier_of(((Pat_TUPLEpat *)pat)->TUPLEpat)); 
#line 51 "pat.pcc"
            } break;
         case a_Pat::tag_EXTUPLEpat: {
#line 52 "pat.pcc"
           new_p = EXTUPLEpat(unifier_of(((Pat_EXTUPLEpat *)pat)->EXTUPLEpat)); 
#line 52 "pat.pcc"
            } break;
         case a_Pat::tag_RECORDpat: {
#line 53 "pat.pcc"
           new_p = RECORDpat(unifier_of(((Pat_RECORDpat *)pat)->_1),((Pat_RECORDpat *)pat)->_2); 
#line 53 "pat.pcc"
            } break;
         case a_Pat::tag_LISTpat: {
#line 56 "pat.pcc"
           new_p = 
#line 56 "pat.pcc"
#line 56 "pat.pcc"
            LISTpat(((Pat_LISTpat *)pat)->cons, ((Pat_LISTpat *)pat)->nil, unifier_of(((Pat_LISTpat *)pat)->head), unifier_of(((Pat_LISTpat *)pat)->tail))
#line 58 "pat.pcc"
#line 58 "pat.pcc"
            ;
            
#line 59 "pat.pcc"
            } break;
         case a_Pat::tag_VECTORpat: {
#line 61 "pat.pcc"
           new_p = 
#line 61 "pat.pcc"
#line 61 "pat.pcc"
            VECTORpat(((Pat_VECTORpat *)pat)->cons, unifier_of(((Pat_VECTORpat *)pat)->len), unifier_of(((Pat_VECTORpat *)pat)->array), unifier_of(((Pat_VECTORpat *)pat)->elements), ((Pat_VECTORpat *)pat)->head_flex, ((Pat_VECTORpat *)pat)->tail_flex)
#line 67 "pat.pcc"
#line 67 "pat.pcc"
            ;
            
#line 68 "pat.pcc"
            } break;
         case a_Pat::tag_GUARDpat: {
#line 54 "pat.pcc"
           new_p = GUARDpat(unifier_of(((Pat_GUARDpat *)pat)->_1),((Pat_GUARDpat *)pat)->_2); 
#line 54 "pat.pcc"
            } break;
         case a_Pat::tag_LOGICALpat: {
#line 70 "pat.pcc"
           new_p = LOGICALpat(((Pat_LOGICALpat *)pat)->_1,unifier_of(((Pat_LOGICALpat *)pat)->_2),unifier_of(((Pat_LOGICALpat *)pat)->_3)); 
#line 70 "pat.pcc"
            } break;
         case a_Pat::tag_MARKEDpat: {
#line 71 "pat.pcc"
           new_p = MARKEDpat(((Pat_MARKEDpat *)pat)->_1, unifier_of(((Pat_MARKEDpat *)pat)->_2)); 
#line 71 "pat.pcc"
            } break;
         case a_Pat::tag_WILDpat:
         case a_Pat::tag_IDpat:
         case a_Pat::tag_LITERALpat:
         case a_Pat::tag_CONTEXTpat:
         case a_Pat::tag_LEXEMEpat: {
            L3:; } break;
         default: { goto L2; } break;
      }
   } else { goto L3; }
}
#line 73 "pat.pcc"
#line 73 "pat.pcc"
   
   if (new_p != pat && boxed(pat) && boxed(new_p))
   {  new_p->selector = pat->selector;
      new_p->ty       = pat->ty;
   }
   return new_p;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Convert a simple pattern list into an unifier list.
//
///////////////////////////////////////////////////////////////////////////////
Pats unifier_of (Pats pats)
{  
#line 87 "pat.pcc"
#line 89 "pat.pcc"
{
   if (pats) {
#line 89 "pat.pcc"
     return 
#line 89 "pat.pcc"
#line 89 "pat.pcc"
      list_1_(unifier_of(pats->_1),unifier_of(pats->_2))
#line 89 "pat.pcc"
#line 89 "pat.pcc"
      ; 
#line 89 "pat.pcc"
   } else {
#line 88 "pat.pcc"
     return 
#line 88 "pat.pcc"
#line 88 "pat.pcc"
      nil_1_
#line 88 "pat.pcc"
#line 88 "pat.pcc"
      ; 
#line 88 "pat.pcc"
   }
}
#line 90 "pat.pcc"
#line 90 "pat.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Convert a simple labeled pattern list into an labeled unifier list.
//
///////////////////////////////////////////////////////////////////////////////
LabPats unifier_of (LabPats pats)
{  
#line 99 "pat.pcc"
#line 105 "pat.pcc"
{
   if (pats) {
#line 101 "pat.pcc"
     LabPat lab_pat;
      lab_pat.label = pats->_1.label;
      lab_pat.pat   = unifier_of(pats->_1.pat);
      return 
#line 104 "pat.pcc"
#line 104 "pat.pcc"
      list_1_(lab_pat,unifier_of(pats->_2))
#line 104 "pat.pcc"
#line 104 "pat.pcc"
      ; 
      
#line 105 "pat.pcc"
   } else {
#line 100 "pat.pcc"
     return 
#line 100 "pat.pcc"
#line 100 "pat.pcc"
      nil_1_
#line 100 "pat.pcc"
#line 100 "pat.pcc"
      ; 
#line 100 "pat.pcc"
   }
}
#line 106 "pat.pcc"
#line 106 "pat.pcc"

}
///////////////////////////////////////////////////////////////////////////////
//
//  Check whether pattern a subsumes b, i.e. more general.
//
///////////////////////////////////////////////////////////////////////////////
Bool subsumes (Pat a, Pat b, Bool v)
{  
#line 114 "pat.pcc"
#line 128 "pat.pcc"
{
   if (a) {
      switch (a->tag__) {
         case a_Pat::tag_CONSpat: {
            if (b) {
               switch (b->tag__) {
                  case a_Pat::tag_CONSpat: {
#line 124 "pat.pcc"
                    return ((Pat_CONSpat *)a)->CONSpat == ((Pat_CONSpat *)b)->CONSpat; 
#line 124 "pat.pcc"
                     } break;
                  case a_Pat::tag_TYPEDpat: {
                     L4:; 
#line 123 "pat.pcc"
                    return subsumes(a,((Pat_TYPEDpat *)b)->_1,v); 
#line 123 "pat.pcc"
                     } break;
                  case a_Pat::tag_ASpat: {
                     L5:; 
#line 121 "pat.pcc"
                    return subsumes(a,((Pat_ASpat *)b)->_2,v); 
#line 121 "pat.pcc"
                     } break;
                  default: {
                     L6:; 
#line 128 "pat.pcc"
                    return false; 
#line 128 "pat.pcc"
                     } break;
               }
            } else { goto L6; }
            } break;
         case a_Pat::tag_APPpat: {
            if (b) {
               switch (b->tag__) {
                  case a_Pat::tag_APPpat: {
#line 125 "pat.pcc"
                    return subsumes(((Pat_APPpat *)a)->_1,((Pat_APPpat *)b)->_1,v) && subsumes(((Pat_APPpat *)a)->_2,((Pat_APPpat *)b)->_2,v); 
#line 125 "pat.pcc"
                     } break;
                  case a_Pat::tag_TYPEDpat: { goto L4; } break;
                  case a_Pat::tag_ASpat: { goto L5; } break;
                  default: { goto L6; } break;
               }
            } else { goto L6; }
            } break;
         case a_Pat::tag_TYPEDpat: {
            if (b) {
               switch (b->tag__) {
                  case a_Pat::tag_ASpat: { goto L5; } break;
                  default: {
                     L7:; 
#line 122 "pat.pcc"
                    return subsumes(((Pat_TYPEDpat *)a)->_1,b,v); 
#line 122 "pat.pcc"
                     } break;
               }
            } else { goto L7; }
            } break;
         case a_Pat::tag_ASpat: {
#line 120 "pat.pcc"
           return subsumes(((Pat_ASpat *)a)->_2,b,v); 
#line 120 "pat.pcc"
            } break;
         case a_Pat::tag_LITERALpat: {
            if (b) {
               switch (b->tag__) {
                  case a_Pat::tag_TYPEDpat: { goto L4; } break;
                  case a_Pat::tag_ASpat: { goto L5; } break;
                  case a_Pat::tag_LITERALpat: {
#line 117 "pat.pcc"
                    return literal_equal(((Pat_LITERALpat *)a)->LITERALpat,((Pat_LITERALpat *)b)->LITERALpat); 
#line 117 "pat.pcc"
                     } break;
                  default: { goto L6; } break;
               }
            } else { goto L6; }
            } break;
         case a_Pat::tag_TUPLEpat: {
            if (b) {
               switch (b->tag__) {
                  case a_Pat::tag_TYPEDpat: { goto L4; } break;
                  case a_Pat::tag_ASpat: { goto L5; } break;
                  case a_Pat::tag_TUPLEpat: {
#line 118 "pat.pcc"
                    return subsumes(((Pat_TUPLEpat *)a)->TUPLEpat,((Pat_TUPLEpat *)b)->TUPLEpat,v); 
#line 118 "pat.pcc"
                     } break;
                  default: { goto L6; } break;
               }
            } else { goto L6; }
            } break;
         case a_Pat::tag_EXTUPLEpat: {
            if (b) {
               switch (b->tag__) {
                  case a_Pat::tag_TYPEDpat: { goto L4; } break;
                  case a_Pat::tag_ASpat: { goto L5; } break;
                  case a_Pat::tag_EXTUPLEpat: {
#line 119 "pat.pcc"
                    return subsumes(((Pat_EXTUPLEpat *)a)->EXTUPLEpat,((Pat_EXTUPLEpat *)b)->EXTUPLEpat,v); 
#line 119 "pat.pcc"
                     } break;
                  default: { goto L6; } break;
               }
            } else { goto L6; }
            } break;
         case a_Pat::tag_GUARDpat: {
            if (b) {
               switch (b->tag__) {
                  case a_Pat::tag_TYPEDpat: { goto L4; } break;
                  case a_Pat::tag_ASpat: { goto L5; } break;
                  case a_Pat::tag_GUARDpat: {
#line 126 "pat.pcc"
                    return subsumes(((Pat_GUARDpat *)a)->_1,((Pat_GUARDpat *)b)->_1,v) && equal(((Pat_GUARDpat *)a)->_2,((Pat_GUARDpat *)b)->_2); 
#line 126 "pat.pcc"
                     } break;
                  default: { goto L6; } break;
               }
            } else { goto L6; }
            } break;
         case a_Pat::tag_LOGICALpat: {
            if (b) {
               switch (b->tag__) {
                  case a_Pat::tag_TYPEDpat: { goto L4; } break;
                  case a_Pat::tag_ASpat: { goto L5; } break;
                  default: {
                     L8:; 
                     switch (((Pat_LOGICALpat *)a)->_1) {
                        case ORpat: {
                           L9:; 
#line 127 "pat.pcc"
                          return subsumes(((Pat_LOGICALpat *)a)->_2,b,v) && subsumes(((Pat_LOGICALpat *)a)->_3,b,v); 
#line 127 "pat.pcc"
                           } break;
                        default: { goto L6; } break;
                     }
                     } break;
               }
            } else { goto L8; }
            } break;
         case a_Pat::tag_BACKEDGEpat: {
#line 116 "pat.pcc"
           return subsumes(((Pat_BACKEDGEpat *)a)->_3,b,v); 
#line 116 "pat.pcc"
            } break;
         case a_Pat::tag_WILDpat:
         case a_Pat::tag_IDpat: {
#line 115 "pat.pcc"
           return true; 
#line 115 "pat.pcc"
            } break;
         default: {
            L10:; 
            if (b) {
               switch (b->tag__) {
                  case a_Pat::tag_TYPEDpat: { goto L4; } break;
                  case a_Pat::tag_ASpat: { goto L5; } break;
                  default: { goto L6; } break;
               }
            } else { goto L6; }
            } break;
      }
   } else { goto L10; }
}
#line 129 "pat.pcc"
#line 129 "pat.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Checks whether list a subsumes list b.  Subsumption is computed
//  componentwise.
//
///////////////////////////////////////////////////////////////////////////////
Bool subsumes (Pats a, Pats b, Bool v)
{  
#line 139 "pat.pcc"
#line 142 "pat.pcc"
{
   if (a) {
      if (b) {
#line 141 "pat.pcc"
        return subsumes(a->_1,b->_1,v) && subsumes(a->_2,b->_2,v); 
#line 141 "pat.pcc"
      } else {
         L11:; 
#line 142 "pat.pcc"
        return false; 
#line 142 "pat.pcc"
      }
   } else {
      if (b) { goto L11; } else {
#line 140 "pat.pcc"
        return true; 
#line 140 "pat.pcc"
      }
   }
}
#line 143 "pat.pcc"
#line 143 "pat.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Computes the subsumption info for two labeled pat lists.
//
///////////////////////////////////////////////////////////////////////////////
Bool subsumes (LabPats, LabPats, Bool verbose)
{  return false;
}
#line 154 "pat.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 751
Number of ifs generated      = 21
Number of switches generated = 15
Number of labels             = 11
Number of gotos              = 41
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
