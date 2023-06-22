// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 29 08 2022

/*
Exemplo:
    1 2 3 4 -> 4
    20 2 4 -13 -> 20

Entradas:
    n1, n2, n3, n4

Processamento:
    verificar se n2 é maior que n1, se sim atribuir n2 verificar se o resultado
    anterior e menor a n3 e repetir o prcesso com n4

Saida:
    O maior numero
*/

#include <stdio.h>
#include <assert.h>

int max(int n1, int n2) {
    return n1>n2?n1:n2;
}

int main(void) {
    int n1, n2, n3, n4, maior;

    printf("coloque 4 idades:\n");
    scanf("%i %i %i %i", &n1, &n2, &n3, &n4);

    maior = max(max(n1, n2), max(n3, n4));

    printf("a maior idade e: %i", maior);
    return 0;
}