//Apenas Bits

//pegar esse número e olhar os bits de cada algarismo
    //utilizar operadores bitwise para isolar os bytes de n
    //máscara de bits
    //dec: 1633837924 = bin: 0  11000010 11000100 11000110 1100100
    //ATENÇÃO: pegar os bits de 8 em 8 da direita para esquerda!
    //pela tabela ASCII, para cada binário (8bits) :: um char; letras, n, ?!...

    //transformar o n lido em binário:
    /* Recursive using bitwise operator 
    Steps to convert decimal number to its binary representation are given below: 

    step 1: Check n > 0
    step 2: Right shift the number by 1 bit and recursive function call
    step 3: Print the bits of number
    */

    //binário: ps número enooorme! n cabe em um long long int
    //preencher cada char aos poucos
    /*
    while (n != 0) {
        resto = n % 2;
        n = n / 2; // n /= 2;
        bin = bin + resto * i; //bin += resto * i;
        i = i * 10; // i*= 10;
    } 
    */

   /* Operadores bitwise são utilizados quando precisamos realizar operações
   a nível de bits com números inteiros, ou seja, trabalhar com sua representação binária.
   Caso ambos os operandos sejam strings, esses operadores irão trabalhar com 
   os valores ASCII de seus caracteres.*/
   
   /* DICA DE IMPLEMENTAÇÃO: Utilize operadores bitwise para isolar os bytes do int. 
   Para isolar um conjunto de bits de algum número, podemos usar uma máscara de bits.
   Isso é, fazer um AND bitwise entre o número e um outro que chamamos de máscara e que,
   em binário, possui 1 apenas nos bits que nos interessam.
   Por exemplo, digamos que estejamos interessados nos 5 bits menos significantes.
   Então o nossa máscara seria 11111. */

   //ERRO: 0 à direita é significativo!
   //char2 = n & 65280; //1111111100000000
   //char3 = n & 16711680; //111111110000000000000000
   //char4 = n & 4278190080; //11111111000000000000000000000000

   /*printf("%c", char4);
    printf("%c", char3);
    printf("%c", char2);
    printf("%c\n", char1);*/

#include <stdio.h>

int main()
{
    int n, char1, char2, char3, char4;
    scanf("%d", &n); //leitura nº inteiro n
    
    //atribuição 8 bytes para cada caractere
    //255: máscara 0b11111111, 8 primeiras entradas (direita -> esquerda)
    char1 = n & 255; //11111111  d
    char2 = (n >> 8) & 255; //desloca entradas para direita 
    char3 = (n >> 16) & 255;
    char4 = (n >> 24) & 255;
    
    //código secreto em letras, especificador char: %c
    //mensagem da esquerda para direita
    printf("%c%c%c%c\n", char4, char3, char2, char1);

    return 0;
}