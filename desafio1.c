#include<stdio.h>
#include <stdlib.h>
 
struct no {
    int info;         
    struct no * prox;
};

struct no * novoNo(int info) {
    struct no * novo = malloc(sizeof(struct no));
    novo->info = info;
    return novo;
}

struct no * insert_first(struct no * lista, int info) {
    struct no *novo = novoNo(info);
    if (!novo) return lista;   // se falhar, mantém a lista como estava
    novo->prox = lista;        // novo aponta para a antiga cabeça
    return novo;               // novo vira a cabeça
}

void insert_last(struct no * lista, int info) {
    struct no *novo = novoNo(info);
    // Precisamos encontrar o último elemento da lista. Quando encontramos, adicionamos o novo!
    struct no *curr = lista;
    while (curr->prox != NULL) {
        curr = curr->prox;
    }
    curr->prox = novo;
}

struct no * remove_first(struct no * lista) {
    if (lista == NULL) return NULL; // lista vazia

    struct no *novo_inicio = lista->prox;
    return novo_inicio;
}



//Implementa a função print_list, que recebe o nó de início da lista e imprime todos os seus valores
void print_list(struct no * lista) {
    struct no * curr = lista;
    while (curr != NULL) {
        if (curr->prox != NULL) 
        printf("%d...aponta para (%d)\n", curr->info, curr->prox->info);
        else
        printf("%d\n", curr->info);
        curr = curr->prox;
    }
}


int main() {
    printf("iniciando");
    struct no * lista = NULL;
    for (int i = 1; i <=20;i++) {
        if (lista == NULL) {
            lista = insert_first(lista, i);
        } else {
            insert_last(lista, i);
        }
    }
    print_list(lista);


    return 0;
}