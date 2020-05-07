	#include "matriz-operacoesv3.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% MATRIZ %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
mymatriz *msomar (mymatriz *mat_a, mymatriz *mat_b, int tipo) {
	mymatriz *mat_c = NULL;

	if ((mat_a->lin != mat_b-> lin) || (mat_a->col != mat_b->col)){
		printf ("Erro: Matrizes incompatíveis!\n");
		exit(1);
	}

	mat_c = (mymatriz *) malloc (sizeof(mymatriz));
	mat_c->lin = mat_a->lin;
	mat_c->col = mat_a->col;

	if (malocar(mat_c)) {	printf ("ERROR: Out of memory\n"); }

	if (tipo == 1) {
		for (int i=0; i < mat_c->lin; i++)
		  for (int j=0; j < mat_c->col; j++)
					mat_c->matriz[i][j] = mat_a->matriz[i][j]+mat_b->matriz[i][j];
	} else {
		for (int j=0; j < mat_c->col; j++)
			for (int i=0; i < mat_c->lin; i++)
					mat_c->matriz[i][j] = mat_a->matriz[i][j]+mat_b->matriz[i][j];
	}
  return mat_c;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
mymatriz *mmultiplicar (mymatriz *mat_a, mymatriz *mat_b, int tipo) {
	//mymatriz *mat_c = NULL;

	return msomar(mat_a, mat_b, tipo);

	//printf("c(%d,%d) = a(%d,%d)*b(%d,%d)\n", N, M, N, L, L, M);
	//imprimir_matriz(mat_a, M, N);
	//imprimir_matriz(mat_b, L, M);
	//imprimir_matriz(mat_c, N, N);
	// for (int i=0; i < N; i++)
	// for (int j=0; j < M; j++) {
	// 	//printf("c(%d,%d) = ", i, j);
	// 		for (int k=0; k < L; k++) {
	// 			//printf("%d", k);
	// 			//printf("%d * %d +", mat_a[i][k],mat_b[k][j]);
	// 			mat_c[i][j] += mat_a[i][k]*mat_b[k][j];
	// 		}
	// 		//printf(" = %d\n", mat_c[i][j]);
	// 	}
	//return mat_c;
}

// // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// int multiplicar_submatriz (matriz_bloco_t *mat_suba, matriz_bloco_t *mat_subb, matriz_bloco_t *mat_subc) {
// 	int col_mat_a, lin_mat_b;
//
//   // printf("\n\n\n$$$$$$ multiplicar submatriz $$$$$\n");
// 	// imprimir_submatriz (mat_suba);
// 	// imprimir_submatriz (mat_subb);
// 	// imprimir_submatriz (mat_subc);
//
// 	// printf("%d\n", mat_suba->matriz[mat_suba->bloco->lin_inicio][mat_suba->bloco->lin_fim]);
// 	// printf("mat_a(%d,%d/%d,%d)\n", mat_suba->bloco->lin_inicio, mat_suba->bloco->lin_fim,
// 	// mat_suba->bloco->col_inicio,mat_suba->bloco->col_fim);
// 	// printf("mat_b(%d,%d/%d,%d)\n", mat_subb->bloco->lin_inicio, mat_subb->bloco->lin_fim,
// 	// mat_subb->bloco->col_inicio,mat_subb->bloco->col_fim);
//
// 		col_mat_a = (mat_suba->bloco->col_fim - mat_suba->bloco->col_inicio)+1;
// 		lin_mat_b = (mat_subb->bloco->lin_fim - mat_subb->bloco->lin_inicio)+1;
// 		// printf("col_a/lin_b (%d,%d)\n", col_mat_a, lin_mat_b);
// 		//
// 		// imprimir_bloco (mat_suba);
// 		// imprimir_bloco (mat_subb);
// 		// imprimir_bloco (mat_subc);
//
// 		assert ( col_mat_a == lin_mat_b);
//
// 		for (int i = mat_subc->bloco->lin_inicio;	i <= mat_subc->bloco->lin_fim; i++) {
// 			for (int j = mat_subc->bloco->col_inicio; j <= mat_subc->bloco->col_fim; j++) {
// 				for (int k = 0; k <= (mat_suba->bloco->col_fim - mat_suba->bloco->col_inicio); k++) {
// 					//printf("mat_c[%d,%d] = mat_a[%d,%d] * mat_b[%d,%d]\n", i, j, i, (k+mat_suba->bloco->col_inicio), (k+mat_subb->bloco->lin_inicio), j);
// 					mat_subc->matriz[i][j] += mat_suba->matriz[i][(k+mat_suba->bloco->col_inicio)] * mat_subb->matriz[(k+mat_subb->bloco->lin_inicio)][j];
// 					//printf("mat_c[%d,%d] (%d,%d) = %d\n", i, j, mat_suba->matriz[i][k], mat_subb->matriz[k][j], mat_subc->matriz[i][j]);
// 				}
// 				//printf("\n");
// 			}
// 		}
//
//
// 	return 0;
// }
