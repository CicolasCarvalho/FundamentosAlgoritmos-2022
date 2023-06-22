// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 26 09 2022

/*
Exemplo:
    nicolas -> nico

Entradas:
    nome

Processamento:
    pegar somente os 34 primeiros caracteres de uma string e no final colocar o \0

Saida:
    os 4 primeiros caracteres do nome
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    char str[30];

    printf("insira um nome:\n");
    scanf("%s", str);

    char str4[5];

    for (int i = 0; i < 4; i++) {
        str4[i] = str[i];
    }
    str4[4] = '\0';

    // strncpy(str4, str, 4);

    printf("%s", str4);
    return 0;
}
