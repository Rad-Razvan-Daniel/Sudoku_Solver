#include "Table.h"
Table::Table()
{
	//initTable();
}
Table::~Table() 
{
	//delete[] table[];
}

void Table::printTable()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			std::cout << table[i][j];
		}
		std::cout << std::endl;
	}
}
void Table::initTable()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			table[i][j] = 0;
}

bool Table::isValid(const int line, const int column, int val) //checks if one of the numbers is compatible with the row, column and its box
{
	//check row
	for (int i = 0; i < 8; i++)
		if (table[line][i] == val) return false;

	//check column
	for (int i = 0; i < 8; i++)
		if (table[i][column] == val) return false;

	//check box
	int x = line - line % 3; //lets say line is 8. line%8 = 2. 8-2 = 6 ; starting from the row 6 we can play around with [6],[7],[8]
	int y = column - column % 3;
	for (int i = 0; i < 3; i++)
		for (int ii = 0; ii < 3; ii++)
			if (table[i + x][ii + y] == val)return false;

	return true;
}