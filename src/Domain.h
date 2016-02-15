#ifndef DOMAIN_H
#define DOMAIN_H


#include <vector>
public class Domain
{	
	public:
		//Constructors
		Domain( int value );
		Domain( int[] values );
		Domain( vector< int > values );
		Domain( Domain d ); //Copy Constructor

		//Accessors
		vector<int> getValues( );
		bool contains( int value );
		bool isEmpty( );
		bool isModified( );
		int size();

		//Mutators
		bool remove( int value );
		void setModified( bool modified );

	private:
		vector< int > values = new vector< int >( );
		boolean modified;



};

#endif