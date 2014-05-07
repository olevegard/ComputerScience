#pragma once

#include "LinkedList.h"

template < typename Object >
class ConstIterator
{
	public:
		ConstIterator( )
			:	current( nullptr )
		{

		}
		const Object& operator* () const
		{
			return Retrieve();
		}

		ConstIterator operator++ ( int )
		{
			ConstIterator prev = *this;
			++(*this);

			return prev;
		}
		ConstIterator &operator++ ()
		{
			current = current->next;
			return *this;
		}

		bool operator==( const ConstIterator &other  )
		{
			return ( current == other.current );
		}
		bool operator!=( const ConstIterator *other )
		{
			return !( *this == other );
		}
	private:

	Object &Retrieve( ) const
	{
		return current->data;
	}
	/*
		ConstIterator( Node<Object>* p )
			:	current( p )
		{
		}
		*/

	Node< Object >* current;
	
	//friend class List<Object>;
};
