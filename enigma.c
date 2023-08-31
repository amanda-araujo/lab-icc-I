//Enigma (exercício dos rotores)
#include <stdio.h>

//3 rotores em sequência, 26 conexões
//sinal >> rotor 1 >> rotor 2 >> rotor 3: msg criptografada

#define n_conexoes 26
#define casas 1

void print_rotor(int *vet_rotor, int size_rotor, char *nome_rotor){
    int i;

    printf("%s = {%d", nome_rotor, vet_rotor[0]);
    for(i = 1; i < size_rotor; ++i){
        printf(", %d", vet_rotor[i]);
    }
    printf("}\n");
}

//Função rodar Rotor 1 casa para esquerda:
/*O segundo rotor só gira uma posição quando o primeiro deu uma volta
completa (andou 26 posições), e o terceiro só gira quando o segundo deu
uma volta completa.*/
    /*
    >>> Esclarescendo: rotor1 gira.
     No instante em que rotor1 retorna a posição inicial, congela, e rotor2 começa a girar. 
     No instante em que rotor2 retorna a posição inicial, congela, e rotor3 começa a girar.
     E quando rotor3 retorna a posição inicial, congela, e rotor1 volta a girar.
     -- recorrência --
    */ 
    /* Acompanhar qual rotor deve girar: 1 2 3
    int (j / n_conexoes) >> ex: j=1, j/26=0 > rotor1 
                                j=26, 1 > rotor2 -- n_conexoes: rotor1 último giro e rotor2 primeiro
                                j=27, 1 > rotor2 
                                j=52, 2 > rotor3 -- 2*n_conexoes: rotor2 último giro e rotor3 primeiro
                                se o resto da divisão for zero: local da mudança

    */

void criptografia(){

}

void giro_esq(int engrenagem[]){
    
    //gira rotor 1 casa para esquerda
    int r[n_conexoes] = {};
        for(int i = 0; i < n_conexoes; i++){
            if(i == n_conexoes - 1){
                r[i] = rotor1[0];
            }
            else{
                r[i] = rotor1[i+casas];
            }
        }
        for(int i = 0; i < n_conexoes; i++){
            rotor1[i] = r[i];
        }
}

void girar_rotor(int j, int rotor1[], int rotor2[], int rotor3[]){

    //até de n_conexoes: só rotor1
    //gira rotor1:
    if(j < n_conexoes){ //até 25
                
        int r[n_conexoes] = {};
        for(int i = 0; i < n_conexoes; i++){
            if(i == n_conexoes - 1){
                r[i] = rotor1[0];
            }
            else{
                r[i] = rotor1[i+1];
            }
        }
        for(int i = 0; i < n_conexoes; i++){
            rotor1[i] = r[i];
        }
    }

    else if(j == n_conexoes){ //26
        int r[n_conexoes] = {};
        for(int i = 0; i < n_conexoes; i++){
            if(i == n_conexoes - 1){
                r[i] = rotor1[0];
            }
            else{
                r[i] = rotor1[i+1];
            }
        }
        for(int i = 0; i < n_conexoes; i++){
            rotor1[i] = r[i];
        }

        //int r[n_conexoes] = {};
        for(int i = 0; i < n_conexoes; i++){
            if(i == n_conexoes - 1){
                r[i] = rotor2[0];
            }
            else{
                r[i] = rotor2[i+1];
            }
        }
        for(int i = 0; i < n_conexoes; i++){
            rotor2[i] = r[i];
        }
    }
    
    //depois de 1 volta completa de rotor1
    //gira rotor2: (juntos! NÃO: ROTOR1 PARADO)
    //j: 26 >> rotor1 retorna ao inicial e rotor2 anda 1
    else if(j < (2*n_conexoes)){//a partir de 27 até 51 
        
        int r[n_conexoes] = {};
        for(int i = 0; i < n_conexoes; i++){
            if(i == n_conexoes - 1){
                r[i] = rotor2[0];
            }
            else{
                r[i] = rotor2[i+1];
            }
        }
        for(int i = 0; i < n_conexoes; i++){
            rotor2[i] = r[i];
        }
    }

    //se já tiver girado todo rotor1 e 2: gira só rotor3 (Todos juntos!)
    else{ 
        int r[n_conexoes] = {};
        for(int i = 0; i < n_conexoes; i++){
            if(i == n_conexoes - 1){
                r[i] = rotor1[0];
            }
            else{
                r[i] = rotor1[i+1];
            }
        }
        for(int i = 0; i < n_conexoes; i++){
            rotor1[i] = r[i];
        }

        //int r[n_conexoes] = {};
        for(int i = 0; i < n_conexoes; i++){
            if(i == n_conexoes - 1){
                r[i] = rotor2[0];
            }
            else{
                r[i] = rotor2[i+1];
            }
        }
        for(int i = 0; i < n_conexoes; i++){
            rotor2[i] = r[i];
        }
        
        //int r[n_conexoes] = {};
        for(int i = 0; i < n_conexoes; i++){
            if(i == n_conexoes - 1){
                r[i] = rotor3[0];
            }
            else{
                r[i] = rotor3[i+1];
            }
        }
        for(int i = 0; i < n_conexoes; i++){
            rotor3[i] = r[i];
        }
    }
}
 
 //erro: letra 27 pra frente não está decodificando corretamente!
 //faltando um giro! >> rotor2
 //até 26 ok! 26 = n_conexoes

