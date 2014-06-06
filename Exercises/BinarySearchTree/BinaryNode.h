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
		root = new BinaryTriNode( 50, nullptr, nullptr, nullptr );
		Insert( 25 );
		Insert( 12 );

		Insert( 37 );
		Insert( 33 );
		Insert( 43 );

		Insert( 80 );
		Insert( 100 );
		Insert( 90 );

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
	void Print()
	{
		BreadthFirstSearch( );
		std::cout << "================================ Post Order Child Ptrs ================================\n";
		PostOrder( root );
		std::cout << "================================ Post Order Non Recursion ================================\n";
		PostOrder2( root );
		std::cout << "================================ Post Order Parent Ptr ================================\n";
		PostOrder_ParentPtr( root );
	}
	void PostOrder( const BinaryTriNode* node ) const
	{
		if ( node == nullptr )
			return;

		// Push all available left children onto stac
		PostOrder( node->leftChild );
		// Take last node and add
		PostOrder( node->rightChild );
		std::cout << node->element << std::endl;
	}
	void PostOrder2( BinaryTriNode* node ) const
	{
		std::stack< BinaryTriNode* > nodes;
		BinaryTriNode* current = node;


		while ( true )
		{
			while ( current->leftChild != nullptr )
			{
				//nodes.push( current->leftChild );
				//std::cout << "\tPushed l : " << current->leftChild->element << std::endl;
				current = current->leftChild;
			}

			std::cout << current->element << std::endl;
			std::cin.ignore();
			//nodes.pop(); current = nodes.top();

			if ( current->leftChild == nullptr && current->rightChild == nullptr )
				current = current->parent;

			while ( current->rightChild != nullptr )
			{
				nodes.push( current->rightChild );
				std::cout << "\tPushed r : " << current->rightChild->element << std::endl;
				current = current->rightChild ;
				break;
			}

			//if ( current->leftChild == nullptr && current->rightChild == nullptr )
			//current = current->parent->parent;
			//std::cout << current->element << std::endl;
			current = nodes.top();
			nodes.pop(); 
		}
		
	}
	void PostOrder_ParentPtr( BinaryTriNode* node ) const
	{
		if ( node == nullptr )
			return;

		BinaryTriNode* current = node;
		std::stack< BinaryTriNode* > nodes;
		nodes.push( current );

		while ( !nodes.empty() )
		{
			while ( current->leftChild )//->leftChild )
			{
				current = current->leftChild;
				nodes.push( current );
			}
			current = nodes.top();

			// Print left
			std::cout << current->element << std::endl;

			// Print right
			auto right = current->parent->rightChild;
			if ( right )
				std::cout << right->element << std::endl;
			
			nodes.pop();
			std::cin.ignore();

			while ( !current->rightChild )//->leftChild )
			{
				current = current->parent;
				}

			while ( current->rightChild )//->leftChild )
			{
				current = current->rightChild;
				nodes.push( current );
			}

			std::cout << current->element << std::endl;
!
			std::cin.ignore();
		}

		std::cout << node->leftChild->element << std::endl;

		if ( node->rightChild )
			std::cout << node->rightChild->element << std::endl;
	}
	void BreadthFirstSearch()
	{
		std::cout << "======================== Breadth First Search ========================\n";
		std::queue< BinaryTriNode* > nodes;
		nodes.push( root );

		int32_t proccessedNodes = 0;
		int32_t nextLevel = 1;
		int32_t emptyNodes = 0;

		while ( !nodes.empty() )
		{
			auto current = nodes.front();
			nodes.pop();

			++proccessedNodes;

			if ( current == nullptr )
			{
				nodes.push( nullptr );
				nodes.push( nullptr );
				++emptyNodes;
				std::cout << "-\t";
			}
			else
			{
				nodes.push( current->leftChild );
				nodes.push( current->rightChild );
				std::cout << current->element << "\t";
			}

			if ( proccessedNodes == nextLevel )
			{
				std::cout << std::endl;
				// Assuming the current level is filled, the amount of nodes in the last level will always be
				// 	( The total amount of nodes so ) far / 2 + 1
				// 	This is essensially the same as 2^x =  2^( x -1 ) + 2^( x - 2 ), ..., + 2^( x - n ) + 1, where x-n == 0
				// 	In other words : 2^x is the sum of 2 to the power of all exponents added together + 1
				// 		This is the same as the sum of the number of nodes in all levels of the tree above the lowest level
				// 		So the number of nodes in the lowest level is double of the nodes in all prev levels + 1
				// 		Reversing this we find that the number of the nodes in the last level is the total amount of nodes, divided by 2 minus one
				if ( emptyNodes == ( ( nextLevel / 2 ) + 1 ) )
					break;

				// Se the above comment for this point
				nextLevel = ( nextLevel * 2 ) + 1;

				// Amount of empty nodes is for this level only
				emptyNodes = 0;
			}
		}
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
