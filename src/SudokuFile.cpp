#include <string>
#include "SudokuFile.h"

using namespace std;

namespace sudoku_namespace
{

	// TODO: Check if p*q = N
	SudokuFile::SudokuFile( void )
	{
		N = 9;
		p = 3;
		q = 3;
		// do something with board
	}

	SudokuFile::SudokuFile( int new_N, int new_p, int new_q, int ** new_board )
	{
		N = new_N;
		p = new_p;
		q = new_q;
		setBoard( new_board );
	}
	int SudokuFile::getP( void ) const
	{
		return p;
	}

	int SudokuFile::getQ( void ) const
	{
		return q;
	}

	int SudokuFile::getN( void ) const
	{
		return N;
	}

	int** SudokuFile::getBoard( void ) const
	{
		return board;
	}

	void SudokuFile::setP( int new_p )
	{
		p = new_p;
	}

	void SudokuFile::setQ( int new_q )
	{
		q = new_q;
	}

	void SudokuFile::setN( int new_N )
	{
		N = new_N;
	}

	void SudokuFile::setBoard( int** new_board )
	{
	
	}

	std::istream &operator>>( std::istream &source, SudokuFile &dest )
	{

	}

	std::ostream &operator<<( std::ostream &dest, const SudokuFile &source )
	{

	}

}