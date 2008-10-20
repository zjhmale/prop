#############################################################################
#  The following parameters must be altered for each platform and compiler.
#  The default is for g++ on Unix and MSDOG.
#############################################################################
ADLIB_PATH	=	../../include
CC		=	g++ 
COPTS		=	-O6 
CINCLUDE	=	-I$(ADLIB_PATH)

ad		=	$(ADLIB_PATH)/AD
D		=	$(ADLIB_PATH)/AD/automata

PROP		=	../../bin/prop
PROP_OPTS	=	-s $(CINCLUDE)

OBJS	= ac.$(OBJ) acgen.$(OBJ) bottomup.$(OBJ) lr0.$(OBJ) compdfa.$(OBJ) densedfa.$(OBJ)
OBJS2	= gentable.$(OBJ) grammar.$(OBJ) lr1.$(OBJ) lalr1gen.$(OBJ)
OBJS3	= lexer.$(OBJ) lexergen.$(OBJ) ll1.$(OBJ) ll1gen.$(OBJ) ll1parse.$(OBJ) lrgen.$(OBJ)
OBJS4	= llk.$(OBJ) llkgen.$(OBJ) lrk.$(OBJ) lrparser.$(OBJ) lookahd.$(OBJ)
OBJS5	= scanner.$(OBJ) sparsdfa.$(OBJ) topdown.$(OBJ) topdowng.$(OBJ)
OBJS6	= treeauto.$(OBJ) treegen.$(OBJ) treegram.$(OBJ) regexmat.$(OBJ)
OBJS7	= nullable.$(OBJ) firstset.$(OBJ) follow.$(OBJ) first_k.$(OBJ) follow_k.$(OBJ) operprec.$(OBJ)
OBJS8	= nfa.$(OBJ) nfa_node.$(OBJ) nfa32.$(OBJ) lr1gen.$(OBJ) lrkgen.$(OBJ) gla.$(OBJ) lexerbuf.$(OBJ)
OBJS9	= iolexerbuf.$(OBJ) iolexerstack.$(OBJ) item.$(OBJ) firstset2.$(OBJ) fastac.$(OBJ)

all:	$(OBJS) $(OBJS2) $(OBJS3) $(OBJS4) \
	$(OBJS5) $(OBJS6) $(OBJS7) $(OBJS8) $(OBJS9)

#############################################################################
#  Prop stuff
#############################################################################
SRC	= treegram.cc topdowng.cc treegen.cc 

src:	$(SRC)

treegram.cc:	treegram.pcc $D/treegram.ph
topdowng.cc:	topdowng.pcc $D/treegram.ph
#treegen.cc:	treegen.pcc $D/treegram.ph
 
ac.$(OBJ):		ac.cc $D/ac.h $D/compdfa.h $(ad)/generic/generic.h \
		$D/sparsdfa.h $D/dfatable.h
acgen.$(OBJ):	acgen.cc $D/acgen.h $D/sparsdfa.h $D/compdfa.h \
		$(ad)/tries/briandai.h $(ad)/contain/varstack.h \
		$(ad)/contain/queue.h $(ad)/generic/generic.h \
		$D/dfatable.h
factac.$(OBJ):	factac.cc $D/acgen.h $D/sparsdfa.h $D/compdfa.h \
		$(ad)/tries/briandai.h $(ad)/contain/varstack.h \
		$(ad)/contain/queue.h $(ad)/generic/generic.h \
		$D/dfatable.h
nullable.$(OBJ):	nullable.cc $D/nullable.h $(ad)/contain/bitset.h \
		$D/grammar.h $(ad)/memory/mempool.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/memory/mem.h
firstset.$(OBJ):	firstset.cc $D/firstset.h $D/nullable.h $(ad)/contain/bitset.h \
		$D/grammar.h $(ad)/memory/mempool.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/memory/mem.h
firstset2.$(OBJ):	firstset2.cc $D/firstset2.h \
		$D/firstset.h $D/nullable.h $(ad)/contain/bitset.h \
		$D/grammar.h $(ad)/memory/mempool.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/memory/mem.h
