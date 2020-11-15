#include <stdio.h>
#include <stdlib.h>
#include "../funcoes/funcoes.h"
#include "derivadas.h"

static float singleCoeficienteAngular(float x, SingleLim f) {
	return (f(x + H) - f(x)) / H;
}

static float doubleCoeficienteAngular(float x, float k, DoubleLim f) {
	return (f(x + H, k) - f(x, k)) / H;
}

static float equacaoDaReta(float y, float a, float x) {
	// y = a.x + b
	// b = y - a.x
	return y - a * x;
}

static void singleEquacaoDaReta(float x, float a, SingleLim f) {
	float b = equacaoDaReta(f(x), a, x);
	printf("A equação da reta neste ponto é de y = %.2f.x + %.2f\n\n", a, b);

	printf("Digite algo para continuar...");
	getchar();
}

static void doubleEquacaoDaReta(float x, float k, float a, DoubleLim f) {
	float b = equacaoDaReta(f(x, k), a, x);
	printf("A equação da reta neste ponto é de y = %.2f.x + %.2f\n\n", a, b);

	printf("Digite algo para continuar...");
	getchar();
}

void showDerivadasSubmenu() {

	int opc;
	do {
		system("cls");
		printf(
				"\tAplicação em derivadas\n\n1.\tf(x) = k\n2.\tf(x) = x^k\n3.\tf(x) = k^x\n4.\tf(x) = e^x\n5.\tf(x) = log k(x)\n6.\tf(x) = ln(x)\n7.\tf(x) = 1/x\n8.\tf(x) = sen(x)\n9.\tf(x) = cos(x)\n10.\tf(x) = tan(x)\n\n11.\tVoltar ao menu principal\n\n");
		scanf("%d", &opc);

		switch (opc) {
		case 1: {
			float xFloat = getFloat();
			float kFloat = getConst();

			float cAngular = doubleCoeficienteAngular(xFloat, kFloat, constK);

			doubleEquacaoDaReta(xFloat, kFloat, cAngular, constK);
			break;
		}
		case 2: {
			float xFloat = getFloat();
			float kFloat = getConst();

			float cAngular = doubleCoeficienteAngular(xFloat, kFloat, xPow);

			doubleEquacaoDaReta(xFloat, kFloat, cAngular, xPow);
			break;
		}
		case 3: {
			float xFloat = getFloat();
			float kFloat = getConst();

			float cAngular = doubleCoeficienteAngular(xFloat, kFloat, kPow);

			doubleEquacaoDaReta(xFloat, kFloat, cAngular, kPow);
			break;
		}
		case 4: {
			float xFloat = getFloat();

			float cAngular = singleCoeficienteAngular(xFloat, ePow);

			singleEquacaoDaReta(xFloat, cAngular, ePow);
			break;
		}
		case 5: {
			float kFloat = getConst();
			float xFloat = getFloat();

			float cAngular = doubleCoeficienteAngular(xFloat, kFloat, logbn);

			doubleEquacaoDaReta(xFloat, kFloat, cAngular, logbn);
			break;
		}
		case 6: {
			float xFloat = getFloat();

			float cAngular = singleCoeficienteAngular(xFloat, ln);

			singleEquacaoDaReta(xFloat, cAngular, ln);
			break;
		}
		case 7: {
			float xFloat = getFloat();

			float cAngular = singleCoeficienteAngular(xFloat, half);

			singleEquacaoDaReta(xFloat, cAngular, half);
			break;
		}
		case 8: {
			float xFloat = getFloat();

			float cAngular = singleCoeficienteAngular(xFloat, fsin);

			singleEquacaoDaReta(xFloat, cAngular, fsin);
			break;
		}
		case 9: {
			float xFloat = getFloat();

			float cAngular = singleCoeficienteAngular(xFloat, fcos);

			singleEquacaoDaReta(xFloat, cAngular, fcos);
			break;
		}
		case 10: {
			float xFloat = getFloat();

			float cAngular = singleCoeficienteAngular(xFloat, ftan);

			singleEquacaoDaReta(xFloat, cAngular, ftan);
			break;
		}
		}
	} while (opc != 11);
}
