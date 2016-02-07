#ifndef ODOMETER_H
#define ODOMETER_H

#include <map>
#include <string>

using namespace std;
namespace sudoku_namespace
{
	class Odometer{

		public:
			//Constructor
			Odometer( void );

			//Method functions
			int odometerToInt( string value );
			string intToOdometer( int num );
			void populateTokensAZ();

		private:
			map<string,int> tokenMap;
			char startChar;
			char endChar;
	};
}
#endif