#include <iostream>
#include <fstream>
#include "Table.h"
#include "Functions.h"
using namespace std;
int main()
{
	cout << 7 % 3;
	Table table;
	/*
	0 0 0|0 0 0|0 0 0
	0 0 0|0 0 0|0 0 0
	0 0 0|0 0 0|0 0 0
	----------------
	0 0 0|0 0 0|0 0 0
	0 0 0|0 0 0|0 0 0
	0 0 0|0 0 0|0 0 0
	-----------------
	0 0 0|0 0 0|0 0 0
	0 0 0|0 0 0|0 0 0
	0 0 0|0 0 0|0 0 0
	*/
	table.solveSudoku();
}