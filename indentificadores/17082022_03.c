// N�colas dos Santos Carvalho - 128660
// Ci�ncia da Computa��o 1 - UEM
// 17 08 2022

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

#include <stdio.h>

int main(void) {
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

    return 0;
}

//----------------------------
// c�digo retirado na revis�o
//----------------------------

// if (x == y && y == z) {                         // x == z implicito
//     printf("\nesse triangulo e equilatero\n");
// } else if (
//     (x == y && y != z) ||                       // x != z implicito
//     (x == z && y != z) ||                       // x != y implicito
//     (y == z && x != z)                          // y != x implicito
// ) {
//     printf("\nesse triangulo e isosceles\n");
// } else {
//     printf("\nesse triangulo e escaleno\n");
// }