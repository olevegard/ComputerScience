#pragma once

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
	std::vector< int32_t > connectedVerticies;
};
class Graph_AdjList
{
	public:
	Graph_AdjList()
	{
	}
	void AddVertex( int32_t vertex )
	{
		adjacencyList.emplace_back( Vertex( vertex ) );
	}

	void AddEdge( int32_t vertex1, int32_t vertex2 )
	{
		for ( auto &p : adjacencyList )
		{
			if ( p.ID == vertex1 )
			{
				p.AddEdge( vertex2 );
				return;
			}
		}
		std::cout << "No edge added!\n";
	}

	bool IsConnected( int32_t vertex1, int32_t vertex2 )
	{
		for ( const auto &p : adjacencyList )
		{
			if ( p.ID == vertex1 )
			{
				if ( p.IsConnected( vertex2 ) )
				{
					std::cout << vertex1 << " is connected to " << vertex2 << std::endl;
					return true;
				}
				else
				{
					std::cout << vertex1 << " but isn't connected to " << vertex2 << std::endl;
					return false;
				}

			}
		}

		std::cout << vertex1 << " doesnt exist" << std::endl;

		return false;
	}

	std::vector< Vertex > adjacencyList;
};

