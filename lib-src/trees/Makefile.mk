D := $(ad)/trees
S := trees

SRC += $S/avl.cc $S/fibheap.cc $S/leftist.cc $S/pagoda.cc $S/rlxheap.cc $S/splay.cc $S/trees.cc $S/vbpq.$(OBJ)

$S/avl.$(OBJ):		$S/avl.cc  $D/avl.h $D/trees.h \
		$(ad)/generic/ordering.h $(ad)/generic/generic.h
$S/fibheap.$(OBJ):	$S/fibheap.cc $D/fibheap.h $D/trees.h \
		$(ad)/generic/ordering.h $(ad)/generic/generic.h
$S/leftist.$(OBJ):	$S/leftist.cc $D/leftist.h $D/trees.h \
		$(ad)/generic/ordering.h $(ad)/generic/generic.h
$S/pagoda.$(OBJ):	$S/pagoda.cc $D/pagoda.h $D/trees.h \
		$(ad)/generic/ordering.h $(ad)/generic/generic.h
$S/rlxheap.$(OBJ):	$S/rlxheap.cc $D/rlxheap.h $D/trees.h \
		$(ad)/generic/ordering.h $(ad)/generic/generic.h
$S/splay.$(OBJ):	$S/splay.cc $D/splay.h $D/trees.h \
		$(ad)/generic/ordering.h $(ad)/generic/generic.h
$S/trees.$(OBJ):	$S/trees.cc $D/trees.h $(ad)/generic/ordering.h $(ad)/generic/generic.h
$S/vbpq.$(OBJ):		$S/vbpq.cc $D/vbpq.h $(ad)/generic/ordering.h $(ad)/generic/generic.h
