// Simple implementation of Dijkstra's algorithm
// NOTE : This example is for educational purposes only
// 	 It is not be effictied but rather demonstrate how Dijkstra's algorithm works
//
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
		,	searched( false )
	{
	}
	int ID;
	int cost;
	bool visited;
	bool searched;

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
std::vector< Node > nodeVector =  { {0, 0}, 1, 2 ,3 ,4 ,5, 6 };
std::vector< int > currentPath = { 0 };
std::vector< int > checkedNodes = { 0 };

void AddNodes();
void PrintGraph();
void FindPaths( Node &node );
bool IsNodeChecked( int node )
{
	for ( const auto i : checkedNodes )
		if ( i == node )
			return true;

	return false;
}
Node FindNextNode( Node current )
{
	int startNodeID = currentPath[ currentPath.size() - 1 ];
	int prevNodeID = currentPath[ currentPath.size() - 2 ];
	Node prevNode = nodeVector[ prevNodeID ].cost;


	Node lowestNode = current.nodeVec[1];

	std::cout << "Staring at node with ID " << current.ID << std::endl;
	std::cout << "\tCost of prev node was " << prevNode.cost << " ID " << prevNode.ID << std::endl;
	for ( auto &node : current.nodeVec )
	{
		if ( nodeVector[node.ID].searched )
		{
			std::cout << "\t\t" << node.ID << " has already been checkded\n\t\t-------------\n";
			continue;
		}

		if ( node.cost < lowestNode.cost )
		{
			std::cout << "\t\tNode " << node.ID << " has a lower cost ( " << node.cost << " ) than " << lowestNode.ID << " ( " << lowestNode.cost << " )\n";
			//std::cout << "Node " << currentNode.ID << " has a lower cost ( " << currentNode.cost << " ) than " << lowestNode.ID << " ( " << lowestNode.cost << " )\n";
			lowestNode = nodeVector[ node.ID ];
		}
	}

	currentPath.push_back( lowestNode.ID );

	return lowestNode;
}
int main()
{
	int currentNode = 0;
	AddNodes();
	PrintGraph();

	FindPaths( nodeVector[ currentNode ]);
	currentPath.push_back( current.ID );
	++currentNode;

	FindPaths( nodeVector[ currentNode ]);
	FindPaths( current );

	FindPaths( nodeVector[ currentNode ]);
	FindPaths( current );

	/*
	FindPaths( nodeVector[ currentPath[ currentPath.size() - 1 ] ] );
	FindPaths( nodeVector[ 0 ] );
	FindPaths( nodeVector[ 1 ] );
	FindPaths( nodeVector[ 2 ] );
	FindPaths( nodeVector[ 3 ] );
	FindPaths( nodeVector[ 4 ] );
	FindPaths( nodeVector[ 5 ] );
	FindPaths( nodeVector[ 6 ] );
	*/

	PrintGraph();
}
void FindPaths( Node &mainNode )
{
	//mainNode.visited = true;
	std::cout << "\nChecking paths from node " << mainNode.ID << ", cost : " << mainNode.cost <<  std::endl;
	for ( auto &node : mainNode.nodeVec )
	{
		// Find current Node in vector
		Node &originalNode = nodeVector[ node.ID ]; 

		//std::cout << "\tConnected to node : " << node.ID << " with cost " << node.cost << std::endl;
		//std::cout << "\t\tTotal cost " << mainNode.cost << " + " << node.cost << " = " << mainNode.cost + node.cost << std::endl;
		//std::cout << "\t\tOriginal cost " << originalNode.cost << " ID " << originalNode.ID << std::endl;

		if ( !originalNode.visited || ( ( mainNode.cost + node.cost ) < originalNode.cost ) )
		{
			//std::cout << "\t\t\tLower!\n";
			originalNode.cost = mainNode.cost + node.cost;
			originalNode.visited = true;
			node.visited = true;
		}
		//else std::cout << "\t\tNot lower!\n";
	}

	nodeVector[mainNode.ID].searched = true;

	std::cin.ignore();
}
void AddNodes()
{
	nodeVector[0].AddNode( 1, 2 );
	nodeVector[0].AddNode( 2, 4 );
	nodeVector[0].AddNode( 3, 1 );
	nodeVector[0].visited = true;

	nodeVector[1].AddNode( 0, 2 );
	nodeVector[1].AddNode( 3, 3 );
	nodeVector[1].AddNode( 4, 10 );

	nodeVector[2].AddNode( 0, 4 );
	nodeVector[2].AddNode( 3, 2 );
	nodeVector[2].AddNode( 4, 5 );

	nodeVector[3].AddNode( 0, 1 );
	nodeVector[3].AddNode( 1, 3 );
	nodeVector[3].AddNode( 2, 2 );
	nodeVector[3].AddNode( 4, 2 );
	nodeVector[3].AddNode( 5, 8 );
	nodeVector[3].AddNode( 6, 4 );

	nodeVector[4].AddNode( 1, 10 );
	nodeVector[4].AddNode( 3, 2 );
	nodeVector[4].AddNode( 6, 6 );

	nodeVector[5].AddNode( 2, 5 );
	nodeVector[5].AddNode( 3, 8 );
	nodeVector[5].AddNode( 6, 1 );

	nodeVector[6].AddNode( 3, 4 );
	nodeVector[6].AddNode( 4, 6 );
	nodeVector[6].AddNode( 5, 1 );
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
