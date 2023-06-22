// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 17 10 2022

#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct {
	int RA;
	char nome[30];
	char curso[30];
	int serie;
} Aluno;

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

typedef struct {
	int RA;
	char nome[30];
	float notas[3];
	float media;
} AlunoFundAlgoritmo;

typedef struct {
    char nome[30];
    float potencia;
    float tempoAtividade;
} Eletrodomestico;

void flush(void);
int verificarCC1(Aluno a);
int maiorNotaPrimeiraProva(AlunoFundAlgoritmo a[5]);
int maiorMedia(AlunoFundAlgoritmo a[5]);
int menorMedia(AlunoFundAlgoritmo a[5]);
int aprovado(AlunoFundAlgoritmo a);
float consumoTotalEletrosDia(Eletrodomestico e[5]);

void teste(void) {
	// 1)
    {
        Aluno a = {
            .RA = 128660,
            .nome = "nicolas carvalho",
            .curso = "ciencia da computacao",
            .serie = 1
        };

        assert(verificarCC1(a)==1);
    }

    // 2)
    {
        Relogio r1 = converterMinutos(61);
        Relogio r2 = converterMinutos(55);

        assert(r1.horas==1 && r1.minutos==1);
        assert(r2.horas==0 && r2.minutos==55);
    }

    // 3)
    {
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

    // 4)
    {
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
}

int main(void) {
    teste();

    // 1)
    {
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
    }

    // 2)
    {
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
        int minutosDecorridos;
        Relogio relogio;

        printf("Insira a quantidade de minutos decorridos:\n");
        scanf("%i", &minutosDecorridos);

        relogio = converterMinutos(minutosDecorridos);

        printf("%.2i:%.2i\n", relogio.horas, relogio.minutos);
    }

    // 3)
    {
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
    }

    // 4)
    {
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

float consumoTotalEletrosDia(Eletrodomestico e[5]) {
    float total = 0.0;

    for (int i = 0; i < 5; i++) {
        total += e[i].potencia*e[i].tempoAtividade;
    }

    return total;
}