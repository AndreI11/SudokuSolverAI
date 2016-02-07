#include <iostream>
#include "Odometer.h"
#include "SudokuBoard.h"
using namespace std;
using namespace sudoku_namespace;

int main( int argc, char* argv[] )
{
	
	if ( argc < 4 )
	{
		cout << "Invalid number of arguments. Must include input file name, output file name, and timeout.";
		return 0; // quit
	}
	string InputFileName = argv[1];
	string OutputFileName = argv[2];
	int timeout = 1000*atoi(argv[3]);
	

	// Load Sudoku File
	// Solve Sudoku Puzzle
	// Publish Results
	

	return 0;

}

/*
Testing <<
	SudokuBoard board;
	int** newBoard;
	newBoard = new int*[9];
	for (int i =0; i<9;i++){
		newBoard[i] = new int[9];
	}
	for (int i =0; i<9;i++){
		for (int j=0; j<9;j++){
			newBoard[i][j] = 'A';
			cout << newBoard[i][j];
		}
	}
	board.setBoard(newBoard);
	cout << board;
	*/