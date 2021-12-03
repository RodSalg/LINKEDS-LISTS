#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo tipoNo;
typedef struct tipoAluno{
    char nome[30];
    int idade;
}tipoAluno;

typedef struct tipoNo{
    tipoAluno info;
    tipoNo *prox;
}tipoNo;


typedef struct tipoLista{
    tipoNo* prim;

}tipoLista;


tipoLista* criarLista(){
    tipoLista *l;
    l = malloc(sizeof(tipoLista));
    l->prim = NULL;

    return l;

}

void mostrarInfo(tipoAluno a){
    printf("nome: %s, idade: %d\n", a.nome, a.idade);
}

void inserirLista(tipoLista *l, tipoAluno a){ //insere no inicio da lista
    tipoNo* no;
    no = (tipoNo*)malloc(sizeof(tipoNo));
    no->info = a;
    no->prox = l->prim;
    l->prim = no;

}

void inserirFinalLista(tipoLista *l, tipoAluno a){ //insere no final da lista

    tipoNo* no;
    no = (tipoNo*)malloc(sizeof(tipoNo));
    no->info = a;
    no->prox = NULL;

    if(l->prim == NULL){
        l->prim = no;
    }else{
        tipoNo *aux = l->prim;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;

    }

    

}

void mostrarLista2(tipoLista *l){//com ponteiro{
    tipoNo *aux = l->prim;
    while(aux){
        mostrarInfo(aux->info);
        aux = aux->prox;
    }
}
void mostrarLista(tipoLista l){ //sem ponteiro
    
    while(l.prim){
        mostrarInfo(l.prim->info);
        l.prim = l.prim->prox;
    }
}

tipoAluno *buscarLista(tipoLista l, int chave){
    
    while(l.prim){
        if(l.prim->info.idade == chave){ //nesse caso estou comparado a info.a.idade
            return &l.prim->info; 
        }
        l.prim = l.prim->prox;
    }

    return NULL;
}


int removerLista(tipoLista *l, int chave){
    tipoNo *aux;
    tipoNo *ant;
    if(l->prim){
        aux = l->prim;
        if(l->prim->info.idade == chave){
            l->prim = aux->prox;
            free(aux);
            return 1;
        }else{
            ant = aux;
            aux = aux->prox;
            while(aux){ //preciso armazenar o elemento antes do aux
                if(aux->info.idade == chave){
                    //printf("achei esse: %d\n", aux->info.idade);
                    ant->prox = aux->prox;
                    free(aux);
                    return 1;    
                }
            }
        }
    }

    return 0;
}



int main(){

    
    tipoLista *lista;
    tipoAluno a;

    lista = criarLista();
    

    for(int i = 0; i < 3; i++){
        scanf("%s", &a.nome);
        a.idade = i;
        inserirFinalLista(lista, a);
    }

    printf("\n\n");
    mostrarLista(*lista);
    printf("\n\n");
    removerLista(lista, 2);
    //printf("removi? reposta: %d\n", removerLista(lista, 2));
    mostrarLista(*lista);
    printf("\n\n");
    


    
    





    return 0;
}