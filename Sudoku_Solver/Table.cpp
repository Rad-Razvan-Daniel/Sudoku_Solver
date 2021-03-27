#include "Table.h"
#include "Functions.h"
Table::Table()
{

}
void Table::initTable()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			table[i][j] = 0;
		}
	}
}

void Table::printTable()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			std::cout << table[i][j];
		}
		cout << endl;
	}
}

bool Table::solveSudoku()
{
	isValid(0,0);
	//return true if it's been solved
	//return false if it's unsolvable
	return false;
}

void Table::initTable()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			table[i][j] = 0;
		}
	}
}
bool Table::isValid(int line, int column)
{
	//check row and columns

}