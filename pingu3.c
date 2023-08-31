#include <stdio.h>

int main(void){

    int n_rodadas, n_jogadores, n_pingu;
    scanf("%d %d %d", &n_rodadas, &n_jogadores, &n_pingu);
    
    char resposta[3][10] = {{" pinguins"},
                            {"no gelo"},
                            {"uhuu!"}};
    int ciclo = 1;
    int indice = 1;
    int rep = 0; 

    //(ciclo, indice, rep); ciclo: n penguins, indice: a frase resposta, rep: contador da repetição
    // 1.1.1 "1 pinguim"
    // 1.2.1 "no gelo"
    // 1.3.1 "uhuu!"
    // 2.1.1 "2 pinguins"
    // 2.1.2 "2 pinguins"
    // 2.2.1 "no gelo"
    // 2.2.2 "no gelo"
    // 2.3.1 "uhuu!"
    // 2.3.2 "uhuu!"
    // 3.1.1 "3 pinguins"

    //Jogo: 
    for (int rodada = 1; rodada <= n_rodadas; rodada++){

        //ajuste índices
        if (rep < ciclo){
            rep++;          
        }
        else{
            rep = 1;
            indice++;
        }
        if (indice > 3){
            indice = 1;
            ciclo++;
        } 
    
        //printf("ciclo: %d, indice: %d, rep: %d\n", ciclo, indice, rep);
        
        // vez de Pingu:
        if (rodada % n_jogadores == n_pingu % n_jogadores){ //20 2 2
            if (indice == 1){
                if (ciclo == 1){ //1.1
                    printf("1 pinguim\n");
                }
                else{
                    printf("%d%s\n", ciclo, resposta[indice - 1]);
                }
            }
            else{
                printf("%s\n", resposta[indice - 1]);
            }

        }
 
    } 
    
    return 0;
}