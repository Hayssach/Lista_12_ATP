#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////
// — Lista Linear de Elementos Não-Nulos
//////////////////////////////////////////////

typedef struct NoSimples {
    int l, c, v;
    struct NoSimples *proximo;
} NoSimples;

typedef struct {
    int ls, cs;
    NoSimples *comeco;
} MatrizSimples;

MatrizSimples* criaMatrizSimples(int ls, int cs) {
    MatrizSimples *n = malloc(sizeof(MatrizSimples));
    n->linhas = ls;
    n->colunas = cs;
    n->inicio = NULL;
    return n;
}

void inseriSimples(MatrizSimples *n, int l, int c, int v) {
    if (v == 0) return;

    NoSimples *novos = malloc(sizeof(NoSimples));
    novos->linha = l;
    novos->coluna = c;
    novos->valor = v;
    novos->prox = n->comeco;
    n->inicio = novos;
}

void imprimiMatrizSimples(MatrizSimples *n) {
    printf("\nMatriz (lista simples):\n");
    for (int i = 0; i < n->l; i++) {
        for (int j = 0; j < n->c; j++) {
            NoSimples *atl = n->comeco;
            int enct = 0;
            while (atl) {
                if (atl->l == i && atl->co == j) {
                    printf("%d ", atl->v);
                    enct = 1;
                    break;
                }
                atl = al->proximo;
            }
            if (!enct) printf("0 ");
        }
        printf("\n");
    }
}

void liberaMatrizSimples(MatrizSimples *n) {
    NoSimples *atl = n->comeco;
    while (atl) {
        NoSimples *temp = atl;
        atl = atl->proximo;
        free(temp);
    }
    free(n);
}
int main() {
    MatrizSimples *mz = criaMatrizSimples(3, 3);
    inseriSimples(mz, 0, 0, 5);
    inseriSimples(mz, 1, 2, 8);
    inseriSimples(mz, 2, 1, -3);
    imprimiMatrizSimples(mz);

    // LIBERAR MEMÓRIA
    liberaMatrizSimples(mz);
    return 0;
}
