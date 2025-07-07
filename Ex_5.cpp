#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    float p;
} Produto;

typedef struct {
    Produto pdt[MAX_ITENS];
    int qtdProdutos;
} Menu;

// Função para inicializar um produto
void inicializaProduto(Produto *P, const char *Nome, float p) {
    strncpy(P->Nome, Nome, MAX_NOME - 1);
    P->Nome[MAX_NOME - 1] = '\0'; // garantir terminação
    P->p = p;
}

int main() {
    FILE *fmenu = fopen("menu.txt", "r");
    if (!fmenu) {
        perror("Erro ao abrir menu.txt");
        return 1;
    }

    Menu menu;
    fscanf(fmenu, "%d", &menu.qtdProdutos);  // número de itens no menu

    // Lê os itens do menu usando struct Produto
    for (int i = 0; i < menu.qtdProdutos; i++) {
        char nTemp[MAX_NOME];
        float pTemp;
        fscanf(fmenu, "%s %f", nTemp, &pTemp);
        inicializar
            Produto(&menu.pdt[i], nTemp, pTemp);
    }

    fclose(fmenu);

    // Mostra o menu
    printf("==== MENU ====\n");
    for (int i = 0; i < menu.qdtProdutos; i++) {
        printf("%d - %s : R$ %.2f\n", i + 1, menu.pdt[i].nome, menu.pdt[i].p);
    }

    int qdts[MAX_ITENS] = {0};
    int e, qtd;

    // Lê pedidos do usuário
    while (1) {
        printf("Digite o número do item que deseja comprar (0 para finalizar): ");
        scanf("%d", &e);
        if (e == 0) break;
        if (e < 1 || e > menu.qtdProdutos) {
            printf("Opção inválida!\n");
            continue;
        }

        printf("Digite a quantidade de %s: ", menu.produtos[escolha - 1].nome);
        scanf("%d", &qtd);
        qdts[e - 1] += qtd;
    }

    // Gera boleto.txt
    FILE *fbol = fopen("boleto.txt", "w");
    if (!fbol) {
        perror("Erro ao criar boleto.txt");
        return 1;
    }

    fprintf(fbol, "====== BOLETO ======\n");
    float tl = 0.0;
    for (int i = 0; i < menu.qtdProdutos; i++) {
        if (qtds[i] > 0) {
            float subt = qtds[i] * menu.pdt[i].p;
            fprintf(fbol, "%s x %d = R$ %.2f\n", menu.pdt[i].nome, qtds[i], subt);
            tl += subt;
        }
    }
    fprintf(fbol, "TOTAL A PAGAR: R$ %.2f\n", total);
    fclose(fbol);

    printf("\nPedido registrado no arquivo boleto.txt\n");

    getchar(); 
    return 0;
}
