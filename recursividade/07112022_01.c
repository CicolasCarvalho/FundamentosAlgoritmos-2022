// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 07112022

/*
Exemplos:
    1, 2, 3, 4, -5;
    1, 2, -3

Entrada:
    numeros

Processamento:
    pegar um numero verificar se e menor de 0 se sim parar de pegar numeros
    se nao continuar pegando

Saída:
    nada
*/

#include <stdio.h>

void pegarNumero(void);

int main(void) {
	pegarNumero();

	return 0;
}

void pegarNumero(void) {
	int n;

	printf("Insira um numero:\n");
	scanf("%i", &n);

	if (n<0)
		return;

	pegarNumero();
}