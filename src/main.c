#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia, mes, ano;
} Data;

typedef struct {
    char nome[50];
    Data data;
} Pessoa;

typedef struct no {
    Pessoa p;
    struct no *prox;
} No;

Pessoa LerPessoas() {
    Pessoa p;
    printf("\nDigite nome e data de nascimento dd mm aaaa:\n");
    scanf("%49[^\n] %d %d %d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

void ImprimirPessoa(Pessoa p) {
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

No* push(No *topo) {

    No *novo = malloc(sizeof(No));

    if(novo) {
        novo->p = LerPessoas();
        novo->prox = topo;
        return novo;
    } else {
        printf("Erro ao alocar memoria...\n");
    }
        
    return NULL;
    
}

No* pop(No **topo) {
    if( *topo != NULL ) {

        No *remover = *topo;
        *topo = remover->prox;
        return remover;

    } else {
        printf("Pilha ja esta vazia! ");
    } 
        
        return NULL;
}

void ImprimirPilha(No *topo) {
    printf("\n----------- PILHA -----------\n");
        while(topo) {
            ImprimirPessoa(topo->p);
            topo = topo->prox;
        }
    printf("\n----------- FIM PILHA -----------\n");
}

int main(int argc, char const *argv[]) {
    
    No *remover, *topo = NULL;
    int opcao = -1;

    do {
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                topo = push(topo);
                break;
            case 2:
                remover = pop(&topo);
                if(remover) {
                    printf("\nElemento Removido com sucesso:");
                    ImprimirPessoa(remover->p);
                    free(remover);
                } 
                break;
            case 3:
                ImprimirPilha(topo);
                break;
        }

    } while(opcao!=0);

    while (topo != NULL) {
    No *temp = topo;
    topo = topo->prox;
    free(temp);
    }

    return 0;
}
