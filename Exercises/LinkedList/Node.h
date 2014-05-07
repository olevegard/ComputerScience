#pragma once

template < typename Object >
struct Node
{
	Object data;
	Node* next;
	Node* prev;

	Node( const Object &data_, Node* prev_, Node* next_ )
		:	data( data_ )
		,	prev( prev_ )
		,	next( next_ )
	{
	}
};
