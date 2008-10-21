D := $(ad)/prop
S := prop

SRC += $S/trace.cc

$S/trace.$(OBJ):	$S/trace.cc $(ad)/generic/generic.h
