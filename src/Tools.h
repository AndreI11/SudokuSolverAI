// Tools.h

#include<string>
#include<sstream>
#include<iostream>

#ifndef TOOLS_LOCK
#define TOOLS_LOCK

namespace tools
{
	// ================= BASIC CONSTS ======================

	extern	const	std::string	WHITESPACE;

	// ================= GET FUNCTIONS =====================

	char		getChar				( std::string prompt );
	char		getCharInString		( std::string prompt, std::string chars );
	bool		getBool				( std::string prompt );
	int			getInt				( std::string prompt );
	int			getBoundedInt		( std::string prompt,	int lowerBound,	int upperBound,	std::string errorMessage = "" );
	int			getNonNegativeInt	( std::string prompt );
	int			getPositiveInt		( std::string prompt );
	int			getPercent			( std::string prompt );
	float		getFloat			( std::string prompt );
	std::string	getLine				( std::string prompt );

	template <class T>
	T getValue ( std::string prompt )
	{
		do
		{
			cout << prompt;

			T userAnswer;
			cin >> userAnswer;
			flushInput();

			if ( !cin.fail() )
				return userAnswer;

			cin.clear();
			flushInput();
			cout << "Format error: Try Again." << endl;

		} while (true);
	}
	
	// =============== STREAM FUNCTIONS ====================
	
	void	pause		( std::string prompt = "Press ENTER to continue...", std::ostream &outStream = std::cout, std::istream &inStream = std::cin );
	void	flushInput	( std::istream &inStream = std::cin );
	void	blankLine	( int numOfLines = 1, std::ostream &outStream = std::cout );
	void	clearScreen	( std::ostream &outStream = std::cout );

	template<class T>
	void openFStream ( T &fStream, std::string prompt )
	{
		while (true)
		{
			fStream.open(getLine(prompt));
			if (!fStream.fail() ) return;
			std::cout << "open failed, try again" << endl;
			fStream.clear();
		}
	}
	
	// =============== STRING FUNCTIONS ====================
	
	char		toLower( char c );
	std::string	toLower( std::string s );

	bool		isIn			( std::string pattern, std::string source );
	bool		isInCaseless	( std::string pattern, std::string source );
	bool		isEmpty			( std::string s );
	bool		isEmpty			( char c );

	std::string	chomp		( std::string s );
	std::string	substitute	( std::string source, std::string pattern, std::string replacement );
	std::string	repeatChar	( char c, int length );
	std::string	pluralize	( int count, std::string singular, std::string plural );
	
	// =============== CASTING FUNCTIONS ===================

	template<class T>
	std::string toString ( T object )
	{
		ostringstream ss;
		ss << object;
		return ss.str();
	}

	// ================ MISC FUNCTIONS =====================

	int	numberWidth	( int number );
	int	randomInt	( int lowerbound, int upperBound );
	
	template<class T>
	void swap ( T &a, T &b )
	{
		T temp = a;
		a = b;
		b = temp;
	}

	template<class T>
	T &min ( T &left, T &right )
	{
		return ( left < right ) ? left : right;
	}

	template<class T>
	const T &min_const( const T &left, const T &right )
	{
		return ( left < right ) ? left : right;
	}

	template<class T>
	T &max ( T &left, T &right )
	{
		return ( left < right ) ? right : left;
	}

	template<class T>
	const T &max_const( const T &left, const T &right )
	{
		return ( left < right ) ? right : left;
	}

}

#endif