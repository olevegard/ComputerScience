#pragma once

class HashTable
{
public:
	HashTable( )
	:	maxHash( 100 )
	,	hashTable( 100 )
	{

		Insert( "aaaaaa" );
		Insert( "bbbbbbb" );
		Insert( "cccccc" );
		Insert( "1234%!@2sasdF2##!@QSAcasdAd" );
		Insert( "!@#ASGSVCGNGHhsdfaAsS4@21^23@1dsadfa" );
		Insert( "ThiIsAHshString" );
		Insert( "WhatValueIsThis" );
		Insert( "42424242424242" );
		Insert( "1234567890" );
		Insert( "abcdefghijklmnopqrstuwxyz" );
		Insert( "ABCDEFGHIJKLMNOPQRSTUVWXYZ" );

		PrintHashTable();
	}
	void PrintHashTable()
	{
		for ( int32_t i = 0 ; i < hashTable.size() ; ++i )
		{
			const auto &str = hashTable[i];
			if ( str.length() != 0 )
				std::cout << i << ". " << str << std::endl;
		}
	}
	void Insert( std::string str )
	{
		int32_t index = Hash( str );

		hashTable[ index ] = str;
	}
	int32_t Hash( const std::string &str )
	{
		int32_t hashedValue = 0;
		for ( const auto c : str )
		{
			hashedValue += c;
		}

		hashedValue %= maxHash;

		std::cout << "Hash for " << str << " is " << hashedValue << std::endl;

		return hashedValue;
	}
	const int32_t maxHash;
	std::vector< std::string > hashTable;
};
