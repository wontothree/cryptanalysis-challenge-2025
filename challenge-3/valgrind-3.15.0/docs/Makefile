# Makefile.in generated by automake 1.16.5 from Makefile.am.
# docs/Makefile.  Generated from Makefile.in by configure.

# Copyright (C) 1994-2021 Free Software Foundation, Inc.

# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.



am__is_gnu_make = { \
  if test -z '$(MAKELEVEL)'; then \
    false; \
  elif test -n '$(MAKE_HOST)'; then \
    true; \
  elif test -n '$(MAKE_VERSION)' && test -n '$(CURDIR)'; then \
    true; \
  else \
    false; \
  fi; \
}
am__make_running_with_option = \
  case $${target_option-} in \
      ?) ;; \
      *) echo "am__make_running_with_option: internal error: invalid" \
              "target option '$${target_option-}' specified" >&2; \
         exit 1;; \
  esac; \
  has_opt=no; \
  sane_makeflags=$$MAKEFLAGS; \
  if $(am__is_gnu_make); then \
    sane_makeflags=$$MFLAGS; \
  else \
    case $$MAKEFLAGS in \
      *\\[\ \	]*) \
        bs=\\; \
        sane_makeflags=`printf '%s\n' "$$MAKEFLAGS" \
          | sed "s/$$bs$$bs[$$bs $$bs	]*//g"`;; \
    esac; \
  fi; \
  skip_next=no; \
  strip_trailopt () \
  { \
    flg=`printf '%s\n' "$$flg" | sed "s/$$1.*$$//"`; \
  }; \
  for flg in $$sane_makeflags; do \
    test $$skip_next = yes && { skip_next=no; continue; }; \
    case $$flg in \
      *=*|--*) continue;; \
        -*I) strip_trailopt 'I'; skip_next=yes;; \
      -*I?*) strip_trailopt 'I';; \
        -*O) strip_trailopt 'O'; skip_next=yes;; \
      -*O?*) strip_trailopt 'O';; \
        -*l) strip_trailopt 'l'; skip_next=yes;; \
      -*l?*) strip_trailopt 'l';; \
      -[dEDm]) skip_next=yes;; \
      -[JT]) skip_next=yes;; \
    esac; \
    case $$flg in \
      *$$target_option*) has_opt=yes; break;; \
    esac; \
  done; \
  test $$has_opt = yes
am__make_dryrun = (target_option=n; $(am__make_running_with_option))
am__make_keepgoing = (target_option=k; $(am__make_running_with_option))
pkgdatadir = $(datadir)/valgrind
pkgincludedir = $(includedir)/valgrind
pkglibdir = $(libdir)/valgrind
pkglibexecdir = $(libexecdir)/valgrind
am__cd = CDPATH="$${ZSH_VERSION+.}$(PATH_SEPARATOR)" && cd
install_sh_DATA = $(install_sh) -c -m 644
install_sh_PROGRAM = $(install_sh) -c
install_sh_SCRIPT = $(install_sh) -c
INSTALL_HEADER = $(INSTALL_DATA)
transform = $(program_transform_name)
NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
build_triplet = x86_64-unknown-linux-gnu
host_triplet = x86_64-unknown-linux-gnu
subdir = docs
ACLOCAL_M4 = $(top_srcdir)/aclocal.m4
am__aclocal_m4_deps = $(top_srcdir)/configure.ac
am__configure_deps = $(am__aclocal_m4_deps) $(CONFIGURE_DEPENDENCIES) \
	$(ACLOCAL_M4)
DIST_COMMON = $(srcdir)/Makefile.am $(am__DIST_COMMON)
mkinstalldirs = $(install_sh) -d
CONFIG_HEADER = $(top_builddir)/config.h
CONFIG_CLEAN_FILES =
CONFIG_CLEAN_VPATH_FILES =
AM_V_P = $(am__v_P_$(V))
am__v_P_ = $(am__v_P_$(AM_DEFAULT_VERBOSITY))
am__v_P_0 = false
am__v_P_1 = :
AM_V_GEN = $(am__v_GEN_$(V))
am__v_GEN_ = $(am__v_GEN_$(AM_DEFAULT_VERBOSITY))
am__v_GEN_0 = @echo "  GEN     " $@;
am__v_GEN_1 = 
AM_V_at = $(am__v_at_$(V))
am__v_at_ = $(am__v_at_$(AM_DEFAULT_VERBOSITY))
am__v_at_0 = @
am__v_at_1 = 
SOURCES =
DIST_SOURCES =
am__can_run_installinfo = \
  case $$AM_UPDATE_INFO_DIR in \
    n|no|NO) false;; \
    *) (install-info --version) >/dev/null 2>&1;; \
  esac
