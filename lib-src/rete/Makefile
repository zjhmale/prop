#############################################################################
#  The following parameters must be altered for each platform and compiler.
#  The default is for g++ on Unix and MSDOG.
#############################################################################
ADLIB_PATH	=	../../include
CC		=	gcc
COPTS		=	-g -O6
CINCLUDE	=	-I$(ADLIB_PATH)

ad		=	$(ADLIB_PATH)/AD
D		=	$(ADLIB_PATH)/AD/rete

OBJS	= rete.$(OBJ) fact.$(OBJ) retenet.$(OBJ) gen_rete.$(OBJ) alphamem.$(OBJ) betamem.$(OBJ) token.$(OBJ)

all:	$(OBJS)

rete.$(OBJ):		rete.cc $D/rete.h $D/fact.h $D/retenet.h \
		$(ad)/contain/varqueue.h $(ad)/generic/ordering.h \
		$(ad)/generic/generic.h $(ad)/hash/chash.h \
		$(ad)/memory/mem.h $(ad)/memory/arena.h
fact.$(OBJ):		fact.cc $D/fact.h
retenet.$(OBJ):	retenet.cc $D/fact.h $D/retenet.h \
		$(ad)/memory/mem.h $(ad)/memory/boundtag.h \
		$(ad)/generic/generic.h
gen_rete.$(OBJ):	gen_rete.cc $D/fact.h $D/gen_rete.h $D/token.h \
		$(ad)/memory/mem.h $(ad)/memory/boundtag.h \
		$(ad)/generic/generic.h $D/alphamem.h $D/betamem.h
alphamem.$(OBJ):	alphamem.cc $D/alphamem.h $D/fact.h $D/token.h \
		$(ad)/memory/mem.h $(ad)/memory/boundtag.h \
		$(ad)/memory/arena.h
betamem.$(OBJ):	betamem.cc $D/betamem.h $D/fact.h $D/token.h \
		$(ad)/memory/mem.h $(ad)/memory/boundtag.h \
		$(ad)/memory/arena.h

%.$(OBJ):	%.cc
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cc)

%.$(OBJ):	%.cpp
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cpp)

%.$(OBJ):	%.cxx
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cxx)

%.$(OBJ):	%.C
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.C)
