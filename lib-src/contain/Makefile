#############################################################################
#  The following parameters must be altered for each platform and compiler.
#  The default is for g++ on Unix and MSDOG.
#############################################################################
ADLIB_PATH	=	../../include
CC		=	gcc
COPTS		=	-O6
CINCLUDE	=	-I$(ADLIB_PATH)

ad		=	$(ADLIB_PATH)/AD
D		=	$(ADLIB_PATH)/AD/contain

OBJS	= basiccol.$(OBJ) bytearry.$(OBJ) charset.$(OBJ) dlist.$(OBJ) intset.$(OBJ) intsets.$(OBJ) \
	  slist.$(OBJ) unionfnd.$(OBJ) variset.$(OBJ) bitset.$(OBJ) fbitset.$(OBJ) n_array.$(OBJ)

all:	$(OBJS)

basiccol.$(OBJ):	basiccol.cc $(D)/basiccol.h $(ad)/generic/generic.h
bytearry.$(OBJ):	bytearry.cc $(D)/bytearry.h $(ad)/generic/generic.h
charset.$(OBJ):	charset.cc  $(D)/charset.h $(ad)/generic/generic.h
dlist.$(OBJ):	dlist.cc    $(D)/dlist.h  $(D)/dlink.h $(ad)/generic/generic.h
intset.$(OBJ):	intset.cc   $(D)/intset.h $(ad)/generic/generic.h
intsets.$(OBJ):	intsets.cc  $(D)/intsets.h $(ad)/generic/generic.h
slist.$(OBJ):	slist.cc    $(D)/slist.h  $(D)/slink.h $(ad)/generic/generic.h
unionfnd.$(OBJ):	unionfnd.cc $(D)/unionfnd.h $(ad)/generic/generic.h
variset.$(OBJ):	variset.cc $(D)/variset.h $(ad)/generic/generic.h
bitset.$(OBJ):	bitset.cc $(D)/bitset.h $(ad)/memory/mem.h $(ad)/generic/generic.h
fbitset.$(OBJ):	fbitset.cc $(D)/fbitset.h \
		$(D)/bitset.h $(ad)/memory/mem.h $(ad)/generic/generic.h
n_array.$(OBJ):	n_array.cc $(D)/n_array.h $(ad)/generic/generic.h

%.$(OBJ):	%.cc
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cc)

%.$(OBJ):	%.cxx
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cxx)

%.$(OBJ):	%.cpp
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cpp)

%.$(OBJ):	%.C
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.C)
