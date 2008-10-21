#############################################################################
#
#  Top level makefile for installing Prop and ADLib
#
#############################################################################

VERSION	= 2.3.0

RM	= rm -f
LIBRARY	= libprop.a
CC	= g++-3.3
COPTS   	= -O6 -pedantic -frepo -g
PROP_COPTS	= $(COPTS)
#LIBRARY_COPTS   = -O6 -pedantic -Wall -fexternal-templates
LIBRARY_COPTS   = -O6 -pedantic -Wall -g
LDOPTS  = #-lg++
OBJ = obj

TARGET_BIN_DIR = /usr/local/bin
TARGET_LIB_DIR = /usr/local/lib
TARGET_INCLUDE_DIR = /usr/local/include

#############################################################################
#
#   Build the ADLib library and the tools
#
#############################################################################
build:
	make -C lib-src
	make -C prop-src
	make -C docs
	@echo Done

config:
	./Configure $(CC)

#############################################################################
#
#   Test prop
#
#############################################################################
test:
	make test -C prop-src
	@echo Testing of the prop translator ran ok.

testall:
	make test -C tests
	@echo All test programs ran ok.

demo:
	make -C demos
	@echo All demo programs have been compiled.

#############################################################################
#
#  Line count
#
#############################################################################
wc:
	wc include/AD/*/*.h lib-src/*/*.cc \
	prop-src/[a-z]*.ph \
	prop-src/[a-z]*.pcc

#############################################################################
#
#  Clean up: remove all *.o files and .cc and .h files generated using
#            Prop.  But don't remove the executable and the library.
#
#############################################################################
spotless:
	make spotless -C lib-src
	make spotless -C prop-src
	cd tools/test; make spotless
	cd tests; make spotless
	cd demos; make spotless
	cd tools/pretty; make spotless
	#cd docs; make spotless

clean:
	make clean -C lib-src
	make clean -C prop-src

cleanall:
	make cleanall -C lib-src
	make cleanall -C prop-src

cleanhouse:
	cd lib-src; make spotless
	cd prop-src; make clean
	cd tools/test; make spotless
	cd tests; make spotless
	cd demos; make spotless
	cd tools/pretty; make spotless
	cd docs; make spotless
	$(RM) lib-src/$(LIBRARY) prop-src/prop

#############################################################################
#  Make tar.gz files for Unix distribution.
#############################################################################
dist:	tar
tar:
	bin/Distribute NO_DISTRIBUTE
full-dist:
	bin/Distribute NO_DISTRIBUTE2

first-install:
	cp prop-src/prop $(TARGET_BIN_DIR)
	chmod 755 $(TARGET_BIN_DIR)/prop
	cp tools/scripts/* $(TARGET_BIN_DIR)
	cp lib-src/$(LIBRARY) $(TARGET_LIB_DIR)
	chmod 644 $(TARGET_LIB_DIR)/$(LIBRARY)
	cp include/propdefs.h $(TARGET_INCLUDE_DIR)

install: first-install
	ln -f -s `pwd`/include/AD $(TARGET_INCLUDE_DIR)/AD

full-install: first-install
	(umask 022; cp -R include $(TARGET_INCLUDE_DIR))
