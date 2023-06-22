// N�colas dos Santos Carvalho - 128660
// Ci�ncia da Computa��o - UEM
// 26 10 2022

/*
Exemplo:
    aluno: N�colas dos Santos Carvalho
    ra: 128660
    ->
    128660 - N�colas dos Santos Carvalho

Entradas:
    ra, nome

Processamento:
    pegar o nome e o ra e colocar na struct passada por referencia

Saida:
    ra e nome
*/

#include <stdio.h>
#include <string.h>

// DEFINI��O ALUNO

typedef struct {
    int RA;
    char nome[50];
} Aluno;

void cadastrarAluno(Aluno* aluno);
void mostrarAluno(Aluno* aluno);

// FIM DEFINI��O ALUNO

void flush(void);

int main(void) {
    Aluno aluno;
    cadastrarAluno(&aluno);
    mostrarAluno(&aluno);

    return 0;
}

void flush(void) {
	char c = ' ';
	while (c != EOF && c != '\n') {
		c = fgetc(stdin);
	}
}

void cadastrarAluno(Aluno* aluno) {
    printf("Insira o RA do aluno:\n");
    scanf("%i", &aluno->RA);
    flush();
    printf("Insira o nome do aluno:\n");
    fgets(aluno->nome, 50, stdin);
    aluno->nome[strlen(aluno->nome)-1] = '\0';
}

void mostrarAluno(Aluno* aluno) {
    printf("\n%i - %s\n", aluno.RA, aluno.nome);
}