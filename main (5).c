#include "arvores2.h"

// VARIAVEIS GLOBAIS
extern int comptot;
extern int rotacao;
extern int nodostot;
extern int alturaavl;

int main(int argc, char **argv)
{     
    int ok = 0;
    FILE *dict = fopen(argv[1], "r"); // abre arquivo do dicionario
    TipoInfo auxinfo = {"", ""};

  // cria nodo raiz e insere primeira palavra do arquivo
    Nodo* raiz = novoNodo(); 
    fscanf(dict, "%s", auxinfo.palavra);
    fgets(auxinfo.simplif, 63, dict);
  
    raiz = InsereAVL(raiz, auxinfo, &ok);

    while (!feof(dict)) // insere as demais palavras do arquivo na arvore
    {
          if (fscanf(dict, "%s", auxinfo.palavra))
          {
              fgets(auxinfo.simplif, 63, dict);
              raiz = InsereAVL(raiz, auxinfo, &ok);
         }
         else
         {
            break;
         }
    }

    fclose(dict);
  
    FILE *texto;
    texto = fopen(argv[2], "r"); // abre arquivo de texto

    FILE *novo_texto = fopen(argv[3], "w"); // abre arquivo de texto novo

    char palavra_temp[64];
    char *simplif_temp;

    while (fscanf(texto, "%s", palavra_temp) && !feof(texto)) // consulta se palavras do texto estao no dicionario e se sim, as troca pela simplificacao
    {
        simplif_temp = consultaNodo(raiz, palavra_temp);

        if (simplif_temp)
          fprintf(novo_texto, "%s ", simplif_temp);
        else
          fprintf(novo_texto, "%s ", palavra_temp);
    }

    fclose(texto);
    fclose(novo_texto);

    alturaavl = Altura(raiz); // calcula altura da arvore
    
    printf("Numero de comparacoes: %d\n", comptot);
    printf("Numero de rotacao: %d\n", rotacao);
    printf("Numero de nos: %d\n", nodostot);
    printf("Altura da arvore: %d\n", alturaavl);

    return 0;
}
