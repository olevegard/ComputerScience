#pragma once

class HashTable
{
	void Insert( std::string str )
	{

	}

	int32_t Hash( const std::string &str )
	{
		int32_t hashedValue = 0;
		for ( const auto c : str )
		{
			hashedValue += c;
		}

		hashedValue %= 1000;

		return hashedValue;
	}
	std::vector< std::string > hasTable;
};
