#include "Odometer.h"

using namespace std;

namespace sudoku_namespace
{
	Odometer::Odometer( ){
		startChar = 'A';
		populateTokensAZ();
	}

	void Odometer::populateTokensAZ()
	{
		int startAsNum = int('A');

		for ( int i = 10; i <= startAsNum - (int) 'Z' + 1; i++ ){
			char nextChar = (char) startAsNum++;
			string toString(1,nextChar);
			tokenMap[ toString ] = i++;  //Convert to int, add 1 and convert back to char. A->B.
		}

	}

	int Odometer::odometerToInt(string value)
	{
		return tokenMap[ value ];
	}

	string Odometer::intToOdometer( int num )
	{
		char numToChar = ((int) startChar + (num - 10)) ;
		string charToString(1,numToChar);
		return charToString;
	}		
	
}