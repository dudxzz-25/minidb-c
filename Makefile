CC=gcc
CFLAGS=-std=c17 -Wall -Wextra -Wpedantic -O2
all: minidb
minidb: src/main.c
	$(CC) $(CFLAGS) src/main.c -o minidb
clean:
	rm -f minidb data/records.dat
