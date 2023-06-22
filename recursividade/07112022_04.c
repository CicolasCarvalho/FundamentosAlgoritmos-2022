// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 07112022

/*
Exemplos:
	[1, 10] incremento: 1 ->
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10

Entrada:
    intervalo; incremento

Processamento:
    pegar o intervalo e imprimir ele incrementando o incremento

Saída:
    o intervalo com o incremento
*/

#include <stdio.h>
#include <assert.h>

void ImprimeSerie(int i, int j, int k);

int main(void) {
	int i, j, k;

	printf("Isira sua serie e incremento (i, j, k):\n");
	scanf("%i %i %i", &i, &j, &k);

	printf("\nA serie e:\n");
	ImprimeSerie(i, j, k);

	return 0;
}

void ImprimeSerie(int i, int j, int k) {
	if (j-i < 0)
		return;

	printf("%i\n", i);

	ImprimeSerie(i+k, j, k);
}