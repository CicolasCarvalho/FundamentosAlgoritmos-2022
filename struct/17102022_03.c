// Ní­colas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 17 10 2022

/*
Exemplo:
    RA = 128660, nome = "nicolas carvalho", notas = {8.5, 9.5, 8.9}, media = 8.9,
    RA = 000001, nome = "hudson henrique", notas = {4, 5, 6}, media = 5.0,
    RA = 000002, nome = "mateus track", notas = {7, 8, 9}, media = 8.0,
    RA = 000003, nome = "rafael takahashi", notas = {7, 10, 10}, media = 9.0,
    RA = 000004, nome = "joao vitor pazinato", notas = {8, 10, 6}, media = 8.0
    ->
    maior nota primeira porva: 128660 / nicolas carvalho
    maior media: 000003 / rafael takahashi
    menor media: 000001 / hudson henrique
    aprovados:
        - 128660 aprovado
        - 000001 reprovado
        - 000002 aprovado
        - 000003 aprovado
        - 000004 aprovado

Entrada:
    alunos e suas respectivas notas

Processamento:
    pegar quem tiroua maior nota na primeira prova
    calcular as medias das provas
    pegar quem teve a maior media e a menor
    ir aluno por aluno checando se foi aprovado ou reprovado

Saída:
    a maior nota na primeira prova
    maior media
    menor media
    lista da situação de cada aluno
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct {
	int RA;
	char nome[30];
	float notas[3];
	float media;
} AlunoFundAlgoritmo;

void flush(void);
int maiorNotaPrimeiraProva(AlunoFundAlgoritmo a[5]);
int maiorMedia(AlunoFundAlgoritmo a[5]);
int menorMedia(AlunoFundAlgoritmo a[5]);
int aprovado(AlunoFundAlgoritmo a);

void teste(void) {
    AlunoFundAlgoritmo alunosTeste[5] = {
        {
            .RA = 128660,
            .nome = "nicolas carvalho",
            .notas = {8.5, 9.5, 8.9},
            .media = 8.9,
        }, {
            .RA = 000001,
            .nome = "hudson henrique",
            .notas = {4, 5, 6},
            .media = 5.0,
        }, {
            .RA = 000002,
            .nome = "mateus track",
            .notas = {7, 8, 9},
            .media = 8.0,
        }, {
            .RA = 000003,
            .nome = "rafael takahashi",
            .notas = {7, 10, 10},
            .media = 9.0,
        }, {
            .RA = 000004,
            .nome = "joao vitor pazinato",
            .notas = {8, 10, 6},
            .media = 8.0,
        }
    };

    assert(maiorNotaPrimeiraProva(alunosTeste)==0);
    assert(maiorMedia(alunosTeste)==3);
    assert(menorMedia(alunosTeste)==1);
    assert(aprovado(alunosTeste[0])==1);
    assert(aprovado(alunosTeste[1])==0);
}

int main(void) {
    teste();

	AlunoFundAlgoritmo alunos[5];

	for (int i = 0; i < 5; i++) {
		printf("Insira o numero de RA do aluno %i:\t", i+1);
		scanf("%i", &alunos[i].RA);
		flush();

		printf("Insira o nome do aluno %i:\t", i+1);
		fgets(alunos[i].nome, 30, stdin);
		alunos[i].nome[strlen(alunos[i].nome)-1] = '\0';

		alunos[i].media = 0.0;
		printf("Inisra as notas das 3 notas do aluno %i:\n", i+1);
		for (int j = 0; j < 3; j++) {
			scanf("%f", &alunos[i].notas[j]);
			alunos[i].media += alunos[i].notas[j]/3.0;
		}
	}

	AlunoFundAlgoritmo alunoMaiorNota = alunos[maiorNotaPrimeiraProva(alunos)];
	printf(
		"- Maior nota primeira prova: %i, %s foi %.1f\n",
		alunoMaiorNota.RA,
		alunoMaiorNota.nome,
		alunoMaiorNota.notas[0]
	);

	AlunoFundAlgoritmo alunoMaiorMedia = alunos[maiorMedia(alunos)];
	printf(
		"- Maior media: %i, %s foi %.1f\n",
		alunoMaiorMedia.RA,
		alunoMaiorMedia.nome,
		alunoMaiorMedia.media
	);

	AlunoFundAlgoritmo alunoMenorMedia = alunos[menorMedia(alunos)];
	printf(
		"- Menor media: %i, %s foi %.1f\n",
		alunoMenorMedia.RA,
		alunoMenorMedia.nome,
		alunoMenorMedia.media
	);

    printf("\n- situacao dos alunos:\n");
	for (int i = 0; i < 5; i++) {
		printf("%i, %s foi: ", alunos[i].RA, alunos[i].nome);
		if (aprovado(alunos[i])) printf("aprovado\n");
		else printf("reprovado!!!\n");
	}

	return 0;
}

void flush(void) {
	char c = ' ';
	while (c != EOF && c != '\n') {
		c = fgetc(stdin);
	}
}

int maiorNotaPrimeiraProva(AlunoFundAlgoritmo a[5]) {
	int indiceMaiorNota = 0;
	float maiorNota = 0.0;

	for (int i = 0; i < 5; i++) {
		if (a[i].notas[0] > maiorNota) {
			maiorNota = a[i].notas[0];
			indiceMaiorNota = i;
		}
	}

	return indiceMaiorNota;
}

int maiorMedia(AlunoFundAlgoritmo a[5]) {
	int indiceMaiorMedia = 0;
	float maiorMediaValor = 0.0;

	for (int i = 0; i < 5; i++) {
		if (a[i].media > maiorMediaValor) {
			maiorMediaValor = a[i].media;
			indiceMaiorMedia = i;
		}
	}

	return indiceMaiorMedia;
}

int menorMedia(AlunoFundAlgoritmo a[5]) {
	int indiceMenorMedia = 0;
	float menorMediaValor = 10.0;

	for (int i = 0; i < 5; i++) {
		if (a[i].media < menorMediaValor) {
			menorMediaValor = a[i].media;
			indiceMenorMedia = i;
		}
	}

	return indiceMenorMedia;
}

int aprovado(AlunoFundAlgoritmo a) {
	return a.media>=6.0;
}
