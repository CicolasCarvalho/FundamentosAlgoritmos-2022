// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 29 08 2022

/*
Exemplo:
    1 -> 0.35
    10 -> 3.50
    ...
    12 -> 3.60

Entradas:
    n

Processamento:
    verificar se foram menos de 12 laranjas, se sim multiplicar por 0,35 se nao por 0,30

Saida:
    O preco total da compra
*/

#include <stdio.h>

float preco(int n) {
    return n*(n<12?0.35:0.30);
}

int main(void) {
    int n;

    printf("quantas laranjas foram compradas?\n");
    scanf("%i", &n);

    printf("\no preco total foi de:%.2f\n", preco(n));

    return 0;
}