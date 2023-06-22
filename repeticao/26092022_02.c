// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 26 09 2022

/*
Exemplo:
    2 -> 1 + 1/2
    5 -> 1 + 1/2 + 1/3 + 1/4 + 1/5

Entradas:
    n

Processamento:
    H = 1 + 1/2 + ... + 1/N

Saida:
    H
*/

#include <stdio.h>
#include <assert.h>

float calc(int n);
void teste(void) {
    assert(calc(0) == 0);
    assert(calc(1) == 1);
    assert(calc(2) == 1.5);
}

int main(void) {
    teste();

    int n;

    printf("Insira o numeros de termos\n");
    scanf("%i", &n);

    float soma = calc(n);
    printf("\nH = 1 + 1/2 + ... + 1/N e:\t%.4f", soma);

    return 0;
}

float calc(int n) {
    float acc = 0;

    for(int i = 1; i <= n; i++) {
        acc += 1.0/(float)i;
    }

    return acc;
}