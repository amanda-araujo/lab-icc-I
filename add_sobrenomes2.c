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

void libera(char **matriz, int num_nomes);
char **aloca_matriz(int num_nomes, int tam_nome);

int main(){

    char **lista, **copia, c;
    int n = 0, n_nomes = 1, tam_nome = 10; //n: nº char do nome
    int pos_i_nome, pos_f_nome; // variaveis para o sobrenome

    // Aloca a matriz:
    lista = aloca_matriz(n_nomes, tam_nome);

    scanf("%c", &c);

    // Leitura:
    while (c != '$'){ //36

        if (c == '\n'){
            
            //Cópia da lista:
            copia = aloca_matriz(n_nomes, tam_nome);
            
            // preenchendo:
            for (int i = 0; i < n_nomes; i++){
                for (int j = 0; j < tam_nome; j++){
                    copia[i][j] = lista[i][j];
                }
            }

            libera(lista, n_nomes);
            
            n_nomes++;
            n = 0;
            
            lista = aloca_matriz(n_nomes, tam_nome);

            // preenchendo: (antigos :: todos)
            for (int i = 0; i < n_nomes - 1; i++){
                for (int j = 0; j < tam_nome; j++){
                    lista[i][j] = copia[i][j];
               }
            }

            libera(copia, n_nomes-1);
        }

        else{ //ler char de um nome
            
            lista[n_nomes - 1][n] = c;
            
            n++; 

            if (n >= tam_nome){ //aumentar tam_max

                //Cópia da lista:
                copia = aloca_matriz(n_nomes, tam_nome);
                
                // preenchendo:
                for (int i = 0; i < n_nomes; i++){
                    for (int j = 0; j < tam_nome; j++){
                        copia[i][j] = lista[i][j];
                    }
                }

                libera(lista, n_nomes);

                tam_nome++;
                //printf("tam_nome: %d\n", tam_nome);

                //Nova lista (permite add + um caractere):
                lista = aloca_matriz(n_nomes, tam_nome);

                // preenchendo: (antigos)
                for (int i = 0; i < n_nomes; i++){
                    for (int j = 0; j < tam_nome-1; j++){
                        lista[i][j] = copia[i][j];
                    }
                }

                libera(copia, n_nomes);
            }
        }
        
        scanf("%c", &c);

        if(c == '\n' || c == '$'){
            // posicao sobrenome anterior
            if(n_nomes%2 == 1){
                pos_f_nome = n-1;  

                for (int i = 0; i < n; i++){
                    if (lista[n_nomes-1][i] == 32){
                        pos_i_nome = i;
                    }
                }
            }
            
            // adiciona o sobrenome
            else {
                if (n < tam_nome){

                    copia = aloca_matriz(n_nomes, tam_nome);

                    for (int i = 0; i < n_nomes; i++){
                        for (int j = 0; j < tam_nome-1; j++){
                            copia[i][j] = lista[i][j];
                        }
                    }

                    libera(lista, n_nomes);

                    int tam_nome_old = tam_nome;
                    tam_nome = tam_nome + (pos_f_nome-pos_i_nome) +1;
                    
                    lista = aloca_matriz(n_nomes, tam_nome);

                    for (int i = 0; i < n_nomes; i++){
                        for (int j = 0; j < tam_nome_old-1; j++){
                            lista[i][j] = copia[i][j];
                        }
                    }
                    
                    libera(copia, n_nomes);
                }


                for (int i = 0; i < (pos_f_nome - pos_i_nome +1); i++){
                    lista[n_nomes-1][n+i] = lista[n_nomes-2][pos_i_nome+i];
                }
            }
        }
    }



    //Print:
    for (int i = 0; i < n_nomes; i++){
        for(int j = 0; j < tam_nome; j++){
            if(lista[i][j] == 0){
                break;
            }
            printf("%c", lista[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

void libera(char **matriz, int num_nomes){
    for(int i = 0; i < num_nomes; i++){
        free(matriz[i]);
    }
    free(matriz);
}


char **aloca_matriz(int num_nomes, int tam_nome){
    char **lista;
    
    lista = (char **) malloc(num_nomes*sizeof(char *));
    
    for (int i = 0; i < num_nomes; i++){
        lista[i] = (char *) malloc(tam_nome*sizeof(char));
    }

    return lista;
}
