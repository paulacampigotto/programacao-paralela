#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "toolsv3.h"
#include "matrizv3.h"
#include "matriz-operacoesv3.h"

int main(int argc, char *argv[]) {

	//Declaração de Variáveis

	mymatriz mat_a, mat_b;
	mymatriz **mat_soma, **mat_mult;
	char filename[100];
	FILE *fmat;
	int nr_line;
	int *vet_line = NULL;
	int N, M, La, Lb;
	double start_time, end_time;

	if (argc != 3){
		printf ("ERRO: Numero de parametros %s <matriz_a> <matriz_b>\n", argv[0]);
		exit (1);
	}

	//Leitura da Matriz A (arquivo)
	fmat = fopen(argv[1],"r");
	if (fmat == NULL) {
		printf("Error: Na abertura dos arquivos.");
		exit(1);
	}
	extrai_parametros_matriz(fmat, &N, &La, &vet_line, &nr_line);
	mat_a.matriz = NULL;
	mat_a.lin = N;
	mat_a.col = La;
	if (malocar(&mat_a)) {
		printf ("ERROR: Out of memory\n");
	}
	filein_matriz (mat_a.matriz, N, La, fmat, vet_line, nr_line);
	free (vet_line);
	fclose(fmat);


	//Leitura da Matriz B (arquivo)
	fmat = fopen(argv[2],"r");
	if (fmat == NULL) {
		printf("Error: Na abertura dos arquivos.");
		exit(1);
	}
	extrai_parametros_matriz(fmat, &Lb, &M, &vet_line, &nr_line);
	mat_b.matriz = NULL;
	mat_b.lin = Lb;
	mat_b.col = M;
	if (malocar(&mat_b)) {
		printf ("ERROR: Out of memory\n");
	}
	filein_matriz (mat_b.matriz, Lb, M, fmat, vet_line, nr_line);
	free (vet_line);
	fclose(fmat);


	//Operação de Adição (matriz A + matriz A)
	printf("\n##### Soma de Matrizes #####\n");

	mat_soma = (mymatriz **) calloc (2,sizeof(mymatriz *));

	start_time = wtime();
	mat_soma[0] = msomar(&mat_a, &mat_a, 0);
	end_time = wtime();

	mimprimir(mat_soma[0]);
	printf("Runtime: %f\n", end_time - start_time);
	sprintf(filename, "soma.result");
	fmat = fopen(filename,"w");
	fileout_matriz(mat_soma[0], fmat);
	fclose(fmat);

	printf("\n");


	//Operação de Multiplicação  (matriz A * matriz B)
	printf("\n##### Multiplicação de Matrizes #####\n");

	mat_mult = (mymatriz **) malloc (sizeof(mymatriz *)*6);

	start_time = wtime();
	mat_mult[0] = mmultiplicar(&mat_a, &mat_b, 0);
	end_time = wtime();

	mimprimir(mat_mult[0]);
	printf("Runtime: %f\n", end_time - start_time);
	sprintf(filename, "mult.result");
	fmat = fopen(filename,"w");
	fileout_matriz(mat_mult[0], fmat);
	fclose(fmat);


	//Liberação de memória

	mliberar(mat_soma[0]);
	free (mat_soma[0]);

	mliberar(mat_mult[0]);
	free (mat_mult[0]);

	mliberar(&mat_a);
	mliberar(&mat_b);
	free(mat_soma);
	free(mat_mult);

	return 0;
}
