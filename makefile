# Compiler
CC = gcc

# Compiler flags
CFLAGS = -W -Wall -Wextra -pedantic -lm -g -lSDL2 -lGL -lSDL2_image

# Source files
SRCS = main.c window.c event_handler.c render.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable
TARGET = myprogram

# Default target
all: $(TARGET)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Debug option for compiler errors
debug:
	$(CC) $(CFLAGS) -DDEBUG $(SRCS) -o $(TARGET)
	

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)
	clear
