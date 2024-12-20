#include "arvores2.h"

// VARIAVEIS GLOBAIS
int comptot = 0;
int rotacao = 0;
int nodostot = 0;
int alturaavl = 0;

// Cria nova arvore
Nodo* novoNodo()
{
    return NULL;
}

Nodo* rotacao_direita(Nodo* p) // faz rotacao a direita
{
    Nodo *u;
    u = p->esq;
    p->esq = u->dir;
    u->dir = p;
    p->FB = 0;
    p = u;
    rotacao++;
    return p;
}

Nodo* rotacao_esquerda(Nodo *p) // faz rotacao a esquerda
{
    Nodo *z;
    z = p->dir;
    p->dir = z->esq;
    z->esq = p;
    p->FB = 0;
    p = z;
    rotacao++;
    return p;
}

Nodo* rotacao_dupla_direita (Nodo* p) // faz rotacao dupla a direita
{
    Nodo *u, *v;
    u = p->esq;
    v = u->dir;
    u->dir = v->esq;
    v->esq = u;
    p->esq = v->dir;
    v->dir = p;
    if (v->FB == 1) p->FB = -1;
    else p->FB = 0;
    if (v->FB == -1) u->FB = 1;
    else u->FB = 0;
    p = v;
    rotacao++;
    return p;
}

Nodo* rotacao_dupla_esquerda (Nodo *p) // faz rotacao dupla a esquerda
{
    Nodo *z, *y;
    z = p->dir;
    y = z->esq;
    z->esq = y->dir;
    y->dir = z;
    p->dir = y->esq;
    y->esq = p;
    if (y->FB == -1) p->FB = 1;
    else p->FB = 0;
    if (y->FB == 1) z->FB = -1;
    else z->FB = 0;
    p = y;
    rotacao++;
    return p;
}

Nodo* Caso1 (Nodo *a , int *ok)
{
    Nodo *z;
    z = a->esq;
    if (z->FB == 1)
        a = rotacao_direita(a);

    else
        a = rotacao_dupla_direita(a);

    a->FB = 0;
    *ok = 0;
    return a;
}

Nodo* Caso2 (Nodo *a , int *ok)
{
    Nodo *z;
    z = a->dir;
    if (z->FB == -1)
        a = rotacao_esquerda(a);

    else
        a = rotacao_dupla_esquerda(a);

    a->FB = 0;
    *ok = 0;
    return a;
}

// Insere nodo na arvore em ordem lexicografica
Nodo* InsereAVL (Nodo *a, TipoInfo x, int *ok)
{
    if (a == NULL)  //insere nodo com info requisitada na arvore vazia
    {
        a = (Nodo*) malloc(sizeof(Nodo));
        a->info = x;
        a->esq = NULL;
        a->dir = NULL;
        a->FB = 0;
        *ok = 1;
        nodostot++;
    }

    else
    {
         int comp = strcasecmp(a->info.palavra, x.palavra); // ve se palavra eh maior ou menor que raiz
         if (comp > 0) // se for menor, insere na subarvore esquerda
            {
                a->esq = InsereAVL(a->esq, x, ok);
                if (*ok) 
                {
                    switch (a->FB) 
                    {
                        case -1: a->FB = 0; *ok = 0; break;
                        case 0: a->FB = 1; break;
                        case 1: a=Caso1(a,ok); break;
                    }
                }
            }

            else if (comp < 0) // se for maior, insere na subarvore direita
            {
                a->dir = InsereAVL(a->dir,x,ok);
                if (*ok) 
                {
                    switch (a->FB) 
                    {
                        case 1: a->FB = 0; *ok = 0; break;
                        case 0: a->FB = -1; break;
                        case -1: a = Caso2(a,ok); break;
                    }
                }
            }
    }
    return a;
}

// Consulta se string esta na arvore e retorna sua simplificacao
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
    if (a == NULL)
        return 0;
    else
    {
        Alt_Esq = Altura (a->esq);
        Alt_Dir = Altura (a->dir);
        if (Alt_Esq > Alt_Dir)
            return (1 + Alt_Esq);
        else
            return (1 + Alt_Dir);
    }
}

