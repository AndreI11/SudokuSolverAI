#ifndef SUDOKUFILE_H
#define SUDOKUFILE_H

namespace sudoku_namespace
{
	class SudokuFile
	{

	public:
		// Constructors
		SudokuFile( void );
		SudokuFile( int N, int p, int q, int ** board );

		// Information
		int getP( void ) const;
		int getQ( void ) const;
		int getN( void ) const;
		int** getBoard( void ) const;

		// Changers
		void setP( int p );
		void setQ( int q );
		void setN( int n );
		void setBoard( int** board );
			
		// operators
		friend std::istream &operator>>( std::istream &source, SudokuFile &dest );
		friend std::ostream &operator<<( std::ostream &dest, const SudokuFile &source );

	private:
		int p;
		int q;
		int N;
		int** board;

	};
}

#endif