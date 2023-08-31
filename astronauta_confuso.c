#include <stdio.h>

int main(void){

    int N, P, x, y, L;
    scanf("%d %d", &N, &P);

    L = N*N;

    //printf("N: %d, P: %d, L: %d\n", N, P, L);
    if(P > L){
        //já saiu
        printf("O astronauta ja saiu em missao ha %d chamadas.\n", P-L);
    }

    else if (P == L){
        x = N/2;
        y = N/2;
        if (N % 2 == 0){//par
            y--;
        }
        printf("O astronauta esta na posicao: %d %d\nPreste atencao, astronauta, chegou a sua vez!\n", x, y);
    }

    else{

        int LP;
        LP = L - P;
        
        //ajustar o indice: ordem da matriz
        //andar só no último andar
        int per = (N - 1)*4;
        int nivel_ordem = N;
        
        while (P > ((nivel_ordem - 1)*4)){
            per = (nivel_ordem - 1)*4;
            P -= per;
            nivel_ordem -= 2;
        }
        //ordem da matriz do andar mais alto
        //andaremos nessa matriz pequena

        //lado
        int lado, resto;
        lado = (P - 1) / (nivel_ordem - 1);
        resto = (P - 1) % (nivel_ordem - 1);
        //printf("Lado: %d, Resto: %d\n", lado, resto);
        switch (lado)
        {
        case 0:
            y = resto;
            x = 0;
            break;
        case 1:
            x = resto;
            y = nivel_ordem - 1;
            break;
        case 2:
            y = nivel_ordem - resto -1;
            x = nivel_ordem - 1;
            break;
        case 3:
            x = nivel_ordem - resto - 1;
            y = 0;
            break;
        
        default:
            break;
        }
        
        //voltar para o x,y originais: depende de quantos níveis subiu
        x += (N - nivel_ordem)/2;
        y += (N - nivel_ordem)/2;
        
        printf("O astronauta esta na posicao: %d %d\nAinda faltam %d chamadas para a sua vez!\n", x, y, LP);
    }

    return 0;
}