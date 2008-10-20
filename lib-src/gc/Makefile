#############################################################################
#  The following parameters must be altered for each platform and compiler.
#  The default is for g++ on Unix and MSDOG.
#############################################################################
ADLIB_PATH	=	../../include
CC		=	gcc
#COPTS		=	-O6 
COPTS		=	-g -O6
#COPTS		=	-g 
CINCLUDE	=	-I$(ADLIB_PATH)

ad		=	$(ADLIB_PATH)/AD
D		=	$(ADLIB_PATH)/AD/gc

OBJS	 = cgc.$(OBJ) bgc.$(OBJ) markswp.$(OBJ) gc.$(OBJ) gcobject.$(OBJ) gcintern.$(OBJ) \
	   rootset.$(OBJ) gcheaps.$(OBJ) gcbitmap.$(OBJ) gcverify.$(OBJ) gctimer.$(OBJ) weakptr.$(OBJ) \
	   userheap.$(OBJ)

all:	$(OBJS) 

qa:	qa.cc $(OBJS)
	$(CC) $(COPTS) $(CINCLUDE) -o qa qa.cc *.$(OBJ) -liostream

cgc.$(OBJ):		cgc.cc $(D)/cgc.h $(D)/gc.h $(D)/gcobject.h $(D)/gcintern.h \
		$(D)/rootset.h $(D)/gcconfig.h $(D)/gcheaps.h $(D)/gcbitmap.h \
		$(D)/gcmacros.h $(ad)/memory/mem.h \
		$(ad)/generic/generic.h $(ad)/memory/sysmem.h
bgc.$(OBJ):		bgc.cc $(D)/bgc.h $(D)/gc.h $(D)/gcobject.h $(D)/gcintern.h \
		$(D)/rootset.h $(D)/gcconfig.h $(D)/gcheaps.h $(D)/gcbitmap.h \
		$(D)/gcmacros.h $(ad)/memory/mem.h $(D)/cgc.h \
		$(ad)/generic/generic.h $(ad)/memory/sysmem.h
markswp.$(OBJ):	markswp.cc $(D)/markswp.h $(D)/gc.h $(D)/gcobject.h \
		$(D)/gcintern.h $(D)/rootset.h $(D)/gcconfig.h \
		$(D)/gcheaps.h $(D)/gcbitmap.h \
		$(D)/gcmacros.h $(ad)/memory/mem.h $(D)/cgc.h \
		$(ad)/generic/generic.h $(ad)/memory/sysmem.h
gc.$(OBJ):		gc.cc $(D)/gc.h $(D)/gcintern.h \
		$(D)/rootset.h $(D)/gcconfig.h \
		$(D)/gcmacros.h $(ad)/memory/mem.h \
		$(ad)/generic/generic.h
gcobject.$(OBJ):	gcobject.cc $(D)/gcobject.h $(D)/gc.h $(D)/gcintern.h \
		$(D)/gcheaps.h $(D)/rootset.h $(D)/gcconfig.h \
		$(D)/gcmacros.h $(ad)/memory/mem.h \
		$(ad)/generic/generic.h
userheap.$(OBJ):	userheap.cc $D/userheap.h $(D)/gcobject.h $(D)/gc.h \
		$(D)/gcintern.h $(D)/gcheaps.h $(D)/rootset.h $(D)/gcconfig.h \
		$(D)/gcmacros.h $(ad)/memory/mem.h \
		$(ad)/generic/generic.h
gcintern.$(OBJ):	gcintern.cc $(D)/gcintern.h  $(D)/gcconfig.h \
		$(ad)/generic/generic.h $(ad)/memory/mem.h
rootset.$(OBJ):	rootset.cc $(D)/rootset.h $(D)/gcintern.h $(D)/gcconfig.h \
		$(ad)/generic/generic.h $(ad)/memory/mem.h
gcheaps.$(OBJ):	gcheaps.cc $(D)/gcheaps.h $(D)/gc.h $(D)/gcobject.h \
		$(D)/gcintern.h $(D)/bgc.h \
		$(D)/gcmacros.h $(ad)/memory/mem.h \
		$(D)/rootset.h $(D)/gcconfig.h $(D)/gcbitmap.h \
		$(ad)/generic/generic.h $(ad)/memory/sysmem.h \
		$(ad)/sort/insort.h $(ad)/memory/mem.h
gcbitmap.$(OBJ):	gcbitmap.cc $(D)/gcbitmap.h  $(D)/gcheaps.h \
		$(D)/gcintern.h $(D)/gcconfig.h $(ad)/generic/generic.h \
		$(D)/gcmacros.h $(ad)/memory/mem.h
gcverify.$(OBJ):	gcverify.cc $(D)/gcverify.h $(D)/gc.h $(D)/gcobject.h \
		$(D)/gcintern.h $(D)/rootset.h $(D)/gcconfig.h \
		$(D)/gcheaps.h $(D)/gcbitmap.h \
		$(D)/gcmacros.h $(ad)/memory/mem.h \
		$(ad)/generic/generic.h $(ad)/memory/sysmem.h
gctimer.$(OBJ):	gctimer.cc $(D)/gctimer.h $(D)/gcconfig.h \
		$(ad)/generic/generic.h $(ad)/memory/mem.h
weakptr.$(OBJ):	weakptr.cc $(D)/weakptr.h $(D)/gc.h $(D)/gcintern.h \
		$(D)/rootset.h $(D)/gcconfig.h $(ad)/memory/mem.h \
		$(D)/gcmacros.h $(ad)/generic/generic.h

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
