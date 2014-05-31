#pragma once

struct HashNode
{
	HashNode( std::string str )
		:	HashNode( str, nullptr )
	{
	}
	HashNode( std::string str, HashNode* next_ )
		:	object( str )
		,	next( next_ )
	{
	}

	bool IsEmpty( )
	{
		return ( object.length() == 0 );
	}
	void Print()
	{
		std::cout << object;
	}
	std::string object;
	HashNode* next;
};

class HashTable
{
	public:
	HashTable( )
		:	maxHash( 100 )
		,	hashTable( maxHash, nullptr )
	{
		Insert( "aaaaaa" );
		Insert( "bbbbbbb" );
		Insert( "cccccc" );
		Insert( "1234%!@2sasdF2##!@QSAcasdAd" );
		Insert( "!@#ASGSVCGNGHhsdfaAsS4@21^23@1dsadfa" );
		Insert( "ThiIsAHshString" );
		Insert( "WhatValueIsThis" );
		Insert( "42424242424242" );
		Insert( "24242424242424" );
		Insert( "22442244224424" );
		Insert( "1234567890" );
		Insert( "abcdefghijklmnopqrstuwxyz" );
		Insert( "ABCDEFGHIJKLMNOPQRSTUVWXYZ" );

		std::cout << "\n\n";
		PrintHashTable();
	}
	void PrintHashTable()
	{
		std::cout << "=============================================== Hash Table ===============================================\n";
		for ( int32_t i = 0 ; i < hashTable.size() ; ++i )
		{
			if ( hashTable[i] == nullptr )
				continue;

			std::cout << i;

			PrintAllItems( hashTable[i] );
		}
	}
	void PrintAllItems( HashNode* node )
	{
		while ( node )
		{
			std::cout << ", " << node->object;
			node = node->next;
		}
		std::cout << std::endl;
	}
	void Insert( std::string str )
	{
		int32_t index = Hash( str );

		HashNode* node = new HashNode( str );

		if ( hashTable[ index ] != nullptr )
		{
			node->next = hashTable[index];
		}

		hashTable[ index ] = node;
	}
	int32_t Hash( const std::string &str )
	{
		int32_t hashedValue = 0;
		for ( const auto c : str )
		{
			hashedValue += c;
		}

		hashedValue %= maxHash;

		std::cout << hashedValue << " hash for " << str << " is " << hashedValue << std::endl;

		return hashedValue;
	}
	const int32_t maxHash;
	std::vector< HashNode*> hashTable;
	private:

};
