#pragma once
class Table
{
	int table[9][9];
	bool isValid(const int& line, const int& column);
	void initTable();

public:
	Table();
	~Table();
	void printTable();
	bool solveSudoku();
};

