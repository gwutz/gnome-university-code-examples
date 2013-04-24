PKG_CONFIG = `pkg-config --libs --cflags gtk+-3.0`
CC = gcc

SYNC_FILES = sync_window.h sync_window.c sync.c
VIEWER_FILES = textfileviewer.c  text_window.c text_window.h
BASIC_FILE = basic.c
CLIPBOARD_FILE = basic_clipboard.c

sync:
	$(CC) $(PKG_CONFIG) $(VIEWER_FILES) -o $@
	
textfileviewer:
	$(CC) $(PKG_CONFIG) $(VIEWER_FILES) -o $@
	
basic:
	$(CC) $(PKG_CONFIG) $(BASIC_FILE) -o $@

basic_clipboard:
	$(CC) $(PKG_CONFIG) $(CLIPBOARD_FILE) -o $@

all:
	$(CC) $(PKG_CONFIG) $(SYNC_FILES) -o sync
	$(CC) $(PKG_CONFIG) $(VIEWER_FILES) -o textfileviewer
	$(CC) $(PKG_CONFIG) $(BASIC_FILE) -o basic
	$(CC) $(PKG_CONFIG) $(CLIPBOARD_FILE) -o basic_clipboard
	
clean_sync:
	rm -f sync
	
clean_viewer:
	rm -f textfileviewer

clean_basic:
	rm -f basic
	
clean_cliboard:
	rm -f basic_clipboard
	
clean:
	rm -f sync
	rm -f textfileviewer
	rm -f basic
	rm -f basic_clipboard
