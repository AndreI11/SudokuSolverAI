#ifndef SUDOKUFILE_H
#define SUDOKUFILE_H

#include <string>
#include <iostream>
class SudokuFile{

public:
	SudokuFile(int N, int p, int q, int ** board);
	int getP();
	int getQ();
	int getN();
	int** getBoard();
	void setP(int p);
	void setQ(int q);
	void setN(int n);
	void setBoard(int** board);
	std::ostream& operator<<(std::ostream& os);

private:
	int p;
	int q;
	int N; 
	int** board;


};

#endif