# Makefile.in generated automatically by automake 1.5 from Makefile.am.
# Generated automatically from Makefile.in by config.pl.
# KDE tags expanded automatically by am_edit - $Revision: 1.349.2.2 $ 
# Copyright 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001
# Free Software Foundation, Inc.
# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.



####### kdevelop will overwrite this part!!! (begin)##########

SHELL = /bin/bash

srcdir = .
top_srcdir = .
VPATH = .
prefix = .
exec_prefix = ${prefix}

bindir = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
libexecdir = ${exec_prefix}/libexec
datadir = ${prefix}/share
sysconfdir = ${prefix}/etc
sharedstatedir = ${prefix}/com
localstatedir = ${prefix}/var
libdir = ${exec_prefix}/lib
infodir = ${prefix}/info
mandir = ${prefix}/man
includedir = ${prefix}/include
oldincludedir = /usr/include
pkgdatadir = $(datadir)/yar
pkglibdir = $(libdir)/yar
pkgincludedir = $(includedir)/yar
top_builddir = .

ACLOCAL = ${SHELL} /root/compile/yar/yar-0.99/admin/missing --run aclocal
AUTOCONF = ${SHELL} /root/compile/yar/yar-0.99/admin/missing --run autoconf
AUTOMAKE = ${SHELL} /root/compile/yar/yar-0.99/admin/missing --run automake
AUTOHEADER = ${SHELL} /root/compile/yar/yar-0.99/admin/missing --run autoheader

