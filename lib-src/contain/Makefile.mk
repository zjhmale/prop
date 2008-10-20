
D := $(ad)/contain
S := contain

SRC += $(patsubst %.cc,$S/%.cc,basiccol.cc bytearry.cc charset.cc dlist.cc intset.cc intsets.cc \
	  slist.cc unionfnd.cc variset.cc bitset.cc fbitset.cc n_array.cc)

$S/basiccol.$(OBJ):	$S/basiccol.cc $(D)/basiccol.h $(ad)/generic/generic.h
$S/bytearry.$(OBJ):	$S/bytearry.cc $(D)/bytearry.h $(ad)/generic/generic.h
$S/charset.$(OBJ):	$S/charset.cc  $(D)/charset.h $(ad)/generic/generic.h
$S/dlist.$(OBJ):	$S/dlist.cc    $(D)/dlist.h  $(D)/dlink.h $(ad)/generic/generic.h
$S/intset.$(OBJ):	$S/intset.cc   $(D)/intset.h $(ad)/generic/generic.h
$S/intsets.$(OBJ):	$S/intsets.cc  $(D)/intsets.h $(ad)/generic/generic.h
$S/slist.$(OBJ):	$S/slist.cc    $(D)/slist.h  $(D)/slink.h $(ad)/generic/generic.h
$S/unionfnd.$(OBJ):	$S/unionfnd.cc $(D)/unionfnd.h $(ad)/generic/generic.h
$S/variset.$(OBJ):	$S/variset.cc $(D)/variset.h $(ad)/generic/generic.h
$S/bitset.$(OBJ):	$S/bitset.cc $(D)/bitset.h $(ad)/memory/mem.h $(ad)/generic/generic.h
$S/fbitset.$(OBJ):	$S/fbitset.cc $(D)/fbitset.h \
		$(D)/bitset.h $(ad)/memory/mem.h $(ad)/generic/generic.h
$S/n_array.$(OBJ):	$S/n_array.cc $(D)/n_array.h $(ad)/generic/generic.h
