struct table{
	char **grid;
	int **view;
	int laser = 1;
	int lost = 0;
};

struct coords{
	int x, y;
};

struct ships{
	coords B[2], C[3], D[4];
};

table checklocation(table user, int x, int y, int orientation, int size, int sizex, int sizey);
//table createboard_player(table player, int sizex, int sizey);
table createboard_automatic(table computer, int sizex, int sizey);

int check(table *player, int n, int sizex, int sizey);
void show(table *player, int n, int sizex, int sizey);

table player1_attack(table player2, int sizex, int sizey);
table *preparelaser(table *player, int sizex, int sizey, int n);

int select_enemy(table *player, int n, int self, int sizex, int sizey);
table computer_turn(table enemy, int sizex, int sizey);