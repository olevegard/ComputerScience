#pragma once

#include "Vector.h"

template < typename Object >
class Iterator
{
	public:
		Iterator( )
			:	Iterator( nullptr )
		{

		}
		Iterator( Node<Object>* p )
			:	current( p )
		{
		}
		const Object& operator* () const
		{
			return Retrieve();
		}

		Iterator operator++ ( int )
		{
			Iterator prev = *this;
			++(*this);

			return prev;
		}
		Iterator &operator++ ()
		{
			current = current->next;
			return *this;
		}

		Iterator &operator-- ()
		{
			current = current->prev;
			return *this;
		}

		bool operator==( const Iterator &other  )
		{
			return ( current == other.current );
		}
		bool operator!=( const Iterator &other )
		{
			return !( *this == other );
		}

		Node< Object >* GetNode()
		{
			return current;
		}
	private:

	Object &Retrieve( ) const
	{
		return current->data;
	}
	/*
		
		*/
	int32_t 
	Object* current;
	
	//friend class List<Object>;
};
