#include <stdio.h>
#include <assert.h>
#include <string.h>

void receberValores(int v[], char* mensagem, int tamanho);
void mostrarVetor(int v[], int tamanho);
int qtdPares(int v[], int tamanho);
void intercalar(int a[], int b[], int c[], int tamanho);
void swapVetor(int v[], int tamanho, int pos1, int pos2);
int menorValorIndice(int v[], int tamanho);
int vetorIdentico(int a[], int b[], int tamanho);
int vetorIgual(int a[], int b[], int tamanho);
int vetorInclui(int v[], int tamanho, int n);
void classificarVetores(int a[], int b[], int tamanho);
int maiorNumero(int v[3][3]);
void colocarDiagonal(int v[5][5], int diagonal[5]);

int teste(void) {
    // 1)
    {
        int t[6] = {1, 2, 3, 4, 5, 6};

        assert(qtdPares(t, 6)==3);
    }

    // 2)
    {
        int v1[2] = {1, 3};
        int v2[2] = {2, 4};
        int v3[4];
        intercalar(v1, v2, v3, 2);

        assert(v3[0]==1);
        assert(v3[1]==2);
        assert(v3[2]==3);
        assert(v3[3]==4);
    }

    // 3)
    {
        int a[10] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int indice = menorValorIndice(a, 10);

        swapVetor(a, 10, indice, 0);
        assert(indice==1);
        assert(a[0] == 1);
        assert(a[1] == 10);
    }

    // 4)
    {
        int a[3] = {1, 2, 3};
        int b[3] = {1, 2, 3};
        int c[3] = {2, 1, 3};
        int d[3] = {4, 1, 3};

        assert(vetorIdentico(a, b, 3)==1);
        assert(vetorIgual(a, c, 3)==1);
        assert(vetorInclui(d, 3, 4)==1);
    }

    // 5)
    {
        int v[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        assert(maiorNumero(v)==9);
    }

    // 6)
    {
        int m[5][5] = {
            {1, 2, 3, 4, 5},
            {1, 2, 3, 4, 5},
            {1, 2, 3, 4, 5},
            {1, 2, 3, 4, 5},
            {1, 2, 3, 4, 5}
        };

        int d[5] = {0, 0, 0, 0, 0};

        colocarDiagonal(m, d);

        for (int i = 0; i < 5; i++) {
            assert(m[i][i]==d[i]);
        }
    }
}

int main(void) {
    teste();
    printf("Ex. %i:\n", 1);
    // 1)
    {
        /*
        Exemplo:
            {1, 2, 3, 4, 5, 6} -> 3 elementos par

        Entrada:
            um vetor de n valores

        Processamento:
            receber o tamanho do vetor e pegar os elementos

        Saída:
            números de elementos par
        */
        int tamanho;

        printf("Insira o tamanho do vetor:\t");
        scanf("%i", &tamanho);

        int v[tamanho];

        receberValores(v, "", tamanho);

        int pares = qtdPares(v, tamanho);
        printf("len({(x) E v : x mod 2 == 0}) = %i\n", pares);
    }

    printf("Ex. %i:\n", 2);
    // 2)
    {
        /*
        Exemplo:
            v1: {1, 3, 5}; v2: {2, 4, 6}
            ->
            {1, 2, 3, 4, 5, 6}

        Entrada:
            2 vetores de n elementos

        Processamento:
            receber o tamanho dos vetores e seus respectivos elementos

        Saída:
            a intercalação dos 2 vetores
        */
        int tamanho;

        printf("Insira o tamanho do vetor:\t");
        scanf("%i", &tamanho);

        int A[tamanho], B[tamanho], C[tamanho*2];

        receberValores(A, "A", tamanho);
        receberValores(B, "B", tamanho);
        intercalar(A, B, C, tamanho);

        mostrarVetor(C, tamanho*2);
    }

    printf("Ex. %i:\n", 3);
    // 3)
    {
        /*
        Exemplo:
            {10, 2, 4, 3, 5, 8, 7, 6, 9, 1}
            ->
            {1, 2, 4, 3, 5, 8, 7, 6, 9, 10}

        Entrada:
            um vetor de 10 elementos

        Processamento:
            receber o vetor pegar o indice do menor valor
            substituir o incdice pelo 0 e o 0 pelo indice

        Saída:
            o vetor inserido com o menor numero em primeiro
        */
        int v[10];

        receberValores(v, "", 10);
        int indice = menorValorIndice(v, 10);
        swapVetor(v, 10, indice, 0);
        mostrarVetor(v, 10);
    }

    printf("Ex. %i:\n", 4);
    // 4)
    {
        /*
        Exemplo:
            v1: {1, 2}; v2: {1, 2} -> sao identicos
            v1: {1, 2}; v2: {2, 1} -> sao iguais
            v1: {1, 2}; v2: {2, 3} -> sao diferentes

        Entrada:
            2 vetores de n elementos

        Processamento:
            receber os 2 vetores verificarem se são iguais,
            se não, verificar se todos elementos de A tem em B
            se não, não são iguais

        Saída:
            se são identicos iguais ou diferentes
        */
        int tamanho;

        printf("Insira o tamanho dos vetores:\t");
        scanf("%i", &tamanho);

        int A[tamanho], B[tamanho];

        receberValores(A, "A", tamanho);
        receberValores(B, "B", tamanho);
        classificarVetores(A, B, tamanho);
    }

    printf("Ex. %i:\n", 5);
    // 5)
    {
        /*
        Exemplo:
            v: {
                1, 2, 3,
                4, 5, 6,
                7, 8, 9
            } -> 9

        Entrada:
            1 vetor 3x3

        Processamento:
            ir indice por indice analisando o maior numero

        Saída:
            o maior elemento do vetor
        */
        int v[3][3];

        receberValores(v[0], "linha 0", 3);
        receberValores(v[1], "linha 1", 3);
        receberValores(v[2], "linha 2", 3);

        int maior = maiorNumero(v);

        printf("%i e o maior numero\n", maior);
    }

    printf("Ex. %i:\n", 6);
    // 6)
    {
        /*
        Exemplo:
            v1: {
                1,  2,  3,  4,  5,
                4,  5,  6,  7,  8,
                7,  8,  9, 10, 11,
                7,  8,  9,  7, 11,
                7,  8, 10, 10,  3
            };
            d: {0, 0, 0, 0, 0} ->
            {
                0,  2,  3,  4,  5,
                4,  0,  6,  7,  8,
                7,  8,  0, 10, 11,
                7,  8,  9,  0, 11,
                7,  8, 10, 10,  0
            }
        Entrada:
            uma matriz 5x5 e um vetor de 5 elementos

        Processamento:
            substituir a diagonal principal do v1 pelo d

        Saída:
            a matriz com a diagonal trocada
        */
        int v5x5[5][5], diagonal[5];

        printf("Insira o vetor\n");

        for (int i = 0; i < 5; i++) {
            char str[30];
            sprintf(str, "linha %i", i);
            receberValores(v5x5[i], str, 5);
        }

        printf("\nInsira a diagonal\n");
        receberValores(diagonal, "diagonal", 5);

        colocarDiagonal(v5x5, diagonal);
        for (int i = 0; i < 5; i++) {
            mostrarVetor(v5x5[i], 5);
        }
    }

    return 0;
}


void receberValores(int v[], char* mensagem, int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		printf("Insira a posicao %i do vetor %s: \n", i, mensagem);
		scanf("%i", &v[i]);
	}
}

