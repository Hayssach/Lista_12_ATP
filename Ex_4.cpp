#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int valor; // valor real multiplicado por 10.000
} Decimal;

// Lê um decimal do usuário e converte para a struct Decimal
Decimal lerDecimal() {
    double entrada;
    Decimal d;
    printf("Digite um número decimal (ex: 12.3456): ");
    scanf("%lf", &entrada);
    d.valor = (int)round(entrada * 10000); // arredonda para evitar truncamento
    return d;
}

// Soma dois Decimais
Decimal somar(Decimal a, Decimal b) {
    Decimal resultado;
    resultado.valor = a.valor + b.valor;
    return resultado;
}

// Subtrai dois Decimais
Decimal subtrair(Decimal a, Decimal b) {
    Decimal resultado;
    resultado.valor = a.valor - b.valor;
    return resultado;
}

// Imprime um Decimal com 4 casas decimais
void imprimir(Decimal d) {
    int parteInteira = d.valor / 10000;
    int parteDecimal = abs(d.valor % 10000);
    printf("%d.%04d", parteInteira, parteDecimal);
}

int main() {
    Decimal d1 = lerDecimal();
    Decimal d2 = lerDecimal();

    Decimal soma = somar(d1, d2);
    Decimal sub = subtrair(d1, d2);

    printf("\nNúmero 1: ");
    imprimir(d1);
    printf("\nNúmero 2: ");
    imprimir(d2);
    printf("\nSoma: ");
    imprimir(soma);
    printf("\nSubtração: ");
    imprimir(sub);
    printf("\n");

    return 0;
}
