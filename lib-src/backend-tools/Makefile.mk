D := $(ad)/backend-tools
S := backend-tools

SRC += $S/codeemit.$(OBJ)

$S/codeemit.$(OBJ):	$S/codeemit.cc $D/codeemit.h ${ad}/hash/lhash.h
