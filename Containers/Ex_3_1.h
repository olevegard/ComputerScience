#pragma once

#include <list>
#include <vector>
#include <iostream>

class Ex_3_1
{
	public:
	static void Ex_3_1_PrintLots( const std::list< int > &l, const std::vector<int> &vec )
	{
		auto p = l.begin();
		int32_t currentIndex = 0;

		for ( const auto &toFind : vec )
		{
			while ( currentIndex != toFind )
			{
				if ( currentIndex > toFind )
				{
					--p;
					--currentIndex;
				}
				else
				{
					++p;
					++currentIndex;
				}
			}

			std::cout << "Item in position : " << currentIndex << " is " << (*p) << std::endl;
		}
	}
	static void Solve()
	{
		std::list< int32_t > list;

		for ( int32_t i = 0; i < 20 ; ++i )
			list.push_back( rand() % 50 );

		std::cout << "Item list : " << std::endl;
		for ( const auto &p : list )
			std::cout << p << ", ";

		std::cout << std::endl << std::endl;;

		std::vector<int32_t> toFind { 0, 4, 9 , 15, 3, 9, 6 };

		std::cout << "To find list : " << std::endl;
		for ( const auto &p : toFind )
			std::cout << p << ", ";
		std::cout << std::endl << std::endl;;

		Ex_3_1_PrintLots( list, toFind );
	}
};
