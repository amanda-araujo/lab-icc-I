#include <stdio.h>

int main(){

    //Criando struct:
    struct ficha_de_aluno
    {
        char id[10];
        char nome[50];
        char curso[50];
        int idade;
    };

    //Criando variável aluno que será do tipo struct ficha_de_aluno:
    struct ficha_de_aluno aluno;
    
    //LEITURA
    //Ler n registros até que o usuário forneça -1:

    //Opa! Provavelmente teremos um vetor de struct: vários alunos
    
    fflush(stdin);

    //Comando fgets() para ler strings:
    fgets();
    

    return 0;
}