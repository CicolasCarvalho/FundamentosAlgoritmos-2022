// N�colas dos Santos Carvalho - 128660
// Ci�ncia da Computa��o - UEM
// 17 08 2022

#include <stdio.h>

int main(void) {
    //1)
    {
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
        int senha;

        printf("Insira a senha:\t");
        scanf("%i", &senha);

        printf("\n");
        if(senha == 1234)
            printf("Senha correta. Bem vindo!\n");
        else
            printf("Senha incorreta. Tente novamente!\n");
    }

    //2)
    {
        /*
        Exemplos:
            - idades: 1, 2, 3, 4 -> meida 2.5 anos, a pessoa mais velha tem 4

        Entrada:
            idades

        Processamento:
            somar as idades e dividi-las por 4. comparar as 4 idades e pegar a maior

        Sa�da:
            a m�dia das idades, e a pessoa mais velha
        */
        int i1, i2, i3, i4, maior;
        float media;

        printf("Informe as idades das 4 pessoas:\n");
        scanf("%i %i %i %i", &i1, &i2, &i3, &i4);

        media = (i1+i2+i3+i4)/4.0;

        maior = i1;
        if (i2>maior) maior = i2;
        if (i3>maior) maior = i3;
        if (i4>maior) maior = i4;

        printf("\nA media de idades e: %f\nA pessoa mais velha tem: %i\n", media, maior);
    }

    //3)
    {
        /*
        Exemplos:
            - x: 3, y: 3, z: 3 -> tri�ngulo equil�tero
            - x: 5, y: 5: z: 6 -> tri�ngulo is�sceles
            - x: 3, y: 4, z: 5 -> tri�ngulo escaleno
            - x: 1, y: 2, z: 3 -> esse triangulo nao existe

        Entrada:
            x, y, z

        Processamento:
            se y+z > x e x+z > y e x+y > z descobrimos se o triangulo existe, se sim:
                testando quantas semelhan�as de lados ocorrem, conseguimos descobrir se h�
                3 semelhan�as -> equilatero; 1 semelhan�a -> is�sceles; nenhuma -> equilatero
            se n�o:
                falamos que o tri�ngulo n�o existe

        Sa�da:
            tipo de tri�ngulo, quando for um tri�ngulo
        */
        float x, y, z;

        printf("Insira os 3 lados do triangulo:\n");
        scanf("%f %f %f", &x, &y, &z);

        if (y+z > x && x+z > y && x+y > z) {
            int lados = 0;
            lados += x == y;            // y == x e x == y
            lados += x == z;            // z == x e x == z
            lados += y == z;            // y == z e z == y

            if (lados == 3) {           // 3 lados que s�o iguais uns aos outros
                printf("\nesse triangulo e equilatero\n");
            } else if (lados == 1) {    // somente uma semelhan�a de lados existe
                printf("\nesse triangulo e isosceles\n");
            } else {                    // nenhum lado � igual
                printf("\nesse triangulo e escaleno\n");
            }
        } else {
            printf("\nesse triangulo nao existe\n");
        }
        /*
        ----------------------------
        c�digo retirado na revis�o
        ----------------------------

        if (x == y && y == z) {                         // x == z implicito
            printf("\nesse triangulo e equilatero\n");
        } else if (
            (x == y && y != z) ||                       // x != z implicito
            (x == z && y != z) ||                       // x != y implicito
            (y == z && x != z)                          // y != x implicito
        ) {
            printf("\nesse triangulo e isosceles\n");
        } else {
            printf("\nesse triangulo e escaleno\n");
        }
        */
    }

    //4)
    {
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
    }

    return 0;
}
