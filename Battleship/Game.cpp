#include "Board.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

table player1_attack(table computer, int sizex, int sizey){
	int x, y, aux = 0;
	char ship;
	printf("\nIntroduce coordinates captain:\n");
	scanf_s("%d %d", &x, &y);

	while (computer.view[x][y] == 1){
		printf("\nCaptain, we alredy hit there\n");
		scanf_s("%d %d", &x, &y);
	}

	while (x >= 10 || y >= 10 || x < 0 || y < 0){
		printf("\nCaptain, that's outside our scope\n");
		scanf_s("%d %d", &x, &y);
	}

	printf("Player [%d][%d]:", x, y);

	computer.view[x][y] = 1;

	if (computer.grid[x][y] == '~'){
		printf("Missed\n");
	}
	else {
		printf("Hit ");
		
		ship = computer.grid[x][y];

		for (x = 0; x < 10; x++){
			for (y = 0; y < 10; y++){
				if (computer.grid[x][y] == ship && computer.view[x][y] == 1){
					aux++;
				}
			}
		}

		switch (ship){
		case 'A':
			printf("& Sunk\n");
			break;
		case 'B':
			if (aux == 2){
				printf("& Sunk\n");
			}
			break;
		case 'C':
			if (aux == 3){
				printf("& Sunk\n");
			}
			break;
		case 'D':
			if (aux == 4){
				printf("& Sunk\n");
			}
			break;
		default:
			printf("\n");
		}
	}

	return computer;
}

int check(table *player, int n, int sizex, int sizey){
	int x, y, p1 = 0, p2 = 0, aux;
	int *winner = (int*)malloc(sizeof(int)*n);

	for (aux = 0; aux < n; aux++){
		winner[aux] = 0;
	}

	for (x = 0; x < 10; x++){
		for (y = 0; y < 10; y++){
			for (aux = 0; aux < n; aux++){
				if ((player[aux].grid[x][y] == 'A' || player[aux].grid[x][y] == 'B' || player[aux].grid[x][y] == 'C' || player[aux].grid[x][y] == 'D') && player[aux].view[x][y] == 1){
					winner[aux]++;
				}
			}
		}
	}

	free(winner);

	return ((p1 == 10) || (p2 == 10));
}

void show(table *player, int n, int sizex, int sizey){
	int x, y, aux = 0;
	
	while (aux < n){
		if (n == 1){
			printf("\n <-- Player\n");
		}
		else if (n > 2 && aux == 0){
			printf("\n <-- Player                   Computer #1-->\n");
		}
		else if (n == 2 && aux == 0) {
			printf("\n <-- Player                   Computer -->\n");
		}
		else if ((n-aux) != 1) {
			printf("\n <-- Computer #%d              Computer #%d-->\n", aux, aux + 1);
		}
		else {
			printf("\n <-- Computer #%d\n", aux);
		}

		if ((n-aux) != 1){
			for (x = 0; x < 10; x++){
				printf("|");

				for (y = 0; y < 10; y++){
					if (player[aux].view[x][y] == 1 && player[aux].grid[x][y] != '~'){
						printf("%c|", player[0].grid[x][y]);
					}
					else if (player[aux].view[x][y] == 1 && player[aux].grid[x][y] == '~'){
						printf("~|");
					}
					else{
						printf(" |");
					}
				}

				printf("   |");

				for (y = 0; y < 10; y++){
					if (player[aux+1].view[x][y] == 1 && player[aux+1].grid[x][y] != '~'){
						printf("%c|", player[0].grid[x][y]);
					}
					else if (player[aux+1].view[x][y] == 1 && player[aux+1].grid[x][y] == '~'){
						printf("~|");
					}
					else{
						printf(" |");
					}

				}

				printf("\n");
			}
			aux += 2;
		}
		else{
			for (x = 0; x < 10; x++){
				printf("|");

				for (y = 0; y < 10; y++){
					if (player[aux].view[x][y] == 1 && player[aux].grid[x][y] != '~'){
						printf("%c|", player[0].grid[x][y]);
					}
					else if (player[aux].view[x][y] == 1 && player[aux].grid[x][y] == '~'){
						printf("~|");
					}
					else{
						printf(" |");
					}
				}

				printf("\n");
			}
			aux++;
		}
	}
}

