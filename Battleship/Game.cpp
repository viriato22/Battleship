#include "Board.h"
#include <stdio.h>

/*table createboard1(table player1){
	int x, y;
	
	for (x = 0; x < 10; x++){
		for (y = 0; y < 10; y++){
			if (x == 1 && y == 1){
				player1.grid[x][y] = 'A';
			}
			else if ((x == 1 && y == 2) || (x == 2 && y == 2) || (x == 3 && y == 2)){
				player1.grid[x][y] = 'C';
			}
			else if ((x == 7 && y == 0) || (x == 7 && y == 1)){
				player1.grid[x][y] = 'B';
			}
			else if ((x == 6 && y == 5) || (x == 6 && y == 6) || (x == 6 && y == 7) || (x == 6 && y == 8)){
				player1.grid[x][y] = 'D';
			}
			else {
				player1.grid[x][y] = '~';
			}
			player1.view[x][y] = 0;
		}
	}

	return player1;
}

table createboard2(table player2){
	int x, y;

	for (x = 0; x < 10; x++){
		for (y = 0; y < 10; y++){
			if (x == 1 && y == 1){
				player2.grid[x][y] = 'A';
			}
			else if ((x == 1 && y == 2) || (x == 2 && y == 2) || (x == 3 && y == 2)){
				player2.grid[x][y] = 'C';
			}
			else if ((x == 7 && y == 0) || (x == 7 && y == 1)){
				player2.grid[x][y] = 'B';
			}
			else if ((x == 6 && y == 5) || (x == 6 && y == 6) || (x == 6 && y == 7) || (x == 6 && y == 8)){
				player2.grid[x][y] = 'D';
			}
			else {
				player2.grid[x][y] = '~';
			}
			player2.view[x][y] = 0;
		}
	}

	return player2;
}*/

table player1_turn(table player2){
	int x, y, aux = 0;
	char ship;
	printf("\nIntroduce coordinates captain:\n");
	scanf_s("%d %d", &x, &y);

	while (player2.view[x][y] == 1){
		printf("\nCaptain, we alredy hit there\n");
		scanf_s("%d %d", &x, &y);
	}

	while (x >= 10 || y >= 10 || x < 0 || y < 0){
		printf("\nCaptain, that's outside our scope\n");
		scanf_s("%d %d", &x, &y);
	}

	printf("Player [%d][%d]:", x, y);

	player2.view[x][y] = 1;

	if (player2.grid[x][y] == '~'){
		printf("Missed\n");
	}
	else {
		printf("Hit ");
		
		ship = player2.grid[x][y];

		for (x = 0; x < 10; x++){
			for (y = 0; y < 10; y++){
				if (player2.grid[x][y] == ship && player2.view[x][y] == 1){
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

	return player2;
}

int check (table player1, table player2){
	int x, y, p1 = 0, p2 = 0, winner;

	for (x = 0; x < 10; x++){
		for (y = 0; y < 10; y++){
			if ((player1.grid[x][y] == 'A' || player1.grid[x][y] == 'B' || player1.grid[x][y] == 'C' || player1.grid[x][y] == 'D') && player1.view[x][y] == 1){
				p2++;
			}
			if ((player2.grid[x][y] == 'A' || player2.grid[x][y] == 'B' || player2.grid[x][y] == 'C' || player2.grid[x][y] == 'D') && player2.view[x][y] == 1){
				p1++;
			}
		}
	}

	return ((p1 == 10) || (p2 == 10));
}

void show(table player1, table player2){
	int x, y;
	printf("\n <-- Player                   Computer -->\n");

	for (x = 0; x < 10; x++){
		printf("|");

		show1(x, player1);

		printf("   |");

		show2(x, player2);

		printf("\n");
	}
}

void show1(int x, table player1){
	int y;

	for (y = 0; y < 10; y++){
		if (player1.view[x][y] == 1 && player1.grid[x][y] != '~'){
			printf("%c|", player1.grid[x][y]);
		}
		else if (player1.view[x][y] == 1 && player1.grid[x][y] == '~'){
			printf("~|");
		}
		else{
			printf(" |");
		}

	}
}

void show2(int x, table player2){
	int y;

	for (y = 0; y < 10; y++){
		if (player2.view[x][y] == 1 && player2.grid[x][y] != '~'){
			printf("%c|", player2.grid[x][y]);
		}
		else if (player2.view[x][y] == 1 && player2.grid[x][y] == '~'){
			printf("~|");
		}
		else{
			printf(" |");
		}

	}
}