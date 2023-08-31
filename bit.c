//Operadores bit a bit: bitwise

#include <stdio.h>

//operador &: bitwise AND -> compara dois valores bit a bit: 1(true) bits =, 0(false) !=
//operador |: bitwise OR  Ps: '|'= pipe -> retornando 1 se um dos bits comparados forem iguais a 1, cc 0 
//operador ^: bitwise XOR ->  retornando 1 se um dos bits comparados forem DIFERENTES, caso bits iguais 0 
//operador ~: bitwise NOT -> inverte todos os bits, complemento
//operador >>: bitwise right shift -> desloca x nº de casas para direita
//operador <<: bitwise left shift

int main()
{
    //int a = 8, b = 2;
    int a, b;

    //leitura numa mesma linha de a, b
    //scan
    scanf("%d %d", &a, &b);
    
    printf("%d \n", a & b); //bitwise AND
    printf("%d \n", a | b); //bitwise OR
    printf("%d \n", a ^ b); //bitwise Exclusive OR: XOR
    printf("%d \n", ~a); //bitwise Complement a
    printf("%d \n", ~b); //bitwise Complement b
    printf("%d \n", a >> 2); //bitwise a Right shift 2
    printf("%d \n", b << 2); //bitwise b Left shift 2
    
    return 0;
}