#
#  A sample Makefile
#

ADLIB_PATH	= ../../include
CC		= gcc
CINCLUDE	= -I$(ADLIB_PATH)
COPTS		= -O6
#COPTS		= -g -O6 -pg
PROP		= prop
PROP_OPTS	= -s 

D		= $(ADLIB_PATH)/AD/csp
ad		= $(ADLIB_PATH)/AD

OBJS		= trail.$(OBJ) logicalterm.$(OBJ)
SRC		= trail.cc logicalterm.cc

all:	$(SRC) $(OBJS)

src:	$(SRC)

trail.$(OBJ):	trail.cc $D/logicalterm.h $D/trail.h $(ad)/memory/mem.h \
		$(ad)/memory/mempool.h $(ad)/generic/generic.h

logicalterm.$(OBJ):	logicalterm.cc $D/logicalterm.h $D/trail.h $(ad)/memory/mem.h \
		$(ad)/memory/mempool.h $(ad)/generic/generic.h

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
