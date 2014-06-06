// Binary Search Tree - Ole Vegard Mythe Moland
//
// Note : this class is not intended as an efficient implementatoin of an AVL tree. 
// 	Though the ideal is to use efficent solutions to problems, the main priority is to learn about AVL trees
// 	Likewise the comments are also used mostly for educational purposes
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
		root = new BinaryNode< Comparable >( 20, nullptr, nullptr );
		root->height = 0;

		Insert( 10 );
		Insert( 5 );
		Insert( 15 );
		Insert( 14 );
		Insert( 18 );
		Insert( 25 );
		Insert( 35 );
		Insert( 30 );
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
		PrintTree_LevelOrder( root );

		BreadthFirstSearch_Quick();

		std::cout << "======================== In Order Traversal ========================\n";
		PrintTree_InOrder( root );

		std::cout << "======================== Pre Order Traversal ========================\n";
		PrintTree_PreOrder( root );

		std::cout << "======================== Depth First ( reverse ) Traversal ========================\n";
		PrintTree_DepthFirstSearch_Descending( root );

		std::cout << "======================== Post Order Traversal ========================\n";
		PrintTree_PostOrder( root );
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
	void PrintTree_InOrder( BinaryNode< Comparable >* head) const
	{
		if ( head == nullptr )
			return;

		PrintTree_InOrder( head->leftChild );
		std::cout << head->element << std::endl;
		PrintTree_InOrder( head->rightChild );
	}
	// This is a DFS( Depth First Search )
	void PrintTree_PreOrder( BinaryNode< Comparable >* head) const
	{
		if ( head == nullptr )
			return;

		std::cout << head->element << std::endl;
		PrintTree_PreOrder( head->leftChild );
		PrintTree_PreOrder( head->rightChild );
	}
	// This is also a DFS( Depth First Search )
	// It starts in at the right child node, so it's not a preorder search
	void PrintTree_DepthFirstSearch_Descending( BinaryNode< Comparable >* head) const
	{
		if ( head == nullptr )
			return;

		std::cout << head->element << std::endl;
		PrintTree_DepthFirstSearch_Descending( head->rightChild );
		PrintTree_DepthFirstSearch_Descending( head->leftChild );
	}
	void PrintTree_PostOrder( BinaryNode< Comparable >* head) const
	{
		if ( head == nullptr )
			return;

		PrintTree_PostOrder( head->leftChild );
		PrintTree_PostOrder( head->rightChild );
		std::cout << head->element << std::endl;
	}
	// Level Order Traversals
	/*
	 * A Breadth First Search is essensially the same as Level Order traversal
	 * This implementation is a shortened version of the one lower down
	 */
	void BreadthFirstSearch()
	{
		std::cout << "======================== Breadth First Search ========================\n";
		std::queue< BinaryNode< Comparable >* > nodes;
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
	void BreadthFirstSearch_Quick() const
	{
		std::cout << "======================== Breadth First Search ( Level-Order ) ========================\n";
		std::queue< BinaryNode< Comparable >* > nodes;
		nodes.push( root );

		while ( !nodes.empty() )
		{
			auto current = nodes.front();
			nodes.pop();

			if ( current != nullptr )
			{
				nodes.push( current->leftChild );
				nodes.push( current->rightChild );
				std::cout << current->element << "\n";
			}
		}
	}
	void PrintTree_LevelOrder( BinaryNode< Comparable >* node ) const
	{
		std::cout << "\n======================== Level-Order ========================\n";
		std::queue< BinaryNode< Comparable >* > nodes;
		nodes.push ( node  );

		int32_t nodeCount = 0;		// Next node to be processed this iteration
		int32_t nextLevel = 1;		// What nodecCount must be in order to move down a level
		int32_t emptyNodesThisLevel = 0;

		while ( !nodes.empty() )
		{
			emptyNodesThisLevel += DoNextItem(  nodes );

			++nodeCount;

			if ( nodeCount == nextLevel )
			{
				if ( emptyNodesThisLevel == nextLevel )
					break;

				nextLevel *= 2;
				emptyNodesThisLevel = 0;
				nodeCount = 0;

				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
	}
	// Dequeue next item, add it's children and print.
	int32_t DoNextItem( std::queue< BinaryNode< Comparable >* > &nodes ) const
	{
		BinaryNode< Comparable >* currentNode = nodes.front();
		nodes.pop();

		//if ( currentNode == nullptr )return 0;

		if ( currentNode )
			std::cout << currentNode->element << "\t";// << currentNode->height << ")   ";
		else
			std::cout << "-\t";

		return AddChildrenToQueue( currentNode, nodes );
	}

	// Add children of node currentNode to nodes
	// Null pointers are not added
	int32_t AddChildrenToQueue( BinaryNode< Comparable >* currentNode, std::queue< BinaryNode< Comparable >* >  &nodes ) const
	{
		int32_t emptyNodes = 0;

		//std::cout << "[";

		if ( !currentNode )
		{
			//std::cout << " l " << "-" << " r " << "-";
			nodes.push ( nullptr  );
			nodes.push ( nullptr  );

			emptyNodes = 1;
			return emptyNodes;
		}

		if ( currentNode->leftChild != nullptr )
		{
			//std::cout << " l " << currentNode->leftChild->element;
			nodes.push ( currentNode->leftChild  );
		}
		else
		{
			//std::cout << " l " << "-";
			nodes.push ( nullptr  );
			//++emptyNodes;
		}

		if ( currentNode->rightChild != nullptr )
		{
			//std::cout << " r " << currentNode->rightChild->element;
			nodes.push ( currentNode->rightChild  );
		}
		else
		{
			//std::cout << " r " << "-";
			nodes.push ( nullptr  );
			//++emptyNodes;
		}

		//std::cout << "]\t";
		//emptyNodes = 0;
		return emptyNodes;
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
