#Team Members: Kevin Townsend, Ryan Renales
#Class Accounts: cssc1461 (Kevin), cssc1453 (Ryan) 
#Class Info: CS 480, Summer 2025 
#Assignment Info: Programming Assignment #1, Chatbots 
#Filename: Makefile

EXEC = bots
FILES = main.c chatbots.c
CC = gcc
LFLAGS = -g
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
