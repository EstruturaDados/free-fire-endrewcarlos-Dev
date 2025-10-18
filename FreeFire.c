#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

    typedef struct
    {
        char nome[30];
        char tipo [20];
        int quantidade;
    }item;

    item mochila[10];
    int totalitens = 0;
    
    void inserirItem(item mochila[], int *total){
    if (*total >= 10)
    {
        printf("Mochila cheia!!\n");
        return;
    }
        item novo;

        printf("Digite o nome do item: ");
        scanf("%s", novo.nome);

        printf("Digite o tipo do item: ");
        scanf("%s", novo.tipo);
    
        printf("Digite a quantidade: ");
        scanf("%d", &novo.quantidade);

        mochila[*total] = novo;
        (*total)++;

        printf("Item adicionado com sucesso");
    }

    void listarItem(item mochila[], int total){
        if (total == 0)
        {
            printf("Mochila vazia.\n");
            return;
        }
            printf("----- Itens na mochila -----\n");
            for (int i = 0; i < total; i++)
            {
                printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n", i+1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            }
                printf("------------------------\n");
    }
    void removerItem(item mochila[], int *total){
    char nome[30];
    int encontrado = 0;

    printf("Digite o nome do item para remover: ");
    scanf("%s", nome);

    for (int i = 0; i < *total; i++){
        if (strcmp(mochila[i].nome, nome) == 0){
            for (int j = i; j < *total - 1; j++){
                mochila[j] = mochila[j + 1];
            }
            (*total)--;  
            printf("Item removido com sucesso!!\n");
            encontrado = 1;
            return; 
        }
    }

    if (!encontrado){
        printf("Item não encontrado.\n");
    }
    }

    void buscarItem(item mochila[], int total){
        char nome[30];
        int encontrado = 0;

        printf("Nome do item para buscar: ");
        scanf("%s", nome);

        for (int i = 0; i < total; i++){
        if (strcmp(mochila[i].nome, nome) == 0){
           printf("Item encontrado");
           printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n", i+1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
           encontrado = 1;
           break; 
        }
    }
    if (!encontrado)
    {
        printf("Item não encontrado");
    }
}

    int main(){

        int opcao;

            do
            {
                printf("\n==============================\n");
                printf("       MENU DA MOCHILA\n");
                printf("==============================\n");
                printf("1 - Inserir item\n");
                printf("2 - Listar itens\n");
                printf("3 - Remover item\n");
                printf("4 - Buscar item\n");
                printf("0 - Sair\n");
                printf("==============================\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opcao);

                switch (opcao)
                {
                case 1:
                    inserirItem(mochila, &totalitens);
                    break;
                case 2:
                    listarItem(mochila, totalitens);
                    break;
                case 3:
                    removerItem(mochila, &totalitens);
                    break;
                case 4:
                    buscarItem(mochila, totalitens);
                    break;
                case 0:
                    printf("SAINDO......\n");
                    break;
                
                default:
                    printf("Opção invalida\n");
                    break;
                }

            } while (opcao != 0);
            
    return 0;
    }