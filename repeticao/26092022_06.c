// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 26 09 2022

/*
Exemplo:
    nicolas -> salocin

Entradas:
    nome

Processamento:
    pegar o nome e ver o tamanho, colocar em uma outra string caracter por caracter
    desse nome só que contando de traz para frente

Saida:
    nome invertido
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    char str[30];
    char strrev[30];

    printf("insira uma palavra:\n");
    scanf("%s", str);

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        strrev[i] = str[-(i-len)-1];
    }
    strrev[len] = '\0';

    printf("\na palavra revertida e: %s\n", strrev);
    return 0;
}
