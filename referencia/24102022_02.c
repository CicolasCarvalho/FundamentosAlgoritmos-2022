// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 24 10 2022

/*
Exemplo:
    v1: {1, 3, 5}; v2: {2, 4, 6}
    ->
    {1, 2, 3, 4, 5, 6}

Entrada:
    2 vetores de n elementos

Processamento:
    receber o tamanho dos vetores e seus respectivos elementos

Saída:
   a intercalação dos 2 vetores
*/

#include <stdio.h>
#include <assert.h>

#include "24102022.h"

void intercalar(int a[], int b[], int c[], int tamanho);

void teste(void) {
    int v1[1] = {1, 3};
    int v2[1] = {2, 4};
    int v3[2];
    intercalar(v1, v2, v3, 1);

    assert(v3[0]==1);
    assert(v3[1]==2);
    assert(v3[2]==3);
    assert(v3[3]==4);
}

int main(void) {
    teste();

	int tamanho;

	printf("Insira o tamanho do vetor:\t");
	scanf("%i", &tamanho);

	int A[tamanho], B[tamanho], C[tamanho*2];

	receberValores(A, "A", tamanho);
	receberValores(B, "B", tamanho);
	intercalar(A, B, C, tamanho);

	mostrarVetor(C, tamanho*2);

    return 0;
}

void intercalar(int a[], int b[], int c[], int tamanho) {
	for (int i = 0; i < tamanho*2; i++) {
		int indice = (i/2);
		int* vetor = (i%2 ? b : a);

		c[i] = vetor[indice];
	}
}