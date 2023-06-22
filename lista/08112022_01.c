#include <stdio.h>

void maior(int vet[],int n,int*maiorvalor){

    printf("%i:%i\n",n,*maiorvalor);

    if(n<1) {
        return;
    }

    if(vet[n-1]>*maiorvalor){
        *maiorvalor = vet[n-1];
    }

    maior(vet,n-1,maiorvalor);
}

int main(){
    int maiorvalor=0;
    int vetor[5];


    for(int i=0;i<5;i++){
        printf("Digite um valor para a posição %i do vetor\n",i);
        scanf("%i",&vetor[i]);
        //printf("%i\n",vetor[i]);
    };

    maior(vetor,5,&maiorvalor);

    printf("O maior valor é: %i",maiorvalor);
}