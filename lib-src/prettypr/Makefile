#############################################################################
#  The following parameters must be altered for each platform and compiler.
#  The default is for g++ on Unix and MSDOG.
#############################################################################
ADLIB_PATH	=	../../include
CC		=	gcc
COPTS		=	-g -O6
CINCLUDE	=	-I$(ADLIB_PATH)

ad		=	$(ADLIB_PATH)/AD
D		=	$(ADLIB_PATH)/AD/prettypr

OBJS	 = prettypr.$(OBJ)

all:	$(OBJS) 

qa:	qa.cc $(OBJS)
	$(CC) $(COPTS) $(CINCLUDE) -o qa qa.cc *.$(OBJ) -liostream

prettypr.$(OBJ):	prettypr.cc $(D)/prettypr.h

%.$(OBJ):	%.cc
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cc)

%.$(OBJ):	%.cpp
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cpp)

%.$(OBJ):	%.cxx
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cxx)

%.$(OBJ):	%.C
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.C)

%.$(OBJ):	%.s
	$(AS) $(@:.$(OBJ)=.s) -o $@
