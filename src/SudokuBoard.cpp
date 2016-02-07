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

	SudokuBoard::SudokuBoard( int new_N, int new_p, int new_q, int ** new_board )
	{
		if ( !checkNpq() ){
			throw std::invalid_argument("Setting of N,p,q invalidates N = p * q");
		}

		N = new_N;
		p = new_p;
		q = new_q;
		setBoard( new_board );
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
	if ( !checkNpq() ){
			throw invalid_argument("Setting of N invalidates N = p * q");
		}

		N = new_N;
	}

void SudokuBoard::setP( int new_p )
	{
		if ( !checkNpq() ){
			throw invalid_argument("Setting of p invalidates N = p * q");
		}

		p = new_p;

	}

void SudokuBoard::setQ( int new_q )
	{
		if ( !checkNpq() ){
			throw invalid_argument("Setting of q invalidates N = p * q");
		}

		q = new_q;
	}

	void SudokuBoard::setBoard( int** new_board )
	{
		board = new_board;
	}

	//Wrote as a function in case we need to check it somehow later.
	bool SudokuBoard::checkNpq(){
		return p * q == N;
	}

	std::istream &operator>>( std::istream &source, SudokuBoard &dest )
	{

	}

	std::ostream &operator<<( std::ostream &dest, const SudokuBoard &source )
	{

	}

}