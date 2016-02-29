struct table{
	char grid[10][10];
	int view[10][10];
	int laser = 1;
};

struct coords{
	int x, y;
};

struct ships{
	coords B[2], C[3], D[4];
};

table checklocation(table user, int x, int y, int orientation, int size);
table createboard_player(table player);
table createboard_automatic(table computer);

int check(table *player, int n);
void show(table *player, int n);

table player1_attack(table player2);

int select_enemy(table *player, int n, int self);
table computer_turn(table enemy);