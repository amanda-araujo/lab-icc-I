#include <stdio.h>
#include <stdlib.h>

#define MAX_POKEMON 10

typedef struct
{
    char Nome[20];
    int Poder;
    float Acuracia;
    char Classe;
} Poder;

typedef struct
{
    int HP;
    int Ataque;
    int Defesa;
    int S_Ataque;
    int S_Defesa;
    int Velocidade;

} Atributos;

typedef struct
{
    char Nome[50];
    char Tipo_Primario[20];
    char Tipo_Secundario[20];
    Atributos Lista_Atributos;
    Poder Lista_Poderes[4];

} Pokemon;

void adiciona_pokemon(Pokemon lista[MAX_POKEMON], int indice);
void adiciona_poder(Pokemon lista[MAX_POKEMON], int indice_pokemon, int indice_poder);
void imprime_pokemon(Pokemon lista[MAX_POKEMON], int indice);
void imprime_poder(Pokemon lista[MAX_POKEMON], int indice_pokemon, int indice_poder);


int main()
{
    int operacao, posicao_pokemon, posicao_poder, num_pokemon = 0;
    Pokemon lista_de_pokemons[MAX_POKEMON];

    scanf("%d", &operacao);

    while (operacao != 0)
    {
        if (operacao == 1)
        {
            adiciona_pokemon(lista_de_pokemons, num_pokemon);
            num_pokemon++;
        }

        if (operacao == 2)
        {
            scanf("%d", &posicao_pokemon);
            scanf("%d", &posicao_poder);
            adiciona_poder(lista_de_pokemons, posicao_pokemon, posicao_poder);
        }

        if (operacao == 3)
        {
            scanf("%d", &posicao_pokemon);
            imprime_pokemon(lista_de_pokemons, posicao_pokemon);
        }

        if (operacao == 4)
        {
            scanf("%d", &posicao_pokemon);
            scanf("%d", &posicao_poder);
            imprime_poder(lista_de_pokemons, posicao_pokemon, posicao_poder);
        }
        

        scanf("%d", &operacao);
    }
}


void adiciona_pokemon(Pokemon lista[MAX_POKEMON], int indice)
{
    scanf("%s", lista[indice].Nome);
    scanf("%s", lista[indice].Tipo_Primario);
    scanf("%s", lista[indice].Tipo_Secundario);


    scanf("%d", &lista[indice].Lista_Atributos.HP);
    scanf("%d", &lista[indice].Lista_Atributos.Ataque);
    scanf("%d", &lista[indice].Lista_Atributos.Defesa);
    scanf("%d", &lista[indice].Lista_Atributos.S_Ataque);
    scanf("%d", &lista[indice].Lista_Atributos.S_Defesa);
    scanf("%d", &lista[indice].Lista_Atributos.Velocidade);
}

void adiciona_poder(Pokemon lista[MAX_POKEMON], int indice_pokemon, int indice_poder)
{
    scanf("%s\n", lista[indice_pokemon].Lista_Poderes[indice_poder].Nome);
    scanf("%d\n", &lista[indice_pokemon].Lista_Poderes[indice_poder].Poder);
    scanf("%f\n", &lista[indice_pokemon].Lista_Poderes[indice_poder].Acuracia);
    scanf("%c\n", &lista[indice_pokemon].Lista_Poderes[indice_poder].Classe);
}

void imprime_pokemon(Pokemon lista[MAX_POKEMON], int indice)
{
    printf("Nome do Pokemon: %s\n", lista[indice].Nome);
    printf("Tipo primario: %s\n", lista[indice].Tipo_Primario);
    printf("Tipo secundario: %s\n", lista[indice].Tipo_Secundario);
    printf("Status:\n");
    printf("\tHP: %d\n", lista[indice].Lista_Atributos.HP);
    printf("\tAtaque: %d\n", lista[indice].Lista_Atributos.Ataque);
    printf("\tDefesa: %d\n", lista[indice].Lista_Atributos.Defesa);
    printf("\tAtaque Especial: %d\n", lista[indice].Lista_Atributos.S_Ataque);
    printf("\tDefesa Especial: %d\n", lista[indice].Lista_Atributos.S_Defesa);
    printf("\tVelocidade: %d\n\n", lista[indice].Lista_Atributos.Velocidade);
}

void imprime_poder(Pokemon lista[MAX_POKEMON], int indice_pokemon, int indice_poder)
{
    printf("Nome do Ataque: %s\n", lista[indice_pokemon].Lista_Poderes[indice_poder].Nome);
    printf("Poder base: %d\n", lista[indice_pokemon].Lista_Poderes[indice_poder].Poder);
    printf("Acuracia: %f\n", lista[indice_pokemon].Lista_Poderes[indice_poder].Acuracia);
    printf("Classe: %c\n\n", lista[indice_pokemon].Lista_Poderes[indice_poder].Classe);
}
