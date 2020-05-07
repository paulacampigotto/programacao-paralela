#include <stdio.h>
#include <stdlib.h>

// Bibliotecas pessoais
#include "vector.h"
#include "toolsvector.h"
#include "sort.h"

int main(int argc, char** argv) {
  int nlinhas;
  int *vet = NULL;
  FILE *fvet;
  double start_time, end_time;

  if (argc != 2){
    printf ("ERRO: Numero de parametros %s <filename>", argv[0]);
    exit (1);
  }

  //nlinhas =  atoi(argv[1]);
  fvet = fopen(argv[1],"r");
  if (fvet == NULL) {
    printf("Error: Na abertura dos arquivos.");
    exit(1);
  }

  nlinhas = extrai_nroLine(fvet);
  vet = alocar_vetor(nlinhas);
  filein_vetor (vet, nlinhas, fvet);
  printf("\t\t**** PRINT vetor lido N(%d) **** \n", nlinhas);
  imprimir_vetor(vet, nlinhas);

  start_time = wtime();
  quick_sort(vet, 0, nlinhas - 1);
  end_time = wtime();

  printf("\t\t**** PRINT vetor Ordenado N(%d) **** \n", nlinhas);
  imprimir_vetor(vet, nlinhas);

  printf("\tRuntime: %f\n", end_time - start_time);

  liberar_vetor (vet);
  fclose (fvet);
  return 0;
}
