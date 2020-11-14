#include <stdio.h>
#include <stdlib.h>
#include "matrizes.h"

void _desalocarMatriz(int **matriz, int r, int c)
{
}

void _mostrarMatriz(int **matriz, int r, int c)
{
    for (int lr = 0; lr < r; lr++)
    {
        for (int lc = 0; lc < c; lc++)
        {
            printf("%d ", matriz[lr][lc]);
        }
        printf("\n");
    }
    printf("\n");
}

int **_alocarMatriz(int r, int c)
{
    int **alocado = malloc(r * sizeof(int *));
    for (int i = 0; i < c; i++)
    {
        alocado[i] = malloc(c * sizeof(int));
    }
    return alocado;
}

int **_construirMatriz(int r, int c)
{
    int **matriz = _alocarMatriz(r, c);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Digite o valor da celula %d %d: ", i + 1, j + 1);

            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\n");
    _mostrarMatriz(matriz, r, c);
    return matriz;
}

void calcularDeterminante(int **matriz, int r, int c)
{
    int dp = 1;
    int ds = 1;

    for (int lr = 0, lc = 0; lr < r && lc < c; lr++, lc++)
    {
        dp *= matriz[lr][lc];
    }

    for (int lr = 0, lc = c - 1; lr < r && lc >= 0; lr++, lc--)
    {
        ds *= matriz[lr][lc];
    }

    printf("Diagonal principal: %d e diagonal segundaria: %d\n", dp, ds);
    printf("O determinante e de %d.\n\n", dp - ds);

    _desalocarMatriz(matriz, r, c);
}

void soma(int **matriz1, int **matriz2, int r, int c)
{
    int **matrizSoma = _alocarMatriz(r, c);

    for (int lr = 0; lr < r; lr++)
    {
        for (int lc = 0; lc < c; lc++)
        {
            matrizSoma[lr][lc] = matriz1[lr][lc] + matriz2[lr][lc];
        }
    }

    printf("O resultado da matriz e: \n");
    _mostrarMatriz(matrizSoma, r, c);

    _desalocarMatriz(matriz1, r, c);
    _desalocarMatriz(matriz2, r, c);
    _desalocarMatriz(matrizSoma, r, c);
}
void subtracao(int **matriz1, int **matriz2, int r, int c)
{
    int **matrizSubtracao = _alocarMatriz(r, c);

    for (int lr = 0; lr < r; lr++)
    {
        for (int lc = 0; lc < c; lc++)
        {
            matrizSubtracao[lr][lc] = matriz1[lr][lc] - matriz2[lr][lc];
        }
    }

    printf("O resultado da matriz e: \n");
    _mostrarMatriz(matrizSubtracao, r, c);

    _desalocarMatriz(matriz1, r, c);
    _desalocarMatriz(matriz2, r, c);
    _desalocarMatriz(matrizSubtracao, r, c);
}
void produto(int **matriz1, int **matriz2, int r, int c)
{
    _mostrarMatriz(matriz1, r, c);
    _mostrarMatriz(matriz2, r, c);
}

void showMatrizesSubmenu()
{
    int opc;
    int r = 2, c = 2;

    do
    {
        printf("MATRIZES\n1. Determinante\n2. Soma\n3. Subtracao\n4. Produto\n5. Voltar ao menu anterior\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            calcularDeterminante(_construirMatriz(r, c), r, c);
            break;
        case 2:
        {
            int **matriz1 = _construirMatriz(r, c);
            int **matriz2 = _construirMatriz(r, c);
            soma(matriz1, matriz2, r, c);
            break;
        }
        case 3:
        {
            int **matriz1 = _construirMatriz(r, c);
            int **matriz2 = _construirMatriz(r, c);
            subtracao(matriz1, matriz2, r, c);
            break;
        }
        case 4:
        {
            int **matriz1 = _construirMatriz(r, c);
            int **matriz2 = _construirMatriz(r, c);
            produto(matriz1, matriz2, r, c);
            break;
        }
        case 5:
            break;
        default:
            break;
        }
    } while (opc != 5);
}
