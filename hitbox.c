#include <stdio.h>

int main(void){

    //leitura: 2 linhas <x> <y> <largura> <altura>
    int x1, y1, larg1, alt1, x2, y2, larg2, alt2;
    scanf("%d %d %d %d", &x1, &y1, &larg1, &alt1);
    scanf("%d %d %d %d", &x2, &y2, &larg2, &alt2);

    //<x> <y>: vértice sup esquerdo
    //x: cresce para direita
    //y: cresce para baixo

    //Não se tocam: MISS
    //Se tocar: HIT: <x> <y> <largura> <altura>, retângulo de intersecção
    
    // Teste se A, B, C, D estão dentro de 
    // [x1, x1 + larg1] e [y1, y1 + alt1]
    
    int X, Y, L, H;
    //A = (x2, y2)
    if ((x2 >= x1 && x2 <= (x1 + larg1) ) 
        && (y2 >= y1 && y2 <= (y1 + alt1) )){
            //A bate 
            // Medidas:
            X = x2;
            Y = y2;
            //largura
            if ( (x2 + larg2) <= (x1 + larg1) ){
                L = larg2;
            }
            else{
                L = (x1 + larg1) - x2;
            }
            //altura
            if ( (y2 + alt2) <= (y1 + alt1) ){
                H = alt2;
            }
            else{
                H = (y1 + alt1) - y2;
            }
            printf("HIT: %d %d %d %d\n", X, Y, L, H);
        }
    
    //B = (x2 + larg2, y2)
    else if (( (x2 + larg2) >= x1 && (x2 + larg2) <= (x1 + larg1) ) 
        && (y2 >= y1 && y2 <= (y1 + alt1) )){
            //B bate
            X = x1;
            Y = y2;
            L = (x2 + larg2) - x1;
            if ( (y2 + alt2) <= (x1 + alt1) ){
                H = alt2;}
            else{
                H = (y1 + alt1) - y2;}
            printf("HIT: %d %d %d %d\n", X, Y, L, H);
        }
    
    //C = (x2, y2 + alt2)
    else if ((x2 >= x1 && x2 <= (x1 + larg1) ) 
        && ( (y2 + alt2) >= y1 && (y2 + alt2) <= (y1 + alt1) )){
            //C bate
            X = x2;
            Y = y1;
            //largura
            if ( (x2 + larg2) <= (x1 + larg1) ){
                L = larg2;
            }
            else{
                L = (x1 + larg1) - x2;
            }
            H = (y2 + alt2) - y1;
            printf("HIT: %d %d %d %d\n", X, Y, L, H);
        }
    
    //D = (x2 + larg2, y2 + alt2)
    else if (( (x2 + larg2) >= x1 && (x2 + larg2) <= (x1 + larg1) ) 
        && ( (y2 + alt2) >= y1 && (y2 + alt2) <= (y1 + alt1) )){
            //D bate
            X = x1;
            Y = y1;
            L = (x2 + larg2) - x1;
            H = (y2 + alt2) - y1;
            printf("HIT: %d %d %d %d\n", X, Y, L, H);
        }

    // Testar se a, b, c, d estão dentro de
    // [x2, x2 + larg2] e [y2, y2 + alt2]
    // (2) engole (1)

    //a = (x1, y1)
    else if( (x1 >= x2 && x1 <= (x2 + larg2) ) 
        && (y1 >= y2 && y1 <= (y2 + alt2) )){
            //a bate 
            X = x1;
            Y = y1;
            //largura
            if ( (x1 + larg1) <= (x2 + larg2) ){
                L = larg1;
            }
            else{
                L = (x2 + larg2) - x1;
            }
            //altura
            if ( (y1 + alt1) <= (y2 + alt2) ){
                H = alt1;
            }
            else{
                H = (y2 + alt2) - y1;
            }
            printf("HIT: %d %d %d %d\n", X, Y, L, H);
        }

    //b = (x1 + larg1, y1)
    else if(( (x1 + larg1) >= x2 && (x1 + larg1) <= (x2 + larg2) ) 
        && (y1 >= y2 && y1 <= (y2 + alt2) )){
            //b bate
            X = x2;
            Y = y1;
            L = (x1 + larg1) - x2;
            if ( (y1 + alt1) <= (x2 + alt2) ){
                H = alt1;}
            else{
                H = (y2 + alt2) - y1;}
            printf("HIT: %d %d %d %d\n", X, Y, L, H);

        }

    //c = (x1, y1 + alt1)
    else if((x1 >= x2 && x1 <= (x2 + larg2) ) 
        && ( (y1 + alt1) >= y2 && (y1 + alt1) <= (y2 + alt2) )){
            //c bate
            X = x1;
            Y = y2;
            //largura
            if ( (x1 + larg1) <= (x2 + larg2) ){
                L = larg1;
            }
            else{
                L = (x2 + larg2) - x1;
            }
            H = (y1 + alt1) - y2;
            printf("HIT: %d %d %d %d\n", X, Y, L, H);

    }
    //d = (x1 + larg1, y1 + alt1)
    else if(( (x1 + larg1) >= x2 && (x1 + larg1) <= (x2 + larg2) ) 
        && ( (y1 + alt1) >= y2 && (y1 + alt1) <= (y2 + alt2) )){
            //D bate
            X = x2;
            Y = y2;
            L = (x1 + larg1) - x2;
            H = (y1 + alt1) - y2;
            printf("HIT: %d %d %d %d\n", X, Y, L, H);
        }

    // Caso intersecção sem vértices dentro 49/50:
    // paralelas horizontais (Y) e verticais (X)

    // 1 em pé, 2 deitado se cruzando no meio
    else if( ((y1 + alt1) > (y2 + alt2)) && ( y1 < y2 )
        && ( x1 > x2 ) && ((x1 + larg1) < (x2 + larg2)) ){
            X = x1;
            Y = y2;
            L = larg1;
            H = alt2;
            printf("HIT: %d %d %d %d\n", X, Y, L, H);
    }

    // 2 em pé, 1 deitado se cruzando no meio
    else if( ((y1 + alt1) < (y2 + alt2)) && ( y1 > y2 )
        && ( x1 < x2 ) && ((x1 + larg1) > (x2 + larg2)) ){
            X = x2;
            Y = y1;
            L = larg2;
            H = alt1;
            printf("HIT: %d %d %d %d\n", X, Y, L, H);
    }

    else{
        //não se batem
        printf("MISS\n");
    }

    return 0;
}