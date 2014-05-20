#pragma once

#include <vector> 

typedef std::pair< int32_t, int32_t > IntPair;
class Heap
{
	public:
	Heap()
	{
		Insert( 31 );

		Insert( 1 ); // 1, parent is ( 1 - 1 ) / 2  = 0
		Insert( 21 );// 2, parent is ( 2 - 1 ) / 2  = 0

		Insert( 5 ); // 3, parent is ( 3 - 1 ) / 2  = 1
		Insert( 10 );// 4, parent is ( 4 - 1 ) / 2  = 1

		Insert( 12 );// 5, parent is ( 5 - 1 ) / 2  = 2
		Insert( 18 );// 6, parent is ( 6 - 1 ) / 2  = 2

		Insert( 3 );// 7, parent is ( 7 - 1 ) / 2  = 3
		Insert( 2 );// 8, parent is ( 8 - 1 ) / 2  = 3

		Insert( 8 );//  9, parent is (  9 - 1 ) / 2  = 4
		Insert( 7 );// 10, parent is ( 10 - 1 ) / 2  = 4

	}
	void Print()
	{
		int level = 1;
		for ( int i = 0; i < elements.size() ; ++i )
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

	int ParentOf( int index )
	{
		return ( index - 1 ) / 2;
	}
	IntPair ChildrenOf( int index )
	{
		IntPair intPair;
		intPair.first = ( index * 2 ) + 1;
		intPair.second = intPair.first + 1;//( index * 2 ) + 1;

		return intPair;
	}

	void Insert( int value )
	{
		elements.push_back( value );
	}
	void PrelocateDown( int index )
	{
		std::cout << "===================================== Prelocate Down ( index " << index << " value " << elements[index] << ") =====================================\n";
		Print();

		if ( index <= 0 || index >= ( elements.size() / 2) )
		{
			std::cout << "Done!\n";
			return;
		}

		IntPair children = ChildrenOf( index );

		int32_t maxChild = ( elements[ children.first ] > elements[ children.second ] )? children.first : children.second;

		if ( elements[ index ] < elements[maxChild] )
		{
			std::cout << "Child is larger, change places!\n";
			std::swap( elements[index], elements[maxChild] );
			PrelocateDown( maxChild );
		}
		else
		{
			std::cout << "Child is not larger, do nothing!\n";
		}

	}

	
	std::vector< int > elements;
};
