// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 29 08 2022

#include <stdio.h>
#include <assert.h>

void numero(int n);
float preco(int n);
int max(int n1, int n2);

int main(void) {
    //1)
    {
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

        int n;

        printf("Coloque um numero entre 0 e 10:\n");
        scanf("%i", &n);
        numero(n);
    }

    //2)
    {
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

        int n;

        printf("quantas laranjas foram compradas?\n");
        scanf("%i", &n);

        printf("\no preco total foi de:%.2f\n", preco(n));
    }

    //3)
    {
        /*
        Exemplo:
            1 2 3 4 -> 4
            20 2 4 13 -> 20

        Entradas:
            n1, n2, n3, n4

        Processamento:
            verificar se n2 é maior que n1, se sim atribuir n2 verificar se o resultado
            anterior e menor a n3 e repetir o prcesso com n4

        Saida:
            O maior numero
        */

        int n1, n2, n3, n4, maior;

        printf("coloque 4 idades:\n");
        scanf("%i %i %i %i", &n1, &n2, &n3, &n4);

        maior = max(max(n1, n2), max(n3, n4));

        printf("a maior idade e: %i", maior);
    }

    return 0;
}

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

float preco(int n) {
    return n*(n<12?0.35:0.30);
}

int max(int n1, int n2) {
    return n1>n2?n1:n2;
}
