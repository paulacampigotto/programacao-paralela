#include "matrizv3.h"
#include <time.h>

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% MATRIZ %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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

	printf("\n \
%%%%%%%%%%%% %%%%%%%%%%%% %%%%%%%%%%%% %%%%%%%%%%%% %%%%%%%%%%%% %%%%%%%%%%%% %%%%%%%%%%%% %%%%%%%%%%%%\n \
	WARNING: Impressão truncada em 15x15! \n \
	WARNING: Último elemento matriz[%d][%d] = %d \n \
%%%%%%%%%%%% %%%%%%%%%%%% %%%%%%%%%%%% %%%%%%%%%%%% %%%%%%%%%%%% %%%%%%%%%%%% %%%%%%%%%%%% %%%%%%%%%%%%\n", \
matriz->lin-1, matriz->col-1, matriz->matriz[matriz->lin-1][matriz->col-1]);
	return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int mliberar (mymatriz *matriz) {
	for (int i =0; i < matriz->lin; i++) {
		//printf("%p\n", matriz->matriz[i]);
		free(matriz->matriz[i]);
	}
	free(matriz->matriz);
	return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int mzerar (mymatriz *matriz){
	return mgerar(matriz,0);
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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


// // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// int gerar_submatriz (int **mat_origem, matriz_bloco_t *submatriz, bloco_t *bloco) {
//   bloco_t *newblock;
//
// 	submatriz->matriz = mat_origem;
//
// 	newblock = (bloco_t *) malloc (sizeof(bloco_t));
//   newblock->lin_inicio = bloco->lin_inicio;
//   newblock->lin_fim = bloco->lin_fim;
//   newblock->col_inicio = bloco->col_inicio;
//   newblock->col_fim = bloco->col_fim;
//   //printf ("Estrutura lin_inicio %d,%d\n", newblock.lin_inicio, bloco->lin_inicio);
//   submatriz->bloco = newblock;
//   //printf ("Estrutura submatriz_lin_inicio %d\n", submatriz->bloco->lin_inicio);
//   return 0;
// }
//
// // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// int imprimir_submatriz (matriz_bloco_t *submatriz){
// 	// printf ("Estrutura %d,%d,%d,%d\n", submatriz->bloco->lin_inicio,
// 	// submatriz->bloco->lin_fim,
// 	// submatriz->bloco->col_inicio,
// 	// submatriz->bloco->col_fim);
//
// 	for (int j = submatriz->bloco->col_inicio; j <= submatriz->bloco->col_fim; j++)
// 	printf("\t(%d)", j);
// 	printf("\n");
// 	for (int i= submatriz->bloco->lin_inicio; i <= submatriz->bloco->lin_fim; i++) {
// 		printf("(%d)", i);
// 		for (int j= submatriz->bloco->col_inicio; j <= submatriz->bloco->col_fim; j++){
// 			printf("\t%d", submatriz->matriz[i][j]);
// 		}
// 		printf("\n");
// 	}
// 	return 0;
// }
//
// // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// int imprimir_bloco (matriz_bloco_t *submatriz) {
//
//   printf("## Bloco (BEGIN) ##\n");
// 	printf("Submatriz[lin_ini,col_ini] = %d\n", submatriz->matriz[submatriz->bloco->lin_inicio][submatriz->bloco->col_inicio]);
// 	printf("Submatriz[lin_fim,col_fim] = %d\n", submatriz->matriz[submatriz->bloco->lin_fim][submatriz->bloco->col_fim]);
// 	printf("Matriz (%p) (l_i,c_i) = (%d,%d) (l_f,c_f) = (%d,%d) \n", submatriz->matriz, submatriz->bloco->lin_inicio, submatriz->bloco->col_inicio, submatriz->bloco->lin_fim, submatriz->bloco->col_fim);
// 	printf("mat_lin/mat_col/divisor = (%d,%d,%d) \n", submatriz->mat_lin, submatriz->mat_col, submatriz->divisor);
// 	printf("## Bloco (END) ##\n");
// 	return 0;
// }
//
// // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// // divisor corresponde ao nro de particoes
// // orientacao, 0 corte horizontal, 1 para corte vertical
// matriz_bloco_t **particionar_matriz (int **matriz, int mat_lin, int mat_col, int orientacao, int divisor) {
// 	matriz_bloco_t **vsubmatriz = NULL;
// 	int nro_submatrizes, base, corte;
// 	bloco_t *bloco_tmp;
//
// 	// if (mat_col != mat_lin) {
// 	// 	printf("<ERRO> Este procedimento funciona somente para matriz quadrada.\n");
// 	// 	return NULL;
// 	// }
//
// 	// if ((mat_col % divisor) != 0) {
// 	// 	printf("<ERRO> Este procedimento funciona somente com divisor perfeito (sem resto).\n");
// 	// 	return NULL;
// 	// }
//
//   // if (orientacao) {
// 	// 	if (mat_col >= divisor) {
// 	// 		printf("mat_col/divisor/orientacao(corte vertical)(%d,%d,%d)\n", mat_col, divisor, orientacao);
// 	// 	}
// 	// } else {
// 	// 	if (mat_lin >= divisor) {
// 	// 		printf("mat_lin/divisor/nro_submatrizes(corte horizontal) =(%d,%d,%d)\n", mat_lin, divisor,orientacao);
// 	// 		imprimir_matriz(matriz, mat_lin, mat_col);
// 	// 	}
// 	// }
//
// 	nro_submatrizes = 2;
// 	// TODO: por ora, fixo.
//   vsubmatriz = (matriz_bloco_t **) malloc (nro_submatrizes*sizeof (matriz_bloco_t *));
//
// 	if (!vsubmatriz) {
// 		printf("ERROR: Out of memory\n");
// 		return NULL;
// 	}
//
// 	base = 0;
// 	//printf("nro_submatrizes/corte = %d/%d/%d\n", nro_submatrizes, corte,mat_lin);
// 	for (int i = 0; i < nro_submatrizes; i++) {
// 		//printf("PAREI AQUI sub[%d] %d\n", i, matriz[0][0]);
// 		vsubmatriz[i] = (matriz_bloco_t *) malloc (sizeof(matriz_bloco_t));
// 		bloco_tmp = (bloco_t *) malloc (sizeof(bloco_t));
//
// 		if (!bloco_tmp) {
// 			printf("ERROR: Out of memory\n");
// 			return NULL;
// 		}
// 		if (orientacao) {
// 			corte = (mat_lin+2) / nro_submatrizes;
// 			bloco_tmp->lin_inicio = 0;
// 			bloco_tmp->lin_fim = (mat_lin-1);
// 			bloco_tmp->col_inicio = base;
// 			bloco_tmp->col_fim = mat_col-1;
// 			if (base == 0) {
// 					bloco_tmp->col_fim = base + (corte-1);
// 			}
//
// 			base =+ corte;
// 			//printf("(%p)bloco_conf(V) (mat_lin/mat_col) = (%d,%d) (l_i,c_i) = (%d,%d) (l_f,c_f) = (%d,%d) \n", matriz, mat_lin, mat_col, bloco_tmp->lin_inicio, bloco_tmp->col_inicio, bloco_tmp->lin_fim, bloco_tmp->col_fim);
// 		} else {
// 			corte = (mat_col+2) / nro_submatrizes;
// 			bloco_tmp->lin_inicio = base;
// 			bloco_tmp->col_inicio = 0;
// 			bloco_tmp->col_fim = (mat_col-1);
// 			bloco_tmp->lin_fim = (mat_lin -1);
// 			if (base == 0) {
// 				bloco_tmp->lin_fim = base + (corte -1);
// 			}
// 			base =+ corte;
// 			//printf("(%p)bloco_conf(H) (mat_lin/mat_col) = (%d,%d) (l_i,c_i) = (%d,%d) (l_f,c_f) = (%d,%d) \n", matriz, mat_lin, mat_col, bloco_tmp->lin_inicio, bloco_tmp->col_inicio, bloco_tmp->lin_fim, bloco_tmp->col_fim);
// 		}
//
// 		vsubmatriz[i]->matriz = matriz;
// 		vsubmatriz[i]->bloco = bloco_tmp;
// 		vsubmatriz[i]->mat_col = mat_col;
// 		vsubmatriz[i]->mat_lin = mat_lin;
// 		vsubmatriz[i]->divisor = nro_submatrizes;
// 		// printf("vmatriz(%d)[%d][%d] %d\n", i, vsubmatriz[i]->bloco->lin_inicio, vsubmatriz[i]->bloco->col_inicio,
// 		// vsubmatriz[i]->matriz[vsubmatriz[i]->bloco->lin_inicio][vsubmatriz[i]->bloco->col_inicio]);
// 		// printf("vmatriz(%d)[%d][%d] %d\n", i, vsubmatriz[i]->bloco->lin_fim, vsubmatriz[i]->bloco->col_fim,
// 		// vsubmatriz[i]->matriz[vsubmatriz[i]->bloco->lin_fim][vsubmatriz[i]->bloco->col_fim]);
// 		//imprimir_bloco (vsubmatriz[i]);
//
// 		//gerar_submatriz (matriz, &A11, bloco_tmp);
// 	}
// return vsubmatriz;
// }
//
// // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// matriz_bloco_t **constroi_submatriz (int **matriz, int mat_lin, int mat_col, int divisor) {
// 	matriz_bloco_t **vsubmatriz = NULL;
// 	bloco_t *bloco_tmp;
//
// 	vsubmatriz = (matriz_bloco_t **) malloc (sizeof (matriz_bloco_t *));
//
// 	if (!vsubmatriz) {
// 		printf("ERROR: Out of memory\n");
// 		return NULL;
// 	}
//
// 	vsubmatriz[0] = (matriz_bloco_t *) malloc (sizeof(matriz_bloco_t));
// 	bloco_tmp = (bloco_t *) malloc (sizeof(bloco_t));
//
// 	if (!bloco_tmp) {
// 		printf("ERROR: Out of memory\n");
// 		return NULL;
// 	}
// 	bloco_tmp->lin_inicio = 0;
// 	bloco_tmp->lin_fim = (mat_lin-1);
// 	bloco_tmp->col_inicio = 0;
// 	bloco_tmp->col_fim = (mat_col-1);
//
// 	vsubmatriz[0]->matriz = matriz;
// 	vsubmatriz[0]->bloco = bloco_tmp;
// 	vsubmatriz[0]->mat_col = mat_col;
// 	vsubmatriz[0]->mat_lin = mat_lin;
// 	vsubmatriz[0]->divisor = divisor;
// 	// int i =0;
// 	// printf("vmatriz(%d)[%d][%d] %d\n", i, vsubmatriz[i]->bloco->lin_inicio, vsubmatriz[i]->bloco->col_inicio,
// 	// vsubmatriz[i]->matriz[vsubmatriz[i]->bloco->lin_inicio][vsubmatriz[i]->bloco->col_inicio]);
// 	// printf("vmatriz(%d)[%d][%d] %d\n", i, vsubmatriz[i]->bloco->lin_fim, vsubmatriz[i]->bloco->col_fim,
// 	// vsubmatriz[i]->matriz[vsubmatriz[i]->bloco->lin_fim][vsubmatriz[i]->bloco->col_fim]);
// 	// imprimir_bloco (vsubmatriz[i]);
// 	return vsubmatriz;
// }
//
// // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// matriz_bloco_t **constroi_submatrizv2 (int mat_lin, int mat_col, int divisor) {
// 	matriz_bloco_t **vsubmatriz = NULL;
// 	int **matRet = NULL;
// 	bloco_t *bloco_tmp;
//
// 	vsubmatriz = (matriz_bloco_t **) malloc (divisor*sizeof (matriz_bloco_t *));
//
// 	if (!vsubmatriz) {
// 		printf("ERROR: Out of memory\n");
// 		return NULL;
// 	}
//
//   for (int i=0; i < divisor; i++) {
// 		matRet = alocar_matriz(mat_lin, mat_col);
// 		zerar_matriz(matRet, mat_lin, mat_col);
// 		vsubmatriz[i] = (matriz_bloco_t *) malloc (sizeof(matriz_bloco_t));
// 		bloco_tmp = (bloco_t *) malloc (sizeof(bloco_t));
//
// 		if (!bloco_tmp) {
// 			printf("ERROR: Out of memory\n");
// 			return NULL;
// 		}
// 		bloco_tmp->lin_inicio = 0;
// 		bloco_tmp->lin_fim = (mat_lin-1);
// 		bloco_tmp->col_inicio = 0;
// 		bloco_tmp->col_fim = (mat_col-1);
//
// 		vsubmatriz[i]->matriz = matRet;
// 		vsubmatriz[i]->bloco = bloco_tmp;
// 		vsubmatriz[i]->mat_col = mat_col;
// 		vsubmatriz[i]->mat_lin = mat_lin;
// 		vsubmatriz[i]->divisor = divisor;
// 	}
// 	// imprimir_bloco (vsubmatriz[0]);
// 	// imprimir_bloco (vsubmatriz[1]);
// 	// imprimir_submatriz (vsubmatriz[0]);
// 	// imprimir_submatriz (vsubmatriz[1]);
// 	return vsubmatriz;
// }
//
//
// // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// matriz_bloco_t **liberar_submatriz (matriz_bloco_t **submatriz) {
// 	int nro_submatrizes;
//
// 	nro_submatrizes = submatriz[0]->divisor;
// 	for (int i = 0; i < nro_submatrizes; i++) {
// 		free (submatriz[i]->bloco);
// 		free (submatriz[i]);
// 	}
//   free (submatriz);
//   return NULL;
// }
