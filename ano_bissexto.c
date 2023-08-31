#include <stdio.h>

int main(void){

    int ano;
    scanf("%d", &ano);

    if (ano % 4 == 0){
        printf("SIM\n");
    }
    else   
        printf("NAO\n");

    return 0;
}

    //operadores ternários: return condition ? A : B;
    //ano_bissexto = (ano % 4 = 0) ? printf("SIM\n") : printf("NAO\n");
    //não deu certo! 
    