am__tagged_files = $(HEADERS) $(SOURCES) $(TAGS_FILES) $(LISP)
am__DIST_COMMON = $(srcdir)/Makefile.in README
DISTFILES = $(DIST_COMMON) $(DIST_SOURCES) $(TEXINFOS) $(EXTRA_DIST)
ACLOCAL = ${SHELL} '/workspace/challenge-3/valgrind-3.15.0/missing' aclocal-1.16
AMTAR = $${TAR-tar}
AM_DEFAULT_VERBOSITY = 1
AR = /usr/bin/ar
AUTOCONF = ${SHELL} '/workspace/challenge-3/valgrind-3.15.0/missing' autoconf
AUTOHEADER = ${SHELL} '/workspace/challenge-3/valgrind-3.15.0/missing' autoheader
AUTOMAKE = ${SHELL} '/workspace/challenge-3/valgrind-3.15.0/missing' automake-1.16
AWK = mawk
BOOST_CFLAGS = 
BOOST_LIBS = 
CC = gcc
CCAS = gcc
CCASDEPMODE = depmode=gcc3
CCASFLAGS = 
CCDEPMODE = depmode=gcc3
CFLAGS = 
CFLAGS_MPI = -g -O -fno-omit-frame-pointer -Wall -fpic
CPP = gcc -E
CPPFLAGS = 
CSCOPE = cscope
CTAGS = ctags
CXX = g++
CXXDEPMODE = depmode=gcc3
CXXFLAGS = 
CYGPATH_W = echo
DEFAULT_SUPP = exp-sgcheck.supp xfree-3.supp xfree-4.supp glibc-2.X-drd.supp glibc-2.34567-NPTL-helgrind.supp glibc-2.X.supp 
DEFS = -DHAVE_CONFIG_H
DEPDIR = .deps
DIFF = diff -u
DIS_PATH = 
ECHO_C = 
ECHO_N = -n
ECHO_T = 
EGREP = /usr/bin/grep -E
ETAGS = etags
EXEEXT = 
FLAG_FALIGNED_NEW = -faligned-new
FLAG_FINLINE_FUNCTIONS = -finline-functions
FLAG_FNO_IPA_ICF = -fno-ipa-icf
FLAG_FNO_STACK_PROTECTOR = -fno-stack-protector
FLAG_FSANITIZE = 
FLAG_M32 = -m32
FLAG_M64 = -m64
FLAG_MLONG_DOUBLE_128 = -mlong-double-128
FLAG_MMMX = -mmmx
FLAG_MSA = 
FLAG_MSSE = -msse
FLAG_NO_BUILD_ID = 
FLAG_NO_PIE = -no-pie
FLAG_OCTEON = 
FLAG_OCTEON2 = 
FLAG_PIE = -pie
FLAG_T_TEXT = -Ttext-segment
FLAG_UNLIMITED_INLINE_UNIT_GROWTH = --param inline-unit-growth=900
FLAG_W_CAST_ALIGN = -Wcast-align
FLAG_W_CAST_QUAL = -Wcast-qual
FLAG_W_EMPTY_BODY = -Wempty-body
FLAG_W_ENUM_CONVERSION = -Wenum-conversion
FLAG_W_EXTRA = -Wextra
FLAG_W_FORMAT = -Wformat
FLAG_W_FORMAT_SECURITY = -Wformat-security
FLAG_W_FORMAT_SIGNEDNESS = -Wformat-signedness
FLAG_W_IGNORED_QUALIFIERS = -Wignored-qualifiers
FLAG_W_IMPLICIT_FALLTHROUGH = -Wimplicit-fallthrough=2
FLAG_W_LOGICAL_OP = -Wlogical-op
FLAG_W_MISSING_PARAMETER_TYPE = -Wmissing-parameter-type
FLAG_W_NO_INFINITE_RECURSION = 
FLAG_W_NO_MEMSET_TRANSPOSED_ARGS = -Wno-memset-transposed-args
FLAG_W_NO_MISMATCHED_NEW_DELETE = -Wno-mismatched-new-delete
FLAG_W_NO_NONNULL = -Wno-nonnull
FLAG_W_NO_OVERFLOW = -Wno-overflow
FLAG_W_NO_POINTER_SIGN = -Wno-pointer-sign
FLAG_W_NO_STATIC_LOCAL_IN_INLINE = 
FLAG_W_NO_UNINITIALIZED = -Wno-uninitialized
FLAG_W_NO_UNUSED_FUNCTION = -Wno-unused-function
FLAG_W_OLD_STYLE_DECLARATION = -Wold-style-declaration
FLAG_W_WRITE_STRINGS = -Wwrite-strings
GDB = /usr/bin/gdb
GLIBC_VERSION = 2.35
GREP = /usr/bin/grep
HWCAP_HAS_ALTIVEC = 
HWCAP_HAS_DFP = 
HWCAP_HAS_HTM = 
HWCAP_HAS_ISA_2_05 = 
HWCAP_HAS_ISA_2_06 = 
HWCAP_HAS_ISA_2_07 = 
HWCAP_HAS_ISA_3_00 = 
HWCAP_HAS_VSX = 
INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_STRIP_PROGRAM = $(install_sh) -c -s
LDFLAGS = 
LDFLAGS_MPI = -fpic -shared
LIBOBJS = 
LIBS = 
LIB_UBSAN = 
LN_S = ln -s
LTLIBOBJS = 
LTO_AR = /usr/bin/ar
LTO_CFLAGS = 
LTO_RANLIB = ranlib
MAINT = #
MAKEINFO = ${SHELL} '/workspace/challenge-3/valgrind-3.15.0/missing' makeinfo
MKDIR_P = /usr/bin/mkdir -p
MPI_CC = mpicc
OBJEXT = o
PACKAGE = valgrind
PACKAGE_BUGREPORT = valgrind-users@lists.sourceforge.net
PACKAGE_NAME = Valgrind
PACKAGE_STRING = Valgrind 3.15.0
PACKAGE_TARNAME = valgrind
PACKAGE_URL = 
PACKAGE_VERSION = 3.15.0
PATH_SEPARATOR = :
PERL = /usr/bin/perl
PREFERRED_STACK_BOUNDARY_2 = -mpreferred-stack-boundary=2
RANLIB = ranlib
SED = /usr/bin/sed
SET_MAKE = 
SHELL = /bin/bash
SOLARIS_UNDEF_LARGESOURCE = 
STRIP = 
VALT_LOAD_ADDRESS_PRI = 0x58000000
VALT_LOAD_ADDRESS_SEC = 0xUNSET
VERSION = 3.15.0
VGCONF_ABI = 
VGCONF_ARCH_PRI = amd64
VGCONF_ARCH_SEC = 
VGCONF_OS = linux
VGCONF_PLATFORM_PRI_CAPS = AMD64_LINUX
VGCONF_PLATFORM_SEC_CAPS = 
VGCONF_PLATVARIANT = vanilla
VG_TMPDIR = /tmp
abs_builddir = /workspace/challenge-3/valgrind-3.15.0/docs
abs_srcdir = /workspace/challenge-3/valgrind-3.15.0/docs
abs_top_builddir = /workspace/challenge-3/valgrind-3.15.0
abs_top_srcdir = /workspace/challenge-3/valgrind-3.15.0
ac_ct_CC = gcc
ac_ct_CXX = g++
am__include = include
am__leading_dot = .
am__quote = 
am__tar = $${TAR-tar} chof - "$$tardir"
am__untar = $${TAR-tar} xf -
bindir = ${exec_prefix}/bin
build = x86_64-unknown-linux-gnu
build_alias = 
build_cpu = x86_64
build_os = linux-gnu
build_vendor = unknown
builddir = .
datadir = ${datarootdir}
datarootdir = ${prefix}/share
docdir = ${datarootdir}/doc/${PACKAGE_TARNAME}
dvidir = ${docdir}
exec_prefix = ${prefix}
host = x86_64-unknown-linux-gnu
host_alias = 
host_cpu = x86_64
host_os = linux-gnu
host_vendor = unknown
htmldir = ${docdir}
includedir = ${prefix}/include
infodir = ${datarootdir}/info
install_sh = ${SHELL} /workspace/challenge-3/valgrind-3.15.0/install-sh
libdir = ${exec_prefix}/lib
libexecdir = ${exec_prefix}/libexec
localedir = ${datarootdir}/locale
localstatedir = ${prefix}/var
mandir = ${datarootdir}/man
mkdir_p = $(MKDIR_P)
oldincludedir = /usr/include
pdfdir = ${docdir}
prefix = /usr
program_transform_name = s,x,x,
psdir = ${docdir}
runstatedir = ${localstatedir}/run
sbindir = ${exec_prefix}/sbin
sharedstatedir = ${prefix}/com
srcdir = .
sysconfdir = ${prefix}/etc
target_alias = 
top_build_prefix = ../
top_builddir = ..
top_srcdir = ..

