#############################################################################
#  The following parameters must be altered for each platform and compiler.
#  The default is for g++ on Unix and MSDOG.
#############################################################################

D	:= $(ad)/automata
S := automata

SRC += $S/ac.cc $S/acgen.cc $S/bottomup.cc $S/lr0.cc $S/compdfa.cc $S/densedfa.cc
SRC += $S/gentable.cc $S/grammar.cc $S/lr1.cc $S/lalr1gen.cc
SRC += $S/lexer.cc $S/lexergen.cc $S/ll1.cc $S/ll1gen.cc $S/ll1parse.cc $S/lrgen.cc
SRC += $S/llk.cc $S/llkgen.cc $S/lrk.cc $S/lrparser.cc $S/lookahd.cc
SRC += $S/scanner.cc $S/sparsdfa.cc $S/topdown.cc $S/topdowng.cc
SRC += $S/treeauto.cc $S/treegen.cc $S/treegram.cc $S/regexmat.cc
SRC += $S/nullable.cc $S/firstset.cc $S/follow.cc $S/first_k.cc $S/follow_k.cc $S/operprec.cc
SRC += $S/nfa.cc $S/nfa_node.cc $S/nfa32.cc $S/lr1gen.cc $S/lrkgen.cc $S/gla.cc $S/lexerbuf.cc
SRC += $S/iolexerbuf.cc $S/iolexerstack.cc $S/item.cc $S/firstset2.cc $S/fastac.cc

#############################################################################
#  Prop stuff
#############################################################################
#SRC	= treegram.cc topdowng.cc treegen.cc
#src:	$(SRC)

$S/treegram.cc:	$S/treegram.pcc $D/treegram.ph
$S/topdowng.cc:	$S/topdowng.pcc $D/treegram.ph
$S/treegen.cc:	$S/treegen.pcc $D/treegram.ph

$S/ac.$(OBJ):	$S/ac.cc $D/ac.h $D/compdfa.h $(ad)/generic/generic.h \
		$D/sparsdfa.h $D/dfatable.h
$S/acgen.$(OBJ):	$S/acgen.cc $D/acgen.h $D/sparsdfa.h $D/compdfa.h \
		$(ad)/tries/briandai.h $(ad)/contain/varstack.h \
		$(ad)/contain/queue.h $(ad)/generic/generic.h \
		$D/dfatable.h
$S/factac.$(OBJ):	$S/factac.cc $D/acgen.h $D/sparsdfa.h $D/compdfa.h \
		$(ad)/tries/briandai.h $(ad)/contain/varstack.h \
		$(ad)/contain/queue.h $(ad)/generic/generic.h \
		$D/dfatable.h
$S/nullable.$(OBJ):	$S/nullable.cc $D/nullable.h $(ad)/contain/bitset.h \
		$D/grammar.h $(ad)/memory/mempool.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/memory/mem.h
$S/firstset.$(OBJ):	$S/firstset.cc $D/firstset.h $D/nullable.h $(ad)/contain/bitset.h \
		$D/grammar.h $(ad)/memory/mempool.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/memory/mem.h
$S/firstset2.$(OBJ):	$S/firstset2.cc $D/firstset2.h \
		$D/firstset.h $D/nullable.h $(ad)/contain/bitset.h \
		$D/grammar.h $(ad)/memory/mempool.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/memory/mem.h
$S/follow.$(OBJ):	$S/follow.cc $D/follow.h $D/firstset.h $D/nullable.h \
		$(ad)/contain/bitset.h \
		$D/grammar.h $(ad)/memory/mempool.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/memory/mem.h
$S/first_k.$(OBJ):	$S/first_k.cc $D/first_k.h $D/follow.h $D/firstset.h $D/nullable.h \
		$(ad)/contain/bitset.h \
		$D/grammar.h $(ad)/memory/mempool.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/memory/mem.h
$S/follow_k.$(OBJ):	$S/follow_k.cc $D/follow_k.h $D/first_k.h $D/follow.h \
		$D/firstset.h $D/nullable.h $(ad)/contain/bitset.h \
		$D/grammar.h $(ad)/memory/mempool.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/memory/mem.h
