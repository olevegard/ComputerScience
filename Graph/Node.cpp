#include <vector>
#include <iostream>


// A simple node.
// Keeps a vector with all its connected notes and the cost
struct Node
{
	Node() = delete;

	Node ( int ID_ )
		:	Node( ID_, 0 )
	{
	}

	Node ( int ID_, int cost_ )
		:	ID( ID_ )
		,	cost( cost_ )
		,	visited( false )
	{
	}
	int ID;
	int cost;
	bool visited;

	void AddNode( int ID_, int cost_ )
	{
		nodeVec.emplace_back( Node( ID_, cost_ ) );
	}
	void Print() const
	{
		std::cout << "Node " << ID << " Lowest Cost : " << cost  <<  std::endl;

		for ( int i = 0 ; i < nodeVec.size() ; ++i )
		{
			std::cout << "\tConnected node : " << nodeVec[i].ID << " with cost " << nodeVec[i].cost << std::endl;
		}
	}

	std::vector< Node > nodeVec;

	// Store the best route. 
	// Only used for the main Nodes, not the subnodes held by Nodes
	std::vector< Node > bestRoute;
};

// This vector holds all the nodes.
std::vector< Node > nodeVector =  { {1, 0}, 2, 3 ,4 ,5 ,6, 7 };

void AddNodes();
void PrintGraph();
void FindPaths( Node &node );

int main()
{
	AddNodes();
	PrintGraph();

	FindPaths( nodeVector[ 0 ] );
	FindPaths( nodeVector[ 1 ] );
	FindPaths( nodeVector[ 2 ] );
	FindPaths( nodeVector[ 3 ] );
	FindPaths( nodeVector[ 4 ] );
	FindPaths( nodeVector[ 5 ] );
	FindPaths( nodeVector[ 6 ] );

	PrintGraph();
}
void FindPaths( Node &mainNode )
{
	//mainNode.visited = true;
	std::cout << "Checking paths from node " << mainNode.ID << ", cost : " << mainNode.cost <<  std::endl;
	for ( auto &node : mainNode.nodeVec )
	{
		// Find current Node in vector
		Node &originalNode = nodeVector[ (node.ID - 1 ) ]; 

		std::cout << "\tConnected to node : " << node.ID << " with cost " << node.cost << std::endl;
		std::cout << "\t\tTotal cost " << mainNode.cost << " + " << node.cost << " = " << mainNode.cost + node.cost << std::endl;
		std::cout << "\t\tOriginal cost " << originalNode.cost << " ID " << originalNode.ID << std::endl;

		if ( !originalNode.visited || ( ( mainNode.cost + node.cost ) < originalNode.cost ) )
		{
			std::cout << "\t\t\tLower!\n";
			originalNode.cost = mainNode.cost + node.cost;
			originalNode.visited = true;
			node.visited = true;
		}
		//else std::cout << "\t\tNot lower!\n";
	}
	std::cin.ignore();
}
void AddNodes()
{
	nodeVector[0].AddNode( 2, 2 );
	nodeVector[0].AddNode( 3, 4 );
	nodeVector[0].AddNode( 4, 1 );
	nodeVector[0].visited = true;

	nodeVector[1].AddNode( 1, 2 );
	nodeVector[1].AddNode( 4, 3 );
	nodeVector[1].AddNode( 5, 10 );

	nodeVector[2].AddNode( 1, 4 );
	nodeVector[2].AddNode( 4, 2 );
	nodeVector[2].AddNode( 6, 5 );

	nodeVector[3].AddNode( 1, 1 );
	nodeVector[3].AddNode( 2, 3 );
	nodeVector[3].AddNode( 3, 2 );
	nodeVector[3].AddNode( 5, 2 );
	nodeVector[3].AddNode( 6, 8 );
	nodeVector[3].AddNode( 7, 4 );

	nodeVector[4].AddNode( 2, 10 );
	nodeVector[4].AddNode( 4, 2 );
	nodeVector[4].AddNode( 7, 6 );

	nodeVector[5].AddNode( 3, 5 );
	nodeVector[5].AddNode( 4, 8 );
	nodeVector[5].AddNode( 7, 1 );

	nodeVector[6].AddNode( 4, 4 );
	nodeVector[6].AddNode( 5, 6 );
	nodeVector[6].AddNode( 6, 1 );
/*
	// Note : Some are duplicates becuase:
	// 1. Some graphs have different cost in different directions
	// 2. It makes it easier to travel back and forth
	nodeVector[0].AddNode( 2, 7 );
	nodeVector[0].AddNode( 3, 9 );
	nodeVector[0].AddNode( 6, 14 );

	//nodeVector[1].AddNode( 1, 7 );
	nodeVector[1].AddNode( 3, 10 );
	nodeVector[1].AddNode( 4, 15 );

	//nodeVector[2].AddNode( 1, 9 );
	//nodeVector[2].AddNode( 2, 10 );
	nodeVector[2].AddNode( 4, 11 );
	nodeVector[2].AddNode( 6, 2 );

	//nodeVector[3].AddNode( 2, 15 );
	//nodeVector[3].AddNode( 3, 11 );
	nodeVector[3].AddNode( 5, 6 );

	//nodeVector[4].AddNode( 4, 6 );
	nodeVector[4].AddNode( 6, 9 );

	//nodeVector[5].AddNode( 1, 14 );
	//nodeVector[5].AddNode( 3, 2 );
	nodeVector[5].AddNode( 5, 9 );
	*/
}
void PrintGraph()
{
	std::cout << "==================================================================\n";
	for ( const auto &node : nodeVector )
		node.Print();
}
