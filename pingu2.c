#include <stdio.h>

int main(void){

    int n_rodadas, n_jogadores, n_pingu;
    scanf("%d %d %d", &n_rodadas, &n_jogadores, &n_pingu);
    
    char resposta[3][10] = {{" penguins"},
                            {"no gelo"},
                            {"uhuu!"}};
    int rodada = 1;
    int ciclo = 1;
    int i = 1;
    int indice = 0;
    
        // jogo
        for(int i = 0; i < ciclo; i++){

            while (rodada <= n_rodadas){

            // índice 
            if (rodada <= 2){
                indice = rodada - 1;
            }
            else{ //opa! tem que considerar o ciclo! ex: n = 2 >> repete o índice 2 vezes
                indice = (rodada - 1) % (3);//*ciclo);  //0, 1, 2
            }
            printf("rodada: %d, indice: %d\n", rodada, indice);

            if (rodada == 1){
                printf("1 penguim\n");
                rodada++;
            }
            else {
                if (indice == 0){
                    printf("%d%s\n", ciclo, resposta[indice]);
                }
                else{
                    printf("%s\n", resposta[indice]);
                }
                
                if (rodada != n_rodadas){
                    
                    // ciclo
                    int mud_ciclo = 0;
                    for (int i = 1; i <= ciclo; i++){
                        mud_ciclo += 3*i;
                    };
                    if (rodada % mud_ciclo == 0){
                        ciclo++;
                    };
                    printf("ciclo: %d\n", ciclo);
                }
                
                rodada++;
            };
            }
        }

    return 0;
}