// Ní­colas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 17 10 2022

/*
Exemplo:
    61 minutos -> 1 hora e 1 minuto
    55 minutos -> 55 minutos

Entrada:
    quantidade de tempo em minutos

Processamento:
    receber o tempo decorrido dividir por 60 inteiro o resultado e a quantidade de horas passadas;
    pegar o modulo do tempo por 60 essee serão os minutos

Saída:
    O tempo decorrido em horas e minutos
*/

#include <stdio.h>
#include <assert.h>

// DEFINICAO RELOGIO

typedef struct {
	int horas;
	int minutos;
} Relogio;

Relogio converterMinutos(int minutos) {
	Relogio r;
	r.horas = minutos/60;
	r.minutos = minutos%60;
	return r;
}

//FIM DEFINICAO RELOGIO

void teste(void) {
	Relogio r1 = converterMinutos(61);
	Relogio r2 = converterMinutos(55);

	assert(r1.horas==1 && r1.minutos==1);
	assert(r2.horas==0 && r2.minutos==55);
}

int main(void) {
	teste();

	int minutosDecorridos;
	Relogio relogio;

	printf("Insira a quantidade de minutos decorridos:\n");
	scanf("%i", &minutosDecorridos);

	relogio = converterMinutos(minutosDecorridos);

	printf("%.2i:%.2i\n", relogio.horas, relogio.minutos);

	return 0;
}