#include <vector>
#include <iostream>


// A simple node.
// Keeps a vector with all its connected notes and the cost
struct Node
{
	Node() = delete;

	Node ( int ID_ )
	{
		ID = ID_;
		cost = 999999;
	}

	Node ( int ID_, int cost_ )
	{
		ID = ID_;
		cost = cost_;
	}
	int ID;
	int cost;

	void AddNode( int ID_, int cost_ )
	{
		nodeVec.emplace_back( Node( ID_, cost_ ) );
	}
	void Print() const
	{
		std::cout << "Node " << ID << " Lowest Cost : " << cost <<  std::endl;

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
std::vector< Node > nodeVector =  { {1, 0}, 2, 3 ,4 ,5 ,6 };

void AddNodes();
void PrintGraph();
void FindPaths( Node node );

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

	PrintGraph();
}
void FindPaths( Node mainNode )
{
	std::cout << "\nChecking paths from node " << mainNode.ID << std::endl;
	for ( const auto &node : mainNode.nodeVec )
	{
		Node &superNode = nodeVector[ (node.ID - 1 ) ]; 
		std::cout << "\tChecking min path for node : " << node.ID
			<< " min cost " << mainNode.cost << " + " << node.cost
			<< " = " << mainNode.cost + node.cost
			<< std::endl;

		if ( ( mainNode.cost + node.cost ) < superNode.cost )
		{
			std::cout << "\t\tLower!\n";
			superNode.cost = mainNode.cost + node.cost;
		}
		else
			std::cout << "\t\tNot lower!\n";
	}

}
void AddNodes()
{
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
}
void PrintGraph()
{
	for ( const auto &node : nodeVector )
		node.Print();
}
