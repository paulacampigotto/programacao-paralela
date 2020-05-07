#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SOME_HEADER_FILE_H
#define SOME_HEADER_FILE_H
#endif

int gerar_vetor(int *vetor, int linha, int valor);
int zerar_vetor (int *vetor, int linha);
int imprimir_vetor (int *vetor, int linha);
int comparar_vetores (int *vetorA, int *vetorB, int linha);
int *liberar_vetor (int *vetor);
int *alocar_vetor (int linha);
