#include "matrizv3.h"
#include <time.h>

int malocar (mymatriz *matriz) {
	int **newMatriz = NULL;

	newMatriz = (int **) malloc(matriz->lin*sizeof(int *));

	if (!newMatriz) {
		printf("ERROR: Out of memory\n");
		return 1;
	}

	for (int i =0; i < matriz->lin; i++) {
		newMatriz[i] = (int *) malloc(sizeof(int)*matriz->col);

		if (!newMatriz) {
			printf("ERROR: Out of memory\n");
			return 1;
		}
	}

	matriz->matriz = newMatriz;
	return 0;
}


int mgerar(mymatriz *matriz, int valor){
	srand( (unsigned)time(NULL) );

	for (int i=0; i < matriz->lin; i++)
	  for (int j=0; j < matriz->col; j++)
			if (valor == -9999)
				matriz->matriz[i][j] = rand() % 10;
			else
				matriz->matriz[i][j] = valor;

	return 0;
}

int mimprimir (mymatriz *matriz){
	int linha, coluna;
	linha = matriz->lin;
	coluna = matriz->col;

	if (linha > 15) {
		linha = 15;
	}

	if (coluna > 15) {
		coluna = 15;
	}

	for (int j =0; j < coluna; j++)
		printf("\t(%d)", j);
	printf("\n");
	for (int i=0; i < linha; i++) {
		printf("(%d)", i);
	  for (int j=0; j < coluna; j++){
			printf("\t%d", matriz->matriz[i][j]);
		}
		printf("\n");
	}

	return 0;
}

int mliberar (mymatriz *matriz) {
	for (int i =0; i < matriz->lin; i++) {
		//printf("%p\n", matriz->matriz[i]);
		free(matriz->matriz[i]);
	}
	free(matriz->matriz);
	return 0;
}

int mzerar (mymatriz *matriz){
	return mgerar(matriz,0);
}

int mcomparar (mymatriz *mat_a, mymatriz *mat_b){
	for (int j =0; j < mat_a->col; j++)
	for (int i=0; i < mat_a->lin; i++) {
		for (int j=0; j < mat_a->col; j++){
			if (mat_a->matriz[i][j] != mat_b->matriz[i][j]) {
				printf("O elemento [%d,%d] é diferente nas matrizes analisadas!", i,j);
				return 1;
			}
		}
	}
	printf("\tVERIFICADO: Matrizes identicas\n");
	return 0;
}