# Comment out the next line to skip building print docs.  The default
# is not to skip building print docs.  Note, after changing it
# you need to re-run autogen.sh and configure to make it take effect.
BUILD_ALL_DOCS = yes
EXTRA_DIST = \
	README \
	images/home.png \
	images/next.png \
	images/prev.png \
	images/up.png \
	images/kcachegrind_xtree.png \
	images/dh-tree.png \
	internals/3_0_BUGSTATUS.txt \
	internals/3_1_BUGSTATUS.txt \
	internals/3_2_BUGSTATUS.txt \
	internals/3_3_BUGSTATUS.txt \
	internals/3_4_BUGSTATUS.txt \
	internals/3_5_BUGSTATUS.txt \
	internals/3_7_BUGSTATUS.txt \
	internals/3_8_BUGSTATUS.txt \
	internals/3_9_BUGSTATUS.txt \
	internals/3_10_BUGSTATUS.txt \
	internals/3_11_BUGSTATUS.txt \
	internals/3_12_BUGSTATUS.txt \
	internals/3_13_BUGSTATUS.txt \
	internals/3_14_BUGSTATUS.txt \
	internals/MERGE_3_10_1.txt \
	internals/arm_thumb_notes_gdbserver.txt \
	internals/avx-notes.txt \
	internals/BIG_APP_NOTES.txt \
	internals/Darwin-notes.txt \
	internals/SPEC-notes.txt \
	internals/directory-structure.txt \
	internals/howto_BUILD_KDE42.txt \
	internals/howto_oprofile.txt \
	internals/m_replacemalloc.txt \
	internals/m_syswrap.txt \
	internals/module-structure.txt \
	internals/multiple-architectures.txt \
	internals/notes.txt \
	internals/performance.txt \
	internals/porting-HOWTO.txt \
	internals/mpi2entries.txt \
	internals/porting-to-ARM.txt \
	internals/qemu-aarch64-linux-HOWTO.txt \
	internals/qemu-mips64-linux-HOWTO.txt \
	internals/register-uses.txt \
	internals/release-HOWTO.txt \
	internals/segments-seginfos.txt \
	internals/t-chaining-notes.txt \
	internals/threads-syscalls-signals.txt \
	internals/tm-mutexstates.dot \
	internals/tm-threadstates.dot \
	internals/tracking-fn-entry-exit.txt \
	internals/why-no-libc.txt \
	internals/xml-output.txt \
	internals/xml-output-protocol4.txt \
	lib/line-wrap.xsl \
	lib/vg_basic.css \
	lib/vg-fo.xsl \
	lib/vg-faq2txt.xsl \
	lib/vg-html-chunk.xsl \
	lib/vg-html-website.xsl \
	lib/vg-html-common.xsl \
	xml/FAQ.xml \
	xml/dist-docs.xml \
	xml/index.xml \
	xml/licenses.xml \
	xml/manpages-index.xml \
	xml/manual.xml \
	xml/manual-intro.xml \
	xml/manual-core.xml \
	xml/manual-core-adv.xml \
	xml/manual-writing-tools.xml \
	xml/design-impl.xml \
	xml/quick-start-guide.xml \
	xml/tech-docs.xml \
	xml/valgrind-manpage.xml \
	xml/vg-entities.xml \
	xml/xml_help.txt

