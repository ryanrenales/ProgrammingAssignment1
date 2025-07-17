CC = gcc
CFLAGS = -Wall -pthread
TARGET = chatbots
OBJS = main.o chatbots.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c chatbots.h
	$(CC) $(CFLAGS) -c main.c

chatbots.o: chatbots.c chatbots.h
	$(CC) $(CFLAGS) -c chatbots.c

clean:
	rm -f $(TARGET) $(OBJS) QUOTE.txt

run: $(TARGET)
	./$(TARGET)
