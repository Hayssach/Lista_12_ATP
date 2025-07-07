#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float notaExe;
    float notaP1;
    float notaP2;
} Aluno;

// Função para calcular a média final
float calculaMediaFinal(Aluno c) {
    float mProvas = (c.notaP1 * 4 + c.notaP2 * 6) / 10;
    float mFinal = (c.notaExe * 0.2) + (mProvas * 0.8);
    return mFinal;
}


int main() {
    Aluno aluno;

    printf("Digite o nome do aluno (sem espaços): ");
    scanf("%s", aluno.nome); // Só lê até o primeiro espaço

    printf("Digite a nota dos exercicios: ");
    scanf("%f", &aluno.notaExe);

    printf("Digite a nota da Prova 1 (peso 4): ");
    scanf("%f", &aluno.notaP1);

    printf("Digite a nota da Prova 2 (peso 6): ");
    scanf("%f", &aluno.notaP2);

    float me = calculaMediaFinal(aluno);

    printf("\nAluno: %s\n", aluno.nome);
    printf("Media final: %.2f\n", me);

    return 0;
}
