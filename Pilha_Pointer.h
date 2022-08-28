/* Pilha de pointer */

#define Max 20
typedef struct {
        void * apont;
        int item;
}Casa;

typedef struct {
      int topo;
      Casa tabela[Max];
} Pilha;

//protótipos
void criarPilhaVazia(Pilha *);
void *acessarTopo(Pilha *);
int verificarPilhaVazia(Pilha *);
int verificarPilhaCheia(Pilha *);
void pushPilha(Pilha *, void *);
void popPilha(Pilha *);

// implementações
void criarPilhaVazia(Pilha *a){
    a->topo = 0;
}

void *acessarTopo(Pilha *a){
    int k;
    void *t;

    if (a->topo != 0){
    	k = a->topo - 1;
    	t = a->tabela[k].apont;	
	}else{
        t = 0; //NULL
    } 
    return t;
}     

int verificarPilhaVazia(Pilha *a){
    int vazia;

    if (a->topo == 0){
        vazia = 1;
    }  else{
        vazia = 0;
    } 
    return vazia;
}

int verificarPilhaCheia(Pilha *a){
    int cheia;
    if (a->topo == Max){
        cheia = 1; 
    } else{
        cheia = 0;
    } 
    return cheia;
}

void pushPilha(Pilha *a, void *novo){
    int k;
    k = a->topo;
    if (a->topo < Max) {
     	a->tabela[k].item = 0;
     	a->tabela[k].apont = novo;
     	a->topo = k + 1;
	}
}

void popPilha(Pilha *a){
    int k;
    k = a->topo;
    if (a->topo != 0){
     	a->topo = k-1;
 	}
}

