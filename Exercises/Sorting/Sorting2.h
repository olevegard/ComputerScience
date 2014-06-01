#pragma once

class Sorting2
{
	public:
	Sorting2()
		:	elementCount( 5 )
		,	data( elementCount, 0 )
	{
		std::generate_n( std::begin( data ), elementCount, [](){ return rand() % 20; } );
		InsertionSort( );
	}
	void InsertionSort( )
	{
		std::vector< int32_t > numbers( data );

		std::cout << "======================================================== Insertion Sort ========================================================\n";
		for ( auto i : numbers )
			std::cout << i << std::endl;

		// Make sur element 0 -> firstUnsorted is sorted
		for ( auto firstUnsorted = 1 ; firstUnsorted < numbers.size() ; ++firstUnsorted )
		{
			int32_t previousNumber = firstUnsorted - 1;
			bool swapped = false;

			while ( numbers[previousNumber] > numbers[firstUnsorted] )
			{
				swapped = true;
				--previousNumber;

				if ( previousNumber < 0 )
					break;
			}

			if ( swapped )
			{
				numbers.insert( std::begin( numbers ) + ( previousNumber + 1 ), numbers[firstUnsorted] );
				numbers.erase( std::begin( numbers ) + firstUnsorted + 1 );
			}
		}

		for ( auto i : numbers )
			std::cout << i << std::endl;

		std::cout << "================================================================================================================================\n";
	}
	int32_t elementCount;
	std::vector< int32_t > data;
};
