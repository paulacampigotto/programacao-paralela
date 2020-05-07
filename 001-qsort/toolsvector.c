#include <time.h>
#include <sys/time.h>
#include "toolsvector.h"

// %%%%%%%%%%%%%%% FERRAMENTAS p/ VETORES %%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
double wtime() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return t.tv_sec + (double) t.tv_usec / 1000000;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int fileout_vetor (int *vetor, int linha, FILE *infile){
  fprintf(infile,"#Linha#\n");
  fprintf(infile,"%d#\n", linha);
  for (int i=0; i < linha; i++) {
    fprintf(infile,"%d\n", vetor[i]);
  }
  return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int filein_vetor (int *vetor, int linha, FILE *file){
  char getLine [9];
  int i=0;

  while (fgets(getLine, 9, file) != NULL) {
    vetor[i++] = atoi(getLine);
    //printf("%d/%s", vetor[i-1],getLine);
  }

  return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int extrai_nroLine (FILE *const fin) {
  int nlinhas = 0, c, count=0;
  char *getLine = NULL;

  // Considero que o tamanho max de elementos do vetor sao 999.999.999
  getLine = (char *) malloc (9*sizeof(char));
  
  fseek( fin, 8, SEEK_SET );
  for( ;; ) {
    c = fgetc( fin );
    //printf ("%d(%c)\n",count, c);
    getLine[count] = c;
    if ( c == '\n' ) {
      getLine[count] = '\x0';
      break;
    }
    count++;
  }
  nlinhas = atoi(getLine);
  return nlinhas;
}