INSTALL = /usr/bin/install -c -p
INSTALL_PROGRAM = ${INSTALL} $(INSTALL_STRIP_FLAG)
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_SCRIPT = ${INSTALL}
INSTALL_HEADER = $(INSTALL_DATA)
transform = s,x,x,
NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
build_alias = aarch64-unknown-linux-gnu
build_triplet = aarch64-unknown-linux-gnu
host_alias = 
host_triplet = aarch64-unknown-linux-gnu
target_alias = 
target_triplet = aarch64-unknown-linux-gnu
AMTAR = ${SHELL} /root/compile/yar/yar-0.99/admin/missing --run tar
ARTSCCONFIG = @ARTSCCONFIG@
AS = @AS@
AUTODIRS = 
AWK = gawk
CC = gcc
CONF_FILES =  $(top_srcdir)/configure.in.in
CPP = gcc -E
CXX = g++
CXXCPP = g++ -E
DCOPIDL = @DCOPIDL@
DCOPIDL2CPP = @DCOPIDL2CPP@
DCOP_DEPENDENCIES = @DCOP_DEPENDENCIES@
DEPDIR = .deps
DLLTOOL = @DLLTOOL@
DOXYGEN = @DOXYGEN@
DOXYGEN_PROJECT_NAME = @DOXYGEN_PROJECT_NAME@
DOXYGEN_PROJECT_NUMBER = @DOXYGEN_PROJECT_NUMBER@
DPMSINC = @DPMSINC@
DPMSLIB = @DPMSLIB@
ECHO = echo
EXEEXT = 
FRAMEWORK_COREAUDIO = @FRAMEWORK_COREAUDIO@
GCJ = @GCJ@
GCJFLAGS = @GCJFLAGS@
GLINC = @GLINC@
GLLIB = @GLLIB@
GMSGFMT = @GMSGFMT@
IDL = @IDL@
IDL_DEPENDENCIES = @IDL_DEPENDENCIES@
INSTALL_STRIP_PROGRAM = ${SHELL} $(install_sh) -c -s
JAR = @JAR@
JAVAC = @JAVAC@
JAVAH = @JAVAH@
JVMLIBS = @JVMLIBS@
KDECONFIG = @KDECONFIG@
KDE_EXTRA_RPATH = @KDE_EXTRA_RPATH@
KDE_HAS_DOXYGEN = @KDE_HAS_DOXYGEN@
KDE_HAVE_DOT = @KDE_HAVE_DOT@
KDE_INCLUDES = @KDE_INCLUDES@
KDE_LDFLAGS = @KDE_LDFLAGS@
KDE_MT_LDFLAGS = @KDE_MT_LDFLAGS@
KDE_MT_LIBS = @KDE_MT_LIBS@
KDE_PLUGIN = -avoid-version -module -no-undefined $(KDE_RPATH) $(KDE_MT_LDFLAGS)
KDE_RPATH = @KDE_RPATH@
KDE_USE_CLOSURE_FALSE = #
KDE_USE_CLOSURE_TRUE = 
KDE_USE_FINAL_FALSE = 
KDE_USE_FINAL_TRUE = #
KDE_XSL_STYLESHEET = @KDE_XSL_STYLESHEET@
LEX = @LEX@
LEXLIB = @LEXLIB@
LIBBZ2 = @LIBBZ2@
LIBCOMPAT = @LIBCOMPAT@
LIBCRYPT = @LIBCRYPT@
LIBDL = @LIBDL@
LIBGEN = @LIBGEN@
LIBJPEG = @LIBJPEG@
LIBMICO = @LIBMICO@
LIBOBJS = 
LIBPNG = @LIBPNG@
LIBPTHREAD = @LIBPTHREAD@
LIBPYTHON = @LIBPYTHON@
LIBQIMGIO = @LIBQIMGIO@
LIBRESOLV = @LIBRESOLV@
LIBSHADOW = @LIBSHADOW@
LIBSM = @LIBSM@
LIBSOCKET = @LIBSOCKET@
LIBSSL = @LIBSSL@
LIBTIFF = @LIBTIFF@
LIBTOOL = $(SHELL) $(top_builddir)/libtool --silent
LIBUCB = @LIBUCB@
LIBUTIL = @LIBUTIL@
LIBXINERAMA = @LIBXINERAMA@
LIBZ = @LIBZ@
LIB_KAB = @LIB_KAB@
LIB_KABC = @LIB_KABC@
LIB_KDECORE = @LIB_KDECORE@
LIB_KDEPRINT = @LIB_KDEPRINT@
LIB_KDEUI = @LIB_KDEUI@
LIB_KFILE = @LIB_KFILE@
LIB_KFM = @LIB_KFM@
LIB_KHTML = @LIB_KHTML@
LIB_KIMGIO = @LIB_KIMGIO@
LIB_KIO = @LIB_KIO@
LIB_KPARTS = @LIB_KPARTS@
LIB_KSPELL = @LIB_KSPELL@
LIB_KSYCOCA = @LIB_KSYCOCA@
LIB_POLL = @LIB_POLL@
LIB_QPE = @LIB_QPE@
LIB_QT = @LIB_QT@
LIB_QTOPIA = @LIB_QTOPIA@
LIB_SMB = @LIB_SMB@
LIB_X11 = @LIB_X11@
LIB_XEXT = @LIB_XEXT@
LN_S = ln -s
MCOPIDL = @MCOPIDL@
MEINPROC = @MEINPROC@
MICO_INCLUDES = @MICO_INCLUDES@
MICO_LDFLAGS = @MICO_LDFLAGS@
MOC = @MOC@
MSGFMT = @MSGFMT@
NOOPT_CFLAGS = -O0
NOOPT_CXXFLAGS = -O0
NOREPO = -fno-repo
OBJDUMP = @OBJDUMP@
OBJEXT = o
PACKAGE = yar
PAMLIBS = @PAMLIBS@
PASSWDLIBS = @PASSWDLIBS@
PYTHONINC = @PYTHONINC@
PYTHONLIB = @PYTHONLIB@
PYTHONMODDIR = @PYTHONMODDIR@
QTDOCDIR = @QTDOCDIR@
QTE_NORTTI = @QTE_NORTTI@
QTOPIA_INCLUDES = @QTOPIA_INCLUDES@
QT_INCLUDES = @QT_INCLUDES@
QT_LDFLAGS = @QT_LDFLAGS@
RANLIB = ranlib
RC = @RC@
REPO = -frepo
SDL_CFLAGS = -I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT
SDL_CONFIG = /usr/bin/sdl-config
SDL_LIBS = -L/usr/lib/aarch64-linux-gnu -lSDL
SETUIDFLAGS = @SETUIDFLAGS@
SSL_INCLUDES = @SSL_INCLUDES@
SSL_LDFLAGS = @SSL_LDFLAGS@
STRIP = strip
TOPSUBDIRS =  yar
UIC = @UIC@
UIC_TR = @UIC_TR@
USER_INCLUDES = 
USER_LDFLAGS = 
USE_EXCEPTIONS = -fexceptions
USE_RTTI = 
USE_THREADS = @USE_THREADS@
VERSION = 0.99
WOVERLOADED_VIRTUAL = 
XGETTEXT = @XGETTEXT@
XPMINC = @XPMINC@
XPMLIB = @XPMLIB@
X_EXTRA_LIBS = @X_EXTRA_LIBS@
X_INCLUDES = @X_INCLUDES@
X_LDFLAGS = @X_LDFLAGS@
X_PRE_LIBS = @X_PRE_LIBS@
all_includes =  
all_libraries =  
am__include = include
am__quote = 
idldir = @idldir@
install_sh = /root/compile/yar/yar-0.99/admin/install-sh
jni_includes = @jni_includes@
kde_appsdir = @kde_appsdir@
kde_bindir = @kde_bindir@
kde_confdir = @kde_confdir@
kde_datadir = @kde_datadir@
kde_htmldir = @kde_htmldir@
kde_icondir = @kde_icondir@
kde_includes = @kde_includes@
kde_libraries = @kde_libraries@
kde_libs_htmldir = @kde_libs_htmldir@
kde_libs_prefix = @kde_libs_prefix@
kde_locale = @kde_locale@
kde_mimedir = @kde_mimedir@
kde_moduledir = @kde_moduledir@
kde_qtver = @kde_qtver@
kde_servicesdir = @kde_servicesdir@
kde_servicetypesdir = @kde_servicetypesdir@
kde_sounddir = @kde_sounddir@
kde_styledir = @kde_styledir@
kde_templatesdir = @kde_templatesdir@
kde_wallpaperdir = @kde_wallpaperdir@
kde_widgetdir = @kde_widgetdir@
micodir = @micodir@
qt_includes = @qt_includes@
qt_libraries = @qt_libraries@
x_includes = @x_includes@
x_libraries = @x_libraries@

