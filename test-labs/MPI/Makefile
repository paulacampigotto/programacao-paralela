# GNU Makefile

CC = mpicc
CCFLAGS = -Wall
#CCFLAGS =
LDFLAGS =
#LDFLAGS = -llmpe -lmpe
TARGET = ex1 ex2 ex3 ex4 ex5 ex6 ex7

#%.o: %.c
#	$(CC) $(CCFLAGS) -c $<
#
#%: %.o
#	$(CC) $^ -o $@

all: $(TARGET)
	sh run.sh

clean:
	rm -f *.o *~ $(TARGET)
