#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float notaEx;
    float notaP1;
    float notaP2;
} Aluno;

void calcula_media(Aluno *b) {
    float meProvas = (b->notaP1 * 4 + b->notaP2 * 6) / 10;
    float meFinal = (b->notaEx * 0.2) + (mProvas * 0.8);
    printf("Aluno: %s | Média Final: %.2f\n", b->nome, meFinal);
}

int main() {
    Aluno c1, c2;

    // Cadastro dos dados do aluno c1
    printf("Digite o nome do aluno 1 (sem espaços): ");
    scanf("%s", c1.nome);
    printf("Nota dos exercícios: ");
    scanf("%f", &c1.notaEx);
    printf("Nota da Prova 1: ");
    scanf("%f", &c1.notaP1);
    printf("Nota da Prova 2: ");
    scanf("%f", &c1.notaP2);

    // Cadastro dos dados do aluno c2
    printf("\nDigite o nome do aluno 2 (sem espaços): ");
    scanf("%s", c2.nome);
    printf("Nota dos exercícios: ");
    scanf("%f", &c2.notaEx);
    printf("Nota da Prova 1: ");
    scanf("%f", &c2.notaP1);
    printf("Nota da Prova 2: ");
    scanf("%f", &c2.notaP2);

    // Calculando e exibindo a média dos alunos
    calcula_media(&c1);
    calcula_media(&c2);

    getchar();
    return 0;
}
