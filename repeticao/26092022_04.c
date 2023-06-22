// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 26 09 2022

/*
Exemplo:
    pessoa 1: 67kg 171cm 18 anos
    pessoa 2: 63kg 160cm 13 anos
    pessoa 3: 40kg 140cm 8 anos
    pessoa 4: 86kg 173cm 45 anos ->
        0 pessoas maior que 50 anos
        110.33 media das alturas entre 10 e 20
        0 por cento de pessoas com menos de 40kg

Entradas:
    peso altura idade * 4 pessoas

Processamento:
    analisar pessoa por pessoa peso altura idade
    se for maior que 50 adicionar a qtde de pessoas com mais de 50 anos
    se idade esta entre 10 e 20 adicionar altura a media
    se peso menos que 40 adicionar 25% a porcentagem de pessoas com menos de 40kg

Saida:
    pessoas com mais de 50 anos;
    media de altura das pessoas entre 10 e 20 anos
    % de pessoas com menos de 50kg
*/

#include <stdio.h>
#include <assert.h>

int main(void) {
    float menos40Peso = 0, peso, altura, mediaAltura10a20 = 0;
    int maior50idade = 0, idadeEntre10e20 = 0, idade;

    for (int i = 0; i < 4; i++) {
        printf("Insira o peso, altura e idade da pessoa %i:\n", i+1);
        scanf("%f %f %i", &peso, &altura, &idade);

        if (idade > 50)
            maior50idade++;

        if (idade > 10 && idade < 20) {
            idadeEntre10e20++;
            mediaAltura10a20 += altura;
        }

        if (peso < 40)
            menos40Peso += 25;
    }

    if (idadeEntre10e20 != 0) {
        mediaAltura10a20 /= idadeEntre10e20;
    }

    printf("\n- %i pessoas maior de 50 anos", maior50idade);
    printf("\n- %.2f e a media de altura entre 10 e 20 anos", mediaAltura10a20);
    printf("\n- %.0f por cento de pessoas com o peso inferior a 40kg", menos40Peso);

    return 0;
}
