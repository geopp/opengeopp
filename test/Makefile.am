## test sub-directory
include $(top_srcdir)/Makefile.common

MAINTAINERCLEANFILES = Makefile.in

##
SUBDIRS = com

EXTRA_DIST = testLib.sh
##

check_PROGRAMS = OpenGeoTestSuite
TESTS = $(check_PROGRAMS)
XFAIL_TESTS = #IndexBuildingTestSuite

OpenGeoTestSuite_SOURCES = OpenGeoTestSuite.hpp OpenGeoTestSuite.cpp
OpenGeoTestSuite_CXXFLAGS= $(BOOST_CFLAGS) $(CPPUNIT_CFLAGS)
OpenGeoTestSuite_LDADD = 
OpenGeoTestSuite_LDFLAGS = $(BOOST_LIBS) $(CPPUNIT_LIBS) \
	$(top_builddir)/test/com/libcppunitcore.la \
	$(top_builddir)/@PACKAGE@/core/lib@PACKAGE@.la
