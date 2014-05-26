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

