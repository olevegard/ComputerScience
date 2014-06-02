#pragma once

class Sorting2
{
	public:
	Sorting2()
		:	elementCount( 9 )
		,	data( elementCount, 0 )
	{
		std::generate_n( std::begin( data ), elementCount, [](){ return rand() % 15; } );

		//InsertionSort( );
		ShellSort();
	}
	void InsertionSort( )
	{
		std::vector< int32_t > numbers( data );
		std::cout << "======================================================== Insertion Sort ========================================================\n";

		// Make sur element 0 -> firstUnsorted is sorted
		for ( auto firstUnsorted = 1 ; firstUnsorted < numbers.size() ; ++firstUnsorted )
		{
			int32_t previousNumber = firstUnsorted - 1;
			bool swapped = false;

			while ( numbers[firstUnsorted] < numbers[previousNumber] )
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
	}
	void ShellSort()
	{
		std::vector< int32_t > numbers( data );
		//std::vector< int32_t > numbers( { 81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15 });
		std::queue< int32_t > increments = CreateIncrementsQueue( numbers.size() );
		std::cout << "======================================================== Shell Sort ========================================================\n";

		int32_t first = 0;
		int32_t interval = increments.front();
		increments.pop();

		while ( interval > 0 )
		{
			SortElementsWithInterval( numbers, first, interval );
			first++;

			if ( first == interval )
			{
				interval = increments.front();
				increments.pop();
				first = 0;
			}
		}

		for ( int32_t first = 0; first < numbers.size() ; ++first  )
		{
			std::cout << first << ". " << numbers[first] << "\n";
		}
	}
	std::queue< int32_t > CreateIncrementsQueue( int32_t sizeOfInput )
	{
		int32_t halfSize = sizeOfInput * 0.5;
		int32_t increment = 1;
		std::queue< int32_t > increments;

		for ( int32_t first = 0; first < halfSize ; ++first  )
		{
			if ( increment < ( halfSize ) )
			{
				increments.push( increment );
				increment *= 2;
			}
			else
				break;
		}

		return increments;
	}


	void SortElementsWithInterval( std::vector< int32_t > &numbers, int32_t start, int32_t interval )
	{
		std::cout << "Sort elements from " << start << " interval : " << interval << std::endl;
		bool swap = true;

		while ( swap )
		{
			int32_t first = start;
			int32_t second = start + interval;
			swap = false;

			while ( second < numbers.size() )
			{
				//std::cout << "\tChecking : " << numbers[first] << " and " << numbers[second] << std::endl;
				if ( numbers[first] > numbers[second] )
				{
					std::swap( numbers[first], numbers[second] );
					//std::cout << "\tSwapped : " << numbers[first] << " and " << numbers[second] << std::endl;
					swap = true;
				}

				first += interval;
				second += interval;
			}
		}
	}

	int32_t elementCount;
	std::vector< int32_t > data;
};
