#include <stdio.h>

int main(void){

    //leitura 6 entradas da entrada padrão de texto
    //Nota: utilize uma estrutura de repetição para ler
    // as 6 entradas e calcular o resultado.

    int i = 1;
    char comando;

    int x = 0, y = 0;
    while (i <= 6){
        scanf("%c", &comando);
        
        switch (comando)
        {
        case 'W':
            y += 1;
            break;
        case 'S':
            y += -1;
            break;
        case 'A':
            x += -1;
            break;
        case 'D':
            x += 1;
            break;
        }
        
        i++;
    }

    printf("%d %d\n", x, y);
    return 0;

}