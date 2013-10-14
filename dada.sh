#!/bin/sh

# in Makefile, CWD is replaced by `pwd`
# it is intended to be the root directory
# of the developers installation

export PB_EXECUTABLE_PATH=CWD/bin/pb
exec python CWD/pydada/dada.py $@
