#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define COLOR_CYAN "\x1b[36m" 
#define COLOR_BROWN "\x1b[33m"
#define COLOR_RED "\x1b[31m"
#define COLOR_RESET "\x1b[0m" 

//criação de um motor de jogos.
/* implementar alguns sistemas independetes: um módulo de renderização
 que mostra coisas na tela, e outro de física que seja capaz de calcular
 as interações entre os diferentes objetos.*/

/*Primeira versão: consiste de um sistema no qual todos os objetos são
conjuntos de partículas. Existem 4 tipos diferentes de partículas e elas
interagem entre si para formar um ambiente dinâmico.

O motor de jogos consiste de um loop que itera por frames.
Um frame é uma representação visual do estado do jogo naquele momento e
é essa representação que deve ser impressa na tela. Depois de imprimir o
frame, o estado do jogo deve ser atualizado de acordo com as regras da 
física desse mundo (descritas abaixo).
*/

#define n_linhas 34 //32 + borda
#define m_colunas 66 //64 + borda

void renderizacao(char mat[n_linhas][m_colunas]); //protótipos
void fisica(char mat[n_linhas][m_colunas]);

int main(){

    /*A função main deve consistir essencialmente de um loop que imprime
    a matriz de estado e em seguida chama a função de aplicar a física. 
    Esse loop deve rodar por um determinado número de iterações fornecido
    na entrada padrão.*/

    char mat[n_linhas][m_colunas]; //iniciada: partículas de ar //mat[y][x]
    
    //borda cimento: espaço "fora" da matriz
    for(int i = 0; i < n_linhas; i++){
        for(int j = 0; j < m_colunas; j++){
            if(i == 0 || j == 0 || i == n_linhas - 1 || j == m_colunas - 1){
                mat[i][j] = '@';
            }
            else{
                mat[i][j] = ' ';
            }
        }
    }
    
    int frames, frame, x, y; 
    char particula;
    
    scanf("%d", &frames); //quantas rodadas dura o jogo

    int frame_atual = 0;
    while(frame_atual < frames){ //jogo rolando

        int leitura = scanf(" %d: %d %d %c", &frame, &x, &y, &particula);

        if (leitura == EOF){//falta só renderizar o último frame e fim
            frame = frames;
        }

        // podem haver várias entradas para um mesmo frame
        while(frame_atual < frame){ //leu todos de um frame, printa ele
            system("clear");
            printf("frame: %d\n", frame_atual + 1);
            renderizacao(mat);
            fisica(mat);
            usleep(750*1000); //micros
            frame_atual++;
        }

        //criar partículas: 
        if(leitura != EOF){
            mat[y+1][x+1] = particula; //cria partícula
        }
    }

    //Print estado final
    system("clear");
    printf("frame: %d\n", frame_atual);
    renderizacao(mat);

    return 0;
}


 void renderizacao(char mat[n_linhas][m_colunas]){

    /* A cada frame essa matriz deve ser imprimida na tela, isso é,
    cada linha imprimida como uma string e ao final dela um caractere '\n'
    para indicar o final da linha. */

    for(int i = 0; i < n_linhas; i++){
        for(int j = 0; j < m_colunas; j++){
            //printf("%c", mat[i][j]);

            if(mat[i][j] == '@'){
                printf(COLOR_RED "%c" COLOR_RESET, mat[i][j]);
            }

            else if(mat[i][j] == '~'){
                printf(COLOR_CYAN "%c" COLOR_RESET, mat[i][j]);
            }

            else if(mat[i][j] == '#'){
                printf(COLOR_BROWN "%c" COLOR_RESET, mat[i][j]);
            }

            else{
                printf("%c", mat[i][j]);
            }

        }
        printf("\n");
    }
}

void fisica(char mat[n_linhas][m_colunas]){
    /*Existem 4 tipos de partículas representadas por caracteres:
    Areia (#), Água (~), Cimento (@) e Ar (<espaço>). 
    Cada uma dessas partículas possui um comportamento diferente que poderá
    mudar sua posição na matriz na hora de aplicar a física.*/

    /*No início da função uma cópia da matriz de estado deve ser criada. 
    Durante a simulação, as atualizações devem ser feitas nessa matriz, 
    enquanto as verificações de qual partícula se encontra em qual posição
    devem ser feitas com a matriz original. Isso é necessário para que não
    verifiquemos posições que já foram atualizadas.*/

    char copia[n_linhas][m_colunas] = {}; 
    for(int i = 0; i < n_linhas; i++){
        for(int j = 0; j < m_colunas; j++){
            copia[i][j] = mat[i][j];
        }
    }

    /*Atenção: Para atualizar a matriz de cópia durante a execução da função 
    de atualização da física, faça uma troca direta e simples dentro da 
    própria matriz cópia.
    
    char tmp = copia[i][j];
    copia[i][j] = copia[i + 1][j];
    copia[i + 1][j] = tmp;
    */ 

    /*Percorra a matriz do topo para baixo apenas uma vez, da esquerda para 
    a direita e atualize a partícula em cada posição de acordo com as regras.
    Por fim, coloque a atualização na matriz cópia.*/

    for(int i = 1; i < n_linhas - 1; i++){ //Percorre matriz original: mat
        for(int j = 1; j < m_colunas - 1; j++){

            //atualiza na cópia
            char tmp = copia[i][j];

            switch (mat[i][j])
            {
            case '@': //cimento
                //nada acontece;
                break;
            
            case ' ': //ar
                //nada acontece;
                break;

            case '#': //areia: troca com ar e agua
                
                //checar elemento debaixo:             
                if(copia[i+1][j] == ' ' || copia[i+1][j] == '~'){
                    copia[i][j] = copia[i + 1][j];
                    copia[i + 1][j] = tmp;
                }

                //checar elemento esq abaixo
                else if(copia[i+1][j-1] == ' ' || copia[i+1][j-1] == '~'){
                    copia[i][j] = copia[i + 1][j - 1];
                    copia[i + 1][j - 1] = tmp;
                }

                //checar elemento dir abaixo
                else if(copia[i+1][j+1] == ' ' || copia[i+1][j+1] == '~'){
                    copia[i][j] = copia[i + 1][j + 1];
                    copia[i + 1][j + 1] = tmp;
                }

                break;

            case '~': //água: troca com ar

                //checar elemento debaixo:
                if(copia[i+1][j] == ' '){
                    copia[i][j] = copia[i + 1][j];
                    copia[i + 1][j] = tmp;
                }

                //checar elemento esq abaixo
                else if(copia[i+1][j-1] == ' '){
                    copia[i][j] = copia[i + 1][j - 1];
                    copia[i + 1][j - 1] = tmp;
                }

                //checar elemento dir abaixo
                else if(copia[i+1][j+1] == ' '){
                    copia[i][j] = copia[i + 1][j + 1];
                    copia[i + 1][j + 1] = tmp;
                }

                //checar elemento ao lado esq
                else if(copia[i][j-1] == ' '){
                    copia[i][j] = copia[i][j - 1];
                    copia[i][j - 1] = tmp;
                }

                //checar elemento ao lado dir
                else if(copia[i][j+1] == ' '){
                    copia[i][j] = copia[i][j + 1];
                    copia[i][j + 1] = tmp;
                }

                break;
            
            default:
                break;
            }
        }
    }

    /*Por último, ao final da função, a matriz com as atualizações 
    (matriz cópia) substitui a matriz original, efetivamente atualizando 
    o estado da simulação.*/

    for(int i = 1; i < n_linhas - 1; i++){
        for(int j = 1; j < m_colunas - 1; j++){
            mat[i][j] = copia[i][j];
        }
    }

}