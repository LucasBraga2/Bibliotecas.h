#include <stdlib.h>
#include <stdio.h>

typedef int tp_item;

typedef struct tp_no
{
    struct tp_no *esq;
    tp_item info;
    struct tp_no *dir;
} tp_no;

typedef tp_no *tp_arvore;

tp_arvore inicializa_arvore()
{
    return NULL;
}

int arvore_vazia(tp_arvore raiz)
{

    if (raiz == NULL)
        return 1;
    else
        return 0;
}

tp_no *aloca_no() // Aloca e retorna o endereco
{
    tp_no *no;
    no = (tp_no *)malloc(sizeof(tp_no));
    return no;
}

int insere_no(tp_arvore *raiz, tp_item e)
{
    tp_no *pai = NULL, *novo, *p = *raiz; // *p=ponteiro auxiliar
    novo = aloca_no();                    // cria um novo elemento e coloca o endereco
    if (!novo)
        return 0; // Nao alocou

    novo->info = e;
    novo->esq = NULL;
    novo->dir = NULL;

    while (p != NULL)
    { // busca a posicao onde sera inserido o novo no
        pai = p;
        if (e < p->info)
            p = p->esq;
        else
            p = p->dir;
    }
    if (pai != NULL) // Qual ponteiro do pai(esq ou dir) ira apontar para o novo
    {
        if (e < pai->info)
            pai->esq = novo;
        else
            pai->dir = novo;
    }
    else
        *raiz = novo;

    return 1;
}

void pre_ordem(tp_no *p)
{

    if (p != NULL)
    {
        printf("\n%d\n", p->info);
        pre_ordem(p->esq);
        pre_ordem(p->dir);
    }
}

void pos_ordem(tp_no *p)
{

    if (p != NULL)
    {
        pos_ordem(p->esq);
        pos_ordem(p->dir);
        printf("\n%d\n", p->info);
    }
}

tp_no *busca_no(tp_no *p, tp_item e)
{
    
}

int niveis_arvore(tp_arvore raiz)
{
    if (raiz == NULL)
        return 0;
    int nv_esq = niveis_arvore(raiz->esq);
    int nv_dir = niveis_arvore(raiz->dir);
    if (nv_esq > nv_dir)
    {
        return nv_esq + 1;
    }
    else
    {
        return nv_dir + 1;
    }
}

int qtde_nos(tp_arvore raiz)
{
    if (raiz == NULL)
        return 0;
    int tot_esq = qtde_nos(raiz->esq);
    int tot_dir = qtde_nos(raiz->dir);
    return (tot_esq + tot_dir + 1);
}
