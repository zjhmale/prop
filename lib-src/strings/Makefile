#############################################################################
#  The following parameters must be altered for each platform and compiler.
#  The default is for g++ on Unix and MSDOG.
#############################################################################
ADLIB_PATH	=	../../include
CC		=	g++
COPTS		=	-O6
CINCLUDE	=	-I$(ADLIB_PATH)

ad		=	$(ADLIB_PATH)/AD
D		=	$(ADLIB_PATH)/AD/strings

OBJS	= atom.$(OBJ) bm.$(OBJ) charesc.$(OBJ) fansu.$(OBJ) kmp.$(OBJ) kr.$(OBJ)
OBJS2	= quark.$(OBJ) regexp.$(OBJ) shiftadd.$(OBJ) string.$(OBJ) strmatch.$(OBJ) twoway.$(OBJ)

all:	$(OBJS) $(OBJS2)

approx.$(OBJ):	approx.cc $D/approx.h $D/shiftadd.h $(ad)/generic/generic.h
atom.$(OBJ):		atom.cc $D/atom.h $(ad)/generic/generic.h $(ad)/hash/dchash.h
bm.$(OBJ):		bm.cc $D/bm.h $D/strmatch.h $(ad)/generic/generic.h
charesc.$(OBJ):	charesc.cc $D/charesc.h
fansu.$(OBJ):	fansu.cc $D/fansu.h $(ad)/generic/generic.h
kmp.$(OBJ):		kmp.cc $D/kmp.h $D/strmatch.h $(ad)/generic/generic.h
kr.$(OBJ):		kr.cc $D/kr.h $D/strmatch.h $(ad)/generic/generic.h
quark.$(OBJ):	quark.cc $D/quark.h $(ad)/hash/dchash.h \
		$(ad)/memory/strpool.h $(ad)/memory/mem.h $(ad)/generic/generic.h 
regexp.$(OBJ):	regexp.cc $D/regexp.h $(ad)/contain/charset.h \
		$(ad)/generic/generic.h
shiftadd.$(OBJ):	shiftadd.cc $D/shiftadd.h $(ad)/generic/generic.h
string.$(OBJ):	string.cc $D/string.h $(ad)/generic/generic.h
strmatch.$(OBJ):	strmatch.cc $D/strmatch.h $(ad)/generic/generic.h
twoway.$(OBJ):	twoway.cc $D/twoway.h $(ad)/generic/generic.h

%.$(OBJ):	%.cc
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cc)

%.$(OBJ):	%.C
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.C)

%.$(OBJ):	%.cpp
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cpp)

%.$(OBJ):	%.cxx
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cxx)
