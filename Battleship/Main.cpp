#include <stdio.h>
#include <stdlib.h>
#include "Board.h"

int main() {
	table player1, player2;
	short counter, winner = 0;
	int x, y;

	/*player1 = createboard1(player1);
	player2 = createboard2(player2);*/

	for (x = 0; x < 10; x++){
		for (y = 0; y < 10; y++){
			if (x == 1 && y == 1){
				player1.grid[x][y] = 'A';
				player2.grid[x][y] = 'A';
			}
			else if ((x == 1 && y == 2) || (x == 2 && y == 2) || (x == 3 && y == 2)){
				player1.grid[x][y] = 'C';
				player2.grid[x][y] = 'C';
			}
			else if ((x == 7 && y == 0) || (x == 7 && y == 1)){
				player1.grid[x][y] = 'B';
				player2.grid[x][y] = 'B';
			}
			else if ((x == 6 && y == 5) || (x == 6 && y == 6) || (x == 6 && y == 7) || (x == 6 && y == 8)){
				player1.grid[x][y] = 'D';
				player2.grid[x][y] = 'D';
			}
			else {
				player1.grid[x][y] = '~';
				player2.grid[x][y] = '~';
			}

			player1.view[x][y] = 0;
			player2.view[x][y] = 0;
		}
	}

	show(player1, player2);

	for (counter = 0; winner == 0; counter++){
		if ((counter % 2) == 0){
			player2 = player1_turn(player1);
		}
		else{
			player1 = player2_turn(player2);
		}

		show(player1, player2);

		winner = check(player1, player2);
	}

	printf("\nThe Winner is:");

	if ((counter % 2) == 0){
		printf(" Player 2\n");
	}
	else{
		printf(" Player 1\n");
	}

	system("pause");
	return 0;
}

