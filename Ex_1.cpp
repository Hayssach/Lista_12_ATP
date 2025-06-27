#include <stdio.h>
#include <stdlib.h>

// Definição da struct Aluno
typedef struct {
    char nome[50];
    float notaExercicios;
    float notaProva1;
    float notaProva2;
} Aluno;

// Função para calcular a média final
float calcularMediaFinal(Aluno a) {
    float mediaProvas = (a.notaProva1 * 4 + a.notaProva2 * 6) / 10;
    float mediaFinal = (a.notaExercicios * 0.2) + (mediaProvas * 0.8);
    return mediaFinal;
}

// Função principal para teste
int main() {
    Aluno aluno;

    printf("Digite o nome do aluno (sem espaços): ");
    scanf("%s", aluno.nome); // Só lê até o primeiro espaço

    printf("Digite a nota dos exercicios: ");
    scanf("%f", &aluno.notaExercicios);

    printf("Digite a nota da Prova 1 (peso 4): ");
    scanf("%f", &aluno.notaProva1);

    printf("Digite a nota da Prova 2 (peso 6): ");
    scanf("%f", &aluno.notaProva2);

    float media = calcularMediaFinal(aluno);

    printf("\nAluno: %s\n", aluno.nome);
    printf("Media final: %.2f\n", media);

    return 0;
}
