#############################################################################
#  The following parameters must be altered for each platform and compiler.
#  The default is for g++ on Unix and MSDOG.
#############################################################################
ADLIB_PATH	=	../../include
CC		=	gcc
COPTS		=	-g -O
CINCLUDE	=	-I$(ADLIB_PATH)

ad		=	$(ADLIB_PATH)/AD
D		=	$(ADLIB_PATH)/AD/trees

OBJS	= avl.$(OBJ) fibheap.$(OBJ) leftist.$(OBJ) pagoda.$(OBJ) rlxheap.$(OBJ) splay.$(OBJ) trees.$(OBJ) vbpq.$(OBJ)

all:	$(OBJS)

avl.$(OBJ):		avl.cc  $D/avl.h $D/trees.h \
		$(ad)/generic/ordering.h $(ad)/generic/generic.h
fibheap.$(OBJ):	fibheap.cc $D/fibheap.h $D/trees.h \
		$(ad)/generic/ordering.h $(ad)/generic/generic.h
leftist.$(OBJ):	leftist.cc $D/leftist.h $D/trees.h \
		$(ad)/generic/ordering.h $(ad)/generic/generic.h
pagoda.$(OBJ):	pagoda.cc $D/pagoda.h $D/trees.h \
		$(ad)/generic/ordering.h $(ad)/generic/generic.h
rlxheap.$(OBJ):	rlxheap.cc $D/rlxheap.h $D/trees.h \
		$(ad)/generic/ordering.h $(ad)/generic/generic.h
splay.$(OBJ):	splay.cc $D/splay.h $D/trees.h \
		$(ad)/generic/ordering.h $(ad)/generic/generic.h
trees.$(OBJ):	trees.cc $D/trees.h $(ad)/generic/ordering.h $(ad)/generic/generic.h
vbpq.$(OBJ):		vbpq.cc $D/vbpq.h $(ad)/generic/ordering.h $(ad)/generic/generic.h

%.$(OBJ):	%.cc
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cc)

%.$(OBJ):	%.cpp
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cpp)

%.$(OBJ):	%.cxx
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cxx)

%.$(OBJ):	%.C
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.C)
