#!/bin/sh

# in Makefile, CWD is replaced by `pwd`
# it is intended to be the root directory
# of the developers installation
#
# BINDIR is replaced by location where executables end up

export PB_EXECUTABLE_PATH=BINDIR/pb
exec python CWD/pydada/dada.py $@
