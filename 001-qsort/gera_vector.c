#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "toolsvector.h"
#include "vector.h"


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int main(int argc, char **argv) {
	int *vet0 = NULL;
	int *vet1 = NULL;
	FILE *fvet;
	int nlinhas, nolinhas, valor_vetor;
	char filename [100];

	if (argc != 3){
		printf ("ERRO: Numero de parametros %s <nr_linhas> <valor_vetor>\n", argv[0]);
		printf("valor_vetor (aleatório entre 0-9) = <-9999>\n");
		printf("valor_vetor (ordem crescente) = <-8888>\n");
		printf("valor_vetor (ordem descrecente) = <-7777>\n");
		printf("valor_vetor (todos em zero) = <0>\n");
		exit (1);
	}

	nlinhas =  atoi(argv[1]);
	valor_vetor =  atoi(argv[2]);
	sprintf (filename, "vector-%d.map", nlinhas);

	fvet = fopen(filename,"w");
  if (fvet == NULL) {
		printf("Error: Na abertura dos arquivos.");
		exit(1);
  }

	vet0 = alocar_vetor(nlinhas);
	// gerar_vetor(vet0, nlinhas, -9999); // aleatório
	// gerar_vetor(vet0, nlinhas, -8888); // ordem crescente
	// gerar_vetor(vet0, nlinhas, -7777); // ordem descrecente
	gerar_vetor(vet0, nlinhas, valor_vetor); // ordem descrecente
	if (vet0 == NULL) {
		printf("ERROR: Out of memory\n");
	}

	printf("\t\t**** PRINT vetor gerado N(%d) **** \n", nlinhas);
	imprimir_vetor(vet0, nlinhas);
	fileout_vetor(vet0, nlinhas, fvet);
	fclose(fvet);

	fvet = fopen(filename,"r");
	if (fvet == NULL) {
		printf("Error: Na abertura dos arquivos.");
		exit(1);
	}

	nolinhas = extrai_nroLine(fvet);
	//printf("Nro_Linhas = %d\n", nolinhas);

	vet1 = alocar_vetor(nolinhas);
	filein_vetor(vet1, nolinhas	, fvet);
	printf("\t\t**** PRINT vetor lido N(%d) **** \n", nlinhas);
	imprimir_vetor(vet1, nolinhas);
  comparar_vetores (vet0,vet1,nolinhas);

	liberar_vetor(vet0);
	liberar_vetor(vet1);
  fclose(fvet);

	printf("##### Arquivo vector-%d.map: VERIFICADO! #####\n", nolinhas);
  return 0;
}
