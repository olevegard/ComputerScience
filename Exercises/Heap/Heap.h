#pragma once

#include <vector> 

typedef std::pair< int32_t, int32_t > IntPair;

template < typename Type >
class Heap
{

	public:
	Heap()
	{
		Insert( 31 );

		Insert( 18 );//  1, parent is ( 1 - 1 ) / 2  = 0
		Insert( 21 );//  2, parent is ( 2 - 1 ) / 2  = 0

		Insert( 35 );//  3, parent is ( 3 - 1 ) / 2  = 1
		Insert( 10 );//  4, parent is ( 4 - 1 ) / 2  = 1

		Insert( 12 );//  5, parent is ( 5 - 1 ) / 2  = 2
		Insert( 1 ); //  6, parent is ( 6 - 1 ) / 2  = 2

		Insert( 3 ); //  7, parent is ( 7 - 1 ) / 2  = 3
		Insert( 2 ); //  8, parent is ( 8 - 1 ) / 2  = 3

		Insert( 8  );//  9, parent is (  9 - 1 ) / 2  = 4
		Insert( 28 );// 10, parent is (  9 - 1 ) / 2  = 4

		Insert( 100 );// 11, parent is ( 10 - 1 ) / 2  = 5
		Insert( 4 );  // 12, parent is ( 10 - 1 ) / 2  = 5
	}
	void Print()
	{
		Type level = 1;
		for ( int32_t i = 0; i < elements.size() ; ++i )
		{
			if ( i == level )
			{
				std::cout << "\n";
				level = ( level * 2 ) + 1;
			}

			std::cout << elements[ i ] << "\t";
		}
		std::cout << std::endl;
	}
	void Insert( Type value )
	{
		elements.push_back( value );
		PrelocateUp( elements.size() - 1 );
	}
	void PrelocateDown( int32_t index )
	{
		if ( index <= 0 || index >= ( elements.size() / 2) )
			return;

		IntPair children = ChildrenOf( index );

		int32_t maxChild = ( elements[ children.first ] > elements[ children.second ] )? children.first : children.second;

		if ( elements[ index ] < elements[maxChild] )
		{
			std::swap( elements[index], elements[maxChild] );
			PrelocateDown( maxChild );
		}
	}
	void PrelocateUp( int32_t index )
	{
		if ( index <= 0  )//|| index >= ( elements.size() / 2) )
			return;

		int32_t parent = ParentOf( index );

		if ( elements[ index ] > elements[parent] )
		{
			std::swap( elements[index], elements[parent] );
			PrelocateUp( parent );
		}
	}
	private:
	int32_t ParentOf( int32_t index )
	{
		return ( index - 1 ) / 2;
	}
	IntPair ChildrenOf( int32_t index )
	{
		IntPair intPair;
		intPair.first = ( index * 2 ) + 1;
		intPair.second = intPair.first + 1;

		return intPair;
	}
	
	std::vector< Type > elements;
};
