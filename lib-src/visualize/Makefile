#############################################################################
#  The following parameters must be altered for each platform and compiler.
#  The default is for g++ on Unix and MSDOG.
#############################################################################
ADLIB_PATH	=	../../include
CC		=	gcc
COPTS		=	-O6 -fexternal-templates -g
CINCLUDE	=	-I$(ADLIB_PATH)

ad		=	$(ADLIB_PATH)/AD
D		=	$(ADLIB_PATH)/AD/visualize

OBJS	 = vcg.$(OBJ)

all:	$(OBJS) 

qa:	qa.cc $(OBJS)
	$(CC) $(COPTS) $(CINCLUDE) -o qa qa.cc *.$(OBJ) -liostream

vcg.$(OBJ):		vcg.cc $(D)/vcg.h $(ad)/generic/generic.h \
		$(ad)/hash/lhash.h \
		$(ad)/visualize/vcg.h \
		$(ad)/hash/lhash.h \
		$(ad)/memory/strpool.h \
		$(ad)/contain/varstack.h \
		$(ad)/strings/charesc.h \
		$(ad)/pretty/postream.h 


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
