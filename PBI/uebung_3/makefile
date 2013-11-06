CC=cc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=quersumme.c
EXECUTABLE=quersumme.x
OBJECTS=$(SOURCES:.c=.o)

all: clear $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
	
clear:	
	rm -f ${EXECUTABLE}	