CC := gcc
CFLAGS := -Wall -Wextra -O2

SRCS := $(wildcard src/*.c)
TARGET := build/brainfuck

all: $(TARGET)

$(TARGET): $(SRCS)
	@mkdir -p build
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf build

.PHONY: all clean
