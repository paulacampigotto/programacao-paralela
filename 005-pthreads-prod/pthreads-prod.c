#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

int total=0;

typedef struct {
      int tid;
      int ntasks;
      int loop;
      char operator;
} param_t;

double wtime()
{
   struct timeval t;
   gettimeofday(&t, NULL);
   return t.tv_sec + (double) t.tv_usec / 1000000;
}

void *exec_thread (void *arg) {
  param_t *p = (param_t *) arg;

  //sleep(p->ntasks - p->tid);
  printf ("(exec_thread) (%c) thread_init(%d); loop/total = %d/%d\n", p->operator, p->tid, p->loop, total);
  for (int i=0; i<p->loop; i++){
    if (p->operator == '-') {
      total--;
    } else {
      total++;
    }
  }
  printf ("(exec_thread) (%c) thread_end(%d); loop/total = %d/%d\n", p->operator, p->tid, p->loop, total);
  return NULL;
}

int main(int argc, char **argv)
{
   int n;
   int rc;
   int taskid, ntasks, loop;
   double start_time, end_time;
   param_t *args;
   pthread_t *threads;

   if ((argc != 3)) {
      printf("Uso: %s <nro processos> <n do loop>\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   ntasks = atoi(argv[1]);
   loop = atoi(argv[2]);

   threads = (pthread_t *) malloc(ntasks * sizeof(pthread_t));
   args = (param_t *) malloc(ntasks * sizeof(param_t));

   start_time = wtime();
   for (int i = 0; i < ntasks; i++)
   {
      args[i].tid = i;
      args[i].ntasks = ntasks;
      args[i].loop = loop;
      args[i].operator = '-';
      if (i % 2) {
        args[i].operator = '+';
      }
      pthread_create(&threads[i], NULL, exec_thread, (void *) (args+i));
   }

   for (int i = 0; i < ntasks; i++)
   {
      pthread_join(threads[i], NULL);
   }
   end_time = wtime();

   printf("%d %f / total = %d\n", ntasks, end_time - start_time, total);
   fflush(stdout);
   return EXIT_SUCCESS;
}
