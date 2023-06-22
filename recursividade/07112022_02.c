// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 07112022

/*
Teste:
+---------+---------------+
|    n    |   resultado   |
+---------+---------------+
|    0    |       1       |
+---------+---------------+
|    1    |       1       |
+---------+---------------+
|    2    |       3       |
+---------+---------------+
|    3    |       5       |
+---------+---------------+
|    4    |       11      |
+---------+---------------+
|    5    |       21      |
+---------+---------------+
*/

#include <stdio.h>
#include <assert.h>

int func(int n);

void teste(void) {
	assert(func(0) == 1);
	assert(func(1) == 1);
	assert(func(5) == 21);
}

int main(void) {
	teste();
	int n;

	printf("Insira um numero:\t");
	scanf("%i", &n);

	printf("%i\n", func(n));

	return 0;
}

int func(int n) {
	if (n == 0)
		return (1);
	if (n == 1)
		return (1);
	else
		return func(n-1) + 2*func(n-2);
}