SUBDIRS = yar 

EXTRA_DIST = yar.kdevprj admin AUTHORS COPYING ChangeLog INSTALL README TODO 

####### kdevelop will overwrite this part!!! (end)############
# not a GNU package. You can remove this line, if
# have all needed files, that a GNU package needs
AUTOMAKE_OPTIONS = foreign

MAINTAINERCLEANFILES = subdirs configure.in acinclude.m4 configure.files
subdir = .
ACLOCAL_M4 = $(top_srcdir)/aclocal.m4
mkinstalldirs = $(SHELL) $(top_srcdir)/admin/mkinstalldirs
CONFIG_HEADER = config.h
CONFIG_CLEAN_FILES =
DIST_SOURCES =

RECURSIVE_TARGETS = info-recursive dvi-recursive install-info-recursive \
	uninstall-info-recursive all-recursive install-data-recursive \
	install-exec-recursive installdirs-recursive install-recursive \
	uninstall-recursive check-recursive installcheck-recursive
DIST_COMMON = README ./stamp-h.in AUTHORS COPYING ChangeLog INSTALL \
	Makefile.am Makefile.in TODO acinclude.m4 aclocal.m4 \
	admin/ChangeLog admin/compile admin/config.guess \
	admin/config.sub admin/depcomp admin/install-sh admin/ltmain.sh \
	admin/missing admin/mkinstalldirs admin/ylwrap config.h.in \
	configure configure.in
