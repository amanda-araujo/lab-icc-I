// Programa para testar alocacao dinamica de vetores.
// Cria alguns vetores, que sao iniciados com
// 0 em todas as posicoes.

#include <stdio.h>
#include <stdlib.h>

// Funcao que cria um vetor de tamanho n de double,
// preenche-o com 0s e devolve o vetor criado.

double *cria_vetor(int n) {
  double *vetor;
  int i;

  // Cria o vetor (aloca na memoria).
  
  vetor = (double *) malloc(n*sizeof(double));

  // Se deu problema na alocacao, termina a funcao.
  
  if (vetor == NULL) {
    printf("Erro na alocacao de memoria\n");
    return(vetor);
  }

  // Preenche os elementos do vetor com 0.
  
  for (i = 0; i < n; i++) {
    vetor[i] = 0;
  }

  return(vetor);
}

int main() {
  double *v5,*v20,*vk;
  int i,k;

  // Cria um vetor com 5 doubles (com 0 em todas as posicoes).
  
  v5 = cria_vetor(5);

  // Imprime o vetor v5.
  
  for (i = 0; i < 5; i++) {
    printf("%.1lf ", v5[i]);
  }
  printf("\n");

  // Desaloca memoria usada pelo v5. Nao da mais para usa-lo.

  free(v5);
  v5 = NULL;

  // Cria um vetor com 20 doubles (com 0 em todas as posicoes).

  v20 = cria_vetor(20);
  
  // Imprime o vetor v20.
  
  for (i = 0; i < 20; i++) {
    printf("%.1lf ", v20[i]);
  }
  printf("\n");

  // Desaloca memoria usada pelo v20. Nao da mais para usa-lo.

  free(v20);
  v20 = NULL;
  
  // Pede para o usuario digitar um tamanho k para o vetor.
  
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &k);

  // Cria um vetor com k doubles (com 0 em todas as posicoes).
  
  vk = cria_vetor(k);

  // Imprime o vetor vk.
  
  for (i = 0; i < k; i++) {
    printf("%.1lf ", vk[i]);
  }
  printf("\n");
  
  // Desaloca memoria usada pelo vk. Nao da mais para usa-lo.

  free(vk);
  vk = NULL;
  
  return(0);
}