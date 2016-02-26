struct table{
	char grid[10][10];
	int view[10][10];
};

struct coords{
	int x, y;
};

struct ships{
	coords B[2], C[3], D[4];
};

table player1_turn(table player2);
table player2_turn(table player1);
int check(table player1, table player2);
/*table createboard1(table player1);
table createboard2(table player2);*/
void show(table player1, table player2);
void show1(int x, table player1);
void show2(int x, table player2);