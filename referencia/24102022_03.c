// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 24 10 2022

/*
Exemplo:
    {10, 2, 4, 3, 5, 8, 7, 6, 9, 1}
    ->
    {1, 2, 4, 3, 5, 8, 7, 6, 9, 10}

Entrada:
    um vetor de 10 elementos

Processamento:
    receber o vetor pegar o indice do menor valor
    substituir o incdice pelo 0 e o 0 pelo indice

Saída:
   o vetor inserido com o menor numero em primeiro
*/

#include <stdio.h>
#include <assert.h>

#include "24102022.h"

void swapVetor(int v[], int tamanho, int pos1, int pos2);
int menorValorIndice(int v[], int tamanho);

void teste(void) {
	int a[10] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int indice = menorValorIndice(a, 10);

	swapVetor(a, 10, indice, 0);
    assert(indice==1);
	assert(a[0] == 1);
	assert(a[1] == 10);
}

int main(void) {
	teste();

	int v[10];

	receberValores(v, "", 10);
	int indice = menorValorIndice(v, 10);
	swapVetor(v, 10, indice, 0);
	mostrarVetor(v, 10);

	return 0;
}

void swapVetor(int v[], int tamanho, int pos1, int pos2) {
	int de = pos1%tamanho,
		para = pos2%tamanho,
		tmp = v[para];

	v[para] = v[de];
	v[de] = tmp;
}

int menorValorIndice(int v[], int tamanho) {
	int indice = 0;
	int menorValor = v[0];

	for (int i = 0; i < tamanho; i++) {
		if (v[i] < menorValor) {
			indice = i;
			menorValor = v[i];
		}
	}

	return indice;
}