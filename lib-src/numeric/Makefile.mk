D := $(ad)/numeric
S := numeric

SRC += $S/bcd.cc $S/bigint.cc $S/fixpt.cc $S/gauss.cc
SRC += $S/matrix.cc $S/pmatrix.cc $S/polynom.cc $S/rabin.cc $S/ratio.cc $S/simplex.cc $S/solovay.cc
SRC += $S/tensor.cc $S/trapez.cc $S/vector.cc $S/vector3d.cc $S/z.cc

$S/bcd.$(OBJ):		$S/bcd.cc $D/bcd.h $(ad)/generic/generic.h
$S/bigint.$(OBJ):	$S/bigint.cc $D/bigint.h $(ad)/generic/generic.h
$S/complex.$(OBJ):	$S/complex.cc $D/complex.h $(ad)/generic/generic.h
$S/fixpt.$(OBJ):	$S/fixpt.cc $D/fixpt.h $(ad)/generic/generic.h
$S/gauss.$(OBJ):	$S/gauss.cc $D/gauss.h $(ad)/generic/generic.h
$S/gaussint.$(OBJ):	$S/gaussint.cc $D/gaussint.h $(ad)/generic/generic.h
$S/matrix.$(OBJ):	$S/matrix.cc $D/matrix.h $(ad)/generic/generic.h
$S/pmatrix.$(OBJ):	$S/pmatrix.cc $D/pmatrix.h $(ad)/generic/generic.h
$S/polynom.$(OBJ):	$S/polynom.cc $D/polynom.h $(ad)/generic/generic.h
$S/rabin.$(OBJ):	$S/rabin.cc $D/primes.h $D/bigint.h $(ad)/generic/generic.h
$S/ratio.$(OBJ):	$S/ratio.cc $D/ratio.h $D/bigint.h $(ad)/generic/generic.h
$S/simplex.$(OBJ):	$S/simplex.cc $D/simplex.h $(ad)/generic/generic.h
$S/solovay.$(OBJ):	$S/solovay.cc $D/primes.h $D/bigint.h $(ad)/generic/generic.h
$S/tensor.$(OBJ):	$S/tensor.cc $D/tensor.h $(ad)/generic/generic.h
$S/trapez.$(OBJ):	$S/trapez.cc $D/trapez.h
$S/vector.$(OBJ):	$S/vector.cc $D/vector.h $(ad)/generic/generic.h
$S/vector3d.$(OBJ):	$S/vector3d.cc $D/vector3d.h $(ad)/generic/generic.h
$S/z.$(OBJ):		$S/z.cc $D/z.h $(ad)/generic/generic.h
