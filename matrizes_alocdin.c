#include <stdio.h>
#include <stdlib.h>

/*Utilizando a forma que achar mais conveniente, crie um programa que receba
 as dimens˜oes das matrizes e os seus elementos sequencialmente, e faça a
multiplicação da matriz por sua transpost, imprimindo na tela o resultado da
operação*/

int **cria_matriz(int m, int n);
int **multiplicacao_matrizes(int **A, int **B, int ma, int na, int mb, int nb);
void print_matriz(int **M, int m, int n);

int main(){

    //Leitura:
    int m, n;
    scanf("%d", &m); //m: nº de linhas
    scanf("%d", &n); //n: nº de colunas

    int **A, **B;
    A = cria_matriz(m, n);
    B = cria_matriz(n, m); //transposta

    // Preenche a matriz:
    int a;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a);
            A[i][j] = a;
            B[j][i] = a;
        }
    }

    // Multiplicação de matrizes:
    int **C;
    C = multiplicacao_matrizes(A, B, m, n, n, m);

    //Print:
    printf("%d %d ", m, m);
    print_matriz(C, m, m);
    printf("\n");

    return 0;
}

int **cria_matriz(int m, int n) { //matriz: m x n (linhas x colunas)
    int **matriz;

    // Cria a matriz (aloca na memoria):
    matriz = (int **) malloc(m*sizeof(int *));

    // Se deu problema na alocacao, termina a funcao:
    if (matriz == NULL) {
    printf("Erro na alocacao de memoria\n");
    return(matriz);
    }

    for(int i = 0; i < m; i++){
        matriz[i] = (int *) malloc(n*sizeof(int));

        // Se deu problema na alocacao, termina a funcao:
        if (matriz[i] == NULL) {
            printf("Erro na alocacao de memoria\n");
            return(matriz);
        }
    }

    // Preenche a matriz:  
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = 0;
        }
    }

    return(matriz);
}

int **multiplicacao_matrizes(int **A, int **B, int ma, int na, int mb, int nb){

    int **prod; //A x B
    prod = cria_matriz(ma, nb);

    //Calculando cada elemento c_ij da matriz produto:
    for (int i = 0; i < ma; i++){
        for (int j = 0; j < nb; j++){
            
            //c_ij = i linha de A x j coluna de B 
            //c11 = a11·b11 + a12·b21 + a13·b31

            for (int k = 0; k < mb; k++){
                prod[i][j] += A[i][k] * B[k][j];
            }
        }  
    }
    
    return(prod);
}

void print_matriz(int **M, int m, int n){

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", M[i][j]);
        }
        //printf("\n");
    }
}
