#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    float preco;
} Produto;

typedef struct {
    Produto produtos[MAX_ITENS];
    int quantidadeProdutos;
} Menu;

// Função para inicializar um produto
void inicializarProduto(Produto *p, const char *nome, float preco) {
    strncpy(p->nome, nome, MAX_NOME - 1);
    p->nome[MAX_NOME - 1] = '\0'; // garantir terminação
    p->preco = preco;
}

int main() {
    FILE *fmenu = fopen("menu.txt", "r");
    if (!fmenu) {
        perror("Erro ao abrir menu.txt");
        return 1;
    }

    Menu menu;
    fscanf(fmenu, "%d", &menu.quantidadeProdutos);  // número de itens no menu

    // Lê os itens do menu usando struct Produto
    for (int i = 0; i < menu.quantidadeProdutos; i++) {
        char nomeTemp[MAX_NOME];
        float precoTemp;
        fscanf(fmenu, "%s %f", nomeTemp, &precoTemp);
        inicializarProduto(&menu.produtos[i], nomeTemp, precoTemp);
    }

    fclose(fmenu);

    // Mostra o menu
    printf("==== MENU ====\n");
    for (int i = 0; i < menu.quantidadeProdutos; i++) {
        printf("%d - %s : R$ %.2f\n", i + 1, menu.produtos[i].nome, menu.produtos[i].preco);
    }

    int quantidades[MAX_ITENS] = {0};
    int escolha, qtd;

    // Lê pedidos do usuário
    while (1) {
        printf("Digite o número do item que deseja comprar (0 para finalizar): ");
        scanf("%d", &escolha);
        if (escolha == 0) break;
        if (escolha < 1 || escolha > menu.quantidadeProdutos) {
            printf("Opção inválida!\n");
            continue;
        }

        printf("Digite a quantidade de %s: ", menu.produtos[escolha - 1].nome);
        scanf("%d", &qtd);
        quantidades[escolha - 1] += qtd;
    }

    // Gera boleto.txt
    FILE *fbol = fopen("boleto.txt", "w");
    if (!fbol) {
        perror("Erro ao criar boleto.txt");
        return 1;
    }

    fprintf(fbol, "====== BOLETO ======\n");
    float total = 0.0;
    for (int i = 0; i < menu.quantidadeProdutos; i++) {
        if (quantidades[i] > 0) {
            float subt = quantidades[i] * menu.produtos[i].preco;
            fprintf(fbol, "%s x %d = R$ %.2f\n", menu.produtos[i].nome, quantidades[i], subt);
            total += subt;
        }
    }
    fprintf(fbol, "TOTAL A PAGAR: R$ %.2f\n", total);
    fclose(fbol);

    printf("\nPedido registrado no arquivo boleto.txt\n");

    getchar(); // Para pausar no Windows
    return 0;
}
