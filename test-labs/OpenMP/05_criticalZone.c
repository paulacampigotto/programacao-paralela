#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
  int i, tid, n = 100;
  double a[100], b[100], sum, private_sum; 
  

  for (i=0; i < n; i++) 
   a[i] = b[i] = 1;
  sum = private_sum = 0.0;

  #pragma omp parallel private (tid)
  {
   tid = omp_get_thread_num();

   #pragma omp parallel for private (private_sum, i) 
    for (i=0; i <= n; i++) {
      private_sum = private_sum + (a[i] * b[i]);
      if (i==n) {
         #pragma critical 
            sum = sum + private_sum;
         printf ("   Private Sum(%d)(%lf) = %lf\n", tid, sum, private_sum);
      } // end if
    } // end for parallel
  } // end parallel
  printf ("   Private Sum = %f\n", sum);
}

