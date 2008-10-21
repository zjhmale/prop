D := $(ad)/memory
S := memory

SRC += $S/arena.cc $S/boundtag.cc $S/freelist.cc $S/mempool.cc $S/sysmem.cc $S/cleanmem.cc
SRC += $S/ptr.cc $S/strpool.cc $S/ref.cc $S/variant.cc $S/mem.cc $S/buddysys.cc
#blacklistmem.$(OBJ)

$S/buddysys.$(OBJ):	$S/buddysys.cc $D/buddy.h $(ad)/generic/generic.h $(ad)/generic/tables.h $D/mem.h
$S/sysmem.$(OBJ):	$S/sysmem.cc $D/mem.h $D/sysmem.h
$S/arena.$(OBJ):	$S/arena.cc $D/arena.h $(ad)/generic/generic.h $D/mem.h
$S/mem.$(OBJ):		$S/mem.cc $D/mem.h $D/sysmem.h
$S/cleanmem.$(OBJ):	$S/cleanmem.cc $D/mem.h $D/cleanmem.h
#blacklistmem.$(OBJ):	blacklistmem.cc $D/mem.h $D/blacklistmem.h $(ad)/gc/gcheaps.h
$S/boundtag.$(OBJ):	$S/boundtag.cc $D/boundtag.h $(ad)/generic/generic.h $D/mem.h
$S/freelist.$(OBJ):	$S/freelist.cc $D/freelist.h $(ad)/generic/generic.h
$S/mempool.$(OBJ):	$S/mempool.cc $D/mempool.h $(ad)/generic/generic.h $D/mem.h
$S/ptr.$(OBJ):		$S/ptr.cc $D/ptr.h $D/ref.h $(ad)/generic/generic.h
$S/ref.$(OBJ):		$S/ref.cc $D/ref.h $(ad)/generic/generic.h
$S/strpool.$(OBJ):	$S/strpool.cc $D/strpool.h $(ad)/generic/generic.h $D/mem.h
$S/variant.$(OBJ):	$S/variant.cc $D/variant.h $D/ref.h $(ad)/generic/generic.h
