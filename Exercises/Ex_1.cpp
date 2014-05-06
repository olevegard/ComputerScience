#include <vector>
#include <iostream>
#include <cstdlib>

#include "Sorting.h"

void SortTest();

int FindKthLargest( const std::vector<int> &list, int k )
{
	if ( ( k - 1 ) < list.size() && k > 0 )
		return list[ k - 1 ];
	else
		return -1;
}
int main()
{
	srand(time(NULL));

	SortTest();
}
void SortTest()
{
	std::vector< int > toSort;

	for ( int i = 0 ; i < 30 ; ++i )
		toSort.push_back( rand() % 100 );

	//BubbleSort( toSort, true );

	Sorting::BubbleSortRecursive( toSort );

	std::cout << 99 << ". largest is " <<  FindKthLargest( toSort, 99 ) << std::endl;;
}


/*
   for ( int j = i + i ; j < numbers.size() ; ++j )
   {
   if ( numbers[i] > numbers[j] )
   {
   std::cout << "\tSwapping " << i << " and " << j << std::endl;
   std::cout << "\t\tBefore " << numbers[i] << " and " << numbers[j] << std::endl;
   int temp = numbers[i];
   numbers[i] = numbers[j];
   numbers[j] = temp;
   std::cout << "\t\tAfter " << numbers[i] << " and " << numbers[j] << std::endl;
   sorted = false;
   }
   }

*/
