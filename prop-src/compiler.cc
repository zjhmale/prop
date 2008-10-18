///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.6),
//  last updated on Nov 2, 1999.
//  The original source file is "compiler.pcc".
///////////////////////////////////////////////////////////////////////////////

#line 1 "compiler.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  The file implements the class Compiler and this is the main entry
//  point of the Prop -> C++ translator.
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream.h>
#include "ir.h"
#include "ast.h"
#include "type.h"
#include "compiler.h"
#include "options.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Constructor and destructor
//
///////////////////////////////////////////////////////////////////////////////
Compiler:: Compiler(TyOpt opt, int embedded_tags) 
   : DatatypeCompiler (opt,embedded_tags) {}
Compiler::~Compiler() {}

///////////////////////////////////////////////////////////////////////////////
//
//  Emit header info
//
///////////////////////////////////////////////////////////////////////////////
void Compiler::emit_header(const char * text, int n) { header.emit(text,n); }
void Compiler::emit_header_text() 
{  const char * header_text = header.text();
   if (header_text) pr("%s",header_text); 
}

///////////////////////////////////////////////////////////////////////////////
//
//  Additional printing method
//
///////////////////////////////////////////////////////////////////////////////
va_list Compiler::printer(char fmt, va_list arg) 
{  
#line 40 "compiler.pcc"
#line 44 "compiler.pcc"
{
   switch (fmt) {
      case '&': {
#line 42 "compiler.pcc"
        gen(va_arg(arg,Decls)); 
#line 42 "compiler.pcc"
      } break;
      case 'D': {
#line 43 "compiler.pcc"
        gen(va_arg(arg,Decl)); 
#line 43 "compiler.pcc"
      } break;
      case 'm': {
#line 41 "compiler.pcc"
        MatchCompiler::gen(va_arg(arg,Match)); 
#line 41 "compiler.pcc"
      } break;
      default: {
#line 44 "compiler.pcc"
        bug("undefined print format '%%%c'\n", (int)fmt); 
#line 44 "compiler.pcc"
      }
   }
}
#line 45 "compiler.pcc"
#line 45 "compiler.pcc"

   return arg;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Top level code generation method
//
///////////////////////////////////////////////////////////////////////////////
void Compiler::generate(Decls ds)
{  
   // generate the quark literals
   if (quark_map.size() > 0)
   {  pr ("%^%/"
          "%^//  Quark literals"
          "%^%/");
      foreach_entry (e, quark_map)
      {  Id name  = (Id)quark_map.key(e);
         Id quark = (Id)quark_map.value(e);
         pr ("%^static const Quark %s(%s);\n", quark, name);
      }
   }

   // now generate the main program.
   gen(ds);

   // finally, generate any outstanding rewriters
   gen_rewriters();

   // if the visualization is on then print GDL
   if (options.visualization) print_definitions_as_GDL();
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate a list of declarations.
//
///////////////////////////////////////////////////////////////////////////////
void Compiler::gen(Decls ds) 
{  Bool line_prefix = true;
   Bool line_suffix = true;
   
#line 86 "compiler.pcc"
#line 94 "compiler.pcc"
{
   for (;;) {
      if (ds) {
#line 88 "compiler.pcc"
       
#line 88 "compiler.pcc"
#line 90 "compiler.pcc"
         {
            Decl _V1 = ds->_1;
            if (_V1) {
               switch (_V1->tag__) {
                  case a_Decl::tag_TYPEEXPdecl: {
#line 89 "compiler.pcc"
                    line_suffix = line_prefix; line_prefix = false; 
#line 89 "compiler.pcc"
                     } break;
                  default: {
                     L2:; 
#line 90 "compiler.pcc"
                    line_suffix = line_prefix; line_prefix = true; 
#line 90 "compiler.pcc"
                     } break;
               }
            } else { goto L2; }
         }
#line 91 "compiler.pcc"
#line 91 "compiler.pcc"
         
         gen(ds->_1,line_prefix,line_suffix);
         ds = ds->_2;
         
#line 94 "compiler.pcc"
      } else { goto L1; }
   }
   L1:;
}
#line 95 "compiler.pcc"
#line 95 "compiler.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate one declaration.
//
///////////////////////////////////////////////////////////////////////////////
void Compiler::gen(Decl d, Bool line_prefix, Bool line_suffix)
{  
#line 104 "compiler.pcc"
#line 175 "compiler.pcc"
{
   if (d) {
      switch (d->tag__) {
         case a_Decl::tag_OPAQUEdecl: {
#line 106 "compiler.pcc"
           pr ("%C",((Decl_OPAQUEdecl *)d)->OPAQUEdecl); 
#line 106 "compiler.pcc"
            } break;
         case a_Decl::tag_DATATYPEdecl: {
#line 107 "compiler.pcc"
           gen_datatype(((Decl_DATATYPEdecl *)d)->_1,((Decl_DATATYPEdecl *)d)->_2,((Decl_DATATYPEdecl *)d)->_3,((Decl_DATATYPEdecl *)d)->_4); 
#line 107 "compiler.pcc"
            } break;
         case a_Decl::tag_INSTANTIATEdecl: {
#line 108 "compiler.pcc"
           instantiate_datatypes(((Decl_INSTANTIATEdecl *)d)->_1,((Decl_INSTANTIATEdecl *)d)->_2);
#line 108 "compiler.pcc"
            } break;
         case a_Decl::tag_CLASSDEFdecl: {
#line 123 "compiler.pcc"
          ((Decl_CLASSDEFdecl *)d)->CLASSDEFdecl->gen_class_definition(*this); 
#line 123 "compiler.pcc"
            } break;
         case a_Decl::tag_INFERENCEdecl: {
#line 115 "compiler.pcc"
           gen_inference_rules(((Decl_INFERENCEdecl *)d)->_1, ((Decl_INFERENCEdecl *)d)->_2); 
#line 115 "compiler.pcc"
            } break;
         case a_Decl::tag_REWRITEdecl: {
#line 109 "compiler.pcc"
           gen_rewrite(((Decl_REWRITEdecl *)d)->_1, ((Decl_REWRITEdecl *)d)->_2, ((Decl_REWRITEdecl *)d)->_3); 
#line 109 "compiler.pcc"
            } break;
         case a_Decl::tag_REWRITINGdecl: {
#line 110 "compiler.pcc"
           gen_rewriting(((Decl_REWRITINGdecl *)d)->_1,((Decl_REWRITINGdecl *)d)->_2,((Decl_REWRITINGdecl *)d)->_3,((Decl_REWRITINGdecl *)d)->_4,((Decl_REWRITINGdecl *)d)->_5,((Decl_REWRITINGdecl *)d)->_6); 
#line 110 "compiler.pcc"
            } break;
         case a_Decl::tag_REPLACEMENTdecl: {
#line 119 "compiler.pcc"
           gen_replacement(((Decl_REPLACEMENTdecl *)d)->_1,((Decl_REPLACEMENTdecl *)d)->_2); 
#line 119 "compiler.pcc"
            } break;
         case a_Decl::tag_CUTREWRITEdecl: {
#line 120 "compiler.pcc"
           gen_cutreplacement(((Decl_CUTREWRITEdecl *)d)->_1,((Decl_CUTREWRITEdecl *)d)->_2); 
#line 120 "compiler.pcc"
            } break;
         case a_Decl::tag_FAILREWRITEdecl: {
#line 121 "compiler.pcc"
           gen_failrewrite(((Decl_FAILREWRITEdecl *)d)->FAILREWRITEdecl); 
#line 121 "compiler.pcc"
            } break;
         case a_Decl::tag_INJECTdecl: {
            if (((Decl_INJECTdecl *)d)->direction) {
               
#line 154 "compiler.pcc"
             pr (" if (i__) insert_alpha(%i,fact__); else remove_alpha(%i,fact__); ",
               ((Decl_INJECTdecl *)d)->node_number, ((Decl_INJECTdecl *)d)->node_number); 
#line 155 "compiler.pcc"
            } else {
               
#line 157 "compiler.pcc"
             pr (" if (i__) insert_beta(%i,f__); else remove_beta(%i,f__); ", 
               ((Decl_INJECTdecl *)d)->node_number, ((Decl_INJECTdecl *)d)->node_number); 
#line 158 "compiler.pcc"
            }
            } break;
         case a_Decl::tag_GOTOdecl: {
#line 151 "compiler.pcc"
           pr ("%^goto %s;\n", ((Decl_GOTOdecl *)d)->GOTOdecl); 
#line 151 "compiler.pcc"
            } break;
         case a_Decl::tag_SETSTATEdecl: {
#line 152 "compiler.pcc"
           pr ("s__ = %i;", ((Decl_SETSTATEdecl *)d)->SETSTATEdecl); 
#line 152 "compiler.pcc"
            } break;
         case a_Decl::tag_SYNTAXdecl: {
#line 113 "compiler.pcc"
           gen_parser(((Decl_SYNTAXdecl *)d)->_1,((Decl_SYNTAXdecl *)d)->_2); 
#line 113 "compiler.pcc"
            } break;
         case a_Decl::tag_ATTRIBUTEGRAMMARdecl: {
#line 114 "compiler.pcc"
           gen_attribute_grammar(((Decl_ATTRIBUTEGRAMMARdecl *)d)->_1,((Decl_ATTRIBUTEGRAMMARdecl *)d)->_2); 
#line 114 "compiler.pcc"
            } break;
         case a_Decl::tag_FUNdecl: {
#line 111 "compiler.pcc"
           gen_fun_def(((Decl_FUNdecl *)d)->FUNdecl); 
#line 111 "compiler.pcc"
            } break;
         case a_Decl::tag_MATCHdecl: {
#line 112 "compiler.pcc"
           gen_match_stmt(((Decl_MATCHdecl *)d)->_1,((Decl_MATCHdecl *)d)->_2,((Decl_MATCHdecl *)d)->_3,((Decl_MATCHdecl *)d)->_4); 
#line 112 "compiler.pcc"
            } break;
         case a_Decl::tag_SETLSTMTdecl: {
#line 116 "compiler.pcc"
           gen_setl(((Decl_SETLSTMTdecl *)d)->SETLSTMTdecl); 
#line 116 "compiler.pcc"
            } break;
         case a_Decl::tag_SETLDEFdecl: {
#line 117 "compiler.pcc"
           gen_setl(((Decl_SETLDEFdecl *)d)->SETLDEFdecl); 
#line 117 "compiler.pcc"
            } break;
         case a_Decl::tag_CLASSOFdecl: {
#line 125 "compiler.pcc"
          
#line 125 "compiler.pcc"
#line 147 "compiler.pcc"
            {
               Ty _V2 = lookup_ty(((Decl_CLASSOFdecl *)d)->CLASSOFdecl);
               if (_V2) {
                  switch (_V2->tag__) {
                     case a_Ty::tag_TYCONty: {
                        if (boxed(((Ty_TYCONty *)_V2)->_1)) {
                           switch (((Ty_TYCONty *)_V2)->_1->tag__) {
                              case a_TyCon::tag_DATATYPEtycon: {
#line 127 "compiler.pcc"
                               pr ("a_%s", ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V2)->_1)->id); 
#line 127 "compiler.pcc"
                                 } break;
                              default: {
                                 L3:; 
#line 147 "compiler.pcc"
                               error ("%Ltype %s has unknown class: %T\n",((Decl_CLASSOFdecl *)d)->CLASSOFdecl, _V2); 
#line 147 "compiler.pcc"
                                 } break;
                           }
                        } else { goto L3; }
                        } break;
                     default: { goto L3; } break;
                  }
               } else {
#line 129 "compiler.pcc"
                
#line 129 "compiler.pcc"
#line 143 "compiler.pcc"
                  {
                     Cons _V3 = find_cons(((Decl_CLASSOFdecl *)d)->CLASSOFdecl);
                     if (_V3) {
                        if (
#line 132 "compiler.pcc"
                        (_V3->opt & OPTunboxed)
#line 132 "compiler.pcc"
) {
                           
                           if (_V3->ty) {
#line 133 "compiler.pcc"
                            error ("%Lthe class representation of constructor %s has been elided\n", ((Decl_CLASSOFdecl *)d)->CLASSOFdecl); 
#line 133 "compiler.pcc"
                           } else {
                              L4:; 
#line 131 "compiler.pcc"
                            error ("%Lconstructor %s is not a class\n", ((Decl_CLASSOFdecl *)d)->CLASSOFdecl); 
#line 131 "compiler.pcc"
                           }
                        } else {
                           
                           if (_V3->alg_ty) {
                              switch (_V3->alg_ty->tag__) {
                                 case a_Ty::tag_TYCONty: {
                                    if (_V3->ty) {
                                       if (boxed(((Ty_TYCONty *)_V3->alg_ty)->_1)) {
                                          switch (((Ty_TYCONty *)_V3->alg_ty)->_1->tag__) {
                                             case a_TyCon::tag_DATATYPEtycon: {
                                                L5:; 
#line 139 "compiler.pcc"
                                              if (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V3->alg_ty)->_1)->opt & OPTsubclassless) pr ("a_%s", ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V3->alg_ty)->_1)->id); 
                                                else                       pr ("%s_%S", ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V3->alg_ty)->_1)->id, _V3->name); 
                                                
#line 141 "compiler.pcc"
                                                } break;
                                             default: {
                                                L6:; 
#line 143 "compiler.pcc"
                                              error ("%Ltype or constructor %s is undefined\n", ((Decl_CLASSOFdecl *)d)->CLASSOFdecl); 
#line 143 "compiler.pcc"
                                                } break;
                                          }
                                       } else { goto L6; }
                                    } else { goto L4; }
                                    } break;
                                 default: {
                                    L7:; 
                                    if (_V3->ty) { goto L6; } else { goto L4; }
                                    } break;
                              }
                           } else { goto L7; }
                        }
                     } else { goto L6; }
                  }
#line 144 "compiler.pcc"
#line 144 "compiler.pcc"
                  
                  
#line 145 "compiler.pcc"
               }
            }
