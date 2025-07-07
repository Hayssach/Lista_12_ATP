#include <stdio.h>
#include <stdlib.h>
#include <math.h> // biblioteca math 

typedef struct {
    int v; // valor real multiplicado por 10.000
} Decimal;

// Lê um decimal do usuário e converte para a struct Decimal
Decimal leDecimal() {
    double entd;
    Decimal D;
    printf("Digite um número decimal (ex: 12.3456): ");
    scanf("%lf", &entd);
    D.v = (int)round(entd * 10000); // arredonda para evitar truncamento
    return D;
}

// Soma dois Decimais
Decimal soma(Decimal b, Decimal c) {
    Decimal result;
    result.v = b.v + c.v;
    return result;
}

// Subtrai dois Decimais
Decimal subtrai(Decimal b, Decimal c) {
    Decimal result;
    result.v = b.v - c.v;
    return result;
}

// Imprime um Decimal com 4 casas decimais
void imprimi(Decimal D) {
    int parteInt = D.v / 10000;
    int parteDec = abs(D.v % 10000);
    printf("%d.%04d", parteInt, parteDec);
}

int main() {
    Decimal D1 = leDecimal();
    Decimal D2 = leDecimal();

    Decimal s = somar(D1, D2);
    Decimal subt = subtrair(D1, D2);

    printf("\nNúmero 1: ");
    imprimi(D1);
    printf("\nNúmero 2: ");
    imprimi(D2);
    printf("\nSoma: ");
    imprimi(s);
    printf("\nSubtração: ");
    imprimi(subt);
    printf("\n");

    return 0;
}
