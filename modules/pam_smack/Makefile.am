securelibdir = $(SECUREDIR)
secureconfdir = $(SCONFIGDIR)

AM_CFLAGS = -I$(top_srcdir)/libpam/include -I$(top_srcdir)/libpamc/include @LIBSMACK_CFLAGS@
AM_LDFLAGS = -no-undefined -avoid-version -module
if HAVE_VERSIONING
  AM_LDFLAGS += -Wl,--version-script=$(srcdir)/../modules.map
endif
securelib_LTLIBRARIES = pam_smack.la
pam_smack_la_LIBADD = $(top_builddir)/libpam/libpam.la @LIBSMACK_LIBS@
pam_smack_la_SOURCES = pam_smack.c
