#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ESTRUTURAS DE DADOS

// Estrutura de item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Estrutura do nó (lista encadeada)
typedef struct No {
    Item dados;
    struct No* prox;
} No;

// VARIÁVEIS GLOBAIS
#define TAM 10
Item mochilaVetor[TAM];
int totalItensVetor = 0;
No* inicioLista = NULL;

// Contadores de comparações
int comparacoesSequencial = 0;
int comparacoesBinaria = 0;

// FUNÇÕES PARA O VETOR

// Inserir item no vetor
void inserirItemVetor() {
    if (totalItensVetor >= TAM) {
        printf("Mochila cheia!\n");
        return;
    }
    Item novo;
    printf("Digite o nome do item: ");
    scanf("%s", novo.nome);
    printf("Digite o tipo do item: ");
    scanf("%s", novo.tipo);
    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);

    mochilaVetor[totalItensVetor] = novo;
    totalItensVetor++;
    printf("Item adicionado com sucesso!\n");
}

// Listar itens do vetor
void listarItensVetor() {
    if (totalItensVetor == 0) {
        printf("Mochila vazia.\n");
        return;
    }
    printf("----- Itens na Mochila (Vetor) -----\n");
    for (int i = 0; i < totalItensVetor; i++) {
        printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochilaVetor[i].nome, mochilaVetor[i].tipo, mochilaVetor[i].quantidade);
    }
    printf("-----------------------------------\n");
}

// Remover item do vetor
void removerItemVetor() {
    if (totalItensVetor == 0) {
        printf("Mochila vazia.\n");
        return;
    }
    char nome[30];
    printf("Digite o nome do item para remover: ");
    scanf("%s", nome);

    for (int i = 0; i < totalItensVetor; i++) {
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            for (int j = i; j < totalItensVetor - 1; j++) {
                mochilaVetor[j] = mochilaVetor[j + 1];
            }
            totalItensVetor--;
            printf("Item removido com sucesso!\n");
            return;
        }
    }
    printf("Item não encontrado.\n");
}

