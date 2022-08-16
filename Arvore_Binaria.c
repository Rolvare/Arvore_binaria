/*  
  Arquivo: Arvore_Binaria
  Autor: LUCCA ROLVARE
  Date: 15/08/22 17:21
  Descricao: Esse é um programa da arvore binaria.
*/

#include<stdio.h>
#include<stdlib.h>
#include "Fila.h"
#include "Booleano.h"

typedef struct No{
    int elemento;
    struct No *esq;
    struct No *dir;
} No;

typedef No *Arvore;

//interface
Arvore criarArvoreVazia();
Arvore construirArvore(int, Arvore, Arvore);
void mostrarArvore(Arvore);
void mostrarX(Arvore);

int obterAltura(Arvore);
int contarNos(Arvore);
int contarFolhas(Arvore);
Arvore insereFolha(Arvore, int);
No* buscar(Arvore, int);

int main(){
    /*
    Arvore a, b, c, d, e;
    a= criarArvoreVazia();
    b= criarArvoreVazia();
    c= construirArvore(3, a, b);  //(3, NULL, NULL);
    d= construirArvore(4, a, b);
    e= construirArvore(7, c, d);
    c= construirArvore(1, a, b);
    d= construirArvore(2, a, b);  

    //mostrarArvore(a);
    */
}

//implementacao

Arvore criarArvoreVazia(){
    Arvore ap;
    ap = NULL;

    return ap;
}

Arvore construirArvore(int y, Arvore a1, Arvore a2){
    Arvore a3;
    a3 = malloc(sizeof(No));

    a3->elemento = y;
    a3->esq = a1;
    a3->dir = a2;

    return a3;
}

void mostrarArvore(Arvore ap){ //caminhamento eRd
    
    if(ap != NULL){
        mostrarArvore(ap->esq);
        printf("\n %d \n", ap->elemento);
        mostrarArvore(ap->dir);
    }
}

/*
void mostrarArvore(Arvore ap){ //caminhamento Red
    if(ap != NULL){
        printf("\n %d \n", ap->elemento);
        mostrarArvore(ap->esq);
        mostrarArvore(ap->dir);
    }
}
*/

/*
void mostrarArvore(Arvore ap) { //caminhamento edR
    
    if(ap != NULL){
        mostrarArvore(ap->esq);
        mostrarArvore(ap->dir);
        printf("\n %d \n", ap->elemento);
    }
}
*/

/*
void mostrarArvore(Arvore ap){  //caminhamento por nivel
    No *, Fila f;
    if(ap ==NULL){
        printf("\n arvore vazia \n");
    }else{
        criarFilaVazia(&f);
        p = ap;
        pushFila(&f, p);

        do{
            p = acessarFila(&f);
            printf("\n %d \n", p->elemento);
            popFila(&f);
            if(p->esq != NULL) pushFila(&f, p->esq);
            if(p->dir != NULL) pushFila(&f, p->dir);
        }while(verFilaVazia(&f) == FALSE);           //(FilaVazia(&f) == FALSE);
    }
}
*/

void mostrarX(Arvore ap){  //mostrarX (a)
    No *p;
    if (ap == NULL){
        printf("\n arvore vazia \n");
    }else{
        p = ap;
        while(p->esq != NULL ){
            p = p->esq;
            printf("\n %d \n", p->elemento);        }
    }
}

int obterAltura (Arvore r){  //r = raiz
    int he, hd;  //h = height

    if(r != NULL){
        he = obterAltura(r->esq);
        hd = obterAltura(r->dir);
    }
    return 1 + he + hd;
}

int contarNos(Arvore ap){
    if(ap == NULL){
        printf("\n numero de nos e igual a zero \n");
    }else{
        contarNos(ap->esq) + contarNos(ap->dir) + 1;
    }
}

int contarFolhas(Arvore ap){
    int qtd;

    if(ap == NULL){
        qtd = contarFolhas(ap);
        qtd = 0;

    } else if((ap->esq == NULL) && (ap->dir == NULL)){
        qtd = 1;
    }else {
        contarFolhas(ap->esq) + contarFolhas(ap->dir);
    }
}

/*
No* buscar(Arvore ap, int y){
    int a, raiz, p;
    Fila S;

    if(ap != -1){
        a = raiz;
        criarFila(S);
        insereFolha(S, a);

        do{
            p = acessarFila(S);
            if(p==y)
        }
    }
}
*/

Arvore insereFolha(Arvore ap, int v){  //v = valor

    if(ap == NULL){
        ap = (Arvore*)malloc(sizeof(No));
        ap->elemento = v;
        ap->esq = NULL;
        ap->dir = NULL;

    }else if( v < ap->elemento){
        ap->esq = insereFolha(ap->esq, v);

    }else {                                   //else if (v > a->elemento) 
        ap->dir = insereFolha(ap->dir, v);    //v >= ap->elemento
    }
    return ap;
}


Arvore removeFolha(Arvore ap, int v){;
    Arvore y, z;
    if(ap == NULL){
        printf("\n arvore vazia \n");
    }else{
        if(ap->elemento > v){  
            ap->esq = removeFolha(ap->esq, v);

        }else if(ap->elemento < v){     
            ap->dir = removeFolha(ap->dir, v);

        }else{      // achou o no a remover
                    // no sem filhos
            if((ap->esq == NULL) && ap->dir == NULL){
                free(ap);
                ap = NULL;
            }else if (ap->esq == NULL) { //no so tem filho a direita
                y = ap;
                ap = ap->dir;
                free(y);
            }else if(ap->dir == NULL){  //no so tem filho a esquerda
                y = ap;
                ap = ap->esq;
                free(y);
            }else {             //no tem dois filhos
                z = ap->esq;

                while(z->dir != NULL){
                    z = z->dir;
                }
                ap->elemento = z->elemento;  //troca as informacoes
                z->elemento = v;
                ap->esq = removerFolha(ap->esq, v);
            }
        }
    }
    return ap;
}
