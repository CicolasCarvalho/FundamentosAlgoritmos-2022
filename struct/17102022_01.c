// Ní­colas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 17 10 2022

/*
Exemplo:
    RA: 128660; Nome: Nícolas Carvalho; Curso: Ciência da computação; Serie: 1
    RA: 128661; Nome: Nicholas dos Santos; Curso: Ciência da computação; Serie: 2
    RA: 128662; Nome: Nikolas Orlof; Curso: Mecânica; Serie: 1
    RA: 128663; Nome: Nicole Machado; Curso: Administração; Serie: 3
    RA: 128664; Nome: Hudson Henrique; Curso: Ciência da Computação; Serie: 1
    ->
    - 128660 / Nícolas Carvalho
    - 128664 / Hudson Henrique

Entrada:
    5 alunos contendo ra, nome, serie, curso

Processamento:
    receber os 5 alunos e salva-los utilizando uma struct;
    ir aluno por aluno verificando se o curso é Ciência da Computação
    se for escrever na tela o RA e o nome

Saída:
    Os alunos, cujo o curso é ciência da computação e são da 1 série
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct {
	int RA;
	char nome[30];
	char curso[30];
	int serie;
} Aluno;

void flush(void);
int verificarCC1(Aluno a);

void teste(void) {
	Aluno a = {
		.RA = 128660,
		.nome = "nicolas carvalho",
		.curso = "ciencia da computacao",
		.serie = 1
	};

	assert(verificarCC1(a)==1);
}

int main(void) {
	teste();
	Aluno alunos[5];

	for (int i = 0; i < 5; ++i) {
		printf("Insira o numero de RA do aluno %i:\t", i+1);
		scanf("%i", &alunos[i].RA);
		flush();

		printf("Insira o nome do aluno %i:\t", i+1);
		fgets(alunos[i].nome, 30, stdin);
		alunos[i].nome[strlen(alunos[i].nome)-1] = '\0';

		printf("Insira o curso do aluno %i:\t", i+1);
		fgets(alunos[i].curso, 30, stdin);
		alunos[i].curso[strlen(alunos[i].curso)-1] = '\0';

		printf("Insira a serie do aluno %i:\t", i+1);
		scanf("%i", &alunos[i].serie);
	}

	printf("\nAlunos Ciencia da Computacao 1 ano:\n");
	for (int i = 0; i < 5; ++i) {
		if (verificarCC1(alunos[i])) {
			printf("- %i, %s\n", alunos[i].RA, alunos[i].nome);
		}
	}

	return 0;
}

void flush(void) {
	char c = ' ';
	while (c != EOF && c != '\n') {
		c = fgetc(stdin);
	}
}

int verificarCC1(Aluno a) {
	return a.serie == 1 && !strcmp(a.curso, "ciencia da computacao");
}