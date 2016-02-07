#ifndef SUDOKUFILE_H
#define SUDOKUFILE_H

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
	std::ostream& operator<< ( std::ostream& os );

private:
	int p;
	int q;
	int N;
	int** board;

};

#endif