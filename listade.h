#ifndef listad_h
#define listad_h

#include <stdio.h>
#include <stdlib.h>

typedef int tp_item;

//dado estruturado que representa o no da lista
typedef struct tp_no{
    struct tp_no *ant;
    tp_item info;
    struct tp_no *prox;
} tp_no;

//dado estruturado que representa o descritor
typedef struct{
    tp_no *ini;
    tp_no *fim;
    //int tamanho;
} tp_listad;

//aloca-se memoria para o descritor
tp_listad *inicializa_listad(){
    tp_listad *lista=(tp_listad*) malloc(sizeof(tp_listad));
    lista->ini = NULL;
    lista->fim = NULL;
    //lista->tamanho = 0;
    return lista;
}

int listad_vazia(tp_listad *lista){
    if (lista->ini==NULL && lista->fim == NULL) return 1;
     return 0;
}

//aloca um no na lista
tp_no *aloca(){
    tp_no *pt;
    pt = (tp_no*) malloc(sizeof(tp_no));
    return pt;
}

//insere um novo no no fim da lista
int insere_listad_no_fim (tp_listad *lista, tp_item e){
    tp_no *novo;
    novo=aloca();
    if (!novo) return 0;
    novo->info = e;
    if(listad_vazia(lista)){//Se for o primeiro no da lista
        novo->prox = NULL;
        novo->ant = NULL;
        lista->ini = lista->fim = novo;
}
else{
    novo->prox = NULL;
    novo->ant = lista->fim;
    lista->fim->prox = novo;
    lista->fim = novo;
}
//lista->tamanho++;
return 1;
}

//remove um elemento da lista
int remove_listad(tp_listad *lista, tp_item e){
    tp_no *atu;
    atu = lista->ini;
    while((atu!=NULL) && (atu->info !=e) ){
        atu= atu->prox;
    if((atu==NULL)) return 0;
    if(lista->ini == lista->fim){//Se for o unico elemento da lista
        lista->ini = lista-> = NULL;}
        else{}
    }

}


#endif