/*table createboard_player(table player, int sizex, int sizey){
	int x, y, orientation = 1;

	printf("Where do you want to place ship A (size 1)?\n");
	printf("Introduce X and Y coordinates:\n");
	scanf_s("%d %d", &x, &y);
	player = checklocation(player, x, y, orientation, 1);

	printf("Where do you want to place ship B (size 2)?\n");
	printf("Introduce X and Y coordinates:\n");
	scanf_s("%d %d", &x, &y);
	printf("\n1. Vertical\n2.Horizontal\n");
	scanf_s("%d", orientation);
	player = checklocation(player, x, y, orientation, 2);

	printf("Where do you want to place ship C (size 3)?\n");
	printf("Introduce X and Y coordinates:\n");
	scanf_s("%d %d", &x, &y);
	printf("\n1. Vertical\n2.Horizontal\n");
	scanf_s("%d", orientation);
	player = checklocation(player, x, y, orientation, 3);

	printf("Where do you want to place ship D (size 4)?\n");
	printf("Introduce X and Y coordinates:\n");
	scanf_s("%d %d", &x, &y);
	printf("\n1. Vertical\n2.Horizontal\n");
	scanf_s("%d", orientation);
	player = checklocation(player, x, y, orientation, 4);
	
	return player;
}*/

table createboard_automatic(table computer, int sizex, int sizey){
	srand(time(NULL));
	int x, y;

	x = rand() % sizex;
	y = rand() % sizey;

	computer.grid[x][y] = 'A';

	x = rand() % 10;
	y = rand() % 10;



	while (computer.grid[x][y] != '~' || ((x + 2)<sizex && (y + 2)<sizey && (x - 2) >= 0 && (y - 2) >= 0) || ((computer.grid[x + 1][y] != '~' || computer.grid[x + 2][y] != '~') && (computer.grid[x - 1][y] != '~' || computer.grid[x - 2][y] == 'A') && (computer.grid[x][y + 1] == 'A' || computer.grid[x][y + 2] == 'A') && (computer.grid[x][y - 1] == 'A' || computer.grid[x][y - 2] == 'A'))){
		x = rand() % 10;
		y = rand() % 10;
	}


	return computer;
}

table checklocation(table user, int x, int y, int orientation, int size, int sizex, int sizey){
	int aux_x, aux_y;

	if (orientation == 1){

	}

	return user;
}

table *preparelaser(table *player, int sizex, int sizey, int n){
	int x, y, aux = 0, nplayers;
	char option;
	int cols = (sizey * 2);
	int rows = (sizex % n) + (sizex / n);

	printf("Do we fire to the row or the column?\n");
	printf("  a. Row\n");
	printf("  b. Column\n");
	option = getchar();

	switch (option){
	case 'a':
		printf("\nPlease introduce the desired row (0 - %d)\n", cols - 1);
		scanf_s("%d", &y);

		while (y > rows){
			printf("\nThat's outside our range (0 - %d)\n", cols - 1);
			scanf_s("%d", &y);
		}

		while (rows > sizey){
			aux++;
			cols -= sizey;
		}

		for (x = 0; x < sizex; x++){
			player[aux].view[x][y] = 1;
			player[aux+1].view[x][y] = 1;
		}

		break;
	default:
		printf("\nPlease introduce the desired column (0 - %d)\n", cols-1);
		scanf_s("%d", &x);

		while (x > cols){
			printf("\nThat's outside our range (0 - %d)\n", cols-1);
			scanf_s("%d", &x);
		}

		while (cols > sizex){
			aux++;
			cols -= sizex;
		}

		if (aux == 0){
			for (int aux2 = 0; aux2 < n; aux2++){
				if (aux2 % 2 == 0){
					for (y = 0; y < sizex; y++){
						player[aux2].view[x][y] = 1;
					}
				}
			}
		}
		else{
			for (int aux2 = 0; aux2 < n; aux2++){
				if (aux2 % 2 != 0){
					for (y = 0; y < sizex; y++){
						player[aux2].view[x][y] = 1;
					}
				}
			}
		}
	}

	return player;
}