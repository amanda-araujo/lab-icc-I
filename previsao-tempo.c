#include <stdio.h>
#include <math.h>

#define N_DIAS 7

int main(void){

    double pred[N_DIAS], real[N_DIAS];
    double mae, diff;
    int i;

    for(i = 0; i < N_DIAS; ++i){
        scanf("%lf", &pred[i]);
    }

    for(i = 0; i < N_DIAS; ++i){
        scanf("%lf", &real[i]);
    } 

    mae = 0.0;
    for(i = 0; i < N_DIAS; ++i){
        //acumular os deltas
        //if-else, operador ternario,  math.h: abs()
        //abs(): calcula e devolve inteiro (joga fora decimal)
        //fabs(): absoluto do float
        diff = fabs(real[i] - pred[i]);
        mae = mae + diff;

        printf("\t[%d] - %lf\n", i, diff);
    }

    //float arr_previsao[7];
    //float arr_observacao[7];

    mae /= N_DIAS; 
    //resultado diferente: mae * (1/N_DIAS)
    //1/7 são dois inteiros, ele devolve em inteiro: 0
    //mae = mae * 1/N_DIAS: dá certo
    //prioridade na conta + hierárquia dos tipos de dados 
    //double * int = double 

    printf(".2%lf", mae);
    return 0;
}

//criar txt com os dados de entrada (inputs)
//colocar na mesma pasta do código
//usar linha de comando: cd lab-icc
//mandar executar
//cls : limpa o terminal
//executarnomedoarquivo < in.txt 
// a setinha simula a entrada do arquivo