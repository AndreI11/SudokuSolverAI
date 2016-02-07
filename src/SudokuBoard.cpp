#include <string>
#include <stdexcept>
#include "SudokuBoard.h"

using namespace std;

namespace sudoku_namespace
{

	SudokuBoard::SudokuBoard( void )
	{
		N = 9;
		p = 3;
		q = 3;
		//do something with board
	}

	SudokuBoard::SudokuBoard( int new_N, int new_p, int new_q)
	{
		if ( !checkNpq() ){
			throw std::invalid_argument("Setting of N,p,q invalidates N = p * q");
		}

		N = new_N;
		p = new_p;
		q = new_q;
	}
	int SudokuBoard::getP( void ) const
	{
		return p;
	}

	int SudokuBoard::getQ( void ) const
	{
		return q;
	}

	int SudokuBoard::getN( void ) const
	{
		return N;
	}

	int** SudokuBoard::getBoard( void ) const
	{
		return board;
	}

	void SudokuBoard::setN( int new_N ){
		N = new_N;
	}

	void SudokuBoard::setP( int new_p )
	{
		p = new_p;
	}

	void SudokuBoard::setQ( int new_q )
	{
		q = new_q;
	}

	void SudokuBoard::setBoard( int** new_board )
	{
		board = new_board;
	}

	//Wrote as a function in case we need to change it somehow later.
	bool SudokuBoard::checkNpq(){
		return p * q == N;
	}


	std::istream &operator>>( std::istream &source, SudokuBoard &dest )
	{

	}

	std::ostream &operator<<( std::ostream &dest, const SudokuBoard &source )
	{
		int** board = source.getBoard();
		int board_size = source.getN();

		dest << to_string(source.getN()) + " " + to_string(source.getQ()) + " " + to_string(source.getP()) + "\n";
		
		for (int row = 0; row < board_size; row++){
			
			for (int col = 0; col < board_size; col++ ){	
				int board_val = board[row][col];
				
				if (board_val > 9){

				}

			}
		} 

		return dest;
	}

}




