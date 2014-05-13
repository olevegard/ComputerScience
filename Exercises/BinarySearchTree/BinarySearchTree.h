#pragma once

#include <queue>

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


		Insert( 2 );
		Insert( 18 );

		FindMin();
		FindMax();

		for ( int32_t i = 0 ; i <= 100 ; ++i )
			Contains( i );
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
		BinaryNode* current = root;

		while ( current )
		{
			if ( current->element == value )
				return true;
			else if ( current->element < value )
				current = current->rightChild;
			else if ( current->element > value )
				current = current->leftChild;
		}

		return false;
	}
	void PrintTree() const
	{
	/*
		std::cout << "\t\t\t\t    " << root->element << std::endl;

		std::cout << "\t\t\t";
		PrintTree( root );
		std::cout << std::endl;

		std::cout << "\t\t    ";
		PrintTree( root->leftChild );
		PrintTree( root->rightChild );

		std::cout << std::endl;

		PrintTree( root->leftChild->leftChild );
		PrintTree( root->leftChild->rightChild );

		PrintTree( root->rightChild->leftChild  );
		PrintTree( root->rightChild->rightChild  );


		PrintTree( root->leftChild->leftChild->leftChild );
		PrintTree( root->leftChild->rightChild->leftChild  );

		PrintTree( root->leftChild->leftChild->rightChild );
		PrintTree( root->leftChild->rightChild->rightChild  );

		PrintTree( root->rightChild->leftChild->leftChild  );
		PrintTree( root->rightChild->rightChild->leftChild  );

		PrintTree( root->rightChild->leftChild->rightChild  );
		PrintTree( root->rightChild->rightChild->rightChild  );


*/

		//PrintTree( root );

		//std::cout << "\t" << root->leftChild->leftChild->leftChild->element;
		std::cout << root->element << std::endl;
		std::cout << root->leftChild->element << std::endl;
		std::cout << root->rightChild->element << std::endl;
		std::cout << root->rightChild->leftChild->element << std::endl;
		std::cout << root->rightChild->rightChild->element << std::endl;

		std::cout << "\n===============================================================" << std::endl;
		PrintTree_LevelOrder( root );
		std::cout << "\n===============================================================" << std::endl;
		PrintTree_LevelOrderV2( root );

		/*jj
		*/
	}

	void MakeEmpty()
	{
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

	bool Contains( const Comparable &value, BinaryNode* node ) const
	{

	}

	void MakeEmpty( BinaryNode* &node )
	{

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
				std::cout << "\nNew Level\n"
				<< "\tNext level is : " << nextLevel
				<< "\n\tNodes skipped this level : " << nodesSkipped
				<< "\n\tNodes so far : " << nodeCount
				<< std::endl;
				//std::cout << std::endl;
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
			std::cout << " l " << currentNode->leftChild->element;
			nodes.push ( currentNode->leftChild  );
			++nodesAdded;
		}

		if ( currentNode->rightChild != nullptr )
		{
			std::cout << " r " << currentNode->rightChild ->element;
			nodes.push ( currentNode->rightChild  );
			++nodesAdded;
		}

		std::cout << "\t";
		return nodesAdded;
	}
	BinaryNode* Clone( BinaryNode* node ) const
	{

	}

};
