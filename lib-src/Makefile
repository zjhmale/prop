#############################################################################
#
#  This Makefile is used to compile the library source code.
#
#############################################################################

#############################################################################
#  The following parameters must be altered for each platform and compiler.
#  The default is for g++ on Unix and MSDOG.
#############################################################################
ADLIB_PATH	:=	../include
ad := $(ADLIB_PATH)/ad
CC :=	cl
#COPTS		=	-O2
#  g++ 2.6.x
#COPTS		=	-O6 -fexternal-templates
COPTS   = /EHsc /nologo
#COPTS		=	-g -fexternal-templates
CINCLUDE	=	-I$(ADLIB_PATH)
#AR		= 	ar rv
#RANLIB		= 	ranlib
LIBRARY		= 	libprop.lib
#MFILE		=	Makefile
RM		= 	rm
PROP		=	../../bin/prop
PROP_OPTS	=	-strict -report -I../../include

OBJ := obj

#############################################################################
#  A list of all ADLib areas
#############################################################################
AREAS	:= automata contain \
		  csp \
		  generic \
		  graph graphtype hash memory \
		  numeric \
		  persist pretty prettypr \
		  prop rete \
		  rewrite strings symbolic \
		  trees tries backend-tools visualize

AREAS := automata contain memory

lib: $(LIBRARY)

#look for include files in
#each of the modules
# CFLAGS += $(patsubst %,-I%,$(MODULES))
#extra libraries if required
LIBS :=
#each module will add to this
SRC :=
#include the description for
#each module
include $(patsubst %, %/Makefile.mk,$(AREAS))
#determine the object files
OBJS := $(patsubst %.cc,%.$(OBJ),$(filter %.cc,$(SRC)))
#link the program
#prog: $(OBJ)
#$(CC) -o $@ $(OBJ) $(LIBS)
#include the C include
#dependencies
#include $(OBJ:.o=.d)
#calculate C include

%.$(OBJ):	%.cc
	$(CC) /Fo$@ -c $(COPTS) $(CINCLUDE) $<

%.$(OBJ):	%.cpp
	$(CC) -c $(COPTS) $(CINCLUDE) $<

%.$(OBJ):	%.cxx
	$(CC) -c $(COPTS) $(CINCLUDE) $<

%.$(OBJ):	%.C
	$(CC) -c $(COPTS) $(CINCLUDE) $<

clean:
	$(RM) $(OBJS)

d:
	@echo $(SRC)
	@echo $(OBJS)

$(LIBRARY): $(OBJS)
	$(RM) -f $(LIBRARY)
	link /OUT:$(LIBRARY) $(OBJS)
	@echo "Done"

#%.cc:	%.pcc
#	$(PROP) $(PROP_OPTS) $(CINCLUDE) $<

#%.h:	%.ph
#	$(PROP) $(PROP_OPTS) $(CINCLUDE) $<


#spotless:
#	for dir in $(AREAS); do \
#	   if [ -d $$dir ]; then $(RM) -f $$dir/*.o; fi; \
#	done
