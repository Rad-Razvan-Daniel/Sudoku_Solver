#pragma once
class Table
{
	int table[9][9];
public:
	Table();
	void initTable();
	bool isValid(int line, int column);
	void printTable();
	bool solveSudoku();
};

