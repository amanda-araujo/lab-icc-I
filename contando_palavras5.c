#include <stdio.h>

int main(void){

    int n_chars = 0, n_palavras = 0, n_linhas = 0;
    char c, c_ant = '.';

    //Leitura: char a char
    while(scanf("%c", &c) != EOF){
        
        //Caracteres:
        n_chars++;

        //Palavras:
        if((c == ' ' || c == '\n' || c == '\r') && (c_ant != ' ' && c_ant != '\t' && c_ant != '\n' && c_ant != '\r')){
            n_palavras++; //terminou palavra
        }
        
        //Linhas:
        //indicadores pula linha: '\n', '\r\n', '\r' OK
        if(c == '\r'){
            n_linhas++;
        }
        else if(c == '\n'){
            if(c_ant != '\r'){
                n_linhas++;
            }
        }

        c_ant = c;
    }

    //Final leitura: c = EOF, c_ant
    if(n_linhas == 0){
        n_linhas++; // nenhuma quebra linha (linha 0)
    }
    if(c_ant != ' ' && c_ant != '\t' && c_ant != '\n' && c_ant != '\r'){
        n_palavras++; // final última palavra
    }
    
    //Print:
    printf("Linhas\tPalav.\tCarac.\n");
    printf("%d\t%d\t%d", n_linhas, n_palavras, n_chars);

    return 0;
}

/*ps: no caso 1 está contando palavras a menos! (??)
    Saída esperada:
Linhas	Palav.	Carac.
972	    5336	34404
    Saída produzida:
Linhas	Palav.	Carac.
972	    5296	34404
*/