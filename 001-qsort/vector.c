#include "vector.h"
#include <time.h>

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% VETOR %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int gerar_vetor(int *vetor, int linha, int valor){

	srand( (unsigned)time(NULL) );

	for (int i=0; i < linha; i++) {

		if (valor == -9999) {
		   vetor[i] = rand() % 10;
		}

		if (valor == -8888) {
		   vetor[i] = i;
		}

		if (valor == -7777) {
		   vetor[i] = linha - i;
		}

		if (valor == 0) {
		   vetor[i] = valor;
		}

	}
	return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int zerar_vetor (int *vetor, int linha){
	return gerar_vetor(vetor,linha,0);
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int imprimir_vetor (int *vetor, int linha){
	printf("###############################");
	for (int i=0; i < linha; i++) {
		if (!(i % 10))
			printf("\n(%d)",i);
		printf("\t%d", vetor[i]);
	}
	printf("\n");
	return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int comparar_vetores (int *vetorA, int *vetorB, int linha){
	for (int i=0; i < linha; i++) {
		if (vetorA[i] != vetorB[i]) {
			printf("O elemento [%d] (%d/%d) é diferente nas matrizes analisadas!\n", i, vetorA[i], vetorB[i]);
			return 1;
		}
	}
	printf("VERIFICADO: Vetores idênticos!\n");
	return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int *liberar_vetor (int *vetor) {
	free(vetor);
	return NULL;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int *alocar_vetor (int linha) {
	int *nova_a = NULL;

	nova_a = (int *) malloc(linha*sizeof(int));
	if (!nova_a) {
		printf("ERROR: Out of memory\n");
		return NULL;
	}

	return nova_a;
}
