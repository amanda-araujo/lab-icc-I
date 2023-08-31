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
    /*FILE* input;
    char nome_arquivo[30];

    scanf("%s", nome_arquivo);
    input = fopen(nome_arquivo, "r");*/
    
    for(int i = 0; i < m_fabrica; i++){

        int j =0;
        while(j < n_fabrica){
            scanf("%c", &fabrica[i][j]); //fgetc(input);
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

    char c;
    int i = i_in; //0
    int j = j_in + 2; //2 //primeiro à direita de '['
    char c_ant[n_fabrica*m_fabrica] = {};
    c_ant[0] = '[';
    c = fabrica[i][j]; 

    int p = 1; //nº de movimentos //primeiro mov
    int loop = 0;

    while(c != ']'){ 

        if(c == '#'){ //continua movimento anterior
            fabrica[i][j] = '-';
            movimento(c_ant[p-1], &i, &j);
        }

        else if(c == '-'){ //2 vez pela junção
            fabrica[i][j] = '#';
            
            //caso '#' lado a lado: '#''#' >> '-''-'
            //c_ant volta até encontrar != '-' (#):
            int a = 1;
            while(c_ant[p-a] == '-'){
                a++;
            }
            movimento(c_ant[p-a], &i, &j);
        }

        else if(c == '.'){
            if(final == 1){
                printf("Loop infinito.\n");
                loop = 1;
            }
            break;
        }
        
        else if(c == '>' || c == '<' || c == '^' || c == 'v'){
            fabrica[i][j] = '.';
            movimento(c, &i, &j);
        }

        else{ 
            break;
        }
        
        c_ant[p] = c;
        c = fabrica[i][j];
        p++;
    }

    if(c == ']'){
        printf("Ok.\n"); //chegou até o final
    }

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
        
    //Print: matriz
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

    return 0;
}