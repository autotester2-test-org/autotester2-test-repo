CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET_DIR = target
BINARY = $(TARGET_DIR)/file_printer
SOURCE = src/main.c

.PHONY: all clean

all: $(BINARY)

$(BINARY): $(SOURCE)
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) $(SOURCE) -o $(BINARY)

clean:
	rm -f $(BINARY)
