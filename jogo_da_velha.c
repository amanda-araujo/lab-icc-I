#include <stdio.h>

#define lado 3

int main(void){

    char jogo[lado][lado];
 
    //Leitura: matriz lado x lado
    for(int i = 0; i < lado; i++){ //linhas
        for(int j = 0; j < lado; j++){ //colunas
            scanf("%c ", &jogo[i][j]);
        }
    }

    //COISA HORROROSA, TOTAL DUMMIE

    //Estado do jogo:
    int game_on = 1; //1: sim, 0: acaba
        
    // Vitória ou empate:
    //diagonal principal:
    if((jogo[0][0] == jogo[1][1]) && (jogo[0][0] == jogo[2][2])){
        if(jogo[0][0] == 'o'){
            printf("o ganhou");
            game_on = 0;
        }
        else if(jogo[0][0] == 'x'){
            printf("x ganhou");
            game_on = 0;
        }
    }

    if(game_on == 1){
        //diagonal não-principal:
        if((jogo[2][0] == jogo[1][1]) && (jogo[2][0] == jogo[0][2])){
            if(jogo[1][1] == 'o'){
                printf("o ganhou");
                game_on = 0;
            }
            else if(jogo[1][1] == 'x'){
                printf("x ganhou");
                game_on = 0;
            }
        }
    }
    
    if(game_on == 1){
        //horizontal:
        for(int i = 0; i < lado; i++){
            if((jogo[i][0] == jogo[i][1]) && (jogo[i][0] == jogo[i][2])){
                if(jogo[i][0] == 'o'){
                    printf("o ganhou");
                    game_on = 0;
                }
                else if(jogo[i][0] == 'x'){
                    printf("x ganhou");
                    game_on = 0;
                }
            }
        }
    }

    if(game_on == 1){
        //vertical:
        for(int j = 0; j < lado; j++){
            if((jogo[0][j] == jogo[1][j]) && (jogo[0][j] == jogo[2][j])){
                if(jogo[0][j] == 'o'){
                    printf("o ganhou");
                    game_on = 0;
                }
                else if(jogo[0][j] == 'x'){
                    printf("x ganhou");
                    game_on = 0;
                }
            }
        }
    }
    
    if(game_on == 1){
        // Em jogo: '-' presente 
        for(int i = 0; i < lado; i++){ //linhas
            for(int j = 0; j < lado; j++){ //colunas
                if (jogo[i][j] == '-'){
                    game_on = 0;
                    break;
                }
            }
        }
        if (game_on == 0){
            printf("em jogo");
        }
    }
    
    if (game_on == 1){
        printf("empate");
    }
    
    return 0;
}