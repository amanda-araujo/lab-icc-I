#include <stdio.h>

int main(void){

    int hoje, dia; //leitura do dia de hoje
    scanf("%d", &hoje);

    //print do calendário
    printf("         Abril 2021         \n");
    printf(" Do  Se  Te  Qu  Qu  Se  Sa \n");
    printf("                ");
    
    for(dia = 1; dia <= 30; dia++){

        if (dia == hoje){ //dia selecionado (hoje)
            printf("(%2d)", dia);
            if ((dia - 3) % 7 == 0){
                printf("\n");
            }
        } 
        else{ //não é o dia selecionado
            printf(" %2d ", dia);
            if ((dia - 3) % 7 == 0){
                printf("\n");
            } 
        }
    };

    printf("\n");
    
    return 0;

}