#include "Table.h"
#include "Game.h"
using namespace std;
int main()
{
	Table table;
    table.printTable();
	cout << table.solve() << endl;
	table.printTable();
	Game game;
	game.runPlease();
}