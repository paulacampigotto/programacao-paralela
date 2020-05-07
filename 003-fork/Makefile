# GNU Makefile

CC = gcc
CCFLAGS = -Wall
LDFLAGS =
TARGET = process

all: $(TARGET)

process: process.c processP0.h processP1.h
	$(CC) $(CCFLAGS) process.c processP0.c processP1.c -o $@ $(LDFLAGS)

clean:
	rm -f *.o *~ $(TARGET)
