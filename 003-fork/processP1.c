#include "processP1.h"

// Implementação do comportamento descrito no gráfico para Processo P1
int processP1(int pid) {
  printf("[P1] (%d) process run!\n", getpid());
  sleep(1);
  printf("#####\t\t[P1] (%d) process finish!!\t\t#####\n", pid);
  return 0;
}
