#############################################################################
#
#  This Makefile is used to compile the library source code.
#
#############################################################################

include ../Makefile.config

ADLIB_PATH	:=	../include
ad := $(ADLIB_PATH)/ad

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

AREAS := contain

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

%.$(OBJ):	%.cc
	$(CC) /Fo$@ -c $(COPTS) $(CINCLUDE) $<

%.$(OBJ):	%.cpp
	$(CC) -c $(COPTS) $(CINCLUDE) $<

%.$(OBJ):	%.cxx
	$(CC) -c $(COPTS) $(CINCLUDE) $<

%.$(OBJ):	%.C
	$(CC) -c $(COPTS) $(CINCLUDE) $<

d:
	@echo $(SRC)
	@echo $(OBJS)

$(LIBRARY): $(OBJS)
	$(RM) $(LIBRARY)
dsds	 $(LIBRARY) $(OBJS)
	@echo "Done"

#%.cc:	%.pcc
#	$(PROP) $(PROP_OPTS) $(CINCLUDE) $<

#%.h:	%.ph
#	$(PROP) $(PROP_OPTS) $(CINCLUDE) $<


#spotless:
#	for dir in $(AREAS); do \
#	   if [ -d $$dir ]; then $(RM) -f $$dir/*.o; fi; \
#	done
