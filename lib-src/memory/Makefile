#############################################################################
#  The following parameters must be altered for each platform and compiler.
#  The default is for g++ on Unix and MSDOG.
#############################################################################
ADLIB_PATH	=	../../include
CC		=	g++
COPTS		=	-O6
CINCLUDE	=	-I$(ADLIB_PATH)

ad		=	$(ADLIB_PATH)/AD
D		=	$(ADLIB_PATH)/AD/memory

OBJS1	= arena.$(OBJ) boundtag.$(OBJ) freelist.$(OBJ) mempool.$(OBJ) sysmem.$(OBJ) cleanmem.$(OBJ)
OBJS2	= ptr.$(OBJ) strpool.$(OBJ) ref.$(OBJ) variant.$(OBJ) mem.$(OBJ) variant.$(OBJ) buddysys.$(OBJ)
#blacklistmem.$(OBJ)

all: $(OBJS1) $(OBJS2)

buddysys.$(OBJ):	buddysys.cc $D/buddy.h $(ad)/generic/generic.h $(ad)/generic/tables.h $D/mem.h
sysmem.$(OBJ):	sysmem.cc $D/mem.h $D/sysmem.h
arena.$(OBJ):	arena.cc $D/arena.h $(ad)/generic/generic.h $D/mem.h
mem.$(OBJ):		mem.cc $D/mem.h $D/sysmem.h
cleanmem.$(OBJ):	cleanmem.cc $D/mem.h $D/cleanmem.h
#blacklistmem.$(OBJ):	blacklistmem.cc $D/mem.h $D/blacklistmem.h $(ad)/gc/gcheaps.h
boundtag.$(OBJ):	boundtag.cc $D/boundtag.h $(ad)/generic/generic.h $D/mem.h
freelist.$(OBJ):	freelist.cc $D/freelist.h $(ad)/generic/generic.h
mempool.$(OBJ):	mempool.cc $D/mempool.h $(ad)/generic/generic.h $D/mem.h
ptr.$(OBJ):		ptr.cc $D/ptr.h $D/ref.h $(ad)/generic/generic.h
ref.$(OBJ):		ref.cc $D/ref.h $(ad)/generic/generic.h
strpool.$(OBJ):	strpool.cc $D/strpool.h $(ad)/generic/generic.h $D/mem.h
variant.$(OBJ):	variant.cc $D/variant.h $D/ref.h $(ad)/generic/generic.h

%.$(OBJ):	%.cc
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cc)

%.$(OBJ):	%.C
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.C)

%.$(OBJ):	%.cpp
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cpp)

%.$(OBJ):	%.cxx
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cxx)
