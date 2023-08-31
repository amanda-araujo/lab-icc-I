// Programa que aloca dinamicamente uma matriz
// bidimensional 6 x 5, preenche a matriz (6 linhas x 5 colunas)
// com alguns valores e depois os imprime.

#include <stdio.h>
#include <stdlib.h>

int main() {
  int **M;
  int i,j;

  // Aloca a matriz.
  
  M = (int **) malloc(6*sizeof(int *));
  if (M == NULL) {
    printf("Erro na alocacao de memoria\n");
    return(-1);
  }

  for (i = 0; i < 6; i++) {
    M[i] = (int *) malloc(5*sizeof(int));
    if (M[i] == NULL) {
      printf("Erro na alocacao de memoria\n");
      return(-1);
    }
  }

  // Preenche a matriz.
  
  for (i = 0; i < 6; i++) {
    for (j = 0; j < 5; j++) {
      M[i][j] = i*10+j;
    }
  }

  // Imprime a matriz.
  
  for (i = 0; i < 6; i++) {
    for (j = 0; j < 5; j++) {
      printf("%2d ", M[i][j]);
    }
    printf("\n");
  }

  // Desaloca a matriz
  for (i = 0; i < 6; i++) {
    free(M[i]);
    M[i] = NULL;
  }
  free(M);
  M = NULL;
  
  return(0);
}