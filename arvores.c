#include "arvores.h"

// VARIAVEIS GLOBAIS
int comptot = 0;
int nodostot = 0;

// Cria um nodo
Nodo novoNodo()
{
    return (Nodo){"","",NULL,NULL};
}

// Insere nodo na arvore em ordem lexicografica
void insereNodo(Nodo *raiz, Nodo *nodo) 
{
    if (raiz && nodo)
    {
        int comp = strcasecmp(raiz->info.palavra, nodo->info.palavra); // compara strings sem considerar maiusculas e minusculas

        if (comp > 0) // se palavra for menor que raiz
        {
            if (raiz->esq) // se nodo esquerdo nao for nulo
                insereNodo(raiz->esq, nodo); 
            else
            {
                raiz->esq = nodo; // coloca nodo na esquerda
                nodostot++;
            }

        }
        else if (comp < 0) // se palavra for maior que raiz
        {
            if (raiz->dir) // se nodo direito nao for nulo
                insereNodo(raiz->dir, nodo);
            else
            {
                raiz->dir = nodo; // coloca nodo na direita
                nodostot++;
            }        
        }
    }
}

// Consulta se string esta na arvore e retorna sua simplificacao em forma de ponteiro
char *consultaNodo(Nodo *raiz, char *palavra)
{
    int comp;

    while (raiz)
    {
        comp = strcasecmp(raiz->info.palavra, palavra); // compara strings sem considerar maiusculas e minusculas
        comptot++;

        if (comp == 0) // se palavras forem iguais
        {
            comptot++;
            return raiz->info.simplif;
        }  
        else
        {
            comptot++;
            if (comp > 0) // se palavra for menor que raiz
            {
                raiz = raiz->esq;
            }  
            else  // se palavra for maior que raiz
            {
                raiz = raiz->dir;
            }   
        }
    }
    return NULL;
}

int Altura (Nodo *a) // calcula altura da arvore
{
    int Alt_Esq, Alt_Dir;
    if (a == NULL) // se arvore for nula
        return 0;
    else
    {
        Alt_Esq = Altura (a->esq); // calcula altura da subarvore esquerda
        Alt_Dir = Altura (a->dir); // calcula altura da subarvore direita
        if (Alt_Esq > Alt_Dir)
            return (1 + Alt_Esq);
        else
            return (1 + Alt_Dir);
    }
}
