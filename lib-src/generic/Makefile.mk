D := $(ad)/generic
S := generic

SRC += $S/except.$(OBJ) $S/generic.$(OBJ) $S/tables.$(OBJ)

$S/except.$(OBJ):	$S/except.cc $(D)/except.h
$S/generic.$(OBJ):	$S/generic.cc $(D)/generic.h
$S/tables.$(OBJ):	$S/tables.cc $(D)/tables.h $(D)/generic.h
