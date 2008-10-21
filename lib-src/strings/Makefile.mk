D := $(ad)/strings
S := strings

SRC += $S/atom.cc $S/bm.cc $S/charesc.cc $S/fansu.cc $S/kmp.cc $S/kr.cc
SRC	+= $S/quark.cc $S/regexp.cc $S/shiftadd.cc $S/string.cc $S/strmatch.cc $S/twoway.cc

$S/approx.$(OBJ):	$S/approx.cc $D/approx.h $D/shiftadd.h $(ad)/generic/generic.h
$S/atom.$(OBJ):		$S/atom.cc $D/atom.h $(ad)/generic/generic.h $(ad)/hash/dchash.h
$S/bm.$(OBJ):		$S/bm.cc $D/bm.h $D/strmatch.h $(ad)/generic/generic.h
$S/charesc.$(OBJ):	$S/charesc.cc $D/charesc.h
$S/fansu.$(OBJ):	$S/fansu.cc $D/fansu.h $(ad)/generic/generic.h
$S/kmp.$(OBJ):		$S/kmp.cc $D/kmp.h $D/strmatch.h $(ad)/generic/generic.h
$S/kr.$(OBJ):		$S/kr.cc $D/kr.h $D/strmatch.h $(ad)/generic/generic.h
$S/quark.$(OBJ):	$S/quark.cc $D/quark.h $(ad)/hash/dchash.h \
		$(ad)/memory/strpool.h $(ad)/memory/mem.h $(ad)/generic/generic.h
$S/regexp.$(OBJ):	$S/regexp.cc $D/regexp.h $(ad)/contain/charset.h \
		$(ad)/generic/generic.h
$S/shiftadd.$(OBJ):	$S/shiftadd.cc $D/shiftadd.h $(ad)/generic/generic.h
$S/string.$(OBJ):	$S/string.cc $D/string.h $(ad)/generic/generic.h
$S/strmatch.$(OBJ):	$S/strmatch.cc $D/strmatch.h $(ad)/generic/generic.h
$S/twoway.$(OBJ):	$S/twoway.cc $D/twoway.h $(ad)/generic/generic.h
