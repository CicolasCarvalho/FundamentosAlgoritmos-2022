// Ní­colas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 13 10 2022

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

#include <stdio.h>
#include <assert.h>

int contem5(int v[5], int item);

void teste(void) {
    int v[5] = {0, 1, 2, 3, 4};

    assert(contem5(v, 0)==1);
    assert(contem5(v, 1)==1);
    assert(contem5(v, 2)==1);
    assert(contem5(v, 3)==1);
    assert(contem5(v, 4)==1);
    assert(contem5(v, 5)==0);
}

int main(void) {
    teste();

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

    return 0;
}

int contem5(int v[5], int item) {
    int tem = 0;

    for(int i = 0; i < 5; i++) {
        if(v[i] == item)
            return 1;
    }

    return 0;
}
