#############################################################################
#  The following parameters must be altered for each platform and compiler.
#  The default is for g++ on Unix and MSDOG.
#############################################################################
ADLIB_PATH	=	../../include
CC		=	gcc
COPTS		=	-g -O
CINCLUDE	=	-I$(ADLIB_PATH)

ad		=	$(ADLIB_PATH)/AD
D		=	$(ADLIB_PATH)/AD/tries

OBJS	= briandai.$(OBJ) comptrie.$(OBJ) hashtrie.$(OBJ) patricia.$(OBJ) trie.$(OBJ)

all:	$(OBJS)

briandai.$(OBJ):	briandai.cc $D/briandai.h $(ad)/generic/generic.h
comptrie.$(OBJ):	comptrie.cc $D/comptrie.h $(ad)/generic/generic.h
hashtrie.$(OBJ):	hashtrie.cc $D/hashtrie.h $(ad)/generic/generic.h
patricia.$(OBJ):	patricia.cc $D/patricia.h $(ad)/generic/generic.h
trie.$(OBJ):		trie.cc $D/trie.h $(ad)/generic/generic.h

%.$(OBJ):	%.cc
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cc)

%.$(OBJ):	%.cpp
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cpp)

%.$(OBJ):	%.cxx
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cxx)

%.$(OBJ):	%.C
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.C)