DIST_SUBDIRS = $(SUBDIRS)
#>- all: config.h
#>+ 1
all: docs-am  config.h
	$(MAKE) $(AM_MAKEFLAGS) all-recursive

.SUFFIXES:

mostlyclean-libtool:
	-rm -f *.lo

clean-libtool:
	-rm -rf .libs _libs

distclean-libtool:
	-rm -f libtool
$(srcdir)/Makefile.in:  Makefile.am  $(top_srcdir)/configure.in $(ACLOCAL_M4)
#>- 	cd $(top_srcdir) && \
#>- 	  $(AUTOMAKE) --foreign  Makefile
#>+ 3
	cd $(top_srcdir) && \
	  $(AUTOMAKE) --foreign  Makefile
	cd $(top_srcdir) && perl admin/am_edit yar-0.99/Makefile.in
Makefile:  $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) && \
	  CONFIG_HEADERS= CONFIG_LINKS= \
	  CONFIG_FILES=$@ $(SHELL) ./config.status

$(top_builddir)/config.status: $(srcdir)/configure $(CONFIG_STATUS_DEPENDENCIES)
	$(SHELL) ./config.status --recheck
$(srcdir)/configure:  $(srcdir)/configure.in $(ACLOCAL_M4) $(CONFIGURE_DEPENDENCIES)
	cd $(srcdir) && $(AUTOCONF)

$(ACLOCAL_M4):  configure.in acinclude.m4
	cd $(srcdir) && $(ACLOCAL) $(ACLOCAL_AMFLAGS)
config.h: stamp-h
	@if test ! -f $@; then \
		rm -f stamp-h; \
		$(MAKE) stamp-h; \
	else :; fi
stamp-h: $(srcdir)/config.h.in $(top_builddir)/config.status
	@rm -f stamp-h stamp-hT
	@echo timestamp > stamp-hT 2> /dev/null
	cd $(top_builddir) \
	  && CONFIG_FILES= CONFIG_HEADERS=config.h \
	     $(SHELL) ./config.status
	@mv stamp-hT stamp-h
$(srcdir)/config.h.in:  $(srcdir)/./stamp-h.in
	@if test ! -f $@; then \
		rm -f $(srcdir)/./stamp-h.in; \
		$(MAKE) $(srcdir)/./stamp-h.in; \
	else :; fi
$(srcdir)/./stamp-h.in: $(top_srcdir)/configure.in $(ACLOCAL_M4) 
	@rm -f $(srcdir)/./stamp-h.in $(srcdir)/./stamp-h.inT
	@echo timestamp > $(srcdir)/./stamp-h.inT 2> /dev/null
	cd $(top_srcdir) && $(AUTOHEADER)
	@mv $(srcdir)/./stamp-h.inT $(srcdir)/./stamp-h.in

distclean-hdr:
	-rm -f config.h
uninstall-info-am:

# This directory's subdirectories are mostly independent; you can cd
# into them and run `make' without going through this Makefile.
# To change the values of `make' variables: instead of editing Makefiles,
# (1) if the variable is set in `config.status', edit `config.status'
#     (which will cause the Makefiles to be regenerated when you run `make');
# (2) otherwise, pass the desired values on the `make' command line.
$(RECURSIVE_TARGETS):
	@set fnord $(MAKEFLAGS); amf=$$2; \
	dot_seen=no; \
	target=`echo $@ | sed s/-recursive//`; \
	list='$(SUBDIRS)'; for subdir in $$list; do \
	  echo "Making $$target in $$subdir"; \
	  if test "$$subdir" = "."; then \
	    dot_seen=yes; \
	    local_target="$$target-am"; \
	  else \
	    local_target="$$target"; \
	  fi; \
	  (cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) $$local_target) \
	   || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; \
	done; \
	if test "$$dot_seen" = "no"; then \
	  $(MAKE) $(AM_MAKEFLAGS) "$$target-am" || exit 1; \
	fi; test -z "$$fail"

