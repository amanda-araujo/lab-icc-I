#include <stdio.h>
#include <stdlib.h>

float **cria_matriz(int m, int n); 
int **cria_matriz_int(int m, int n);

int main(){

    // Relações:
    int m;
    scanf("%d", &m);

    float **relacoes;
    relacoes = cria_matriz(m, m);

    // Preencher matriz relações:
    float a;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            scanf("%f", &a);
            relacoes[i][j] = a;
        }
    }

    /*for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.2f ", relacoes[i][j]);
        }
        printf("\n");
    }*/

    // Ataque: vários ataques possíveis
    /*duas informações: a primeira é seu poder de ataque (inteiro), 
    e a segunda seu tipo (índice do tipo na tabela)*/

    int **ataques, **copia; //matriz m x 2
    int m_ataques = 0, at1_poder = 0, at2_tipo;
    ataques = cria_matriz_int(m_ataques, 2);

    while (at1_poder != -1)
    {
        scanf("%d", &at1_poder);
        if (at1_poder == -1){
            break;
        }
        else{
            scanf("%d", &at2_tipo);
            
            copia = cria_matriz_int(m_ataques, 2);
            for (int i = 0; i < m_ataques; i++){
                for (int j = 0; j < 2; j++){
                    copia[i][j] = ataques[i][j];
                }
            }
            
            m_ataques++;

            ataques = cria_matriz_int(m_ataques, 2);
            
            //Passar valores antigos:
            for (int i = 0; i < m_ataques - 1; i++){
                for (int j = 0; j < 2; j++){
                    ataques[i][j] = copia[i][j];
                }
            }
            
            //Novos valores:
            ataques[m_ataques-1][0] = at1_poder;
            ataques[m_ataques-1][1] = at2_tipo;
        }
    }

    /*for (int i = 0; i < m_ataques; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", ataques[i][j]);
        }
        printf("\n");
    }*/
    
    // Tipo do inimigo:
    int inimigo; 
    scanf("%d", &inimigo);

    // Dano: checar o dano de cada possível ataque, pegar o maior
    /*tipo do ataque diz qual LINHA olhar em relacoes: ataques[i][1]; //Tipo
      inimigo diz qual COLUNA olhar em relações
      dano = poder (ataques[i][0]; //Poder) * relação (ataque-inimigo)*/
      
    int indice;
    float dano = 0.0, d;

    //matriz ataques:
    for (int i = 0; i < m_ataques; i++){
        
        d = relacoes[(ataques[i][1])][inimigo] * ataques[i][0];
        if (d > dano){
            dano = d;
            indice = i;
        }
    }
    
    //Print:
    printf("O melhor ataque possui indice %d e dano %.2f\n", indice, dano);        

    return 0;
}

float **cria_matriz(int m, int n) { //matriz: m x n (linhas x colunas)
    float **matriz;

    // Cria a matriz (aloca na memoria):
    matriz = (float **) malloc(m*sizeof(float *));

    // Se deu problema na alocacao, termina a funcao:
    if (matriz == NULL) {
    printf("Erro na alocacao de memoria\n");
    return(matriz);
    }

    for(int i = 0; i < m; i++){
        matriz[i] = (float *) malloc(n*sizeof(float));

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

int **cria_matriz_int(int m, int n) { //matriz: m x n (linhas x colunas)
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
    /*for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = 0;
        }
    }*/

    return(matriz);
}

