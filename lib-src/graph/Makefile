#############################################################################
#  The following parameters must be altered for each platform and compiler.
#  The default is for g++ on Unix. 
#############################################################################
ADLIB_PATH	=	../../include
CC		=	gcc
COPTS		=	-O6
CINCLUDE	=	-I$(ADLIB_PATH)

ad		=	$(ADLIB_PATH)/AD
D		=	$(ADLIB_PATH)/AD/graph

OBJS	 = graph.$(OBJ) node.$(OBJ) edge.$(OBJ) \
		graphaux.$(OBJ)

all:	$(OBJS) 

graph.$(OBJ):	$(D)/graph_base.h $(D)/graph.h $(ad)/pretty/postream.h \
		graphinline.h
edge.$(OBJ):		$(D)/graph_base.h $(D)/graph.h $(ad)/pretty/postream.h
node.$(OBJ):		$(D)/graph_base.h $(D)/graph.h $(ad)/pretty/postream.h
graphaux.$(OBJ):	$(D)/graph_base.h $(D)/graph.h $(D)/node.h $(D)/edge.h

qa:	qa.cc $(OBJS)
	$(CC) $(COPTS) $(CINCLUDE) -o qa qa.cc *.$(OBJ) -liostream

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