myxmldir = $(top_srcdir)/docs/xml
myimgdir = $(top_srcdir)/docs/images
mylibdir = $(top_srcdir)/docs/lib
myhtmldir = $(top_builddir)/docs/html
myprintdir = $(top_builddir)/docs/print
websitedir = $(top_builddir)/docs/website
valkyriedir = $(top_builddir)/docs/vg-html
downloadsdir = $(top_builddir)/docs/downloads
vgdir = $(top_builddir)/docs/valgrind
XML_CATALOG_FILES = /etc/xml/catalog

# file to log print output to
LOGFILE = print.log

# validation stuff
XMLLINT = xmllint
LINT_FLAGS = --noblanks --noout --xinclude --postvalid --noent
# validate with docbook 4.3 'cos it supports xml:base natively
VALID_FLAGS = --dtdvalid http://www.oasis-open.org/docbook/xml/4.3/docbookx.dtd 
XMLLINT_FLAGS = $(LINT_FLAGS) $(VALID_FLAGS)

# stylesheet processor
XSLTPROC = xsltproc
XSLTPROC_FLAGS = --nonet --xinclude

# stylesheets
XSL_HTML_CHUNK_STYLE = $(mylibdir)/vg-html-chunk.xsl
XSL_FO_STYLE = $(mylibdir)/vg-fo.xsl
XSL_TEXT_STYLE = $(mylibdir)/vg-faq2txt.xsl
XSL_WEBSITE_STYLE = $(mylibdir)/vg-html-website.xsl
XSL_MAN_STYLES = \
    /usr/share/sgml/docbook/xsl-stylesheets/manpages/docbook.xsl \
    /usr/share/xml/docbook/stylesheet/nwalsh/current/manpages/docbook.xsl \
    /usr/share/xml/docbook/stylesheet/nwalsh/manpages/docbook.xsl

