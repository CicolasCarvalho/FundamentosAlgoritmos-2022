// N�colass dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 24 10 2022

#include <stdio.h>

#define PI 3.1415

void areaCirculo(float *area, float raio);
void setDobro(int* a, int* b);

int main(void) {
	float area, raio;
	areaCirculo(&area, raio);

	printf("%f\n", area);

	int a, b;

	printf("Insira um numero:\t");
	scanf("%i", &a);
	setDobro(&a, &b);

	printf("a = %i\nb = %i\n", a, b);

	return 0;
}

void areaCirculo(float *area, float raio) {
	*area = PI*raio*raio;
}

void setDobro(int* a, int* b) {
	*b = *a*2;
}