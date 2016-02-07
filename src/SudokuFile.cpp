#include "SudokuFile.h"

SudokuFile::SudokuFile(int N, int p, int q, int ** board){
	this->N = N;
	this->p = p;
	this->q = q;
	this->board = nullptr;
}