// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 24 10 2022

/*
Exemplo:
    {1, 2, 3, 4, 5, 6} -> 3 elementos par

Entrada:
    um vetor de n valores

Processamento:
    receber o tamanho do vetor e pegar os elementos

Saída:
    números de elementos par
*/

#include <stdio.h>

#include "24102022.h"

int qtdPares(int v[], int tamanho);

void teste(void) {
    int t[6] = {1, 2, 3, 4, 5, 6};

    assert(qtdPares(t, 6)==3);
}

int main(void) {
    teste();

	int tamanho;

	printf("Insira o tamanho do vetor:\t");
	scanf("%i", &tamanho);

	int v[tamanho];

	receberValores(v, "", tamanho);

	int pares = qtdPares(v, tamanho);
	printf("len({(x) E v : x mod 2 == 0}) = %i\n", pares);

	return 0;
}

int qtdPares(int v[], int tamanho) {
	int acc = 0;

	for (int i = 0; i < tamanho; i++) {
		acc += (v[i]%2-1)*-1;
	}

	return acc;
}