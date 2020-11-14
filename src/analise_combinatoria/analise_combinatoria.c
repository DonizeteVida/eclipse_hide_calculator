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
        printf("\nAnálise combinatória \n1. Fatorial \n2. Permutação simples \n3. Permutação com repetição \n4. Arranjo simples \n5. Arranjo com repetição \n6. Combinação simples \n7. Combinação com repetição\nOpção desejada: ");
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
            printf("\nO fatorial de %.0lf é igual a: %.0lf ", a, m);
            break;
        case 2:
            printf("\nDigite o valor: ");
            scanf("%lf", &m);
            a = m;
            for (n = m - 1; n >= 1; n--)
            {
                m *= n;
            }
            printf("\nA permutação simples de %.0lf é igual a: %.0lf ", a, m);
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
            printf("\nA permutação com repetição de %.0lf elementos e %0.lf que se repetem é igual a: %.0lf ", a, n, m);
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
            printf("\nO arranjo simples de  %.0lf elementos e %0.lf agrupamentos é igual a: %.0lf ", a, n, m);
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
            printf("\nO arranjo com repetição de  %.0lf elementos e %0.lf elementos que se repetem é igual a: %.0lf ", a, j, m);
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
            printf("\nA combinção simples de  %.0lf elementos e %0.lf agrupamentos é igual a: %.0lf ", a, b, m);
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
            printf("\nA combinção com repetição de  %.0lf elementos e %0.lf agrupamentos que se repetem é igual a: %.0lf ", a, b, m);
            break;
        default:
            break;
        }
        if (opc <= 7 && opc != 0)
        {
            printf("\nDeseja continuar utilizando a análise combinatória?\n1.Sim\n2.Não\nOpção desejada: ");
            scanf("%d", &opc);
            if (opc != 1)
            {
                printf("\nSaindo de análise combinatória !\n");
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
            printf("\nOpção inválida, por favor, tente novamente !\n");
            sleep(2);
            opc = 1;
            system("cls");
        }
    } while (opc <= 7 && opc != 0);
}
