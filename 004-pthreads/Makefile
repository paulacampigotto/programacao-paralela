# GNU Makefile

CC = gcc
CCFLAGS = -Wall
LDFLAGS = -pthread #-pg
TARGET = pthreads

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

%: %.o
	$(CC) $(LDFLAGS) $^ -o $@

all: $(TARGET)

# Dependencias

pthreads: pthreads.c

clean:
	rm -f *.o *~ $(TARGET)
