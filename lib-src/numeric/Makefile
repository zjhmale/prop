#############################################################################
#  The following parameters must be altered for each platform and compiler.
#  The default is for g++ on Unix and MSDOG.
#############################################################################
ADLIB_PATH	=	../../include
CC		=	gcc
COPTS		=	-g -O6
CINCLUDE	=	-I$(ADLIB_PATH)

ad		=	$(ADLIB_PATH)/AD
D		=	$(ADLIB_PATH)/AD/numeric

#OBJS	= bcd.$(OBJ) bigint.$(OBJ) complex.$(OBJ) fixpt.$(OBJ) gauss.$(OBJ) gaussint.$(OBJ)
OBJS	= bcd.$(OBJ) bigint.$(OBJ) fixpt.$(OBJ) gauss.$(OBJ)
OBJS2	= matrix.$(OBJ) pmatrix.$(OBJ) polynom.$(OBJ) rabin.$(OBJ) ratio.$(OBJ) simplex.$(OBJ) solovay.$(OBJ)
OBJS3	= tensor.$(OBJ) trapez.$(OBJ) vector.$(OBJ) vector3d.$(OBJ) z.$(OBJ)

all:	$(OBJS) $(OBJS2) $(OBJS3)

bcd.$(OBJ):		bcd.cc $D/bcd.h $(ad)/generic/generic.h
bigint.$(OBJ):	bigint.cc $D/bigint.h $(ad)/generic/generic.h
complex.$(OBJ):	complex.cc $D/complex.h $(ad)/generic/generic.h
fixpt.$(OBJ):	fixpt.cc $D/fixpt.h $(ad)/generic/generic.h
gauss.$(OBJ):	gauss.cc $D/gauss.h $(ad)/generic/generic.h
gaussint.$(OBJ):	gaussint.cc $D/gaussint.h $(ad)/generic/generic.h
matrix.$(OBJ):	matrix.cc $D/matrix.h $(ad)/generic/generic.h
pmatrix.$(OBJ):	pmatrix.cc $D/pmatrix.h $(ad)/generic/generic.h
polynom.$(OBJ):	polynom.cc $D/polynom.h $(ad)/generic/generic.h
rabin.$(OBJ):	rabin.cc $D/primes.h $D/bigint.h $(ad)/generic/generic.h
ratio.$(OBJ):	ratio.cc $D/ratio.h $D/bigint.h $(ad)/generic/generic.h
simplex.$(OBJ):	simplex.cc $D/simplex.h $(ad)/generic/generic.h
solovay.$(OBJ):	solovay.cc $D/primes.h $D/bigint.h $(ad)/generic/generic.h
tensor.$(OBJ):	tensor.cc $D/tensor.h $(ad)/generic/generic.h
trapez.$(OBJ):	trapez.cc $D/trapez.h
vector.$(OBJ):	vector.cc $D/vector.h $(ad)/generic/generic.h
vector3d.$(OBJ):	vector3d.cc $D/vector3d.h $(ad)/generic/generic.h
z.$(OBJ):		z.cc $D/z.h $(ad)/generic/generic.h

%.$(OBJ):	%.cc
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.cc)

%.$(OBJ):	%.C
	$(CC) -c $(COPTS) $(CINCLUDE) $(@:.$(OBJ)=.C)
