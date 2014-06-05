#pragma once

class Sorting2
{
	public:
	Sorting2()
		:	elementCount( 100 )
		,	data( elementCount, 0 )
	{
		std::generate_n( std::begin( data ), elementCount, [](){ return rand() % 1000; } );

		std::cout << "======================================================== Insertion Sort ========================================================\n";
		InsertionSort( );

		std::cout << "======================================================== Shell Sort ========================================================\n";
		ShellSort();

		std::cout << "======================================================== Merge Sort ========================================================\n";
		MergeSort();
	}
	void InsertionSort( )
	{
		std::vector< int32_t > numbers( data );

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

		std::cout << "Sorted? " << std::boolalpha << std::is_sorted( numbers.begin(), numbers.end() ) << std::endl;
	}
	// Sort all itesms with an index of a given intrval. When all itms with this interval is in sorted order, do a new, lowr interval
	// Example : 81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15
	// Interval 5
	// 		Sort all items with 5 interval starting at 0 to 4
	// 			0	: 81, 35, 41	= 35, 41, 81
	// 			1	: 94, 17, 75	= 17, 75, 94
	// 			2	: 11, 95, 15	= 11, 15, 95
	// 			3	: 96, 28		= 28, 96
	// 			4	: 12, 58		= 12, 58
	// 		Sort all items with 3 as an intervall
	// 			.......
	// 		Continu until you rach 1 as an interval
	
	void ShellSort()
	{
		std::vector< int32_t > numbers( data );
		std::stack< int32_t > increments = CreateIncrementsStack( numbers.size() );

		int32_t first = 1;

		// For each iteration, do SortElementsWithInterval() for all values of first below the interval
		while ( !increments.empty() )
		{
			SortElementsWithInterval( numbers, first, increments.top() );
			first++;

			if ( first == increments.top() )
			{
				increments.pop();
				first = 0;
			}
		}
		std::cout << "Sorted? " << std::boolalpha << std::is_sorted( numbers.begin(), numbers.end() ) << std::endl;
	}
	void MergeSort()
	{
		std::vector< int32_t > allElements( 10  );
		std::vector< int32_t > list1;
		std::vector< int32_t > list2;

		std::generate_n( std::begin( allElements ), 10, [](){ return rand() % 1000; } );

		SplitListInHalf( allElements, list1, list2 );

		std::cout << "==================================== Original List==================================\n";
		for ( const auto &p : allElements )
			std::cout << p << std::endl;

		std::cout << "==================================== List 1 ==================================\n";
		for ( const auto &p : list1 )
			std::cout << p << std::endl;

		std::cout << "==================================== List 1 ==================================\n";
		for ( const auto &p : list2 )
			std::cout << p << std::endl;

		//MergeLists( list1, list2 );
	}
	private:
	void SplitListInHalf( std::vector< int32_t > &input, std::vector< int32_t > &list1, std::vector< int32_t > &list2 )
	{
		std::move(
			input.begin(),
			input.begin() + input.size() / 2,
			std::back_inserter ( list1 )
		);

		std::move(
			input.begin() + input.size() / 2,
			input.end(),
			std::back_inserter ( list2 )
		);
	}
	std::vector< int32_t > MergeLists( std::vector< int32_t > list1, std::vector< int32_t > list2 )
	{
		std::vector< int32_t > mergedList;
		//mergedList.reserve( elementCount * 2 );
		mergedList.reserve( 2 );

		while ( !list1.empty() || !list2.empty() )
		{
			if ( list1.empty() )
			{
				mergedList.push_back( list2[0] );
				list2.erase( std::begin( list2 ) );
				continue;
			}

			if ( list2.empty() )
			{
				mergedList.push_back( list1[0] );
				list1.erase( std::begin( list1 ) );
				continue;
			}

			if ( list1[0] < list2[0] )
			{
				mergedList.push_back( list1[0] );
				list1.erase( std::begin( list1 ) );
			}
			else
			{
				mergedList.push_back( list2[0] );
				list2.erase( std::begin( list2 ) );
			}
		}

		std::cout << "Merged list\n";
		for ( const auto &p : mergedList )
			std::cout << p << ", ";
		std::cout << std::endl;

		std::cout << "Merged list size " << mergedList.size() << " list 1 size " << list1.size() << " list 2 size " << list2.size() << std::endl;

		return mergedList;
	}
	std::stack< int32_t > CreateIncrementsStack( int32_t sizeOfInput )
	{
		int32_t halfSize = sizeOfInput * 0.5;
		std::stack< int32_t > increments;

		for ( int32_t increment = 2; ( increment - 1 ) <= ( halfSize ); increment *= 2 )
		{
			increments.push( ( increment - 1 ) );
		}

		return increments;
	}
	void SortElementsWithInterval( std::vector< int32_t > &numbers, int32_t start, int32_t interval )
	{
		bool swap = true;

		while ( swap )
		{
			int32_t first = start;
			int32_t second = start + interval;
			swap = false;

			while ( second < numbers.size() )
			{
				if ( numbers[first] > numbers[second] )
				{
					std::swap( numbers[first], numbers[second] );
					swap = true;
				}

				first += interval;
				second += interval;
			}
		}
	}
	int32_t elementCount;
	std::vector< int32_t > data;
	std::vector< std::vector< int32_t > > sortedArrays;
};
