// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 07112022

/*
Exemplos:
    2^0 -> 1
    2^1 -> 2
    2^10 -> 1024

Entrada:
    base; expoente

Processamento:
    multiplicar a base n(expoente) vezes ate chegarmos na potencia
    desejada

Saída:
    base^expoente
*/

#include <stdio.h>
#include <assert.h>

int potencia(int base, int exp);

void teste(void) {
	assert(potencia(2, 0) == 1);
	assert(potencia(2, 1) == 2);
	assert(potencia(2, 10) == 1024);
}

int main(void) {
	teste();

	int base, expoente;

	printf("Insira x e y (x^y):\n");
	scanf("%i %i", &base, &expoente);

	printf("x^y = %i", potencia(base, expoente));

	return 0;
}

int potencia(int base, int exp) {
	if (exp == 0)
		return 1;
	
	return base*potencia(base, exp-1);
}