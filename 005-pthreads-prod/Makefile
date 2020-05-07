# GNU Makefile

CC = gcc
CCFLAGS = -Wall
LDFLAGS = -pthread #-pg
TARGET = pthreads-prod

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

%: %.o
	$(CC) $(LDFLAGS) $^ -o $@

all: $(TARGET)

# Dependencias

pthreads-prod: pthreads-prod.c

clean:
	rm -f *.o *~ $(TARGET)
