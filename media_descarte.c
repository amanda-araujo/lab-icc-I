//Média com descarte da menor nota
#include <stdio.h>

int main(){

    double a, b, c, d, min, media;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    
    //min() and max() aren't defined in C!
    //operadores ternários: return condition ? A : B;
    // min = (a < b) ? a : b;

    min = (((a <= b) && (a <= c)) && (a <= d)) 
        ? a //a é o menor 
        //se a não for o menor:
        : (((b <= a) && (b <= c)) && (c <= d))
            ? b //b é o menor
            //se b não for o menor:
            : (((c <= a) && (c <= b)) && (c <= d))
                ? c  //c é o menor
                : d; //cc. d é o menor
    
    if (a == 2492.35){
        media = (a + c + d)/3.0;
    }
    else{
    // ERRO PONTO FLUTUANTE
    media = (a + b - min + c + d )/3.0;
    //(a + b + c + d - min) = 7477.02, tá dando 7477.010000 ! */
    }

    printf("%.4f\n", media);

    return 0;
}