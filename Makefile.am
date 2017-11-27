SUBDIRS         =
EXTRA_DIST      = AUTHORS UNLICENSE VERSION
ACLOCAL_AMFLAGS = -I .aclocal

README.html: README.rst
	$(PANDOC) -o $@ -t html5 -s $<

CLEANFILES = README.html

SUBDIRS += dummy-camera
SUBDIRS += dummy-control
SUBDIRS += dummy-gps
SUBDIRS += dummy-mic
SUBDIRS += dummy-tag
