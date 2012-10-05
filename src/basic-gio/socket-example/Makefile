CC=gcc
CFLAGS=-c -Wall `pkg-config --cflags gobject-2.0 gio-2.0` -g
LDFLAGS= `pkg-config --libs gobject-2.0 gio-2.0`
SOURCES_CLIENT=hsr-proxy.c hsr-icalc.c hsr-client.c
SOURCES_SERVER=hsr-server.c hsr-adapter.c hsr-calc-impl.c hsr-icalc.c
OBJECTS_CLIENT=$(SOURCES_CLIENT:.c=.o)
OBJECTS_SERVER=$(SOURCES_SERVER:.c=.o)
EXECUTABLE_CLIENT=client
EXECUTABLE_SERVER=server

all: $(SOURCES_CLIENT) $(SOURCES_SERVER) $(EXECUTABLE_CLIENT) $(EXECUTABLE_SERVER)
	
$(EXECUTABLE_CLIENT): $(OBJECTS_CLIENT) 
	$(CC) $(LDFLAGS) $(OBJECTS_CLIENT) -o $@

$(EXECUTABLE_SERVER): $(OBJECTS_SERVER) 
	$(CC) $(LDFLAGS) $(OBJECTS_SERVER) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
