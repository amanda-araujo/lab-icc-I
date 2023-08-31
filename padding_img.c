//Padding de imagens: matrizes
#include <stdio.h>
#include <stdlib.h>

int **cria_matriz(int m, int n);
void print_matriz(int **M, int m, int n);
void desalocar_matriz(int **M, int m, int n);

int main(){

    //LEITURA:
    int larg, alt;
    scanf("%d", &larg); //n: colunas
    scanf("%d", &alt);  //m: linhas

    int **imagem;
    imagem = cria_matriz(alt, larg);

    // Preenche a matriz:
    int a;
    for (int i = 0; i < alt; i++) {
        for (int j = 0; j < larg; j++) {
            scanf("%d", &a);
            imagem[i][j] = a;
        }
    }

    int borda;
    scanf("%d", &borda);

    //PADDING (add de bordas):
    int **padding;
    padding =  cria_matriz(alt+2*borda, larg+2*borda);
    
    // Preenche a matriz: 
    for (int i = borda; i < alt + borda; i++) {
        for (int j = borda; j < larg + borda; j++) {
            padding[i][j] = imagem[i - borda][j - borda];
        }
    }

    //PRINT:
    print_matriz(padding, alt+2*borda, larg+2*borda);
    printf("\n");
    print_matriz(imagem, alt, larg);

    //Desalocar matrizes:
    desalocar_matriz(imagem, alt, larg);
    desalocar_matriz(padding, alt+2*borda, larg+2*borda);

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

void print_matriz(int **M, int m, int n){

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

void desalocar_matriz(int **M, int m, int n){

    for (int i = 0; i < m; i++) {
        free(M[i]);
        M[i] = NULL;
    }
    free(M);
    M = NULL;
}