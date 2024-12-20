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

    struct Nodo *esq;
    struct Nodo *dir;
} Nodo;

Nodo novoNodo();
void insereNodo(Nodo *raiz, Nodo *nodo);
char *consultaNodo(Nodo *raiz, char *palavra);
int Altura (Nodo *a);



