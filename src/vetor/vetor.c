#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

typedef int Validador(int, int);

int menor(int left, int right)
{
    return left < right;
}

int maior(int left, int right)
{
    return left > right;
}

int *criarVetor()
{
    //Ponteiro de inteiro -> int *
    //int = 4 bytes
    return malloc(sizeof(int) * 5);
}

int *preencheVetor(int *p)
{
    for (int i = 0; i < 5; i++)
    {
        printf("Escreva o valor da posição %d: ", i + 1);
        scanf("%d", p + i);
    }
    return p;
}

int *ordenaVetor(int *v, Validador val)
{
    // [4,1,3,2] -> [1,3,2,4]
    // [1,3,2] -> [1,2,3]
    // [1,2] -> [1,2]
    // [1,2,3,4]
    for (int i = 4; i >= 0; i--)
    {
        for (int a = 0; a < i; a++)
        {
            int *left = v + a;
            int *right = v + a + 1;
            if (val(*left, *right))
            {
                int temp = *left;
                *left = *right;
                *right = temp;
            }
        }
    }

    return v;
}

void mostrarVetor(int *v)
{
    for (int vetor = 0; vetor < 5; vetor++)
    {
        // v + vetor Move o vetor de lugar
        printf("%d ", *(v + vetor));
    }
    printf("\n");
    free(v);
    v = 0;
}

void showVetorSubmenu()
{
    int opc;
    do
    {
        system("cls");
        printf("\tVETOR\n1. Ordenar de forma crescente\n2. Ordenar de forma decrescente\n3. VOLTAR AO MENU PRINCIPAL\n");
        scanf("%d", &opc);

        Validador *validadores[] = {maior, menor};

        switch (opc)
        {
        case 1:
        case 2:
            mostrarVetor(ordenaVetor(preencheVetor(criarVetor()), validadores[opc - 1]));
            break;
        default:
            break;
        }
    } while (opc != 3);
}