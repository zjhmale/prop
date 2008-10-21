D	:= $(ADLIB_PATH)/AD/tries
S := tries

SRC += $S/briandai.cc $S/comptrie.cc $S/hashtrie.cc $S/patricia.cc $S/trie.cc

$S/briandai.$(OBJ):	$S/briandai.cc $D/briandai.h $(ad)/generic/generic.h
$S/comptrie.$(OBJ):	$S/comptrie.cc $D/comptrie.h $(ad)/generic/generic.h
$S/hashtrie.$(OBJ):	$S/hashtrie.cc $D/hashtrie.h $(ad)/generic/generic.h
$S/patricia.$(OBJ):	$S/patricia.cc $D/patricia.h $(ad)/generic/generic.h
$S/trie.$(OBJ):		$S/trie.cc $D/trie.h $(ad)/generic/generic.h
