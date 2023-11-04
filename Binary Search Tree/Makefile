CC = g++
CFLAGS = -Wall

SOURCES = bst.cpp time.cpp parser.cpp
OBJECTS = $(SOURCES:.c=.o)

all: my_program

my_program: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS) my_program
