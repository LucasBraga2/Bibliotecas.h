#include <stdlib.h>
#include <stdio.h>

typedef int tp_item;

typedef struct tp_no
{
    struct tp_no *esq;
    tp_item info;
    struct tp_no *dir;

} tp_no;

typedef tp_no *tp_arvore; // ponteiro de tp no

tp_arvore inicializa_arvore() // tp_arvore = inicializa_arvore
{
    return NULL;
}

int arvore_vazia(tp_arvore raiz)
{
    if (raiz == NULL)
        return 1; // ta vazia
    else
        return 0;
}

tp_no *aloca_no() // aloca e retorna o endereço
{
    tp_no *no;
    no = (tp_no *)malloc(sizeof(tp_no));
    return no;
}

int insere_no(tp_arvore *raiz, tp_item e)
{
    tp_no *pai = NULL, *novo, *p = *raiz; //*p=ponteiro auxiliar (ponteiro de ponteiro)
    novo = aloca_no();                    // cria um novo elemento e coloca o endereço de memoria
    if (!novo)
        return 0; // impossivel alocar (novo==NULL)

    novo->info = e;
    novo->esq = NULL;
    novo->dir = NULL;

    while (p != NULL)
    { // busca a posição onde será iniciado o novo no

        pai = p;
        if (e < p->info)
            p = p->esq;
        else
            p = p->dir;
    }
    if (pai != NULL) // qual ponteiro do pai (esq ou dir) irá apontar para o novo
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

void pre_ordem(tp_no *p) // imprime os elementos em pre ordem
{
    if (p != NULL)
    {
        printf("\n%d\n", p->info);
        pre_ordem(p->esq);
        pre_ordem(p->dir);
    }
}

void em_ordem(tp_no *p) // imprime os elementos em ordem
{
    if (p != NULL)
    {
        em_ordem(p->esq);
        printf("\n%d\n", p->info);
        em_ordem(p->dir);
    }
}

void pos_ordem(tp_no *p) // imprime os elementos em pos ordem
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
    while (p != NULL)
    {
        if (e < p->info)
            p = p->esq;
        else if (e > p->info)
            p = p->dir;
        else
            return (p);
    };
    return (NULL);
}

tp_arvore busca_no_rec(tp_arvore p, tp_item e)
{
    if (p != NULL)
    {
        if (e < p->info)
            return busca_no_rec(p->esq, e);
        else if (e > p->info)
            return busca_no_rec(p->dir, e);
        else
            return (p);
    }
    else
        return (NULL);
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
int remove_no(tp_arvore *raiz, tp_item e)
{
    tp_no *p = *raiz, *ant = NULL, *sub, *pai, *filho; // sub é o substituto

    while (p != NULL && p->info != e)
    {
        ant = p;

        if (e < p->info)
            p = p->esq;

        else
            p = p->dir;
    }
    if (p == NULL) // n encontrou
        return 0;

    // no tem no maximo um filho
    if (p->esq == NULL)
        sub = p->dir;
    else if (p->dir == NULL)
        sub = p->esq;
    else
    { // no tem dois filhos
        pai = p;
        sub = p->dir;
        filho = sub->esq;

        while (filho != NULL)
        {
            pai = sub;
            sub = filho;
            filho = sub->esq;
        }
        // nesse ponto, sub é o sucessor em ordem de p;
    }
    if (pai != p)
    { // p não é o pai desub e sub == pai->esq

        pai->esq = sub->dir;
        /* remove o no apontado por sub de sua atual
        posição e substitui pelo filho direito de p.
        sub ocupa o lugar de p */
        sub->dir = p->dir;
    }
    sub->esq = p->esq; /*define filho esq de sub para que sub ocupe o lugar de p */
                       /* insere sub na posição ocupada por p */
    if (ant == NULL)
        *raiz = sub; /* p era raiz */
    else if (p == ant->esq)
        ant->esq = sub;
    else
    {
        ant->dir = sub;
        free(p);
        return 1;
    }
}

void destroi_no(tp_no *no)
{
    if (no == NULL)
        return;
    destroi_no(no->esq);
    destroi_no(no->dir); // printf("\n %d ", no->info);

    free(no);
    no = NULL;
    return;
}

void destroi_arvore(tp_arvore *raiz)
{
    if (*raiz == NULL)
        return;
    destroi_no(*raiz);
    // free(*raiz);
    *raiz = NULL;
}
