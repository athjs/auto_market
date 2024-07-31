CFLAGS = -std=c99 -Wall -Werror -Wextra -g
CC = gcc

all: build

build: test

# Compile the object files from the source directory
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile the object files from the test directory
tst/%.o: tst/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Linking the object files to create the test executable
test: src/market.o src/money.o src/math.o tst/test_market.o tst/test_money.o tst/alltest.o 
	$(CC) $(CFLAGS) -o test src/market.o src/money.o src/math.c tst/test_market.o tst/test_money.o tst/alltest.o

clean:
	rm -f src/*.o tst/*.o test

.PHONY: clean
