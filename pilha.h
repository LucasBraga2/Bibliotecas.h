#ifndef pilha_h
#define pilha_h

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

typedef char
tp_item;

typedef struct {
int topo;
tp_item item[MAX];
} tp_pilha;

void inicializa_pilha(tp_pilha *p){
p->topo = -1;
}

int pilha_vazia(tp_pilha *p){
if (p->topo == -1) return 1;
return 0;
}

int pilha_cheia(tp_pilha *p){
if(p->topo == MAX-1){
return 1;
} else{
return 0;
}
}

int push(tp_pilha *p,tp_item e){
if(pilha_cheia(p) == 1) return 0;
p-> topo++;
p->item[p->topo] = e;
return 1;
}

int pop(tp_pilha *p, tp_item *e){
if (pilha_vazia(p)) return 0;
*e=p->item[p->topo];
p->topo--;
return 1;
}

int top(tp_pilha *p, tp_item *e){
if (pilha_vazia(p)) return 0;
*e=p->item[p->topo];
return 1;
}

void imprime_pilha(tp_pilha p){
tp_item e;
printf("\n");

while (!pilha_vazia(&p)){
    pop(&p, &e);
    printf(" %c ",e);
}
}

int altura_pilha(tp_pilha *p){
return p->topo+1;
}

void retirar_impar(tp_pilha *p){

tp_pilha p_aux;
inicializa_pilha(&p_aux);
tp_item e;

while(!pilha_vazia(p)){
pop(p, &e);
if (e % 2 == 0)
{
push(&p_aux, e);
}

}
while(!pilha_vazia(&p_aux)){
pop(&p_aux, &e);
push(p,e);
}
}

int verificar_igualdade(tp_pilha p1, tp_pilha p2){

tp_item e1, e2;

if(altura_pilha (&p1) != altura_pilha (&p2)) return 0;

while (!pilha_vazia(&p1)){
pop(&p1, &e1);
pop(&p2, &e2);

if(e2 != e1){
    return 0;
}
}

return 1;
}

int empilha_pilha(tp_pilha *p1, tp_pilha *p2){

tp_item e;
tp_pilha p_aux;
inicializa_pilha(&p_aux);

if (altura_pilha(p1) + altura_pilha(p2) > MAX)
{
return 0;
}

while (!pilha_vazia(p2))
{
pop(p2, &e);
push(&p_aux, e);
}

while (!pilha_vazia(&p_aux))
{
pop(&p_aux, &e);
push(p1, e);
}
return 1;
}

#endif
