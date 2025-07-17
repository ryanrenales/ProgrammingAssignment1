EXEC = bots
FILES = main.c chatbots.c
CC = gcc
CFLAGS = -Wall -pthread -g
OBJECTS = $(FILES:.c=.o)

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJECTS)
	rm -f *.o

.c.o:
	$(CC) $(CFLAGS) -c $<

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f *.o core a.out QUOTE.txt $(EXEC)
