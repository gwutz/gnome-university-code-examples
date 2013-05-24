PKG_CONFIG = `pkg-config --libs --cflags gtk+-3.0 gtksourceview-3.0`
LIBS = gucodeviewer.c gucodeviewer.h
LIB_OBJ = gucodeviewer.o
MAIN = main.c
CC = gcc
MAIN_FLAGS = -o
OBJ_FLAGS = -c

all:
	$(CC) $(LIBS) $(OBJ_FLAGS) $(PKG_CONFIG)
	$(CC) $(MAIN) $(LIB_OBJ) $(MAIN_FLAGS) gucodeviewer $(PKG_CONFIG) 
clean:
	rm -rf gucodeviewer
	rm -rf $(LIB_OBJ)
