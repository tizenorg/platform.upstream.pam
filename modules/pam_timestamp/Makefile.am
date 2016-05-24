#
# Copyright (c) 2005, 2009 Thorsten Kukuk <kukuk@suse.de>
# Copyright (c) 2005, 2008 Red Hat, Inc.
#

CLEANFILES = *~
MAINTAINERCLEANFILES = $(MANS) README

XMLS = README.xml pam_timestamp.8.xml
man_MANS = pam_timestamp.8
dist_TESTS = tst-pam_timestamp
nodist_TESTS = hmacfile
TESTS = $(dist_TESTS) $(nodist_TESTS)

EXTRA_DIST = $(man_MANS) $(XMLS) $(dist_TESTS)

securelibdir = $(SECUREDIR)
secureconfdir = $(SCONFIGDIR)

noinst_HEADERS = hmacsha1.h sha1.h

AM_CFLAGS = -I$(top_srcdir)/libpam/include -I$(top_srcdir)/libpamc/include

pam_timestamp_la_LDFLAGS = -no-undefined -avoid-version -module $(AM_LDFLAGS)
pam_timestamp_la_LIBADD = $(top_builddir)/libpam/libpam.la
if HAVE_VERSIONING
  pam_timestamp_la_LDFLAGS += -Wl,--version-script=$(srcdir)/../modules.map
endif

securelib_LTLIBRARIES = pam_timestamp.la

pam_timestamp_la_SOURCES = pam_timestamp.c hmacsha1.c sha1.c
pam_timestamp_la_CFLAGS = $(AM_CFLAGS)

hmacfile_SOURCES = hmacfile.c hmacsha1.c sha1.c
hmacfile_LDADD = $(top_builddir)/libpam/libpam.la

if ENABLE_REGENERATE_MAN
noinst_DATA = README
README: pam_timestamp.8.xml
-include $(top_srcdir)/Make.xml.rules
endif

noinst_PROGRAMS = hmacfile
