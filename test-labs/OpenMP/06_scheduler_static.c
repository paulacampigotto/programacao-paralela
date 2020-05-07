#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
  int i, n = 10, tid;

  #pragma omp parallel private(tid)
  {
   tid = omp_get_thread_num();
   printf("Hello World from thread = %d\n", tid);

   //#pragma omp for schedule (static,2) private (i)
   #pragma omp for schedule (static) private (i)
    for (i=0; i < n; i++) {
      int load = tid % 2;
      if (!load) {
         printf ("TID (%d) ->Inside bigWork function(%d)(i=%d)\n", tid, load, i);
         sleep(5);
         printf ("TID (%d) ->Out of bigWork function(%d)\n", tid, load);
      } else { 
         printf ("TID (%d) ->Inside smallWork function(%d)(i=%d)\n", tid, load, i);
         sleep(1);
         printf ("TID (%d) ->Out of smallWork function(%d)\n", tid, load);
      }
  }
 }
}
