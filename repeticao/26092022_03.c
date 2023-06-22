// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 26 09 2022

/*
Exemplo:
    1, 2, 3, 4, 5, 9, 9 -> 2 numeros maior que 8

Entradas:
    n1, n2, n3, n4, n5, n6, n7

Processamento:
    pegar um numero e ver se é maior que 8 se sim adicionar +1 em uma variavel acumuladora

Saida:
    quantidade de numeros maior que 8
*/

#include <stdio.h>
#include <assert.h>

int maiorQ8(void);

int main(void) {
    printf("ha %i numeros maior que 8", maiorQ8());
    return 0;
}

int maiorQ8(void) {
    int acc = 0, numero;

    for (int i = 0; i < 7; i++) {
        printf("coloque o numero %i: ", i+1);
        scanf("%i", &numero);

        if(numero > 8)
            acc++;
    }

    return acc;
}