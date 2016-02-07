// Tools.cpp

#include"Tools.h"
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<time.h>
using namespace std;

namespace tools
{
	const string WHITESPACE = " \t\n\r";

	char getChar ( string prompt )
	{
		do
		{
			cout << prompt;

			char userAnswer;
			cin >> userAnswer;
			flushInput();

			if ( !cin.fail() )
				return userAnswer;

			cin.clear();
			flushInput();
			cout << "[Input Format Error] Please enter one character." << endl;

		} while ( true );
	}

	char getCharInString( string prompt, string chars )
	{
		do
		{
			char userAnswer = getChar( prompt );

			if ( string::npos != chars.find( userAnswer ) )
				return userAnswer;

			cout << "[Input Format Error] Please enter a character from within \"" << chars << "\"" << endl;

		} while ( true );
	}

	bool getBool ( string prompt )
	{
		do
		{
			switch ( getChar(prompt) )
			{
			case 'y':
			case 'Y':
				return true;
			case 'n':
			case 'N':
				return false;
			}

			cout << "[Input Format Error] Please enter y or n." << endl;

		} while ( true );
	}
	
	int getInt ( string prompt )
	{
		do
		{
			cout << prompt;

			int userAnswer;
			cin >> userAnswer;
			flushInput();

			if ( !cin.fail() )
				return userAnswer;

			cin.clear();
			flushInput();
			cout << "[Input Format Error] Please enter an integer." << endl;

		} while ( true );
	}

	int getBoundedInt ( string prompt, int lowerBound, int upperBound, string errorMessage )
	{
		do
		{
			cout << prompt;

			int userAnswer;
			cin >> userAnswer;
			flushInput();

			if ( !cin.fail() )
				if ( userAnswer >= lowerBound && userAnswer <= upperBound )
					return userAnswer;

			cin.clear();
			flushInput();

			if ( errorMessage != "" ) 
				cout << errorMessage << endl;
			else
				cout << "[Input Format Error] Please enter an integer from "
					 << lowerBound 
					 << " to "
					 << upperBound
					 << "."
					 << endl;

		} while ( true );
	}

	int getNonNegativeInt ( string prompt )
	{
		return getBoundedInt( prompt, 0, INT_MAX, "[Input Format Error] Please enter a nonnegative integer." );
	}
	
	int getPositiveInt ( string prompt )
	{
		return getBoundedInt( prompt, 1, INT_MAX, "[Input Format Error] Please enter a positive integer." );
	}

	int getPercent ( string prompt )
	{
		return getBoundedInt( prompt, 0, 100 );
	}

	float getFloat ( string prompt )
	{
		do
		{
			cout << prompt;

			float userAnswer;
			cin >> userAnswer;
			flushInput();

			if ( !cin.fail() )
				return userAnswer;

			cin.clear();
			flushInput();
			cout << "[Input Format Error] Please enter a real number." << endl;

		} while ( true );
	}

	string getLine (string prompt)
	{
		do
		{
			cout << prompt;

			string userAnswer;
			getline( cin, userAnswer );

			if ( !cin.fail() )
				return userAnswer;

			cin.clear();
			flushInput();
			cout << "[Input Format Error] Please try again." << endl;

		} while ( true );
	}

	void pause ( std::string prompt, std::ostream &outStream, std::istream &inStream )
	{
		outStream << prompt;
		inStream.ignore( 999, '\n');
	}

	void flushInput ( istream &inStream )
	{
		inStream.ignore( 999, '\n' );
	}
	
	void blankLine ( int numOfLines, ostream &outStream )
	{
		outStream << string(numOfLines, '/n');
	}

	void clearScreen ( std::ostream &outStream )
	{
		blankLine(50, outStream);
	}

	char toLower ( char c )
	{
		return ( c >= 'A' && c <='Z' )
					? c - 'A' + 'a'
					: c;
	}

	string toLower ( string s )
	{
		for ( string::size_type index = 0 ; index < s.size() ; ++index )
			s[index] = toLower(s[index]);
		return s;
	}

	bool isIn ( std::string pattern, std::string source )
	{
		return std::string::npos != source.find(pattern);
	}

	bool isInCaseless ( std::string pattern, std::string source )
	{
		return isIn( toLower(pattern), toLower(source) );
	}

	bool isEmpty ( std::string s )
	{
		return std::string::npos == s.find_first_not_of( WHITESPACE );
	}

	bool isEmpty ( char c )
	{
		return std::string::npos != WHITESPACE.find(c);
	}

	string chomp ( string s )
	{
		while ( s.length() > 0 && isEmpty(s[0]) )
			s.erase(0,1);
		while ( s.length() > 0 && isEmpty(s[s.length()-1]) )
			s.erase(s.length()-1,1);
		return s;
	}

	string substitute ( string source, string pattern, string replacement )
	{
		string::size_type location = source.find(pattern);
		return ( location == string::npos )
				? source
				: ( source.substr(0,location)
					+ replacement
					+ source.substr( location+pattern.length(), source.length()-location) );
	}

	string repeatChar ( char c, int length )
	{
		string result;
		while (--length >= 0)
			result += c;
		return result;
	}

	string pluralize ( int count, string singular, string plural )
	{
		return (count == 1) ? singular : plural;
	}

	int numberWidth ( int number )
	{
		if ( number = 0 )
			return 1;

		int outputCharacterCount = 0;

		if ( number < 0 )
		{
			++outputCharacterCount;
			number = -number;
		}
	
		for ( int digits = number ; digits > 0 ; digits /= 10 )
			++outputCharacterCount;

		return outputCharacterCount; 
	}

	int randomInt( int lowerBound, int upperBound )
	{
		static bool initialized = false;
		if ( !initialized )
		{
			typedef unsigned int uint;
			srand(uint(time(0)));
			initialized = true;
			rand();
		}
		return int(lowerBound + (1 + upperBound - lowerBound) * (rand() / (RAND_MAX + 1.0f)));
	}

}