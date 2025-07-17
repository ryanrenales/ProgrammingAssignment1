#exectuable name
Target = chatbots

#Compiler and flags
CC = gcc
CFLAGS = -Wall -pthread

# Source and object files
SRC = main.c
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJ)