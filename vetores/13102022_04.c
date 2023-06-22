// Ní­colas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 13 10 2022

/*
Exemplo:
    M = [
		1, 2, 3,
		3, 2, 3,
		3, 3, 3
    ]

Entrada:
    uma matriz 3x3

Processamento:
	pegar o maior numero na diagonal e dividir todos os elementos por o maior numero

Saí­da:
    A lista com todos os elementos divididos pelo maior numero da diagona principal
*/

#include <stdio.h>
#include <assert.h>

float maiorNDiagonal3x3(float m[3][3]);

void teste(void) {
	float m[3][3] = {
		{1, 3, 3},
		{3, 2, 3},
		{3, 3, 3}
	};

	assert(maiorNDiagonal3x3(m)==3);
}

int main(void) {
	float m[3][3];

	for (int y = 0; y < 3; y++) {
		printf("Insira a linha %i:\n", y);
		for (int x = 0; x < 3; x++) {
			scanf("%f", &m[y][x]);
		}
	}

	float maior = maiorNDiagonal3x3(m);

	printf("m = [\n");
	for (int y = 0; y < 3; y++) {
		printf("\t");
		for (int x = 0; x < 3; x++) {
			m[y][x] /= maior;

			printf("%f", m[y][x]);
        	if(y+1 < 3 || x+1 < 3) printf(", ");
		}
		printf("\n");
	}
	printf("]\n");

	return 0;
}

float maiorNDiagonal3x3(float m[3][3]) {
	float maior = m[0][0];

	for (int i = 1; i < 3; ++i) {
		if (m[i][i] > maior) {
			maior = m[i][i];
		}
	}

	return maior;
}