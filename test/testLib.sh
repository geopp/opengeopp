#!/bin/sh

INSTALL_DIR=`grep "^prefix =" ../Makefile | cut -d"=" -d" " -f3`
TST_PROG=../opengeopp/batches/opengeopp
OPENGEOPP_API_VERSION=`grep "^PACKAGE_VERSION =" ../Makefile | cut -d"=" -d" " -f3`
OPENGEOPP_LIBRARY_NAME=`grep "^PACKAGE =" ../Makefile | cut -d"=" -d" " -f3`
OPENGEOPP_LIB=lib${OPENGEOPP_LIBRARY_NAME}-${OPENGEOPP_API_VERSION}.so

if [ ! -x ${TST_PROG} ];
then
	echo "The sample program does not seem to have been compiled. Try 'make check' first."
	exit -1
fi

if [ "$1" = "-h" -o "$1" = "-H" -o "$1" = "--h" -o "$1" = "--help" ];
then
	echo "Usage: $0 [<Number of random draws> <Cabin capacity> <CSV input filename> <Optimisation method flag: 0=MC, 1=DP, 2=EMSR, 3=EMSR-a, 4=EMSR-b>]"
	echo "By default:"
	echo
	echo "The library (${OPENGEOPP_LIB}) is installed in: ${INSTALL_DIR}/lib"
	exit 0
fi

${TST_PROG} $1