#line 148 "compiler.pcc"
#line 148 "compiler.pcc"
            
            
#line 149 "compiler.pcc"
            } break;
         case a_Decl::tag_TYPEEXPdecl: {
#line 150 "compiler.pcc"
           pr ("%t", ((Decl_TYPEEXPdecl *)d)->TYPEEXPdecl,""); 
#line 150 "compiler.pcc"
            } break;
         case a_Decl::tag_EXPdecl: {
            if (((Decl_EXPdecl *)d)->exp) {
               switch (((Decl_EXPdecl *)d)->exp->tag__) {
                  case a_Exp::tag_THISSYNexp:
                  case a_Exp::tag_SYNexp: {
#line 164 "compiler.pcc"
                    pr ("%e", ((Decl_EXPdecl *)d)->exp); 
#line 164 "compiler.pcc"
                     } break;
                  default: {
                     L8:; 
#line 166 "compiler.pcc"
                    pr ("%^%s%e%s", (((Decl_EXPdecl *)d)->prefix ? ((Decl_EXPdecl *)d)->prefix : ""),((Decl_EXPdecl *)d)->exp, (((Decl_EXPdecl *)d)->suffix ? ((Decl_EXPdecl *)d)->suffix : "")); 
#line 166 "compiler.pcc"
                     } break;
               }
            } else { goto L8; }
            } break;
         case a_Decl::tag_MARKEDdecl: {
#line 168 "compiler.pcc"
          line = ((Decl_MARKEDdecl *)d)->_1.begin_line; 
            file = ((Decl_MARKEDdecl *)d)->_1.file_name;
            if (line_prefix) pr ("%#",line,file);
            gen(((Decl_MARKEDdecl *)d)->_2);         
            line = ((Decl_MARKEDdecl *)d)->_1.end_line; 
            if (line_suffix) pr ("%#",line,file);
            
#line 174 "compiler.pcc"
            } break;
         default: {
#line 175 "compiler.pcc"
           bug("Unimplemented feature"); 
#line 175 "compiler.pcc"
            } break;
      }
   } else {
#line 105 "compiler.pcc"
     /* skip */ 
#line 105 "compiler.pcc"
   }
}
#line 176 "compiler.pcc"
#line 176 "compiler.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate a report.
//
///////////////////////////////////////////////////////////////////////////////
ostream& Compiler::print_report(ostream& f)
{  f << 
   "------------------------------- Statistics -------------------------------"
<< "\nMerge matching rules         = " << (options.merge_match ?  "yes" : "no")
<< "\nNumber of DFA nodes merged   = " << merges 
<< "\nNumber of ifs generated      = " << ifs
<< "\nNumber of switches generated = " << switches
<< "\nNumber of labels             = " << goto_labels
<< "\nNumber of gotos              = " << gotos
<< "\nAdaptive matching            = " << (options.adaptive_matching ? "enabled" : "disabled")
<< "\nFast string matching         = " << (options.fast_string_match ? "enabled" : "disabled")
<< "\nInline downcasts             = " << (options.inline_casts ? "enabled" : "disabled")
<< "\n"
   "--------------------------------------------------------------------------"
   "\n"
   ;
   return f;
}
#line 202 "compiler.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 398
Number of ifs generated      = 14
Number of switches generated = 8
Number of labels             = 7
Number of gotos              = 10
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
