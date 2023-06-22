// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação 1 - UEM
// 17 08 2022

/*
Exemplos:
    - idades: 1, 2, 3, 4 -> meida 2.5 anos, a pessoa mais velha tem 4

Entrada:
    idades

Processamento:
    somar as idades e dividi-las por 4. comparar as 4 idades e pegar a maior

Saída:
    a média das idades, e a pessoa mais velha
*/

#include <stdio.h>

int main(void) {
    int i1, i2, i3, i4, maior;
    float media;

    printf("Informe as idades das 4 pessoas:\n");
    scanf("%i %i %i %i", &i1, &i2, &i3, &i4);

    media = (i1+i2+i3+i4)/4.0;

    maior = i1;
    if (i2>maior) maior = i2;
    if (i3>maior) maior = i3;
    if (i4>maior) maior = i4;

    printf("\nA media de idades e: %f\nA pessoa mais velha tem: %i\n", media, maior);

    return 0;
}

//-------------------------
// implemtação com vetores
//-------------------------

// int main(void) {
//     int idades[4];
//     int maior = 0;
//     float media = 0.0;

//     for (int i = 0; i < 4; i++) {
//         printf("Insira a idade de numero %i:\n", i+1);
//         scanf("%i", &idades[i]);

//         if (idades[i] > maior)
//            maior = idades[i];

//         media += idades[i];
//     }

//     media /= 4.0;
//     printf("\nA media de idades e: %f\nA pessoa mais velha tem: %i\n", media, maior);

//     return 0;
// }
