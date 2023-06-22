// Ní­colas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 13 10 2022

/*
Exemplo:
    M = [ 
    	1, 2, 3,
    	4, 5, 6,
    	7, 8, 9,
    	10, 11, 12
    ] -> 78

Entrada:
    uma matriz 3 por 4

Processamento:
	passar elemento por eemento somando em uma variavel acc

Saí­da:
    a soma de todos os numeros
*/

#include <stdio.h>
#include <assert.h>

int soma4x3(int v[4][3]);

void teste(void) {
	int v[4][3] = {
		{1,  2,  3 },
		{4,  5,  6 },
		{7,  8,  9 },
		{10, 11, 12}
	};

	assert(soma4x3(v)==78);
}

int main(void) {
	teste();

	int m[4][3], soma;

	for (int y = 0; y < 4; y++) {
		printf("insira a linha %i:\n", y);
		for (int x = 0; x < 3; x++) {
			scanf("%i", &m[y][x]);
		}
	}

	soma = soma4x3(m);

	printf("a soma de todos elementos de m sao: %i\n", soma);

	return 0;
}

int soma4x3(int m[4][3]) {
	int soma = 0;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 3; x++) {
			soma += m[y][x];
		}
	}

	return soma;
}