#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "somatorio.h"

#define pair(type, name) \
{\
	type m, n;\
} name;

typedef struct pair(double, ValorSomatorio)

typedef double (*SomatorioPointer)(double, double);

static ValorSomatorio pegarValores()
{
    ValorSomatorio valorSomatorio;

    printf("Digite o valor inicial, m: ");
    scanf("%lf", &valorSomatorio.m);

    printf("Digite o valor da final, n: ");
    scanf("%lf", &valorSomatorio.n);

    if (valorSomatorio.n < valorSomatorio.m)
    {
        printf("Você não pode digitar o valor final sendo menor que o inicial, os valores serão zerados !!!\n");
        valorSomatorio.m = 0;
        valorSomatorio.n = 0;
    }
    return valorSomatorio;
}

static long double processaSomatorio(SomatorioPointer somatorio)
{
    ValorSomatorio valor = pegarValores();
    return somatorio(valor.m, valor.n);
}

static void processarResultado(double resultado, int qualSomatorio)
{
    printf("O resultado do somatório %d foi de %.50lf\n\n", qualSomatorio, resultado);
    fflush(stdin);
    getchar();
}

static long double factorial(double num)
{
    if (num == 0)
    {
        return 1;
    }
    return num * factorial(num - 1);
}

void showSomatorioSubmenu()
{
    int opc;

    SomatorioPointer somatoriosPointers[] = {
        &somatorio1,
        &somatorio2,
        &somatorio3,
        &somatorio4,
    };

    do
    {
    	system("cls");
        printf("\tSomatório\n\n1.\tSomatório de j até m para a regra j\n2.\tSomatório de j = m até n para a regra (-j)^(j+1)\n3.\tSomatório de j = 0 até n para a regra 1/j!\n4.\tSomatório de j = 0 até n para a regra 8 / ( ( 4j + 1 ) * ( 4j + 3 ) )\n\n5.\tSair do Somatório\n\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
        case 2:
        case 3:
        case 4:
            processarResultado(processaSomatorio(somatoriosPointers[opc - 1]), opc);
            break;
        }
    } while (opc != 5);
}

double somatorio1(double m, double n)
{
    if (m == n)
    {
        return m;
    }
    return m + somatorio1(m + 1, n);
}

double somatorio2(double m, double n)
{
    if (m == n)
    {
        return pow(-m, m + 1);
    }
    return pow(-m, m + 1) + somatorio2(m + 1, n);
}

double somatorio3(double m, double n)
{
    if (m == n)
    {
        return 1 / factorial(m);
    }
    return 1 / factorial(m) + somatorio3(m + 1, n);
}

double somatorio4(double m, double n)
{
    if (m == n)
    {
        return 8 / ((4 * m + 1) * (4 * m + 3));
    }
    return 8 / ((4 * m + 1) * (4 * m + 3)) + somatorio4(m + 1, n);
}
