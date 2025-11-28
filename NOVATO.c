#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

int main() {
    struct Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;

    do {
        printf("\n===== MOCHILA - NIVEL NOVATO =====\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            if (total >= MAX_ITENS) {
                printf("Mochila cheia!\n");
            } else {
                printf("Nome do item: ");
                fgets(mochila[total].nome, 30, stdin);
                mochila[total].nome[strcspn(mochila[total].nome, "\n")] = 0;

                printf("Tipo do item: ");
                fgets(mochila[total].tipo, 20, stdin);
                mochila[total].tipo[strcspn(mochila[total].tipo, "\n")] = 0;

                printf("Quantidade: ");
                scanf("%d", &mochila[total].quantidade);

                total++;
                printf("Item adicionado!\n");
            }
        }

        else if (opcao == 2) {
            char nome[30];
            printf("Nome do item para remover: ");
            getchar();
            fgets(nome, 30, stdin);
            nome[strcspn(nome, "\n")] = 0;

            int i, encontrado = 0;
            for (i = 0; i < total; i++) {
                if (strcmp(mochila[i].nome, nome) == 0) {
                    encontrado = 1;
                    mochila[i] = mochila[total - 1];
                    total--;
                    printf("Item removido!\n");
                    break;
                }
            }
            if (!encontrado)
                printf("Item não encontrado.\n");
        }

        else if (opcao == 3) {
            printf("\n--- ITENS NA MOCHILA ---\n");
            for (int i = 0; i < total; i++) {
                printf("%s | %s | %d\n",
                    mochila[i].nome,
                    mochila[i].tipo,
                    mochila[i].quantidade);
            }
        }

    } while (opcao != 0);

    return 0;
}

