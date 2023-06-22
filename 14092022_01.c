// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 24 08 2022

#include <stdio.h>
#include <string.h>

enum tipo {par, impar};

enum tipo parOuImpar(int n);

int main(void) {
    //1
    {
        int n;

        printf("insira o numero:\t");
        scanf("%i", &n);

        if (parOuImpar(n) == par) {
            printf("\no numero e par");
        } else {
            printf("\no numero e impar");
        }
    }

    // 2; 3
    {
        char s1[50], s2[50];

        printf("\ncoloque 2 palavras:\n");
        printf("palavra 1: ");
        fgets(s1, 50, stdin);
        printf("palavra 2: ");
        fgets(s2, 50, stdin);

        int len1 = strlen(s1),
            len2 = strlen(s2);

        s1[len1-1] = '\0';
        s2[len2-1] = '\0';

        if (len1 > len2) {
            printf("'%s' e maior", s1);
        } else if (len1 < len2) {
            printf("'%s' e maior", s2);
        } else {
            printf("as 2 palavras tem o mesmo tamanho");
        }
    }

    return 0;
}

enum tipo parOuImpar(int n) {
    if (!n%2) {
        return par;
    } else {
        return impar;
    }
}