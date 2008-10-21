D := $(ad)/rewrite
S := rewrite

SRC += $S/twig.cc $S/b_item.cc $S/b_items.cc $S/b_rules.cc $S/burs_gen.cc $S/twig_gen.cc $S/burs.cc $S/cache.cc

$S/b_rules.cc:	$S/b_rules.pcc $(ad)/automata/treegram.ph

$S/twig.$(OBJ):		$S/twig.cc $D/twig.h $(ad)/automata/topdown.h \
		$(ad)/automata/ac.h $(ad)/automata/sparsdfa.h \
		$(ad)/automata/compdfa.h $(ad)/automata/dfatable.h \
		$(ad)/memory/mem.h $(ad)/memory/boundtag.h \
		$(ad)/contain/bitset.h $(ad)/generic/generic.h
$S/twig_gen.$(OBJ):	$S/twig_gen.cc $D/twig_gen.h $(ad)/automata/topdown.h \
		$(ad)/automata/ac.h $(ad)/automata/sparsdfa.h \
		$(ad)/automata/compdfa.h $(ad)/automata/dfatable.h \
		$(ad)/memory/mem.h $(ad)/memory/boundtag.h \
		$(ad)/contain/bitset.h $(ad)/generic/generic.h
$S/b_item.$(OBJ):	$S/b_item.cc $D/b_item.h $(ad)/automata/treetab.h \
		$(ad)/automata/treegram.h $(ad)/memory/mem.h \
		$(ad)/generic/generic.h
$S/b_items.$(OBJ):	$S/b_items.cc $D/b_items.h $D/b_item.h $(ad)/automata/treetab.h \
		$(ad)/automata/treegram.h $(ad)/memory/mem.h \
		$(ad)/generic/generic.h
$S/b_rules.$(OBJ):	$S/b_rules.cc $D/b_rules.h $D/b_items.h $D/b_item.h \
		$(ad)/automata/treetab.h \
		$(ad)/automata/treegram.h $(ad)/memory/mem.h \
		$(ad)/generic/generic.h
$S/burs.$(OBJ):		$S/burs.cc $D/burs.h \
		$(ad)/automata/treetab.h $(ad)/automata/treeauto.h \
		$(ad)/automata/treegram.h $(ad)/memory/mem.h
$S/burs_gen.$(OBJ):	$S/burs_gen.cc $D/burs_gen.h \
		$D/b_items.h $D/b_item.h $D/b_rules.h \
		$(ad)/automata/treetab.h $(ad)/automata/treeauto.h \
		$(ad)/automata/treegram.h $(ad)/memory/mem.h \
		$(ad)/generic/generic.h $(ad)/hash/dchash.h \
		$(ad)/automata/dfatable.h $(ad)/automata/compdfa.h \
		$(ad)/automata/sparsdfa.h
$S/burs_gn2.$(OBJ):	$S/burs_gn2.cc $D/burs_gn2.h $D/burs_gen.h \
		$D/b_items.h $D/b_item.h $D/b_rules.h \
		$(ad)/automata/treetab.h $(ad)/automata/treeauto.h \
		$(ad)/automata/treegram.h $(ad)/memory/mem.h \
		$(ad)/generic/generic.h $(ad)/hash/dchash.h \
		$(ad)/automata/dfatable.h $(ad)/automata/compdfa.h \
		$(ad)/automata/sparsdfa.h
