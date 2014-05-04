#pragma once

#include <iostream>

class Sorting
{
	public:
		static int BubbleSort( std::vector<int> &numbers, bool print )
		{
			if ( print )
			{
				std::cout << "======================================================================================================================================\n";
				PrintVector( numbers );
			}

			bool sorted = false;

			while ( !sorted )
			{
				sorted = true;

				for ( int i = 0 ; i < numbers.size() - 1 ; ++i )
				{
					if ( numbers[i] > numbers[ i + 1] )
					{
						std::swap( numbers[i], numbers[i + 1] );
						sorted = false;
					}
				}
			}

			if ( print )
			{
				PrintVector( numbers );
				std::cout << "======================================================================================================================================\n";
			}

			return 0;
		}
		static void BubbleSortRecursive( std::vector<int> &numbers)
		{
			bool sorted = true;

			for ( int i = 0 ; i < numbers.size() - 1 ; ++i )
			{
				if ( numbers[i] > numbers[ i + 1] )
				{
					std::swap( numbers[i], numbers[i + 1] );
					sorted = false;
				}
			}

			if ( !sorted )
			{
				BubbleSortRecursive( numbers );
				return;
			}

			PrintVector( numbers );
			std::cout << "======================================================================================================================================\n";
		}
		static void PrintVector( const std::vector< int > &vec )
		{
			for ( const auto i : vec )
				std::cout << i << ", ";
			std::cout << std::endl;
		}
};
