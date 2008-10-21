D := $(ad)/symbolic
S := symbolic

SRC += $S/bdd.cc $S/expr.cc $S/string.cc $S/atom.cc $S/term.cc $S/fouriermotzkin.$(OBJ)

$S/bdd.$(OBJ):		$S/bdd.cc $D/bdd.h $(ad)/generic/generic.h
$S/expr.$(OBJ):		$S/expr.cc $D/expr.h $(ad)/generic/generic.h
$S/string.$(OBJ):	$S/string.cc $D/expr.h $D/string.h $(ad)/generic/generic.h \
		$(ad)/strings/string.h
$S/atom.$(OBJ):		$S/atom.cc $D/atom.h $D/expr.h $D/string.h $(ad)/generic/generic.h \
		$(ad)/strings/string.h
$S/term.$(OBJ):		$S/term.cc $D/term.h $D/expr.h $(ad)/generic/generic.h
$S/fouriermotzkin.$(OBJ): $S/fouriermotzkin.cc $D/fouriermotzkin.h \
		$(ad)/generic/generic.h $(ad)/memory/mem.h
