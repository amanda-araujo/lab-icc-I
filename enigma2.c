#include <stdio.h>

//Máquina Enigma: 3 rotores em sequência, 26 conexões 
#define n_conexoes 26 

/*Modelo de entrada:
    Rotores:            INÚTIL
    <valores rotor 1>
    <valores rotor 2>
    <valores rotor 3>
                        INÚTIL
    Mensagem:           INÚTIL
    <mensagem>*/

void ignorar_linha(void){
    scanf("%*[^\r\n]s"); // Ignora tudo até o final da linha
    scanf("%*[\r\n]s");  // Ignora o pula linha  
}

void ler_rotor(int *rotor){
    for (int i = 0; i < n_conexoes; i++){
        scanf("%d", &rotor[i]);    
    }
}

void print_rotor(int *rotor, char *rotorx){
    // rotor1 = {0, 1, 2, ... 25}
    
    printf("%s = {", rotorx);
    for(int i = 0; i < n_conexoes; i++){
        if(i == n_conexoes - 1){
            printf("%d", rotor[i]);
        }
        else{
            printf("%d, ", rotor[i]);
        }
    }
    printf("}\n");
}

void girar_rotor(int *rotor){
    //Giro do rotor 1 casa para esquerda
    
    int r[n_conexoes] = {}; //auxiliar
    
    r[n_conexoes - 1] = rotor[0]; //último
    for(int i = 0; i < n_conexoes - 1; i++){
        r[i] = rotor[i+1];
    }
    
    for(int i = 0; i < n_conexoes; i++){
        rotor[i] = r[i];
    }
}

void maquina_enigma(int contador_char, int *rotor1, int *rotor2, int *rotor3){
    
    //Funcionamento da máquina
    /*Com 3 rotores a situação é a mesma, mas temos 3 rotores conectados
     em série. Assim, o sinal que sai do teclado vai para o rotor 1, que
     vai para o 2 e por fim para o 3, embaralhando cada vez mais a letra.
     Entretanto, há uma diferença: o segundo rotor só gira uma posição
     quando o primeiro deu uma volta completa (andou 26 posições), e o
     terceiro só gira quando o segundo deu uma volta completa. Como se
     fossem os ponteiros de um relógio.
    */
    
    girar_rotor(rotor1);
    if(contador_char % n_conexoes == 0){ //volta completa rotor1
        girar_rotor(rotor2);
    }
    if(contador_char % (n_conexoes*n_conexoes) == 0){ //volta completa rotor2
        girar_rotor(rotor3);
    }
}

int descriptografar(char c, int *rotor1, int *rotor2, int *rotor3, int contador_char){
    /*IN: letra criptografada, rotores; 
      OUT: letra descriptografada (original)*/

    //Letras originais (alfabeto ordenado):
    char alfabeto_minusculas[n_conexoes] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char alfabeto_maiusculas[n_conexoes] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int char_especial = 1; //caractere especial ?!%&#.,;+

    //Descriptografia:
    for(int i = 0; i < n_conexoes; i++){
        int indice = rotor3[rotor2[rotor1[i]]];
        
        if(c == alfabeto_minusculas[i]){
            printf("%c", alfabeto_minusculas[indice]);
            char_especial = 0;
            contador_char++;
        }
        else if(c == alfabeto_maiusculas[i]){
            printf("%c", alfabeto_maiusculas[indice]);
            char_especial = 0;
            contador_char++;
        }
    }
    if(char_especial == 1){
        printf("%c", c);
    }
    else{ //Engrenagens:
        maquina_enigma(contador_char, rotor1, rotor2, rotor3);
    }

    return contador_char;
}


int main(void){
    
    ignorar_linha(); //1ª linha 
    
    //Leitura: Rotores
    int rotor1[n_conexoes] = {};
    int rotor2[n_conexoes] = {};
    int rotor3[n_conexoes] = {};
    
    ler_rotor(rotor1); //2ª linha
    ler_rotor(rotor2); //3ª linha
    ler_rotor(rotor3); //4ª linha

    //print_rotor(rotor1, "rotor1");
    //print_rotor(rotor2, "rotor2");
    //print_rotor(rotor3, "rotor3");

    ignorar_linha(); //5ª linha
    ignorar_linha(); //6ª linha

    //Leitura: Mensagem 
    /*char a char, até o final da mensagem: EOF*/
    char char_cripto;
    int j = 0; //contador de char (*exceto os especiais)

    while(scanf("%c", &char_cripto) != EOF){
        
        j = descriptografar(char_cripto, rotor1, rotor2, rotor3, j); //printa char decodificado + invoca o mecanismo da máquina
        
        //print_rotor(rotor1, "rotor1");
        //print_rotor(rotor2, "rotor2");
        //print_rotor(rotor3, "rotor3");

        //printf("j: %d\n", j);
    }

    return 0;  
}

//ERRO: até a letra 27 OK, depois cagado.
/* Como funciona de fato o mecanismo? A o rodar rotor1 completo, rotor2 passa a rodar. Os dois rodam juntos? Ou rotor1 foca parado enquanto rotor2 se movimenta?
   E o rotor3? Quando ele começa a girar os três giram juntos, ou ele se movimenta sozinho?

Acho que entendi: 
rotor2 só anda 1 quando rotor1 anda n_conexoes
rotor3 só anda 1 quando rotor2 anda n_conexoes
    Por isso que na descrição comenta-se que é um sistema lento e como um relógio!

*/