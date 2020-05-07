#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

typedef struct {
      int tid;
      int ntasks;
} param_t;

double wtime()
{
   struct timeval t;
   gettimeofday(&t, NULL);
   return t.tv_sec + (double) t.tv_usec / 1000000;
}

void *exec_thread (void *arg) {
  param_t *p = (param_t *) arg;

  sleep(p->ntasks - p->tid);
  printf ("(exec_thread) %d\n", p->tid);
  return NULL;
}

int main(int argc, char **argv)
{
   int n;
   int rc;
   int taskid, ntasks;
   double start_time, end_time;
   param_t *args;
   pthread_t *threads;

   if ((argc != 2)) {
      printf("Uso: %s <nro processos>\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   ntasks = atoi(argv[1]);

   threads = (pthread_t *) malloc(ntasks * sizeof(pthread_t));
   args = (param_t *) malloc(ntasks * sizeof(param_t));

   start_time = wtime();
   for (int i = 0; i < ntasks; i++)
   {
      args[i].tid = i;
      args[i].ntasks = ntasks;
      pthread_create(&threads[i], NULL, exec_thread, (void *) (args+i));
   }

   for (int i = 0; i < ntasks; i++)
   {
      pthread_join(threads[i], NULL);
   }
   end_time = wtime();

   printf("%d %f\n", ntasks, end_time - start_time);
   fflush(stdout);
   return EXIT_SUCCESS;
}
