void receberValores(int v[], char* mensagem, int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		printf("Insira a posicao %i do vetor %s: \n", i, mensagem);
		scanf("%i", &v[i]);
	}
}

void mostrarVetor(int v[], int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		printf("%i", v[i]);
		if (i+1 < tamanho) {
			printf(", ");
		}
	}
	printf("\n");
}

// void mostrarMapa(int* v[], int linhas, int colunas) {
// 	for (int i = 0; i < linhas; i++) {
// 		int linha[] = v[i];
// 		mostrarVetor(linha);
// 		printf("\n");
// 	}
// }