int main (void){

    /*Modelo de entrada:
    Rotores:            INÚTIL
    <valores rotor 1>
    <valores rotor 2>
    <valores rotor 3>
                        INÚTIL
    Mensagem:           INÚTIL
    <mensagem>*/

    int rotor1[n_conexoes] = {};
    int rotor2[n_conexoes] = {};
    int rotor3[n_conexoes] = {};
    
    // LEITURA   

    // 1ª linha "Rotores:"
    scanf("%*[^\r\n]s"); // Ignora tudo até o final da linha
    scanf("%*[\r\n]s"); // Ignora o pula linha   
    
    // Ler rotores:
    for (int i = 0; i < n_conexoes; i++){
        scanf("%d", &rotor1[i]);
    }
    for (int i = 0; i < n_conexoes; i++){
        scanf("%d", &rotor2[i]);
    }
    for (int i = 0; i < n_conexoes; i++){
        scanf("%d", &rotor3[i]);
    }

    print_rotor(rotor1, n_conexoes, "rotor1");
    print_rotor(rotor2, n_conexoes, "rotor2");
    print_rotor(rotor3, n_conexoes, "rotor3");

    //Linha vazia:
    scanf("%*[^\r\n]s"); // Ignora tudo até o final da linha
    scanf("%*[\r\n]s"); // Ignora o pula linha
    // "Mensagem:"
    scanf("%*[^\r\n]s"); // Ignora tudo até o final da linha
    scanf("%*[\r\n]s"); // Ignora o pula linha 

    //Mensagem criptografada: <mensage> é um texto cifrado de tamanho arbitrário (ler até EOF). 
    //ler char a char, descriptografar e printar
    char char_cripto;
    
    char alfabeto_minusculas[n_conexoes] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char alfabeto_maiusculas[n_conexoes] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int indice;
    int j = 0 ; //conta quantas voltas já deu para saber qual rotor girar
    
    while (scanf("%c", &char_cripto) != EOF){
        
        int especial = 0;

        //Decodificar:
        for(int i = 0; i < n_conexoes; i++){

            if (char_cripto == alfabeto_minusculas[i]){
                
                indice = rotor3[rotor2[rotor1[i]]];
                
                printf("%c", alfabeto_minusculas[indice]);

                j++;
                //se girar o 3 todo, volta pro 1:
                //if(j == 3*n_conexoes){
                //    j = 0;}

                girar_rotor(j, rotor1, rotor2, rotor3);
                print_rotor(rotor1, n_conexoes, "rotor1");
                print_rotor(rotor2, n_conexoes, "rotor2");
                print_rotor(rotor3, n_conexoes, "rotor3");
                printf("j: %d\n", j);
                    
            }

            else if(char_cripto == alfabeto_maiusculas[i]){
                
                indice = rotor3[rotor2[rotor1[i]]];
                
                printf("%c", alfabeto_maiusculas[indice]);

                j++;
                //se girar o 3 todo, volta pro 1:
                //if(j == 3*n_conexoes){
                //    j = 0;}

                girar_rotor(j, rotor1, rotor2, rotor3);
                print_rotor(rotor1, n_conexoes, "rotor1");
                print_rotor(rotor2, n_conexoes, "rotor2");
                print_rotor(rotor3, n_conexoes, "rotor3");
                printf("j: %d\n", j);
            
            }

            else{
                especial += 1;
            } 
        }

        //caso não encontre equivalência: char especiais !?: se mantém
        if (especial == n_conexoes){ //rodou todos e n encontrou eq >> especial & # $ % ?
            printf("%c", char_cripto);
        }
    }
    
    return 0;
}