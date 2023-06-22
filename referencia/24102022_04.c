// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 24 10 2022

/*
Exemplo:
    v1: {1, 2}; v2: {1, 2} -> sao identicos
    v1: {1, 2}; v2: {2, 1} -> sao iguais
    v1: {1, 2}; v2: {2, 3} -> sao diferentes

Entrada:
    2 vetores de n elementos

Processamento:
    receber os 2 vetores verificarem se são iguais,
    se não, verificar se todos elementos de A tem em B
    se não, não são iguais

Saída:
   se são identicos iguais ou diferentes
*/

#include <stdio.h>
#include <assert.h>

#include "24102022.h"

int vetorIdentico(int a[], int b[], int tamanho);
int vetorIgual(int a[], int b[], int tamanho);
int vetorInclui(int v[], int tamanho, int n);
void classificarVetores(int a[], int b[], int tamanho);

void teste(void) {
    int a[3] = {1, 2, 3};
    int b[3] = {1, 2, 3};
    int c[3] = {2, 1, 3};
    int d[3] = {4, 1, 3};

    assert(vetorIdentico(a, b, 3)==1);
    assert(vetorIgual(a, c, 3)==1);
    assert(vetorInclui(a, d, 3)==1);
}

int main(void) {
    teste();

	int tamanho;

	printf("Insira o tamanho dos vetores:\t");
	scanf("%i", &tamanho);

	int A[tamanho], B[tamanho];

	receberValores(A, "A", tamanho);
	receberValores(B, "B", tamanho);
	classificarVetores(A, B, tamanho);

	return 0;
}

int vetorIdentico(int a[], int b[], int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		if (a[i] != b[i]) {
			return 0;
		}
	}

	return 1;
}

int vetorIgual(int a[], int b[], int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		if (!vetorInclui(b, tamanho, a[i])) {
			return 0;
		}
	}

	return 1;
}

int vetorInclui(int v[], int tamanho, int n) {
	for (int i = 0; i < tamanho; i++) {
		if (v[i] == n) {
			return 1;
		}
	}

	return 0;
}

void classificarVetores(int a[], int b[], int tamanho) {
	if (vetorIdentico(A, B, tamanho))
		printf("A e B sao identicos\n");
	else if(vetorIgual(A, B, tamanho))
		printf("A e B contem os mesmos valores\n");
	else
		printf("A contem um valor que nÃ£o hÃ¡ em B\n");
}