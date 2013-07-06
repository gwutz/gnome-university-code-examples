PKG_CONFIG = `pkg-config --libs --cflags gtk+-3.0`
LIBS = gu_button.c gu_button.h gu_note.c gu_note.h gu_window.c gu_window.h 
LIB_OBJ = gu_button.o gu_note.o gu_window.o
MAIN = main.c
CC = gcc
MAIN_FLAGS = -o
OBJ_FLAGS = -c

all:
	$(CC) $(LIBS) $(OBJ_FLAGS) $(PKG_CONFIG)
	$(CC) $(MAIN) $(LIB_OBJ) $(MAIN_FLAGS) gunotebook $(PKG_CONFIG) 
clean:
	rm -rf gunotebook
	rm -rf $(LIB_OBJ)
	rm -rf *.*.gch
