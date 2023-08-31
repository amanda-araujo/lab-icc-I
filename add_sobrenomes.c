#include <stdio.h>
#include <stdlib.h> //necessário para usar as funções malloc() e free()

/*você deverá ler nomes até encontrar o caractere '$', com código ASC II
 decimal de valor 36.

 Para todo nome de índice par na sua lista (a partir de 0), caso exista
 o próximo nome, você deverá adicionar* o último sobrenome do atual nome
  de índice par no próximo nome de índice ímpar.*/

/*Obs: Use alocação dinâmica, você não sabe quantos nomes terão, o tamanho
 de cada nome e nem quantos sobrenomes tem cada nome, portanto, não faz
 sentido utilizar vetores estáticos.*/

/*Quantos nomes: TAMANHO DA LISTA DE NOMES 'lista'
  Tamanho de cada nome: 'nome' (total de caracteres)
  Quantos sobrenomes tem cada nome: contar nº de palavras, 
                                    para poder pegar o último sobrenome*/

int main(){

    char **lista, **copia, c;
    int n = 0, n_nomes = 1, tam_nome = 10; //n: nº char do nome

    // Aloca a matriz:
    lista = (char **) malloc(n_nomes*sizeof(char *));
    for (int i = 0; i < n_nomes; i++){
        lista[i] = (char *) malloc(tam_nome*sizeof(char));
    }

    /*
    // Preenche a matriz: ela existe!
    for (int i = 0; i < n_nomes; i++) {
        for (int j = 0; j < tam_nome; j++) {
            lista[i][j] = 'z';
        }
    }

    //Print:
    for (int i = 0; i < n_nomes; i++) {
        for (int j = 0; j < tam_nome; j++) {
            printf("%c ", lista[i][j]);
        }
        printf("\n");
    }*/

    scanf("%c", &c);

    // Leitura:
    while (c != '$'){ //36

        if (c == '\n'){
            
            //Cópia da lista:
            copia = (char **) malloc(n_nomes*sizeof(char *));
            for (int i = 0; i < n_nomes; i++){
                copia[i] = (char *) malloc(tam_nome*sizeof(char));
            }
            // preenchendo:
            for (int i = 0; i < n_nomes; i++){
                for (int j = 0; j < tam_nome; j++){
                    copia[i][j] = lista[i][j];
                }
            }
            
            //Print Cópia
            printf("Print cópia nova linha:\n");
            for (int i = 0; i < n_nomes; i++) {
                for (int j = 0; j < tam_nome; j++) {
                    printf("%c", copia[i][j]);
                }
                printf("\n");
            }
            
            n_nomes++;
            n = 0;
            
            //Nova lista (add + um nome): 
            lista = (char **) malloc(n_nomes*sizeof(char *));
            for (int i = 0; i < n_nomes; i++){
                lista[i] = (char *) malloc(tam_nome*sizeof(char));
            }
            // preenchendo: (antigos :: todos)
            for (int i = 0; i < n_nomes - 1; i++){
                for (int j = 0; j < tam_nome; j++){
                    lista[i][j] = copia[i][j];
                }
            }
        }

        else{ //ler char de um nome
            
            lista[n_nomes - 1][n] = c;
            
            n++; 

            //printf("n: %d\n", n);
            if (n >= tam_nome){ //aumentar tam_max

                //Cópia da lista:
                copia = (char **) malloc(n_nomes*sizeof(char *));
                for (int i = 0; i < n_nomes; i++){
                    copia[i] = (char *) malloc(tam_nome*sizeof(char));
                }
                // preenchendo:
                for (int i = 0; i < n_nomes; i++){
                    for (int j = 0; j < tam_nome; j++){
                        copia[i][j] = lista[i][j];
                    }
                }

                //Print Cópia ERRO AO FAZER A CÓPIA pq???
                printf("Print cópia tam+1:\n");
                for (int i = 0; i < n_nomes; i++) {
                    for (int j = 0; j < tam_nome; j++) {
                        printf("%c", copia[i][j]);
                    }
                    printf("\n");
                }

                tam_nome++;
                printf("tam_nome: %d\n", tam_nome);

                //Nova lista (permite add + um caractere): 
                lista = (char **) malloc(n_nomes*sizeof(char *));
                for (int i = 0; i < n_nomes; i++){
                    lista[i] = (char *) malloc(tam_nome*sizeof(char));
                }
                // preenchendo: (antigos)
                for (int i = 0; i < n_nomes - 1; i++){
                    for (int j = 0; j < tam_nome; j++){
                        lista[i][j] = copia[i][j];
                    }
                }
            }           
        }

        scanf("%c", &c);
    }

    //Print:
    for (int i = 0; i < n_nomes; i++){
        for(int j = 0; j < tam_nome; j++){
            printf("%c", lista[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}

