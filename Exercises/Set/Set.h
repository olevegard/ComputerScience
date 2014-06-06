#pragma once

#include <vector>

struct SetItem
{
	SetItem( int32_t className_ )
		:	className( className_ )
		,	parent ( this )
	{
	}
	void SetParent( SetItem* item )
	{
		parent = item;
	}
	int32_t className;
	SetItem* parent;
};
class Set
{
	public:
		Set()
		{
			Insert( 0 );
			Insert( 1 );
			Insert( 2 );
			Insert( 3 );
			Insert( 4 );
			Insert( 5 );
			Insert( 6 );
			Insert( 7 );


			Union( 2, 3 );

			std::cout << "\nUnion 2, 3" << std::endl;
			PrintSet();

			std::cout << std::endl;

			Union( 4, 6 );
			Union( 5, 6 );

			std::cout << "\nUnion 4, 6 and 5, 6" << std::endl;
			PrintSet();

			Union( 3, 4 );
			std::cout << "\nUnion 3, 4 6" << std::endl;
			PrintSet();
		}
		void Union( int32_t source, int32_t destination )
		{
			setList[ source ].parent = &setList[ destination ];
		}
		void Insert( int32_t className )
		{
			setList.emplace_back( SetItem( setList.size() ) );
			setList.back().SetParent( &setList.back() );
		}
		int32_t FindParentClassName( SetItem* item )
		{
			SetItem* current = item->parent;

			while ( current->parent != current )
				current = current->parent;

			return current->parent->className;
		}
		void PrintSet()
		{
			for ( int32_t i = 0 ; i < setList.size() ; ++i )
			{
				std::cout << i << " is in set " << FindParentClassName( &setList[i] ) << std::endl;
			}
		}
		void PrintItemsInClass( int32_t className )
		{
			std::cout << "In class " << className << " :\n\t";
			for ( int32_t i = 0 ; i < setList.size() ; ++i )
			{
				if ( setList[i].className == className )
					std::cout << i << ", ";
			}
			std::cout << std::endl;
		}
	private:
		std::vector< SetItem > setList;
};