follow.$(OBJ):	follow.cc $D/follow.h $D/firstset.h $D/nullable.h \
		$(ad)/contain/bitset.h \
		$D/grammar.h $(ad)/memory/mempool.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/memory/mem.h
first_k.$(OBJ):	first_k.cc $D/first_k.h $D/follow.h $D/firstset.h $D/nullable.h \
		$(ad)/contain/bitset.h \
		$D/grammar.h $(ad)/memory/mempool.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/memory/mem.h
follow_k.$(OBJ):	follow_k.cc $D/follow_k.h $D/first_k.h $D/follow.h \
		$D/firstset.h $D/nullable.h $(ad)/contain/bitset.h \
		$D/grammar.h $(ad)/memory/mempool.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/memory/mem.h
bottomup.$(OBJ):	bottomup.cc $D/bottomup.h $D/treeauto.h \
		$D/treepat.h $D/termpat.h $(ad)/generic/generic.h \
		$(ad)/contain/dchmap.h $(ad)/memory/mempool.h \
		$(ad)/contain/vararray.h $(ad)/contain/stack.h \
		$(ad)/contain/varqueue.h $D/treetab.h \
		$D/dfatable.h $(ad)/memory/mem.h \
		$D/compdfa.h $D/sparsdfa.h
item.$(OBJ):		item.cc $D/item.h $D/grammar.h $D/gentable.h \
		$(ad)/generic/generic.h 
lr0.$(OBJ):		lr0.cc $D/lr0.h $D/grammar.h $D/gentable.h \
		$(ad)/hash/dchash.h $(ad)/contain/hashmap.h \
		$(ad)/contain/dchmap.h $(ad)/generic/generic.h \
		$(ad)/generic/ordering.h $D/item.h $(ad)/memory/mempool.h \
		$D/dfatable.h $(ad)/contain/bitset.h $(ad)/memory/mem.h
gla.$(OBJ):		gla.cc $D/gla.h $D/grammar.h $D/gentable.h \
		$(ad)/hash/dchash.h $(ad)/contain/hashmap.h \
		$(ad)/contain/dchmap.h $(ad)/generic/generic.h \
		$(ad)/generic/ordering.h $(ad)/memory/mempool.h \
		$D/dfatable.h $(ad)/contain/bitset.h $(ad)/memory/mem.h
compdfa.$(OBJ):	compdfa.cc $D/compdfa.h $(ad)/generic/generic.h \
		$D/dfatable.h
densedfa.$(OBJ):	densedfa.cc $D/densedfa.h $D/sparsdfa.h $D/compdfa.h \
		$(ad)/contain/varstack.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/memory/mem.h
dfa.$(OBJ):		dfa.cc $D/dfa.h $(ad)/contain/map.h $(ad)/memory/mempool.h \
		$(ad)/generic/generic.h $(ad)/memory/mem.h
gentable.$(OBJ):	gentable.cc $D/gentable.h $(ad)/generic/generic.h
graminfo.$(OBJ):	graminfo.cc $D/graminfo.h $D/grammar.h \
		$(ad)/contain/intsets.h $(ad)/generic/generic.h \
		$(ad)/sort/shellsrt.h $(ad)/generic/ordering.h \
		$(ad)/sort/sorting.h $D/dfatable.h
grammar.$(OBJ):	grammar.cc $D/grammar.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/strings/charesc.h
#labtree.$(OBJ):	labtree.cc $D/labtree.h $(ad)/contain/charset.h \
#		$(ad)/generic/generic.h $D/dfatable.h
lr1.$(OBJ):		lr1.cc $D/lr1.h $D/grammar.h $(ad)/generic/generic.h \
		$D/dfatable.h
lrparser.$(OBJ):	lrparser.cc $D/lrparser.h $D/lr1.h \
		$D/grammar.h $(ad)/generic/generic.h \
		$D/compdfa.h $D/dfatable.h
lalr1gen.$(OBJ):	lalr1gen.cc $D/grammar.h $(ad)/generic/generic.h \
		$(ad)/hash/dchash.h $(ad)/contain/hashmap.h $(ad)/contain/dchmap.h \
		$(ad)/memory/mempool.h $D/gentable.h $D/lrgen.h \
		$D/lr0.h $D/lookahd.h $D/operprec.h \
		$D/dfatable.h $(ad)/contain/bitset.h $D/densedfa.h \
		$D/sparsdfa.h $(ad)/memory/mem.h
