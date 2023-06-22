// Ní­colas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 13 10 2022

/*
Exemplo:
    0, 1, 10, 20, 25, 50, 100 ->
    [0, 0.01, 0.10, 0.20, 0.25, 0.50, 1]

Entrada:
    7 números

Processamento:
    Comparar qual numero e maior que todos, e dividir todos os elementos da array por ele

Saí­da:
    A lista com todos os elementos divididos
*/

#include <stdio.h>
#include <assert.h>

float getMaior7(float vetor[7]);

void teste(void) {
    float v[7] = {0,1,2,3,4,5,10};

    assert(getMaior7(v)==10);
}

int main(void) {
    teste();

    float vetor[7], maior;

    for(int i = 0; i < 7; i++) {
        printf("Insira o valor %i do vetor:\t", i+1);
        scanf("%f", &vetor[i]);
    }

    maior = getMaior7(vetor);

    printf("\nvetor = [");
    for(int i = 0; i < 7; i++) {
        vetor[i] /= maior;

        printf("%.3f", vetor[i]);

        if(i+1 < 7) printf(", ");
        else printf("]\n");
    }

    return 0;
}

float getMaior7(float vetor[7]) {
    float maior = vetor[0];

    for(int i = 1; i < 7; i++) {
        if(vetor[i] > maior)
            maior = vetor[i];
    }

    return maior;
}
