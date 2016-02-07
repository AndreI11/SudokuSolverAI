#include "SudokuFileReader.h"
using namespace std;

namespace sudoku_namespace
{
	SudokuBoard *readFile ( string InputFileName )
	{
		ifstream inputFile;
		inputFile.open(InputFileName);

		if ( inputFile.fail() )
			;//Handle Error

		SudokuBoard* sb = nullptr;

		for (int lineNumber = 0; ; lineNumber++)
			if ( !readLine( inputFile, sb, lineNumber ) )
				break;

		if ( sb == nullptr )
			sb = new SudokuBoard();

		return sb;
	}

	bool readLine ( istream& inputFile,  SudokuBoard* sb, int lineNumber )
	{
		if ( sb != nullptr && lineNumber == 0 )
		{
			int n, p, q;
			inputFile >> n >> p >> q;
			sb = new SudokuBoard(n, p, q);
			return true;
		}

		string line;
		getline(inputFile, line);
		istringstream lineStream(line);
		int numOfColumns = sb->getN();
		for ( int columnIndex = 0; columnIndex < numOfColumns; ++columnIndex )
		{
			string token;
			lineStream >> token;
			sb->editBoard(lineNumber-1, columnIndex, token);
		}
	}
}