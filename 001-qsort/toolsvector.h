#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// externos a biblioteca tools
double wtime();

// Biblioteca p/ vetores
int fileout_vetor (int *vetor, int linha, FILE *infile);
int filein_vetor (int *vetor, int linha, FILE *file);
int extrai_nroLine (FILE *const fin);
