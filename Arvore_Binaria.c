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
}/*  
  Arquivo: Arvore_Binaria
  Autor: LUCCA ROLVARE
  Date: 15/08/22 17:21
  Descricao: Esse é um programa da arvore binaria.
*/

#include<stdio.h>
#include<stdlib.h>
#include "Fila_Pointer.h"
#include "Pilha_Pointer.h"
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
void mostrarArvore(Arvore);     //recursivo
void mostrarArvoreNR(Arvore);   //nao recursivo
void mostrarX(Arvore);
void mostrarRaiz(Arvore);
void mostrarPrimeiro(Arvore); //caminhamento eRd
void mostrarUltimo(Arvore);   //caminhamento eRd
bool verificarArvoreVazia(Arvore);

int obterAltura(Arvore);
int contarNos(Arvore);
int contarFolhas(Arvore);
Arvore insereFolha(Arvore, int);
Arvore construirArvoreRam(int); //constroi arvore perfeitamente balanceada
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

Arvore construirArvore(int item, Arvore a1, Arvore a2){
    No *novo, *raiz;
    novo = (struct No*)malloc(sizeof(struct No));

    novo->elemento = item;
    novo->esq = a1;
    novo->dir = a2;
    raiz = novo;

    return raiz;
}

bool verificarArvoreVazia(Arvore ap){
    bool ok;
    if(ap == NULL){
        ok = TRUE;
    }else{
        ok = FALSE;
    }

    return ok;
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

void mostrarArvoreNR(Arvore ap){
    Pilha s;
    No *p;
    bool fim;

    if(ap != NULL){
        criarPilha(&s); 
        fim = FALSE;
        p = ap;

        do{
            while (p != NULL){
                pushPilha(&s, p);
                p = p->esq;
            }
            if(pilhaVazia(&s) == FALSE){
                p = acessarTopo(&s);
                printf("\n %d \n", p->elemento);
                popPilha(&s);
                p = p->dir;
            }else{
                fim = TRUE;
            }
        }while(fim == FALSE);
    }else{
        printf("\n arvore vazia \n");
    }
}

void mostrarX(Arvore ap){  //mostrarX (a)
    No *p;
    
    if (ap == NULL){
        printf("\n arvore vazia \n");
    }else{
        p = ap;
        while(p->esq != NULL ){
            p = p->esq;
            printf("\n %d \n", p->elemento);        
        }
    }
}

void mostrarPrimeiro(Arvore ap){
    No *p;

    if(ap == NULL){
        printf("\n arvore vazia");
    }else{
        p = ap;
        while(p->esq != NULL){  //existe o filho esquerdo?
            p = p->esq;
            printf("\n primeiro eRd = %d \n", p->elemento);
        }
    }
}

void mostrarUltimo(Arvore ap){
    No *p;

    if(ap == NULL){
        printf("\n arvore vazia\n");
    }else{
        p = ap;
        while(p->dir != NULL){  //existe o filho direito?
            p = p->dir;
            printf("\n primeiro eRd = %d \n", p->elemento);
        }
    }
}

void mostrarRaiz(Arvore ap){
    if(ap != NULL){
        printf("  %d  \n", ap->elemento);
    }
}

int obterAltura (Arvore r){  //r = raiz
    int h, he, hd;  //h = height

    if(r == NULL){  //caso de base
        r = -1;

    }else{          //caso recursivo
        he = obterAltura(r->esq);
        hd = obterAltura(r->dir);

        if(he > hd){
            h = he + 1;
        }else{
            h = hd + 1;
        }
    }
    return h;
}

int contarNos(Arvore ap){
    int cont, sae, sad; //sae = sub arvore esquerda | sad = sub arvore direita 

    if(ap == NULL){
        cont = 0;
    }else{
        sae = contarNos(ap->esq); 
        sad = contarNos(ap->dir);
        cont = sae + sad + 1;
    }
    return cont;
}

int contarFolhas(Arvore r){ //r = raiz
    int sae, sad, qtd;    //quantidade de folhas;

    if(r == NULL){
        qtd = 0;

    } else if((r->esq == NULL) && (r->dir == NULL)){
        qtd = 1;
    }else {
        sae = contarFolhas(r->esq);  
        sad =contarFolhas(r->dir);
        qtd = sae + sad;
    }
    return qtd;
}

/*
No* buscar(Arvore ap, int y){
    No *p;
    int a, e, d, raiz;
    bool achou = TRUE;
    Fila *S;

    if(ap != -1){
        a = raiz;
        criarFila(S);
        pushFila(S, a);

        do{
            p = acessarFila(S);
            if(&p==y){
                achou;
            }else{
                popFila(S);
                e = p->esq;
                d = p->dir;

                if(e != NULL){
                    pushFila(S, e);

                }else if(d != NULL) {
                    pushFila(S, d);
                }
            }
        }while((S == NULL) || (achou));
    }
}
*/

No* buscar(Arvore ap, int valor) {
    No *p;

    if(ap == NULL){
        p = NULL;
    }else if(ap->elemento == valor){
        p = ap;
    }else{
        p = buscar(ap->esq, valor);
        
        if(p == NULL){
            p = buscar(ap->dir, valor);
        }
    }
    return p;
}

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
    int cont;
    if(ap == NULL){
        //cont->ap = 0;
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
