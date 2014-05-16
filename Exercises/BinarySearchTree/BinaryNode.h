#pragma once

template < typename Comparable >
struct BinaryNode
{
	Comparable element;
	BinaryNode *leftChild;
	BinaryNode *rightChild;
	int32_t height;

	BinaryNode( Comparable value, BinaryNode* leftChild_, BinaryNode* rightChild_ )
		:	element( value )
		,	leftChild( leftChild_ )
		,	rightChild( rightChild_ )
	{

	}
};
