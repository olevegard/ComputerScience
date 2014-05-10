#pragma once

#include <iostream>
#include <list>
#include <algorithm>

#include "LinkedList/LinkedList.h"

class Ex_3_5
{
	public:
	static void Union( List< int32_t > &list1, List< int32_t > &list2 )
	{
		List< int32_t > result;

		auto node1    = list1.Begin().GetNode();
		auto node1End = list1.End().GetNode();

		while ( node1 != node1End )
		{
			if ( CheckUnion( list2, result, node1->data ) )
				result.PushBack( node1->data );

			node1 = node1->next;
		}

		result.Print();
	}
	static bool CheckUnion( const List< int32_t > &list, List< int32_t > &foundUnions,  int32_t number )
	{
		auto node  = list.Begin().GetNode();
		auto nodeEnd  = list.End().GetNode();

		while ( node != nodeEnd )
		{
			if ( number == node->data )
			{
				if ( !IsNumInList( node->data, foundUnions) )
					return true;
				else
					return false;
			}
			node = node->next;
		}

		return false;
	}
	static bool IsNumInList( int32_t num, const List< int32_t > &list )
	{
		auto node = list.Begin().GetNode();
		bool numFound = false;

		while ( node != list.End().GetNode()->next )
		{
			if (  node->data == num )
			{
				numFound = true;
				break;
			}

			node = node->next;
		}

		return numFound;
	}

	static std::vector< int32_t > FindUnique1( const std::list< int32_t > &l1, const std::list< int32_t > &l2)
	{
		std::vector< int32_t > l3;
		bool found = false;

		std::copy( std::begin( l1 ), std::end( l1 ), std::back_inserter( l3 ) );

		int32_t i = 0;
		for ( const auto &i1 : l2 )
		{

			auto i2 = std::begin( l1 );
			for ( ; i2 != std::end( l1 ) ; ++i2 )
			{
				std::cout << "Comparing " << (*i2) << " and " << i1 << std::endl;
				if ( (*i2) == i1 ) 
				{
					std::cout << "\tFound!\n";
					found = true;
					break;
				}
				//if ( i1 < (*i2) ) break;
			}
			//std::cin.ignore();
			if ( !found && i2 != std::end( l2 )  )
				//l3.push_back( i1 );
				l3.insert( std::begin( l3 ) + i + 1, i1 );
			//l3.insert( std::begin( l3 ) + i - 2, i1 );
			else
				found = false;

			++i;
		}
		//std::sort( std::begin( l3 ), std::end( l3 ) );
		//std::sort( std::begin( l3 ), std::end( l3 ) );
		/*
		   for ( const auto &i2 : l1 )
		   {
		   if ( i2 == i1 ) 
		   {
		   found = true;
		   break;
		   }
		   if ( i2 > i1 )
		   break;
		   }

		   if ( !found )
		   l3.push_back( i1 );
		   else
		   {
		//l3.push_back( i1 );
		found = false;
		}
		*/

		for ( const auto &i : l2 )
			std::cout << i << ", ";

		std::cout << std::endl;

		for ( const auto &i : l3 )
			std::cout << i << ", ";

		std::cout << std::endl;

		return l3;
	}
	static std::vector< int32_t > FindUnique2( const std::list< int32_t > &l1, const std::list< int32_t > &l2)
	{
		std::vector< int32_t > l3;

		std::set_union( std::begin( l1 ), std::end( l1 ), std::begin( l2 ), std::end( l2 ), std::back_inserter( l3 ) );

		for ( const auto &i : l3 )
			std::cout << i << ", ";

		std::cout << std::endl;

		return l3;
	}
	static void Solve()
	{
		std::list< int32_t > l1{ 0, 4, 6, 10, 15, 23, 37, 42 };
		std::list< int32_t > l2{ 0, 8, 8, 10, 19, 23,     42, 94 }; 

		FindUnique1( l1, l2 );
		FindUnique2( l1, l2 );
	}
};