$S/bottomup.$(OBJ):	$S/bottomup.cc $D/bottomup.h $D/treeauto.h \
		$D/treepat.h $D/termpat.h $(ad)/generic/generic.h \
		$(ad)/contain/dchmap.h $(ad)/memory/mempool.h \
		$(ad)/contain/vararray.h $(ad)/contain/stack.h \
		$(ad)/contain/varqueue.h $D/treetab.h \
		$D/dfatable.h $(ad)/memory/mem.h \
		$D/compdfa.h $D/sparsdfa.h
$S/item.$(OBJ):		$S/item.cc $D/item.h $D/grammar.h $D/gentable.h \
		$(ad)/generic/generic.h
$S/lr0.$(OBJ):		$S/lr0.cc $D/lr0.h $D/grammar.h $D/gentable.h \
		$(ad)/hash/dchash.h $(ad)/contain/hashmap.h \
		$(ad)/contain/dchmap.h $(ad)/generic/generic.h \
		$(ad)/generic/ordering.h $D/item.h $(ad)/memory/mempool.h \
		$D/dfatable.h $(ad)/contain/bitset.h $(ad)/memory/mem.h
$S/gla.$(OBJ):		$S/gla.cc $D/gla.h $D/grammar.h $D/gentable.h \
		$(ad)/hash/dchash.h $(ad)/contain/hashmap.h \
		$(ad)/contain/dchmap.h $(ad)/generic/generic.h \
		$(ad)/generic/ordering.h $(ad)/memory/mempool.h \
		$D/dfatable.h $(ad)/contain/bitset.h $(ad)/memory/mem.h
$S/compdfa.$(OBJ):	$S/compdfa.cc $D/compdfa.h $(ad)/generic/generic.h \
		$D/dfatable.h
$S/densedfa.$(OBJ):	$S/densedfa.cc $D/densedfa.h $D/sparsdfa.h $D/compdfa.h \
		$(ad)/contain/varstack.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/memory/mem.h
$S/dfa.$(OBJ):		$S/dfa.cc $D/dfa.h $(ad)/contain/map.h $(ad)/memory/mempool.h \
		$(ad)/generic/generic.h $(ad)/memory/mem.h
$S/gentable.$(OBJ):	$S/gentable.cc $D/gentable.h $(ad)/generic/generic.h
$S/graminfo.$(OBJ):	$S/graminfo.cc $D/graminfo.h $D/grammar.h \
		$(ad)/contain/intsets.h $(ad)/generic/generic.h \
		$(ad)/sort/shellsrt.h $(ad)/generic/ordering.h \
		$(ad)/sort/sorting.h $D/dfatable.h
$S/grammar.$(OBJ):	$S/grammar.cc $D/grammar.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/strings/charesc.h
#labtree.$(OBJ):	labtree.cc $D/labtree.h $(ad)/contain/charset.h \
#		$(ad)/generic/generic.h $D/dfatable.h
$S/lr1.$(OBJ):		$S/lr1.cc $D/lr1.h $D/grammar.h $(ad)/generic/generic.h \
		$D/dfatable.h
$S/lrparser.$(OBJ):	$S/lrparser.cc $D/lrparser.h $D/lr1.h \
		$D/grammar.h $(ad)/generic/generic.h \
		$D/compdfa.h $D/dfatable.h
$S/lalr1gen.$(OBJ):	$S/lalr1gen.cc $D/grammar.h $(ad)/generic/generic.h \
		$(ad)/hash/dchash.h $(ad)/contain/hashmap.h $(ad)/contain/dchmap.h \
		$(ad)/memory/mempool.h $D/gentable.h $D/lrgen.h \
		$D/lr0.h $D/lookahd.h $D/operprec.h \
		$D/dfatable.h $(ad)/contain/bitset.h $D/densedfa.h \
		$D/sparsdfa.h $(ad)/memory/mem.h
