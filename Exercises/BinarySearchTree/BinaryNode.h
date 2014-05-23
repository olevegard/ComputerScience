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

struct BinaryTriNode
{
	int32_t element;
	BinaryTriNode* leftChild;
	BinaryTriNode* rightChild;
	BinaryTriNode* parent;
	int32_t height;

	BinaryTriNode( int32_t value, BinaryTriNode* parent_, BinaryTriNode* leftChild_, BinaryTriNode* rightChild_ )
		:	element( value )
		,	leftChild( leftChild_ )
		,	rightChild( rightChild_ )
		,	parent( parent_ )
	{
	}
};

class BinaryTreeTester
{
	public:
	BinaryTreeTester()
	{
		root = new BinaryTriNode( 20, nullptr, nullptr, nullptr );
		Insert( 15 );
		Insert( 25 );
		Insert( 35 );
		Insert( 45 );
		Insert( 40 );
		Insert( 5 );
		Insert( 43 );
		Insert( 26 );

		InOrder( root );

	}
	void Insert( int32_t value )
	{
		BinaryTriNode* node = root;
		BinaryTriNode* prevNode = root;

		while ( node )
		{
			prevNode = node;
			if ( value < node->element )
				node = node->leftChild;
			else
				node = node->rightChild;
		}

		Insert( value, prevNode );
	}
	void Insert( int32_t value, BinaryTriNode* &node ) const
	{
		int32_t height = node->height + 1;

		if ( value < node->element )
		{
			node->leftChild = new BinaryTriNode( value, node,  nullptr, nullptr );
			node->leftChild->height = height;
		}
		else
		{
			node->rightChild = new BinaryTriNode( value, node, nullptr, nullptr );
			node->rightChild->height = height;
		}
	}
	void PostOrder( const BinaryTriNode* ndoe ) const
	{
		if ( node == nullptr )
			return;

		InOrder( node->leftChild );
		InOrder( node->rightChild );
		std::cout << node->element << std::endl;
	}
	void PostOrder_ParentPtr( const BinaryTriNode* ndoe ) const
	{
		if ( node == nullptr )
			return;

		InOrder( node->leftChild );
		InOrder( node->rightChild );
		std::cout << node->element << std::endl;
	}
	void InOrder( const BinaryTriNode* node ) const
	{
		if ( node == nullptr )
			return;

		InOrder( node->leftChild );
		std::cout << node->element << std::endl;
		InOrder( node->rightChild );
	}
	//std::vector< BinaryTriNode > nodes;
	BinaryTriNode* root;
};
