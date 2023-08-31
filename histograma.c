#include <stdio.h>

#define tamanho_imagem 25
#define n_cores 5

void ler_vetor(int *vetor){
    for (int i = 0; i < tamanho_imagem; i++){
        scanf("%d", &vetor[i]);    
    }
}

void print_vetor(int n, int *vetor){
    for (int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void hashtag(int *hist, int i){
    for(int j = 0; j < hist[i]; j++){
            printf("#");
        }
}

int maximo(int n, int *vetor){
    // Encontrar maior valor (índice)
    
    int max = 0;  // assume que o primeiro é o maior
    for(int i = 0; i < n; i++){
       if (vetor[i] > vetor[max]){
           max = i;
       }
    }

    return max;
}


int main(void){

    //Leitura: imagem
    int imagem[tamanho_imagem] = {};
    ler_vetor(imagem);
    //print_vetor(tamanho_imagem, imagem);

    //Histograma:
    int hist[n_cores] = {0}; //valor inicial: zero
    //print_vetor(n_cores, hist);

    for (int i = 0; i < tamanho_imagem; i++){ //ler cada entrada, descobrir qual o valor e contar
        hist[imagem[i]]++;    
    }
    //print_vetor(n_cores, hist);

    //Print:
    /* formatação proposta: valor da cor: |#\n 
     o caractere '#' deve ser impresso o número de vezes
     correspondente ao valor daquela cor no histograma.
    */
    for(int i = 0; i < n_cores; i++){
        
        switch (i)
        {
        case 0:
            printf("0: |");
            hashtag(hist, i);
            printf("\n");
            break;
        
        case 1:
            printf("1: |");
            hashtag(hist, i);
            printf("\n");
            break;

        case 2:
            printf("2: |");
            hashtag(hist, i);
            printf("\n");
            break;

        case 3:
            printf("3: |");
            hashtag(hist, i);
            printf("\n");
            break;

        case 4:
            printf("4: |");
            hashtag(hist, i);
            printf("\n");
            break;

        default:
            break;
        }        
    }

    /*para a cor mais presente na imagem, 
    imprima o índice de cada pixel que possui determinada cor
    (em ordem crescente)*/
    int max = 0;
    max = maximo(n_cores, hist);
    for (int i = 0; i < tamanho_imagem; i++){ 
        if(imagem[i] == max){
            printf("%d\n", i);
        }    
    }

    return 0;
}