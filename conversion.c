//Conversão de (tipos de) variáveis

#include <stdio.h>

int main(void){

 double x1 = 4.2;
 char x2 = 'a';
 double resultado_double;
 int resultado_int;

 // implicito
 resultado_double = x1 + x2 + 1.0;
 printf("resultado_double = %lf\n", resultado_double);

 // explicito
 resultado_int = (int)x1 + (int)x2 + 1;
 printf("resultado_int = %d\n", resultado_int);

 return 0;

}