// Busca sequencial no vetor
void buscarSequencialVetor() {
    if (totalItensVetor == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    char nome[30];
    comparacoesSequencial = 0;
    printf("Digite o nome do item para buscar: ");
    scanf("%s", nome);

    for (int i = 0; i < totalItensVetor; i++) {
        comparacoesSequencial++;
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            printf("Item encontrado: Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochilaVetor[i].nome, mochilaVetor[i].tipo, mochilaVetor[i].quantidade);
            printf("Comparações realizadas: %d\n", comparacoesSequencial);
            return;
        }
    }

    printf("Item não encontrado.\n");
    printf("Comparações realizadas: %d\n", comparacoesSequencial);
}

// Ordenar vetor (Bubble Sort)
void ordenarVetor() {
    Item temp;
    for (int i = 0; i < totalItensVetor - 1; i++) {
        for (int j = 0; j < totalItensVetor - i - 1; j++) {
            if (strcmp(mochilaVetor[j].nome, mochilaVetor[j + 1].nome) > 0) {
                temp = mochilaVetor[j];
                mochilaVetor[j] = mochilaVetor[j + 1];
                mochilaVetor[j + 1] = temp;
            }
        }
    }
    printf("Itens ordenados com sucesso (Bubble Sort).\n");
}

// Busca binária no vetor
void buscarBinariaVetor() {
    if (totalItensVetor == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    char nome[30];
    int inicio = 0, fim = totalItensVetor - 1, meio;
    comparacoesBinaria = 0;

    printf("Digite o nome do item para busca binária: ");
    scanf("%s", nome);

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        comparacoesBinaria++;

        int cmp = strcmp(mochilaVetor[meio].nome, nome);
        if (cmp == 0) {
            printf("Item encontrado: Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochilaVetor[meio].nome, mochilaVetor[meio].tipo, mochilaVetor[meio].quantidade);
            printf("Comparações realizadas: %d\n", comparacoesBinaria);
            return;
        } else if (cmp < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    printf("Item não encontrado.\n");
    printf("Comparações realizadas: %d\n", comparacoesBinaria);
}

// FUNÇÕES PARA LISTA ENCADEADA

// Inserir item na lista
void inserirItemLista() {
    Item novo;
    printf("Digite o nome do item: ");
    scanf("%s", novo.nome);
    printf("Digite o tipo do item: ");
    scanf("%s", novo.tipo);
    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);

    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dados = novo;
    novoNo->prox = inicioLista;
    inicioLista = novoNo;

    printf("Item adicionado com sucesso!\n");
}

// Listar itens da lista
void listarItensLista() {
    if (inicioLista == NULL) {
        printf("Mochila vazia.\n");
        return;
    }
    No* atual = inicioLista;
    int i = 1;
    printf("----- Itens na Mochila (Lista) -----\n");
    while (atual != NULL) {
        printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n",
               i, atual->dados.nome, atual->dados.tipo, atual->dados.quantidade);
        atual = atual->prox;
        i++;
    }
    printf("-----------------------------------\n");
}

// Remover item da lista
void removerItemLista() {
    if (inicioLista == NULL) {
        printf("Mochila vazia.\n");
        return;
    }

    char nome[30];
    printf("Digite o nome do item para remover: ");
    scanf("%s", nome);

    No* atual = inicioLista;
    No* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->dados.nome, nome) == 0) {
            if (anterior == NULL) {
                inicioLista = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Item removido com sucesso!\n");
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }

    printf("Item não encontrado.\n");
}

// Busca sequencial na lista
void buscarItemLista() {
    if (inicioLista == NULL) {
        printf("Mochila vazia.\n");
        return;
    }

    char nome[30];
    comparacoesSequencial = 0;
    printf("Digite o nome do item para buscar: ");
    scanf("%s", nome);

    No* atual = inicioLista;
    while (atual != NULL) {
        comparacoesSequencial++;
        if (strcmp(atual->dados.nome, nome) == 0) {
            printf("Item encontrado: Nome: %s | Tipo: %s | Quantidade: %d\n",
                   atual->dados.nome, atual->dados.tipo, atual->dados.quantidade);
            printf("Comparações realizadas: %d\n", comparacoesSequencial);
            return;
        }
        atual = atual->prox;
    }

    printf("Item não encontrado.\n");
    printf("Comparações realizadas: %d\n", comparacoesSequencial);
}

// MENU PRINCIPAL
int main() {
    int opcaoPrincipal, opcaoEstrutura;

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1 - Usar Mochila (Vetor)\n");
        printf("2 - Usar Mochila (Lista Encadeada)\n");
        printf("0 - Sair\n");
        printf("==========================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoPrincipal);

        switch (opcaoPrincipal) {
        case 1:
            do {
                printf("\n--- MENU MOCHILA (VETOR) ---\n");
                printf("1 - Inserir Item\n");
                printf("2 - Listar Itens\n");
                printf("3 - Remover Item\n");
                printf("4 - Buscar Sequencial\n");
                printf("5 - Ordenar Itens (Bubble Sort)\n");
                printf("6 - Buscar Binária\n");
                printf("0 - Voltar\n");
                printf("----------------------------\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opcaoEstrutura);

                switch (opcaoEstrutura) {
                case 1: inserirItemVetor(); break;
                case 2: listarItensVetor(); break;
                case 3: removerItemVetor(); break;
                case 4: buscarSequencialVetor(); break;
                case 5: ordenarVetor(); break;
                case 6: buscarBinariaVetor(); break;
                case 0: break;
                default: printf("Opção inválida!\n"); break;
                }
            } while (opcaoEstrutura != 0);
            break;

        case 2:
            do {
                printf("\n--- MENU MOCHILA (LISTA) ---\n");
                printf("1 - Inserir Item\n");
                printf("2 - Listar Itens\n");
                printf("3 - Remover Item\n");
                printf("4 - Buscar Item\n");
                printf("0 - Voltar\n");
                printf("----------------------------\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opcaoEstrutura);

                switch (opcaoEstrutura) {
                case 1: inserirItemLista(); break;
                case 2: listarItensLista(); break;
                case 3: removerItemLista(); break;
                case 4: buscarItemLista(); break;
                case 0: break;
                default: printf("Opção inválida!\n"); break;
                }
            } while (opcaoEstrutura != 0);
            break;

        case 0:
            printf("Encerrando o programa...\n");
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }

    } while (opcaoPrincipal != 0);

    return 0;
}
