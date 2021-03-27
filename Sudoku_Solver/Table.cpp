#include "Table.h"
#include "Functions.h"
Table::Table()
{
	initTable();
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
		cout << endl;
		
	}
}

bool Table::solveSudoku()	//return true if it's been solved
{							//return false if it's unsolvable
	if (isValid(0, 0)) {}//go check next



	return false;
}

void Table::initTable()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			table[i][j] = 0;
		
	
}
bool Table::isValid(const int &line, const int &column)
{
	//check row
	for (int i = 0; i < 9; i++)
		if (table[line] == table[i]) return false;
	
	//check column
	for (int i = 0; i < 9; i++)
		if (table[line][column] == table[line][i]) return false;
	

	//check box
	int x = line - line % 3; //lets say line is 8. line%8 = 2. 8-2 = 6 ; starting from the row 6 we can play around with [6],[7],[8]
	int y = column- column% 3;
	for (int i = 0; i < 3; i++)
		for (int ii = 0; ii < 3; ii++)
			if (table[i + x][ii + y] == table[line][column])return false;
		
	
	return true;
}