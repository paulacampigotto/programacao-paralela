#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
  int tid = 999;
  float sum, private_sum; 
  
  sum = private_sum = 0.0;

  #pragma omp parallel private (tid, private_sum)
  {
   tid = omp_get_thread_num();

   private_sum = tid;
   sum = private_sum;
   printf ("   Private Sum(%d) = %f\n", tid, private_sum);
  }
   
  printf ("   Sum/Private_sum (%d) = %f %f\n", tid, sum, private_sum);
  tid = omp_get_thread_num();
  printf ("   Sum/Private_sum (%d) = %f %f\n", tid, sum, private_sum);
}