lookahd.$(OBJ):	lookahd.cc $D/lookahd.h $D/grammar.h $(ad)/generic/generic.h \
		$(ad)/hash/dchash.h $(ad)/contain/hashmap.h $(ad)/contain/dchmap.h \
		$(ad)/memory/mempool.h $D/gentable.h $D/lrgen.h \
		$D/lr0.h $D/firstset.h $D/nullable.h $D/operprec.h \
		$D/dfatable.h $(ad)/contain/bitset.h $(ad)/memory/mem.h \
		$D/firstset2.h
lrgen.$(OBJ):	lrgen.cc $D/lrgen.h $(ad)/generic/generic.h \
		$D/compdfa.h $D/sparsdfa.h $D/densedfa.h $D/grammar.h  \
		$D/dfatable.h 
lexer.$(OBJ):	lexer.cc $D/lexer.h $D/compdfa.h $(ad)/generic/generic.h \
		$D/dfatable.h
lexergen.$(OBJ):	lexergen.cc $D/lexergen.h $D/labtree.h $D/dfa.h \
		$D/densedfa.h $D/sparsdfa.h $D/compdfa.h $D/nfa.h $D/nfa_node.h\
		$(ad)/contain/varstack.h $(ad)/contain/fixqueue.h \
		$(ad)/hash/dchash.h $(ad)/generic/generic.h \
		$(ad)/contain/bitset.h $D/dfatable.h $(ad)/contain/fbitset.h
ll1.$(OBJ):		ll1.cc $D/ll1.h $D/grammar.h $D/compdfa.h \
		$(ad)/generic/generic.h $D/dfatable.h
ll1gen.$(OBJ):	ll1gen.cc $D/ll1gen.h $D/grammar.h $D/sparsdfa.h \
		$D/compdfa.h $(ad)/generic/generic.h $D/dfatable.h \
		$D/nullable.h $D/firstset.h $D/follow.h \
		$(ad)/contain/bitset.h $(ad)/memory/mempool.h $(ad)/memory/mem.h
ll1parse.$(OBJ):	ll1parse.cc $D/ll1.h \
		$D/grammar.h $D/sparsdfa.h $D/compdfa.h \
		$(ad)/generic/generic.h $D/dfatable.h
llk.$(OBJ):		llk.cc $D/llk.h $D/grammar.h $D/compdfa.h \
		$(ad)/generic/generic.h $D/dfatable.h
llkgen.$(OBJ):	llkgen.cc $D/llkgen.h $D/graminfo.h \
		$D/grammar.h $D/densedfa.h $D/sparsdfa.h $D/compdfa.h \
		$(ad)/generic/generic.h $D/dfatable.h \
		$D/follow_k.h $D/first_k.h $D/follow.h $D/firstset.h \
		$D/nullable.h $(ad)/contain/bitset.h $(ad)/memory/mempool.h $(ad)/memory/mem.h
lr1gen.$(OBJ):	lr1gen.cc $D/grammar.h $(ad)/generic/generic.h \
		$(ad)/hash/dchash.h $(ad)/contain/hashmap.h $(ad)/contain/dchmap.h \
		$(ad)/memory/mempool.h $D/gentable.h $D/lr0.h \
		$D/dfatable.h $D/lrgen.h $D/sparsdfa.h $D/compdfa.h
lrk.$(OBJ):		lrk.cc $D/lrk.h $D/grammar.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/memory/mem.h
lrkgen.$(OBJ):	lrkgen.cc $D/lrkgen.h $D/graminfo.h \
		$D/grammar.h $D/densedfa.h $D/sparsdfa.h $D/compdfa.h \
		$(ad)/generic/generic.h $D/dfatable.h
nfa.$(OBJ):		nfa.cc $D/nfa.h $D/nfa_node.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/contain/fbitset.h $(ad)/contain/bitset.h
nfa_node.$(OBJ):	nfa_node.cc $D/nfa_node.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/contain/bitset.h $(ad)/contain/fbitset.h
nfa32.$(OBJ):	nfa32.cc $D/nfa32.h $(ad)/generic/generic.h \
		$D/dfatable.h
