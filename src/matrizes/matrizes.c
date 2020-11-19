#include <stdio.h>
#include <stdlib.h>
#include "matrizes.h"

static void desalocarMatriz(int **matriz) {
}

static void mostrarMatriz(int **matriz) {
	for (int lr = 0; lr < MAX; lr++) {
		for (int lc = 0; lc < MAX; lc++) {
			printf("%d ", matriz[lr][lc]);
		}
		printf("\n");
	}
	printf("\n");
}

static int** alocarMatriz() {
	int **alocado = malloc(MAX * sizeof(int*));
	for (int i = 0; i < MAX; i++) {
		alocado[i] = malloc(MAX * sizeof(int));
	}
	return alocado;
}

static int** construirMatriz() {
	int **matriz = alocarMatriz();

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			printf("Digite o valor da celula %d %d: ", i + 1, j + 1);

			scanf("%d", &matriz[i][j]);
		}
	}
	printf("\n");
	mostrarMatriz(matriz);
	fflush(stdin);
	return matriz;
}

void calcularDeterminante(int **matriz) {
	int dp = 1;
	int ds = 1;

	for (int lr = 0, lc = 0; lr < MAX && lc < MAX; lr++, lc++) {
		dp *= matriz[lr][lc];
	}

	for (int lr = 0, lc = MAX - 1; lr < MAX && lc >= 0; lr++, lc--) {
		ds *= matriz[lr][lc];
	}

	printf("Diagonal principal: %d e diagonal segundaria: %d\n", dp, ds);
	printf("O determinante e de %d.\n\n", dp - ds);

	desalocarMatriz(matriz);
}

void soma(int **matriz1, int **matriz2) {
	int **matrizSoma = alocarMatriz();

	for (int lr = 0; lr < MAX; lr++) {
		for (int lc = 0; lc < MAX; lc++) {
			matrizSoma[lr][lc] = matriz1[lr][lc] + matriz2[lr][lc];
		}
	}

	printf("O resultado da matriz e: \n");
	mostrarMatriz(matrizSoma);

	desalocarMatriz(matriz1);
	desalocarMatriz(matriz2);
	desalocarMatriz(matrizSoma);
}
void subtracao(int **matriz1, int **matriz2) {
	int **matrizSubtracao = alocarMatriz();

	for (int lr = 0; lr < MAX; lr++) {
		for (int lc = 0; lc < MAX; lc++) {
			matrizSubtracao[lr][lc] = matriz1[lr][lc] - matriz2[lr][lc];
		}
	}

	printf("O resultado da matriz e: \n");
	mostrarMatriz(matrizSubtracao);

	desalocarMatriz(matriz1);
	desalocarMatriz(matriz2);
	desalocarMatriz(matrizSubtracao);
}
void produto(int **matriz1, int **matriz2) {
	int **matrizProduto = alocarMatriz();

	for (int r = 0; r < MAX; r++) {
		for (int c = 0; c < MAX; c++) {
			matrizProduto[r][c] = 0;
		}
	}

	for (int i = 0; i < MAX; i++) {
		for (int r = 0; r < MAX; r++) {
			for (int c = 0; c < MAX; c++) {

				int val1 = matriz1[i][c];
				int val2 = matriz2[c][r];
				int res = val1 * val2;

				matrizProduto[i][r] += res;
			}

		}
	}

	mostrarMatriz(matrizProduto);
}

void showMatrizesSubmenu() {
	int opc;

	do {
		system("cls");
		printf(
				"\tMatrizes\n\n1.\tDeterminante\n2.\tSoma\n3.\tSubtracao\n4.\tProduto\n\n5.\tVoltar ao menu anterior\n");
		scanf("%d", &opc);

		switch (opc) {
		case 1:
			calcularDeterminante(construirMatriz());
			getchar();
			break;
		case 2: {
			int **matriz1 = construirMatriz();
			int **matriz2 = construirMatriz();
			soma(matriz1, matriz2);
			getchar();
			break;
		}
		case 3: {
			int **matriz1 = construirMatriz();
			int **matriz2 = construirMatriz();
			subtracao(matriz1, matriz2);
			getchar();
			break;
		}
		case 4: {
			int **matriz1 = construirMatriz();
			int **matriz2 = construirMatriz();
			produto(matriz1, matriz2);
			getchar();
			break;
		}
		default:
			break;
		}
	} while (opc != 5);
}
