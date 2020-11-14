#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

float get(const char *const phrase)
{   
    fflush(stdin);
    float f;
    printf("%s", phrase);
    scanf("%f", &f);
    return f;
}

float getConst()
{
    return get("Digite o valor de K: ");
}

float getFloat()
{
    return get("Digite o valor: ");
}

/*1*/ float constK(float number)
{
    return getConst();
}

/*2*/ float x(float number)
{
    return powf(getFloat(), getConst());
}

/*3*/ float k(float number)
{
    return powf(getConst(), getFloat());
}

/*4*/ float e(float expo)
{
    return powf(E, expo);
}

/*5*/ float logbn(float number)
{
    float k = getConst();
    return log10(getFloat()) / log10(k);
}

/*6*/ float ln(float number)
{
    return log(number);
}

/*7*/ float half(float number)
{
    return 1.0 / number;
}

/*8*/ float fsin(float number)
{
    return sinf(number / 360.0 * PI * 2);
}

/*9*/ float fcos(float number)
{
    return cosf(number / 360.0 * PI * 2);
}

/*10*/ float ftan(float number)
{
    return tanf(number / 360.0 * PI * 2);
}

void mostrarValor(float valor)
{
    fflush(stdin);
    system("cls");
    printf("O valor foi de %.2f\n", valor);
    getchar();
}

void showFuncoesSubmenu()
{
    int opc;
    do
    {
        system("cls");
        printf("\tAplicaç?o em funç?o\n1.\tf(x) = k\n2.\tf(x) = x^k\n3.\tf(x) = k^x\n4.\tf(x) = e^x\n5.\tf(x) = log k(x)\n6.\tf(x) = ln(x)\n7.\tf(x) = 1/x\n8.\tf(x) = sen(x)\n9.\tf(x) = cos(x)\n10.\tf(x) = tan(x)\n11.\tVOLTAR AO MENU PRINCIPAL\n\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            mostrarValor(constK(getFloat()));
            break;
        case 2:
            mostrarValor(x(getFloat()));
            break;
        case 3:
            mostrarValor(k(getFloat()));
            break;
        case 4:
            mostrarValor(e(getFloat()));
            break;
        case 5:
            mostrarValor(logbn(getFloat()));
            break;
        case 6:
            mostrarValor(ln(getFloat()));
            break;
        case 7:
            mostrarValor(half(getFloat()));
            break;
        case 8:
            mostrarValor(fsin(getFloat()));
            break;
        case 9:
            mostrarValor(fcos(getFloat()));
            break;
        case 10:
            mostrarValor(ftan(getFloat()));
            break;
        }
    } while (opc != 11);
}