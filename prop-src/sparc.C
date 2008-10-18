///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.3.0),
//  last updated on Feb 5, 1997.
//  The original source file is "sparc.pC".
///////////////////////////////////////////////////////////////////////////////

#define PROP_REWRITING_USED
#define PROP_EQUALITY_USED
#define PROP_QUARK_USED
#include <propdefs.h>
#line 36 "sparc.pC"
///////////////////////////////////////////////////////////////////////////////
// Forward class definition for Inst
///////////////////////////////////////////////////////////////////////////////
#ifndef datatype_Inst_defined
#define datatype_Inst_defined
   typedef class a_Inst * Inst;
#endif

///////////////////////////////////////////////////////////////////////////////
// Class hierarchy for datatype Inst
///////////////////////////////////////////////////////////////////////////////
class a_Inst; // base class for datatype Inst
   class Inst_ADDD;	// subclass for 'ADDD (Inst, Inst)'
   class Inst_ADDF;	// subclass for 'ADDF (Inst, Inst)'
   class Inst_ADDI;	// subclass for 'ADDI (Inst, Inst)'
   class Inst_ADDP;	// subclass for 'ADDP (Inst, Inst)'
   class Inst_ADDU;	// subclass for 'ADDU (Inst, Inst)'
   class Inst_ADDRFP;	// subclass for 'ADDRFP ()'
   class Inst_ADDRGP;	// subclass for 'ADDRGP ()'
   class Inst_ADDRLP;	// subclass for 'ADDRLP ()'
   class Inst_ARGB;	// subclass for 'ARGB Inst'
   class Inst_ARGD;	// subclass for 'ARGD Inst'
   class Inst_ARGF;	// subclass for 'ARGF Inst'
   class Inst_ARGI;	// subclass for 'ARGI Inst'
   class Inst_ARGP;	// subclass for 'ARGP Inst'
   class Inst_ASGNB;	// subclass for 'ASGNB (Inst, Inst)'
   class Inst_ASGNC;	// subclass for 'ASGNC (Inst, Inst)'
   class Inst_ASGND;	// subclass for 'ASGND (Inst, Inst)'
   class Inst_ASGNF;	// subclass for 'ASGNF (Inst, Inst)'
   class Inst_ASGNI;	// subclass for 'ASGNI (Inst, Inst)'
   class Inst_ASGNP;	// subclass for 'ASGNP (Inst, Inst)'
   class Inst_ASGNS;	// subclass for 'ASGNS (Inst, Inst)'
   class Inst_BANDU;	// subclass for 'BANDU (Inst, Inst)'
   class Inst_BCOMU;	// subclass for 'BCOMU Inst'
   class Inst_BORU;	// subclass for 'BORU (Inst, Inst)'
   class Inst_BXORU;	// subclass for 'BXORU (Inst, Inst)'
   class Inst_CALLB;	// subclass for 'CALLB (Inst, Inst)'
   class Inst_CALLD;	// subclass for 'CALLD Inst'
   class Inst_CALLF;	// subclass for 'CALLF Inst'
   class Inst_CALLI;	// subclass for 'CALLI Inst'
   class Inst_CALLV;	// subclass for 'CALLV Inst'
   class Inst_CNSTC;	// subclass for 'CNSTC ()'
   class Inst_CNSTD;	// subclass for 'CNSTD ()'
   class Inst_CNSTF;	// subclass for 'CNSTF ()'
   class Inst_CNSTI;	// subclass for 'CNSTI ()'
   class Inst_CNSTP;	// subclass for 'CNSTP ()'
   class Inst_CNSTS;	// subclass for 'CNSTS ()'
   class Inst_CNSTU;	// subclass for 'CNSTU ()'
   class Inst_CVCI;	// subclass for 'CVCI Inst'
   class Inst_CVCU;	// subclass for 'CVCU Inst'
   class Inst_CVDF;	// subclass for 'CVDF Inst'
   class Inst_CVDI;	// subclass for 'CVDI Inst'
   class Inst_CVFD;	// subclass for 'CVFD Inst'
   class Inst_CVIC;	// subclass for 'CVIC Inst'
   class Inst_CVID;	// subclass for 'CVID Inst'
   class Inst_CVIS;	// subclass for 'CVIS Inst'
   class Inst_CVIU;	// subclass for 'CVIU Inst'
   class Inst_CVPU;	// subclass for 'CVPU Inst'
   class Inst_CVSI;	// subclass for 'CVSI Inst'
   class Inst_CVSU;	// subclass for 'CVSU Inst'
   class Inst_CVUC;	// subclass for 'CVUC Inst'
   class Inst_CVUI;	// subclass for 'CVUI Inst'
   class Inst_CVUP;	// subclass for 'CVUP Inst'
   class Inst_CVUS;	// subclass for 'CVUS Inst'
   class Inst_DIVD;	// subclass for 'DIVD (Inst, Inst)'
   class Inst_DIVF;	// subclass for 'DIVF (Inst, Inst)'
   class Inst_DIVI;	// subclass for 'DIVI (Inst, Inst)'
   class Inst_DIVU;	// subclass for 'DIVU (Inst, Inst)'
   class Inst_EQD;	// subclass for 'EQD (Inst, Inst)'
   class Inst_EQF;	// subclass for 'EQF (Inst, Inst)'
   class Inst_EQI;	// subclass for 'EQI (Inst, Inst)'
   class Inst_GED;	// subclass for 'GED (Inst, Inst)'
   class Inst_GEF;	// subclass for 'GEF (Inst, Inst)'
   class Inst_GEI;	// subclass for 'GEI (Inst, Inst)'
   class Inst_GEU;	// subclass for 'GEU (Inst, Inst)'
   class Inst_GTD;	// subclass for 'GTD (Inst, Inst)'
   class Inst_GTF;	// subclass for 'GTF (Inst, Inst)'
   class Inst_GTI;	// subclass for 'GTI (Inst, Inst)'
   class Inst_GTU;	// subclass for 'GTU (Inst, Inst)'
   class Inst_INDIRB;	// subclass for 'INDIRB Inst'
   class Inst_INDIRC;	// subclass for 'INDIRC Inst'
   class Inst_INDIRD;	// subclass for 'INDIRD Inst'
   class Inst_INDIRF;	// subclass for 'INDIRF Inst'
   class Inst_INDIRI;	// subclass for 'INDIRI Inst'
   class Inst_INDIRP;	// subclass for 'INDIRP Inst'
   class Inst_INDIRS;	// subclass for 'INDIRS Inst'
   class Inst_JUMPV;	// subclass for 'JUMPV Inst'
   class Inst_LABELV;	// subclass for 'LABELV ()'
   class Inst_LED;	// subclass for 'LED (Inst, Inst)'
   class Inst_LEF;	// subclass for 'LEF (Inst, Inst)'
   class Inst_LEI;	// subclass for 'LEI (Inst, Inst)'
   class Inst_LEU;	// subclass for 'LEU (Inst, Inst)'
   class Inst_LOADB;	// subclass for 'LOADB Inst'
   class Inst_LOADC;	// subclass for 'LOADC Inst'
   class Inst_LOADD;	// subclass for 'LOADD Inst'
   class Inst_LOADF;	// subclass for 'LOADF Inst'
   class Inst_LOADI;	// subclass for 'LOADI Inst'
   class Inst_LOADP;	// subclass for 'LOADP Inst'
   class Inst_LOADS;	// subclass for 'LOADS Inst'
   class Inst_LOADU;	// subclass for 'LOADU Inst'
   class Inst_LSHI;	// subclass for 'LSHI (Inst, Inst)'
   class Inst_LSHU;	// subclass for 'LSHU (Inst, Inst)'
   class Inst_LTD;	// subclass for 'LTD (Inst, Inst)'
   class Inst_LTF;	// subclass for 'LTF (Inst, Inst)'
   class Inst_LTI;	// subclass for 'LTI (Inst, Inst)'
   class Inst_LTU;	// subclass for 'LTU (Inst, Inst)'
   class Inst_MODI;	// subclass for 'MODI (Inst, Inst)'
   class Inst_MODU;	// subclass for 'MODU (Inst, Inst)'
   class Inst_MULD;	// subclass for 'MULD (Inst, Inst)'
   class Inst_MULF;	// subclass for 'MULF (Inst, Inst)'
   class Inst_MULI;	// subclass for 'MULI (Inst, Inst)'
   class Inst_MULU;	// subclass for 'MULU (Inst, Inst)'
   class Inst_NED;	// subclass for 'NED (Inst, Inst)'
   class Inst_NEF;	// subclass for 'NEF (Inst, Inst)'
   class Inst_NEI;	// subclass for 'NEI (Inst, Inst)'
   class Inst_NEGD;	// subclass for 'NEGD Inst'
   class Inst_NEGF;	// subclass for 'NEGF Inst'
   class Inst_NEGI;	// subclass for 'NEGI Inst'
   class Inst_RETD;	// subclass for 'RETD Inst'
   class Inst_RETF;	// subclass for 'RETF Inst'
   class Inst_RETI;	// subclass for 'RETI Inst'
   class Inst_RSHI;	// subclass for 'RSHI (Inst, Inst)'
   class Inst_RSHU;	// subclass for 'RSHU (Inst, Inst)'
   class Inst_SUBD;	// subclass for 'SUBD (Inst, Inst)'
   class Inst_SUBF;	// subclass for 'SUBF (Inst, Inst)'
   class Inst_SUBI;	// subclass for 'SUBI (Inst, Inst)'
   class Inst_SUBP;	// subclass for 'SUBP (Inst, Inst)'
   class Inst_SUBU;	// subclass for 'SUBU (Inst, Inst)'
   class Inst_VREGP;	// subclass for 'VREGP ()'

