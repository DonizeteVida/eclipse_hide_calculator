/*
 ============================================================================
 Name        : eclipse_hide_calculator.c
 Author      : DonizeteVida
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "analise_combinatoria/analise_combinatoria.h"
#include "logica_proposicional/logica_proposicional.h"
#include "matrizes/matrizes.h"
#include "somatorio/somatorio.h"
#include "vetor/vetor.h"
#include "funcoes/funcoes.h"
#include "derivadas/derivadas.h"

typedef void (*Submenu)(void);

int main(int argc, char const *argv[]) {
	setlocale(LC_ALL, "");

	int opc = 0;
	int wrongOption = 0;

	do {
		system("cls");
		printf("Mini calculadora discreta\n");

		if (wrongOption) {
			wrongOption = 0;
			printf("Nenhuma opção selecionada, tente novamente\n");
		}

		printf(
				"\t\tMENU\n1.\tSomatório\n2.\tLógica proposicional\n3.\tMatrizes\n4.\tAnálise combinatória\n5.\tOrdenar Elementos do Vetor\n6.\tAplicação em função\n7.\tAplicação em derivadas\n8.\tSair\n\n");
		scanf("%d", &opc);

		Submenu submenus[] = { showSomatorioSubmenu,
				showLogicaProposicionalSubmenu, showMatrizesSubmenu,
				showAnaliseCombinatoriaSubmenu, showVetorSubmenu,
				showFuncoesSubmenu, showDerivadasSubmenu, };

		switch (opc) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			submenus[opc - 1]();
			break;
		case 8:
			break;
		default:
			wrongOption = 1;
			break;
		}
	} while (opc != 8);

	return EXIT_SUCCESS;
}
