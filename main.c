#include"arvoreBB.h"

int main(){

    tp_arvore arvore;

    arvore = inicializa_arvore();

    if(arvore_vazia(arvore)==1){
        printf("Vazia\n");
    }

    insere_no(&arvore, 3);
    insere_no(&arvore, 5);
    insere_no(&arvore, 6);

    pre_ordem(arvore);
    return 0;
}
