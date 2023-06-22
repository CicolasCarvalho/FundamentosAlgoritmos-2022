// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 24 10 2022

/*
Exemplo:
    v: {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    } -> 9

Entrada:
    1 vetor 3x3

Processamento:
    ir indice por indice analisando o maior numero

Saída:
   o maior elemento do vetor
*/

#include <stdio.h>
#include <assert.h>

#include "24102022.h"

int maiorNumero(int v[3][3]);

void teste(void) {
	int v[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	assert(maiorNumero(v)==9);
}

int main(void) {
	teste();

	int v[3][3];

	receberValores(v[0], "linha 0", 3);
	receberValores(v[1], "linha 1", 3);
	receberValores(v[2], "linha 2", 3);

	int maior = maiorNumero(v);

	printf("%i e o maior numero\n", maior);

	return 0;
}

int maiorNumero(int v[3][3]) {
	int maiorN = v[0][0];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (v[i][j] > maiorN) {
				maiorN = v[i][j];
			}
		}
	}

	return maiorN;
}