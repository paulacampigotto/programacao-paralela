#include "processP0.h"

// Implementação do comportamento descrito no gráfico para Processo P0
int processP0(int pid) {
  printf("[P0] (%d) process run!\n", getpid());
  sleep (2);
  printf("#####\t\t[P0] (%d) process finish!!\t\t#####\n", pid);
  return 0;
}
