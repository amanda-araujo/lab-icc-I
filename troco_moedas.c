#include <stdio.h>

/*criar um programa que retorne a menor quantidade 
possível de moedas como troco de uma compra*/
//Algoritmo guloso

void troco_moedas(int *valor, int *um_cent, int *cinco_cent, int *dez_cent,
                  int *vintecinco_cent, int *cinquenta_cent, int *um_real){
    
    //entrada: valor em centavos
    //decrementando valor pelas moedas disponíveis: maior >> menor

    while(*valor >= 100){
        *valor -= 100;
        *um_real = *um_real + 1; //ps: *p++ n funciona (incrementa o ponteiro em si, outro endereço de memória)! :: ++*p OK
    }

    while (*valor >= 50){
        *valor -= 50;
        ++*cinquenta_cent;
    }

    while (*valor >= 25){
        *valor -= 25;
        ++*vintecinco_cent;
    }

    while (*valor >= 10){
        *valor -= 10;
        ++*dez_cent;
    }

    while (*valor >= 5){
        *valor -= 5;
        ++*cinco_cent;
    }

    while (*valor >= 1){
        *valor -= 1;
        ++*um_cent;
    }
}

int main(){

    //Leitura:
    int valor; //em centavos!
    scanf("%d", &valor);

    //Cálculo troco:
    int um_cent = 0, cinco_cent = 0, dez_cent = 0, vintecinco_cent = 0, cinquenta_cent = 0, um_real = 0;
    troco_moedas(&valor, &um_cent, &cinco_cent, &dez_cent, &vintecinco_cent, &cinquenta_cent, &um_real);

    //Print:
    printf("O valor consiste em %d moedas de 1 real\n", um_real);
    printf("O valor consiste em %d moedas de 50 centavos\n", cinquenta_cent);
    printf("O valor consiste em %d moedas de 25 centavos\n", vintecinco_cent);
    printf("O valor consiste em %d moedas de 10 centavos\n", dez_cent);
    printf("O valor consiste em %d moedas de 5 centavos\n", cinco_cent);
    printf("O valor consiste em %d moedas de 1 centavo\n", um_cent);

    return 0;
}