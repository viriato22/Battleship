#include <stdio.h>
#include "Board.h"
#include <stdlib.h>
#include <time.h>

table player2_turn(table player1){
	short x, y, nB = 0, nC = 0, nD = 0, x1, y1, x2, y2, aux = 0;
	char ship;
	ships player1_ships;
	srand(time(NULL));

	for (x = 0; x < 10; x++){
		for (y = 0; y < 10; y++){
			if (player1.grid[x][y] == 'B' && player1.view[x][y] == '1'){
				player1_ships.B[nB].x = x;
				player1_ships.B[nB].y = y;
				nB++;
			}
			else if (player1.grid[x][y] == 'C' && player1.view[x][y] == '1'){
				player1_ships.C[nC].x = x;
				player1_ships.C[nC].y = y;
				nC++;
			}
			else if (player1.grid[x][y] == 'D' && player1.view[x][y] == '1'){
				player1_ships.D[nD].x = x;
				player1_ships.D[nD].y = y;
				nD++;
			}
		}
	}

	if (nB > 0 && nB < 2){
		x = player1_ships.B[0].x;
		y = player1_ships.B[0].y;

		if (player1.view[x + 1][y] != 1){
			x++;
			player1.view[x][y] = 1;
		}
		else if (player1.view[x - 1][y] != 1){
			x--;
			player1.view[x][y] = 1;
		}
		else if (player1.view[x][y + 1] != 1){
			y++;
			player1.view[x][y] = 1;
		}
		else{
			y--;
			player1.view[x][y] = 1;
		}
	}
	else if (nC > 0 && nC < 3){
		if (nC == 2){
			x = player1_ships.C[0].x;
			y = player1_ships.C[0].y;
			x1 = player1_ships.C[1].x;
			y1 = player1_ships.C[1].y;

			if (player1_ships.C[0].x - player1_ships.C[1].x == 0){
				if (player1.view[x][y + 1] != 1){
					y++;
					player1.view[x][y] = 1;
				}
				else if (player1.view[x][y - 1] != 1){
					y--;
					player1.view[x][y] = 1;
				}
				else if (player1.view[x1][y1 + 1] != 1){
					y = y1 + 1;
					player1.view[x][y] = 1;
				}
				else if (player1.view[x1][y1 - 1] != 1){
					y = y1 - 1;
					player1.view[x][y] = 1;
				}
			}
			else{
				if (player1.view[x + 1][y] != 1){
					x++;
					player1.view[x][y] = 1;
				}
				else if (player1.view[x][y - 1] != 1){
					x--;
					player1.view[x][y] = 1;
				}
				else if (player1.view[x1][y1 + 1] != 1){
					x = x1 + 1;
					player1.view[x][y] = 1;
				}
				else if (player1.view[x1][y1 - 1] != 1){
					x = x1 - 1;
					player1.view[x][y] = 1;
				}
			}
		}
		else{
			if (player1.view[x + 1][y] != 1){
				x++;
				player1.view[x][y] = 1;
			}
			else if (player1.view[x - 1][y] != 1){
				x--;
				player1.view[x][y] = 1;
			}
			else if (player1.view[x][y + 1] != 1){
				y++;
				player1.view[x][y] = 1;
			}
			else{
				y--;
				player1.view[x][y] = 1;
			}
		}
	}
	else if (nD>0 && nD < 4){
		if (nD == 2){
			x = player1_ships.D[0].x;
			y = player1_ships.D[0].y;
			x1 = player1_ships.D[1].x;
			y1 = player1_ships.D[1].y;

			if (player1_ships.D[0].x - player1_ships.D[1].x == 0){
				if (player1.view[x][y + 1] != 1){
					y++;
					player1.view[x][y] = 1;
				}
				else if (player1.view[x][y - 1] != 1){
					y--;
					player1.view[x][y] = 1;
				}
				else if (player1.view[x1][y1 + 1] != 1){
					y = y1 + 1;
					player1.view[x][y] = 1;
				}
				else{
					y = y1 - 1;
					player1.view[x][y] = 1;
				}
			}
			else{
				if (player1.view[x + 1][y] != 1){
					x++;
					player1.view[x][y] = 1;
				}
				else if (player1.view[x][y - 1] != 1){
					x--;
					player1.view[x][y] = 1;
				}
				else if (player1.view[x1 + 1][y1] != 1){
					x = x1 + 1;
					player1.view[x][y] = 1;
				}
				else{
					x = x1 - 1;
					player1.view[x][y] = 1;
				}
			}
		}
		else if (nD == 3){
			x = player1_ships.D[0].x;
			y = player1_ships.D[0].y;
			x1 = player1_ships.D[1].x;
			y1 = player1_ships.D[1].y;
			x2 = player1_ships.D[2].x;
			y2 = player1_ships.D[2].y;

			if (player1_ships.D[0].x - player1_ships.D[1].x == 0){
				if (player1.view[x][y + 1] != 1){
					y++;
					player1.view[x][y] = 1;
				}
				else if (player1.view[x][y - 1] != 1){
					y--;
					player1.view[x][y] = 1;
				}
				else if (player1.view[x1][y1 + 1] != 1){
					y = y1 + 1;
					player1.view[x][y] = 1;
				}
				else if (player1.view[x2][y2 - 1] != 1){
					y = y1 - 1;
					player1.view[x][y] = 1;
				}
				else if (player1.view[x2][y2 + 1] != 1){
					y = y2 + 1;
					player1.view[x][y] = 1;
				}
				else {
					y = y2 - 1;
					player1.view[x][y] = 1;
				}
			}
			else{
				if (player1.view[x + 1][y] != 1){
					x++;
					player1.view[x][y] = 1;
				}
				else if (player1.view[x - 1][y] != 1){
					x--;
					player1.view[x][y] = 1;
				}
				else if (player1.view[x1 + 1][y1] != 1){
					x = x1 + 1;
					player1.view[x][y] = 1;
				}
				else if (player1.view[x1 - 1][y1] != 1){
					x = x1 - 1;
					player1.view[x][y] = 1;
				}
				else if (player1.view[x2 + 1][y1] != 1){
					x = x2 + 1;
					player1.view[x][y] = 1;
				}
				else{
					x = x2 - 1;
					player1.view[x][y] = 1;
				}
			}
		}
		else{
			if (player1.view[x + 1][y] != 1){
				x++;
				player1.view[x][y] = 1;
			}
			else if (player1.view[x - 1][y] != 1){
				x--;
				player1.view[x][y] = 1;
			}
			else if (player1.view[x][y + 1] != 1){
				y++;
				player1.view[x][y] = 1;
			}
			else{
				y--;
				player1.view[x][y] = 1;
			}
		}
	}
	else {
		x = rand() % 10;
		y = rand() % 10;

		while (player1.view[x][y] == 1){
			x = rand() % 10;
			y = rand() % 10;
		}
	}

	printf("Computer [%d][%d]:", x, y);

	player1.view[x][y] = 1;

	if (player1.grid[x][y] == '~'){
		printf(" Missed\n");
	}
	else {
		printf("Hit ");
		
		ship = player1.grid[x][y];

		for (x = 0; x < 10; x++){
			for (y = 0; y < 10; y++){
				if (player1.grid[x][y] == ship && player1.view[x][y] == 1){
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

	return player1;
}