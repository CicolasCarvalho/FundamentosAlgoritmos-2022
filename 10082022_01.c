// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação 1 - UEM
// 10 08 2022

#include <stdio.h>

int main(void) {
    // Faça um programa que leia uma nota e fale se o aluno foi aprovado
    {
        float nota;

        printf("Qual a nota tirada pelo aluno:\n");
        scanf("%f", &nota);

        if (nota >= 6.0)
            printf("\nPassou de ano");
        else
            printf("\nReporovou de ano");
    }

    //Exercicio 2 - temperaturas
    {
        float tempF, tempC;

        printf("Insira a temperatura em Farenheit:\n");
        scanf("%f", &tempF);
        tempC = (5.0/9.0)*(tempF-32.0);
        printf("\nTemperatura em Celsius:\t%f", tempC);

        printf("\nO clima esta:\t");
        if(tempC < 17)      printf("Frio!");
        else if(tempC < 25) printf("Agradavel!");
        else                printf("Quente");
    }


    return 0;
}
