/*
    NAO COPIE ESTE CODIGO
        > Voce vai tirar zero no exercicio por copia!!!
*/

#include <stdio.h>

#define N_CHARS 26

void descarta_linha(){
    scanf("%*[^\r\n]s");
    scanf("%*[\r\n]s");
}

void ler_rotor(int *vet_rotor, int size_rotor){
    int i;

    for(i = 0; i < size_rotor; ++i){
        scanf("%d", &vet_rotor[i]);
    }
}

void print_rotor(int *vet_rotor, int size_rotor, char *nome_rotor){
    int i;

    printf("%s = {%d", nome_rotor, vet_rotor[0]);
    for(i = 1; i < size_rotor; ++i){
        printf(", %d", vet_rotor[i]);
    }
    printf("}\n");
}

int main(void){
    char string[100];
    char msg_char;
    int i;
    int rot1[N_CHARS], rot2[N_CHARS], rot3[N_CHARS];

    /*descarta a linha "Entrada:"*/
    descarta_linha();

    /*descarta a linha "Rotores:"*/
    descarta_linha();

    ler_rotor(rot1, N_CHARS);
    ler_rotor(rot2, N_CHARS);
    ler_rotor(rot3, N_CHARS);

    print_rotor(rot1, N_CHARS, "rotor1");
    print_rotor(rot2, N_CHARS, "rotor2");
    print_rotor(rot3, N_CHARS, "rotor3");

    /*descarta linha vazia + linha "Mensagem:"*/
    descarta_linha();
    descarta_linha();

    //scanf("%[^\n]", string);
    //printf("string = %s\n", string);

    while(scanf("%c", &msg_char) != EOF){
        printf("%c", msg_char);
    }

    return 0;
}
