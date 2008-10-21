D := $(ad)/visualize
S := visualize

SRC += $S/vcg.cc

$S/vcg.$(OBJ):		$S/vcg.cc $(D)/vcg.h $(ad)/generic/generic.h \
		$(ad)/hash/lhash.h \
		$(ad)/visualize/vcg.h \
		$(ad)/hash/lhash.h \
		$(ad)/memory/strpool.h \
		$(ad)/contain/varstack.h \
		$(ad)/strings/charesc.h \
		$(ad)/pretty/postream.h