void mostrarVetor(int v[], int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		printf("%i", v[i]);
		if (i+1 < tamanho) {
			printf(", ");
		}
	}
	printf("\n");
}

// 1)
int qtdPares(int v[], int tamanho) {
	int acc = 0;

	for (int i = 0; i < tamanho; i++) {
		acc += (v[i]%2-1)*-1;
	}

	return acc;
}

// 2)
void intercalar(int a[], int b[], int c[], int tamanho) {
	for (int i = 0; i < tamanho*2; i++) {
		int indice = (i/2);
		int* vetor = (i%2 ? b : a);

		c[i] = vetor[indice];
	}
}

// 3)
void swapVetor(int v[], int tamanho, int pos1, int pos2) {
	int de = pos1%tamanho,
		para = pos2%tamanho,
		tmp = v[para];

	v[para] = v[de];
	v[de] = tmp;
}

int menorValorIndice(int v[], int tamanho) {
	int indice = 0;
	int menorValor = v[0];

	for (int i = 0; i < tamanho; i++) {
		if (v[i] < menorValor) {
			indice = i;
			menorValor = v[i];
		}
	}

	return indice;
}

// 4)
int vetorIdentico(int a[], int b[], int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		if (a[i] != b[i]) {
			return 0;
		}
	}

	return 1;
}

int vetorIgual(int a[], int b[], int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		if (!vetorInclui(b, tamanho, a[i])) {
			return 0;
		}
	}

	return 1;
}

int vetorInclui(int v[], int tamanho, int n) {
	for (int i = 0; i < tamanho; i++) {
		if (v[i] == n) {
			return 1;
		}
	}

	return 0;
}

void classificarVetores(int a[], int b[], int tamanho) {
	if (vetorIdentico(a, b, tamanho))
		printf("A e B sao identicos\n");
	else if(vetorIgual(a, b, tamanho))
		printf("A e B contem os mesmos valores\n");
	else
		printf("A contem um valor que nao ha em B\n");
}

// 5)
int maiorNumero(int v[3][3]) {
	int maiorN = v[0][0];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (v[i][j] > maiorN) {
				maiorN = v[i][j];
			}
		}
	}

	return maiorN;
}

// 6)
void colocarDiagonal(int v[5][5], int diagonal[5]) {
	for (int i = 0; i < 5; i++) {
		v[i][i] = diagonal[i];
	}
}