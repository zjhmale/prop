#
#  A sample Makefile
#

ADLIB_PATH	= ../../include
CC		= g++
CINCLUDE	= -I$(ADLIB_PATH)
COPTS		= -O6
PROP		= prop
PROP_OPTS	= -s -v

D		= $(ADLIB_PATH)/AD/absinterp
ad		= $(ADLIB_PATH)/AD

OBJS		= absdomain.$(OBJ)

all:	$(OBJS)

src:	$(SRC)

absdomain.$(OBJ):	absdomain.cc $D/absdomain.h $(ad)/generic/generic.h

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
