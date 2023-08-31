//Expoente
#include <stdio.h>
#include<math.h>

int main(){

    double a = 0, b = 0, pot = 0;
    //8 bytes: melhor precisão cálculos
    // %lf : double (long float)
    // para atribuir o valor lido à váriável: &x
    scanf("%lf %lf", &a, &b);

    pot = pow(a, b); //pow(base, expoente)

    printf("%.4lf\n", pot);

    return 0;
}