mostlyclean-recursive clean-recursive distclean-recursive \
maintainer-clean-recursive:
	@set fnord $(MAKEFLAGS); amf=$$2; \
	dot_seen=no; \
	case "$@" in \
	  distclean-* | maintainer-clean-*) list='$(DIST_SUBDIRS)' ;; \
	  *) list='$(SUBDIRS)' ;; \
	esac; \
	rev=''; for subdir in $$list; do \
	  if test "$$subdir" = "."; then :; else \
	    rev="$$subdir $$rev"; \
	  fi; \
	done; \
	rev="$$rev ."; \
	target=`echo $@ | sed s/-recursive//`; \
	for subdir in $$rev; do \
	  echo "Making $$target in $$subdir"; \
	  if test "$$subdir" = "."; then \
	    local_target="$$target-am"; \
	  else \
	    local_target="$$target"; \
	  fi; \
	  (cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) $$local_target) \
	   || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; \
	done && test -z "$$fail"
tags-recursive:
	list='$(SUBDIRS)'; for subdir in $$list; do \
	  test "$$subdir" = . || (cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) tags); \
	done

tags: TAGS

ID: $(HEADERS) $(SOURCES) $(LISP) $(TAGS_FILES)
	list='$(SOURCES) $(HEADERS) $(TAGS_FILES)'; \
	unique=`for i in $$list; do \
	    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
	  done | \
	  $(AWK) '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	mkid -fID $$unique $(LISP)

TAGS: tags-recursive $(HEADERS) $(SOURCES) config.h.in $(TAGS_DEPENDENCIES) \
		$(TAGS_FILES) $(LISP)
	tags=; \
	here=`pwd`; \
	list='$(SUBDIRS)'; for subdir in $$list; do \
	  if test "$$subdir" = .; then :; else \
	    test -f $$subdir/TAGS && tags="$$tags -i $$here/$$subdir/TAGS"; \
	  fi; \
	done; \
	list='$(SOURCES) $(HEADERS) $(TAGS_FILES)'; \
	unique=`for i in $$list; do \
	    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
	  done | \
	  $(AWK) '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	test -z "$(ETAGS_ARGS)config.h.in$$unique$(LISP)$$tags" \
	  || etags $(ETAGS_ARGS) $$tags config.h.in $$unique $(LISP)

GTAGS:
	here=`CDPATH=: && cd $(top_builddir) && pwd` \
	  && cd $(top_srcdir) \
	  && gtags -i $(GTAGS_ARGS) $$here

distclean-tags:
	-rm -f TAGS ID GTAGS GRTAGS GSYMS GPATH

#>- DISTFILES = $(DIST_COMMON) $(DIST_SOURCES) $(TEXINFOS) $(EXTRA_DIST)
#>+ 4
KDE_DIST=subdirs configure.files yar.kdevses Makefile.dist configure.in.in 

DISTFILES= $(DIST_COMMON) $(DIST_SOURCES) $(TEXINFOS) $(EXTRA_DIST) $(KDE_DIST)


top_distdir = .
# Avoid unsightly `./'.
distdir = $(PACKAGE)-$(VERSION)

GZIP_ENV = --best

