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

bool Table::solve(int line , int column)	
{												

	if (line == 8 && column == 9)
		return true;
	//safety check because when we solve() we will encounter column+1, which can be 9
	if (column == 9) {
		line++;
		column = 0;
	}
	if (table[line][column] != 0)
		return solve(line, column+1);


	for (int nr = 1; nr < 10; nr++)
	{
		//check validity
		if (isValid(line,column, nr))
		{
			table[line][column] = nr;
			if(solve(line,column))
				return true;

		}
		//if we got here, n was wrong, meaning we should make this position the initial value; 0
		table[line][column] = 0;
	}
	return false;
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
	int y = column- column% 3;
	for (int i = 0; i < 3; i++)
		for (int ii = 0; ii < 3; ii++)
			if (table[i + x][ii + y] == val)return false;
		
	
	return true;
}