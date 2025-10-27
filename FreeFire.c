#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ====================== ESTRUTURAS ======================

typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

typedef struct No {
    Item dados;
    struct No* prox;
} No;

// ====================== VARIÁVEIS GLOBAIS ======================

#define TAM 10
#define MAX 20

Item mochilaVetor[TAM];
int totalItensVetor = 0;

No* inicioLista = NULL;

Componente componentes[MAX];
int totalComponentes = 0;

int comparacoesSequencial = 0;
int comparacoesBinaria = 0;

// ====================== FUNÇÕES VETOR ======================

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

// ====================== FUNÇÕES LISTA ======================

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
            if (anterior == NULL) inicioLista = atual->prox;
            else anterior->prox = atual->prox;
            free(atual);
            printf("Item removido com sucesso!\n");
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Item não encontrado.\n");
}

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

// ====================== FUNÇÕES COMPONENTES ======================

void cadastrarComponentes() {
    if (totalComponentes >= MAX) {
        printf("Limite maximo de componentes atingido!\n");
        return;
    }
    Componente novo;
    printf("Digite o Nome do componente: ");
    scanf("%s", novo.nome);
    printf("Digite o Tipo do Componente: ");
    scanf("%s", novo.tipo);
    printf("Digite a prioridade (1 a 10): ");
    scanf("%d", &novo.prioridade);

    componentes[totalComponentes] = novo;
    totalComponentes++;

    printf("Componente cadastrado com sucesso!\n");
}

void listarComponentes() {
    if (totalComponentes == 0) {
        printf("Nenhum componente cadastrado.\n");
        return;
    }
    printf("----- Componentes -----\n");
    for (int i = 0; i < totalComponentes; i++) {
        printf("%d. Nome: %s | Tipo: %s | Prioridade: %d\n",
               i + 1, componentes[i].nome, componentes[i].tipo, componentes[i].prioridade);
    }
    printf("-----------------------\n");
}

void ordenarComponentesPorPrioridade() {
    Componente temp;
    for (int i = 0; i < totalComponentes - 1; i++) {
        for (int j = 0; j < totalComponentes - i - 1; j++) {
            if (componentes[j].prioridade < componentes[j + 1].prioridade) {
                temp = componentes[j];
                componentes[j] = componentes[j + 1];
                componentes[j + 1] = temp;
            }
        }
    }
    printf("Componentes ordenados por prioridade (decrescente)!\n");
}

void buscarSequencialComponente() {
    if (totalComponentes == 0) {
        printf("Nenhum componente cadastrado.\n");
        return;
    }

    char nome[30];
    comparacoesSequencial = 0;
    printf("Digite o nome do componente para buscar: ");
    scanf("%s", nome);

    for (int i = 0; i < totalComponentes; i++) {
        comparacoesSequencial++;
        if (strcmp(componentes[i].nome, nome) == 0) {
            printf("Componente encontrado: Nome: %s | Tipo: %s | Prioridade: %d\n",
                   componentes[i].nome, componentes[i].tipo, componentes[i].prioridade);
            printf("Comparações realizadas: %d\n", comparacoesSequencial);
            return;
        }
    }

    printf("Componente não encontrado.\n");
    printf("Comparações realizadas: %d\n", comparacoesSequencial);
}

void buscarBinariaComponente() {
    if (totalComponentes == 0) {
        printf("Nenhum componente cadastrado.\n");
        return;
    }

    ordenarComponentesPorPrioridade(); // garante ordenação

    char nome[30];
    comparacoesBinaria = 0;
    int inicio = 0, fim = totalComponentes - 1, meio;

    printf("Digite o nome do componente para busca binária: ");
    scanf("%s", nome);

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        comparacoesBinaria++;

        int cmp = strcmp(componentes[meio].nome, nome);
        if (cmp == 0) {
            printf("Componente encontrado: Nome: %s | Tipo: %s | Prioridade: %d\n",
                   componentes[meio].nome, componentes[meio].tipo, componentes[meio].prioridade);
            printf("Comparações realizadas: %d\n", comparacoesBinaria);
            return;
        } else if (cmp < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    printf("Componente não encontrado.\n");
    printf("Comparações realizadas: %d\n", comparacoesBinaria);
}

// ====================== MAIN ======================

int main() {
    int opcaoPrincipal, opcaoEstrutura;

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1 - Usar Mochila (Vetor)\n");
        printf("2 - Usar Mochila (Lista Encadeada)\n");
        printf("3 - Componentes\n");
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

        case 3:
            do {
                printf("\n--- MENU COMPONENTES ---\n");
                printf("1 - Cadastrar Componente\n");
                printf("2 - Listar Componentes\n");
                printf("3 - Ordenar por Prioridade\n");
                printf("4 - Buscar Sequencial\n");
                printf("5 - Buscar Binária\n");
                printf("0 - Voltar\n");
                printf("-------------------------\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opcaoEstrutura);

                switch (opcaoEstrutura) {
                case 1: cadastrarComponentes(); break;
                case 2: listarComponentes(); break;
                case 3: ordenarComponentesPorPrioridade(); break;
                case 4: buscarSequencialComponente(); break;
                case 5: buscarBinariaComponente(); break;
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