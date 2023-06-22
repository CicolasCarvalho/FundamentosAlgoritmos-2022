// N�colas dos Santos Carvalho - 128660
// Ci�ncia da Computa��o - UEM
// 17 08 2022

/*
Exemplos:
    - senha: 1234 -> "Senha correta. Bem Vindo!"
    - senha: 1233 -> "Senha incorreta. Tente novamente!"

Entrada:
    senha

Processamento:
    Comparar a senha inserida com 1234

Sa�da:
    se estiver correta retornar "Senha correta. Bem Vindo!", se n�o "Senha incorreta. Tente novamente!"
*/

#include <stdio.h>

int main(void) {
    int senha;

    printf("Insira a senha:\t");
    scanf("%i", &senha);

    printf("\n");
    if(senha == 1234)
        printf("Senha correta. Bem vindo!\n");
    else
        printf("Senha incorreta. Tente novamente!\n");

    return 0;
}
