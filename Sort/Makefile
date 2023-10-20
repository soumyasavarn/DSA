CC = g++
CFLAGS = -Wall

SOURCES = sort.c time.c
OBJECTS = $(SOURCES:.c=.o)

all: my_program

my_program: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS) my_program
