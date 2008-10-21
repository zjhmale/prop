D := $(ad)/graph
S := graph

SRC += $S/graph.$(OBJ) $S/node.$(OBJ) $S/edge.$(OBJ) $S/graphaux.$(OBJ)

$S/graph.$(OBJ):	$(D)/graph_base.h $(D)/graph.h $(ad)/pretty/postream.h $S/graphinline.h
$S/edge.$(OBJ):		$(D)/graph_base.h $(D)/graph.h $(ad)/pretty/postream.h
$S/node.$(OBJ):		$(D)/graph_base.h $(D)/graph.h $(ad)/pretty/postream.h
$S/graphaux.$(OBJ):	$(D)/graph_base.h $(D)/graph.h $(D)/node.h $(D)/edge.h
