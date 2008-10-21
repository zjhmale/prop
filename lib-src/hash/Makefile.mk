D := $(ad)/hash
S := hash

SRC += $S/bhash.cc $S/chash.cc $S/dchash.cc $S/dhash.cc $S/hashfn.cc $S/lhash.cc $S/ohash.cc

$S/hashfn.$(OBJ):	$S/hashfn.cc $(D)/hashfn.h
$S/bhash.$(OBJ):	$S/bhash.cc  $(D)/bhash.h  $(ad)/generic/ordering.h
$S/chash.$(OBJ):	$S/chash.cc  $(D)/chash.h  $(ad)/generic/ordering.h
$S/dchash.$(OBJ):	$S/dchash.cc $(D)/dchash.h $(ad)/generic/ordering.h
$S/dhash.$(OBJ):	$S/dhash.cc  $(D)/dhash.h  $(ad)/generic/ordering.h
$S/lhash.$(OBJ):	$S/lhash.cc  $(D)/lhash.h  $(ad)/generic/ordering.h
$S/ohash.$(OBJ):	$S/ohash.cc  $(D)/ohash.h  $(ad)/generic/ordering.h
