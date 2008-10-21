D := $(ad)/graphtype
S := graphtype

SRC += $S/graphtype.$(OBJ)

$S/graphtype.$(OBJ):	$S/graphtype.cc $(D)/graphtype.h $(ad)/generic/generic.h
