#############################################################################
#
#  This Makefile is used to compile the library source code.
#
#############################################################################

include ../Makefile.config

ADLIB_PATH	:=	../include
ad := $(ADLIB_PATH)/AD

CINCLUDE := -I$(ADLIB_PATH)
CFLAGS := $(CPP_OPTS) $(CINCLUDE)
LIBRARY := libprop.$(LIB)

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

#PROP		=	../../bin/prop
#PROP_OPTS	=	-strict -report -I../../include

lib: $(LIBRARY)

#each module will add to this
SRC :=
GEN_SRC :=

# include all modules
include $(patsubst %, %/Makefile.mk,$(AREAS))

# deduce object files
OBJS := $(patsubst %.cc,%.$(OBJ),$(filter %.cc,$(SRC)))

%.$(OBJ):	%.cc
	$(call MKOBJ,$@, $(CFLAGS) $<)

%.$(OBJ):	%.cpp
	$(call MKOBJ,$@, $(CFLAGS) $<)

%.$(OBJ):	%.cxx
	$(call MKOBJ,$@, $(CFLAGS) $<)

%.$(OBJ):	%.C
	$(call MKOBJ,$@, $(CFLAGS) $<)

clean:
	$(RM) $(OBJS)

cleanall: clean
	$(RM) $(LIBRARY)

spotless: cleanall
	$(RM) $(GEN_SRC)

vars:
	@echo $(SRC)
	@echo $(GEN_SRC)
	@echo $(OBJS)

$(LIBRARY): $(OBJS)
	$(call MKLIB,$(LIBRARY),$(OBJS))
	@echo Done

#%.cc:	%.pcc
#	$(PROP) $(PROP_OPTS) $(CINCLUDE) $<

#%.h:	%.ph
#	$(PROP) $(PROP_OPTS) $(CINCLUDE) $<
