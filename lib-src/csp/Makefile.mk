D := $(ad)/csp
S := csp

SRC += $S/trail.cc $S/logicalterm.cc

$S/trail.$(OBJ):	$S/trail.cc $D/logicalterm.h $D/trail.h $(ad)/memory/mem.h \
		$(ad)/memory/mempool.h $(ad)/generic/generic.h

$S/logicalterm.$(OBJ):	$S/logicalterm.cc $D/logicalterm.h $D/trail.h $(ad)/memory/mem.h \
		$(ad)/memory/mempool.h $(ad)/generic/generic.h
