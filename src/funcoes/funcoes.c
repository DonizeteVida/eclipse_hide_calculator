#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

static float get(const char *const phrase) {
	fflush(stdin);
	float f;
	printf("%s", phrase);
	scanf("%f", &f);
	return f;
}

static float getConst() {
	return get("Digite o valor de K: ");
}

static float getFloat() {
	return get("Digite o valor de X: ");
}

/*1*/float constK(float number) {
	return getConst();
}

/*2*/float x(float xNumber, float kNumber) {
	return powf(xNumber, kNumber);
}

/*3*/float k(float kNumber, float xNumber) {
	return powf(kNumber, xNumber);
}

/*4*/float e(float expo) {
	return powf(E, expo);
}

/*5*/float logbn(float kFloat, float xFloat) {
	return log10(xFloat) / log10(kFloat);
}

/*6*/float ln(float number) {
	return log(number);
}

/*7*/float half(float number) {
	return 1.0 / number;
}

/*8*/float fsin(float number) {
	return sinf(number / 180.0 * PI);
}

/*9*/float fcos(float number) {
	return cosf(number / 180.0 * PI);
}

/*10*/float ftan(float number) {
	return tanf(number / 180.0 * PI);
}

void mostrarValor(float valor) {
	fflush(stdin);
	system("cls");
	printf("O valor foi de %.2f\n\n", valor);

	printf("Aperte algo para continuar...");
	getchar();
}

void showFuncoesSubmenu() {
	int opc;
	do {
		system("cls");
		printf(
				"\tAplicação em função\n\n1.\tf(x) = k\n2.\tf(x) = x^k\n3.\tf(x) = k^x\n4.\tf(x) = e^x\n5.\tf(x) = log k(x)\n6.\tf(x) = ln(x)\n7.\tf(x) = 1/x\n8.\tf(x) = sen(x)\n9.\tf(x) = cos(x)\n10.\tf(x) = tan(x)\n\n11.\tVoltar ao menu principal\n\n");
		scanf("%d", &opc);

		switch (opc) {
		case 1: {
			mostrarValor(constK(getFloat()));
			break;
		}
		case 2: {
			float xFloat = getFloat();
			float kFloat = getConst();

			mostrarValor(x(xFloat, kFloat));
			break;
		}
		case 3: {
			float kFloat = getConst();
			float xFloat = getFloat();

			mostrarValor(k(kFloat, xFloat));
			break;
		}
		case 4: {
			mostrarValor(e(getFloat()));
			break;
		}
		case 5: {
			float kFloat = getConst();
			float xFloat = getFloat();

			mostrarValor(logbn(kFloat, xFloat));
			break;
		}
		case 6: {
			mostrarValor(ln(getFloat()));
			break;
		}
		case 7: {
			mostrarValor(half(getFloat()));
			break;
		}
		case 8: {
			mostrarValor(fsin(getFloat()));
			break;
		}
		case 9: {
			mostrarValor(fcos(getFloat()));
			break;
		}
		case 10: {
			mostrarValor(ftan(getFloat()));
			break;
		}
		}
	} while (opc != 11);
}
