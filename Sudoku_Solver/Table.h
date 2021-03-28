#pragma once
class Table
{
	bool isValid(const int line, const int column, const int val);
	void initTable();

	int table[9][9] ={ { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
					   { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
					   { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
					   { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
					   { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
					   { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
					   { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
					   { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
					   { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
public:

	Table();
	~Table();
	void printTable();
	bool solveSudoku(int line = 0, int column = 0);
};

