// Nícolas dos Santos Carvalho - 128660
// Ciência da Computação - UEM
// 26 09 2022

#include <stdio.h>
#include <string.h>
#include <assert.h>

float calc(int n);
int maiorQ8(void);
void teste(void) {
    assert(calc(0) == 0);
    assert(calc(1) == 1);
    assert(calc(2) == 1.5);
}

int main(void) {
    teste();
    // 1)
    {
        /*
        Exemplo:
            100 100 100 100 100
            0   0   0   0   0 -> temp media 50, temp maxima 100

        Entradas:
            temperaturas

        Processamento:
            pegar as temperaturas e checar se e maior que a maior ate agora
            pegar as temperaturas divido por 10 e soma a media

        Saida:
            a media e a maior temperatura
        */
       float temperatura, tempMedia, tempMaxima = 0;

        for (int i = 0; i < 10; i++) {
            printf("Informe a temperatura %i:\t", i+1);
            scanf("%f", &temperatura);

            if (tempMaxima < temperatura)
                tempMaxima = temperatura;

            tempMedia += temperatura/10.0;
        }

        printf("\nA temperatura media foi de: %.2f", tempMedia);
        printf("\nA temperatura maxima foi de: %.2f\n", tempMaxima);
    }

    // 2)
    {
        /*
        Exemplo:
            2 -> 1 + 1/2
            5 -> 1 + 1/2 + 1/3 + 1/4 + 1/5

        Entradas:
            n

        Processamento:
            H = 1 + 1/2 + ... + 1/N

        Saida:
            H
        */

        int n;

        printf("Insira o numeros de termos\n");
        scanf("%i", &n);

        float soma = calc(n);
        printf("\nH = 1 + 1/2 + ... + 1/N e:\t%.4f", soma);
    }

    // 3)
    {
        /*
        Exemplo:
            1, 2, 3, 4, 5, 9, 9 -> 2 numeros maior que 8

        Entradas:
            n1, n2, n3, n4, n5, n6, n7

        Processamento:
            pegar um numero e ver se é maior que 8 se sim adicionar +1 em uma variavel acumuladora

        Saida:
            quantidade de numeros maior que 8
        */
        printf("ha %i numeros maior que 8", maiorQ8());
    }

    // 4)
    {
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

        printf("\n- %i pessoas maior de 50 anos", maior50idade);
        printf("\n- %.2f e a media de altura entre 10 e 20 anos", mediaAltura10a20);
        printf("\n- %.0f por cento de pessoas com o peso inferior a 40kg", menos40Peso);
    }

    // 5)
    {
        /*
        Exemplo:
            nicolas -> nico

        Entradas:
            nome

        Processamento:
            pegar somente os 34 primeiros caracteres de uma string e no final colocar o \0

        Saida:
            os 4 primeiros caracteres do nome
        */
        char str[30];

        printf("insira um nome:\n");
        scanf("%s", str);

        char str4[5];

        for (int i = 0; i < 4; i++) {
            str4[i] = str[i];
        }
        str4[4] = '\0';

        // strncpy(str4, str, 4);

        printf("%s", str4);
    }

    // 6)
    {
        /*
        Exemplo:
            nicolas -> salocin

        Entradas:
            nome

        Processamento:
            pegar o nome e ver o tamanho, colocar em uma outra string caracter por caracter
            desse nome só que contando de traz para frente

        Saida:
            nome invertido
        */
        char str[30];
        char strrev[30];

        printf("insira uma palavra:\n");
        scanf("%s", str);

        int len = strlen(str);

        for (int i = 0; i < len; i++) {
            strrev[i] = str[-(i-len)-1];
        }
        strrev[len] = '\0';

        printf("\na palavra revertida e: %s\n", strrev);
    }

    // 7)
    {
        /*
        Exemplo:
            nicolas carvalho
            'n' 'c' -> cicolas carvalho

        Entradas:
            palavra, l1, l2

        Processamento:
            ler a palavra depois ler o caracter a ser substituido e o que entrara no lugar
            ir caracter por caracter se ele for igual ao a ser reposto troque, caso nao mantenha no mesmo

        Saida:
            palavra com as letras trocadas
        */
        char str[50];
        char c, subs;

        printf("insira uma palavra:\n");
        fgets(str, 50, stdin);
        str[strlen(str)-1] = '\0';

        printf("caracater a ser substituido e qual sera posto no lugar (L1, L2):\n");
        scanf("%c %c", &c, &subs);

        for (int i = 0; i < 50; i++) {
            if (str[i] == c)
                str[i] = subs;
        }

        printf("%s", str);
    }

    return 0;
}

float calc(int n) {
    float acc = 0;

    for(int i = 1; i <= n; i++) {
        acc += 1.0/(float)i;
    }

    return acc;
}

int maiorQ8(void) {
    int acc = 0, numero;

    for (int i = 0; i < 7; i++) {
        printf("coloque o numero %i: ", i+1);
        scanf("%i", &numero);

        if(numero > 8)
            acc++;
    }

    return acc;
}