$S/lookahd.$(OBJ):	$S/lookahd.cc $D/lookahd.h $D/grammar.h $(ad)/generic/generic.h \
		$(ad)/hash/dchash.h $(ad)/contain/hashmap.h $(ad)/contain/dchmap.h \
		$(ad)/memory/mempool.h $D/gentable.h $D/lrgen.h \
		$D/lr0.h $D/firstset.h $D/nullable.h $D/operprec.h \
		$D/dfatable.h $(ad)/contain/bitset.h $(ad)/memory/mem.h \
		$D/firstset2.h
$S/lrgen.$(OBJ):	$S/lrgen.cc $D/lrgen.h $(ad)/generic/generic.h \
		$D/compdfa.h $D/sparsdfa.h $D/densedfa.h $D/grammar.h  \
		$D/dfatable.h
$S/lexer.$(OBJ):	$S/lexer.cc $D/lexer.h $D/compdfa.h $(ad)/generic/generic.h \
		$D/dfatable.h
$S/lexergen.$(OBJ):	$S/lexergen.cc $D/lexergen.h $D/labtree.h $D/dfa.h \
		$D/densedfa.h $D/sparsdfa.h $D/compdfa.h $D/nfa.h $D/nfa_node.h\
		$(ad)/contain/varstack.h $(ad)/contain/fixqueue.h \
		$(ad)/hash/dchash.h $(ad)/generic/generic.h \
		$(ad)/contain/bitset.h $D/dfatable.h $(ad)/contain/fbitset.h
$S/ll1.$(OBJ):		$S/ll1.cc $D/ll1.h $D/grammar.h $D/compdfa.h \
		$(ad)/generic/generic.h $D/dfatable.h
$S/ll1gen.$(OBJ):	$S/ll1gen.cc $D/ll1gen.h $D/grammar.h $D/sparsdfa.h \
		$D/compdfa.h $(ad)/generic/generic.h $D/dfatable.h \
		$D/nullable.h $D/firstset.h $D/follow.h \
		$(ad)/contain/bitset.h $(ad)/memory/mempool.h $(ad)/memory/mem.h
$S/ll1parse.$(OBJ):	$S/ll1parse.cc $D/ll1.h \
		$D/grammar.h $D/sparsdfa.h $D/compdfa.h \
		$(ad)/generic/generic.h $D/dfatable.h
$S/llk.$(OBJ):		$S/llk.cc $D/llk.h $D/grammar.h $D/compdfa.h \
		$(ad)/generic/generic.h $D/dfatable.h
$S/llkgen.$(OBJ):	$S/llkgen.cc $D/llkgen.h $D/graminfo.h \
		$D/grammar.h $D/densedfa.h $D/sparsdfa.h $D/compdfa.h \
		$(ad)/generic/generic.h $D/dfatable.h \
		$D/follow_k.h $D/first_k.h $D/follow.h $D/firstset.h \
		$D/nullable.h $(ad)/contain/bitset.h $(ad)/memory/mempool.h $(ad)/memory/mem.h
$S/lr1gen.$(OBJ):	$S/lr1gen.cc $D/grammar.h $(ad)/generic/generic.h \
		$(ad)/hash/dchash.h $(ad)/contain/hashmap.h $(ad)/contain/dchmap.h \
		$(ad)/memory/mempool.h $D/gentable.h $D/lr0.h \
		$D/dfatable.h $D/lrgen.h $D/sparsdfa.h $D/compdfa.h
$S/lrk.$(OBJ):		$S/lrk.cc $D/lrk.h $D/grammar.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/memory/mem.h
$S/lrkgen.$(OBJ):	$S/lrkgen.cc $D/lrkgen.h $D/graminfo.h \
		$D/grammar.h $D/densedfa.h $D/sparsdfa.h $D/compdfa.h \
		$(ad)/generic/generic.h $D/dfatable.h
