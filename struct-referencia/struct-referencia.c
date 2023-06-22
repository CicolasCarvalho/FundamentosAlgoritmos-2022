// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 26 10 2022

#include <stdio.h>
#include <assert.h>
#include <string.h>

// DEFINIÇÃO ALUNO

typedef struct {
    int RA;
    char nome[50];
} Aluno;

void cadastrarAluno(Aluno* aluno);
void mostrarAluno(Aluno* aluno);

// FIM DEFINIÇÃO ALUNO

// DEFINIÇÃO PRODUTO

typedef struct {
    int codigo;
    char nome[50];
    float preco;
} Produto;

void cadastrarProduto(Produto* prod, int n);

// FIM DEFINIÇÃO ALUNO

void flush(void);
float mediaProdutos(Produto produtos[], int quatidade);
void menosDe10Produtos(Produto produtos[], int quantidade);

void teste(void) {
    // 3 e 4)
    {
        Produto prodTeste[4] = {
            {
                .codigo = 1,
                .nome = "coca cola",
                .preco = 4.00
            },
            {
                .codigo = 2,
                .nome = "picanha",
                .preco = 45.00
            },
            {
                .codigo = 3,
                .nome = "batata",
                .preco = 5.00
            },
            {
                .codigo = 4,
                .nome = "whiskey",
                .preco = 150.00
            }
        };

        assert(mediaProdutos(prodTeste, 4)==51);
    }
}

int main(void) {
    teste();

    // 1 e 2)
    {
        /*
        Exemplo:
            aluno: Nícolas dos Santos Carvalho
            ra: 128660
            ->
            128660 - Nícolas dos Santos Carvalho

        Entradas:
            ra, nome

        Processamento:
            pegar o nome e o ra e colocar na struct passada por referencia

        Saida:
            ra e nome
        */
        Aluno aluno;
        cadastrarAluno(&aluno);
        mostrarAluno(&aluno);
    }

    // 3 e 4)
    {
        /*
        3)
            Exemplo:
                codigo = 1; nome = "coca cola"; preco = 4.00
                codigo = 2; nome = "picanha"; preco = 45.00
                codigo = 3; nome = "batata"; preco = 5.00
                codigo = 4; nome = "whiskey"; preco = 150.00
                ->
                media: RS51

            Entradas:
                4 produtos (codigo, nome, preco)

            Processamento:
                pegar os quatros produtos somar seus precos e dividir por 4

            Saida:
                media de precos

        4)
            Exemplo:
                codigo = 1; nome = "coca cola"; preco = 4.00
                codigo = 2; nome = "picanha"; preco = 45.00
                codigo = 3; nome = "batata"; preco = 5.00
                codigo = 4; nome = "whiskey"; preco = 150.00
                ->
                produtos abaixo de R$10:
                    R$4,00 - coca cola
                    R$5,00 - batata

            Entradas:
                4 produtos (codigo, nome, preco)

            Processamento:
                Além do exercício 3, pegar todos os produtos com o valor abaixo de R$10

            Saida:
                todos os produtos com o preço abaixo de R$10
        */
        Produto produtos[4];

        for (int i = 0; i < 4; i++) {
            cadastrarProduto(&produtos[i], i);
            printf("\n");
        }

        float media = mediaProdutos(produtos, 4);
        printf("A media dos produtos e de %.2f", media);

        menosDe10Produtos(produtos, 4);
    }

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
    printf("\n%i - %s\n", aluno->RA, aluno->nome);
}

void cadastrarProduto(Produto* prod, int n) {
    printf("Insira o codigo do produto %i:\t", n);
    scanf("%i", &prod->codigo);
    flush();

    printf("Insira o nome do produto %i:\t", n);
    fgets(prod->nome, 50, stdin);
    prod->nome[strlen(prod->nome)-1] = '\0';

    printf("Insira o preco do produto %i:\t", n);
    scanf("%f", &prod->preco);
    flush();
}

float mediaProdutos(Produto produtos[], int quantidade) {
    float media = 0.0;

    for (int i = 0; i < quantidade; i++) {
        media += produtos[i].preco/quantidade;
    }

    return media;
}

void menosDe10Produtos(Produto produtos[], int quantidade) {
    printf("\nProdutos por menos de R$10,00:\n");
    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].preco < 10) {
            printf("R$%.2f - %s\n", produtos[i].preco, produtos[i].nome);
        }
    }
}