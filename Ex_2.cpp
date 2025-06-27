#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float notaExercicios;
    float notaProva1;
    float notaProva2;
} Aluno;

void calcular_media(Aluno *a) {
    float mediaProvas = (a->notaProva1 * 4 + a->notaProva2 * 6) / 10;
    float mediaFinal = (a->notaExercicios * 0.2) + (mediaProvas * 0.8);
    printf("Aluno: %s | Média Final: %.2f\n", a->nome, mediaFinal);
}

int main() {
    Aluno a1, a2;

    // Cadastro dos dados do aluno a1
    printf("Digite o nome do aluno 1 (sem espaços): ");
    scanf("%s", a1.nome);
    printf("Nota dos exercícios: ");
    scanf("%f", &a1.notaExercicios);
    printf("Nota da Prova 1: ");
    scanf("%f", &a1.notaProva1);
    printf("Nota da Prova 2: ");
    scanf("%f", &a1.notaProva2);

    // Cadastro dos dados do aluno a2
    printf("\nDigite o nome do aluno 2 (sem espaços): ");
    scanf("%s", a2.nome);
    printf("Nota dos exercícios: ");
    scanf("%f", &a2.notaExercicios);
    printf("Nota da Prova 1: ");
    scanf("%f", &a2.notaProva1);
    printf("Nota da Prova 2: ");
    scanf("%f", &a2.notaProva2);

    // Calculando e exibindo a média dos alunos
    calcular_media(&a1);
    calcular_media(&a2);

    getchar(); // pausa antes de sair (para sistemas como Windows)
    return 0;
}
