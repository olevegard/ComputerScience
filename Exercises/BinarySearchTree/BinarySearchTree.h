#pragma once

#include <queue>
#include <stack>
#include <iostream>

#include "BinaryNode.h"

template< typename Comparable >
class BinarySearchTree
{
	public:
	BinarySearchTree()
	{
		root = new BinaryNode< Comparable >( 50, nullptr, nullptr );
		root->height = 0;

/*
		root->rightChild = new BinaryNode< Comparable >( 100, nullptr, nullptr );
		root->rightChild->leftChild = new BinaryNode< Comparable >( 75, nullptr, nullptr ); 
		root->rightChild->leftChild->leftChild  = new BinaryNode< Comparable >( 60, nullptr, nullptr ); 
		*/
		Insert( 60 );
		Insert( 70 );
		Insert( 65 );
		Insert( 90 );

		Insert( 40 );
		Insert( 30 );
		Insert( 35 );
		Insert( 10 );

		PrintTree();
		Rotate_RR( root->rightChild );
		PrintTree();
		//Rotate_LL( root->leftChild );
		PrintTree();
/*
		Insert( 25 );
		Insert( 75 );

		Insert( 12 );
		Insert( 37 );
		Insert( 67 );
		Insert( 87 );

		Insert( 12 );
		Insert( 37 );
		Insert( 67 )
		Insert( 87 );

		Insert( 6 );
		Insert( 15 );
		Insert( 30 );
		Insert( 47 );
		Insert( 55 );
		Insert( 70 );
		//Insert( 80 );
		Insert( 105 );


		Insert( 4 );
		Insert( 8 );
		Insert( 14 );
		Insert( 18 );
		Insert( 28 );
		Insert( 35 );
		Insert( 45 );
		Insert( 48 );
		Insert( 52 );
		Insert( 60 );
		Insert( 68 );
		Insert( 72 );
		//Insert( 78 );
		//Insert( 85 );
		Insert( 110 );
		Insert( 100 );

		Insert( 2 );

		Insert( 1 );

		Insert( 105 );
		*/

		std::cout << "Max element is : " << FindMax() << std::endl;
		std::cout << "Max element is : " << FindMax( root )->element << std::endl;


		std::cout << "Min element is : " << FindMin() << std::endl;
		std::cout << "Min element is : " << FindMin( root )->element << std::endl;
		std::cin.ignore();
	}
	const BinarySearchTree& operator=( const BinarySearchTree &rhs );

	const Comparable& FindMin() const
	{
		BinaryNode< Comparable >* node = FindMin_Iterative( root );
		return node->element;
	}
	const Comparable& FindMax() const
	{
		BinaryNode< Comparable >* node = FindMax_Iterative( root );
		return node->element;
	}
	bool Contains( const Comparable &value ) const
	{
		//BinaryNode* current = root;
		return Contains( value, root );
	}
	void PrintTree() const
	{
		std::cout << "======================== Level-Order ========================\n";
		PrintTree_LevelOrder( root );
		std::cin.ignore();
		/*
		std::cout << "======================== In-Order ========================\n";
		PrintTree_InOrder( root );
		*/
		std::cin.ignore();
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
		BinaryNode< Comparable >* node = root;
		BinaryNode< Comparable >* prevNode = root;

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
		BinaryNode< Comparable >* node = FindValue(  value );
	}

	private:
	
	BinaryNode<Comparable>* root;

	// Find / Contains
	// =================================================================================
	BinaryNode< Comparable >* FindMin( BinaryNode< Comparable > *node ) const
	{
		if ( node->leftChild == nullptr )
			return node;

		return FindMin( node->leftChild );
	}
	BinaryNode< Comparable >* FindMin_Iterative( BinaryNode< Comparable > *node ) const
	{
		BinaryNode< Comparable >* current = root;
		BinaryNode< Comparable >* prev = root;

		while ( current )
		{
			prev = current;
			current = current->leftChild;
		}
		return prev;
	}
	BinaryNode< Comparable >* FindMax( BinaryNode< Comparable > *node ) const
	{
		if ( node->rightChild == nullptr )
			return node;

		return FindMax( node->rightChild );
	}
	BinaryNode< Comparable >* FindMax_Iterative( BinaryNode< Comparable > *node ) const
	{
		BinaryNode< Comparable >* current = root;
		BinaryNode< Comparable >* prev = root;

		while ( current )
		{
			prev = current;
			current = current->rightChild;
		}

		return prev;
	}