$S/nfa.$(OBJ):		$S/nfa.cc $D/nfa.h $D/nfa_node.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/contain/fbitset.h $(ad)/contain/bitset.h
$S/nfa_node.$(OBJ):	$S/nfa_node.cc $D/nfa_node.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/contain/bitset.h $(ad)/contain/fbitset.h
$S/nfa32.$(OBJ):	$S/nfa32.cc $D/nfa32.h $(ad)/generic/generic.h \
		$D/dfatable.h
$S/scanner.$(OBJ):	$S/scanner.cc $D/scanner.h $D/compdfa.h \
		$(ad)/generic/generic.h $D/sparsdfa.h $D/densedfa.h \
		$D/lexer.h $D/dfatable.h
$S/sparsdfa.$(OBJ):	$S/sparsdfa.cc $D/sparsdfa.h $D/compdfa.h \
		$(ad)/contain/varstack.h $(ad)/generic/generic.h \
		$D/dfatable.h
#termpat.$(OBJ):	termpat.cc $D/termpat.h $(ad)/generic/generic.h \
#		$D/dfatable.h
$S/topdowng.$(OBJ):	$S/topdowng.cc $D/topdowng.h $D/acgen.h $D/treegram.h \
                $D/sparsdfa.h $D/compdfa.h \
		$(ad)/contain/varstack.h \
		$(ad)/tries/briandai.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/contain/bitset.h
$S/topdown.$(OBJ):	$S/topdown.cc $D/topdown.h $D/ac.h $D/sparsdfa.h $D/compdfa.h \
		$(ad)/generic/generic.h $D/dfatable.h
$S/treeauto.$(OBJ):	$S/treeauto.cc $D/treeauto.h $D/gentable.h \
		$(ad)/generic/generic.h $D/dfatable.h $D/treetab.h \
		$(ad)/contain/n_array.h
#
#  Compiler bug in g++ 2.5.8 under Linux makes it impossible to
#  compile this file with symbols.
#
#	$(CC) -c -O6 $(CINCLUDE) $(@:.o=.cc)
$S/treegen.$(OBJ):	$S/treegen.cc $D/treegen.h $D/treegram.h $D/treeauto.h \
		$(ad)/generic/generic.h $(ad)/contain/dchmap.h \
		$(ad)/contain/vararray.h $(ad)/memory/mempool.h \
		$D/dfatable.h $(ad)/memory/mem.h $D/treetab.h \
		$(ad)/contain/bitset.h \
		$D/compdfa.h $D/sparsdfa.h
$S/treegram.$(OBJ):	$S/treegram.cc $D/treegram.h $D/treeauto.h $(ad)/generic/generic.h \
		$(ad)/contain/bitset.h
#treemat.$(OBJ):	treemat.cc $D/treemat.h $D/treeauto.h $(ad)/generic/generic.h
#treepat.$(OBJ):	treepat.cc $D/treepat.h $D/termpat.h $(ad)/generic/generic.h \
#		$(ad)/memory/mempool.h $D/treeauto.h $(ad)/memory/mem.h
$S/regexmat.$(OBJ):	$S/regexmat.cc $D/regexmat.h $D/lexer.h $D/dfatable.h \
		$(ad)/generic/generic.h
$S/lexerbuf.$(OBJ):	$S/lexerbuf.cc $D/lexerbuf.h $D/regexmat.h $D/lexer.h \
		$D/dfatable.h $(ad)/generic/generic.h $(ad)/strings/charesc.h
$S/iolexerbuf.$(OBJ):	$S/iolexerbuf.cc $D/iolexerbuf.h \
		$D/lexerbuf.h $D/regexmat.h $D/lexer.h \
		$D/dfatable.h $(ad)/generic/generic.h $(ad)/strings/charesc.h
$S/iolexerstack.$(OBJ):	$S/iolexerstack.cc $D/iolexerstack.h $D/iolexerbuf.h \
		$D/lexerbuf.h $D/regexmat.h $D/lexer.h \
		$D/dfatable.h $(ad)/generic/generic.h $(ad)/strings/charesc.h
$S/operprec.$(OBJ):	$S/operprec.cc $D/operprec.h $D/grammar.h $D/dfatable.h \
		$(ad)/generic/generic.h
