CC = gcc
CC_FLAGS = -Wall -pedantic -std=c11
 
EXEC = renderer
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
 
# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC) -lm
 
# To obtain object files
%.o: %.c
	$(CC) -c $(CC_FLAGS) $< -o $@
 
# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