	BinaryNode< Comparable >* FindValue( const Comparable &value )
	{
		BinaryNode< Comparable >* current = root;

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
	bool Contains_Iterative( const Comparable &value, BinaryNode< Comparable >* current ) const
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
	bool Contains( const Comparable &value, BinaryNode< Comparable >* current ) const
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
	// Tree traversal / Printing
	// =====================================================================================================================================
	void PrintTree_PreOrder( BinaryNode< Comparable >* node ) const
	{
		if ( node == nullptr )
			return;

		PrintTree_InOrder( node->leftChild );
		std::cout << "\n" << node->element;
		PrintTree_InOrder( node->rightChild );
	}
	
	void PrintTree_InOrder( BinaryNode< Comparable >* node ) const
	{
		if ( node == nullptr )
			return;

		PrintTree_InOrder( node->leftChild );
		std::cout << "\n" << node->element;
		PrintTree_InOrder( node->rightChild );
	}
	void PrintTree_LevelOrder( BinaryNode< Comparable >* node ) const
	{
		std::queue< BinaryNode< Comparable >* > nodes;
		nodes.push ( node  );

		int32_t nodeCount = 1;		// Next node to be processed this iteration
		int32_t nextLevel = 2;		// What nodecCount must be in order to move down a level
		int32_t nodesSkipped = 0;	// Number of empty nodes.

		while ( !nodes.empty() )
		{
			int32_t nodesAdded = DoNextItem(  nodes );
			int32_t skippedThisTime = ( 2 - nodesAdded );
			nodesSkipped += skippedThisTime;

			++nodeCount;

			if ( nodeCount == nextLevel )
			{
				nextLevel = nodeCount * 2;

				// Skipped nodes needs to be added just once per level
				nodeCount += nodesSkipped;

				// k skipped nodes in level m
				// Wil lead to k * 2 skipped nodes in level m + 1
				// In other words : number of skipped nodes dobules for every level
				nodesSkipped *= 2;
				std::cout << std::endl;
			}
		}
	}
	// Dequeue next item, add it's children and print.
	int32_t DoNextItem( std::queue< BinaryNode< Comparable >* > &nodes ) const
	{
		BinaryNode< Comparable >* currentNode = nodes.front();
		nodes.pop();

		if ( currentNode == nullptr )
			return 0;

		std::cout << currentNode->element;// << "\t";// << currentNode->height << ")   ";

		return AddChildrenToQueue( currentNode, nodes );
	}

	// Add children of node currentNode to nodes
	// Null pointers are not added
	int32_t AddChildrenToQueue( BinaryNode< Comparable >* currentNode, std::queue< BinaryNode< Comparable >* >  &nodes ) const
	{
		int32_t nodesAdded = 0;

		if ( currentNode->leftChild != nullptr )
		{
			std::cout << " l " << currentNode->leftChild->element;
			nodes.push ( currentNode->leftChild  );
			++nodesAdded;
		}

		if ( currentNode->rightChild != nullptr )
		{
			std::cout << " r " << currentNode->rightChild->element;
			nodes.push ( currentNode->rightChild  );
			++nodesAdded;
		}

		std::cout << "\t";
		return nodesAdded;
	}
	// Manipulation
	// =====================================================================================================================================
	void Insert( Comparable value, BinaryNode<Comparable>* &node ) const
	{
		int32_t height = node->height + 1;

		if ( value < node->element )
		{
			node->leftChild = new BinaryNode< Comparable >( value, nullptr, nullptr );
			node->leftChild->height = height;
		}
		if ( value > node->element )
		{
			node->rightChild = new BinaryNode< Comparable >( value, nullptr, nullptr );
			node->rightChild->height = height;
		}
	}

	void Remove( Comparable value, BinaryNode< Comparable >* &node ) const
	{
			}

	void Rotate_LL( BinaryNode< Comparable >* &head ) const
	{
		// Create a copy of the adress of head. We will be changing head since it is a reference to a pointer and not a copy
		auto headCopy = head;

		// Set new head ( the left child of the old head )
		head = head->leftChild;

		// Set the left child of the moved node ( old head ) to the right child of the new head.
		// The right child of the new head will be changed in the nect step
		headCopy->leftChild = head->rightChild;

		// Set the right child of the new head to the old head.
		head->rightChild = headCopy;
	}
	void Rotate_RR( BinaryNode< Comparable >* &head ) const
	{
		// Create a copy of the adress of head. We will be changing head since it is a reference to a pointer and not a copy
		auto headCopy = head;

		// Set new head ( the right child of the old head )
		head = head->rightChild;

		// Set the right head of the old head to the left child of the old head. This will otherwise "get lost" in the next step
		headCopy->rightChild = head->leftChild;

		// The old head can now take it's place as the new left child of head
		head->leftChild = headCopy;

	}
	void DeleteNode( BinaryNode< Comparable >* &node )
	{
		std::cout <<"Deleting " << node->element << std::endl;

		node->leftChild = nullptr;
		node->rightChild = nullptr;

		delete node;

		node = nullptr;
	}
	BinaryNode< Comparable >* Clone( BinaryNode< Comparable >* node ) const
	{

	}
	
	void MakeEmpty_Recursive( BinaryNode< Comparable >* &node )
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
	void MakeEmpty_Iterative( BinaryNode< Comparable >* &current )
	{
		std::stack< BinaryNode< Comparable >* > checkedNodes;
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
			BinaryNode< Comparable >* popped = checkedNodes.top();
			checkedNodes.pop();

			current = popped->rightChild;

			DeleteNode( popped );
		}
		while ( !checkedNodes.empty() || current != nullptr );
	}


};
