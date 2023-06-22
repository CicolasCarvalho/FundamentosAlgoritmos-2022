// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 26 10 2022

/*
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
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>

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

void teste(void) {
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

int main(void) {
    Produto produtos[4];

    for (int i = 0; i < 4; i++) {
        cadastrarProduto(&produtos[i], i);
        printf("\n");
    }

    float media = mediaProdutos(produtos, 4);
    printf("A media dos produtos e de R$%.2f", media);

    return 0;
}

void flush(void) {
	char c = ' ';
	while (c != EOF && c != '\n') {
		c = fgetc(stdin);
	}
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