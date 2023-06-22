// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 26 09 2022

/*
Exemplo:
    nicolas carvalho
    'n' 'c' -> cicolas carvalho

Entradas:
    palavra, l1, l2

Processamento:
    ler a palavra depois ler o caracter a ser substituido e o que entrara no lugar
    ir caracter por caracter se ele for igual ao a ser reposto troque, caso nao mantenha no mesmo

Saida:
    palavra com as letras trocadas
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    char str[50];
    char c, subs;

    printf("insira uma palavra:\n");
    fgets(str, 50, stdin);
    str[strlen(str)-1] = '\0';

    printf("caracater a ser substituido e qual sera posto no lugar (L1, L2):\n");
    scanf("%c %c", &c, &subs);

    for (int i = 0; i < 50; i++) {
        if (str[i] == c)
            str[i] = subs;
    }

    printf("%s", str);
    return 0;
}
