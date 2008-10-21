D := $(ad)/persist
S := persist

SRC += $S/pstream.cc $S/pfactory.cc $S/pistream.cc $S/postream.cc $S/piostream.cc $S/pobject.cc $S/ptype.cc $S/pmisc.cc

$S/pobject.$(OBJ):	$S/pobject.cc $D/pstream.h $D/pobject.h $D/pconfig.h \
		$D/pconvert.h $D/ptype.h $D/ptypeentry.h
$S/ptype.$(OBJ):	$S/ptype.cc $D/ptype.h $D/pstream.h $D/pobject.h \
		$D/pconfig.h $D/pconvert.h $D/ptypeentry.h \
		$(ad)/contain/vararray.h $D/pi_impl.h $D/po_impl.h \
		$(ad)/contain/variset.h $(ad)/contain/varptrarray.h
$S/pstream.$(OBJ):	$S/pstream.cc $D/pstream.h $D/pobject.h $D/pconfig.h \
		$D/pconvert.h $D/ptype.h $D/ptypeentry.h
$S/pistream.$(OBJ):	$S/pistream.cc $D/pstream.h $D/pobject.h $D/pconfig.h $D/pconvert.h \
		$(ad)/hash/lhash.h $(ad)/memory/mem.h $D/pi_impl.h \
		$D/ptype.h $D/ptypeentry.h  $(ad)/contain/vararray.h  \
		$(ad)/contain/varptrarray.h
$S/postream.$(OBJ):	$S/postream.cc $D/pstream.h $D/pobject.h $D/pconfig.h $D/pconvert.h \
		$(ad)/hash/lhash2.h \
		$D/ptype.h $D/ptypeentry.h $(ad)/contain/variset.h \
		$D/po_impl.h
$S/piostream.$(OBJ):	$S/piostream.cc $D/pstream.h $D/pobject.h $D/pconfig.h $D/pconvert.h \
		$(ad)/memory/mem.h \
		$D/ptype.h $D/ptypeentry.h
$S/pfactory.$(OBJ):	$S/pfactory.cc $D/pfactory.h $D/pobject.h $D/pconfig.h $D/pconvert.h \
		$(ad)/hash/lhash.h \
		$D/ptype.h $D/ptypeentry.h
$S/pmisc.$(OBJ):	$S/pmisc.cc $D/pobject.h $D/pconfig.h $D/pstream.h
