## Process this file with automake to produce Makefile.in

## Created by Anjuta



AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(NOTEBOOK_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = notebook

notebook_SOURCES = \
	main.c \
	gu_note.c \
	gu_note.h \
	gu_button.c \
	gu_button.h \
	gu_window.c \
	gu_window.h

notebook_LDFLAGS = \
	-Wl,--export-dynamic

notebook_LDADD = $(NOTEBOOK_LIBS)


