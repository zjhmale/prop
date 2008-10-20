#############################################################################
#  The following parameters must be altered for each platform and compiler.
#  The default is for g++ on Unix and MSDOG.
#############################################################################
ADLIB_PATH	=	../../include
CC		=	gcc
COPTS		=	-g -O
CINCLUDE	=	-I$(ADLIB_PATH)

ad		=	$(ADLIB_PATH)/AD
D		=	$(ADLIB_PATH)/AD/hash

OBJS	= bhash.$(OBJ) chash.$(OBJ) dchash.$(OBJ) dhash.$(OBJ) hashfn.$(OBJ) lhash.$(OBJ) ohash.$(OBJ)

all:	$(OBJS)

hashfn.$(OBJ):	hashfn.cc $(D)/hashfn.h
bhash.$(OBJ):	bhash.cc  $(D)/bhash.h  $(ad)/generic/ordering.h
chash.$(OBJ):	chash.cc  $(D)/chash.h  $(ad)/generic/ordering.h
dchash.$(OBJ):	dchash.cc $(D)/dchash.h $(ad)/generic/ordering.h
dhash.$(OBJ):	dhash.cc  $(D)/dhash.h  $(ad)/generic/ordering.h
lhash.$(OBJ):	lhash.cc  $(D)/lhash.h  $(ad)/generic/ordering.h
ohash.$(OBJ):	ohash.cc  $(D)/ohash.h  $(ad)/generic/ordering.h

%.$(OBJ):	%.cc
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cc)

%.$(OBJ):	%.cpp
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cpp)

%.$(OBJ):	%.cxx
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cxx)

%.$(OBJ):	%.C
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.C)
