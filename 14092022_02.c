#include <stdio.h>

enum tipo {par, impar};

int eFloat(float n1);
int parOuImpar(float n1);

int main(void) {
    float n;

    scanf("%f", &n);
    printf("%i", parOuImpar(n));

    return 0;
}

int eFloat(float n1) {
    if ((int)n1 == n1) {
        return 0;
    } else {
        return 1;
    }
}

int parOuImpar(float n1) {
    if(eFloat(n1/2.0)) {
        return impar;
    } else {
        return par;
    }
}