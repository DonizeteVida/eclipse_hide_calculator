#include "analise_combinatoria.h"
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <locale.h>

void showAnaliseCombinatoriaSubmenu()
{
    int opc;
    double m, n, j, o, a, b, c, d;
    do
    {
    	system("cls");
        printf("\tAn�lise combinat�ria\n\n1.\tFatorial \n2.\tPermuta��o simples\n3.\tPermuta��o com repeti��o\n4.\tArranjo simples\n5.\tArranjo com repeti��o\n6.\tCombina��o simples\n7.\tCombina��o com repeti��o\n\nOp��o desejada: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            printf("\nDigite o valor: ");
            scanf("%lf", &m);
            a = m;
            for (n = m - 1; n >= 1; n--)
            {
                m *= n;
            }
            printf("\nO fatorial de %.0lf � igual a: %.0lf ", a, m);
            break;
        case 2:
            printf("\nDigite o valor: ");
            scanf("%lf", &m);
            a = m;
            for (n = m - 1; n >= 1; n--)
            {
                m *= n;
            }
            printf("\nA Permuta��o simples de %.0lf � igual a: %.0lf ", a, m);
            break;
        case 3:
            printf("\nDigite o valor para o total de elementos: ");
            scanf("%lf", &m);
            printf("\nDigite o valor para o total dos elementos que se repetem: ");
            scanf("%lf", &n);
            a = m;
            for (j = m - 1; j > n; j--)
            {
                m *= j;
            }
            printf("\nA Permuta��o com repeti��o de %.0lf elementos e %0.lf que se repetem � igual a: %.0lf ", a, n, m);
            break;
        case 4:
            printf("\nDigite o valor para o total de elementos: ");
            scanf("%lf", &m);
            printf("\nDigite o valor para o total de agrupamentos: ");
            scanf("%lf", &n);
            a = m;
            if (n <= m)
            {
                o = m - n;
            }
            for (j = m - 1; j > o; j--)
            {
                m *= j;
            }
            printf("\nO arranjo simples de  %.0lf elementos e %0.lf agrupamentos � igual a: %.0lf ", a, n, m);
            break;
        case 5:
            printf("\nDigite o valor para o total de elementos: ");
            scanf("%lf", &m);
            printf("\nDigite o valor para o total de elementos que se repetem: ");
            scanf("%lf", &n);
            a = m;
            j = n;
            for (; n > 1; n--)
            {
                m *= a;
            }
            printf("\nO arranjo com repeti��o de  %.0lf elementos e %0.lf elementos que se repetem � igual a: %.0lf ", a, j, m);
            break;
        case 6:
            printf("\nDigite o valor para o total de elementos: ");
            scanf("%lf", &m);
            printf("\nDigite o valor para o total de agrupamentos: ");
            scanf("%lf", &n);
            a = m;
            b = n;
            d = n;
            if (n <= m)
            {
                o = m - n;
            }
            for (j = m - 1; j > o; j--)
            {
                m *= j;
            }
            for (c = d - 1; c >= 1; c--)
            {
                d *= c;
            }
            m = m / d;
            printf("\nA combina��o simples de  %.0lf elementos e %0.lf agrupamentos � igual a: %.0lf ", a, b, m);
            break;
        case 7:
            printf("\nDigite o valor para o total de elementos: ");
            scanf("%lf", &m);
            printf("\nDigite o valor para o total de agrupamentos: ");
            scanf("%lf", &n);
            a = m;
            b = n;
            d = n;
            if (n <= m)
            {
                o = m - 1;
            }
            m += n - 1;
            for (j = m - 1; j > o; j--)
            {
                m *= j;
            }
            for (c = d - 1; c >= 1; c--)
            {
                d *= c;
            }
            m = m / d;
            printf("\nA combina��o com repeti��o de  %.0lf elementos e %0.lf agrupamentos que se repetem � igual a: %.0lf ", a, b, m);
            break;
        default:
            break;
        }
        if (opc <= 7 && opc != 0)
        {
            printf("\nDeseja continuar utilizando a An�lise combinat�ria?\n1.Sim\n2.N�o\nOp��o desejada: ");
            scanf("%d", &opc);
            if (opc != 1)
            {
                printf("\nSaindo de An�lise combinat�ria !\n");
                sleep(2);
                system("cls");
                break;
            }
            printf("\nIniciando novamente");
            sleep(1);
            printf(".");
            sleep(1);
            printf(".");
            sleep(1);
            printf(".");
            sleep(1);
            printf(".");
            sleep(1);
            printf(".");
            system("cls");
        }
        else
        {
            printf("\nOp��o inv�lida, por favor, tente novamente !\n");
            sleep(2);
            opc = 1;
            system("cls");
        }
    } while (opc <= 7 && opc != 0);
}
