#pragma once

#include <map>
#include "../Heap/Heap.h"

class Graph_Matrix
{
	public:
	Graph_Matrix()
	{
		for ( int i = 0 ; i < 5 ; ++i )
		{
			for ( int j = 0 ; j < 5 ; ++j )
				matrix[i][j] = false;
		}
	}
	void InsertEdge( int first, int second )
	{
		matrix[first][second] = true;
		matrix[second][first] = true;
	}
	bool IsConnected( int first, int second )
	{
		bool connected = matrix[first][second];
		std::cout << "Is " << first << ", " << second << " connected? " << std::boolalpha << connected << std::endl;
		return connected;
	}

	bool matrix[5][5];
};
struct Edge
{
	Edge( int32_t id_, int32_t cost_ )
	:	ID( id_ )
	,	cost( cost_ )
	{
	}
	Edge( int32_t id_ )
	:	Edge( id_, 0 )
	{
	}
	Edge( )
	:	Edge( 0, 0 )
	{
	}
	void operator=( const int &otherID )
	{
		ID = otherID;
	}

	int32_t ID;
	int32_t cost;
};
inline bool operator==( const Edge &lhs, const int32_t &rhs)
{
	return ( lhs.ID == rhs );
}
inline bool operator<( const Edge &lhs, const Edge &rhs )
{
	return lhs.cost > rhs.cost;
}
struct Vertex
{
	Vertex( int32_t id_ )
	:	ID( id_ )
	{
	}
	void AddEdge( int32_t vertex, int32_t cost )
	{
		connectedVerticies.push_back( Edge( vertex, cost ) );
	}
	bool IsConnected ( int32_t vertex ) const
	{
		for ( auto i : connectedVerticies )
		{
			if ( i == vertex )
				return true;
		}

		return false;
	}
	int32_t ID;
	std::vector< Edge > connectedVerticies;
};
class Graph_AdjList
{
	public:
	Graph_AdjList()
	{
		AddVertex( 1 );
		AddVertex( 2 );
		AddVertex( 3 );
		AddVertex( 4 );
		AddVertex( 5 );
		AddVertex( 6 );
		AddVertex( 7 );

		AddEdge( 1, 2, 2 );
		AddEdge( 1, 4, 1 );

		AddEdge( 2, 4, 3 );
		AddEdge( 2, 5, 10 );

		AddEdge( 3, 1, 4 );
		AddEdge( 3, 6, 5 );

		AddEdge( 4, 3, 2 );
		AddEdge( 4, 5, 2 );
		AddEdge( 4, 6, 8 );
		AddEdge( 4, 7, 4 );

		AddEdge( 5, 7, 6 );

		AddEdge( 7, 6, 1 );

		std::cout << "All vertices and edges added\n";

		std::cout << std::boolalpha << IsConnected( 7, 6 ) << std::endl;
		std::cout << std::boolalpha << IsConnected( 6, 7 ) << std::endl;
		std::cout << std::boolalpha << IsConnected( 9, 6 ) << std::endl;

		std::cout << "=============================== Breadth First Search ===============================\n";
		BFS();
		std::cout << "=============================== Debth First Search ===============================\n";
		DFS();
		std::cout << "=============================== Dijkstra ===============================\n";
		Dijkstra();
	}
	void AddVertex( int32_t vertex )
	{
		adjacencyList.insert( std::pair< int32_t , Vertex > ( vertex, Vertex( vertex ) ) );
	}
	void AddEdge( int32_t vertex1, int32_t vertex2, int32_t cost = 0 )
	{
		auto vertex = adjacencyList.find( vertex1 );

		if ( vertex != std::end( adjacencyList ) )
			vertex->second.AddEdge( vertex2, cost );
	}
	void BFS()
	{
		std::map< int32_t, Edge > path{ { 1, 0 } };
		std::queue< Edge > toVisit( { 1 } );

		while ( !toVisit.empty() )
		{
			Edge currentEdge = toVisit.front();
			toVisit.pop();

			const auto edgesFromCurrentVertex = adjacencyList.at( currentEdge.ID ).connectedVerticies;
			
			for ( const Edge edge : edgesFromCurrentVertex )
			{
				if ( path.count( edge.ID) == 0 )
				{
					path[ edge.ID ].ID = currentEdge.ID;
					path[ edge.ID ].cost = ( edge.cost + currentEdge.cost );
					toVisit.push( edge );
				}
			}
		}

		for ( const auto &v : adjacencyList )
			std::cout << "Path to " << v.second.ID << " : " << path[v.second.ID].ID << " cost " << path[v.second.ID].cost << std::endl;
	}
	void Dijkstra()
	{
		std::map< int32_t, Edge > path{ { 1, 0 } };
		std::queue< Edge > toVisit( { 1 } );

		while ( !toVisit.empty() )
		{
			Edge currentEdge = toVisit.front();
			toVisit.pop();
			int32_t currentCost = path[ currentEdge.ID ].cost;

			const auto list = adjacencyList.at( currentEdge.ID ).connectedVerticies;
			
			if ( list.size() == 0 )
				continue;

			std::priority_queue< Edge > edgeHeap;
			for ( const Edge edge : list )
				edgeHeap.push( edge );

			while ( !edgeHeap.empty() )
			{
				Edge edge = edgeHeap.top();

				edgeHeap.pop();

				// If path is new or has better cost that previous path
				if ( ( path.count( edge.ID ) == 0 ) || ( path[ edge.ID ].cost > ( edge.cost + currentCost ) ) )
				{
					path[ edge.ID ].ID = currentEdge.ID;
					path[ edge.ID ].cost = ( edge.cost + currentCost );

					toVisit.push( edge );
				}
			}
		}

		for ( const auto &v : adjacencyList )
			std::cout << "Path to " << v.second.ID << " : " << path[v.second.ID].ID << " cost " << path[v.second.ID].cost << std::endl;
	}
	void DFS()
	{
		std::map< int32_t, Edge > path{ { 1, 0 } };
		std::queue< Edge > toVisit( { 1 } );

		while ( !toVisit.empty() )
		{
			Edge currentEdge = toVisit.front();
			toVisit.pop();

			const auto list = adjacencyList.at( currentEdge.ID ).connectedVerticies;
			
			for ( const Edge edge : list )
			{
				if ( path.count( edge.ID) == 0 )
				{
					path[ edge.ID ].ID = currentEdge.ID;
					path[ edge.ID ].cost = ( edge.cost + currentEdge.cost );
					toVisit.push( edge );
				}
			}
		}

		for ( const auto &v : adjacencyList )
			std::cout << "Path to " << v.second.ID << " : " << path[v.second.ID].ID << " cost " << path[v.second.ID].cost << std::endl;
	}
	void ListConnectedVerteices( const Vertex &vertex  )
	{
		for ( const Edge &edge : vertex.connectedVerticies )
			std::cout << edge.ID << ", cost : " << edge.cost << std::endl;
	}
	bool IsConnected( int32_t vertex1, int32_t vertex2 )
	{
		std::cout << "Is " << vertex1 << " connected to " << vertex2 << "? ";
		auto vertex = adjacencyList.find( vertex1 );

		if ( vertex != std::end( adjacencyList ) )
			return vertex->second.IsConnected( vertex2 );
		else
			return false;
	}

	std::map< int32_t, Vertex > adjacencyList;
};
