// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 29 08 2022

/*
Exemplo:
    1 -> "Um"
    2 -> "Dois"
    ...
    9 -> "Nove"

Entradas:
    n

Processamento:
    Checar se o número está entre 0 e 9 e se sim checar caso a caso o numero e retornar por extenso

Saida:
    O numero por extenso
*/

#include <stdio.h>
#include <assert.h>

void numero(int n) {
    switch (n) {
        case 0:
            printf("\nZero\n");
            break;
        case 1:
            printf("\nUm\n");
            break;
        case 2:
            printf("\nDois\n");
            break;
        case 3:
            printf("\nTres\n");
            break;
        case 4:
            printf("\nQuatro\n");
            break;
        case 5:
            printf("\nCinco\n");
            break;
        case 6:
            printf("\nSeis\n");
            break;
        case 7:
            printf("\nSete\n");
            break;
        case 8:
            printf("\nOito\n");
            break;
        case 9:
            printf("\nNove\n");
            break;
        default:
            printf("o numero dado nao esta no intervalo [0,10[\n\n");
            break;
    }
}

int main(void) {
    int n;

    printf("Coloque um numero entre 0 e 10:\n");
    scanf("%i", &n);
    numero(n);

    return 0;
}