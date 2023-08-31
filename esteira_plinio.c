#include <stdio.h>

//fábrica: a_m,n >> i: linha i, m linhas; j: coluna j, n colunas
#define m_fabrica 32 //m : i > linhas
#define n_fabrica 65 //n : j > colunas

void movimento(char c, int* i, int* j){ //altera valores originais de i, j

    //precisava que devolvesse i, j!
    //ponteiro: altera valores originais de i, j
    
    switch (c)
        {
        case '>':
            *j = *j + 2; //j: só pares (ímpares ' ')
            break;
        
        case '<':
            *j = *j - 2;
            break;

        case '^':
            *i = *i - 1;
            break;

        case 'v':
            *i = *i + 1;
            break;
     
        default:
            break;
        }
}

int main(void){

    char fabrica[m_fabrica][n_fabrica] = {};
    
    //Leitura:    
    FILE* input;
    char nome_arquivo[30];

    scanf("%s", nome_arquivo);
    input = fopen(nome_arquivo, "r");
    
    for(int i = 0; i < m_fabrica; i++){

        int j =0;
        while(j < n_fabrica){
            fabrica[i][j] = fgetc(input);
            if(fabrica[i][j] == '\n'){
                j = n_fabrica;
            }
            j++;
        }
    }  
    
    //Verificação da esteira:
    /*verifique se essa esteira contém loops infinitos, possui falha, 
      ou está correta.*/
    /*O robô pode deixar uma marca pelos lugares que passar,
    substituindo o caractere naquele lugar da matriz por um '.'
    */
    
    //Ponto inicial '[' + Checar Falha na esteira ']'
    int i_in, j_in;
    int final = 0; //if not ] (0): falha na estreira

    for(int i = 0; i < m_fabrica; i++){
        for(int j = 0; j < n_fabrica; j++){
            if(fabrica[i][j] == '['){
                i_in = i;
                j_in = j;
            }
            if(fabrica[i][j] == ']'){
                final = 1; //não há falha na esteira
            }
        }
    }
    
    //printf("Posição [: i = %d, j = %d\n", i_in, j_in);

    char c;
    int i = i_in; //0
    int j = j_in + 2; //2 //primeiro à direita de '['
    //char c_ant = '[';
    char c_ant[n_fabrica*m_fabrica] = {};
    c_ant[0] = '[';
    c = fabrica[i][j]; 

    //printf("Primeiro comando da esteira: i: %d, j: %d\n", i, j);

    int p = 1; //nº de movimentos //primeiro mov
    int loop = 0;

    while(c != ']'){ //|| p < n_fabrica*m_fabrica){

        if(c == '#'){ //continua movimento anterior
            printf("valor da posição i: %d, j:%d e comando: %c\n", i, j, fabrica[i][j]);
            printf("c_ant de '#': %c", c_ant[p-1]);
            fabrica[i][j] = '-';
            movimento(c_ant[p-1], &i, &j);
            printf("posição depois do movimento: i = %d, j: %d\n", i, j);
        }

        else if(c == '-'){ //2 vez pela junção
            printf("valor da posição i: %d, j:%d e comando: %c\n", i, j, fabrica[i][j]);
            fabrica[i][j] = '#';
            
            //caso '#' lado a lado: '#''#' >> '-''-'
            //c_ant volta até encontrar != '-' (#): CASO GERAL
            int a = 1;
            while(c_ant[p-a] == '-'){
                a++;
            }
            movimento(c_ant[p-a], &i, &j);
            printf("posição depois do movimento: i = %d, j: %d\n", i, j);

            /*
            if(c_ant[p-1] == '-'){
                movimento(c_ant[p-2], &i, &j);
                printf("posição depois do movimento: i = %d, j: %d\n", i, j);
            }
            else{
            movimento(c_ant[p-1], &i, &j);
            printf("posição depois do movimento: i = %d, j: %d\n", i, j);
            }*/
        }

        else if(c == '.'){
            if(final == 1){
                printf("Loop infinito.\n");
                loop = 1;
            }
            break;
        }
        
        else if(c == '>' || c == '<' || c == '^' || c == 'v'){
            printf("valor da posição i: %d, j:%d e comando: %c\n", i, j, fabrica[i][j]);
            fabrica[i][j] = '.';
            movimento(c, &i, &j);
            printf("posição depois do movimento: i = %d, j: %d\n", i, j);
        }

        else{ //torna p inútil
            break;
        }
        
        c_ant[p] = c;
        c = fabrica[i][j];
        p++;
    }

    if(c == ']'){
        printf("Ok.\n"); //chegou até o final
    }

    //printf("p = %d\n", p);
    //if(p >= n_fabrica*m_fabrica){
    //    printf("Falha na esteira.\n"); //tem ']', mas Falha na esteira
    //}

    //falha: tem ']', mas chega nele antes de rodar toda a esteira
    if(loop == 0){
        for(int i = 0; i < m_fabrica; i++){
            for(int j = 0; j < n_fabrica; j++){
                if(fabrica[i][j] == '>' || fabrica[i][j] == '<' || fabrica[i][j] == '^' || fabrica[i][j] == 'v'){
                    final = 0;
                    break;
                }
            }
        }
    }

    if(final == 0){
        printf("Falha na esteira.\n");
    }           
        
    //Print:
    for(int i = 0; i < m_fabrica; i++){
        for(int j = 0; j < n_fabrica; j++){
            if(fabrica[i][j] == '-'){
                printf("#");
            }
            else{
                printf("%c", fabrica[i][j]);
            }
        }
    }
    printf("\n");
    
    fclose(input);
    return 0;
}