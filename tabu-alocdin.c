#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamMax_tabu 20

char *cria_vetor(int n);

int main(){

    char palavraTabu[tamMax_tabu], c;
    scanf("%s\n", palavraTabu);

    //não sabemos o tamnho da linha: aloc din!
    int tam_linha = 0;
    char *linha, *copia;
    linha = cria_vetor(tam_linha);

    //Leitura char a char:
    scanf("%c", &c);

    while (c != '$'){

        //Cópia linha:
        copia = cria_vetor(tam_linha);
        for (int i = 0; i < tam_linha; i++){
            copia[i] = linha[i];
        }

        tam_linha++;

        linha = cria_vetor(tam_linha);

        // Passar valores antigos:
        for (int i = 0; i < tam_linha - 1; i++){
            linha[i] = copia[i];
        }
        // Novo valor:
        linha[tam_linha - 1] = c;

        scanf("%c", &c);
    }

    //Retirar palavra tabu:
    /*Dica 2: para a comparação, é sugerido o uso da função strncmp(). 
    Com uma pequena manipulação do ponteiro da frase é possível usá-la sem 
    problemas :) ;*/
    /*you can subtract 2 pointers (to char) and interpret the result as
     an integer: position = ptr - sntnc;*/ 

    int n = 0, posicao;
    char *ptr = strstr(linha, palavraTabu);
    
    while(strstr(linha, palavraTabu) != NULL){
        n++;
        
        posicao = ptr - linha; //posicao 1ª letra tabu em linha
        printf("posicao: %d\n", posicao);

        //Retirar: apagar de posicao até tam_tabu
        int tam_tabu = strlen(palavraTabu);
        //printf("tam tabu: %d\n", tam_tabu);

        char *nova_linha = cria_vetor(tam_linha - tam_tabu);
        int p = 0;

        for(int i = 0; i < tam_linha; i++){ //varre linha            
            if (i < posicao || i > (posicao + tam_tabu)){
                nova_linha[p] = linha[i];
                p++;
            }
        }

        //Print:
        printf("Nova_linha:\n");
        for(int i = 0; i < tam_linha - tam_tabu; i++){
            printf("%c", nova_linha[i]);
        }
        printf("\n");

        for(int i = 0; i < tam_linha - tam_tabu; i++){       
            linha[i] = nova_linha[i];
        }
        for(int i = tam_linha - tam_tabu; i < tam_linha; i++){
            linha[i] = ' ';
        }

        //Print:
        printf("Linha após retirada\n");
        for(int i = 0; i < tam_linha; i++){
            printf("%c", linha[i]);
        }
        printf("\n");
            
        //Busca de novo por outra:
        *ptr = strstr(linha, palavraTabu); //não está pegando a linha atualizada!! 
        printf("*ptr final: %d\n", *ptr);    
    }
    
    //Print:
    printf("A palavra tabu foi encontrada %d vezes\n", n);
    printf("Frase: %s\n", linha);

    return 0;
}

char *cria_vetor(int n) {
  char *vetor;

  // Cria o vetor (aloca na memoria):  
  vetor = (char *) malloc(n*sizeof(char));

  // Se deu problema na alocacao, termina a funcao:  
  if (vetor == NULL) {
    printf("Erro na alocacao de memoria\n");
    return(vetor);
  }

  // Preenche os elementos do vetor com 0:  
  /*for (int i = 0; i < n; i++) {
    vetor[i] = 0;
  }*/

  return(vetor);
}
