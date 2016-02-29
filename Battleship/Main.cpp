#include <stdio.h>
#include <stdlib.h>
#include "Board.h"

int main() {
	short counter, winner = 0;
	int x, y, n, aux, surrender = 0, sel;
	char action;
	
	printf("Introduce number of players:\n");
	scanf_s("%d", &n);

	table *player = (table*)malloc(sizeof(table)*(n));

	if (n == 0){
		printf("No players means no game\n");
	}
	else {
		//Defined assignation
		for (x = 0; x < 10; x++){
			for (y = 0; y < 10; y++){
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

		for (counter = 0; winner == 0; counter++){
			if (counter%n == 0 && surrender != 1){
				printf("                        Turn #%d:\n", counter / n);

				show(player, n);

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

					player[aux] = player1_attack(player[aux]);
					break;
				case 'b':
					break;
				case 'c':
					surrender = 1;
					break;
				default:
					printf("We don't understand that order.\n\n");
					goto tryagain;
				}
			}
			else{
				sel = select_enemy(player, n, counter%n);
				player[sel] = computer_turn(player[sel]);
			}

			winner = check(player, n);
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

