#
#  A sample Makefile
#

ADLIB_PATH	= ../../include
CC		= g++
CINCLUDE	= -I$(ADLIB_PATH)
COPTS		= -O6
PROP		= prop
PROP_OPTS	= -s -v

D		= $(ADLIB_PATH)/AD/symbolic
ad		= $(ADLIB_PATH)/AD

OBJS		= bdd.$(OBJ) expr.$(OBJ) string.$(OBJ) atom.$(OBJ) term.$(OBJ) fouriermotzkin.$(OBJ)

all:	$(OBJS)

src:	$(SRC)

bdd.$(OBJ):		bdd.cc $D/bdd.h $(ad)/generic/generic.h
expr.$(OBJ):		expr.cc $D/expr.h $(ad)/generic/generic.h
string.$(OBJ):	string.cc $D/expr.h $D/string.h $(ad)/generic/generic.h \
		$(ad)/strings/string.h
atom.$(OBJ):		atom.cc $D/atom.h $D/expr.h $D/string.h $(ad)/generic/generic.h \
		$(ad)/strings/string.h
term.$(OBJ):		term.cc $D/term.h $D/expr.h $(ad)/generic/generic.h
fouriermotzkin.$(OBJ): fouriermotzkin.cc $D/fouriermotzkin.h \
		$(ad)/generic/generic.h $(ad)/memory/mem.h

%.$(OBJ):	%.cc
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cc)

%.$(OBJ):	%.cpp
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cpp)

%.$(OBJ):	%.c++
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.c++)

%.$(OBJ):	%.c
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.c)

%.cc:	%.pcc
	$(PROP) $(PROP_OPTS) $(CINCLUDE) $(@:.cc=.pcc)

%.h:	%.ph
	$(PROP) $(PROP_OPTS) $(CINCLUDE) $(@:.h=.ph)