all: all-am

.SUFFIXES:
$(srcdir)/Makefile.in: # $(srcdir)/Makefile.am  $(am__configure_deps)
	@for dep in $?; do \
	  case '$(am__configure_deps)' in \
	    *$$dep*) \
	      ( cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh ) \
	        && { if test -f $@; then exit 0; else break; fi; }; \
	      exit 1;; \
	  esac; \
	done; \
	echo ' cd $(top_srcdir) && $(AUTOMAKE) --foreign docs/Makefile'; \
	$(am__cd) $(top_srcdir) && \
	  $(AUTOMAKE) --foreign docs/Makefile
Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@case '$?' in \
	  *config.status*) \
	    cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh;; \
	  *) \
	    echo ' cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__maybe_remake_depfiles)'; \
	    cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__maybe_remake_depfiles);; \
	esac;

$(top_builddir)/config.status: $(top_srcdir)/configure $(CONFIG_STATUS_DEPENDENCIES)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh

$(top_srcdir)/configure: # $(am__configure_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(ACLOCAL_M4): # $(am__aclocal_m4_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(am__aclocal_m4_deps):
tags TAGS:

ctags CTAGS:

cscope cscopelist:

distdir: $(BUILT_SOURCES)
	$(MAKE) $(AM_MAKEFLAGS) distdir-am

