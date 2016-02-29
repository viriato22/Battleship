#include <stdio.h>
#include <stdlib.h>
#include "Board.h"

int main() {
	short counter, winner = 0;
	int x, y, n, aux, aux2, sel;
	int sizex, sizey;
	char action, weapon;
	
	printf("Introduce number of players:\n");
	scanf_s("%d", &n);

	table *player = (table*)malloc(sizeof(table)*(n));

	if (n == 0){
		printf("No players means no game\n");
	}
	else if (n == 1){
		printf("Don't play by yourself\n");
	}
	else {
		printf("Introduce the height and width of the board\n");
		scanf_s("%d %d", &sizex, &sizey);

		for (aux = 0; aux < n; aux++){
			player[aux].grid = (char**)malloc(sizeof(char)*(sizex));
			player[aux].view = (int**)malloc(sizeof(int)*(sizex));
			for (aux2 = 0; aux2 < sizex; aux2++){
				player[aux].grid[aux2] = (char*)malloc(sizeof(char)*(sizey));
				player[aux].view[aux2] = (int*)malloc(sizeof(int)*(sizey));
			}
		}

		//Defined assignation
		
		for (x = 0; x < sizex; x++){
			for (y = 0; y < sizey; y++){
				for (aux = 0; aux < n; aux++){
					if (x == 1 && y == 1){
						player[aux].grid[x][y] = 'A';
					}
					else if ((x == 1 && y == 2) || (x == 2 && y == 2) || (x == 3 && y == 2)){
						player[aux].grid[x][y] = 'C';
					}
					else if ((x == 7 && y == 0) || (x == 7 && y == 1)){
						player[aux].grid[x][y] = 'B';
					}
					else if ((x == 6 && y == 5) || (x == 6 && y == 6) || (x == 6 && y == 7) || (x == 6 && y == 8)){
						player[aux].grid[x][y] = 'D';
					}
					else {
						player[aux].grid[x][y] = '~';
					}
					player[aux].view[x][y] = 0;
				}
			}
		}
		
		// Rand asignation
		/*
		for (aux = 0; aux < n; aux++){
			player[aux] = createboard_automatic(player[aux], sizex, sizey);
		}
		*/

		for (counter = 0; winner == 0; counter++){
			if (counter%n == 0 && player[0].lost != 1){
				printf("                        Turn #%d:\n", counter / n);

				show(player, n, sizex, sizey);

			tryagain:

				printf("What do you want to do captain?\n");
				printf("   a. Attack\n");
				printf("   b. Special Action\n");
				printf("   c. Surrender\n");
				scanf_s("%c", &action, 1);

				switch (action){
				case 'a':
					printf("Select target\n");
					scanf_s("%d", &aux);

					while (aux == 0){
						printf("That's us captain, please select another target.\n");
						scanf_s("%d", &aux);
					}

					while (aux >= n){
						printf("We can't find that fleet, please select another target.\n");
						scanf_s("%d", &aux);
					}

					player[aux] = player1_attack(player[aux], sizex, sizey);
					break;
				case 'b':
					printf("Select special weapon:\n");
					printf("  a. Laser\n");
					printf("  b. Cancel\n");
					weapon = getchar();
					
					switch (weapon){
					case 'a':
						player[0].laser--;
						player = preparelaser(player, sizex, sizey, n);
						break;
					default:
						goto tryagain;
					}

					break;
				case 'c':
					player[0].lost = 1;
					break;
				default:
					printf("We don't understand that order.\n\n");
					goto tryagain;
				}
			}
			else if(player[counter%n].lost != 1){
				sel = select_enemy(player, n, counter%n, sizex, sizey);
				player[sel] = computer_turn(player[sel], sizex, sizey);
			}

			winner = check(player, n, sizex, sizey);
		}

		printf("\nThe Winner is:");

		if ((counter%n) == 0){
			printf(" Player\n");
		}
		else{
			printf(" Computer #\n", counter%n);
		}
	}

	free(player);

	system("pause");
	return 0;
}

