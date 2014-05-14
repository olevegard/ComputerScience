#pragma once

#include <queue>
#include <stack>
#include <iostream>

template< typename Comparable >
class BinarySearchTree
{
	public:
	BinarySearchTree()
	{
		root = new BinaryNode( 50, nullptr, nullptr );

		Insert( 25 );
		Insert( 75 );

		Insert( 12 );
		Insert( 37 );

		Insert( 67 );
		Insert( 87 );

		Insert( 6 );
		Insert( 15 );

		Insert( 30 );
		Insert( 47 );

		Insert( 55 );
		Insert( 70 );

		Insert( 80 );
		Insert( 90 );


		Insert( 8 );
		Insert( 4 );

		FindMin();
		FindMax();

		for ( int32_t i = 0 ; i <= 100 ; ++i )
		{
			if ( Contains( i ) )
				std::cout << i << ". exists\n";
		}
		std::cin.ignore();
	}
	const BinarySearchTree& operator=( const BinarySearchTree &rhs );

	const Comparable& FindMin() const
	{
		BinaryNode* current = root;
		BinaryNode* prev = root;

		while ( current )
		{
			prev = current;
			current = current->leftChild;
		}

		std::cout << "Min element is : " << prev->element << std::endl;
		return prev->element;
	}
	const Comparable& FindMax() const
	{
		BinaryNode* current = root;
		BinaryNode* prev = root;

		while ( current )
		{
			prev = current;
			current = current->rightChild;
		}

		std::cout << "Max element is : " << prev->element << std::endl;
		return prev->element;
	}
	bool Contains( const Comparable &value ) const
	{
		//BinaryNode* current = root;
		return Contains( value, root );

		//return false;
	}
	void PrintTree() const
	{
		PrintTree_LevelOrder( root );
	}

	void MakeEmpty()
	{
		//MakeEmpty_Recursive( root );
		MakeEmpty_Iterative( root );
	}
	bool IsEmpty() const
	{
		return root == nullptr;
	}
	void Insert( Comparable value )
	{
		BinaryNode* node = root;
		BinaryNode* prevNode = root;

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

	void Remove( Comparable value )
	{
		BinaryNode* node = FindValue(  value );

	}

		private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode *leftChild;
		BinaryNode *rightChild;

		BinaryNode( Comparable value, BinaryNode* leftChild_, BinaryNode* rightChild_ )
		:	element( value )
		,	leftChild( leftChild_ )
		,	rightChild( rightChild_ )
		{
		}
	};

	BinaryNode* root;

	void Insert( Comparable value, BinaryNode* &node ) const
	{
		if ( value < node->element )
		{
			node->leftChild = new BinaryNode( value, nullptr, nullptr );
		}
		if ( value > node->element )
		{
			node->rightChild = new BinaryNode( value, nullptr, nullptr );
		}
	}

	void Remove( Comparable value, BinaryNode* &node ) const
	{

	}

	BinaryNode* FindMin( BinaryNode *node ) const
	{

	}
	BinaryNode* FindMax( BinaryNode *node ) const
	{

	}