distdir: $(DISTFILES)
	-chmod -R a+w $(distdir) >/dev/null 2>&1; rm -rf $(distdir)
	mkdir $(distdir)
	$(mkinstalldirs) $(distdir)/admin
	@for file in $(DISTFILES); do \
	  if test -f $$file; then d=.; else d=$(srcdir); fi; \
	  dir=`echo "$$file" | sed -e 's,/[^/]*$$,,'`; \
	  if test "$$dir" != "$$file" && test "$$dir" != "."; then \
	    $(mkinstalldirs) "$(distdir)/$$dir"; \
	  fi; \
	  if test -d $$d/$$file; then \
	    cp -pR $$d/$$file $(distdir) \
	    || exit 1; \
	  else \
	    test -f $(distdir)/$$file \
	    || cp -p $$d/$$file $(distdir)/$$file \
	    || exit 1; \
	  fi; \
	done
	for subdir in $(SUBDIRS); do \
	  if test "$$subdir" = .; then :; else \
	    test -d $(distdir)/$$subdir \
	    || mkdir $(distdir)/$$subdir \
	    || exit 1; \
	    (cd $$subdir && \
	      $(MAKE) $(AM_MAKEFLAGS) \
	        top_distdir="$(top_distdir)" \
	        distdir=../$(distdir)/$$subdir \
	        distdir) \
	      || exit 1; \
	  fi; \
	done
	$(MAKE) $(AM_MAKEFLAGS) \
	  top_distdir="${top_distdir}" distdir="$(distdir)" \
	  dist-hook
	-find $(distdir) -type d ! -perm -777 -exec chmod a+rwx {} \; -o \
	  ! -type d ! -perm -444 -links 1 -exec chmod a+r {} \; -o \
	  ! -type d ! -perm -400 -exec chmod a+r {} \; -o \
	  ! -type d ! -perm -444 -exec $(SHELL) $(install_sh) -c -m a+r {} {} \; \
	|| chmod -R a+r $(distdir)
dist: distdir
	$(AMTAR) chof - $(distdir) | GZIP=$(GZIP_ENV) gzip -c >$(distdir).tar.gz
	-chmod -R a+w $(distdir) >/dev/null 2>&1; rm -rf $(distdir)

# This target untars the dist file and tries a VPATH configuration.  Then
# it guarantees that the distribution is self-contained by making another
# tarfile.
distcheck: dist
	-chmod -R a+w $(distdir) > /dev/null 2>&1; rm -rf $(distdir)
	GZIP=$(GZIP_ENV) gunzip -c $(distdir).tar.gz | $(AMTAR) xf -
	chmod -R a-w $(distdir); chmod a+w $(distdir)
	mkdir $(distdir)/=build
	mkdir $(distdir)/=inst
	chmod a-w $(distdir)
	dc_install_base=`CDPATH=: && cd $(distdir)/=inst && pwd` \
	  && cd $(distdir)/=build \
	  && ../configure --srcdir=.. --prefix=$$dc_install_base \
	  && $(MAKE) $(AM_MAKEFLAGS) \
	  && $(MAKE) $(AM_MAKEFLAGS) dvi \
	  && $(MAKE) $(AM_MAKEFLAGS) check \
	  && $(MAKE) $(AM_MAKEFLAGS) install \
	  && $(MAKE) $(AM_MAKEFLAGS) installcheck \
	  && $(MAKE) $(AM_MAKEFLAGS) uninstall \
	  && (test `find $$dc_install_base -type f -print | wc -l` -le 1 \
	     || (echo "Error: files left after uninstall" 1>&2; \
	         exit 1) ) \
	  && $(MAKE) $(AM_MAKEFLAGS) dist \
	  && $(MAKE) $(AM_MAKEFLAGS) distclean \
	  && rm -f $(distdir).tar.gz \
	  && (test `find . -type f -print | wc -l` -eq 0 \
	     || (echo "Error: files left after distclean" 1>&2; \
	         exit 1) )
	-chmod -R a+w $(distdir) > /dev/null 2>&1; rm -rf $(distdir)
	@echo "$(distdir).tar.gz is ready for distribution" | \
	  sed 'h;s/./=/g;p;x;p;x'
check-am: all-am
check: check-recursive
all-am: Makefile config.h
installdirs: installdirs-recursive
installdirs-am:

install: install-recursive
install-exec: install-exec-recursive
install-data: install-data-recursive
uninstall: uninstall-recursive

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am

