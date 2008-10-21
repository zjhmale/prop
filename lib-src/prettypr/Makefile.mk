D := $(ad)/prettypr
S := prettypr

SRC += $S/prettypr.cc

$S/prettypr.$(OBJ):	$S/prettypr.cc $(D)/prettypr.h
