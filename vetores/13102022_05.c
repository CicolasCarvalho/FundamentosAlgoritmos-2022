// Ní­colas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 13 10 2022

/*
Exemplo:
    largura 11
    altura 5
    M = [
        "ACASAMCASWB",
        "CAXRFTPASAC",
        "ASXIEJHWTQA",
        "SAEOWMQZODB",
        "ACYKFWCAAVB",
    ] 
    palavra = "casa" ->
        Horizontal:
            linha: 0, coluna: [1, 4]
        Vertical:
            linha: [1, 4], coluna: 0
            linha: [0, 3], coluna: 1

Entrada:
    uma largura, uma altura, uma matriz LARGURAxALTURA, palavra chave

Processamento:
    pegar a largura e altura, criar uma matriz com esses dados, pegar linha por linha
    pegar a palavra chave, checar horizontalmente passando em todas as linhas e em cada posição analisando
    se os caracteres coincidem com a palavra chave, fazer a mesma coisa verticalmente
    passando coluna por coluna, caso encontre um valor que todas as letra coincidam
    escreva no console

Saí­da:
    todas as ocorrencias da palavra chave na matriz
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>

char maiuscula(char c);

int main(void) {
    int largura, altura;

    printf("qual a largura e altura do caca palavras:\t");
    scanf("%i %i", &largura, &altura);
    printf("\n");

	char palavra[largura+1];
	// char M[6][12] = {
	// 	"ACASAMCASWB\0",
	// 	"CAXRFTPASAC\0",
	// 	"ASXIEJHWTQA\0",
	// 	"SAEOWMQZODB\0",
	// 	"ACYKFWCAAVB\0",
    //  "\0\0\0\0\0\0\0\0\0\0\0\0"
	// };
    char M[altura+1][largura+1];
    for (int i = 0; i < largura; i++) {
        M[altura][i] = '\0';
    }

    // colocado aqui por bug com alocação
    // não foi entendido muito o motivo
    // mas imagino que seja por culpa da
    // array bidimensional não definida
    // com o calloc
    char linha[largura+1];
    char coluna[altura+1];

    for (int i = 0; i < altura; i++) {
        printf("Insira a linha %i do caca palavras:\n", i);
        scanf("%s", M[i]);

        M[i][largura] = '\0';
    }

    printf("Insira a palavra a ser procurada:\n");
    scanf("%s", palavra);

    int palavraChaveLen = strlen(palavra);
    printf("o tamanho da palavra %s e: %i\n\n", palavra, palavraChaveLen);

    for (int i = 0; i < palavraChaveLen; i++) {
        palavra[i] = maiuscula(palavra[i]);
    }

    printf("foram encontrada ocorrencias em:\n");
    // checar horizontalmente
    printf("\tHorizontal:\n");
    for (int i = 0; i < altura; i++) {
        strcpy(linha, M[i]);

        for (int j = 0; j < largura+1-palavraChaveLen; j++) {
            for (int k = 0; k < palavraChaveLen; k++) {
                if (linha[j+k] != palavra[k]) {
                    break;
                } else if (k+1 == palavraChaveLen) {
                    printf("\t\tlinha: %i, coluna: [%i, %i]\n", i, j, j+k);
                }
            }
        }
    }

    // checar verticalmente
    printf("\tVertical:\n");
    for (int i = 0; i < largura; i++) {
        for (int c = 0; c < altura+1; c++) {
            coluna[c] = M[c][i];
        }

        for (int j = 0; j < altura+1-palavraChaveLen; j++) {
            for (int k = 0; k < palavraChaveLen; k++) {
                if (coluna[j+k] != palavra[k]) {
                    break;
                } else if (k+1 == palavraChaveLen) {
                    printf("\t\tlinha: [%i, %i], coluna: %i\n", j, j+k, i);
                }
            }
        }
    }

	return 0;
}

char maiuscula(char c) {
    // minuscula -> [97, 122]
    // maiuscula -> [65, 90]
    return (c>90)?c-32:c;
}