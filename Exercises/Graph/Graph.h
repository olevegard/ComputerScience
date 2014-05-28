#pragma once

#include <map>

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

		BFS();
		DFS();
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
		std::map< int32_t, Edge > path;
		std::queue< Edge > toVisit;

		toVisit.push( 1 );
		path[1] = Edge( 1, 0 );
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
			std::cout << "Path to " << v.second.ID << "\n\t" << path[v.second.ID].ID << " cost " << path[v.second.ID].cost << std::endl;
	}
	void DFS()
	{
		std::map< int32_t, Edge > path;
		std::stack< Edge > toVisit;

		toVisit.push( 1 );
		path[1] = Edge( 1, 0 );
		while ( !toVisit.empty() )
		{
			Edge currentEdge = toVisit.top();
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
			std::cout << "Path to " << v.second.ID << "\n\t" << path[v.second.ID].ID << " cost " << path[v.second.ID].cost << std::endl;
	}
	void ListConnectedVerteices( const Vertex &vertex  )
	{
		//for ( const int i : vertex.connectedVerticies )std::cout << i << std::endl;
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
