#include "arvores.h"

// VARIAVEIS GLOBAIS
extern int comptot;
extern int nodostot;

int main(int argc, char **argv)
{    
    int alturaabp;
    FILE *dict = fopen(argv[1], "r"); // abre arquivo de dicionario

    Nodo raiz = novoNodo();
    fscanf(dict, "%s", raiz.info.palavra); // coloca primeira palavra do dicionario na raiz
    fgets(raiz.info.simplif, 63, dict);
    nodostot++;

    while (!feof(dict))
    {
        Nodo *novo_nodo = (Nodo *)malloc(sizeof(Nodo));
        *novo_nodo = novoNodo();

        if (fscanf(dict, "%s", novo_nodo->info.palavra)) // escaneia palavras do dicionario e as insere na arvore
        {
            fgets(novo_nodo->info.simplif, 63, dict);
            insereNodo(&raiz, novo_nodo);
        }
        else
        {
            free(novo_nodo);
            break;
        }
    }

    fclose(dict);

    alturaabp = Altura(&raiz); // calcula altura da arvore

    FILE *texto;
    texto = fopen(argv[2], "r"); // abre arquivo de texto

    FILE *novo_texto = fopen(argv[3], "w"); // abre arquivo de texto novo

    char palavra_temp[64];
    char *simplif_temp;

    while (fscanf(texto, "%s", palavra_temp) && !feof(texto)) // consulta se palavras do texto estao no dicionario e se sim, as troca pela simplificacao
    {
        simplif_temp = consultaNodo(&raiz, palavra_temp);

        if (simplif_temp)
          fprintf(novo_texto, "%s ", simplif_temp);
        else
            fprintf(novo_texto, "%s ", palavra_temp);
        
          
        
    }

    fclose(texto);
    fclose(novo_texto);
    
    printf("Numero de comparacoes: %d\n", comptot);
    printf("Numero de rotacao: 0\n");
    printf("Numero de nos: %d\n", nodostot);
    printf("Altura da arvore: %d\n", alturaabp);

    return 0;
}