distdir-am: $(DISTFILES)
	@srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	topsrcdirstrip=`echo "$(top_srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	list='$(DISTFILES)'; \
	  dist_files=`for file in $$list; do echo $$file; done | \
	  sed -e "s|^$$srcdirstrip/||;t" \
	      -e "s|^$$topsrcdirstrip/|$(top_builddir)/|;t"`; \
	case $$dist_files in \
	  */*) $(MKDIR_P) `echo "$$dist_files" | \
			   sed '/\//!d;s|^|$(distdir)/|;s,/[^/]*$$,,' | \
			   sort -u` ;; \
	esac; \
	for file in $$dist_files; do \
	  if test -f $$file || test -d $$file; then d=.; else d=$(srcdir); fi; \
	  if test -d $$d/$$file; then \
	    dir=`echo "/$$file" | sed -e 's,/[^/]*$$,,'`; \
	    if test -d "$(distdir)/$$file"; then \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    if test -d $(srcdir)/$$file && test $$d != $(srcdir); then \
	      cp -fpR $(srcdir)/$$file "$(distdir)$$dir" || exit 1; \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    cp -fpR $$d/$$file "$(distdir)$$dir" || exit 1; \
	  else \
	    test -f "$(distdir)/$$file" \
	    || cp -p $$d/$$file "$(distdir)/$$file" \
	    || exit 1; \
	  fi; \
	done
	$(MAKE) $(AM_MAKEFLAGS) \
	  top_distdir="$(top_distdir)" distdir="$(distdir)" \
	  dist-hook
check-am: all-am
check: check-am
all-am: Makefile
installdirs:
install: install-am
install-exec: install-exec-am
install-data: install-data-am
uninstall: uninstall-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am

installcheck: installcheck-am
install-strip:
	if test -z '$(STRIP)'; then \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	      install; \
	else \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	    "INSTALL_PROGRAM_ENV=STRIPPROG='$(STRIP)'" install; \
	fi
mostlyclean-generic:

clean-generic:

distclean-generic:
	-test -z "$(CONFIG_CLEAN_FILES)" || rm -f $(CONFIG_CLEAN_FILES)
	-test . = "$(srcdir)" || test -z "$(CONFIG_CLEAN_VPATH_FILES)" || rm -f $(CONFIG_CLEAN_VPATH_FILES)

maintainer-clean-generic:
	@echo "This command is intended for maintainers to use"
	@echo "it deletes files that may require special tools to rebuild."
clean: clean-am

clean-am: clean-generic mostlyclean-am

distclean: distclean-am
	-rm -f Makefile
distclean-am: clean-am distclean-generic distclean-local

dvi: dvi-am

dvi-am:

html: html-am

html-am:

info: info-am

info-am:

install-data-am:
	@$(NORMAL_INSTALL)
	$(MAKE) $(AM_MAKEFLAGS) install-data-hook
install-dvi: install-dvi-am

install-dvi-am:

install-exec-am:

install-html: install-html-am

install-html-am:

install-info: install-info-am

install-info-am:

install-man:

install-pdf: install-pdf-am

install-pdf-am:

install-ps: install-ps-am

install-ps-am:

installcheck-am:

maintainer-clean: maintainer-clean-am
	-rm -f Makefile
maintainer-clean-am: distclean-am maintainer-clean-generic

mostlyclean: mostlyclean-am

mostlyclean-am: mostlyclean-generic

pdf: pdf-am

pdf-am:

ps: ps-am

ps-am:

uninstall-am:

.MAKE: install-am install-data-am install-strip

.PHONY: all all-am check check-am clean clean-generic cscopelist-am \
	ctags-am dist-hook distclean distclean-generic distclean-local \
	distdir dvi dvi-am html html-am info info-am install \
	install-am install-data install-data-am install-data-hook \
	install-dvi install-dvi-am install-exec install-exec-am \
	install-html install-html-am install-info install-info-am \
	install-man install-pdf install-pdf-am install-ps \
	install-ps-am install-strip installcheck installcheck-am \
	installdirs maintainer-clean maintainer-clean-generic \
	mostlyclean mostlyclean-generic pdf pdf-am ps ps-am tags-am \
	uninstall uninstall-am

.PRECIOUS: Makefile


all-docs: FAQ.txt man-pages html-docs print-docs

valid:
	$(XMLLINT) $(XMLLINT_FLAGS) $(myxmldir)/index.xml

# The text version of the FAQ.
FAQ.txt:
	@echo "Generating the text version of the FAQ ..."
	export XML_CATALOG_FILES=$(XML_CATALOG_FILES) && \
	$(XSLTPROC) $(XSLTPROC_FLAGS) -o ./FAQ.txt $(XSL_TEXT_STYLE) $(myxmldir)/FAQ.xml

# the valgrind manpages
man-pages:
	set -e; \
	for x in $(XSL_MAN_STYLES) ; do \
	    if test -f $$x; then \
		echo "Using manpage stylesheet: $$x"; \
		export XML_CATALOG_FILES=$(XML_CATALOG_FILES) && \
		$(XSLTPROC) $(XSLTPROC_FLAGS) -o ./ $$x $(myxmldir)/manpages-index.xml; \
		exit 0; \
	    fi; \
	done; \
	echo ""; \
	echo "Error: I can't find the XSL_MAN_STYLE file";     \
	echo "Please check where it lives on your system, and"      \
	     "amend the line 'XSL_MAN_STYLES = ' in this Makefile."; \
	exit 1;

# chunked html, on a chapter-by-chapter basis
html-docs:
	@echo "Generating html files..."
	export XML_CATALOG_FILES=$(XML_CATALOG_FILES) && \
	mkdir -p $(myhtmldir) && \
	/bin/rm -fr $(myhtmldir)/ && \
	mkdir -p $(myhtmldir)/ && \
	mkdir -p $(myhtmldir)/images && \
	cp $(mylibdir)/vg_basic.css $(myhtmldir)/ && \
	cp $(myimgdir)/*.png $(myhtmldir)/images && \
	$(XSLTPROC) $(XSLTPROC_FLAGS) -o $(myhtmldir)/ $(XSL_HTML_CHUNK_STYLE) $(myxmldir)/index.xml

# pdf and postscript
print-docs:
	@echo "Generating PDF file: $(myprintdir)/index.pdf (please be patient)...";
	export XML_CATALOG_FILES=$(XML_CATALOG_FILES) && \
	mkdir -p $(myprintdir) && \
	mkdir -p $(myprintdir)/images && \
	cp $(myimgdir)/*.png $(myprintdir)/images && \
	$(XSLTPROC) $(XSLTPROC_FLAGS) -o $(myprintdir)/index.fo $(XSL_FO_STYLE) $(myxmldir)/index.xml && \
	(cd $(myprintdir) && \
         ( pdfxmltex index.fo && \
	   pdfxmltex index.fo && \
	   pdfxmltex index.fo ) &> $(LOGFILE) < /dev/null && \
	 echo "Generating PS file: $(myprintdir)/index.ps ..." && \
	 pdftops index.pdf && \
	 rm -f *.log *.aux *.fo *.out)

# If the docs have been built, install them.  But don't worry if they have 
# not -- developers do 'make install' not from a 'make dist'-ified distro all
# the time.
#
# Note: this is done at 'make install' time.
# Note 2: the ifeq/else/endif have to be indented one space 
# because otherwise it seems that automake thinks it should
# be the one to handle the else/endif parts, not GNU make
# as we intend.
install-data-hook:
	set -e; \
	if test -r html ; then \
		mkdir -p $(DESTDIR)$(datadir)/doc/valgrind; \
		cp -r html $(DESTDIR)$(datadir)/doc/valgrind; \
	fi
	for f in *.1 ; do \
		if test -r $$f ; then \
			mkdir -p $(DESTDIR)$(mandir)/man1; \
			cp $$f $(DESTDIR)$(mandir)/man1; \
		fi \
	done
 ifeq ($(BUILD_ALL_DOCS),yes)
	set -e; \
	if test -r index.pdf ; then \
		mkdir -p $(DESTDIR)$(datadir)/doc/valgrind; \
		cp index.pdf $(DESTDIR)$(datadir)/doc/valgrind/valgrind_manual.pdf; \
	fi
	set -e; \
	if test -r index.ps ; then \
		mkdir -p $(DESTDIR)$(datadir)/doc/valgrind; \
		cp index.ps $(DESTDIR)$(datadir)/doc/valgrind/valgrind_manual.ps; \
	fi
 endif

# This is done at 'make dist' time.  It builds the html docs, print
# docs and man pages and copies them into the docs/ directory in the
# tarball.
 ifeq ($(BUILD_ALL_DOCS),yes)
dist-hook: FAQ.txt html-docs man-pages print-docs
	cp -r html $(distdir)
	cp FAQ.txt $(distdir)/..
	cp *.1 $(distdir)
	cp print/index.pdf $(distdir)
	cp print/index.ps $(distdir)
 else
dist-hook: FAQ.txt html-docs man-pages
	cp -r html $(distdir)
	cp FAQ.txt $(distdir)/..
	cp *.1 $(distdir)
 endif

distclean-local:
	rm -rf html print
	rm -f FAQ.txt
	rm -f $(top_builddir)/FAQ.txt $(top_builddir)/docs/*.1

# -----------------------------------------------------------------------
# Note: the rest of this file is nothing to do with the normal build
# tree.  The stuff below contains special targets for web-site
# artefacts.

# chunked html with no html/body tags, css, or top nav, to fit into the website
website-docs:
	@echo "Generating website html files ..."
	export XML_CATALOG_FILES=$(XML_CATALOG_FILES)
	/bin/rm -fr $(websitedir)
	mkdir -p $(websitedir)
	$(XSLTPROC) $(XSLTPROC_FLAGS) -o $(websitedir)/ $(XSL_WEBSITE_STYLE) $(myxmldir)/index.xml

# valkyrie carries around her own copy of the valgrind manual
valkyrie-docs:
	@echo "Generating a set of valgrind docs for valkyrie..."
	export XML_CATALOG_FILES=$(XML_CATALOG_FILES)
	/bin/rm -fr $(valkyriedir)
	mkdir -p $(valkyriedir)
	mkdir -p $(valkyriedir)/images
	cp $(mylibdir)/vg_basic.css $(valkyriedir)/
	cp $(myimgdir)/*.png $(valkyriedir)/images/
	$(XSLTPROC) $(XSLTPROC_FLAGS) -o $(valkyriedir)/ $(XSL_HTML_CHUNK_STYLE) $(myxmldir)/index.xml

# html.tar.bz2, .pdf, .ps.bz2 files for downloading from the website
download-docs:
	export XML_CATALOG_FILES=$(XML_CATALOG_FILES)
	/bin/rm -fr $(downloadsdir)
	mkdir -p $(downloadsdir)
	@echo ""
	@echo "Generating valgrind_manual.html.tar.bz2 ..."
	export XML_CATALOG_FILES=$(XML_CATALOG_FILES)
	/bin/rm -fr $(vgdir)
	mkdir -p $(vgdir)
	mkdir -p $(vgdir)/html
	mkdir -p $(vgdir)/html/images
	cp $(mylibdir)/vg_basic.css $(vgdir)/html/
	cp $(myimgdir)/*.png $(vgdir)/html/images/
	$(XSLTPROC) $(XSLTPROC_FLAGS) -o $(vgdir)/html/ $(XSL_HTML_CHUNK_STYLE) $(myxmldir)/index.xml
	(cd $(top_builddir)/docs/ && \
		(tar cfj $(downloadsdir)/valgrind_manual.html.tar.bz2 ./valgrind/html/ ) )
	/bin/rm -fr $(vgdir)/html/
	@echo ""
	@echo "Generating valgrind_manual.pdf ..."
	mkdir -p $(vgdir)/print
	mkdir -p $(vgdir)/print/images
	$(XSLTPROC) $(XSLTPROC_FLAGS) -o $(vgdir)/print/manual.fo $(XSL_FO_STYLE) $(myxmldir)/index.xml
	(cd $(vgdir)/print/ && \
		( pdfxmltex manual.fo && \
		  pdfxmltex manual.fo && \
		  pdfxmltex manual.fo ) &> $(LOGFILE) < /dev/null )
	@echo ""
	@echo "Generating valgrind_manual.ps.bz2 ..."
	(cd $(vgdir)/print/ && \
		( pdftops manual.pdf ) )
	mv $(vgdir)/print/manual.pdf $(downloadsdir)/valgrind_manual.pdf
	mv $(vgdir)/print/manual.ps $(downloadsdir)/valgrind_manual.ps
	bzip2 $(downloadsdir)/valgrind_manual.ps
	/bin/rm -fr $(vgdir)

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
