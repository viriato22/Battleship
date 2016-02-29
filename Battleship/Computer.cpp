#include "Board.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int select_enemy(table *player, int n, int self){	
	srand(time(NULL));
	int target;

	for (int counter = 0; counter < n; counter++){
		for (int x = 0; x < 10; x++){
			for (int y = 0; y < 10; y++){
				if ((player[counter].grid[x][y] == 'B' && player[counter].view[x][y] == '1') || (player[counter].grid[x][y] == 'C' && player[counter].view[x][y] == '1') || (player[counter].grid[x][y] == 'D' && player[counter].view[x][y] == '1')){
					return counter;
				}
			}
		}
	}
	target = rand() % n;
	while (target == self){
		target = rand() % n;
	}
	
	return target;
}


table computer_turn(table enemy){
	short x, y, nB = 0, nC = 0, nD = 0, x1, y1, x2, y2, aux = 0;
	char ship;
	ships enemy_ships;
	srand(time(NULL));

	for (x = 0; x < 10; x++){
		for (y = 0; y < 10; y++){
			if (enemy.grid[x][y] == 'B' && enemy.view[x][y] == '1'){
				enemy_ships.B[nB].x = x;
				enemy_ships.B[nB].y = y;
				nB++;
			}
			else if (enemy.grid[x][y] == 'C' && enemy.view[x][y] == '1'){
				enemy_ships.C[nC].x = x;
				enemy_ships.C[nC].y = y;
				nC++;
			}
			else if (enemy.grid[x][y] == 'D' && enemy.view[x][y] == '1'){
				enemy_ships.D[nD].x = x;
				enemy_ships.D[nD].y = y;
				nD++;
			}
		}
	}

	if (nB > 0 && nB < 2){
		x = enemy_ships.B[0].x;
		y = enemy_ships.B[0].y;

		if (enemy.view[x + 1][y] != 1){
			x++;
			enemy.view[x][y] = 1;
		}
		else if (enemy.view[x - 1][y] != 1){
			x--;
			enemy.view[x][y] = 1;
		}
		else if (enemy.view[x][y + 1] != 1){
			y++;
			enemy.view[x][y] = 1;
		}
		else{
			y--;
			enemy.view[x][y] = 1;
		}
	}
	else if (nC > 0 && nC < 3){
		if (nC == 2){
			x = enemy_ships.C[0].x;
			y = enemy_ships.C[0].y;
			x1 = enemy_ships.C[1].x;
			y1 = enemy_ships.C[1].y;

			if (enemy_ships.C[0].x - enemy_ships.C[1].x == 0){
				if (enemy.view[x][y + 1] != 1){
					y++;
					enemy.view[x][y] = 1;
				}
				else if (enemy.view[x][y - 1] != 1){
					y--;
					enemy.view[x][y] = 1;
				}
				else if (enemy.view[x1][y1 + 1] != 1){
					y = y1 + 1;
					enemy.view[x][y] = 1;
				}
				else if (enemy.view[x1][y1 - 1] != 1){
					y = y1 - 1;
					enemy.view[x][y] = 1;
				}
			}
			else{
				if (enemy.view[x + 1][y] != 1){
					x++;
					enemy.view[x][y] = 1;
				}
				else if (enemy.view[x][y - 1] != 1){
					x--;
					enemy.view[x][y] = 1;
				}
				else if (enemy.view[x1][y1 + 1] != 1){
					x = x1 + 1;
					enemy.view[x][y] = 1;
				}
				else if (enemy.view[x1][y1 - 1] != 1){
					x = x1 - 1;
					enemy.view[x][y] = 1;
				}
			}
		}
		else{
			if (enemy.view[x + 1][y] != 1){
				x++;
				enemy.view[x][y] = 1;
			}
			else if (enemy.view[x - 1][y] != 1){
				x--;
				enemy.view[x][y] = 1;
			}
			else if (enemy.view[x][y + 1] != 1){
				y++;
				enemy.view[x][y] = 1;
			}
			else{
				y--;
				enemy.view[x][y] = 1;
			}
		}
	}
	else if (nD>0 && nD < 4){
		if (nD == 2){
			x = enemy_ships.D[0].x;
			y = enemy_ships.D[0].y;
			x1 = enemy_ships.D[1].x;
			y1 = enemy_ships.D[1].y;

			if (enemy_ships.D[0].x - enemy_ships.D[1].x == 0){
				if (enemy.view[x][y + 1] != 1){
					y++;
					enemy.view[x][y] = 1;
				}
				else if (enemy.view[x][y - 1] != 1){
					y--;
					enemy.view[x][y] = 1;
				}
				else if (enemy.view[x1][y1 + 1] != 1){
					y = y1 + 1;
					enemy.view[x][y] = 1;
				}
				else{
					y = y1 - 1;
					enemy.view[x][y] = 1;
				}
			}
			else{
				if (enemy.view[x + 1][y] != 1){
					x++;
					enemy.view[x][y] = 1;
				}
				else if (enemy.view[x][y - 1] != 1){
					x--;
					enemy.view[x][y] = 1;
				}
				else if (enemy.view[x1 + 1][y1] != 1){
					x = x1 + 1;
					enemy.view[x][y] = 1;
				}
				else{
					x = x1 - 1;
					enemy.view[x][y] = 1;
				}
			}
		}
		else if (nD == 3){
			x = enemy_ships.D[0].x;
			y = enemy_ships.D[0].y;
			x1 = enemy_ships.D[1].x;
			y1 = enemy_ships.D[1].y;
			x2 = enemy_ships.D[2].x;
			y2 = enemy_ships.D[2].y;

			if (enemy_ships.D[0].x - enemy_ships.D[1].x == 0){
				if (enemy.view[x][y + 1] != 1){
					y++;
					enemy.view[x][y] = 1;
				}
				else if (enemy.view[x][y - 1] != 1){
					y--;
					enemy.view[x][y] = 1;
				}
				else if (enemy.view[x1][y1 + 1] != 1){
					y = y1 + 1;
					enemy.view[x][y] = 1;
				}
				else if (enemy.view[x2][y2 - 1] != 1){
					y = y1 - 1;
					enemy.view[x][y] = 1;
				}
				else if (enemy.view[x2][y2 + 1] != 1){
					y = y2 + 1;
					enemy.view[x][y] = 1;
				}
				else {
					y = y2 - 1;
					enemy.view[x][y] = 1;
				}
			}
			else{
				if (enemy.view[x + 1][y] != 1){
					x++;
					enemy.view[x][y] = 1;
				}
				else if (enemy.view[x - 1][y] != 1){
					x--;
					enemy.view[x][y] = 1;
				}
				else if (enemy.view[x1 + 1][y1] != 1){
					x = x1 + 1;
					enemy.view[x][y] = 1;
				}
				else if (enemy.view[x1 - 1][y1] != 1){
					x = x1 - 1;
					enemy.view[x][y] = 1;
				}
				else if (enemy.view[x2 + 1][y1] != 1){
					x = x2 + 1;
					enemy.view[x][y] = 1;
				}
				else{
					x = x2 - 1;
					enemy.view[x][y] = 1;
				}
			}
		}
		else{
			if (enemy.view[x + 1][y] != 1){
				x++;
				enemy.view[x][y] = 1;
			}
			else if (enemy.view[x - 1][y] != 1){
				x--;
				enemy.view[x][y] = 1;
			}
			else if (enemy.view[x][y + 1] != 1){
				y++;
				enemy.view[x][y] = 1;
			}
			else{
				y--;
				enemy.view[x][y] = 1;
			}
		}
	}
	else {
		x = rand() % 10;
		y = rand() % 10;

		while (enemy.view[x][y] == 1){
			x = rand() % 10;
			y = rand() % 10;
		}
	}

	printf("Computer [%d][%d]:", x, y);

	enemy.view[x][y] = 1;

	if (enemy.grid[x][y] == '~'){
		printf(" Missed\n");
	}
	else {
		printf("Hit ");
		
		ship = enemy.grid[x][y];

		for (x = 0; x < 10; x++){
			for (y = 0; y < 10; y++){
				if (enemy.grid[x][y] == ship && enemy.view[x][y] == 1){
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

	return enemy;
}