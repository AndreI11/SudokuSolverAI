#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

namespace sudoku_namespace
{
	class SudokuBoard
	{

	public:
		// Constructors
		SudokuBoard( void );
		SudokuBoard( int N, int p, int q );

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
		friend std::istream &operator>>( std::istream &source, SudokuBoard &dest );
		friend std::ostream &operator<<( std::ostream &dest, const SudokuBoard &source );

	private:
		int p;
		int q;
		int N;
		int** board;
		bool checkNpq();

	};
}

#endif