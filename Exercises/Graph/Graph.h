#pragma once

class Graph_Matrix
{
	public:
	Graph_Matrix()
	{
		for ( int i = 0 ; i < 5 ; ++i )
		{
			for ( int j = 0 ; j < 5 ; ++j )
			{
				matrix[i][j] = false;
			}
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
struct Vertex
{
	Vertex( int32_t id_ )
	:	ID( id_ )
	{
	}

	void AddEdge( int32_t vertex )
	{
		connectedVerticies.push_back( vertex );
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

