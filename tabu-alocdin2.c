#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamMax_tabu 20

int main(){

    char palavraTabu[tamMax_tabu], c;
    scanf("%s\n", palavraTabu);

    //não sabemos o tamnho da linha: aloc din!
    int tam_linha = 1;
    char *linha, *copia;
    linha = (char*) malloc(tam_linha * sizeof(char));

    //Leitura char a char:
    scanf("%c", &c);

    while (c != 36){

        linha[tam_linha - 1] = c;

        //Cópia linha:
        copia = (char*) malloc(tam_linha * sizeof(char));

        for (int i = 0; i < tam_linha; i++){
            copia[i] = linha[i];
        }

        tam_linha++;

        free(linha);
        linha = (char*) malloc(tam_linha * sizeof(char));

        // Passar valores antigos:
        for (int i = 0; i < tam_linha-1; i++){
            linha[i] = copia[i];
        }

        free(copia);
        
        // Novo valor:
        scanf("%c", &c);
    }

    tam_linha--;

    //Retirar palavra tabu:
    /*Dica 2: para a comparação, é sugerido o uso da função strncmp(). 
    Com uma pequena manipulação do ponteiro da frase é possível usá-la sem 
    problemas :) ;*/
    /*you can subtract 2 pointers (to char) and interpret the result as
     an integer: position = ptr - sntnc;*/ 

    int n = 0, posicao;
    char *ptr = strstr(linha, palavraTabu);
    char *nova_linha;
    
    //Retirar: apagar de posicao até tam_tabu
    int tam_tabu = strlen(palavraTabu);
    
    while(strstr(linha, palavraTabu) != NULL){
        n++;
        
        posicao = ptr - linha; //posicao 1ª letra tabu em linha
        //printf("posicao: %d %d\n", posicao, n);

        //printf("tam tabu: %d\n", tam_tabu);
        
        nova_linha = (char*) malloc((tam_linha - n * tam_tabu) * sizeof(char));
        int p = 0;

        for(int i = 0; i < tam_linha; i++){ //varre linha            
            if (i < posicao || i >= (posicao + tam_tabu)){
                nova_linha[p] = linha[i];
                p++;
            }
        }

        //Print:
/*
        printf("Nova_linha:\n");
        for(int i = 0; i < tam_linha - tam_tabu; i++){
            printf("%c", nova_linha[i]);
        }
        printf("\n");
*/
        for(int i = 0; i < tam_linha - tam_tabu; i++){       
            linha[i] = nova_linha[i];
        }
        for(int i = tam_linha - tam_tabu; i < tam_linha; i++){
            linha[i] = ' ';
        }

        //Print:
/*
        printf("Linha após retirada\n");
        for(int i = 0; i < tam_linha; i++){
            printf("%c", linha[i]);
        }
        printf("\n");
*/          
        //Busca de novo por outra:
        ptr = strstr(linha, palavraTabu); //não está pegando a linha atualizada!! 
        //printf("*ptr final: %d\n", *ptr);

        free(nova_linha);
    }
    
    //Print:
    printf("A palavra tabu foi encontrada %d vezes\n", n);
    printf("Frase: ");
    for(int i = 0; i < (tam_linha - n * tam_tabu); i++){
        printf("%c", linha[i]);
    }
    printf("\n");


    return 0;
}
