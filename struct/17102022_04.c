// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 17 10 2022

/*
Exemplo:
    nome = "geladeira", potencia = 500, tempoAtividade = 24
    nome = "computador", potencia = 500, tempoAtividade = 12
    nome = "ar condicionado", potencia = 1400, tempoAtividade = 6
    nome = "maquina de lavar roupa", potencia = 1000, tempoAtividade = 4
    nome = "televisao", potencia = 90, tempoAtividade = 12
    dias: 1
    ->
    Consumo total = 31480.00kW
    Consumo relativo em 1 dias:
        - geladeira, 12000.00kW, 24.0h: 38%
        - computador, 6000.00kW, 12.0h: 19%
        - ar condicionado, 8400.00kW, 6.0h: 27%
        - maquina de lavar roupa, 4000.00kW, 4.0h: 13%
        - televisao, 1080.00kW, 12.0h: 3%

Entrada:
    5 eletros domestico
    dias passados

Processamento:
    calcular o consumo total por dia e multiplicar pela quantidade de dias
    dividir o consumo por dia dos eletrosdomesticos e descobrir a por centagem
    multiplicar essa por centagem pelos dias

Saída:
    consumo total
    proporcao do consumo por eletrodomestico
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct {
    char nome[30];
    float potencia;
    float tempoAtividade;
} Eletrodomestico;

void flush(void);
float consumoTotalEletrosDia(Eletrodomestico e[5]);

void teste(void) {
    Eletrodomestico eletrosTeste[5] = {
        {
            .nome = "geladeira",
            .potencia = 500,
            .tempoAtividade = 24
        }, {
            .nome = "computador",
            .potencia = 500,
            .tempoAtividade = 12
        }, {
            .nome = "ar condicionado",
            .potencia = 1400,
            .tempoAtividade = 6
        }, {
            .nome = "maquina de lavar roupa",
            .potencia = 1000,
            .tempoAtividade = 4
        }, {
            .nome = "televisao",
            .potencia = 90,
            .tempoAtividade = 12
        }
    };

    assert(consumoTotalEletrosDia(eletrosTeste)==31480);
}

int main(void) {
    teste();

    Eletrodomestico eletros[5];

    for (int i = 0; i < 5; i++) {
		printf("Insira o nome do eletrodomestrico %i:\t", i+1);
		fgets(eletros[i].nome, 30, stdin);
        eletros[i].nome[strlen(eletros[i].nome)-1] = '\0';

		printf("Insira a potencia[kW] do eletrodomestico %i:\t", i+1);
		scanf("%f", &eletros[i].potencia);

		printf("Inisra o tempo de atividade[h/dia] do eletrodomestico %i:\n", i+1);
		scanf("%f", &eletros[i].tempoAtividade);
        flush();
	}

    int dias;
    printf("\nQuantidade de dias:\t");
    scanf("%i", &dias);

    float consumoTotal = consumoTotalEletrosDia(eletros)*dias;
    printf("\nConsumo total = %.2fkW", consumoTotal);

    printf("\nConsumo relativo em %i dias:\n", dias);
    for (int i = 0; i < 5; i++) {
        float consumoRelativo = eletros[i].potencia*eletros[i].tempoAtividade*dias;
        float tempoTotal = eletros[i].tempoAtividade*dias;
        float gastoRelativo = consumoRelativo/consumoTotal;

        printf(
            "\t- %s, %.2fkW, %.1fh: %.0f%\n",
            eletros[i].nome,
            consumoRelativo,
            tempoTotal,
            gastoRelativo*100
        );
    }

    return 0;
}

void flush(void) {
	char c = ' ';
	while (c != EOF && c != '\n') {
		c = fgetc(stdin);
	}
}

float consumoTotalEletrosDia(Eletrodomestico e[5]) {
    float total = 0.0;

    for (int i = 0; i < 5; i++) {
        total += e[i].potencia*e[i].tempoAtividade;
    }

    return total;
}