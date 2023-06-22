// N�colas dos Santos Carvalho - 128660
// Ci�ncia da Computa��o - UEM
// 17 08 2022

/*
Exemplos:
    - m�dia final: 4,9 -> D
    - m�dia final: 5,7 -> C
    - m�dia final: 7,2 -> B
    - m�dia final: 9,9 -> A

Entrada:
    m�dia final

Processamento:
    verificar se a m�dia final esta dentro do limite e se a media do aluno �
    menor que 5, se n�o se menor que 7, se n�o se menor que 8, se n�o se � menor que 10

Sa�da:
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