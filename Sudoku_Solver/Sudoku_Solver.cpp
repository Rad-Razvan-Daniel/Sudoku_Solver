#include <iostream>
#include <fstream>
#include "Table.h"
#include "Functions.h"
using namespace std;
int main()
{
	Table table;
	table.initTable();
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