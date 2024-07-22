
CFLAGS = -std=c99 -Wall -Werror -Wextra 
CC = gcc

all: build 

%.o : src/%.c
	$(CC) $< $(CFLAGS) -c

clean: 
	rm *.o 

.PHONY: clean 

