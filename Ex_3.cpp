#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////
// — Lista Linear de Elementos Não-Nulos
//////////////////////////////////////////////

typedef struct NoSimples {
    int linha, coluna, valor;
    struct NoSimples *prox;
} NoSimples;

typedef struct {
    int linhas, colunas;
    NoSimples *inicio;
} MatrizSimples;

MatrizSimples* criarMatrizSimples(int linhas, int colunas) {
    MatrizSimples *m = malloc(sizeof(MatrizSimples));
    m->linhas = linhas;
    m->colunas = colunas;
    m->inicio = NULL;
    return m;
}

void inserirSimples(MatrizSimples *m, int linha, int coluna, int valor) {
    if (valor == 0) return;

    NoSimples *novo = malloc(sizeof(NoSimples));
    novo->linha = linha;
    novo->coluna = coluna;
    novo->valor = valor;
    novo->prox = m->inicio;
    m->inicio = novo;
}

void imprimirMatrizSimples(MatrizSimples *m) {
    printf("\nMatriz (lista simples):\n");
    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            NoSimples *atual = m->inicio;
            int encontrado = 0;
            while (atual) {
                if (atual->linha == i && atual->coluna == j) {
                    printf("%d ", atual->valor);
                    encontrado = 1;
                    break;
                }
                atual = atual->prox;
            }
            if (!encontrado) printf("0 ");
        }
        printf("\n");
    }
}

void liberarMatrizSimples(MatrizSimples *m) {
    NoSimples *atual = m->inicio;
    while (atual) {
        NoSimples *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(m);
}
int main() {
    MatrizSimples *ms = criarMatrizSimples(3, 3);
    inserirSimples(ms, 0, 0, 5);
    inserirSimples(ms, 1, 2, 8);
    inserirSimples(ms, 2, 1, -3);
    imprimirMatrizSimples(ms);

    // LIBERAR MEMÓRIA
    liberarMatrizSimples(ms);
    return 0;
}
