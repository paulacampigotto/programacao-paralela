# GNU Makefile

CC = gcc 
CCFLAGS = -Wall
LDFLAGS = -fopenmp
TARGET = 11_nested 10_mm 10_omp_mm 10_omp_workshare 01_hello 02_forSum 03_forReductionSum 04_private 05_criticalZone 06_scheduler_dynamic 06_scheduler_static

%.o: %.c
	$(CC) $(CCFLAGS) -c $<
	echo "export OMP_NUM_THREADS=<nroThread>"

%: %.o
	$(CC) $(LDFLAGS) $^ -o $@ 

all: $(TARGET)
	sh run.sh
    

# Dependencias

01_hello: 01_hello.c
02_forSum: 02_forSum.c
03_forReductionSum: 03_forReductionSum.c
04_private: 04_private.c
05_criticalZone: 05_criticalZone.c
06_scheduler_dynamic: 06_scheduler_dynamic.c
06_scheduler_static: 06_scheduler_static.c
10_mm: 10_mm.c
10_omp_mm: 10_omp_mm.c
10_omp_workshare: 10_omp_workshare.c
11_nested: 11_nested.c

clean:
	rm -f *.o *~ $(TARGET)
