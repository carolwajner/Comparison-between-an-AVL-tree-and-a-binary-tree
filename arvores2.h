#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declarancao do tipo de informacao
typedef struct TipoInfo
{
    char palavra[64];
    char simplif[64];
} TipoInfo;

// Declaracao estrutura da arvore
typedef struct Nodo
{
    TipoInfo info;
    int FB;
    struct Nodo *esq;
    struct Nodo *dir;
} Nodo;

Nodo* novoNodo();
Nodo* rotacao_direita(Nodo* p);
Nodo* rotacao_esquerda(Nodo *p);
Nodo* rotacao_dupla_direita (Nodo* p);
Nodo* rotacao_dupla_esquerda (Nodo *p);
Nodo* Caso1 (Nodo *a , int *ok);
Nodo* Caso2 (Nodo *a , int *ok);
Nodo* InsereAVL (Nodo *a, TipoInfo x, int *ok);
char *consultaNodo(Nodo *raiz, char *palavra);
int Altura (Nodo *a);


