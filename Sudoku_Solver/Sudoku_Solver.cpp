#include <iostream>
#include <fstream>
#include "Table.h"
#include "Functions.h"
using namespace std;
int main()
{
	Table table;
    table.printTable();
	cout << table.solveSudoku() << endl;
	table.printTable();
}