installcheck: installcheck-recursive
install-strip:
	$(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	  `test -z '$(STRIP)' || \
	    echo "INSTALL_PROGRAM_ENV=STRIPPROG='$(STRIP)'"` install
mostlyclean-generic:

clean-generic:

distclean-generic:
	-rm -f Makefile $(CONFIG_CLEAN_FILES) stamp-h stamp-h[0-9]*

maintainer-clean-generic:
	@echo "This command is intended for maintainers to use"
	@echo "it deletes files that may require special tools to rebuild."
	-test -z "$(MAINTAINERCLEANFILES)" || rm -f $(MAINTAINERCLEANFILES)
#>- clean: clean-recursive
#>+ 1
clean: kde-rpo-clean  clean-recursive

clean-am: clean-generic clean-libtool mostlyclean-am

dist-all: distdir
	$(AMTAR) chof - $(distdir) | GZIP=$(GZIP_ENV) gzip -c >$(distdir).tar.gz
	-chmod -R a+w $(distdir) >/dev/null 2>&1; rm -rf $(distdir)
distclean: distclean-recursive
	-rm -f config.status config.cache config.log
distclean-am: clean-am distclean-generic distclean-hdr distclean-libtool \
	distclean-tags

dvi: dvi-recursive

dvi-am:

info: info-recursive

info-am:

install-data-am:

install-exec-am:

install-info: install-info-recursive

install-man:

installcheck-am:

maintainer-clean: maintainer-clean-recursive

maintainer-clean-am: distclean-am maintainer-clean-generic

mostlyclean: mostlyclean-recursive

mostlyclean-am: mostlyclean-generic mostlyclean-libtool

uninstall-am: uninstall-info-am

uninstall-info: uninstall-info-recursive

.PHONY: $(RECURSIVE_TARGETS) GTAGS all all-am check check-am clean \
	clean-generic clean-libtool clean-recursive dist dist-all \
	distcheck distclean distclean-generic distclean-hdr \
	distclean-libtool distclean-recursive distclean-tags distdir \
	dvi dvi-am dvi-recursive info info-am info-recursive install \
	install-am install-data install-data-am install-data-recursive \
	install-exec install-exec-am install-exec-recursive \
	install-info install-info-am install-info-recursive install-man \
	install-recursive install-strip installcheck installcheck-am \
	installdirs installdirs-am installdirs-recursive \
	maintainer-clean maintainer-clean-generic \
	maintainer-clean-recursive mostlyclean mostlyclean-generic \
	mostlyclean-libtool mostlyclean-recursive tags tags-recursive \
	uninstall uninstall-am uninstall-info-am \
	uninstall-info-recursive uninstall-recursive


$(top_srcdir)/configure.in: configure.in.in $(top_srcdir)/subdirs
	cd $(top_srcdir) && $(MAKE) -f admin/Makefile.common configure.in ;

$(top_srcdir)/subdirs:
	cd $(top_srcdir) && $(MAKE) -f admin/Makefile.common subdirs

$(top_srcdir)/acinclude.m4: $(top_srcdir)/admin/acinclude.m4.in $(top_srcdir)/admin/libtool.m4.in
	@cd $(top_srcdir) && cat admin/acinclude.m4.in admin/libtool.m4.in > acinclude.m4

package-messages:
	$(MAKE) -f admin/Makefile.common package-messages

dist-hook:
	cd $(top_distdir) && perl admin/am_edit -padmin
	cd $(top_distdir) && $(MAKE) -f admin/Makefile.common subdirs
# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:


#>+ 2
docs-am:

#>+ 6
force-reedit:
		cd $(top_srcdir) && \
	  $(AUTOMAKE) --foreign  Makefile
	cd $(top_srcdir) && perl admin/am_edit yar-0.99/Makefile.in


#>+ 2
final:
	$(MAKE) all-am
#>+ 2
final-install:
	$(MAKE) install-am
#>+ 2
no-final:
	$(MAKE) all-am
#>+ 2
no-final-install:
	$(MAKE) install-am
#>+ 3
cvs-clean:
	$(MAKE) admindir=$(top_srcdir)/admin -f $(top_srcdir)/admin/Makefile.common cvs-clean

#>+ 3
kde-rpo-clean:
	-rm -f *.rpo
