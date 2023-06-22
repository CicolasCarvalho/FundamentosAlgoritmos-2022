// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 24 10 2022

/*
Exemplo:
    v1: {
        1,  2,  3,  4,  5,
        4,  5,  6,  7,  8,
        7,  8,  9, 10, 11,
        7,  8,  9,  7, 11,
        7,  8, 10, 10,  3
    };
    d: {0, 0, 0, 0, 0} ->
    {
        0,  2,  3,  4,  5,
        4,  0,  6,  7,  8,
        7,  8,  0, 10, 11,
        7,  8,  9,  0, 11,
        7,  8, 10, 10,  0
    }
Entrada:
    uma matriz 5x5 e um vetor de 5 elementos

Processamento:
    substituir a diagonal principal do v1 pelo d

Saída:
   a matriz com a diagonal trocada
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "24102022.h"

void colocarDiagonal(int v[5][5], int diagonal[5]);

void teste(void) {
    int m[5][5] = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5}
    };

    int d[5] = {0, 0, 0, 0, 0};

    colocarDiagonal(m, d);

    for (int i = 0; i < 5; i++) {
        assert(m[i][i]==d[i]);
    }
}

int main(void) {
    teste();

	int v5x5[5][5], diagonal[5];

	printf("Insira o vetor\n");

	for (int i = 0; i < 5; i++) {
		char str[30];
		sprintf(str, "linha %i", i);
		receberValores(v5x5[i], str, 5);
	}

	printf("\nInsira a diagonal\n");
	receberValores(diagonal, "diagonal", 5);

	colocarDiagonal(v5x5, diagonal);
	for (int i = 0; i < 5; i++) {
		mostrarVetor(v5x5[i], 5);
	}

	return 0;
}

void colocarDiagonal(int v[5][5], int diagonal[5]) {
	for (int i = 0; i < 5; i++) {
		v[i][i] = diagonal[i];
	}
}