// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 17 08 2022

/*
Exemplos:
    - média final: 4,9 -> D
    - média final: 5,7 -> C
    - média final: 7,2 -> B
    - média final: 9,9 -> A

Entrada:
    média final

Processamento:
    verificar se a média final esta dentro do limite e se a media do aluno é
    menor que 5, se não se menor que 7, se não se menor que 8, se não se é menor que 10

Saída:
    o conceito do aluno
*/

#include <stdio.h>

int main(void) {
    float nota;

    printf("Media final do aluno:\n");
    scanf("%f", &nota);

    if (nota < 0.0 || nota > 10.0) {
        printf("A media final nao pode ser menor que 0 ou maior que 10");
        return 1;
    }

    printf("\nO aluno ficou com conceito: ");
    if (nota < 5.0) {
        printf("D\n");
    } else if (nota < 7.0) {
        printf("C\n");
    } else if (nota < 9.0) {
        printf("B\n");
    } else if (nota < 10.0) {
        printf("A\n");
    }

    return 0;
}