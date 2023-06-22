// Ní­colas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 13 10 2022

#include <stdio.h>
#include <assert.h>
#include <string.h>

float getMaior7(float vetor[7]);
int contem5(int v[5], int item);
int soma4x3(int v[4][3]);
float maiorNDiagonal3x3(float m[3][3]);
char maiuscula(char c);

void teste(void) {
    // 1)
    {
    	float v[7] = {0,1,2,3,4,5,10};
    
        assert(getMaior7(v)==10);
    }

    // 2)
    {
    	int v[5] = {0, 1, 2, 3, 4};
    
        assert(contem5(v, 0)==1);
        assert(contem5(v, 1)==1);
        assert(contem5(v, 2)==1);
        assert(contem5(v, 3)==1);
        assert(contem5(v, 4)==1);
        assert(contem5(v, 5)==0);
    }

    // 3)
    {
		int v[4][3] = {
			{1,  2,  3 },
			{4,  5,  6 },
			{7,  8,  9 },
			{10, 11, 12}
		};

		assert(soma4x3(v)==78);
    }

    // 4)
    {
		float m[3][3] = {
			{1, 3, 3},
			{3, 2, 3},
			{3, 3, 3}
		};

		assert(maiorNDiagonal3x3(m)==3);
    }
}

int main(void) {
    teste();
	// 1)
	{
		/*
		Exemplo:
		    0, 1, 10, 20, 25, 50, 100 ->
		    [0, 0.01, 0.10, 0.20, 0.25, 0.50, 1]

		Entrada:
		    7 números

		Processamento:
		    Comparar qual numero e maior que todos, e dividir todos os elementos da array por ele

		Saí­da:
		    A lista com todos os elementos divididos
		*/

		float vetor[7], maior;

	    for(int i = 0; i < 7; i++) {
	        printf("Insira o valor %i do vetor:\t", i+1);
	        scanf("%f", &vetor[i]);
	    }

	    maior = getMaior7(vetor);

	    printf("\nvetor = [");
	    for(int i = 0; i < 7; i++) {
	        vetor[i] /= maior;

	        printf("%.3f", vetor[i]);

	        if(i+1 < 7) printf(", ");
	        else printf("]\n");
	    }
	}

	// 2)
	{
		/*
		Exemplo:
		    [0, 1, 2, 3, 4]
		    [0, 1, 2, 3, 4, 5, 6] ->
		    [0, 1, 2, 3, 4]

		Entrada:
		    uma matriz de 5 posiçoes e outra de 7

		Processamento:
		    Comparar se há o numero da segunda matriz na primeira se sim aumenta a quantidade
		    de numeros em comum, depois passsar por todos os numero da m5 e verificar em m7 e
		    adicionar na matriz intersecao

		Saí­da:
		    A lista com todos os elementos em comum
		*/

		int a[5], b[7], qtd;

	    for(int i = 0; i < 5; i++) {
	        printf("Insira a posicao %i do vetor de 5:\t", i);
	        scanf("%i", &a[i]);
	    }

	    printf("\n");

	    for(int i = 0; i < 7; i++) {
	        printf("Insira a posicao %i do vetor de 7:\t", i);
	        scanf("%i", &b[i]);

	        if(contem5(a, b[i]))
	            qtd++;
	    }

	    int c[1];
	    int k = 0;

	    for(int i = 0; i < 7; i++) {
	        for(int j = 0; j < 5; j++) {
	            if(b[i] == a[j]) {
	                c[k++] = b[i];
	            }
	        }
	    }

	    printf("\na interseccao de a e b é = {");
	    for(int i = 0; i < qtd; i++) {
	        printf("%i", c[i]);

	        if(i+1 < qtd) printf(", ");
	    }
	    printf("}\n");
	}

	// 3)
	{
		/*
		Exemplo:
		    M = [ 
		    	1, 2, 3,
		    	4, 5, 6,
		    	7, 8, 9,
		    	10, 11, 12
		    ] -> 78

		Entrada:
		    uma matriz 3 por 4

		Processamento:
			passar elemento por eemento somando em uma variavel acc

		Saí­da:
		    a soma de todos os numeros
		*/

		int m[4][3], soma;

		for (int y = 0; y < 4; y++) {
			printf("insira a linha %i:\n", y);
			for (int x = 0; x < 3; x++) {
				scanf("%i", &m[y][x]);
			}
		}

		soma = soma4x3(m);

		printf("a soma de todos elementos de m sao: %i\n", soma);
	}

	// 4)
	{
		/*
		Exemplo:
		    M = [
				1, 2, 3,
				3, 2, 3,
				3, 3, 3
		    ]

		Entrada:
		    uma matriz 3x3

		Processamento:
			pegar o maior numero na diagonal e dividir todos os elementos por o maior numero

		Saí­da:
		    A lista com todos os elementos divididos pelo maior numero da diagona principal
		*/
		float m[3][3];

		for (int y = 0; y < 3; y++) {
			printf("Insira a linha %i:\n", y);
			for (int x = 0; x < 3; x++) {
				scanf("%f", &m[y][x]);
			}
		}

		float maior = maiorNDiagonal3x3(m);

		printf("m = [\n");
		for (int y = 0; y < 3; y++) {
			printf("\t");
			for (int x = 0; x < 3; x++) {
				m[y][x] /= maior;

				printf("%f", m[y][x]);
	        	if(y+1 < 3 || x+1 < 3) printf(", ");
			}
			printf("\n");
		}
		printf("]\n");
	}

	// 5)
	{
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
	}

	return 0;
}

float getMaior7(float vetor[7]) {
    float maior = vetor[0];

    for(int i = 1; i < 7; i++) {
        if(vetor[i] > maior)
            maior = vetor[i];
    }

    return maior;
}

int contem5(int v[5], int item) {
    int tem = 0;

    for(int i = 0; i < 5; i++) {
        if(v[i] == item)
            return 1;
    }

    return 0;
}

int soma4x3(int m[4][3]) {
	int soma = 0;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 3; x++) {
			soma += m[y][x];
		}
	}

	return soma;
}

float maiorNDiagonal3x3(float m[3][3]) {
	float maior = m[0][0];

	for (int i = 1; i < 3; ++i) {
		if (m[i][i] > maior) {
			maior = m[i][i];
		}
	}

	return maior;
}

char maiuscula(char c) {
    // minuscula -> [97, 122]
    // maiuscula -> [65, 90]
    return (c>90)?c-32:c;
}
