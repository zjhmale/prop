#############################################################################
#  The following parameters must be altered for each platform and compiler.
#  The default is for g++ on Unix and MSDOG.
#############################################################################
ADLIB_PATH	=	../../include
CC		=	gcc
COPTS		=	-O6
CINCLUDE	=	-I$(ADLIB_PATH)

ad		=	$(ADLIB_PATH)/AD
D		=	$(ADLIB_PATH)/AD/pretty

OBJS	 = pristream.$(OBJ) prostream.$(OBJ) priostream.$(OBJ)

all:	$(OBJS) 

qa:	qa.cc $(OBJS)
	$(CC) $(COPTS) $(CINCLUDE) -o qa qa.cc *.$(OBJ) -liostream

pristream.$(OBJ):	pristream.cc $(D)/pistream.h
prostream.$(OBJ):	prostream.cc $(D)/postream.h
priostream.$(OBJ):	priostream.cc $(D)/piostream.h $(D)/pistream.h $(D)/postream.h

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
