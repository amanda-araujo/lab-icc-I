#include <stdio.h>

#define n_numeros 10

int maior(int numeros[n_numeros]){

    int maior = numeros[0];
    for(int i = 0; i < n_numeros; i++){
        if(numeros[i] > maior){
            maior = numeros[i];
        }
    }

    return maior;
}

int menor(int numeros[n_numeros]){

    int menor = numeros[0];
    for(int i = 0; i < n_numeros; i++){
        if(numeros[i] < menor){
            menor = numeros[i];
        }
    }

    return menor;
}

float media(int numeros[n_numeros]){

    float media = 0.0;
    for(int i = 0; i < n_numeros; i++){
        media += numeros[i];
    }
    media = media/n_numeros;

    return media;
}

int moda(int numeros[n_numeros]){

    int moda;
    int contagem[n_numeros];

    for(int i = 0; i < n_numeros; i++){
        for(int j = 0; j < n_numeros; j++){
            if(numeros[i] == numeros[j]){
                contagem[i]++;
            }
        }
    }

    int i_maior = 0;
    for(int i = 0; i < n_numeros; i++){
        if(contagem[i] > contagem[i_maior]){
            i_maior = i;
        }
    }

    moda = numeros[i_maior];
    return moda;
}


int main(void){

    int numeros[n_numeros];

    //Leitura:
    for(int i = 0; i < n_numeros; i++){
        scanf("%d ", &numeros[i]);
    }

    //Valores:
    printf("%d %d %.2f %d", maior(numeros), menor(numeros), media(numeros), moda(numeros));

    return 0;
}