	bool Contains_Iterative( const Comparable &value, BinaryNode* current ) const
	{
		while ( current )
		{
			if ( current->element == value )
				return true;
			else if ( current->element < value )
				current = current->rightChild;
			else
				current = current->leftChild;
		}

		return false;
	}
	bool Contains( const Comparable &value, BinaryNode* current ) const
	{
		if ( current == nullptr )
			return false;

		if ( current->element == value )
			return true;
		else if ( current->element < value )
			return Contains( value, current->rightChild );
		else
			return Contains( value, current->leftChild);
	}
	void MakeEmpty_Recursive( BinaryNode* &node )
	{
		if ( node == nullptr )
			return;

		MakeEmpty_Recursive( node->leftChild );
		MakeEmpty_Recursive( node->rightChild );

		DeleteNode( node );
	}
	// Delete all nodes without recursion
	// Run time : n log n
	//	Outer loop loops as long as there are nodes in the stack
	//	Every node will only be added to the stack once
	//	This means the outer loop maximum will loop n times
	//
	//	The inner loop will loop to the bottom of the tree which is O( log n )
	void MakeEmpty_Iterative( BinaryNode* &current )
	{
		std::stack< BinaryNode* > checkedNodes;
		do
		{
			// Add all left child nodes
			while ( current != nullptr )
			{
				checkedNodes.push( current );
				current = current->leftChild;
			}

			// Pop the last node
			// Store its child 
			// Restart loop
			BinaryNode* popped = checkedNodes.top();
			checkedNodes.pop();

			current = popped->rightChild;

			DeleteNode( popped );
		}
		while ( !checkedNodes.empty() || current != nullptr );
	}
	void DeleteNode( BinaryNode* &node )
	{
				std::cout <<"Deleting " << node->element << std::endl;

		node->leftChild = nullptr;
		node->rightChild = nullptr;

		delete node;

		node = nullptr;
	}
	void PrintTree( BinaryNode* node ) const
	{
		if ( node == nullptr )
		{
			return;
		}

		PrintTree( node->leftChild );
		std::cout << "\t" << node->element;
		PrintTree( node->rightChild );
	}
	void PrintTree_LevelOrder( BinaryNode* node ) const
	{
		if ( IsEmpty() )
		{
			std::cout << "tree is empty\n";
			return;
			}

		std::queue< BinaryNode* > nodes;
		nodes.push ( root  );

		// The two below values might seem strange
		// Having nodeCount start at 1 
		int32_t nodeCount = 1; // Next node to be processed working
		int32_t nextLevel = 2; // working
		int32_t nodesSkipped = 0;

		while ( !nodes.empty() )
		{
			DoNextItem(  nodes );

			++nodeCount;
			if ( nodeCount == nextLevel )
			{
				nextLevel = nodeCount * 2;
				/*
				std::cout << "\nNew Level\n"
				<< "\tNext level is : " << nextLevel
				<< "\n\tNodes skipped this level : " << nodesSkipped
				<< "\n\tNodes so far : " << nodeCount
				<< std::endl;
				*/
				std::cout << std::endl;
			}
		}
		std::cout << "\nNode count " << nodeCount << std::endl;

	}
	void PrintTree_LevelOrderV2( BinaryNode* node ) const
	{
		std::queue< BinaryNode* > nodes;
		nodes.push ( root  );

		// The two below values might seem strange
		// Having nodeCount start at 1 
		int32_t nodeCount = 1; // Next node to be processed working
		int32_t nextLevel = 2; // working
		int32_t nodesSkipped = 0;

		while ( !nodes.empty() )
		{
			int32_t nodesAdded = DoNextItem(  nodes );
			int32_t skipped = ( 2 - nodesAdded );
			nodesSkipped += skipped;

			//nodeCount += 1;// working
			++nodeCount;
			if ( nodeCount == nextLevel )
			{
				nextLevel = nodeCount * 2;
				std::cout << "\nNew Level\n"
				<< "\tNext level is : " << nextLevel
				<< "\n\tNodes skipped this level : " << nodesSkipped
				<< "\n\tNodes so far : " << nodeCount
				<< std::endl;
				//std::cout << std::endl;
			}
		}
		std::cout << "\nNode count " << nodeCount << std::endl;
		std::cout << "\nNext level " << nextLevel << std::endl;

	}
	// Dequeue next item, add it's children and print.
	int32_t DoNextItem( std::queue< BinaryNode* > &nodes ) const
	{
		BinaryNode* currentNode = nodes.front();
		nodes.pop();

		//std::cout << currentNode->element << "\t";
		std::cout << currentNode->element;
		return AddChildrenToQueue( currentNode, nodes );
	}

	// Add children of node currentNode to nodes
	// Null pointers are not added
	int32_t AddChildrenToQueue( BinaryNode* currentNode, std::queue< BinaryNode* > &nodes ) const
	{
		int32_t nodesAdded = 0;

		if ( currentNode->leftChild != nullptr )
		{
			nodes.push ( currentNode->leftChild  );
			++nodesAdded;
		}

		if ( currentNode->rightChild != nullptr )
		{
			nodes.push ( currentNode->rightChild  );
			++nodesAdded;
		}

		std::cout << "\t";
		return nodesAdded;
	}
	BinaryNode* Clone( BinaryNode* node ) const
	{

	}

	BinaryNode* FindValue( const Comparable &value )
	{
		BinaryNode* current = root;

		while ( current )
		{
			if ( current->element == value )
				return current;
			else if ( current->element < value )
				current = current->rightChild;
			else if ( current->element > value )
				current = current->leftChild;
		}

		return nullptr;
	}
};
