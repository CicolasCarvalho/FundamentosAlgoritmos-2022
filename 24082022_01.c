// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 24 08 2022

// Funções

#include <stdio.h>
#include <assert.h>

int maior(int n1, int n2) {
    return n1>n2?n1:n2;
}

float areaTriangulo(float lado, float altura) {
    return lado*altura/2;
}

int main(void) {
    //Ex. 1:
    {
        assert(maior(2, 3)==3);

        int n1, n2, c;

        printf("Valores a serem comparados:\n");
        scanf("%i %i", &n1, &n2);

        c = maior(n1, n2);
        printf("%i\n\n", c);
    }

    //Ex. 2:
    {
        assert(areaTriangulo(4, 2)==4);

        float lado, altura, area;

        printf("Insira o lado:\t");
        scanf("%f", &lado);
        printf("Insira o altura:\t");
        scanf("%f", &altura);

        area = areaTriangulo(lado, altura);
        printf(
            "A area do triangulo de lado %.2f e altura %.2f e: %.2f\n\n",
            lado,
            altura,
            area
        );
    }

    return 0;
}
