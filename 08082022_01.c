// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação 1 - UEM
// 08 08 2022

#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main(void) {
    //Exercio 1 - Calculo da área de um cilindro
    float raio, altura, area;

    printf("Coloque o raio do cilindro\n");
    scanf("%f", &raio);
    printf("Coloque a altura do cilindro\n");
    scanf("%f", &altura);
    area = raio*raio*PI*altura;
    printf("A area total do cilindro e: %f", area);

    //Exercicio 3 - quantidade média de gasto de combustivel
    float tempo, velMedia, qtdCombustivel;

    printf("Coloque o tempo de viagem\n");
    scanf("%f", &tempo);
    printf("Coloque a velociade média do carro\n");
    scanf("%f", &velMedia);
    qtdCombustivel = tempo*velMedia/12.0;
    printf("A quantidade total de combustivel foi: %f", qtdCombustivel);

    //Exercicio 4 - quantidade de latas de tintas
    float lado1, lado2, alturaParede, areaParede, areaTeto, areaTotal;
    int numeroLatas;

    printf("Informe os lados das paredes:\n");
    scanf("%f %f", &lado1, &lado2);
    printf("Informe a altura da sala:\n");
    scanf("%f", &alturaParede);
    areaParede = (lado1*alturaParede)+(lado2*alturaParede);
    areaTeto = lado1*lado2;
    areaTotal = areaParede+areaTeto;
    numeroLatas = ceil(areaTotal/12.0);

    printf (
        "A area total da sala e de: %f.\nO numero de latas que deverao ser compradas e de: %i",
        areaTotal,
        numeroLatas
    );

    //Exercicio 5 - swap de variaveis
    int a, b;

    scanf("%i %i", &a, &b);
    a = a+b;
    b = a-b;
    a = a-b;
    printf("a: %i, b: %i", a, b);

    //Exercicio 6 - custo final
    float custoInicial, custoFinal, taxaImposto, taxaVendedor;
    taxaImposto = .45;
    taxaVendedor = .2;

    printf("Digite o custo inicial do carro:\n");
    scanf("%f", &custoInicial);
    custoFinal = (custoInicial*taxaImposto)+(custoInicial*taxaVendedor)+custoInicial;
    printf("O custo final do produto será de: %f", custoFinal);

    return 0;
}