scanner.$(OBJ):	scanner.cc $D/scanner.h $D/compdfa.h \
		$(ad)/generic/generic.h $D/sparsdfa.h $D/densedfa.h \
		$D/lexer.h $D/dfatable.h
sparsdfa.$(OBJ):	sparsdfa.cc $D/sparsdfa.h $D/compdfa.h \
		$(ad)/contain/varstack.h $(ad)/generic/generic.h \
		$D/dfatable.h
#termpat.$(OBJ):	termpat.cc $D/termpat.h $(ad)/generic/generic.h \
#		$D/dfatable.h
topdowng.$(OBJ):	topdowng.cc $D/topdowng.h $D/acgen.h $D/treegram.h \
                $D/sparsdfa.h $D/compdfa.h \
		$(ad)/contain/varstack.h \
		$(ad)/tries/briandai.h $(ad)/generic/generic.h \
		$D/dfatable.h $(ad)/contain/bitset.h
topdown.$(OBJ):	topdown.cc $D/topdown.h $D/ac.h $D/sparsdfa.h $D/compdfa.h \
		$(ad)/generic/generic.h $D/dfatable.h
treeauto.$(OBJ):	treeauto.cc $D/treeauto.h $D/gentable.h \
		$(ad)/generic/generic.h $D/dfatable.h $D/treetab.h \
		$(ad)/contain/n_array.h 
#
#  Compiler bug in g++ 2.5.8 under Linux makes it impossible to
#  compile this file with symbols.  
#
#	$(CC) -c -O6 $(CINCLUDE) $(@:.o=.cc)
treegen.$(OBJ):	treegen.cc $D/treegen.h $D/treegram.h $D/treeauto.h \
		$(ad)/generic/generic.h $(ad)/contain/dchmap.h \
		$(ad)/contain/vararray.h $(ad)/memory/mempool.h \
		$D/dfatable.h $(ad)/memory/mem.h $D/treetab.h \
		$(ad)/contain/bitset.h \
		$D/compdfa.h $D/sparsdfa.h
treegram.$(OBJ):	treegram.cc $D/treegram.h $D/treeauto.h $(ad)/generic/generic.h \
		$(ad)/contain/bitset.h
#treemat.$(OBJ):	treemat.cc $D/treemat.h $D/treeauto.h $(ad)/generic/generic.h
#treepat.$(OBJ):	treepat.cc $D/treepat.h $D/termpat.h $(ad)/generic/generic.h \
#		$(ad)/memory/mempool.h $D/treeauto.h $(ad)/memory/mem.h
regexmat.$(OBJ):	regexmat.cc $D/regexmat.h $D/lexer.h $D/dfatable.h \
		$(ad)/generic/generic.h
lexerbuf.$(OBJ):	lexerbuf.cc $D/lexerbuf.h $D/regexmat.h $D/lexer.h \
		$D/dfatable.h $(ad)/generic/generic.h $(ad)/strings/charesc.h
iolexerbuf.$(OBJ):	iolexerbuf.cc $D/iolexerbuf.h \
		$D/lexerbuf.h $D/regexmat.h $D/lexer.h \
		$D/dfatable.h $(ad)/generic/generic.h $(ad)/strings/charesc.h
iolexerstack.$(OBJ):	iolexerstack.cc $D/iolexerstack.h $D/iolexerbuf.h \
		$D/lexerbuf.h $D/regexmat.h $D/lexer.h \
		$D/dfatable.h $(ad)/generic/generic.h $(ad)/strings/charesc.h
operprec.$(OBJ):	operprec.cc $D/operprec.h $D/grammar.h $D/dfatable.h \
		$(ad)/generic/generic.h

%.$(OBJ):	%.cc
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cc)

%.$(OBJ):	%.cpp
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cpp)

%.$(OBJ):	%.cxx
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cxx)

%.$(OBJ):	%.C
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.C)

#%.cc:	%.pcc
#	$(PROP) $(PROP_OPTS) $(@:.cc=.pcc)
