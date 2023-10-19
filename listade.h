#ifndef listad_h
#define listad_h

#include <stdio.h>
#include <stdlib.h>

typedef int tp_item;

// dado estruturado que representa o no da lista
typedef struct tp_no
{
    struct tp_no *ant;
    tp_item info;
    struct tp_no *prox;
} tp_no;

// dado estruturado que representa o descritor
typedef struct
{
    tp_no *ini;
    tp_no *fim;
    // int tamanho;
} tp_listad;

// aloca-se memoria para o descritor
tp_listad *inicializa_listad()
{
    tp_listad *lista = (tp_listad *)malloc(sizeof(tp_listad));
    lista->ini = NULL;
    lista->fim = NULL;
    // lista->tamanho = 0;
    return lista;
}

int listad_vazia(tp_listad *lista)
{
    if (lista->ini == NULL && lista->fim == NULL)
        return 1;
    return 0;
}

// aloca um no na lista
tp_no *aloca()
{
    tp_no *pt;
    pt = (tp_no *)malloc(sizeof(tp_no));
    return pt;
}

// insere um novo no no fim da lista
int insere_listad_no_fim(tp_listad *lista, tp_item e)
{
    tp_no *novo;
    novo = aloca();
    if (!novo)
        return 0;
    novo->info = e;
    if (listad_vazia(lista))
    { // Se for o primeiro no da lista
        novo->prox = NULL;
        novo->ant = NULL;
        lista->ini = lista->fim = novo;
    }
    else
    {
        novo->prox = NULL;
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    // lista->tamanho++;
    return 1;
}

// imprime os conteudos da lista (de frente para tras ou de tras pra frente)
void imprime_listad(tp_listad *lista, int ordem)
{
    if (lista == NULL)
        printf("Lista nao inicializada");
    else
    {
        tp_no *atu;
        switch (ordem)
        {
        case 1:
            atu = lista->ini;
            while (atu != NULL)
            {
                printf("%d ", atu->info);
                atu = atu->prox;
            }
            break;
        case 2:
            atu = lista->fim;
            while (atu != NULL)
            {
                printf("%d ", atu->info);
                atu = atu->ant;
            }
            break;
        default:
            printf("codigo invalido");
        }
    }
    printf("\n");
}

// remove um elemento da lista
int remove_listad(tp_listad *lista, tp_item e)
{
    tp_no *atu;
    atu = lista->ini;
    while ((atu != NULL) && (atu->info != e))
    {
        atu = atu->prox;
    }
    if (atu == NULL)
        return 0;
    if (lista->ini == lista->fim)
    { // Se o for o unico elemento da lista
        lista->ini = lista->fim = NULL;
    }
    else
    {
        if (lista->ini == atu)
        { // Se for o primeiro elemento da lista
            lista->ini = atu->prox;
            atu->prox->ant = NULL;
        }
        else
        {
            if (lista->fim == atu)
            { // se for o ltimo no da lista
                lista->fim = atu->ant;
                atu->ant->prox = NULL;
            }
            else
            {
                atu->prox->ant = atu->ant;
                atu->ant->prox = atu->prox;
            }
        }
    }
    free(atu);
    // lista->tamanho--;
    return 1;
}

// Com base em um conteudo, retorna-se o endereco do no que contem o conteudo
tp_no *busca_listade(tp_listad *lista, tp_item e)
{
    tp_no *atu;
    atu = lista->ini;
    while ((atu != NULL) && (atu->info != e))
    {
        atu = atu->prox;
    }
    return atu;
}
// Retira da memoria todos os nos da lista e tambem o descritor
tp_listad *Destroi_listad(tp_listad *lista)
{
    tp_no *atu;
    atu = lista->ini;
    while (atu != NULL)
    {
        lista->ini = atu->prox;
        free(atu);
        atu = lista->ini;
    }
    free(lista);
    return NULL;
}

#endif
