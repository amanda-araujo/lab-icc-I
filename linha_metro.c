#include <stdio.h>

void rota(int n){
    
    int i;
    char linha_amarela[10][30] = {{"* Morumbi"}, 
                              {"* Butanta"},
                              {"* Pinheiros"},
                              {"* Faria Lima"},
                              {"* Fradique Coutinho"},
                              {"* Oscar Freire"},
                              {"* Paulista"},
                              {"* Higienopolis-Mackenzie"},
                              {"* Republica"},
                              {"* Luz"}};
    
    if (n <= 5){
        for (i = n; i <= 5; i++){
                printf("%s\n", linha_amarela[i]);
                if (i < 5){
                    printf("|\n");
                };
        }
    }

    else{
        for (i = n; i <= 9; i++){
                printf("%s\n", linha_amarela[i]);
                if (i < 9){
                    printf("|\n");
                };
            }
    }
    
}

int main(void){

    int n; //estação 
    scanf("%d", &n);
    
    rota(n);

    return 0;

}

/*
switch (n)
    {
    //antes/até oscar freire
        case 0 ... 5:
            for (i = n; i <= 5; i++){
                printf("%s\n", linha_amarela[i]);
                if (i < 5){
                    printf("|\n");
                };
            } 
            break;
        
    //depois da oscar freire
        case 6:
            for (i = n; i <= 9; i++){
                printf("%s\n", linha_amarela[i]);
                if (i < 9){
                    printf("|\n");
                };
            }
            break;

        case 7:
            rota_luz(n);
            break;
    
        case 8:
            rota_luz(n);
            break;
    
        case 9:
            rota_luz(n);
            break;

        default:
            break;
    };
    
    return 0;    
}

char rota_oscarfreire(int n){
    
    int i;
    char linha_amarela[10][30] = {{"* Morumbi"}, 
                              {"* Butanta"},
                              {"* Pinheiros"},
                              {"* Faria Lima"},
                              {"* Fradique Coutinho"},
                              {"* Oscar Freire"},
                              {"* Paulista"},
                              {"* Higienopolis-Mackenzie"},
                              {"* Republica"},
                              {"* Luz"}};
    
    for (i = n; i <= 5; i++){
                printf("%s\n", linha_amarela[i]);
                if (i < 5){
                    printf("|\n");
                };
        }
}

char rota_luz(int n){
    
    int i;
    char linha_amarela[10][30] = {{"* Morumbi"}, 
                              {"* Butanta"},
                              {"* Pinheiros"},
                              {"* Faria Lima"},
                              {"* Fradique Coutinho"},
                              {"* Oscar Freire"},
                              {"* Paulista"},
                              {"* Higienopolis-Mackenzie"},
                              {"* Republica"},
                              {"* Luz"}};
    
    for (i = n; i <= 9; i++){
                printf("%s\n", linha_amarela[i]);
                if (i < 9){
                    printf("|\n");
                };
            }
}
*/