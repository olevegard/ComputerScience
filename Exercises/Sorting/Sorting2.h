// Sorting - Ole Vegard Mythe Moland
// A class to show off a few sorting algorithms
// Note : These implementations are designed to be intuitive rather than optimized!

#pragma once

#include <deque>
#include <iomanip>

class Sorting2
{
	typedef std::pair< std::vector< int32_t >, std::vector< int32_t > > VecPair;

	public:
	Sorting2()
		:	elementCount( 32 )
		,	data( elementCount, 0 )
	{
		int32_t seed = time( 0 );
		std::cout << "Seed is " << seed << std::endl;
		srand( seed );
		std::generate_n( std::begin( data ), elementCount, [](){ return rand() % 100; } );

		std::cout << "======================================================== Insertion Sort ========================================================\n";
		InsertionSort( );

		std::cout << "======================================================== Shell Sort ========================================================\n";
		ShellSort();

		std::cout << "======================================================== Merge Sort ========================================================\n";
		MergeSort();

		std::cout << "======================================================== Quick Sort ========================================================\n";
		QuickSort();
	}
	void InsertionSort( )
	{
		std::deque< int32_t > numbers( data );

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
		std::deque< int32_t > numbers( data );
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
	// 1. Move all elements into list
	// 2. Merge all the list so that the resulting list is sorted
	// 3. Take the resulting lists and merge them together
	// 4. Repeat step 3
	//
	//	The size of the lists will be 1 in the first pass ( since all elements are unsorted )
	//	The secon time the lists of size one will habe been merged int lists of size two
	//	The third time the lists will be of size 4, then 8, then 16, etx...
	//
	// 	Mergin two list will run in O( n ) time since the lists are sorted
	void MergeSort()
	{
		std::deque< int32_t > allElements( data );

		int32_t seriesLength = 1;
		while ( seriesLength < allElements.size() )
		{
			std::deque< VecPair > result;

			for ( int32_t i = 0 ;( i * seriesLength * 2 ) < allElements.size(); ++i )
				result.push_back( SplitIntoNewLists( allElements, i, seriesLength ) );

			// Merge and add elements to allElements
			AddPairsToVector( result, allElements );

			seriesLength *= 2;
		}
	}
	void QuickSort( )
	{
		std::deque< int32_t > allElements( data );
		//int32_t pivot = 1;//allElements.size() / 2 ;
		int32_t pivot = allElements.size() / 2 ;


		int32_t wall = 0;

		std::cout << "Pivot is " << allElements[ pivot ] << " which has the index " << pivot << std::endl;
		PrintWithWall( allElements, wall, pivot );
		std::cout << "\n========================================================\n";

		QuickSort( allElements, wall, pivot, allElements.size() );

/*
		std::deque< int32_t > preWall;
		std::move( allElements.begin(), allElements.begin() + wall, std::back_inserter( preWall ) );
		allElements.erase( allElements.begin(), allElements.begin() + wall ); 
		//std::swap_ranges( allElements.begin(), allElements.begin() + wall, std::back_inserter( preWall ) );

		PrintWithWall( preWall, 1000 );
		PrintWithWall( allElements, 1000 );
		*/
	}
	private:
	void QuickSort( std::deque< int32_t > &input, int32_t &wall, int32_t &pivot, int32_t end  )
	{
		for ( int32_t i = 0 ; i < end; ++i )
		{
			if ( input[i] < input[pivot] && i != pivot )
			{
				std::cout << std::setw( 2 ) << input[i] << " is smaller than pivot "
					<< input[pivot]    << " [ " << pivot << " ], swapping "
					<< std::setw( 2 ) << input[i]    << " [ " << std::setw( 2 ) << i     << " ] with "
					<< std::setw( 2 ) << input[wall] << " [ " << std::setw( 2 ) << wall  << " ]\n";
				std::swap ( input[i], input[wall] );
				++wall;
				if ( wall > pivot )
					pivot = i;
			}
		}
		std::cout << "======================================================================\n";
		PrintWithWall( input, wall, pivot );
		std::cout << "\n";
		std::swap( input[wall], input[pivot] );
		pivot = wall;
		PrintWithWall( input, wall, pivot );

		std::cin.ignore();
	}
	
	void PrintWithWall( const std::deque< int32_t > &input, int32_t wall, int32_t pivot )
	{
		for ( int32_t j = 0 ; j < input.size() ; ++j )
		{
			if ( j == wall )
				std::cout << "| ";
			if ( j == pivot )
				std::cout << "{";
				
			std::cout << input[ j ];

			if ( j == pivot )
				std::cout << "}";

			std::cout << " ";
		}
	}
	VecPair SplitIntoNewLists( const std::deque< int32_t > &input, int32_t index, int32_t seriesLength )
	{
		int32_t seriesStart = index * ( seriesLength * 2 );

		VecPair pair;

		if ( seriesStart + seriesLength >= input.size()  )
		{
			std::copy( input.begin() + seriesStart, input.end(), std::back_inserter( pair.first ) );

			return pair;
		}
		std::copy( input.begin() + seriesStart, input.begin() + seriesStart + seriesLength, std::back_inserter( pair.first ) );

		if ( ( seriesStart + ( seriesLength* 2 ) ) > input.size()  )
		{
			std::copy( input.begin() + seriesStart + seriesLength, input.end(), std::back_inserter( pair.second ) );

			return pair;
		}

		std::copy( input.begin() + seriesStart + seriesLength, input.begin() + seriesStart + ( seriesLength * 2 ), std::back_inserter( pair.second ) );

		return pair;
	}
	void PrintPairs( const std::deque< VecPair > &result )
	{
		std::cout << "=================================== Sorted Pairs ===================================\n";

		for ( const auto &pair : result )
		{
			std::cout << "\tList first\n\t\t";
			for ( const auto &i : pair.first )
				std::cout << i << ", ";
			std::cout << std::endl;

			std::cout << "\tList second\n\t\t";
			for ( const auto &i : pair.second )
				std::cout << i << ", ";
			std::cout << std::endl;

			std::cout << "====================================================================================\n";
		}
	}
	void AddPairsToVector( const std::deque< VecPair > &result, std::deque< int32_t > &allElements )
	{
		allElements.clear();

		for ( const auto &pair : result )
			AddToVector( MergeLists( pair.first, pair.second ), allElements );
	}
	void AddToVector( const std::vector< int32_t > &input, std::deque< int32_t > &output )
	{
		for ( const auto &i : input )
			output.push_back( i );
	}
	VecPair SplitListInHalf( std::vector< int32_t > &input )
	{
		VecPair output;

		std::move(
				input.begin(),
				input.begin() + input.size() / 2,
				std::back_inserter ( output.first )
				);

		std::move(
				input.begin() + input.size() / 2,
				input.end(),
				std::back_inserter ( output.second )
				);

		return output;
	}
	std::vector< int32_t > MergeLists( std::vector< int32_t > list1, std::vector< int32_t > list2 )
	{
		std::vector< int32_t > mergedList;
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
	void SortElementsWithInterval( std::deque< int32_t > &numbers, int32_t start, int32_t interval )
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
	std::deque< int32_t > data;
	std::vector< std::deque< int32_t > > sortedArrays;
};
