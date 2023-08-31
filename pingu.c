#include <stdio.h>

int main(void){

    int n_rodadas, n_jogadores, n_pingu, rodada, ciclo, mud_ciclo;
    scanf("%d %d %d", &n_rodadas, &n_jogadores, &n_pingu);
    printf("n_rodadas: %d, n_jogadores: %d, vez Pingu: %d\n", n_rodadas, n_jogadores, n_pingu);

    char resposta[3][10] = {{" pinguins"},
                    {"no gelo"},
                    {"uhuu!"},};
    
    // Jogo:

    rodada = 1; //número da rodada atual
    ciclo = 1;
    mud_ciclo = 0;
    while (rodada <= n_rodadas - 1){ // jogo rolando
        
        //gira de 3 em 3n (n : ciclos)
        if (rodada <= 3){
            switch (rodada)
            {
            case 1:
                printf("1 pinguim\n");
                break;
            
            case 2 ... 3:
                printf("%s\n", resposta[rodada - 1]);
                break;
            }
        };

        //mudança de ciclo (repetições)
        //som 3 * i de i=1 até i=n: 3*1 + ... + 3*n
        for (int i = 1; i = ciclo; i++){
            mud_ciclo += 3*i;
        };
        
        if (rodada % mud_ciclo == 0){
            ciclo++;
        };


        //for (int i = 1; i <= ciclo; i++){};


        // vez de Pingu:
        //if (n_rodadas % n_jogadores == n_pingu){}

        printf("rodada atual: %d", rodada);
        rodada++;

    };

    return 0;
}

