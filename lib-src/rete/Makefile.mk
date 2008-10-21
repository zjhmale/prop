D := $(ad)/rete
S := rete

SRC += $S/rete.cc $S/fact.cc $S/retenet.cc $S/gen_rete.cc $S/alphamem.cc $S/betamem.cc $S/token.$(OBJ)

$S/rete.$(OBJ):		$S/rete.cc $D/rete.h $D/fact.h $D/retenet.h \
		$(ad)/contain/varqueue.h $(ad)/generic/ordering.h \
		$(ad)/generic/generic.h $(ad)/hash/chash.h \
		$(ad)/memory/mem.h $(ad)/memory/arena.h
$S/fact.$(OBJ):		$S/fact.cc $D/fact.h
$S/retenet.$(OBJ):	$S/retenet.cc $D/fact.h $D/retenet.h \
		$(ad)/memory/mem.h $(ad)/memory/boundtag.h \
		$(ad)/generic/generic.h
$S/gen_rete.$(OBJ):	$S/gen_rete.cc $D/fact.h $D/gen_rete.h $D/token.h \
		$(ad)/memory/mem.h $(ad)/memory/boundtag.h \
		$(ad)/generic/generic.h $D/alphamem.h $D/betamem.h
$S/alphamem.$(OBJ):	$S/alphamem.cc $D/alphamem.h $D/fact.h $D/token.h \
		$(ad)/memory/mem.h $(ad)/memory/boundtag.h \
		$(ad)/memory/arena.h
$S/betamem.$(OBJ):	$S/betamem.cc $D/betamem.h $D/fact.h $D/token.h \
		$(ad)/memory/mem.h $(ad)/memory/boundtag.h \
		$(ad)/memory/arena.h
