include $(top_srcdir)/Makefile.common
include $(srcdir)/sources.mk

## Source directory

MAINTAINERCLEANFILES = Makefile.in


# Binaries (batches)
bin_PROGRAMS = opengeopp

opengeopp_SOURCES = $(batches_h_sources) $(batches_cc_sources)
opengeopp_CXXFLAGS = $(BOOST_CFLAGS)
#opengeopp_LDADD = 
opengeopp_LDFLAGS = $(BOOST_PROGRAM_OPTIONS_LIB) \
	$(top_builddir)/@PACKAGE@/core/lib@PACKAGE@.la