///////////////////////////////////////////////////////////////////////////////
// Base class for datatype 'Inst'
///////////////////////////////////////////////////////////////////////////////
class a_Inst : public TermObj {
public:
   enum Tag_Inst {
      tag_ADDD = 0, tag_ADDF = 1, tag_ADDI = 2, tag_ADDP = 3, 
      tag_ADDU = 4, tag_ADDRFP = 5, tag_ADDRGP = 6, tag_ADDRLP = 7, 
      tag_ARGB = 8, tag_ARGD = 9, tag_ARGF = 10, tag_ARGI = 11, 
      tag_ARGP = 12, tag_ASGNB = 13, tag_ASGNC = 14, tag_ASGND = 15, 
      tag_ASGNF = 16, tag_ASGNI = 17, tag_ASGNP = 18, tag_ASGNS = 19, 
      tag_BANDU = 20, tag_BCOMU = 21, tag_BORU = 22, tag_BXORU = 23, 
      tag_CALLB = 24, tag_CALLD = 25, tag_CALLF = 26, tag_CALLI = 27, 
      tag_CALLV = 28, tag_CNSTC = 29, tag_CNSTD = 30, tag_CNSTF = 31, 
      tag_CNSTI = 32, tag_CNSTP = 33, tag_CNSTS = 34, tag_CNSTU = 35, 
      tag_CVCI = 36, tag_CVCU = 37, tag_CVDF = 38, tag_CVDI = 39, 
      tag_CVFD = 40, tag_CVIC = 41, tag_CVID = 42, tag_CVIS = 43, 
      tag_CVIU = 44, tag_CVPU = 45, tag_CVSI = 46, tag_CVSU = 47, 
      tag_CVUC = 48, tag_CVUI = 49, tag_CVUP = 50, tag_CVUS = 51, 
      tag_DIVD = 52, tag_DIVF = 53, tag_DIVI = 54, tag_DIVU = 55, 
      tag_EQD = 56, tag_EQF = 57, tag_EQI = 58, tag_GED = 59, 
      tag_GEF = 60, tag_GEI = 61, tag_GEU = 62, tag_GTD = 63, 
      tag_GTF = 64, tag_GTI = 65, tag_GTU = 66, tag_INDIRB = 67, 
      tag_INDIRC = 68, tag_INDIRD = 69, tag_INDIRF = 70, tag_INDIRI = 71, 
      tag_INDIRP = 72, tag_INDIRS = 73, tag_JUMPV = 74, tag_LABELV = 75, 
      tag_LED = 76, tag_LEF = 77, tag_LEI = 78, tag_LEU = 79, 
      tag_LOADB = 80, tag_LOADC = 81, tag_LOADD = 82, tag_LOADF = 83, 
      tag_LOADI = 84, tag_LOADP = 85, tag_LOADS = 86, tag_LOADU = 87, 
      tag_LSHI = 88, tag_LSHU = 89, tag_LTD = 90, tag_LTF = 91, 
      tag_LTI = 92, tag_LTU = 93, tag_MODI = 94, tag_MODU = 95, 
      tag_MULD = 96, tag_MULF = 97, tag_MULI = 98, tag_MULU = 99, 
      tag_NED = 100, tag_NEF = 101, tag_NEI = 102, tag_NEGD = 103, 
      tag_NEGF = 104, tag_NEGI = 105, tag_RETD = 106, tag_RETF = 107, 
      tag_RETI = 108, tag_RSHI = 109, tag_RSHU = 110, tag_SUBD = 111, 
      tag_SUBF = 112, tag_SUBI = 113, tag_SUBP = 114, tag_SUBU = 115, 
      tag_VREGP = 116
   };

protected:
   const Tag_Inst _tag_;
   inline a_Inst(Tag_Inst _t_) : _tag_(_t_) {}
public:
   inline int untag() const { return _tag_; }
   inline friend int boxed(const a_Inst * x) { return 1; }
   inline friend int untag(const a_Inst * x) { return x->_tag_; }
   ////////////////////////////////////////////////////////////////////////////
   // Downcasting functions for Inst
   ////////////////////////////////////////////////////////////////////////////
   inline friend Inst_ADDD * _ADDD(Inst _x_) { return (Inst_ADDD *)_x_; }
   inline friend Inst_ADDF * _ADDF(Inst _x_) { return (Inst_ADDF *)_x_; }
   inline friend Inst_ADDI * _ADDI(Inst _x_) { return (Inst_ADDI *)_x_; }
   inline friend Inst_ADDP * _ADDP(Inst _x_) { return (Inst_ADDP *)_x_; }
   inline friend Inst_ADDU * _ADDU(Inst _x_) { return (Inst_ADDU *)_x_; }
   inline friend Inst_ADDRFP * _ADDRFP(Inst _x_) { return (Inst_ADDRFP *)_x_; }
   inline friend Inst_ADDRGP * _ADDRGP(Inst _x_) { return (Inst_ADDRGP *)_x_; }
   inline friend Inst_ADDRLP * _ADDRLP(Inst _x_) { return (Inst_ADDRLP *)_x_; }
   inline friend Inst_ARGB * _ARGB(Inst _x_) { return (Inst_ARGB *)_x_; }
   inline friend Inst_ARGD * _ARGD(Inst _x_) { return (Inst_ARGD *)_x_; }
   inline friend Inst_ARGF * _ARGF(Inst _x_) { return (Inst_ARGF *)_x_; }
   inline friend Inst_ARGI * _ARGI(Inst _x_) { return (Inst_ARGI *)_x_; }
   inline friend Inst_ARGP * _ARGP(Inst _x_) { return (Inst_ARGP *)_x_; }
   inline friend Inst_ASGNB * _ASGNB(Inst _x_) { return (Inst_ASGNB *)_x_; }
   inline friend Inst_ASGNC * _ASGNC(Inst _x_) { return (Inst_ASGNC *)_x_; }
   inline friend Inst_ASGND * _ASGND(Inst _x_) { return (Inst_ASGND *)_x_; }
   inline friend Inst_ASGNF * _ASGNF(Inst _x_) { return (Inst_ASGNF *)_x_; }
   inline friend Inst_ASGNI * _ASGNI(Inst _x_) { return (Inst_ASGNI *)_x_; }
   inline friend Inst_ASGNP * _ASGNP(Inst _x_) { return (Inst_ASGNP *)_x_; }
   inline friend Inst_ASGNS * _ASGNS(Inst _x_) { return (Inst_ASGNS *)_x_; }
   inline friend Inst_BANDU * _BANDU(Inst _x_) { return (Inst_BANDU *)_x_; }
   inline friend Inst_BCOMU * _BCOMU(Inst _x_) { return (Inst_BCOMU *)_x_; }
   inline friend Inst_BORU * _BORU(Inst _x_) { return (Inst_BORU *)_x_; }
   inline friend Inst_BXORU * _BXORU(Inst _x_) { return (Inst_BXORU *)_x_; }
   inline friend Inst_CALLB * _CALLB(Inst _x_) { return (Inst_CALLB *)_x_; }
   inline friend Inst_CALLD * _CALLD(Inst _x_) { return (Inst_CALLD *)_x_; }
   inline friend Inst_CALLF * _CALLF(Inst _x_) { return (Inst_CALLF *)_x_; }
   inline friend Inst_CALLI * _CALLI(Inst _x_) { return (Inst_CALLI *)_x_; }
   inline friend Inst_CALLV * _CALLV(Inst _x_) { return (Inst_CALLV *)_x_; }
   inline friend Inst_CNSTC * _CNSTC(Inst _x_) { return (Inst_CNSTC *)_x_; }
   inline friend Inst_CNSTD * _CNSTD(Inst _x_) { return (Inst_CNSTD *)_x_; }
   inline friend Inst_CNSTF * _CNSTF(Inst _x_) { return (Inst_CNSTF *)_x_; }
   inline friend Inst_CNSTI * _CNSTI(Inst _x_) { return (Inst_CNSTI *)_x_; }
   inline friend Inst_CNSTP * _CNSTP(Inst _x_) { return (Inst_CNSTP *)_x_; }
   inline friend Inst_CNSTS * _CNSTS(Inst _x_) { return (Inst_CNSTS *)_x_; }
   inline friend Inst_CNSTU * _CNSTU(Inst _x_) { return (Inst_CNSTU *)_x_; }
   inline friend Inst_CVCI * _CVCI(Inst _x_) { return (Inst_CVCI *)_x_; }
   inline friend Inst_CVCU * _CVCU(Inst _x_) { return (Inst_CVCU *)_x_; }
   inline friend Inst_CVDF * _CVDF(Inst _x_) { return (Inst_CVDF *)_x_; }
   inline friend Inst_CVDI * _CVDI(Inst _x_) { return (Inst_CVDI *)_x_; }
   inline friend Inst_CVFD * _CVFD(Inst _x_) { return (Inst_CVFD *)_x_; }
   inline friend Inst_CVIC * _CVIC(Inst _x_) { return (Inst_CVIC *)_x_; }
   inline friend Inst_CVID * _CVID(Inst _x_) { return (Inst_CVID *)_x_; }
   inline friend Inst_CVIS * _CVIS(Inst _x_) { return (Inst_CVIS *)_x_; }
   inline friend Inst_CVIU * _CVIU(Inst _x_) { return (Inst_CVIU *)_x_; }
   inline friend Inst_CVPU * _CVPU(Inst _x_) { return (Inst_CVPU *)_x_; }
   inline friend Inst_CVSI * _CVSI(Inst _x_) { return (Inst_CVSI *)_x_; }
   inline friend Inst_CVSU * _CVSU(Inst _x_) { return (Inst_CVSU *)_x_; }
   inline friend Inst_CVUC * _CVUC(Inst _x_) { return (Inst_CVUC *)_x_; }
   inline friend Inst_CVUI * _CVUI(Inst _x_) { return (Inst_CVUI *)_x_; }
   inline friend Inst_CVUP * _CVUP(Inst _x_) { return (Inst_CVUP *)_x_; }
   inline friend Inst_CVUS * _CVUS(Inst _x_) { return (Inst_CVUS *)_x_; }
   inline friend Inst_DIVD * _DIVD(Inst _x_) { return (Inst_DIVD *)_x_; }
   inline friend Inst_DIVF * _DIVF(Inst _x_) { return (Inst_DIVF *)_x_; }
   inline friend Inst_DIVI * _DIVI(Inst _x_) { return (Inst_DIVI *)_x_; }
   inline friend Inst_DIVU * _DIVU(Inst _x_) { return (Inst_DIVU *)_x_; }
   inline friend Inst_EQD * _EQD(Inst _x_) { return (Inst_EQD *)_x_; }
   inline friend Inst_EQF * _EQF(Inst _x_) { return (Inst_EQF *)_x_; }
   inline friend Inst_EQI * _EQI(Inst _x_) { return (Inst_EQI *)_x_; }
   inline friend Inst_GED * _GED(Inst _x_) { return (Inst_GED *)_x_; }
   inline friend Inst_GEF * _GEF(Inst _x_) { return (Inst_GEF *)_x_; }
   inline friend Inst_GEI * _GEI(Inst _x_) { return (Inst_GEI *)_x_; }
   inline friend Inst_GEU * _GEU(Inst _x_) { return (Inst_GEU *)_x_; }
   inline friend Inst_GTD * _GTD(Inst _x_) { return (Inst_GTD *)_x_; }
   inline friend Inst_GTF * _GTF(Inst _x_) { return (Inst_GTF *)_x_; }
   inline friend Inst_GTI * _GTI(Inst _x_) { return (Inst_GTI *)_x_; }
   inline friend Inst_GTU * _GTU(Inst _x_) { return (Inst_GTU *)_x_; }
   inline friend Inst_INDIRB * _INDIRB(Inst _x_) { return (Inst_INDIRB *)_x_; }
   inline friend Inst_INDIRC * _INDIRC(Inst _x_) { return (Inst_INDIRC *)_x_; }
   inline friend Inst_INDIRD * _INDIRD(Inst _x_) { return (Inst_INDIRD *)_x_; }
   inline friend Inst_INDIRF * _INDIRF(Inst _x_) { return (Inst_INDIRF *)_x_; }
   inline friend Inst_INDIRI * _INDIRI(Inst _x_) { return (Inst_INDIRI *)_x_; }
   inline friend Inst_INDIRP * _INDIRP(Inst _x_) { return (Inst_INDIRP *)_x_; }
   inline friend Inst_INDIRS * _INDIRS(Inst _x_) { return (Inst_INDIRS *)_x_; }
   inline friend Inst_JUMPV * _JUMPV(Inst _x_) { return (Inst_JUMPV *)_x_; }
   inline friend Inst_LABELV * _LABELV(Inst _x_) { return (Inst_LABELV *)_x_; }
   inline friend Inst_LED * _LED(Inst _x_) { return (Inst_LED *)_x_; }
   inline friend Inst_LEF * _LEF(Inst _x_) { return (Inst_LEF *)_x_; }
   inline friend Inst_LEI * _LEI(Inst _x_) { return (Inst_LEI *)_x_; }
   inline friend Inst_LEU * _LEU(Inst _x_) { return (Inst_LEU *)_x_; }
   inline friend Inst_LOADB * _LOADB(Inst _x_) { return (Inst_LOADB *)_x_; }
   inline friend Inst_LOADC * _LOADC(Inst _x_) { return (Inst_LOADC *)_x_; }
   inline friend Inst_LOADD * _LOADD(Inst _x_) { return (Inst_LOADD *)_x_; }
   inline friend Inst_LOADF * _LOADF(Inst _x_) { return (Inst_LOADF *)_x_; }
   inline friend Inst_LOADI * _LOADI(Inst _x_) { return (Inst_LOADI *)_x_; }
   inline friend Inst_LOADP * _LOADP(Inst _x_) { return (Inst_LOADP *)_x_; }
   inline friend Inst_LOADS * _LOADS(Inst _x_) { return (Inst_LOADS *)_x_; }
   inline friend Inst_LOADU * _LOADU(Inst _x_) { return (Inst_LOADU *)_x_; }
   inline friend Inst_LSHI * _LSHI(Inst _x_) { return (Inst_LSHI *)_x_; }
   inline friend Inst_LSHU * _LSHU(Inst _x_) { return (Inst_LSHU *)_x_; }
   inline friend Inst_LTD * _LTD(Inst _x_) { return (Inst_LTD *)_x_; }
   inline friend Inst_LTF * _LTF(Inst _x_) { return (Inst_LTF *)_x_; }
   inline friend Inst_LTI * _LTI(Inst _x_) { return (Inst_LTI *)_x_; }
   inline friend Inst_LTU * _LTU(Inst _x_) { return (Inst_LTU *)_x_; }
   inline friend Inst_MODI * _MODI(Inst _x_) { return (Inst_MODI *)_x_; }
   inline friend Inst_MODU * _MODU(Inst _x_) { return (Inst_MODU *)_x_; }
   inline friend Inst_MULD * _MULD(Inst _x_) { return (Inst_MULD *)_x_; }
   inline friend Inst_MULF * _MULF(Inst _x_) { return (Inst_MULF *)_x_; }
   inline friend Inst_MULI * _MULI(Inst _x_) { return (Inst_MULI *)_x_; }
   inline friend Inst_MULU * _MULU(Inst _x_) { return (Inst_MULU *)_x_; }
   inline friend Inst_NED * _NED(Inst _x_) { return (Inst_NED *)_x_; }
   inline friend Inst_NEF * _NEF(Inst _x_) { return (Inst_NEF *)_x_; }
   inline friend Inst_NEI * _NEI(Inst _x_) { return (Inst_NEI *)_x_; }
   inline friend Inst_NEGD * _NEGD(Inst _x_) { return (Inst_NEGD *)_x_; }
   inline friend Inst_NEGF * _NEGF(Inst _x_) { return (Inst_NEGF *)_x_; }
   inline friend Inst_NEGI * _NEGI(Inst _x_) { return (Inst_NEGI *)_x_; }
   inline friend Inst_RETD * _RETD(Inst _x_) { return (Inst_RETD *)_x_; }
   inline friend Inst_RETF * _RETF(Inst _x_) { return (Inst_RETF *)_x_; }
   inline friend Inst_RETI * _RETI(Inst _x_) { return (Inst_RETI *)_x_; }
   inline friend Inst_RSHI * _RSHI(Inst _x_) { return (Inst_RSHI *)_x_; }
   inline friend Inst_RSHU * _RSHU(Inst _x_) { return (Inst_RSHU *)_x_; }
   inline friend Inst_SUBD * _SUBD(Inst _x_) { return (Inst_SUBD *)_x_; }
   inline friend Inst_SUBF * _SUBF(Inst _x_) { return (Inst_SUBF *)_x_; }
   inline friend Inst_SUBI * _SUBI(Inst _x_) { return (Inst_SUBI *)_x_; }
   inline friend Inst_SUBP * _SUBP(Inst _x_) { return (Inst_SUBP *)_x_; }
   inline friend Inst_SUBU * _SUBU(Inst _x_) { return (Inst_SUBU *)_x_; }
   inline friend Inst_VREGP * _VREGP(Inst _x_) { return (Inst_VREGP *)_x_; }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ADDD (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_ADDD : public a_Inst {
public:
#line 1 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_ADDD (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_ADDD), _1(_x1), _2(_x2) {}
   inline friend a_Inst * ADDD (Inst _x1, Inst _x2)
      { return new Inst_ADDD (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ADDF (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_ADDF : public a_Inst {
public:
#line 2 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_ADDF (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_ADDF), _1(_x1), _2(_x2) {}
   inline friend a_Inst * ADDF (Inst _x1, Inst _x2)
      { return new Inst_ADDF (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ADDI (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_ADDI : public a_Inst {
public:
#line 2 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_ADDI (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_ADDI), _1(_x1), _2(_x2) {}
   inline friend a_Inst * ADDI (Inst _x1, Inst _x2)
      { return new Inst_ADDI (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ADDP (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_ADDP : public a_Inst {
public:
#line 3 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_ADDP (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_ADDP), _1(_x1), _2(_x2) {}
   inline friend a_Inst * ADDP (Inst _x1, Inst _x2)
      { return new Inst_ADDP (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ADDU (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_ADDU : public a_Inst {
public:
#line 3 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_ADDU (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_ADDU), _1(_x1), _2(_x2) {}
   inline friend a_Inst * ADDU (Inst _x1, Inst _x2)
      { return new Inst_ADDU (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ADDRFP ()'
///////////////////////////////////////////////////////////////////////////////
class Inst_ADDRFP : public a_Inst {
public:
#line 4 "sparc.pC"
   
   inline Inst_ADDRFP ()
      : a_Inst(a_Inst::tag_ADDRFP) {}
   inline friend a_Inst * ADDRFP ()
      { return new Inst_ADDRFP ; }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ADDRGP ()'
///////////////////////////////////////////////////////////////////////////////
class Inst_ADDRGP : public a_Inst {
public:
#line 4 "sparc.pC"
   
   inline Inst_ADDRGP ()
      : a_Inst(a_Inst::tag_ADDRGP) {}
   inline friend a_Inst * ADDRGP ()
      { return new Inst_ADDRGP ; }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ADDRLP ()'
///////////////////////////////////////////////////////////////////////////////
class Inst_ADDRLP : public a_Inst {
public:
#line 4 "sparc.pC"
   
   inline Inst_ADDRLP ()
      : a_Inst(a_Inst::tag_ADDRLP) {}
   inline friend a_Inst * ADDRLP ()
      { return new Inst_ADDRLP ; }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ARGB Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_ARGB : public a_Inst {
public:
#line 5 "sparc.pC"
   Inst ARGB; 
   inline Inst_ARGB (Inst _xARGB)
      : a_Inst(a_Inst::tag_ARGB), ARGB(_xARGB) {}
   inline friend a_Inst * ARGB (Inst _xARGB)
      { return new Inst_ARGB (_xARGB); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ARGD Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_ARGD : public a_Inst {
public:
#line 5 "sparc.pC"
   Inst ARGD; 
   inline Inst_ARGD (Inst _xARGD)
      : a_Inst(a_Inst::tag_ARGD), ARGD(_xARGD) {}
   inline friend a_Inst * ARGD (Inst _xARGD)
      { return new Inst_ARGD (_xARGD); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ARGF Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_ARGF : public a_Inst {
public:
#line 5 "sparc.pC"
   Inst ARGF; 
   inline Inst_ARGF (Inst _xARGF)
      : a_Inst(a_Inst::tag_ARGF), ARGF(_xARGF) {}
   inline friend a_Inst * ARGF (Inst _xARGF)
      { return new Inst_ARGF (_xARGF); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ARGI Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_ARGI : public a_Inst {
public:
#line 5 "sparc.pC"
   Inst ARGI; 
   inline Inst_ARGI (Inst _xARGI)
      : a_Inst(a_Inst::tag_ARGI), ARGI(_xARGI) {}
   inline friend a_Inst * ARGI (Inst _xARGI)
      { return new Inst_ARGI (_xARGI); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ARGP Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_ARGP : public a_Inst {
public:
#line 5 "sparc.pC"
   Inst ARGP; 
   inline Inst_ARGP (Inst _xARGP)
      : a_Inst(a_Inst::tag_ARGP), ARGP(_xARGP) {}
   inline friend a_Inst * ARGP (Inst _xARGP)
      { return new Inst_ARGP (_xARGP); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ASGNB (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_ASGNB : public a_Inst {
public:
#line 6 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_ASGNB (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_ASGNB), _1(_x1), _2(_x2) {}
   inline friend a_Inst * ASGNB (Inst _x1, Inst _x2)
      { return new Inst_ASGNB (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ASGNC (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_ASGNC : public a_Inst {
public:
#line 6 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_ASGNC (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_ASGNC), _1(_x1), _2(_x2) {}
   inline friend a_Inst * ASGNC (Inst _x1, Inst _x2)
      { return new Inst_ASGNC (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ASGND (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_ASGND : public a_Inst {
public:
#line 6 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_ASGND (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_ASGND), _1(_x1), _2(_x2) {}
   inline friend a_Inst * ASGND (Inst _x1, Inst _x2)
      { return new Inst_ASGND (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ASGNF (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_ASGNF : public a_Inst {
public:
#line 7 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_ASGNF (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_ASGNF), _1(_x1), _2(_x2) {}
   inline friend a_Inst * ASGNF (Inst _x1, Inst _x2)
      { return new Inst_ASGNF (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ASGNI (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_ASGNI : public a_Inst {
public:
#line 7 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_ASGNI (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_ASGNI), _1(_x1), _2(_x2) {}
   inline friend a_Inst * ASGNI (Inst _x1, Inst _x2)
      { return new Inst_ASGNI (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ASGNP (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_ASGNP : public a_Inst {
public:
#line 7 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_ASGNP (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_ASGNP), _1(_x1), _2(_x2) {}
   inline friend a_Inst * ASGNP (Inst _x1, Inst _x2)
      { return new Inst_ASGNP (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::ASGNS (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_ASGNS : public a_Inst {
public:
#line 7 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_ASGNS (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_ASGNS), _1(_x1), _2(_x2) {}
   inline friend a_Inst * ASGNS (Inst _x1, Inst _x2)
      { return new Inst_ASGNS (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::BANDU (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_BANDU : public a_Inst {
public:
#line 8 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_BANDU (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_BANDU), _1(_x1), _2(_x2) {}
   inline friend a_Inst * BANDU (Inst _x1, Inst _x2)
      { return new Inst_BANDU (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::BCOMU Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_BCOMU : public a_Inst {
public:
#line 8 "sparc.pC"
   Inst BCOMU; 
   inline Inst_BCOMU (Inst _xBCOMU)
      : a_Inst(a_Inst::tag_BCOMU), BCOMU(_xBCOMU) {}
   inline friend a_Inst * BCOMU (Inst _xBCOMU)
      { return new Inst_BCOMU (_xBCOMU); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::BORU (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_BORU : public a_Inst {
public:
#line 8 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_BORU (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_BORU), _1(_x1), _2(_x2) {}
   inline friend a_Inst * BORU (Inst _x1, Inst _x2)
      { return new Inst_BORU (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::BXORU (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_BXORU : public a_Inst {
public:
#line 8 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_BXORU (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_BXORU), _1(_x1), _2(_x2) {}
   inline friend a_Inst * BXORU (Inst _x1, Inst _x2)
      { return new Inst_BXORU (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CALLB (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_CALLB : public a_Inst {
public:
#line 9 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_CALLB (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_CALLB), _1(_x1), _2(_x2) {}
   inline friend a_Inst * CALLB (Inst _x1, Inst _x2)
      { return new Inst_CALLB (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CALLD Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CALLD : public a_Inst {
public:
#line 9 "sparc.pC"
   Inst CALLD; 
   inline Inst_CALLD (Inst _xCALLD)
      : a_Inst(a_Inst::tag_CALLD), CALLD(_xCALLD) {}
   inline friend a_Inst * CALLD (Inst _xCALLD)
      { return new Inst_CALLD (_xCALLD); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CALLF Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CALLF : public a_Inst {
public:
#line 9 "sparc.pC"
   Inst CALLF; 
   inline Inst_CALLF (Inst _xCALLF)
      : a_Inst(a_Inst::tag_CALLF), CALLF(_xCALLF) {}
   inline friend a_Inst * CALLF (Inst _xCALLF)
      { return new Inst_CALLF (_xCALLF); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CALLI Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CALLI : public a_Inst {
public:
#line 9 "sparc.pC"
   Inst CALLI; 
   inline Inst_CALLI (Inst _xCALLI)
      : a_Inst(a_Inst::tag_CALLI), CALLI(_xCALLI) {}
   inline friend a_Inst * CALLI (Inst _xCALLI)
      { return new Inst_CALLI (_xCALLI); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CALLV Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CALLV : public a_Inst {
public:
#line 9 "sparc.pC"
   Inst CALLV; 
   inline Inst_CALLV (Inst _xCALLV)
      : a_Inst(a_Inst::tag_CALLV), CALLV(_xCALLV) {}
   inline friend a_Inst * CALLV (Inst _xCALLV)
      { return new Inst_CALLV (_xCALLV); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CNSTC ()'
///////////////////////////////////////////////////////////////////////////////
class Inst_CNSTC : public a_Inst {
public:
#line 10 "sparc.pC"
   
   inline Inst_CNSTC ()
      : a_Inst(a_Inst::tag_CNSTC) {}
   inline friend a_Inst * CNSTC ()
      { return new Inst_CNSTC ; }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CNSTD ()'
///////////////////////////////////////////////////////////////////////////////
class Inst_CNSTD : public a_Inst {
public:
#line 10 "sparc.pC"
   
   inline Inst_CNSTD ()
      : a_Inst(a_Inst::tag_CNSTD) {}
   inline friend a_Inst * CNSTD ()
      { return new Inst_CNSTD ; }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CNSTF ()'
///////////////////////////////////////////////////////////////////////////////
class Inst_CNSTF : public a_Inst {
public:
#line 10 "sparc.pC"
   
   inline Inst_CNSTF ()
      : a_Inst(a_Inst::tag_CNSTF) {}
   inline friend a_Inst * CNSTF ()
      { return new Inst_CNSTF ; }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CNSTI ()'
///////////////////////////////////////////////////////////////////////////////
class Inst_CNSTI : public a_Inst {
public:
#line 10 "sparc.pC"
   
   inline Inst_CNSTI ()
      : a_Inst(a_Inst::tag_CNSTI) {}
   inline friend a_Inst * CNSTI ()
      { return new Inst_CNSTI ; }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CNSTP ()'
///////////////////////////////////////////////////////////////////////////////
class Inst_CNSTP : public a_Inst {
public:
#line 10 "sparc.pC"
   
   inline Inst_CNSTP ()
      : a_Inst(a_Inst::tag_CNSTP) {}
   inline friend a_Inst * CNSTP ()
      { return new Inst_CNSTP ; }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CNSTS ()'
///////////////////////////////////////////////////////////////////////////////
class Inst_CNSTS : public a_Inst {
public:
#line 10 "sparc.pC"
   
   inline Inst_CNSTS ()
      : a_Inst(a_Inst::tag_CNSTS) {}
   inline friend a_Inst * CNSTS ()
      { return new Inst_CNSTS ; }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CNSTU ()'
///////////////////////////////////////////////////////////////////////////////
class Inst_CNSTU : public a_Inst {
public:
#line 10 "sparc.pC"
   
   inline Inst_CNSTU ()
      : a_Inst(a_Inst::tag_CNSTU) {}
   inline friend a_Inst * CNSTU ()
      { return new Inst_CNSTU ; }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CVCI Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CVCI : public a_Inst {
public:
#line 11 "sparc.pC"
   Inst CVCI; 
   inline Inst_CVCI (Inst _xCVCI)
      : a_Inst(a_Inst::tag_CVCI), CVCI(_xCVCI) {}
   inline friend a_Inst * CVCI (Inst _xCVCI)
      { return new Inst_CVCI (_xCVCI); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CVCU Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CVCU : public a_Inst {
public:
#line 11 "sparc.pC"
   Inst CVCU; 
   inline Inst_CVCU (Inst _xCVCU)
      : a_Inst(a_Inst::tag_CVCU), CVCU(_xCVCU) {}
   inline friend a_Inst * CVCU (Inst _xCVCU)
      { return new Inst_CVCU (_xCVCU); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CVDF Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CVDF : public a_Inst {
public:
#line 11 "sparc.pC"
   Inst CVDF; 
   inline Inst_CVDF (Inst _xCVDF)
      : a_Inst(a_Inst::tag_CVDF), CVDF(_xCVDF) {}
   inline friend a_Inst * CVDF (Inst _xCVDF)
      { return new Inst_CVDF (_xCVDF); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CVDI Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CVDI : public a_Inst {
public:
#line 11 "sparc.pC"
   Inst CVDI; 
   inline Inst_CVDI (Inst _xCVDI)
      : a_Inst(a_Inst::tag_CVDI), CVDI(_xCVDI) {}
   inline friend a_Inst * CVDI (Inst _xCVDI)
      { return new Inst_CVDI (_xCVDI); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CVFD Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CVFD : public a_Inst {
public:
#line 11 "sparc.pC"
   Inst CVFD; 
   inline Inst_CVFD (Inst _xCVFD)
      : a_Inst(a_Inst::tag_CVFD), CVFD(_xCVFD) {}
   inline friend a_Inst * CVFD (Inst _xCVFD)
      { return new Inst_CVFD (_xCVFD); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CVIC Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CVIC : public a_Inst {
public:
#line 12 "sparc.pC"
   Inst CVIC; 
   inline Inst_CVIC (Inst _xCVIC)
      : a_Inst(a_Inst::tag_CVIC), CVIC(_xCVIC) {}
   inline friend a_Inst * CVIC (Inst _xCVIC)
      { return new Inst_CVIC (_xCVIC); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CVID Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CVID : public a_Inst {
public:
#line 12 "sparc.pC"
   Inst CVID; 
   inline Inst_CVID (Inst _xCVID)
      : a_Inst(a_Inst::tag_CVID), CVID(_xCVID) {}
   inline friend a_Inst * CVID (Inst _xCVID)
      { return new Inst_CVID (_xCVID); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CVIS Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CVIS : public a_Inst {
public:
#line 12 "sparc.pC"
   Inst CVIS; 
   inline Inst_CVIS (Inst _xCVIS)
      : a_Inst(a_Inst::tag_CVIS), CVIS(_xCVIS) {}
   inline friend a_Inst * CVIS (Inst _xCVIS)
      { return new Inst_CVIS (_xCVIS); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CVIU Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CVIU : public a_Inst {
public:
#line 12 "sparc.pC"
   Inst CVIU; 
   inline Inst_CVIU (Inst _xCVIU)
      : a_Inst(a_Inst::tag_CVIU), CVIU(_xCVIU) {}
   inline friend a_Inst * CVIU (Inst _xCVIU)
      { return new Inst_CVIU (_xCVIU); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CVPU Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CVPU : public a_Inst {
public:
#line 12 "sparc.pC"
   Inst CVPU; 
   inline Inst_CVPU (Inst _xCVPU)
      : a_Inst(a_Inst::tag_CVPU), CVPU(_xCVPU) {}
   inline friend a_Inst * CVPU (Inst _xCVPU)
      { return new Inst_CVPU (_xCVPU); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CVSI Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CVSI : public a_Inst {
public:
#line 13 "sparc.pC"
   Inst CVSI; 
   inline Inst_CVSI (Inst _xCVSI)
      : a_Inst(a_Inst::tag_CVSI), CVSI(_xCVSI) {}
   inline friend a_Inst * CVSI (Inst _xCVSI)
      { return new Inst_CVSI (_xCVSI); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CVSU Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CVSU : public a_Inst {
public:
#line 13 "sparc.pC"
   Inst CVSU; 
   inline Inst_CVSU (Inst _xCVSU)
      : a_Inst(a_Inst::tag_CVSU), CVSU(_xCVSU) {}
   inline friend a_Inst * CVSU (Inst _xCVSU)
      { return new Inst_CVSU (_xCVSU); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CVUC Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CVUC : public a_Inst {
public:
#line 14 "sparc.pC"
   Inst CVUC; 
   inline Inst_CVUC (Inst _xCVUC)
      : a_Inst(a_Inst::tag_CVUC), CVUC(_xCVUC) {}
   inline friend a_Inst * CVUC (Inst _xCVUC)
      { return new Inst_CVUC (_xCVUC); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CVUI Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CVUI : public a_Inst {
public:
#line 14 "sparc.pC"
   Inst CVUI; 
   inline Inst_CVUI (Inst _xCVUI)
      : a_Inst(a_Inst::tag_CVUI), CVUI(_xCVUI) {}
   inline friend a_Inst * CVUI (Inst _xCVUI)
      { return new Inst_CVUI (_xCVUI); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CVUP Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CVUP : public a_Inst {
public:
#line 14 "sparc.pC"
   Inst CVUP; 
   inline Inst_CVUP (Inst _xCVUP)
      : a_Inst(a_Inst::tag_CVUP), CVUP(_xCVUP) {}
   inline friend a_Inst * CVUP (Inst _xCVUP)
      { return new Inst_CVUP (_xCVUP); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::CVUS Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_CVUS : public a_Inst {
public:
#line 14 "sparc.pC"
   Inst CVUS; 
   inline Inst_CVUS (Inst _xCVUS)
      : a_Inst(a_Inst::tag_CVUS), CVUS(_xCVUS) {}
   inline friend a_Inst * CVUS (Inst _xCVUS)
      { return new Inst_CVUS (_xCVUS); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::DIVD (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_DIVD : public a_Inst {
public:
#line 15 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_DIVD (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_DIVD), _1(_x1), _2(_x2) {}
   inline friend a_Inst * DIVD (Inst _x1, Inst _x2)
      { return new Inst_DIVD (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::DIVF (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_DIVF : public a_Inst {
public:
#line 15 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_DIVF (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_DIVF), _1(_x1), _2(_x2) {}
   inline friend a_Inst * DIVF (Inst _x1, Inst _x2)
      { return new Inst_DIVF (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::DIVI (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_DIVI : public a_Inst {
public:
#line 15 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_DIVI (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_DIVI), _1(_x1), _2(_x2) {}
   inline friend a_Inst * DIVI (Inst _x1, Inst _x2)
      { return new Inst_DIVI (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::DIVU (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_DIVU : public a_Inst {
public:
#line 15 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_DIVU (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_DIVU), _1(_x1), _2(_x2) {}
   inline friend a_Inst * DIVU (Inst _x1, Inst _x2)
      { return new Inst_DIVU (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::EQD (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_EQD : public a_Inst {
public:
#line 16 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_EQD (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_EQD), _1(_x1), _2(_x2) {}
   inline friend a_Inst * EQD (Inst _x1, Inst _x2)
      { return new Inst_EQD (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::EQF (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_EQF : public a_Inst {
public:
#line 16 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_EQF (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_EQF), _1(_x1), _2(_x2) {}
   inline friend a_Inst * EQF (Inst _x1, Inst _x2)
      { return new Inst_EQF (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::EQI (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_EQI : public a_Inst {
public:
#line 16 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_EQI (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_EQI), _1(_x1), _2(_x2) {}
   inline friend a_Inst * EQI (Inst _x1, Inst _x2)
      { return new Inst_EQI (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::GED (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_GED : public a_Inst {
public:
#line 17 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_GED (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_GED), _1(_x1), _2(_x2) {}
   inline friend a_Inst * GED (Inst _x1, Inst _x2)
      { return new Inst_GED (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::GEF (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_GEF : public a_Inst {
public:
#line 17 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_GEF (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_GEF), _1(_x1), _2(_x2) {}
   inline friend a_Inst * GEF (Inst _x1, Inst _x2)
      { return new Inst_GEF (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::GEI (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_GEI : public a_Inst {
public:
#line 17 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_GEI (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_GEI), _1(_x1), _2(_x2) {}
   inline friend a_Inst * GEI (Inst _x1, Inst _x2)
      { return new Inst_GEI (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::GEU (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_GEU : public a_Inst {
public:
#line 17 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_GEU (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_GEU), _1(_x1), _2(_x2) {}
   inline friend a_Inst * GEU (Inst _x1, Inst _x2)
      { return new Inst_GEU (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::GTD (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_GTD : public a_Inst {
public:
#line 18 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_GTD (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_GTD), _1(_x1), _2(_x2) {}
   inline friend a_Inst * GTD (Inst _x1, Inst _x2)
      { return new Inst_GTD (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::GTF (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_GTF : public a_Inst {
public:
#line 18 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_GTF (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_GTF), _1(_x1), _2(_x2) {}
   inline friend a_Inst * GTF (Inst _x1, Inst _x2)
      { return new Inst_GTF (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::GTI (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_GTI : public a_Inst {
public:
#line 18 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_GTI (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_GTI), _1(_x1), _2(_x2) {}
   inline friend a_Inst * GTI (Inst _x1, Inst _x2)
      { return new Inst_GTI (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::GTU (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_GTU : public a_Inst {
public:
#line 18 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_GTU (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_GTU), _1(_x1), _2(_x2) {}
   inline friend a_Inst * GTU (Inst _x1, Inst _x2)
      { return new Inst_GTU (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::INDIRB Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_INDIRB : public a_Inst {
public:
#line 19 "sparc.pC"
   Inst INDIRB; 
   inline Inst_INDIRB (Inst _xINDIRB)
      : a_Inst(a_Inst::tag_INDIRB), INDIRB(_xINDIRB) {}
   inline friend a_Inst * INDIRB (Inst _xINDIRB)
      { return new Inst_INDIRB (_xINDIRB); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::INDIRC Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_INDIRC : public a_Inst {
public:
#line 19 "sparc.pC"
   Inst INDIRC; 
   inline Inst_INDIRC (Inst _xINDIRC)
      : a_Inst(a_Inst::tag_INDIRC), INDIRC(_xINDIRC) {}
   inline friend a_Inst * INDIRC (Inst _xINDIRC)
      { return new Inst_INDIRC (_xINDIRC); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::INDIRD Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_INDIRD : public a_Inst {
public:
#line 19 "sparc.pC"
   Inst INDIRD; 
   inline Inst_INDIRD (Inst _xINDIRD)
      : a_Inst(a_Inst::tag_INDIRD), INDIRD(_xINDIRD) {}
   inline friend a_Inst * INDIRD (Inst _xINDIRD)
      { return new Inst_INDIRD (_xINDIRD); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::INDIRF Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_INDIRF : public a_Inst {
public:
#line 19 "sparc.pC"
   Inst INDIRF; 
   inline Inst_INDIRF (Inst _xINDIRF)
      : a_Inst(a_Inst::tag_INDIRF), INDIRF(_xINDIRF) {}
   inline friend a_Inst * INDIRF (Inst _xINDIRF)
      { return new Inst_INDIRF (_xINDIRF); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::INDIRI Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_INDIRI : public a_Inst {
public:
#line 20 "sparc.pC"
   Inst INDIRI; 
   inline Inst_INDIRI (Inst _xINDIRI)
      : a_Inst(a_Inst::tag_INDIRI), INDIRI(_xINDIRI) {}
   inline friend a_Inst * INDIRI (Inst _xINDIRI)
      { return new Inst_INDIRI (_xINDIRI); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::INDIRP Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_INDIRP : public a_Inst {
public:
#line 20 "sparc.pC"
   Inst INDIRP; 
   inline Inst_INDIRP (Inst _xINDIRP)
      : a_Inst(a_Inst::tag_INDIRP), INDIRP(_xINDIRP) {}
   inline friend a_Inst * INDIRP (Inst _xINDIRP)
      { return new Inst_INDIRP (_xINDIRP); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::INDIRS Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_INDIRS : public a_Inst {
public:
#line 20 "sparc.pC"
   Inst INDIRS; 
   inline Inst_INDIRS (Inst _xINDIRS)
      : a_Inst(a_Inst::tag_INDIRS), INDIRS(_xINDIRS) {}
   inline friend a_Inst * INDIRS (Inst _xINDIRS)
      { return new Inst_INDIRS (_xINDIRS); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::JUMPV Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_JUMPV : public a_Inst {
public:
#line 21 "sparc.pC"
   Inst JUMPV; 
   inline Inst_JUMPV (Inst _xJUMPV)
      : a_Inst(a_Inst::tag_JUMPV), JUMPV(_xJUMPV) {}
   inline friend a_Inst * JUMPV (Inst _xJUMPV)
      { return new Inst_JUMPV (_xJUMPV); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::LABELV ()'
///////////////////////////////////////////////////////////////////////////////
class Inst_LABELV : public a_Inst {
public:
#line 21 "sparc.pC"
   
   inline Inst_LABELV ()
      : a_Inst(a_Inst::tag_LABELV) {}
   inline friend a_Inst * LABELV ()
      { return new Inst_LABELV ; }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::LED (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_LED : public a_Inst {
public:
#line 22 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_LED (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_LED), _1(_x1), _2(_x2) {}
   inline friend a_Inst * LED (Inst _x1, Inst _x2)
      { return new Inst_LED (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::LEF (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_LEF : public a_Inst {
public:
#line 22 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_LEF (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_LEF), _1(_x1), _2(_x2) {}
   inline friend a_Inst * LEF (Inst _x1, Inst _x2)
      { return new Inst_LEF (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::LEI (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_LEI : public a_Inst {
public:
#line 22 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_LEI (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_LEI), _1(_x1), _2(_x2) {}
   inline friend a_Inst * LEI (Inst _x1, Inst _x2)
      { return new Inst_LEI (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::LEU (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_LEU : public a_Inst {
public:
#line 22 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_LEU (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_LEU), _1(_x1), _2(_x2) {}
   inline friend a_Inst * LEU (Inst _x1, Inst _x2)
      { return new Inst_LEU (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::LOADB Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_LOADB : public a_Inst {
public:
#line 23 "sparc.pC"
   Inst LOADB; 
   inline Inst_LOADB (Inst _xLOADB)
      : a_Inst(a_Inst::tag_LOADB), LOADB(_xLOADB) {}
   inline friend a_Inst * LOADB (Inst _xLOADB)
      { return new Inst_LOADB (_xLOADB); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::LOADC Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_LOADC : public a_Inst {
public:
#line 23 "sparc.pC"
   Inst LOADC; 
   inline Inst_LOADC (Inst _xLOADC)
      : a_Inst(a_Inst::tag_LOADC), LOADC(_xLOADC) {}
   inline friend a_Inst * LOADC (Inst _xLOADC)
      { return new Inst_LOADC (_xLOADC); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::LOADD Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_LOADD : public a_Inst {
public:
#line 23 "sparc.pC"
   Inst LOADD; 
   inline Inst_LOADD (Inst _xLOADD)
      : a_Inst(a_Inst::tag_LOADD), LOADD(_xLOADD) {}
   inline friend a_Inst * LOADD (Inst _xLOADD)
      { return new Inst_LOADD (_xLOADD); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::LOADF Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_LOADF : public a_Inst {
public:
#line 23 "sparc.pC"
   Inst LOADF; 
   inline Inst_LOADF (Inst _xLOADF)
      : a_Inst(a_Inst::tag_LOADF), LOADF(_xLOADF) {}
   inline friend a_Inst * LOADF (Inst _xLOADF)
      { return new Inst_LOADF (_xLOADF); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::LOADI Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_LOADI : public a_Inst {
public:
#line 24 "sparc.pC"
   Inst LOADI; 
   inline Inst_LOADI (Inst _xLOADI)
      : a_Inst(a_Inst::tag_LOADI), LOADI(_xLOADI) {}
   inline friend a_Inst * LOADI (Inst _xLOADI)
      { return new Inst_LOADI (_xLOADI); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::LOADP Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_LOADP : public a_Inst {
public:
#line 24 "sparc.pC"
   Inst LOADP; 
   inline Inst_LOADP (Inst _xLOADP)
      : a_Inst(a_Inst::tag_LOADP), LOADP(_xLOADP) {}
   inline friend a_Inst * LOADP (Inst _xLOADP)
      { return new Inst_LOADP (_xLOADP); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::LOADS Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_LOADS : public a_Inst {
public:
#line 24 "sparc.pC"
   Inst LOADS; 
   inline Inst_LOADS (Inst _xLOADS)
      : a_Inst(a_Inst::tag_LOADS), LOADS(_xLOADS) {}
   inline friend a_Inst * LOADS (Inst _xLOADS)
      { return new Inst_LOADS (_xLOADS); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::LOADU Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_LOADU : public a_Inst {
public:
#line 24 "sparc.pC"
   Inst LOADU; 
   inline Inst_LOADU (Inst _xLOADU)
      : a_Inst(a_Inst::tag_LOADU), LOADU(_xLOADU) {}
   inline friend a_Inst * LOADU (Inst _xLOADU)
      { return new Inst_LOADU (_xLOADU); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::LSHI (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_LSHI : public a_Inst {
public:
#line 25 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_LSHI (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_LSHI), _1(_x1), _2(_x2) {}
   inline friend a_Inst * LSHI (Inst _x1, Inst _x2)
      { return new Inst_LSHI (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::LSHU (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_LSHU : public a_Inst {
public:
#line 25 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_LSHU (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_LSHU), _1(_x1), _2(_x2) {}
   inline friend a_Inst * LSHU (Inst _x1, Inst _x2)
      { return new Inst_LSHU (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::LTD (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_LTD : public a_Inst {
public:
#line 26 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_LTD (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_LTD), _1(_x1), _2(_x2) {}
   inline friend a_Inst * LTD (Inst _x1, Inst _x2)
      { return new Inst_LTD (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::LTF (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_LTF : public a_Inst {
public:
#line 26 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_LTF (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_LTF), _1(_x1), _2(_x2) {}
   inline friend a_Inst * LTF (Inst _x1, Inst _x2)
      { return new Inst_LTF (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::LTI (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_LTI : public a_Inst {
public:
#line 26 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_LTI (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_LTI), _1(_x1), _2(_x2) {}
   inline friend a_Inst * LTI (Inst _x1, Inst _x2)
      { return new Inst_LTI (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::LTU (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_LTU : public a_Inst {
public:
#line 26 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_LTU (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_LTU), _1(_x1), _2(_x2) {}
   inline friend a_Inst * LTU (Inst _x1, Inst _x2)
      { return new Inst_LTU (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::MODI (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_MODI : public a_Inst {
public:
#line 27 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_MODI (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_MODI), _1(_x1), _2(_x2) {}
   inline friend a_Inst * MODI (Inst _x1, Inst _x2)
      { return new Inst_MODI (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::MODU (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_MODU : public a_Inst {
public:
#line 27 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_MODU (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_MODU), _1(_x1), _2(_x2) {}
   inline friend a_Inst * MODU (Inst _x1, Inst _x2)
      { return new Inst_MODU (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::MULD (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_MULD : public a_Inst {
public:
#line 28 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_MULD (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_MULD), _1(_x1), _2(_x2) {}
   inline friend a_Inst * MULD (Inst _x1, Inst _x2)
      { return new Inst_MULD (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::MULF (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_MULF : public a_Inst {
public:
#line 28 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_MULF (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_MULF), _1(_x1), _2(_x2) {}
   inline friend a_Inst * MULF (Inst _x1, Inst _x2)
      { return new Inst_MULF (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::MULI (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_MULI : public a_Inst {
public:
#line 28 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_MULI (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_MULI), _1(_x1), _2(_x2) {}
   inline friend a_Inst * MULI (Inst _x1, Inst _x2)
      { return new Inst_MULI (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::MULU (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_MULU : public a_Inst {
public:
#line 28 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_MULU (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_MULU), _1(_x1), _2(_x2) {}
   inline friend a_Inst * MULU (Inst _x1, Inst _x2)
      { return new Inst_MULU (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::NED (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_NED : public a_Inst {
public:
#line 29 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_NED (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_NED), _1(_x1), _2(_x2) {}
   inline friend a_Inst * NED (Inst _x1, Inst _x2)
      { return new Inst_NED (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::NEF (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_NEF : public a_Inst {
public:
#line 29 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_NEF (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_NEF), _1(_x1), _2(_x2) {}
   inline friend a_Inst * NEF (Inst _x1, Inst _x2)
      { return new Inst_NEF (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::NEI (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_NEI : public a_Inst {
public:
#line 29 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_NEI (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_NEI), _1(_x1), _2(_x2) {}
   inline friend a_Inst * NEI (Inst _x1, Inst _x2)
      { return new Inst_NEI (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::NEGD Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_NEGD : public a_Inst {
public:
#line 30 "sparc.pC"
   Inst NEGD; 
   inline Inst_NEGD (Inst _xNEGD)
      : a_Inst(a_Inst::tag_NEGD), NEGD(_xNEGD) {}
   inline friend a_Inst * NEGD (Inst _xNEGD)
      { return new Inst_NEGD (_xNEGD); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::NEGF Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_NEGF : public a_Inst {
public:
#line 30 "sparc.pC"
   Inst NEGF; 
   inline Inst_NEGF (Inst _xNEGF)
      : a_Inst(a_Inst::tag_NEGF), NEGF(_xNEGF) {}
   inline friend a_Inst * NEGF (Inst _xNEGF)
      { return new Inst_NEGF (_xNEGF); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::NEGI Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_NEGI : public a_Inst {
public:
#line 30 "sparc.pC"
   Inst NEGI; 
   inline Inst_NEGI (Inst _xNEGI)
      : a_Inst(a_Inst::tag_NEGI), NEGI(_xNEGI) {}
   inline friend a_Inst * NEGI (Inst _xNEGI)
      { return new Inst_NEGI (_xNEGI); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::RETD Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_RETD : public a_Inst {
public:
#line 31 "sparc.pC"
   Inst RETD; 
   inline Inst_RETD (Inst _xRETD)
      : a_Inst(a_Inst::tag_RETD), RETD(_xRETD) {}
   inline friend a_Inst * RETD (Inst _xRETD)
      { return new Inst_RETD (_xRETD); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::RETF Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_RETF : public a_Inst {
public:
#line 31 "sparc.pC"
   Inst RETF; 
   inline Inst_RETF (Inst _xRETF)
      : a_Inst(a_Inst::tag_RETF), RETF(_xRETF) {}
   inline friend a_Inst * RETF (Inst _xRETF)
      { return new Inst_RETF (_xRETF); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::RETI Inst'
///////////////////////////////////////////////////////////////////////////////
class Inst_RETI : public a_Inst {
public:
#line 31 "sparc.pC"
   Inst RETI; 
   inline Inst_RETI (Inst _xRETI)
      : a_Inst(a_Inst::tag_RETI), RETI(_xRETI) {}
   inline friend a_Inst * RETI (Inst _xRETI)
      { return new Inst_RETI (_xRETI); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::RSHI (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_RSHI : public a_Inst {
public:
#line 32 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_RSHI (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_RSHI), _1(_x1), _2(_x2) {}
   inline friend a_Inst * RSHI (Inst _x1, Inst _x2)
      { return new Inst_RSHI (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::RSHU (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_RSHU : public a_Inst {
public:
#line 32 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_RSHU (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_RSHU), _1(_x1), _2(_x2) {}
   inline friend a_Inst * RSHU (Inst _x1, Inst _x2)
      { return new Inst_RSHU (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::SUBD (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_SUBD : public a_Inst {
public:
#line 33 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_SUBD (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_SUBD), _1(_x1), _2(_x2) {}
   inline friend a_Inst * SUBD (Inst _x1, Inst _x2)
      { return new Inst_SUBD (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::SUBF (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_SUBF : public a_Inst {
public:
#line 33 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_SUBF (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_SUBF), _1(_x1), _2(_x2) {}
   inline friend a_Inst * SUBF (Inst _x1, Inst _x2)
      { return new Inst_SUBF (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::SUBI (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_SUBI : public a_Inst {
public:
#line 33 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_SUBI (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_SUBI), _1(_x1), _2(_x2) {}
   inline friend a_Inst * SUBI (Inst _x1, Inst _x2)
      { return new Inst_SUBI (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::SUBP (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_SUBP : public a_Inst {
public:
#line 34 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_SUBP (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_SUBP), _1(_x1), _2(_x2) {}
   inline friend a_Inst * SUBP (Inst _x1, Inst _x2)
      { return new Inst_SUBP (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::SUBU (Inst, Inst)'
///////////////////////////////////////////////////////////////////////////////
class Inst_SUBU : public a_Inst {
public:
#line 34 "sparc.pC"
   Inst _1; Inst _2; 
   inline Inst_SUBU (Inst _x1, Inst _x2)
      : a_Inst(a_Inst::tag_SUBU), _1(_x1), _2(_x2) {}
   inline friend a_Inst * SUBU (Inst _x1, Inst _x2)
      { return new Inst_SUBU (_x1, _x2); }
};

///////////////////////////////////////////////////////////////////////////////
// class for constructor 'Inst::VREGP ()'
///////////////////////////////////////////////////////////////////////////////
class Inst_VREGP : public a_Inst {
public:
#line 35 "sparc.pC"
   
   inline Inst_VREGP ()
      : a_Inst(a_Inst::tag_VREGP) {}
   inline friend a_Inst * VREGP ()
      { return new Inst_VREGP ; }
};

#line 36 "sparc.pC"
#line 36 "sparc.pC"


extern int move(Inst);
extern int range(Inst,int,int);
extern int imm(Inst);
extern int notarget(Inst);

void compile (Inst e)
{
#line 45 "sparc.pC"
#line 230 "sparc.pC"
   extern void  _s_p_a_r_cco_X1_rewrite(Inst & );
   _s_p_a_r_cco_X1_rewrite(e);
#line 231 "sparc.pC"
#line 231 "sparc.pC"

}
#line 233 "sparc.pC"
class _s_p_a_r_cco_X1 : public BURS {
private:
   _s_p_a_r_cco_X1(const _s_p_a_r_cco_X1&);               // no copy constructor
   void operator = (const _s_p_a_r_cco_X1&); // no assignment
public:
   struct _s_p_a_r_cco_X1_StateRec * stack__, * stack_top__;
          void labeler(Inst redex);
   inline virtual void operator () (Inst redex) { labeler(redex); }
          void  reduce(Inst redex,int lhs = 1);
private: 
   public:
      inline _s_p_a_r_cco_X1() {}
};
void  _s_p_a_r_cco_X1_rewrite(Inst &  _x_) 
{  _s_p_a_r_cco_X1 _r_;
   _r_(_x_); _r_.reduce(_x_);
}


///////////////////////////////////////////////////////////////////////////////
// State record for rewrite class _s_p_a_r_cco_X1
///////////////////////////////////////////////////////////////////////////////
struct _s_p_a_r_cco_X1_StateRec {
   TreeTables::Cost cost[16]; // cost for each non-terminal
   struct { // accept rule number
      unsigned int _call : 2;
      unsigned int _stk : 2;
      unsigned int _rc5 : 2;
      unsigned int _rc : 2;
      unsigned int _addrg : 2;
      unsigned int _addrl : 2;
      unsigned int _stk13 : 2;
      unsigned int _addr : 3;
      unsigned int _con13 : 3;
      unsigned int _stmt : 6;
      unsigned int _con : 3;
      unsigned int _reg : 7;
      unsigned int _spill : 2;
      unsigned int _rel : 4;
      unsigned int _base : 3;
   } rule;
};

///////////////////////////////////////////////////////////////////////////////
// Accept rules tables for rewrite class _s_p_a_r_cco_X1
///////////////////////////////////////////////////////////////////////////////
const char _s_p_a_r_cco_X1_base_accept[] = { -1, 40, 39, 38, 37, 36, 35 };

const short _s_p_a_r_cco_X1_call_accept[] = { -1, 136, 135 };

const char _s_p_a_r_cco_X1_rc5_accept[] = { -1, 107, 106 };

const char _s_p_a_r_cco_X1_rc_accept[] = { -1, 96, 95 };

const char _s_p_a_r_cco_X1_addrg_accept[] = { -1, 121 };

const char _s_p_a_r_cco_X1_addrl_accept[] = { -1, 56 };

const char _s_p_a_r_cco_X1_stk13_accept[] = { -1, 24, 23 };

const char _s_p_a_r_cco_X1_addr_accept[] = { -1, 45, 44, 43, 42, 41 };

const char _s_p_a_r_cco_X1_con13_accept[] = { -1, 34, 33, 32, 31, 30 };

const short _s_p_a_r_cco_X1_stmt_accept[] = { -1, 184, 181, 148, 147, 146, 145, 144, 143, 142, 141, 140, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 122, 67, 66, 65, 64, 63, 62, 60, 58, 55, 54, 53, 52, 51, 17, 11, 10, 9, 8, 7, 6 };

const char _s_p_a_r_cco_X1_con_accept[] = { -1, 16, 15, 14, 13, 12 };

const short _s_p_a_r_cco_X1_reg_accept[] = { -1, 183, 182, 168, 167, 166, 165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151, 150, 149, 139, 138, 137, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 105, 104, 103, 102, 101, 100, 99, 98, 97, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 59, 57, 50, 49, 48, 47, 46, 29, 28, 25, 22, 21, 20, 19, 18, 5, 4, 3, 2, 1, 0 };

const char _s_p_a_r_cco_X1_spill_accept[] = { -1, 61 };

const short _s_p_a_r_cco_X1_rel_accept[] = { -1, 180, 179, 178, 177, 176, 175, 174, 173, 172, 171, 170, 169 };

const char _s_p_a_r_cco_X1_stk_accept[] = { -1, 27, 26 };

///////////////////////////////////////////////////////////////////////////////
// Closure methods for rewrite class _s_p_a_r_cco_X1
///////////////////////////////////////////////////////////////////////////////
static void _s_p_a_r_cco_X1_stk_closure(Inst redex,int cost);
static void _s_p_a_r_cco_X1_stk13_closure(Inst redex,int cost);
static void _s_p_a_r_cco_X1_addr_closure(Inst redex,int cost);
static void _s_p_a_r_cco_X1_con13_closure(Inst redex,int cost);
static void _s_p_a_r_cco_X1_con_closure(Inst redex,int cost);
static void _s_p_a_r_cco_X1_reg_closure(Inst redex,int cost);
static void _s_p_a_r_cco_X1_rel_closure(Inst redex,int cost);
static void _s_p_a_r_cco_X1_base_closure(Inst redex,int cost);

static void _s_p_a_r_cco_X1_stk_closure(Inst redex,int cost__)
{
   _s_p_a_r_cco_X1_StateRec * _state_rec = (_s_p_a_r_cco_X1_StateRec *)(redex->get_state_rec());
   if (cost__ + 0 < _state_rec->cost[8])
   {  _state_rec->cost[8] = cost__ + 0;
      _state_rec->rule._addr = 1;
      _s_p_a_r_cco_X1_addr_closure(redex,cost__ + 0);
   }
}

static void _s_p_a_r_cco_X1_stk13_closure(Inst redex,int cost__)
{
   _s_p_a_r_cco_X1_StateRec * _state_rec = (_s_p_a_r_cco_X1_StateRec *)(redex->get_state_rec());
   if (cost__ + 1 < _state_rec->cost[1])
   {  _state_rec->cost[1] = cost__ + 1;
      _state_rec->rule._reg = 1;
      _s_p_a_r_cco_X1_reg_closure(redex,cost__ + 1);
   }
   if (cost__ + 0 < _state_rec->cost[7])
   {  _state_rec->cost[7] = cost__ + 0;
      _state_rec->rule._base = 2;
      _s_p_a_r_cco_X1_base_closure(redex,cost__ + 0);
   }
}

static void _s_p_a_r_cco_X1_addr_closure(Inst redex,int cost__)
{
   _s_p_a_r_cco_X1_StateRec * _state_rec = (_s_p_a_r_cco_X1_StateRec *)(redex->get_state_rec());
   if (cost__ + 0 < _state_rec->cost[14])
   {  _state_rec->cost[14] = cost__ + 0;
      _state_rec->rule._call = 1;
   }
}

static void _s_p_a_r_cco_X1_con13_closure(Inst redex,int cost__)
{
   _s_p_a_r_cco_X1_StateRec * _state_rec = (_s_p_a_r_cco_X1_StateRec *)(redex->get_state_rec());
   if (cost__ + 0 < _state_rec->cost[7])
   {  _state_rec->cost[7] = cost__ + 0;
      _state_rec->rule._base = 1;
      _s_p_a_r_cco_X1_base_closure(redex,cost__ + 0);
   }
   if (cost__ + 0 < _state_rec->cost[11])
   {  _state_rec->cost[11] = cost__ + 0;
      _state_rec->rule._rc = 2;
   }
}

static void _s_p_a_r_cco_X1_con_closure(Inst redex,int cost__)
{
   _s_p_a_r_cco_X1_StateRec * _state_rec = (_s_p_a_r_cco_X1_StateRec *)(redex->get_state_rec());
   if (cost__ + 1 < _state_rec->cost[1])
   {  _state_rec->cost[1] = cost__ + 1;
      _state_rec->rule._reg = 1;
      _s_p_a_r_cco_X1_reg_closure(redex,cost__ + 1);
   }
}

static void _s_p_a_r_cco_X1_reg_closure(Inst redex,int cost__)
{
   _s_p_a_r_cco_X1_StateRec * _state_rec = (_s_p_a_r_cco_X1_StateRec *)(redex->get_state_rec());
   if (cost__ + 0 < _state_rec->cost[2])
   {  _state_rec->cost[2] = cost__ + 0;
      _state_rec->rule._stmt = 1;
   }
   if (cost__ + 0 < _state_rec->cost[7])
   {  _state_rec->cost[7] = cost__ + 0;
      _state_rec->rule._base = 2;
      _s_p_a_r_cco_X1_base_closure(redex,cost__ + 0);
   }
   if (cost__ + 0 < _state_rec->cost[11])
   {  _state_rec->cost[11] = cost__ + 0;
      _state_rec->rule._rc = 3;
   }
   if (cost__ + 0 < _state_rec->cost[12])
   {  _state_rec->cost[12] = cost__ + 0;
      _state_rec->rule._rc5 = 4;
   }
}

static void _s_p_a_r_cco_X1_rel_closure(Inst redex,int cost__)
{
   _s_p_a_r_cco_X1_StateRec * _state_rec = (_s_p_a_r_cco_X1_StateRec *)(redex->get_state_rec());
   if (cost__ + 4 < _state_rec->cost[2])
   {  _state_rec->cost[2] = cost__ + 4;
      _state_rec->rule._stmt = 1;
   }
}

static void _s_p_a_r_cco_X1_base_closure(Inst redex,int cost__)
{
   _s_p_a_r_cco_X1_StateRec * _state_rec = (_s_p_a_r_cco_X1_StateRec *)(redex->get_state_rec());
   if (cost__ + 0 < _state_rec->cost[8])
   {  _state_rec->cost[8] = cost__ + 0;
      _state_rec->rule._addr = 1;
      _s_p_a_r_cco_X1_addr_closure(redex,cost__ + 0);
   }
}

void _s_p_a_r_cco_X1::labeler (Inst redex)
{
   int cost__;
   _s_p_a_r_cco_X1_StateRec * _state_rec = (_s_p_a_r_cco_X1_StateRec *)mem[sizeof(_s_p_a_r_cco_X1_StateRec)];
   redex->set_state_rec(_state_rec);
   _state_rec->cost[0] = 0;
   _state_rec->cost[1] = 
   _state_rec->cost[2] = 
   _state_rec->cost[3] = 
   _state_rec->cost[4] = 
   _state_rec->cost[5] = 
   _state_rec->cost[6] = 
   _state_rec->cost[7] = 
   _state_rec->cost[8] = 
   _state_rec->cost[9] = 
   _state_rec->cost[10] = 
   _state_rec->cost[11] = 
   _state_rec->cost[12] = 
   _state_rec->cost[13] = 
   _state_rec->cost[14] = 
   _state_rec->cost[15] = 32767;
   {
      switch (redex->untag()) {
         case a_Inst::tag_ADDD: {
            labeler(_ADDD(redex)->_1);
            labeler(_ADDD(redex)->_2);
            // reg -> ADDD (reg, reg) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_ADDD(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_ADDD(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 16;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_ADDF: {
            labeler(_ADDF(redex)->_1);
            labeler(_ADDF(redex)->_2);
            // reg -> ADDF (reg, reg) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_ADDF(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_ADDF(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 15;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_ADDI: {
            labeler(_ADDI(redex)->_1);
            labeler(_ADDI(redex)->_2);
            // base -> ADDI (reg, con13): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_ADDI(redex)->_1->get_state_rec())->cost[7] + (((_s_p_a_r_cco_X1_StateRec *)_ADDI(redex)->_2->get_state_rec())->cost[7] + 1));
            if (cost__ < _state_rec->cost[7])
            {   _state_rec->cost[7] = cost__;
                _state_rec->rule._base = 6;
               _s_p_a_r_cco_X1_base_closure(redex, cost__);
            }
            // addr -> ADDI (reg, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_ADDI(redex)->_1->get_state_rec())->cost[8] + (((_s_p_a_r_cco_X1_StateRec *)_ADDI(redex)->_2->get_state_rec())->cost[8] + 1));
            if (cost__ < _state_rec->cost[8])
            {   _state_rec->cost[8] = cost__;
                _state_rec->rule._addr = 4;
               _s_p_a_r_cco_X1_addr_closure(redex, cost__);
            }
            // reg -> ADDI (reg, rc) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_ADDI(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_ADDI(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 47;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_ADDP: {
            labeler(_ADDP(redex)->_1);
            labeler(_ADDP(redex)->_2);
            // base -> ADDP (reg, con13): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_ADDP(redex)->_1->get_state_rec())->cost[7] + (((_s_p_a_r_cco_X1_StateRec *)_ADDP(redex)->_2->get_state_rec())->cost[7] + 1));
            if (cost__ < _state_rec->cost[7])
            {   _state_rec->cost[7] = cost__;
                _state_rec->rule._base = 5;
               _s_p_a_r_cco_X1_base_closure(redex, cost__);
            }
            // addr -> ADDP (reg, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_ADDP(redex)->_1->get_state_rec())->cost[8] + (((_s_p_a_r_cco_X1_StateRec *)_ADDP(redex)->_2->get_state_rec())->cost[8] + 1));
            if (cost__ < _state_rec->cost[8])
            {   _state_rec->cost[8] = cost__;
                _state_rec->rule._addr = 3;
               _s_p_a_r_cco_X1_addr_closure(redex, cost__);
            }
            // reg -> ADDP (reg, rc) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_ADDP(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_ADDP(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 46;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_ADDU: {
            labeler(_ADDU(redex)->_1);
            labeler(_ADDU(redex)->_2);
            // base -> ADDU (reg, con13): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_ADDU(redex)->_1->get_state_rec())->cost[7] + (((_s_p_a_r_cco_X1_StateRec *)_ADDU(redex)->_2->get_state_rec())->cost[7] + 1));
            if (cost__ < _state_rec->cost[7])
            {   _state_rec->cost[7] = cost__;
                _state_rec->rule._base = 4;
               _s_p_a_r_cco_X1_base_closure(redex, cost__);
            }
            // addr -> ADDU (reg, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_ADDU(redex)->_1->get_state_rec())->cost[8] + (((_s_p_a_r_cco_X1_StateRec *)_ADDU(redex)->_2->get_state_rec())->cost[8] + 1));
            if (cost__ < _state_rec->cost[8])
            {   _state_rec->cost[8] = cost__;
                _state_rec->rule._addr = 2;
               _s_p_a_r_cco_X1_addr_closure(redex, cost__);
            }
            // reg -> ADDU (reg, rc) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_ADDU(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_ADDU(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 45;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_ADDRFP: {
            // stk13 -> ADDRFP (): ...
            cost__ = 0 + 1;
            if (cost__ < _state_rec->cost[4])
            {   _state_rec->cost[4] = cost__;
                _state_rec->rule._stk13 = 2;
               _s_p_a_r_cco_X1_stk13_closure(redex, cost__);
            }
            // stk -> ADDRFP () \ 2: ...
            cost__ = 2 + 1;
            if (cost__ < _state_rec->cost[5])
            {   _state_rec->cost[5] = cost__;
                _state_rec->rule._stk = 2;
               _s_p_a_r_cco_X1_stk_closure(redex, cost__);
            }
            // reg -> ADDRFP () \ 3: ...
            cost__ = 3 + 1;
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 83;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_ADDRGP: {
            // reg -> ADDRGP (): ...
            cost__ = 0 + 1;
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 85;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }
            // addrg -> ADDRGP (): ...
            cost__ = 0 + 1;
            if (cost__ < _state_rec->cost[13])
            {   _state_rec->cost[13] = cost__;
                _state_rec->rule._addrg = 1;
            }
            // call -> ADDRGP (): ...
            cost__ = 0 + 1;
            if (cost__ < _state_rec->cost[14])
            {   _state_rec->cost[14] = cost__;
                _state_rec->rule._call = 2;
            }} break;
         case a_Inst::tag_ADDRLP: {
            // stk13 -> ADDRLP (): ...
            cost__ = 0 + 1;
            if (cost__ < _state_rec->cost[4])
            {   _state_rec->cost[4] = cost__;
                _state_rec->rule._stk13 = 1;
               _s_p_a_r_cco_X1_stk13_closure(redex, cost__);
            }
            // stk -> ADDRLP () \ 2: ...
            cost__ = 2 + 1;
            if (cost__ < _state_rec->cost[5])
            {   _state_rec->cost[5] = cost__;
                _state_rec->rule._stk = 1;
               _s_p_a_r_cco_X1_stk_closure(redex, cost__);
            }
            // reg -> ADDRLP () \ 3: ...
            cost__ = 3 + 1;
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 82;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }
            // addrl -> ADDRLP () \ imm(redex): ...
            int _X2 = imm(redex);
            cost__ = _X2 + 1;
            if (cost__ < _state_rec->cost[9])
            {   _state_rec->cost[9] = cost__;
                _state_rec->rule._addrl = 1;
            }
            // spill -> ADDRLP () \ (! imm(redex)): ...
            int _X3 = (! imm(redex));
            cost__ = _X3 + 1;
            if (cost__ < _state_rec->cost[10])
            {   _state_rec->cost[10] = cost__;
                _state_rec->rule._spill = 1;
            }} break;
         case a_Inst::tag_ARGB: {
            labeler(_ARGB(redex)->ARGB);} break;
         case a_Inst::tag_ARGD: {
            labeler(_ARGD(redex)->ARGD);
            // stmt -> ARGD reg \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_ARGD(redex)->ARGD->get_state_rec())->cost[2] + 1);
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 4;
            }} break;
         case a_Inst::tag_ARGF: {
            labeler(_ARGF(redex)->ARGF);
            // stmt -> ARGF reg \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_ARGF(redex)->ARGF->get_state_rec())->cost[2] + 1);
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 3;
            }} break;
         case a_Inst::tag_ARGI: {
            labeler(_ARGI(redex)->ARGI);
            // stmt -> ARGI reg \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_ARGI(redex)->ARGI->get_state_rec())->cost[2] + 1);
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 6;
            }} break;
         case a_Inst::tag_ARGP: {
            labeler(_ARGP(redex)->ARGP);
            // stmt -> ARGP reg \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_ARGP(redex)->ARGP->get_state_rec())->cost[2] + 1);
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 5;
            }} break;
         case a_Inst::tag_ASGNB: {
            labeler(_ASGNB(redex)->_1);
            labeler(_ASGNB(redex)->_2);
            switch (_ASGNB(redex)->_2->untag()) {
               case a_Inst::tag_INDIRB: {
                  // stmt -> ASGNB (reg, INDIRB reg): ...
                  cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_ASGNB(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_INDIRB(_ASGNB(redex)->_2)->INDIRB->get_state_rec())->cost[2] + 1));
                  if (cost__ < _state_rec->cost[2])
                  {   _state_rec->cost[2] = cost__;
                      _state_rec->rule._stmt = 1;
                  }} break;
               default: {} break;
            }
            } break;
         case a_Inst::tag_ASGNC: {
            labeler(_ASGNC(redex)->_1);
            labeler(_ASGNC(redex)->_2);
            switch (_ASGNC(redex)->_1->untag()) {
               case a_Inst::tag_VREGP: {
                  // stmt -> ASGNC (VREGP (), reg): ...
                  cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_ASGNC(redex)->_2->get_state_rec())->cost[2] + 1);
                  if (cost__ < _state_rec->cost[2])
                  {   _state_rec->cost[2] = cost__;
                      _state_rec->rule._stmt = 44;
                  }} break;
               default: {} break;
            }
            // stmt -> ASGNC (addr, reg) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_ASGNC(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_ASGNC(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 37;
            }
            // stmt -> ASGNC (spill, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_ASGNC(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_ASGNC(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 30;
            }} break;
         case a_Inst::tag_ASGND: {
            labeler(_ASGND(redex)->_1);
            labeler(_ASGND(redex)->_2);
            switch (_ASGND(redex)->_1->untag()) {
               case a_Inst::tag_VREGP: {
                  // stmt -> ASGND (VREGP (), reg): ...
                  cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_ASGND(redex)->_2->get_state_rec())->cost[2] + 1);
                  if (cost__ < _state_rec->cost[2])
                  {   _state_rec->cost[2] = cost__;
                      _state_rec->rule._stmt = 43;
                  }} break;
               default: {} break;
            }
            // stmt -> ASGND (addrl, reg) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_ASGND(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_ASGND(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 32;
            }
            // stmt -> ASGND (base, reg) \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_ASGND(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_ASGND(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 31;
            }
            // stmt -> ASGND (spill, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_ASGND(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_ASGND(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 25;
            }} break;
         case a_Inst::tag_ASGNF: {
            labeler(_ASGNF(redex)->_1);
            labeler(_ASGNF(redex)->_2);
            switch (_ASGNF(redex)->_1->untag()) {
               case a_Inst::tag_VREGP: {
                  // stmt -> ASGNF (VREGP (), reg): ...
                  cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_ASGNF(redex)->_2->get_state_rec())->cost[2] + 1);
                  if (cost__ < _state_rec->cost[2])
                  {   _state_rec->cost[2] = cost__;
                      _state_rec->rule._stmt = 42;
                  }} break;
               default: {} break;
            }
            // stmt -> ASGNF (addr, reg) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_ASGNF(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_ASGNF(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 33;
            }
            // stmt -> ASGNF (spill, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_ASGNF(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_ASGNF(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 26;
            }} break;
         case a_Inst::tag_ASGNI: {
            labeler(_ASGNI(redex)->_1);
            labeler(_ASGNI(redex)->_2);
            switch (_ASGNI(redex)->_1->untag()) {
               case a_Inst::tag_VREGP: {
                  // stmt -> ASGNI (VREGP (), reg): ...
                  cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_ASGNI(redex)->_2->get_state_rec())->cost[2] + 1);
                  if (cost__ < _state_rec->cost[2])
                  {   _state_rec->cost[2] = cost__;
                      _state_rec->rule._stmt = 41;
                  }} break;
               default: {} break;
            }
            // stmt -> ASGNI (addr, reg) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_ASGNI(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_ASGNI(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 35;
            }
            // stmt -> ASGNI (spill, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_ASGNI(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_ASGNI(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 28;
            }} break;
         case a_Inst::tag_ASGNP: {
            labeler(_ASGNP(redex)->_1);
            labeler(_ASGNP(redex)->_2);
            switch (_ASGNP(redex)->_1->untag()) {
               case a_Inst::tag_VREGP: {
                  // stmt -> ASGNP (VREGP (), reg): ...
                  cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_ASGNP(redex)->_2->get_state_rec())->cost[2] + 1);
                  if (cost__ < _state_rec->cost[2])
                  {   _state_rec->cost[2] = cost__;
                      _state_rec->rule._stmt = 40;
                  }} break;
               default: {} break;
            }
            // stmt -> ASGNP (addr, reg) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_ASGNP(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_ASGNP(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 34;
            }
            // stmt -> ASGNP (spill, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_ASGNP(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_ASGNP(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 27;
            }} break;
         case a_Inst::tag_ASGNS: {
            labeler(_ASGNS(redex)->_1);
            labeler(_ASGNS(redex)->_2);
            switch (_ASGNS(redex)->_1->untag()) {
               case a_Inst::tag_VREGP: {
                  // stmt -> ASGNS (VREGP (), reg): ...
                  cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_ASGNS(redex)->_2->get_state_rec())->cost[2] + 1);
                  if (cost__ < _state_rec->cost[2])
                  {   _state_rec->cost[2] = cost__;
                      _state_rec->rule._stmt = 39;
                  }} break;
               default: {} break;
            }
            // stmt -> ASGNS (addr, reg) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_ASGNS(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_ASGNS(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 36;
            }
            // stmt -> ASGNS (spill, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_ASGNS(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_ASGNS(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 29;
            }} break;
         case a_Inst::tag_BANDU: {
            labeler(_BANDU(redex)->_1);
            labeler(_BANDU(redex)->_2);
            switch (_BANDU(redex)->_2->untag()) {
               case a_Inst::tag_BCOMU: {
                  // reg -> BANDU (reg, BCOMU rc) \ 1: ...
                  cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_BANDU(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_BCOMU(_BANDU(redex)->_2)->BCOMU->get_state_rec())->cost[1] + 1));
                  if (cost__ < _state_rec->cost[1])
                  {   _state_rec->cost[1] = cost__;
                      _state_rec->rule._reg = 34;
                     _s_p_a_r_cco_X1_reg_closure(redex, cost__);
                  }} break;
               default: {} break;
            }
            // reg -> BANDU (reg, rc) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_BANDU(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_BANDU(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 44;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_BCOMU: {
            labeler(_BCOMU(redex)->BCOMU);
            // reg -> BCOMU reg \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_BCOMU(redex)->BCOMU->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 30;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_BORU: {
            labeler(_BORU(redex)->_1);
            labeler(_BORU(redex)->_2);
            switch (_BORU(redex)->_2->untag()) {
               case a_Inst::tag_BCOMU: {
                  // reg -> BORU (reg, BCOMU rc) \ 1: ...
                  cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_BORU(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_BCOMU(_BORU(redex)->_2)->BCOMU->get_state_rec())->cost[1] + 1));
                  if (cost__ < _state_rec->cost[1])
                  {   _state_rec->cost[1] = cost__;
                      _state_rec->rule._reg = 33;
                     _s_p_a_r_cco_X1_reg_closure(redex, cost__);
                  }} break;
               default: {} break;
            }
            // reg -> BORU (reg, rc) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_BORU(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_BORU(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 43;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_BXORU: {
            labeler(_BXORU(redex)->_1);
            labeler(_BXORU(redex)->_2);
            switch (_BXORU(redex)->_2->untag()) {
               case a_Inst::tag_BCOMU: {
                  // reg -> BXORU (reg, BCOMU rc) \ 1: ...
                  cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_BXORU(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_BCOMU(_BXORU(redex)->_2)->BCOMU->get_state_rec())->cost[1] + 1));
                  if (cost__ < _state_rec->cost[1])
                  {   _state_rec->cost[1] = cost__;
                      _state_rec->rule._reg = 32;
                     _s_p_a_r_cco_X1_reg_closure(redex, cost__);
                  }} break;
               default: {} break;
            }
            // reg -> BXORU (reg, rc) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_BXORU(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_BXORU(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 42;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CALLB: {
            labeler(_CALLB(redex)->_1);
            labeler(_CALLB(redex)->_2);
            // stmt -> CALLB (call, reg) \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_CALLB(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_CALLB(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 10;
            }} break;
         case a_Inst::tag_CALLD: {
            labeler(_CALLD(redex)->CALLD);
            // reg -> CALLD call \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_CALLD(redex)->CALLD->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 25;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CALLF: {
            labeler(_CALLF(redex)->CALLF);
            // reg -> CALLF call \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_CALLF(redex)->CALLF->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 24;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CALLI: {
            labeler(_CALLI(redex)->CALLI);
            // reg -> CALLI call \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_CALLI(redex)->CALLI->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 23;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CALLV: {
            labeler(_CALLV(redex)->CALLV);
            // stmt -> CALLV call \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_CALLV(redex)->CALLV->get_state_rec())->cost[2] + 1);
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 11;
            }} break;
         case a_Inst::tag_CNSTC: {
            // con -> CNSTC (): ...
            cost__ = 0 + 1;
            if (cost__ < _state_rec->cost[3])
            {   _state_rec->cost[3] = cost__;
                _state_rec->rule._con = 5;
               _s_p_a_r_cco_X1_con_closure(redex, cost__);
            }
            // con13 -> CNSTC () \ imm(redex): ...
            int _X4 = imm(redex);
            cost__ = _X4 + 1;
            if (cost__ < _state_rec->cost[6])
            {   _state_rec->cost[6] = cost__;
                _state_rec->rule._con13 = 5;
               _s_p_a_r_cco_X1_con13_closure(redex, cost__);
            }
            // reg -> CNSTC () \ range(redex,0,0): ...
            int _X5 = range(redex,0,0);
            cost__ = _X5 + 1;
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 53;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CNSTD: {} break;
         case a_Inst::tag_CNSTF: {} break;
         case a_Inst::tag_CNSTI: {
            // con -> CNSTI (): ...
            cost__ = 0 + 1;
            if (cost__ < _state_rec->cost[3])
            {   _state_rec->cost[3] = cost__;
                _state_rec->rule._con = 4;
               _s_p_a_r_cco_X1_con_closure(redex, cost__);
            }
            // con13 -> CNSTI () \ imm(redex): ...
            int _X6 = imm(redex);
            cost__ = _X6 + 1;
            if (cost__ < _state_rec->cost[6])
            {   _state_rec->cost[6] = cost__;
                _state_rec->rule._con13 = 4;
               _s_p_a_r_cco_X1_con13_closure(redex, cost__);
            }
            // reg -> CNSTI () \ range(redex,0,0): ...
            int _X7 = range(redex,0,0);
            cost__ = _X7 + 1;
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 52;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }
            // rc5 -> CNSTI () \ range(redex,0,31): ...
            int _X8 = range(redex,0,31);
            cost__ = _X8 + 1;
            if (cost__ < _state_rec->cost[12])
            {   _state_rec->cost[12] = cost__;
                _state_rec->rule._rc5 = 2;
            }} break;
         case a_Inst::tag_CNSTP: {
            // con -> CNSTP (): ...
            cost__ = 0 + 1;
            if (cost__ < _state_rec->cost[3])
            {   _state_rec->cost[3] = cost__;
                _state_rec->rule._con = 3;
               _s_p_a_r_cco_X1_con_closure(redex, cost__);
            }
            // con13 -> CNSTP () \ imm(redex): ...
            int _X9 = imm(redex);
            cost__ = _X9 + 1;
            if (cost__ < _state_rec->cost[6])
            {   _state_rec->cost[6] = cost__;
                _state_rec->rule._con13 = 3;
               _s_p_a_r_cco_X1_con13_closure(redex, cost__);
            }
            // reg -> CNSTP () \ range(redex,0,0): ...
            int _X10 = range(redex,0,0);
            cost__ = _X10 + 1;
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 51;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CNSTS: {
            // con -> CNSTS (): ...
            cost__ = 0 + 1;
            if (cost__ < _state_rec->cost[3])
            {   _state_rec->cost[3] = cost__;
                _state_rec->rule._con = 2;
               _s_p_a_r_cco_X1_con_closure(redex, cost__);
            }
            // con13 -> CNSTS () \ imm(redex): ...
            int _X11 = imm(redex);
            cost__ = _X11 + 1;
            if (cost__ < _state_rec->cost[6])
            {   _state_rec->cost[6] = cost__;
                _state_rec->rule._con13 = 2;
               _s_p_a_r_cco_X1_con13_closure(redex, cost__);
            }
            // reg -> CNSTS () \ range(redex,0,0): ...
            int _X12 = range(redex,0,0);
            cost__ = _X12 + 1;
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 50;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CNSTU: {
            // con -> CNSTU (): ...
            cost__ = 0 + 1;
            if (cost__ < _state_rec->cost[3])
            {   _state_rec->cost[3] = cost__;
                _state_rec->rule._con = 1;
               _s_p_a_r_cco_X1_con_closure(redex, cost__);
            }
            // con13 -> CNSTU () \ imm(redex): ...
            int _X13 = imm(redex);
            cost__ = _X13 + 1;
            if (cost__ < _state_rec->cost[6])
            {   _state_rec->cost[6] = cost__;
                _state_rec->rule._con13 = 1;
               _s_p_a_r_cco_X1_con13_closure(redex, cost__);
            }
            // reg -> CNSTU () \ range(redex,0,0): ...
            int _X14 = range(redex,0,0);
            cost__ = _X14 + 1;
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 49;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CVCI: {
            labeler(_CVCI(redex)->CVCI);
            switch (_CVCI(redex)->CVCI->untag()) {
               case a_Inst::tag_INDIRC: {
                  // reg -> CVCI INDIRC addr: ...
                  cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_INDIRC(_CVCI(redex)->CVCI)->INDIRC->get_state_rec())->cost[1] + 1);
                  if (cost__ < _state_rec->cost[1])
                  {   _state_rec->cost[1] = cost__;
                      _state_rec->rule._reg = 74;
                     _s_p_a_r_cco_X1_reg_closure(redex, cost__);
                  }} break;
               default: {} break;
            }
            // reg -> CVCI reg \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_CVCI(redex)->CVCI->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 29;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CVCU: {
            labeler(_CVCU(redex)->CVCU);
            switch (_CVCU(redex)->CVCU->untag()) {
               case a_Inst::tag_INDIRC: {
                  // reg -> CVCU INDIRC addr: ...
                  cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_INDIRC(_CVCU(redex)->CVCU)->INDIRC->get_state_rec())->cost[1] + 1);
                  if (cost__ < _state_rec->cost[1])
                  {   _state_rec->cost[1] = cost__;
                      _state_rec->rule._reg = 72;
                     _s_p_a_r_cco_X1_reg_closure(redex, cost__);
                  }} break;
               default: {} break;
            }
            // reg -> CVCU reg \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_CVCU(redex)->CVCU->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 27;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CVDF: {
            labeler(_CVDF(redex)->CVDF);
            // reg -> CVDF reg \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_CVDF(redex)->CVDF->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 6;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CVDI: {
            labeler(_CVDI(redex)->CVDI);
            // reg -> CVDI reg \ 3: ...
            cost__ = 3 + (((_s_p_a_r_cco_X1_StateRec *)_CVDI(redex)->CVDI->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 4;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CVFD: {
            labeler(_CVFD(redex)->CVFD);
            // reg -> CVFD reg \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_CVFD(redex)->CVFD->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 5;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CVIC: {
            labeler(_CVIC(redex)->CVIC);
            // reg -> CVIC reg \ move(redex): ...
            int _X15 = move(redex);
            cost__ = _X15 + (((_s_p_a_r_cco_X1_StateRec *)_CVIC(redex)->CVIC->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 70;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }
            // reg -> CVIC reg \ notarget(redex): ...
            int _X16 = notarget(redex);
            cost__ = _X16 + (((_s_p_a_r_cco_X1_StateRec *)_CVIC(redex)->CVIC->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 62;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CVID: {
            labeler(_CVID(redex)->CVID);
            // reg -> CVID reg \ 3: ...
            cost__ = 3 + (((_s_p_a_r_cco_X1_StateRec *)_CVID(redex)->CVID->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 3;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CVIS: {
            labeler(_CVIS(redex)->CVIS);
            // reg -> CVIS reg \ move(redex): ...
            int _X17 = move(redex);
            cost__ = _X17 + (((_s_p_a_r_cco_X1_StateRec *)_CVIS(redex)->CVIS->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 69;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }
            // reg -> CVIS reg \ notarget(redex): ...
            int _X18 = notarget(redex);
            cost__ = _X18 + (((_s_p_a_r_cco_X1_StateRec *)_CVIS(redex)->CVIS->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 61;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CVIU: {
            labeler(_CVIU(redex)->CVIU);
            // reg -> CVIU reg \ notarget(redex): ...
            int _X19 = notarget(redex);
            cost__ = _X19 + (((_s_p_a_r_cco_X1_StateRec *)_CVIU(redex)->CVIU->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 89;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }
            // reg -> CVIU reg \ move(redex): ...
            int _X20 = move(redex);
            cost__ = _X20 + (((_s_p_a_r_cco_X1_StateRec *)_CVIU(redex)->CVIU->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 68;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CVPU: {
            labeler(_CVPU(redex)->CVPU);
            // reg -> CVPU reg \ notarget(redex): ...
            int _X21 = notarget(redex);
            cost__ = _X21 + (((_s_p_a_r_cco_X1_StateRec *)_CVPU(redex)->CVPU->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 88;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }
            // reg -> CVPU reg \ move(redex): ...
            int _X22 = move(redex);
            cost__ = _X22 + (((_s_p_a_r_cco_X1_StateRec *)_CVPU(redex)->CVPU->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 67;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CVSI: {
            labeler(_CVSI(redex)->CVSI);
            switch (_CVSI(redex)->CVSI->untag()) {
               case a_Inst::tag_INDIRS: {
                  // reg -> CVSI INDIRS addr: ...
                  cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_INDIRS(_CVSI(redex)->CVSI)->INDIRS->get_state_rec())->cost[1] + 1);
                  if (cost__ < _state_rec->cost[1])
                  {   _state_rec->cost[1] = cost__;
                      _state_rec->rule._reg = 73;
                     _s_p_a_r_cco_X1_reg_closure(redex, cost__);
                  }} break;
               default: {} break;
            }
            // reg -> CVSI reg \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_CVSI(redex)->CVSI->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 28;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CVSU: {
            labeler(_CVSU(redex)->CVSU);
            switch (_CVSU(redex)->CVSU->untag()) {
               case a_Inst::tag_INDIRS: {
                  // reg -> CVSU INDIRS addr: ...
                  cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_INDIRS(_CVSU(redex)->CVSU)->INDIRS->get_state_rec())->cost[1] + 1);
                  if (cost__ < _state_rec->cost[1])
                  {   _state_rec->cost[1] = cost__;
                      _state_rec->rule._reg = 71;
                     _s_p_a_r_cco_X1_reg_closure(redex, cost__);
                  }} break;
               default: {} break;
            }
            // reg -> CVSU reg \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_CVSU(redex)->CVSU->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 26;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CVUC: {
            labeler(_CVUC(redex)->CVUC);
            // reg -> CVUC reg \ move(redex): ...
            int _X23 = move(redex);
            cost__ = _X23 + (((_s_p_a_r_cco_X1_StateRec *)_CVUC(redex)->CVUC->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 66;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }
            // reg -> CVUC reg \ notarget(redex): ...
            int _X24 = notarget(redex);
            cost__ = _X24 + (((_s_p_a_r_cco_X1_StateRec *)_CVUC(redex)->CVUC->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 60;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CVUI: {
            labeler(_CVUI(redex)->CVUI);
            // reg -> CVUI reg \ notarget(redex): ...
            int _X25 = notarget(redex);
            cost__ = _X25 + (((_s_p_a_r_cco_X1_StateRec *)_CVUI(redex)->CVUI->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 87;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }
            // reg -> CVUI reg \ move(redex): ...
            int _X26 = move(redex);
            cost__ = _X26 + (((_s_p_a_r_cco_X1_StateRec *)_CVUI(redex)->CVUI->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 65;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CVUP: {
            labeler(_CVUP(redex)->CVUP);
            // reg -> CVUP reg \ notarget(redex): ...
            int _X27 = notarget(redex);
            cost__ = _X27 + (((_s_p_a_r_cco_X1_StateRec *)_CVUP(redex)->CVUP->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 86;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }
            // reg -> CVUP reg \ move(redex): ...
            int _X28 = move(redex);
            cost__ = _X28 + (((_s_p_a_r_cco_X1_StateRec *)_CVUP(redex)->CVUP->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 64;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_CVUS: {
            labeler(_CVUS(redex)->CVUS);
            // reg -> CVUS reg \ move(redex): ...
            int _X29 = move(redex);
            cost__ = _X29 + (((_s_p_a_r_cco_X1_StateRec *)_CVUS(redex)->CVUS->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 63;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }
            // reg -> CVUS reg \ notarget(redex): ...
            int _X30 = notarget(redex);
            cost__ = _X30 + (((_s_p_a_r_cco_X1_StateRec *)_CVUS(redex)->CVUS->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 59;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_DIVD: {
            labeler(_DIVD(redex)->_1);
            labeler(_DIVD(redex)->_2);
            // reg -> DIVD (reg, reg) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_DIVD(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_DIVD(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 14;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_DIVF: {
            labeler(_DIVF(redex)->_1);
            labeler(_DIVF(redex)->_2);
            // reg -> DIVF (reg, reg) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_DIVF(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_DIVF(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 13;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_DIVI: {
            labeler(_DIVI(redex)->_1);
            labeler(_DIVI(redex)->_2);
            // reg -> DIVI (reg, reg) \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_DIVI(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_DIVI(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 22;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_DIVU: {
            labeler(_DIVU(redex)->_1);
            labeler(_DIVU(redex)->_2);
            // reg -> DIVU (reg, reg) \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_DIVU(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_DIVU(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 21;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_EQD: {
            labeler(_EQD(redex)->_1);
            labeler(_EQD(redex)->_2);
            // rel -> EQD (reg, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_EQD(redex)->_1->get_state_rec())->cost[15] + (((_s_p_a_r_cco_X1_StateRec *)_EQD(redex)->_2->get_state_rec())->cost[15] + 1));
            if (cost__ < _state_rec->cost[15])
            {   _state_rec->cost[15] = cost__;
                _state_rec->rule._rel = 12;
               _s_p_a_r_cco_X1_rel_closure(redex, cost__);
            }} break;
         case a_Inst::tag_EQF: {
            labeler(_EQF(redex)->_1);
            labeler(_EQF(redex)->_2);
            // rel -> EQF (reg, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_EQF(redex)->_1->get_state_rec())->cost[15] + (((_s_p_a_r_cco_X1_StateRec *)_EQF(redex)->_2->get_state_rec())->cost[15] + 1));
            if (cost__ < _state_rec->cost[15])
            {   _state_rec->cost[15] = cost__;
                _state_rec->rule._rel = 11;
               _s_p_a_r_cco_X1_rel_closure(redex, cost__);
            }} break;
         case a_Inst::tag_EQI: {
            labeler(_EQI(redex)->_1);
            labeler(_EQI(redex)->_2);
            // stmt -> EQI (reg, rc) \ 3: ...
            cost__ = 3 + (((_s_p_a_r_cco_X1_StateRec *)_EQI(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_EQI(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 21;
            }} break;
         case a_Inst::tag_GED: {
            labeler(_GED(redex)->_1);
            labeler(_GED(redex)->_2);
            // rel -> GED (reg, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_GED(redex)->_1->get_state_rec())->cost[15] + (((_s_p_a_r_cco_X1_StateRec *)_GED(redex)->_2->get_state_rec())->cost[15] + 1));
            if (cost__ < _state_rec->cost[15])
            {   _state_rec->cost[15] = cost__;
                _state_rec->rule._rel = 10;
               _s_p_a_r_cco_X1_rel_closure(redex, cost__);
            }} break;
         case a_Inst::tag_GEF: {
            labeler(_GEF(redex)->_1);
            labeler(_GEF(redex)->_2);
            // rel -> GEF (reg, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_GEF(redex)->_1->get_state_rec())->cost[15] + (((_s_p_a_r_cco_X1_StateRec *)_GEF(redex)->_2->get_state_rec())->cost[15] + 1));
            if (cost__ < _state_rec->cost[15])
            {   _state_rec->cost[15] = cost__;
                _state_rec->rule._rel = 9;
               _s_p_a_r_cco_X1_rel_closure(redex, cost__);
            }} break;
         case a_Inst::tag_GEI: {
            labeler(_GEI(redex)->_1);
            labeler(_GEI(redex)->_2);
            // stmt -> GEI (reg, rc) \ 3: ...
            cost__ = 3 + (((_s_p_a_r_cco_X1_StateRec *)_GEI(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_GEI(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 20;
            }} break;
         case a_Inst::tag_GEU: {
            labeler(_GEU(redex)->_1);
            labeler(_GEU(redex)->_2);
            // stmt -> GEU (reg, rc) \ 3: ...
            cost__ = 3 + (((_s_p_a_r_cco_X1_StateRec *)_GEU(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_GEU(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 19;
            }} break;
         case a_Inst::tag_GTD: {
            labeler(_GTD(redex)->_1);
            labeler(_GTD(redex)->_2);
            // rel -> GTD (reg, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_GTD(redex)->_1->get_state_rec())->cost[15] + (((_s_p_a_r_cco_X1_StateRec *)_GTD(redex)->_2->get_state_rec())->cost[15] + 1));
            if (cost__ < _state_rec->cost[15])
            {   _state_rec->cost[15] = cost__;
                _state_rec->rule._rel = 8;
               _s_p_a_r_cco_X1_rel_closure(redex, cost__);
            }} break;
         case a_Inst::tag_GTF: {
            labeler(_GTF(redex)->_1);
            labeler(_GTF(redex)->_2);
            // rel -> GTF (reg, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_GTF(redex)->_1->get_state_rec())->cost[15] + (((_s_p_a_r_cco_X1_StateRec *)_GTF(redex)->_2->get_state_rec())->cost[15] + 1));
            if (cost__ < _state_rec->cost[15])
            {   _state_rec->cost[15] = cost__;
                _state_rec->rule._rel = 7;
               _s_p_a_r_cco_X1_rel_closure(redex, cost__);
            }} break;
         case a_Inst::tag_GTI: {
            labeler(_GTI(redex)->_1);
            labeler(_GTI(redex)->_2);
            // stmt -> GTI (reg, rc) \ 3: ...
            cost__ = 3 + (((_s_p_a_r_cco_X1_StateRec *)_GTI(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_GTI(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 18;
            }} break;
         case a_Inst::tag_GTU: {
            labeler(_GTU(redex)->_1);
            labeler(_GTU(redex)->_2);
            // stmt -> GTU (reg, rc) \ 3: ...
            cost__ = 3 + (((_s_p_a_r_cco_X1_StateRec *)_GTU(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_GTU(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 17;
            }} break;
         case a_Inst::tag_INDIRB: {
            labeler(_INDIRB(redex)->INDIRB);} break;
         case a_Inst::tag_INDIRC: {
            labeler(_INDIRC(redex)->INDIRC);
            switch (_INDIRC(redex)->INDIRC->untag()) {
               case a_Inst::tag_VREGP: {
                  // reg -> INDIRC VREGP (): ...
                  cost__ = 0 + 1;
                  if (cost__ < _state_rec->cost[1])
                  {   _state_rec->cost[1] = cost__;
                      _state_rec->rule._reg = 95;
                     _s_p_a_r_cco_X1_reg_closure(redex, cost__);
                  }} break;
               default: {} break;
            }
            // reg -> INDIRC addr \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_INDIRC(redex)->INDIRC->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 81;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_INDIRD: {
            labeler(_INDIRD(redex)->INDIRD);
            switch (_INDIRD(redex)->INDIRD->untag()) {
               case a_Inst::tag_VREGP: {
                  // reg -> INDIRD VREGP (): ...
                  cost__ = 0 + 1;
                  if (cost__ < _state_rec->cost[1])
                  {   _state_rec->cost[1] = cost__;
                      _state_rec->rule._reg = 94;
                     _s_p_a_r_cco_X1_reg_closure(redex, cost__);
                  }} break;
               default: {} break;
            }
            // reg -> INDIRD addrl \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_INDIRD(redex)->INDIRD->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 76;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }
            // reg -> INDIRD base \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_INDIRD(redex)->INDIRD->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 75;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_INDIRF: {
            labeler(_INDIRF(redex)->INDIRF);
            switch (_INDIRF(redex)->INDIRF->untag()) {
               case a_Inst::tag_VREGP: {
                  // reg -> INDIRF VREGP (): ...
                  cost__ = 0 + 1;
                  if (cost__ < _state_rec->cost[1])
                  {   _state_rec->cost[1] = cost__;
                      _state_rec->rule._reg = 93;
                     _s_p_a_r_cco_X1_reg_closure(redex, cost__);
                  }} break;
               default: {} break;
            }
            // reg -> INDIRF addr \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_INDIRF(redex)->INDIRF->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 77;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_INDIRI: {
            labeler(_INDIRI(redex)->INDIRI);
            switch (_INDIRI(redex)->INDIRI->untag()) {
               case a_Inst::tag_VREGP: {
                  // reg -> INDIRI VREGP (): ...
                  cost__ = 0 + 1;
                  if (cost__ < _state_rec->cost[1])
                  {   _state_rec->cost[1] = cost__;
                      _state_rec->rule._reg = 92;
                     _s_p_a_r_cco_X1_reg_closure(redex, cost__);
                  }} break;
               default: {} break;
            }
            // reg -> INDIRI addr \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_INDIRI(redex)->INDIRI->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 79;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_INDIRP: {
            labeler(_INDIRP(redex)->INDIRP);
            switch (_INDIRP(redex)->INDIRP->untag()) {
               case a_Inst::tag_VREGP: {
                  // reg -> INDIRP VREGP (): ...
                  cost__ = 0 + 1;
                  if (cost__ < _state_rec->cost[1])
                  {   _state_rec->cost[1] = cost__;
                      _state_rec->rule._reg = 91;
                     _s_p_a_r_cco_X1_reg_closure(redex, cost__);
                  }} break;
               default: {} break;
            }
            // reg -> INDIRP addr \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_INDIRP(redex)->INDIRP->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 78;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_INDIRS: {
            labeler(_INDIRS(redex)->INDIRS);
            switch (_INDIRS(redex)->INDIRS->untag()) {
               case a_Inst::tag_VREGP: {
                  // reg -> INDIRS VREGP (): ...
                  cost__ = 0 + 1;
                  if (cost__ < _state_rec->cost[1])
                  {   _state_rec->cost[1] = cost__;
                      _state_rec->rule._reg = 90;
                     _s_p_a_r_cco_X1_reg_closure(redex, cost__);
                  }} break;
               default: {} break;
            }
            // reg -> INDIRS addr \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_INDIRS(redex)->INDIRS->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 80;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_JUMPV: {
            labeler(_JUMPV(redex)->JUMPV);
            // stmt -> JUMPV addrg \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_JUMPV(redex)->JUMPV->get_state_rec())->cost[2] + 1);
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 24;
            }
            // stmt -> JUMPV addr \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_JUMPV(redex)->JUMPV->get_state_rec())->cost[2] + 1);
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 23;
            }} break;
         case a_Inst::tag_LABELV: {
            // stmt -> LABELV (): ...
            cost__ = 0 + 1;
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 22;
            }} break;
         case a_Inst::tag_LED: {
            labeler(_LED(redex)->_1);
            labeler(_LED(redex)->_2);
            // rel -> LED (reg, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_LED(redex)->_1->get_state_rec())->cost[15] + (((_s_p_a_r_cco_X1_StateRec *)_LED(redex)->_2->get_state_rec())->cost[15] + 1));
            if (cost__ < _state_rec->cost[15])
            {   _state_rec->cost[15] = cost__;
                _state_rec->rule._rel = 6;
               _s_p_a_r_cco_X1_rel_closure(redex, cost__);
            }} break;
         case a_Inst::tag_LEF: {
            labeler(_LEF(redex)->_1);
            labeler(_LEF(redex)->_2);
            // rel -> LEF (reg, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_LEF(redex)->_1->get_state_rec())->cost[15] + (((_s_p_a_r_cco_X1_StateRec *)_LEF(redex)->_2->get_state_rec())->cost[15] + 1));
            if (cost__ < _state_rec->cost[15])
            {   _state_rec->cost[15] = cost__;
                _state_rec->rule._rel = 5;
               _s_p_a_r_cco_X1_rel_closure(redex, cost__);
            }} break;
         case a_Inst::tag_LEI: {
            labeler(_LEI(redex)->_1);
            labeler(_LEI(redex)->_2);
            // stmt -> LEI (reg, rc) \ 3: ...
            cost__ = 3 + (((_s_p_a_r_cco_X1_StateRec *)_LEI(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_LEI(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 16;
            }} break;
         case a_Inst::tag_LEU: {
            labeler(_LEU(redex)->_1);
            labeler(_LEU(redex)->_2);
            // stmt -> LEU (reg, rc) \ 3: ...
            cost__ = 3 + (((_s_p_a_r_cco_X1_StateRec *)_LEU(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_LEU(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 15;
            }} break;
         case a_Inst::tag_LOADB: {
            labeler(_LOADB(redex)->LOADB);} break;
         case a_Inst::tag_LOADC: {
            labeler(_LOADC(redex)->LOADC);
            // reg -> LOADC reg \ move(redex): ...
            int _X31 = move(redex);
            cost__ = _X31 + (((_s_p_a_r_cco_X1_StateRec *)_LOADC(redex)->LOADC->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 58;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_LOADD: {
            labeler(_LOADD(redex)->LOADD);
            // reg -> LOADD reg \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_LOADD(redex)->LOADD->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 2;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_LOADF: {
            labeler(_LOADF(redex)->LOADF);
            // reg -> LOADF reg \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_LOADF(redex)->LOADF->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 7;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_LOADI: {
            labeler(_LOADI(redex)->LOADI);
            // reg -> LOADI reg \ move(redex): ...
            int _X32 = move(redex);
            cost__ = _X32 + (((_s_p_a_r_cco_X1_StateRec *)_LOADI(redex)->LOADI->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 57;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_LOADP: {
            labeler(_LOADP(redex)->LOADP);
            // reg -> LOADP reg \ move(redex): ...
            int _X33 = move(redex);
            cost__ = _X33 + (((_s_p_a_r_cco_X1_StateRec *)_LOADP(redex)->LOADP->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 56;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_LOADS: {
            labeler(_LOADS(redex)->LOADS);
            // reg -> LOADS reg \ move(redex): ...
            int _X34 = move(redex);
            cost__ = _X34 + (((_s_p_a_r_cco_X1_StateRec *)_LOADS(redex)->LOADS->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 55;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_LOADU: {
            labeler(_LOADU(redex)->LOADU);
            // reg -> LOADU reg \ move(redex): ...
            int _X35 = move(redex);
            cost__ = _X35 + (((_s_p_a_r_cco_X1_StateRec *)_LOADU(redex)->LOADU->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 54;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_LSHI: {
            labeler(_LSHI(redex)->_1);
            labeler(_LSHI(redex)->_2);
            // reg -> LSHI (reg, rc5) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_LSHI(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_LSHI(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 38;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_LSHU: {
            labeler(_LSHU(redex)->_1);
            labeler(_LSHU(redex)->_2);
            // reg -> LSHU (reg, rc5) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_LSHU(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_LSHU(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 37;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_LTD: {
            labeler(_LTD(redex)->_1);
            labeler(_LTD(redex)->_2);
            // rel -> LTD (reg, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_LTD(redex)->_1->get_state_rec())->cost[15] + (((_s_p_a_r_cco_X1_StateRec *)_LTD(redex)->_2->get_state_rec())->cost[15] + 1));
            if (cost__ < _state_rec->cost[15])
            {   _state_rec->cost[15] = cost__;
                _state_rec->rule._rel = 4;
               _s_p_a_r_cco_X1_rel_closure(redex, cost__);
            }} break;
         case a_Inst::tag_LTF: {
            labeler(_LTF(redex)->_1);
            labeler(_LTF(redex)->_2);
            // rel -> LTF (reg, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_LTF(redex)->_1->get_state_rec())->cost[15] + (((_s_p_a_r_cco_X1_StateRec *)_LTF(redex)->_2->get_state_rec())->cost[15] + 1));
            if (cost__ < _state_rec->cost[15])
            {   _state_rec->cost[15] = cost__;
                _state_rec->rule._rel = 3;
               _s_p_a_r_cco_X1_rel_closure(redex, cost__);
            }} break;
         case a_Inst::tag_LTI: {
            labeler(_LTI(redex)->_1);
            labeler(_LTI(redex)->_2);
            // stmt -> LTI (reg, rc) \ 3: ...
            cost__ = 3 + (((_s_p_a_r_cco_X1_StateRec *)_LTI(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_LTI(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 14;
            }} break;
         case a_Inst::tag_LTU: {
            labeler(_LTU(redex)->_1);
            labeler(_LTU(redex)->_2);
            // stmt -> LTU (reg, rc) \ 3: ...
            cost__ = 3 + (((_s_p_a_r_cco_X1_StateRec *)_LTU(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_LTU(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 13;
            }} break;
         case a_Inst::tag_MODI: {
            labeler(_MODI(redex)->_1);
            labeler(_MODI(redex)->_2);
            // reg -> MODI (reg, reg) \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_MODI(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_MODI(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 20;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_MODU: {
            labeler(_MODU(redex)->_1);
            labeler(_MODU(redex)->_2);
            // reg -> MODU (reg, reg) \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_MODU(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_MODU(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 19;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_MULD: {
            labeler(_MULD(redex)->_1);
            labeler(_MULD(redex)->_2);
            // reg -> MULD (reg, reg) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_MULD(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_MULD(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 12;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_MULF: {
            labeler(_MULF(redex)->_1);
            labeler(_MULF(redex)->_2);
            // reg -> MULF (reg, reg) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_MULF(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_MULF(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 11;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_MULI: {
            labeler(_MULI(redex)->_1);
            labeler(_MULI(redex)->_2);
            // reg -> MULI (reg, reg) \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_MULI(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_MULI(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 18;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_MULU: {
            labeler(_MULU(redex)->_1);
            labeler(_MULU(redex)->_2);
            // reg -> MULU (reg, reg) \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_MULU(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_MULU(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 17;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_NED: {
            labeler(_NED(redex)->_1);
            labeler(_NED(redex)->_2);
            // rel -> NED (reg, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_NED(redex)->_1->get_state_rec())->cost[15] + (((_s_p_a_r_cco_X1_StateRec *)_NED(redex)->_2->get_state_rec())->cost[15] + 1));
            if (cost__ < _state_rec->cost[15])
            {   _state_rec->cost[15] = cost__;
                _state_rec->rule._rel = 2;
               _s_p_a_r_cco_X1_rel_closure(redex, cost__);
            }} break;
         case a_Inst::tag_NEF: {
            labeler(_NEF(redex)->_1);
            labeler(_NEF(redex)->_2);
            // rel -> NEF (reg, reg): ...
            cost__ = 0 + (((_s_p_a_r_cco_X1_StateRec *)_NEF(redex)->_1->get_state_rec())->cost[15] + (((_s_p_a_r_cco_X1_StateRec *)_NEF(redex)->_2->get_state_rec())->cost[15] + 1));
            if (cost__ < _state_rec->cost[15])
            {   _state_rec->cost[15] = cost__;
                _state_rec->rule._rel = 1;
               _s_p_a_r_cco_X1_rel_closure(redex, cost__);
            }} break;
         case a_Inst::tag_NEI: {
            labeler(_NEI(redex)->_1);
            labeler(_NEI(redex)->_2);
            // stmt -> NEI (reg, rc) \ 3: ...
            cost__ = 3 + (((_s_p_a_r_cco_X1_StateRec *)_NEI(redex)->_1->get_state_rec())->cost[2] + (((_s_p_a_r_cco_X1_StateRec *)_NEI(redex)->_2->get_state_rec())->cost[2] + 1));
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 12;
            }} break;
         case a_Inst::tag_NEGD: {
            labeler(_NEGD(redex)->NEGD);
            // reg -> NEGD reg \ 2: ...
            cost__ = 2 + (((_s_p_a_r_cco_X1_StateRec *)_NEGD(redex)->NEGD->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 1;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_NEGF: {
            labeler(_NEGF(redex)->NEGF);
            // reg -> NEGF reg \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_NEGF(redex)->NEGF->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 8;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_NEGI: {
            labeler(_NEGI(redex)->NEGI);
            // reg -> NEGI reg \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_NEGI(redex)->NEGI->get_state_rec())->cost[1] + 1);
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 31;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_RETD: {
            labeler(_RETD(redex)->RETD);
            // stmt -> RETD reg \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_RETD(redex)->RETD->get_state_rec())->cost[2] + 1);
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 9;
            }} break;
         case a_Inst::tag_RETF: {
            labeler(_RETF(redex)->RETF);
            // stmt -> RETF reg \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_RETF(redex)->RETF->get_state_rec())->cost[2] + 1);
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 8;
            }} break;
         case a_Inst::tag_RETI: {
            labeler(_RETI(redex)->RETI);
            // stmt -> RETI reg \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_RETI(redex)->RETI->get_state_rec())->cost[2] + 1);
            if (cost__ < _state_rec->cost[2])
            {   _state_rec->cost[2] = cost__;
                _state_rec->rule._stmt = 7;
            }} break;
         case a_Inst::tag_RSHI: {
            labeler(_RSHI(redex)->_1);
            labeler(_RSHI(redex)->_2);
            // reg -> RSHI (reg, rc5) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_RSHI(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_RSHI(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 36;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_RSHU: {
            labeler(_RSHU(redex)->_1);
            labeler(_RSHU(redex)->_2);
            // reg -> RSHU (reg, rc5) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_RSHU(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_RSHU(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 35;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_SUBD: {
            labeler(_SUBD(redex)->_1);
            labeler(_SUBD(redex)->_2);
            // reg -> SUBD (reg, reg) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_SUBD(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_SUBD(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 10;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_SUBF: {
            labeler(_SUBF(redex)->_1);
            labeler(_SUBF(redex)->_2);
            // reg -> SUBF (reg, reg) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_SUBF(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_SUBF(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 9;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_SUBI: {
            labeler(_SUBI(redex)->_1);
            labeler(_SUBI(redex)->_2);
            // reg -> SUBI (reg, rc) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_SUBI(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_SUBI(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 41;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_SUBP: {
            labeler(_SUBP(redex)->_1);
            labeler(_SUBP(redex)->_2);
            // reg -> SUBP (reg, rc) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_SUBP(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_SUBP(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 40;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         case a_Inst::tag_SUBU: {
            labeler(_SUBU(redex)->_1);
            labeler(_SUBU(redex)->_2);
            // reg -> SUBU (reg, rc) \ 1: ...
            cost__ = 1 + (((_s_p_a_r_cco_X1_StateRec *)_SUBU(redex)->_1->get_state_rec())->cost[1] + (((_s_p_a_r_cco_X1_StateRec *)_SUBU(redex)->_2->get_state_rec())->cost[1] + 1));
            if (cost__ < _state_rec->cost[1])
            {   _state_rec->cost[1] = cost__;
                _state_rec->rule._reg = 39;
               _s_p_a_r_cco_X1_reg_closure(redex, cost__);
            }} break;
         default: {} break;
      }
   }
   
}

void _s_p_a_r_cco_X1::reduce(Inst redex,int lhs)
{
   const _s_p_a_r_cco_X1_StateRec * _state_rec = (const _s_p_a_r_cco_X1_StateRec *)(redex->get_state_rec());
   int r__;
   switch (lhs) {
      case 7: r__ = _s_p_a_r_cco_X1_base_accept[_state_rec->rule._base]; break;
      case 14: r__ = _s_p_a_r_cco_X1_call_accept[_state_rec->rule._call]; break;
      case 12: r__ = _s_p_a_r_cco_X1_rc5_accept[_state_rec->rule._rc5]; break;
      case 11: r__ = _s_p_a_r_cco_X1_rc_accept[_state_rec->rule._rc]; break;
      case 13: r__ = _s_p_a_r_cco_X1_addrg_accept[_state_rec->rule._addrg]; break;
      case 9: r__ = _s_p_a_r_cco_X1_addrl_accept[_state_rec->rule._addrl]; break;
      case 4: r__ = _s_p_a_r_cco_X1_stk13_accept[_state_rec->rule._stk13]; break;
      case 8: r__ = _s_p_a_r_cco_X1_addr_accept[_state_rec->rule._addr]; break;
      case 6: r__ = _s_p_a_r_cco_X1_con13_accept[_state_rec->rule._con13]; break;
      case 2: r__ = _s_p_a_r_cco_X1_stmt_accept[_state_rec->rule._stmt]; break;
      case 3: r__ = _s_p_a_r_cco_X1_con_accept[_state_rec->rule._con]; break;
      case 1: r__ = _s_p_a_r_cco_X1_reg_accept[_state_rec->rule._reg]; break;
      case 10: r__ = _s_p_a_r_cco_X1_spill_accept[_state_rec->rule._spill]; break;
      case 15: r__ = _s_p_a_r_cco_X1_rel_accept[_state_rec->rule._rel]; break;
      case 5: r__ = _s_p_a_r_cco_X1_stk_accept[_state_rec->rule._stk]; break;
      default: r__ = -1; break;
   }
   switch (r__) {
      case 184: { // ASGNB (reg, INDIRB reg)
         reduce(_ASGNB(redex)->_1,2); // stmt
         reduce(_INDIRB(_ASGNB(redex)->_2)->INDIRB,2); // stmt
         
#line 230 "sparc.pC"
        "# ASGNB\n"; 
#line 230 "sparc.pC"
} break;
      case 183: { // NEGD reg
         reduce(_NEGD(redex)->NEGD,1); // reg
         
#line 229 "sparc.pC"
        "# NEGD\n"; 
#line 229 "sparc.pC"
} break;
      case 182: { // LOADD reg
         reduce(_LOADD(redex)->LOADD,1); // reg
         
#line 228 "sparc.pC"
        "# LOADD\n"; 
#line 228 "sparc.pC"
} break;
      case 181: { // rel
         reduce(redex,2); // stmt
         
#line 227 "sparc.pC"
        "%0 %a; nop\n"; 
#line 227 "sparc.pC"
} break;
      case 180: { // NEF (reg, reg)
         reduce(_NEF(redex)->_1,15); // rel
         reduce(_NEF(redex)->_2,15); // rel
         
#line 226 "sparc.pC"
        "fcmpes %%f%0,%%f%1; nop; fbne"; 
#line 226 "sparc.pC"
} break;
      case 179: { // NED (reg, reg)
         reduce(_NED(redex)->_1,15); // rel
         reduce(_NED(redex)->_2,15); // rel
         
#line 225 "sparc.pC"
        "fcmped %%f%0,%%f%1; nop; fbne"; 
#line 225 "sparc.pC"
} break;
      case 178: { // LTF (reg, reg)
         reduce(_LTF(redex)->_1,15); // rel
         reduce(_LTF(redex)->_2,15); // rel
         
#line 224 "sparc.pC"
        "fcmpes %%f%0,%%f%1; nop; fbul"; 
#line 224 "sparc.pC"
} break;
      case 177: { // LTD (reg, reg)
         reduce(_LTD(redex)->_1,15); // rel
         reduce(_LTD(redex)->_2,15); // rel
         
#line 223 "sparc.pC"
        "fcmped %%f%0,%%f%1; nop; fbul"; 
#line 223 "sparc.pC"
} break;
      case 176: { // LEF (reg, reg)
         reduce(_LEF(redex)->_1,15); // rel
         reduce(_LEF(redex)->_2,15); // rel
         
#line 222 "sparc.pC"
        "fcmpes %%f%0,%%f%1; nop; fbule"; 
#line 222 "sparc.pC"
} break;
      case 175: { // LED (reg, reg)
         reduce(_LED(redex)->_1,15); // rel
         reduce(_LED(redex)->_2,15); // rel
         
#line 221 "sparc.pC"
        "fcmped %%f%0,%%f%1; nop; fbule"; 
#line 221 "sparc.pC"
} break;
      case 174: { // GTF (reg, reg)
         reduce(_GTF(redex)->_1,15); // rel
         reduce(_GTF(redex)->_2,15); // rel
         
#line 220 "sparc.pC"
        "fcmpes %%f%0,%%f%1; nop; fbug"; 
#line 220 "sparc.pC"
} break;
      case 173: { // GTD (reg, reg)
         reduce(_GTD(redex)->_1,15); // rel
         reduce(_GTD(redex)->_2,15); // rel
         
#line 219 "sparc.pC"
        "fcmped %%f%0,%%f%1; nop; fbug"; 
#line 219 "sparc.pC"
} break;
      case 172: { // GEF (reg, reg)
         reduce(_GEF(redex)->_1,15); // rel
         reduce(_GEF(redex)->_2,15); // rel
         
#line 218 "sparc.pC"
        "fcmpes %%f%0,%%f%1; nop; fbuge"; 
#line 218 "sparc.pC"
} break;
      case 171: { // GED (reg, reg)
         reduce(_GED(redex)->_1,15); // rel
         reduce(_GED(redex)->_2,15); // rel
         
#line 217 "sparc.pC"
        "fcmped %%f%0,%%f%1; nop; fbuge"; 
#line 217 "sparc.pC"
} break;
      case 170: { // EQF (reg, reg)
         reduce(_EQF(redex)->_1,15); // rel
         reduce(_EQF(redex)->_2,15); // rel
         
#line 216 "sparc.pC"
        "fcmpes %%f%0,%%f%1; nop; fbue"; 
#line 216 "sparc.pC"
} break;
      case 169: { // EQD (reg, reg)
         reduce(_EQD(redex)->_1,15); // rel
         reduce(_EQD(redex)->_2,15); // rel
         
#line 215 "sparc.pC"
        "fcmped %%f%0,%%f%1; nop; fbue"; 
#line 215 "sparc.pC"
} break;
      case 168: { // CVID reg
         reduce(_CVID(redex)->CVID,1); // reg
         
#line 214 "sparc.pC"
        "st %%%0,[%%sp+64]; ld [%%sp+64],%%f%c; fitod %%f%c,%%f%c\n"; 
#line 214 "sparc.pC"
} break;
      case 167: { // CVDI reg
         reduce(_CVDI(redex)->CVDI,1); // reg
         
#line 213 "sparc.pC"
        "fdtoi %%f%0,%%f0; st %%f0,[%%sp+64]; ld [%%sp+64],%%%c\n"; 
#line 213 "sparc.pC"
} break;
      case 166: { // CVFD reg
         reduce(_CVFD(redex)->CVFD,1); // reg
         
#line 212 "sparc.pC"
        "fstod %%f%0,%%f%c\n"; 
#line 212 "sparc.pC"
} break;
      case 165: { // CVDF reg
         reduce(_CVDF(redex)->CVDF,1); // reg
         
#line 211 "sparc.pC"
        "fdtos %%f%0,%%f%c\n"; 
#line 211 "sparc.pC"
} break;
      case 164: { // LOADF reg
         reduce(_LOADF(redex)->LOADF,1); // reg
         
#line 210 "sparc.pC"
        "fmovs %%f%0,%%f%c\n"; 
#line 210 "sparc.pC"
} break;
      case 163: { // NEGF reg
         reduce(_NEGF(redex)->NEGF,1); // reg
         
#line 209 "sparc.pC"
        "fnegs %%f%0,%%f%c\n"; 
#line 209 "sparc.pC"
} break;
      case 162: { // SUBF (reg, reg)
         reduce(_SUBF(redex)->_1,1); // reg
         reduce(_SUBF(redex)->_2,1); // reg
         
#line 208 "sparc.pC"
        "fsubs %%f%0,%%f%1,%%f%c\n"; 
#line 208 "sparc.pC"
} break;
      case 161: { // SUBD (reg, reg)
         reduce(_SUBD(redex)->_1,1); // reg
         reduce(_SUBD(redex)->_2,1); // reg
         
#line 207 "sparc.pC"
        "fsubd %%f%0,%%f%1,%%f%c\n"; 
#line 207 "sparc.pC"
} break;
      case 160: { // MULF (reg, reg)
         reduce(_MULF(redex)->_1,1); // reg
         reduce(_MULF(redex)->_2,1); // reg
         
#line 206 "sparc.pC"
        "fmuls %%f%0,%%f%1,%%f%c\n"; 
#line 206 "sparc.pC"
} break;
      case 159: { // MULD (reg, reg)
         reduce(_MULD(redex)->_1,1); // reg
         reduce(_MULD(redex)->_2,1); // reg
         
#line 205 "sparc.pC"
        "fmuld %%f%0,%%f%1,%%f%c\n"; 
#line 205 "sparc.pC"
} break;
      case 158: { // DIVF (reg, reg)
         reduce(_DIVF(redex)->_1,1); // reg
         reduce(_DIVF(redex)->_2,1); // reg
         
#line 204 "sparc.pC"
        "fdivs %%f%0,%%f%1,%%f%c\n"; 
#line 204 "sparc.pC"
} break;
      case 157: { // DIVD (reg, reg)
         reduce(_DIVD(redex)->_1,1); // reg
         reduce(_DIVD(redex)->_2,1); // reg
         
#line 203 "sparc.pC"
        "fdivd %%f%0,%%f%1,%%f%c\n"; 
#line 203 "sparc.pC"
} break;
      case 156: { // ADDF (reg, reg)
         reduce(_ADDF(redex)->_1,1); // reg
         reduce(_ADDF(redex)->_2,1); // reg
         
#line 202 "sparc.pC"
        "fadds %%f%0,%%f%1,%%f%c\n"; 
#line 202 "sparc.pC"
} break;
      case 155: { // ADDD (reg, reg)
         reduce(_ADDD(redex)->_1,1); // reg
         reduce(_ADDD(redex)->_2,1); // reg
         
#line 201 "sparc.pC"
        "faddd %%f%0,%%f%1,%%f%c\n"; 
#line 201 "sparc.pC"
} break;
      case 154: { // MULU (reg, reg)
         reduce(_MULU(redex)->_1,1); // reg
         reduce(_MULU(redex)->_2,1); // reg
         
#line 200 "sparc.pC"
        "call .umul,2; nop\n"; 
#line 200 "sparc.pC"
} break;
      case 153: { // MULI (reg, reg)
         reduce(_MULI(redex)->_1,1); // reg
         reduce(_MULI(redex)->_2,1); // reg
         
#line 199 "sparc.pC"
        "call .mul,2; nop\n"; 
#line 199 "sparc.pC"
} break;
      case 152: { // MODU (reg, reg)
         reduce(_MODU(redex)->_1,1); // reg
         reduce(_MODU(redex)->_2,1); // reg
         
#line 198 "sparc.pC"
        "call .urem,2; nop\n"; 
#line 198 "sparc.pC"
} break;
      case 151: { // MODI (reg, reg)
         reduce(_MODI(redex)->_1,1); // reg
         reduce(_MODI(redex)->_2,1); // reg
         
#line 197 "sparc.pC"
        "call .rem,2; nop\n"; 
#line 197 "sparc.pC"
} break;
      case 150: { // DIVU (reg, reg)
         reduce(_DIVU(redex)->_1,1); // reg
         reduce(_DIVU(redex)->_2,1); // reg
         
#line 196 "sparc.pC"
        "call .udiv,2; nop\n"; 
#line 196 "sparc.pC"
} break;
      case 149: { // DIVI (reg, reg)
         reduce(_DIVI(redex)->_1,1); // reg
         reduce(_DIVI(redex)->_2,1); // reg
         
#line 195 "sparc.pC"
        "call .div,2; nop\n"; 
#line 195 "sparc.pC"
} break;
      case 148: { // ARGF reg
         reduce(_ARGF(redex)->ARGF,2); // stmt
         
#line 194 "sparc.pC"
        "# ARGF\n"; 
#line 194 "sparc.pC"
} break;
      case 147: { // ARGD reg
         reduce(_ARGD(redex)->ARGD,2); // stmt
         
#line 193 "sparc.pC"
        "# ARGD\n"; 
#line 193 "sparc.pC"
} break;
      case 146: { // ARGP reg
         reduce(_ARGP(redex)->ARGP,2); // stmt
         
#line 192 "sparc.pC"
        "st %%%0,[%%sp+4*%c+68]\n"; 
#line 192 "sparc.pC"
} break;
      case 145: { // ARGI reg
         reduce(_ARGI(redex)->ARGI,2); // stmt
         
#line 191 "sparc.pC"
        "st %%%0,[%%sp+4*%c+68]\n"; 
#line 191 "sparc.pC"
} break;
      case 144: { // RETI reg
         reduce(_RETI(redex)->RETI,2); // stmt
         
#line 190 "sparc.pC"
        "# ret\n"; 
#line 190 "sparc.pC"
} break;
      case 143: { // RETF reg
         reduce(_RETF(redex)->RETF,2); // stmt
         
#line 189 "sparc.pC"
        "# ret\n"; 
#line 189 "sparc.pC"
} break;
      case 142: { // RETD reg
         reduce(_RETD(redex)->RETD,2); // stmt
         
#line 188 "sparc.pC"
        "# ret\n"; 
#line 188 "sparc.pC"
} break;
      case 141: { // CALLB (call, reg)
         reduce(_CALLB(redex)->_1,2); // stmt
         reduce(_CALLB(redex)->_2,2); // stmt
         
#line 187 "sparc.pC"
        "call %0; st %%%1,[%%sp+64]\n"; 
#line 187 "sparc.pC"
} break;
      case 140: { // CALLV call
         reduce(_CALLV(redex)->CALLV,2); // stmt
         
#line 186 "sparc.pC"
        "call %0; nop\n"; 
#line 186 "sparc.pC"
} break;
      case 139: { // CALLI call
         reduce(_CALLI(redex)->CALLI,1); // reg
         
#line 185 "sparc.pC"
        "call %0; nop\n"; 
#line 185 "sparc.pC"
} break;
      case 138: { // CALLF call
         reduce(_CALLF(redex)->CALLF,1); // reg
         
#line 184 "sparc.pC"
        "call %0; nop\n"; 
#line 184 "sparc.pC"
} break;
      case 137: { // CALLD call
         reduce(_CALLD(redex)->CALLD,1); // reg
         
#line 183 "sparc.pC"
        "call %0; nop\n"; 
#line 183 "sparc.pC"
} break;
      case 136: { // addr
         reduce(redex,14); // call
         
#line 182 "sparc.pC"
        "%0"; 
#line 182 "sparc.pC"
} break;
      case 135: { // ADDRGP ()
         
#line 181 "sparc.pC"
        "%a"; 
#line 181 "sparc.pC"
} break;
      case 134: { // NEI (reg, rc)
         reduce(_NEI(redex)->_1,2); // stmt
         reduce(_NEI(redex)->_2,2); // stmt
         
#line 180 "sparc.pC"
        "cmp %%%0,%1; bne %a; nop\n"; 
#line 180 "sparc.pC"
} break;
      case 133: { // LTU (reg, rc)
         reduce(_LTU(redex)->_1,2); // stmt
         reduce(_LTU(redex)->_2,2); // stmt
         
#line 179 "sparc.pC"
        "cmp %%%0,%1; blu %a; nop\n"; 
#line 179 "sparc.pC"
} break;
      case 132: { // LTI (reg, rc)
         reduce(_LTI(redex)->_1,2); // stmt
         reduce(_LTI(redex)->_2,2); // stmt
         
#line 178 "sparc.pC"
        "cmp %%%0,%1; bl %a; nop\n"; 
#line 178 "sparc.pC"
} break;
      case 131: { // LEU (reg, rc)
         reduce(_LEU(redex)->_1,2); // stmt
         reduce(_LEU(redex)->_2,2); // stmt
         
#line 177 "sparc.pC"
        "cmp %%%0,%1; bleu %a; nop\n"; 
#line 177 "sparc.pC"
} break;
      case 130: { // LEI (reg, rc)
         reduce(_LEI(redex)->_1,2); // stmt
         reduce(_LEI(redex)->_2,2); // stmt
         
#line 176 "sparc.pC"
        "cmp %%%0,%1; ble %a; nop\n"; 
#line 176 "sparc.pC"
} break;
      case 129: { // GTU (reg, rc)
         reduce(_GTU(redex)->_1,2); // stmt
         reduce(_GTU(redex)->_2,2); // stmt
         
#line 175 "sparc.pC"
        "cmp %%%0,%1; bgu %a; nop\n"; 
#line 175 "sparc.pC"
} break;
      case 128: { // GTI (reg, rc)
         reduce(_GTI(redex)->_1,2); // stmt
         reduce(_GTI(redex)->_2,2); // stmt
         
#line 174 "sparc.pC"
        "cmp %%%0,%1; bg %a; nop\n"; 
#line 174 "sparc.pC"
} break;
      case 127: { // GEU (reg, rc)
         reduce(_GEU(redex)->_1,2); // stmt
         reduce(_GEU(redex)->_2,2); // stmt
         
#line 173 "sparc.pC"
        "cmp %%%0,%1; bgeu %a; nop\n"; 
#line 173 "sparc.pC"
} break;
      case 126: { // GEI (reg, rc)
         reduce(_GEI(redex)->_1,2); // stmt
         reduce(_GEI(redex)->_2,2); // stmt
         
#line 172 "sparc.pC"
        "cmp %%%0,%1; bge %a; nop\n"; 
#line 172 "sparc.pC"
} break;
      case 125: { // EQI (reg, rc)
         reduce(_EQI(redex)->_1,2); // stmt
         reduce(_EQI(redex)->_2,2); // stmt
         
#line 171 "sparc.pC"
        "cmp %%%0,%1; be %a; nop\n"; 
#line 171 "sparc.pC"
} break;
      case 124: { // LABELV ()
         
#line 170 "sparc.pC"
        "%a:\n"; 
#line 170 "sparc.pC"
} break;
      case 123: { // JUMPV addr
         reduce(_JUMPV(redex)->JUMPV,2); // stmt
         
#line 169 "sparc.pC"
        "jmp %0; nop\n"; 
#line 169 "sparc.pC"
} break;
      case 122: { // JUMPV addrg
         reduce(_JUMPV(redex)->JUMPV,2); // stmt
         
#line 168 "sparc.pC"
        "ba %0; nop\n"; 
#line 168 "sparc.pC"
} break;
      case 121: { // ADDRGP ()
         
#line 167 "sparc.pC"
        "%a"; 
#line 167 "sparc.pC"
} break;
      case 120: { // CVSU reg
         reduce(_CVSU(redex)->CVSU,1); // reg
         
#line 166 "sparc.pC"
        "set 0xffff,%%g1; and %%%0,%%g1,%%%c\n"; 
#line 166 "sparc.pC"
} break;
      case 119: { // CVCU reg
         reduce(_CVCU(redex)->CVCU,1); // reg
         
#line 165 "sparc.pC"
        "and %%%0,0xff,%%%c\n"; 
#line 165 "sparc.pC"
} break;
      case 118: { // CVSI reg
         reduce(_CVSI(redex)->CVSI,1); // reg
         
#line 164 "sparc.pC"
        "sll %%%0,16,%%%c; sra %%%c,16,%%%c\n"; 
#line 164 "sparc.pC"
} break;
      case 117: { // CVCI reg
         reduce(_CVCI(redex)->CVCI,1); // reg
         
#line 163 "sparc.pC"
        "sll %%%0,24,%%%c; sra %%%c,24,%%%c\n"; 
#line 163 "sparc.pC"
} break;
      case 116: { // BCOMU reg
         reduce(_BCOMU(redex)->BCOMU,1); // reg
         
#line 162 "sparc.pC"
        "not %%%0,%%%c\n"; 
#line 162 "sparc.pC"
} break;
      case 115: { // NEGI reg
         reduce(_NEGI(redex)->NEGI,1); // reg
         
#line 161 "sparc.pC"
        "neg %%%0,%%%c\n"; 
#line 161 "sparc.pC"
} break;
      case 114: { // BXORU (reg, BCOMU rc)
         reduce(_BXORU(redex)->_1,1); // reg
         reduce(_BCOMU(_BXORU(redex)->_2)->BCOMU,1); // reg
         
#line 160 "sparc.pC"
        "xnor %%%0,%1,%%%c\n"; 
#line 160 "sparc.pC"
} break;
      case 113: { // BORU (reg, BCOMU rc)
         reduce(_BORU(redex)->_1,1); // reg
         reduce(_BCOMU(_BORU(redex)->_2)->BCOMU,1); // reg
         
#line 159 "sparc.pC"
        "orn %%%0,%1,%%%c\n"; 
#line 159 "sparc.pC"
} break;
      case 112: { // BANDU (reg, BCOMU rc)
         reduce(_BANDU(redex)->_1,1); // reg
         reduce(_BCOMU(_BANDU(redex)->_2)->BCOMU,1); // reg
         
#line 158 "sparc.pC"
        "andn %%%0,%1,%%%c\n"; 
#line 158 "sparc.pC"
} break;
      case 111: { // RSHU (reg, rc5)
         reduce(_RSHU(redex)->_1,1); // reg
         reduce(_RSHU(redex)->_2,1); // reg
         
#line 157 "sparc.pC"
        "srl %%%0,%1,%%%c\n"; 
#line 157 "sparc.pC"
} break;
      case 110: { // RSHI (reg, rc5)
         reduce(_RSHI(redex)->_1,1); // reg
         reduce(_RSHI(redex)->_2,1); // reg
         
#line 156 "sparc.pC"
        "sra %%%0,%1,%%%c\n"; 
#line 156 "sparc.pC"
} break;
      case 109: { // LSHU (reg, rc5)
         reduce(_LSHU(redex)->_1,1); // reg
         reduce(_LSHU(redex)->_2,1); // reg
         
#line 155 "sparc.pC"
        "sll %%%0,%1,%%%c\n"; 
#line 155 "sparc.pC"
} break;
      case 108: { // LSHI (reg, rc5)
         reduce(_LSHI(redex)->_1,1); // reg
         reduce(_LSHI(redex)->_2,1); // reg
         
#line 154 "sparc.pC"
        "sll %%%0,%1,%%%c\n"; 
#line 154 "sparc.pC"
} break;
      case 107: { // reg
         reduce(redex,12); // rc5
         
#line 153 "sparc.pC"
        "%%%0"; 
#line 153 "sparc.pC"
} break;
      case 106: { // CNSTI ()
         
#line 152 "sparc.pC"
        "%a"; 
#line 152 "sparc.pC"
} break;
      case 105: { // SUBU (reg, rc)
         reduce(_SUBU(redex)->_1,1); // reg
         reduce(_SUBU(redex)->_2,1); // reg
         
#line 151 "sparc.pC"
        "sub %%%0,%1,%%%c\n"; 
#line 151 "sparc.pC"
} break;
      case 104: { // SUBP (reg, rc)
         reduce(_SUBP(redex)->_1,1); // reg
         reduce(_SUBP(redex)->_2,1); // reg
         
#line 150 "sparc.pC"
        "sub %%%0,%1,%%%c\n"; 
#line 150 "sparc.pC"
} break;
      case 103: { // SUBI (reg, rc)
         reduce(_SUBI(redex)->_1,1); // reg
         reduce(_SUBI(redex)->_2,1); // reg
         
#line 149 "sparc.pC"
        "sub %%%0,%1,%%%c\n"; 
#line 149 "sparc.pC"
} break;
      case 102: { // BXORU (reg, rc)
         reduce(_BXORU(redex)->_1,1); // reg
         reduce(_BXORU(redex)->_2,1); // reg
         
#line 148 "sparc.pC"
        "xor %%%0,%1,%%%c\n"; 
#line 148 "sparc.pC"
} break;
      case 101: { // BORU (reg, rc)
         reduce(_BORU(redex)->_1,1); // reg
         reduce(_BORU(redex)->_2,1); // reg
         
#line 147 "sparc.pC"
        "or %%%0,%1,%%%c\n" ; 
#line 147 "sparc.pC"
} break;
      case 100: { // BANDU (reg, rc)
         reduce(_BANDU(redex)->_1,1); // reg
         reduce(_BANDU(redex)->_2,1); // reg
         
#line 146 "sparc.pC"
        "and %%%0,%1,%%%c\n"; 
#line 146 "sparc.pC"
} break;
      case 99: { // ADDU (reg, rc)
         reduce(_ADDU(redex)->_1,1); // reg
         reduce(_ADDU(redex)->_2,1); // reg
         
#line 145 "sparc.pC"
        "add %%%0,%1,%%%c\n"; 
#line 145 "sparc.pC"
} break;
      case 98: { // ADDP (reg, rc)
         reduce(_ADDP(redex)->_1,1); // reg
         reduce(_ADDP(redex)->_2,1); // reg
         
#line 144 "sparc.pC"
        "add %%%0,%1,%%%c\n"; 
#line 144 "sparc.pC"
} break;
      case 97: { // ADDI (reg, rc)
         reduce(_ADDI(redex)->_1,1); // reg
         reduce(_ADDI(redex)->_2,1); // reg
         
#line 143 "sparc.pC"
        "add %%%0,%1,%%%c\n"; 
#line 143 "sparc.pC"
} break;
      case 96: { // reg
         reduce(redex,11); // rc
         
#line 142 "sparc.pC"
        "%%%0"; 
#line 142 "sparc.pC"
} break;
      case 95: { // con13
         reduce(redex,11); // rc
         
#line 141 "sparc.pC"
        "%0"; 
#line 141 "sparc.pC"
} break;
      case 94: { // con
         reduce(redex,1); // reg
         
#line 140 "sparc.pC"
        "set %0,%%%c\n"; 
#line 140 "sparc.pC"
} break;
      case 93: { // CNSTU ()
         
#line 139 "sparc.pC"
        "# reg\n"; 
#line 139 "sparc.pC"
} break;
      case 92: { // CNSTS ()
         
#line 138 "sparc.pC"
        "# reg\n"; 
#line 138 "sparc.pC"
} break;
      case 91: { // CNSTP ()
         
#line 137 "sparc.pC"
        "# reg\n"; 
#line 137 "sparc.pC"
} break;
      case 90: { // CNSTI ()
         
#line 136 "sparc.pC"
        "# reg\n"; 
#line 136 "sparc.pC"
} break;
      case 89: { // CNSTC ()
         
#line 135 "sparc.pC"
        "# reg\n"; 
#line 135 "sparc.pC"
} break;
      case 88: { // LOADU reg
         reduce(_LOADU(redex)->LOADU,1); // reg
         
#line 134 "sparc.pC"
        "mov %%%0,%%%c\n"; 
#line 134 "sparc.pC"
} break;
      case 87: { // LOADS reg
         reduce(_LOADS(redex)->LOADS,1); // reg
         
#line 133 "sparc.pC"
        "mov %%%0,%%%c\n"; 
#line 133 "sparc.pC"
} break;
      case 86: { // LOADP reg
         reduce(_LOADP(redex)->LOADP,1); // reg
         
#line 132 "sparc.pC"
        "mov %%%0,%%%c\n"; 
#line 132 "sparc.pC"
} break;
      case 85: { // LOADI reg
         reduce(_LOADI(redex)->LOADI,1); // reg
         
#line 131 "sparc.pC"
        "mov %%%0,%%%c\n"; 
#line 131 "sparc.pC"
} break;
      case 84: { // LOADC reg
         reduce(_LOADC(redex)->LOADC,1); // reg
         
#line 130 "sparc.pC"
        "mov %%%0,%%%c\n"; 
#line 130 "sparc.pC"
} break;
      case 83: { // CVUS reg
         reduce(_CVUS(redex)->CVUS,1); // reg
         
#line 129 "sparc.pC"
        "%0"; 
#line 129 "sparc.pC"
} break;
      case 82: { // CVUC reg
         reduce(_CVUC(redex)->CVUC,1); // reg
         
#line 128 "sparc.pC"
        "%0"; 
#line 128 "sparc.pC"
} break;
      case 81: { // CVIS reg
         reduce(_CVIS(redex)->CVIS,1); // reg
         
#line 127 "sparc.pC"
        "%0"; 
#line 127 "sparc.pC"
} break;
      case 80: { // CVIC reg
         reduce(_CVIC(redex)->CVIC,1); // reg
         
#line 126 "sparc.pC"
        "%0"; 
#line 126 "sparc.pC"
} break;
      case 79: { // CVUS reg
         reduce(_CVUS(redex)->CVUS,1); // reg
         
#line 125 "sparc.pC"
        "mov %%%0,%%%c\n"; 
#line 125 "sparc.pC"
} break;
      case 78: { // CVUP reg
         reduce(_CVUP(redex)->CVUP,1); // reg
         
#line 124 "sparc.pC"
        "mov %%%0,%%%c\n"; 
#line 124 "sparc.pC"
} break;
      case 77: { // CVUI reg
         reduce(_CVUI(redex)->CVUI,1); // reg
         
#line 123 "sparc.pC"
        "mov %%%0,%%%c\n"; 
#line 123 "sparc.pC"
} break;
      case 76: { // CVUC reg
         reduce(_CVUC(redex)->CVUC,1); // reg
         
#line 122 "sparc.pC"
        "mov %%%0,%%%c\n"; 
#line 122 "sparc.pC"
} break;
      case 75: { // CVPU reg
         reduce(_CVPU(redex)->CVPU,1); // reg
         
#line 121 "sparc.pC"
        "mov %%%0,%%%c\n"; 
#line 121 "sparc.pC"
} break;
      case 74: { // CVIU reg
         reduce(_CVIU(redex)->CVIU,1); // reg
         
#line 120 "sparc.pC"
        "mov %%%0,%%%c\n"; 
#line 120 "sparc.pC"
} break;
      case 73: { // CVIS reg
         reduce(_CVIS(redex)->CVIS,1); // reg
         
#line 119 "sparc.pC"
        "mov %%%0,%%%c\n"; 
#line 119 "sparc.pC"
} break;
      case 72: { // CVIC reg
         reduce(_CVIC(redex)->CVIC,1); // reg
         
#line 118 "sparc.pC"
        "mov %%%0,%%%c\n"; 
#line 118 "sparc.pC"
} break;
      case 71: { // CVSU INDIRS addr
         reduce(_INDIRS(_CVSU(redex)->CVSU)->INDIRS,1); // reg
         
#line 117 "sparc.pC"
        "lduh [%0],%%%c\n"; 
#line 117 "sparc.pC"
} break;
      case 70: { // CVCU INDIRC addr
         reduce(_INDIRC(_CVCU(redex)->CVCU)->INDIRC,1); // reg
         
#line 116 "sparc.pC"
        "ldub [%0],%%%c\n"; 
#line 116 "sparc.pC"
} break;
      case 69: { // CVSI INDIRS addr
         reduce(_INDIRS(_CVSI(redex)->CVSI)->INDIRS,1); // reg
         
#line 115 "sparc.pC"
        "ldsh [%0],%%%c\n"; 
#line 115 "sparc.pC"
} break;
      case 68: { // CVCI INDIRC addr
         reduce(_INDIRC(_CVCI(redex)->CVCI)->INDIRC,1); // reg
         
#line 114 "sparc.pC"
        "ldsb [%0],%%%c\n"; 
#line 114 "sparc.pC"
} break;
      case 67: { // ASGND (spill, reg)
         reduce(_ASGND(redex)->_1,2); // stmt
         reduce(_ASGND(redex)->_2,2); // stmt
         
#line 113 "sparc.pC"
        "set %0,%%g1\nstd %%f%1,[%%fp+%%g1]\n"; 
#line 113 "sparc.pC"
} break;
      case 66: { // ASGNF (spill, reg)
         reduce(_ASGNF(redex)->_1,2); // stmt
         reduce(_ASGNF(redex)->_2,2); // stmt
         
#line 112 "sparc.pC"
        "set %0,%%g1\nst %%f%1,[%%fp+%%g1]\n"; 
#line 112 "sparc.pC"
} break;
      case 65: { // ASGNP (spill, reg)
         reduce(_ASGNP(redex)->_1,2); // stmt
         reduce(_ASGNP(redex)->_2,2); // stmt
         
#line 111 "sparc.pC"
        "set %0,%%g1\nst %%%1,[%%fp+%%g1]\n"; 
#line 111 "sparc.pC"
} break;
      case 64: { // ASGNI (spill, reg)
         reduce(_ASGNI(redex)->_1,2); // stmt
         reduce(_ASGNI(redex)->_2,2); // stmt
         
#line 110 "sparc.pC"
        "set %0,%%g1\nst %%%1,[%%fp+%%g1]\n"; 
#line 110 "sparc.pC"
} break;
      case 63: { // ASGNS (spill, reg)
         reduce(_ASGNS(redex)->_1,2); // stmt
         reduce(_ASGNS(redex)->_2,2); // stmt
         
#line 109 "sparc.pC"
        "set %0,%%g1\nsth %%%1,[%%fp+%%g1]\n"; 
#line 109 "sparc.pC"
} break;
      case 62: { // ASGNC (spill, reg)
         reduce(_ASGNC(redex)->_1,2); // stmt
         reduce(_ASGNC(redex)->_2,2); // stmt
         
#line 108 "sparc.pC"
        "set %0,%%g1\nstb %%%1,[%%fp+%%g1]\n"; 
#line 108 "sparc.pC"
} break;
      case 61: { // ADDRLP ()
         
#line 107 "sparc.pC"
        "%a"; 
#line 107 "sparc.pC"
} break;
      case 60: { // ASGND (base, reg)
         reduce(_ASGND(redex)->_1,2); // stmt
         reduce(_ASGND(redex)->_2,2); // stmt
         
#line 106 "sparc.pC"
        "st2 %%f%1,[%0]\n"; 
#line 106 "sparc.pC"
} break;
      case 59: { // INDIRD base
         reduce(_INDIRD(redex)->INDIRD,1); // reg
         
#line 105 "sparc.pC"
        "ld2 [%0],%%f%c\n"; 
#line 105 "sparc.pC"
} break;
      case 58: { // ASGND (addrl, reg)
         reduce(_ASGND(redex)->_1,2); // stmt
         reduce(_ASGND(redex)->_2,2); // stmt
         
#line 104 "sparc.pC"
        "std %%f%1,[%0]\n"; 
#line 104 "sparc.pC"
} break;
      case 57: { // INDIRD addrl
         reduce(_INDIRD(redex)->INDIRD,1); // reg
         
#line 103 "sparc.pC"
        "ldd [%0],%%f%c\n"; 
#line 103 "sparc.pC"
} break;
      case 56: { // ADDRLP ()
         
#line 102 "sparc.pC"
        "%%%fp+%a"; 
#line 102 "sparc.pC"
} break;
      case 55: { // ASGNF (addr, reg)
         reduce(_ASGNF(redex)->_1,2); // stmt
         reduce(_ASGNF(redex)->_2,2); // stmt
         
#line 101 "sparc.pC"
        "st %%f%1,[%0]\n"; 
#line 101 "sparc.pC"
} break;
      case 54: { // ASGNP (addr, reg)
         reduce(_ASGNP(redex)->_1,2); // stmt
         reduce(_ASGNP(redex)->_2,2); // stmt
         
#line 100 "sparc.pC"
        "st %%%1,[%0]\n"; 
#line 100 "sparc.pC"
} break;
      case 53: { // ASGNI (addr, reg)
         reduce(_ASGNI(redex)->_1,2); // stmt
         reduce(_ASGNI(redex)->_2,2); // stmt
         
#line 99 "sparc.pC"
        "st %%%1,[%0]\n"; 
#line 99 "sparc.pC"
} break;
      case 52: { // ASGNS (addr, reg)
         reduce(_ASGNS(redex)->_1,2); // stmt
         reduce(_ASGNS(redex)->_2,2); // stmt
         
#line 98 "sparc.pC"
        "sth %%%1,[%0]\n"; 
#line 98 "sparc.pC"
} break;
      case 51: { // ASGNC (addr, reg)
         reduce(_ASGNC(redex)->_1,2); // stmt
         reduce(_ASGNC(redex)->_2,2); // stmt
         
#line 97 "sparc.pC"
        "stb %%%1,[%0]\n"; 
#line 97 "sparc.pC"
} break;
      case 50: { // INDIRF addr
         reduce(_INDIRF(redex)->INDIRF,1); // reg
         
#line 96 "sparc.pC"
        "ld [%0],%%f%c\n"; 
#line 96 "sparc.pC"
} break;
      case 49: { // INDIRP addr
         reduce(_INDIRP(redex)->INDIRP,1); // reg
         
#line 95 "sparc.pC"
        "ld [%0],%%%c\n"; 
#line 95 "sparc.pC"
} break;
      case 48: { // INDIRI addr
         reduce(_INDIRI(redex)->INDIRI,1); // reg
         
#line 94 "sparc.pC"
        "ld [%0],%%%c\n"; 
#line 94 "sparc.pC"
} break;
      case 47: { // INDIRS addr
         reduce(_INDIRS(redex)->INDIRS,1); // reg
         
#line 93 "sparc.pC"
        "ldsh [%0],%%%c\n"; 
#line 93 "sparc.pC"
} break;
      case 46: { // INDIRC addr
         reduce(_INDIRC(redex)->INDIRC,1); // reg
         
#line 92 "sparc.pC"
        "ldsb [%0],%%%c\n"; 
#line 92 "sparc.pC"
} break;
      case 45: { // stk
         reduce(redex,8); // addr
         
#line 91 "sparc.pC"
        "%%fp+%%%0"; 
#line 91 "sparc.pC"
} break;
      case 44: { // ADDU (reg, reg)
         reduce(_ADDU(redex)->_1,8); // addr
         reduce(_ADDU(redex)->_2,8); // addr
         
#line 90 "sparc.pC"
        "%%%0+%%%1"; 
#line 90 "sparc.pC"
} break;
      case 43: { // ADDP (reg, reg)
         reduce(_ADDP(redex)->_1,8); // addr
         reduce(_ADDP(redex)->_2,8); // addr
         
#line 89 "sparc.pC"
        "%%%0+%%%1"; 
#line 89 "sparc.pC"
} break;
      case 42: { // ADDI (reg, reg)
         reduce(_ADDI(redex)->_1,8); // addr
         reduce(_ADDI(redex)->_2,8); // addr
         
#line 88 "sparc.pC"
        "%%%0+%%%1"; 
#line 88 "sparc.pC"
} break;
      case 41: { // base
         reduce(redex,8); // addr
         
#line 87 "sparc.pC"
        "%0"; 
#line 87 "sparc.pC"
} break;
      case 40: { // stk13
         reduce(redex,7); // base
         
#line 86 "sparc.pC"
        "%%fp+%0"; 
#line 86 "sparc.pC"
} break;
      case 39: { // con13
         reduce(redex,7); // base
         
#line 85 "sparc.pC"
        "%0"; 
#line 85 "sparc.pC"
} break;
      case 38: { // reg
         reduce(redex,7); // base
         
#line 84 "sparc.pC"
        "%%%0"; 
#line 84 "sparc.pC"
} break;
      case 37: { // ADDU (reg, con13)
         reduce(_ADDU(redex)->_1,7); // base
         reduce(_ADDU(redex)->_2,7); // base
         
#line 83 "sparc.pC"
        "%%%0+%1"; 
#line 83 "sparc.pC"
} break;
      case 36: { // ADDP (reg, con13)
         reduce(_ADDP(redex)->_1,7); // base
         reduce(_ADDP(redex)->_2,7); // base
         
#line 82 "sparc.pC"
        "%%%0+%1"; 
#line 82 "sparc.pC"
} break;
      case 35: { // ADDI (reg, con13)
         reduce(_ADDI(redex)->_1,7); // base
         reduce(_ADDI(redex)->_2,7); // base
         
#line 81 "sparc.pC"
        "%%%0+%1"; 
#line 81 "sparc.pC"
} break;
      case 34: { // CNSTU ()
         
#line 80 "sparc.pC"
        "%a"; 
#line 80 "sparc.pC"
} break;
      case 33: { // CNSTS ()
         
#line 79 "sparc.pC"
        "%a"; 
#line 79 "sparc.pC"
} break;
      case 32: { // CNSTP ()
         
#line 78 "sparc.pC"
        "%a"; 
#line 78 "sparc.pC"
} break;
      case 31: { // CNSTI ()
         
#line 77 "sparc.pC"
        "%a"; 
#line 77 "sparc.pC"
} break;
      case 30: { // CNSTC ()
         
#line 76 "sparc.pC"
        "%a"; 
#line 76 "sparc.pC"
} break;
      case 29: { // ADDRLP ()
         
#line 75 "sparc.pC"
        "set %a,%%%c\nadd %%%c,%%fp,%%%c\n"; 
#line 75 "sparc.pC"
} break;
      case 28: { // ADDRFP ()
         
#line 74 "sparc.pC"
        "set %a,%%%c\nadd %%%c,%%fp,%%%c\n"; 
#line 74 "sparc.pC"
} break;
      case 27: { // ADDRLP ()
         
#line 73 "sparc.pC"
        "set %a,%%%c\n"; 
#line 73 "sparc.pC"
} break;
      case 26: { // ADDRFP ()
         
#line 72 "sparc.pC"
        "set %a,%%%c\n"; 
#line 72 "sparc.pC"
} break;
      case 25: { // stk13
         reduce(redex,1); // reg
         
#line 71 "sparc.pC"
        "add %0,%%fp,%%%c\n"; 
#line 71 "sparc.pC"
} break;
      case 24: { // ADDRLP ()
         
#line 70 "sparc.pC"
        "%a"; 
#line 70 "sparc.pC"
} break;
      case 23: { // ADDRFP ()
         
#line 69 "sparc.pC"
        "%a"; 
#line 69 "sparc.pC"
} break;
      case 22: { // ADDRGP ()
         
#line 68 "sparc.pC"
        "set %a,%%%c\n"; 
#line 68 "sparc.pC"
} break;
      case 21: { // CVUP reg
         reduce(_CVUP(redex)->CVUP,1); // reg
         
#line 67 "sparc.pC"
        "%0"; 
#line 67 "sparc.pC"
} break;
      case 20: { // CVUI reg
         reduce(_CVUI(redex)->CVUI,1); // reg
         
#line 66 "sparc.pC"
        "%0"; 
#line 66 "sparc.pC"
} break;
      case 19: { // CVPU reg
         reduce(_CVPU(redex)->CVPU,1); // reg
         
#line 65 "sparc.pC"
        "%0"; 
#line 65 "sparc.pC"
} break;
      case 18: { // CVIU reg
         reduce(_CVIU(redex)->CVIU,1); // reg
         
#line 64 "sparc.pC"
        "%0"; 
#line 64 "sparc.pC"
} break;
      case 17: { // reg
         reduce(redex,2); // stmt
         
#line 63 "sparc.pC"
        ""; 
#line 63 "sparc.pC"
} break;
      case 16: { // CNSTU ()
         
#line 62 "sparc.pC"
        "%a"; 
#line 62 "sparc.pC"
} break;
      case 15: { // CNSTS ()
         
#line 61 "sparc.pC"
        "%a"; 
#line 61 "sparc.pC"
} break;
      case 14: { // CNSTP ()
         
#line 60 "sparc.pC"
        "%a"; 
#line 60 "sparc.pC"
} break;
      case 13: { // CNSTI ()
         
#line 59 "sparc.pC"
        "%a"; 
#line 59 "sparc.pC"
} break;
      case 12: { // CNSTC ()
         
#line 58 "sparc.pC"
        "%a"; 
#line 58 "sparc.pC"
} break;
      case 11: { // ASGNS (VREGP (), reg)
         reduce(_ASGNS(redex)->_2,2); // stmt
         
#line 57 "sparc.pC"
        "# write register\n"; 
#line 57 "sparc.pC"
} break;
      case 10: { // ASGNP (VREGP (), reg)
         reduce(_ASGNP(redex)->_2,2); // stmt
         
#line 56 "sparc.pC"
        "# write register\n"; 
#line 56 "sparc.pC"
} break;
      case 9: { // ASGNI (VREGP (), reg)
         reduce(_ASGNI(redex)->_2,2); // stmt
         
#line 55 "sparc.pC"
        "# write register\n"; 
#line 55 "sparc.pC"
} break;
      case 8: { // ASGNF (VREGP (), reg)
         reduce(_ASGNF(redex)->_2,2); // stmt
         
#line 54 "sparc.pC"
        "# write register\n"; 
#line 54 "sparc.pC"
} break;
      case 7: { // ASGND (VREGP (), reg)
         reduce(_ASGND(redex)->_2,2); // stmt
         
#line 53 "sparc.pC"
        "# write register\n"; 
#line 53 "sparc.pC"
} break;
      case 6: { // ASGNC (VREGP (), reg)
         reduce(_ASGNC(redex)->_2,2); // stmt
         
#line 52 "sparc.pC"
        "# write register\n"; 
#line 52 "sparc.pC"
} break;
      case 5: { // INDIRS VREGP ()
         
#line 51 "sparc.pC"
        "# read register\n"; 
#line 51 "sparc.pC"
} break;
      case 4: { // INDIRP VREGP ()
         
#line 50 "sparc.pC"
        "# read register\n"; 
#line 50 "sparc.pC"
} break;
      case 3: { // INDIRI VREGP ()
         
#line 49 "sparc.pC"
        "# read register\n"; 
#line 49 "sparc.pC"
} break;
      case 2: { // INDIRF VREGP ()
         
#line 48 "sparc.pC"
        "# read register\n"; 
#line 48 "sparc.pC"
} break;
      case 1: { // INDIRD VREGP ()
         
#line 47 "sparc.pC"
        "# read register\n"; 
#line 47 "sparc.pC"
} break;
      case 0: { // INDIRC VREGP ()
         
#line 46 "sparc.pC"
        "# read register\n"; 
#line 46 "sparc.pC"
} break;
   }
}

/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 2327
Number of ifs generated      = 0
Number of switches generated = 21
Number of labels             = 0
Number of gotos              = 0
Adaptive matching            = disabled
Fast string matching         = disabled
Inline downcasts             = disabled
--------------------------------------------------------------------------
*/
