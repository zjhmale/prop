D := $(ad)/pretty
S := pretty

SRC += $S/pristream.cc $S/prostream.cc $S/priostream.cc

$S/pristream.$(OBJ):	$S/pristream.cc $(D)/pistream.h
$S/prostream.$(OBJ):	$S/prostream.cc $(D)/postream.h
$S/priostream.$(OBJ):	$S/priostream.cc $(D)/piostream.h $(D)/pistream.h $(D)/postream.h
