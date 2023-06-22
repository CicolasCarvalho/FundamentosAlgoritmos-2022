// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 26 09 2022

/*
Exemplo:
    100 100 100 100 100
    0   0   0   0   0 -> temp media 50, temp maxima 100

Entradas:
    temperaturas

Processamento:
    pegar as temperaturas e checar se e maior que a maior ate agora
    pegar as temperaturas divido por 10 e soma a media

Saida:
    a media e a maior temperatura
*/

#include <stdio.h>

int main(void) {
    float temperatura, tempMedia, tempMaxima = 0;

    for (int i = 0; i < 10; i++) {
        printf("Informe a temperatura %i:\t", i+1);
        scanf("%f", &temperatura);

        if (tempMaxima < temperatura)
            tempMaxima = temperatura;

        tempMedia += temperatura/10.0;
    }

    printf("\nA temperatura media foi de: %.2f", tempMedia);
    printf("\nA temperatura maxima foi de: %.2f\n", tempMaxima);

    return 0;
}