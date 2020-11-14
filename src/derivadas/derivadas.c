#include <stdio.h>
#include <stdlib.h>
#include "../funcoes/funcoes.h"
#include "derivadas.h"

float coeficienteAngular(float x, LimFun f)
{
    return (f(x + H) - f(x)) / H;
}

void equacaoDaReta(float x, float a, LimFun f)
{
    float y = f(x);
    // y = a.x + b
    // b = y - a.x
    float b = y - a * x;

    printf("A equaç?o da reta neste ponto é de y = %.2f.x + %.2f\n", a, b);
}

void showDerivadasSubmenu()
{
    LimFun limFuns[] = {
        &constK,
        &x,
        &k,
        &e,
        &logbn,
        &ln,
        &half,
        &fsin,
        &fcos,
        &ftan,
    };

    int opc;
    do
    {
        system("cls");
        printf("\tAplicaç?o em derivadas\n1.\tf(x) = k\n2.\tf(x) = x^k\n3.\tf(x) = k^x\n4.\tf(x) = e^x\n5.\tf(x) = log k(x)\n6.\tf(x) = ln(x)\n7.\tf(x) = 1/x\n8.\tf(x) = sen(x)\n9.\tf(x) = cos(x)\n10.\tf(x) = tan(x)\n11.\tVOLTAR AO MENU PRINCIPAL\n\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        {
            float x = 0;
            printf("Digite o valor de X: ");
            scanf("%f", &x);
            LimFun f = limFuns[opc - 1];
            float c = coeficienteAngular(x, f);
            printf("O coeficiente angular do ponto %.2f é de %.10f\n", x, c);
            equacaoDaReta(x, c, f);
            fflush(stdin);
            getchar();
        }
        break;
        }
    } while (opc != 11);
}