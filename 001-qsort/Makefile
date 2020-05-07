# GNU Makefile

CC = gcc
CCFLAGS = -Wall -O3
LDFLAGS =
TARGET = sort gera_vector help

all: $(TARGET)

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

%: %.o
	$(CC) $(LDFLAGS) $^ -o $@

sort: main_sort.c toolsvector.o vector.o sort.o
	$(CC) $(CCFLAGS) toolsvector.o vector.o sort.o main_sort.c -o $@ $(LDFLAGS)

gera_vector: gera_vector.c toolsvector.o vector.o
		$(CC) $(CCFLAGS) vector.o toolsvector.o gera_vector.c -o $@ $(LDFLAGS)

help:
	./gera_vector 10 -9999
	@echo
	@echo
	@echo "####### Exemplo de Execução #######"
	@echo "./sort vector.example"

clean:
	rm -f *.o *~ $(TARGET) *.map *.map-result
