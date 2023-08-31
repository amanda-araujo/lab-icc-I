#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    size_t tamanho[4];
    char nusp[8];
    char nome[100];
    char curso[100];
    char idade[2];
} Aluno;


size_t get_string(char string[100]);
void adiciona_aluno(Aluno lista_aluno[30], Aluno aluno, size_t tam_lista);
void imprime_aluno(Aluno lista_aluno[30], size_t pos_aluno);

int main()
{
    int tam_linha;
    size_t tam_lista = 0;
    char linha[100] = {}, consulta = '0';
    Aluno lista_de_alunos[30];

    tam_linha = get_string(linha);
    while (consulta != '4')
    {
        if (consulta == '0')
        {
            Aluno cadastro = {};

            // Lendo registros
            cadastro.tamanho[0] = tam_linha;
            for (int i = 0; i < tam_linha; i++)
            {
              cadastro.nusp[i] = linha[i];
            }

            tam_linha = get_string(linha);
            cadastro.tamanho[1] = tam_linha;
            for (int i = 0; i < tam_linha; i++)
            {
              cadastro.nome[i] = linha[i];
            }

            tam_linha = get_string(linha);
            cadastro.tamanho[2] = tam_linha;
            for (int i = 0; i < tam_linha; i++)
            {
              cadastro.curso[i] = linha[i];
            }

            tam_linha = get_string(linha);
            cadastro.tamanho[3] = tam_linha;
            for (int i = 0; i < tam_linha; i++)
            {
              cadastro.idade[i] = linha[i];
            }


            tam_lista++;
            
            adiciona_aluno(lista_de_alunos, cadastro, tam_lista);

            tam_linha = get_string(linha);
        }


        // Operacao 1
        if (consulta == '1')
        {
            tam_linha = get_string(linha);
            
            for (int i = 0; i < tam_lista; i++)
            {
                int j = 0, teste_nusp = 1;
                while (teste_nusp == 1 && j < tam_linha)
                {
                    if (linha[j] != lista_de_alunos[i].nusp[j])
                    {
                        teste_nusp = 0;
                    }

                    j++;
                }

                if (teste_nusp == 1)
                {
                    imprime_aluno(lista_de_alunos, i);
                }
            }
            
            tam_linha = get_string(linha);
            consulta = linha[0];
        }


        // Operacao 2
        if (consulta == '2')
        {
            tam_linha = get_string(linha);
            
            for (int i = 0; i < tam_lista; i++)
            {
                int j = 0, teste_curso = 1;
                while (teste_curso == 1 && j < tam_linha)
                {
                    if (linha[j] != lista_de_alunos[i].curso[j])
                    {
                        teste_curso = 0;
                    }

                    j++;
                }

                if (teste_curso == 1)
                {
                    imprime_aluno(lista_de_alunos, i);
                }
            }
            
            tam_linha = get_string(linha);
            consulta = linha[0];
        }


        // Operacao 3
        if (consulta == '3')
        {
            for (int i = 0; i < tam_lista; i++)
            {
                imprime_aluno(lista_de_alunos, i);
            }
            
            tam_linha = get_string(linha);
            consulta = linha[0];
        }


        // Operação -1 assim que termina o cadastro
        if (linha[0] == '-' && consulta == '0')
        {
            tam_linha = get_string(linha);
            consulta = linha[0];
        }

        // Operação -1 assim que termina o arquivo
        if(linha[0] == '-' && consulta != '0')
        {
            consulta = '4';
        }
    }

    return 0;
}


size_t get_string(char string[100])
{
    char charac;
    
    scanf("%c", &charac);

    size_t i_charac = 0;
    while (charac != '\n')
    {
        string[i_charac] = charac;
        i_charac++;
        scanf("%c", &charac);
    }

    return i_charac;
}

void adiciona_aluno(Aluno lista_aluno[30], Aluno aluno, size_t tam_lista)
{
    lista_aluno[tam_lista-1] = aluno;
}


void imprime_aluno(Aluno lista_aluno[30], size_t pos_aluno)
{
    printf("Nome: %s\n", lista_aluno[pos_aluno].nome);
    printf("Curso: %s\n", lista_aluno[pos_aluno].curso);
    printf("N USP: %s\n", lista_aluno[pos_aluno].nusp);
    printf("IDADE: %s\n\n", lista_aluno[pos_aluno].idade);
}
