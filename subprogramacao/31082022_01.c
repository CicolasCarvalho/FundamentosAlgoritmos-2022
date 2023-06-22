#include <stdio.h>
#include <math.h>
#include <assert.h>

// #define area(x, y) (abs(x*y))

float area(float x, float y) {
    return abs(x*y);
}

int main(void) {
    float lado1, lado2, alturaParede, areaTotal;
    int numeroLatas;

    assert(area(1, 2)==2);
    assert(area(-1, 2)==2);
    assert(area(1/2.0, 2)==1);

    printf("Informe os lados das paredes:\n");
    scanf("%f %f", &lado1, &lado2);
    printf("Informe a altura da sala:\n");
    scanf("%f", &alturaParede);

    areaTotal = area(lado1, alturaParede)+area(lado2, alturaParede)+area(lado1, lado2);
    numeroLatas = ceil(areaTotal/12.0);

    printf (
        "A area total da sala e de: %.2f.\nO numero de latas que deverao ser compradas e de: %i\n",
        areaTotal,
        numeroLatas
    );

    return 0;
}