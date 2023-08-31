#include <stdio.h>

int main(void){

    // Leitura dos valores, salvando em um vetor
    #define TAM_MAX 4

    double Valores[TAM_MAX];

    for(int i=0; i<TAM_MAX; i++)
       scanf("%lf", &Valores[i]);
    
    // Encontrar menor valor (índice)
    int min = 0;  // assume que o primeiro é o menor
    for(int i=0; i<TAM_MAX; i++){
       if (Valores[i] < Valores[min]){
           min = i;
       }
    }
    
    //printf("O menor elemento é %f\n", Valores[min]);
    //printf("Minimo posição no vetor: %d\n", min);

    // Calcular a média com descarte:
    double media_descarte = 0;
    for(int i=0; i<TAM_MAX; i++){
        if (i != min){
            media_descarte += Valores[i]; 
        }
    }
    media_descarte = media_descarte/(TAM_MAX-1);
    
    printf("%.4f\n", media_descarte);

    /*for (int i = 0; i<=3; i++){
        printf("%f ", Valores[i]);
    }*/
    
    return 0;
}