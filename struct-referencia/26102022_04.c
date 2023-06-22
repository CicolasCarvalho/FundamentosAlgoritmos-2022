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

// FIM DEFINIÇÃO PRODUTO

void flush(void);
float mediaProdutos(Produto produtos[], int quantidade);
void menosDe10Produtos(Produto produtos[], int quantidade);

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
    printf("A media dos produtos e de %.2f", media);

    menosDe10Produtos(produtos, 4);

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

void menosDe10Produtos(Produto produtos[], int quantidade) {
    printf("\nProdutos por menos de R$10,00:\n");
    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].preco < 10) {
            printf("R$%.2f - %s\n", produtos[i].preco, produtos[i].nome);
        }
    }
}