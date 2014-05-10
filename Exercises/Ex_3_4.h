#pragma once

#include <iostream>
#include <list>
#include <algorithm>
#include "LinkedList/LinkedList.h"

class Ex_3_4
{
	public:
	static List< int32_t > Intersect( List< int32_t> &list1, List< int32_t>  &list2 )
	{
		List<int32_t > result;


		auto node1End = list1.End().GetNode()->next;
		auto node2End = list2.End().GetNode()->next;

		std::cout << "Original List 1\n";
		list1.Print();
		std::cout << "Original List 2\n";
		list2.Print();

		auto node1 = list1.Begin().GetNode();
		while ( node1 != node1End) 
		{
			bool found = false;

			auto node2 = list2.Begin().GetNode();
			while ( node2 != node2End) 
			{
				if ( node1->data == node2->data )
				{
					std::cout << "Found! "
						<< "\n\tData 1 : " << node1->data 
						<< "\n\tData 2 : " << node2->data
						<< "\n\tPtr 1 : " << node1
						<< "\n\tPtr 2 : " << node2
						<< std::endl;
					found = true;
					}

				node2 = node2->next;
			}

			if ( !found )
			{
				std::cout << "Adding : " << node1->data << std::endl;
				list2.PushBack( node1->data );
			}

			node1 = node1->next;
		}

		std::cout << "Copied List\n";
		list2.Print();
		return result;
	
	}
	static std::vector< int32_t > FindUnique( const std::list< int32_t > &l1, const std::list< int32_t > &l2)
	{
		std::vector< int32_t > l3;
		bool found = false;

		for ( const auto &i1 : l2 )
		{
			for ( const auto &i2 : l1 )
			{
				std::cout << "\tComparing " << i1 << " and " << i2 << std::endl;
				if ( i2 == i1 ) 
				{
					std::cout << "\t\tFound!\n";
					found = true;
					break;
				}
				if ( i2 > i1 )
				{
					break;
				}
			}

			if ( !found )
				std::cout << "\t" << i1 << " was not found\n";
			else
			{
				l3.push_back( i1 );
				found = false;
			}
		}
		for ( const auto &i : l3 )
			std::cout << i << ", ";

		std::cout << std::endl;

		return l3;
	}
	static void Solve()
	{
		std::list< int32_t > l1{ 0, 4, 6, 10, 15, 23, 37, 42 };
		std::list< int32_t > l2{ 0, 8, 8, 10, 19, 23, 42, 94 }; 

		Intersection1( l1, l2 );
		Intersection2( l1, l2 );
		Intersection3( l1, l2 );
		Intersection4( l1, l2 );
		FindUnique( l1, l2 );
	}
	private:
	static std::vector< int32_t > Intersection1( const std::list< int32_t > &l1, const std::list< int32_t > &l2)
	{
		std::vector< int32_t > l3;

		for ( const auto &i : l1 )
		{
			auto found = std::find( std::begin( l2 ), std::end( l2 ), i );

			if ( found != std::end( l2 ) )
				l3.push_back( i );
		}

		for ( const auto &i : l3 )
			std::cout << i << ", ";

			std::cout << std::endl;

		return l3;
	}
	static std::vector< int32_t > Intersection2( const std::list< int32_t > &l1, const std::list< int32_t > &l2)
	{
		std::vector< int32_t > l3;
		auto it1 = l1.begin();
		

		for ( ; it1 != std::end( l1 ) ; ++it1 )
		{
			for ( auto it2 = l2.begin(); it2 != std::end( l2 ) ; ++it2 )
			{
					if ( (*it1) == (*it2) )
					{
						l3.push_back( (*it2) );
						break;
					}
			}
		}

		for ( const auto &i : l3 )
			std::cout << i << ", ";

		std::cout << std::endl;

		return l3;
	}
	static std::vector< int32_t > Intersection3( const std::list< int32_t > &l1, const std::list< int32_t > &l2)
	{
		std::vector< int32_t > l3;
		auto it1 = l1.begin();

		for ( const auto &i1 : l1 )
		{
			for ( const auto &i2 : l2 )
			{
				if ( i1 == i2 )
				{
					l3.push_back( i1 );
					break;
				}
			}
		}

		for ( const auto &i : l3 )
			std::cout << i << ", ";

		std::cout << std::endl;

		return l3;
	}
	static std::vector< int32_t > Intersection4( const std::list< int32_t > &l1, const std::list< int32_t > &l2)
	{
		std::vector< int32_t > l3;

		std::set_intersection(
			std::begin( l1 ), std::end( l1 ),
			std::begin( l2 ), std::end( l2 ),
			std::back_inserter( l3 )
		);

		for ( const auto &i : l3 )
			std::cout << i << ", ";

		std::cout << std::endl;

		return l3;
	}
};

