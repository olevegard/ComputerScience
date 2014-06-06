#pragma once

static const int32_t SPACE_CAPACITY = 20;

//#include "Iterator.h"

template < typename Object >
class Vector
{
	public:
	explicit Vector( int32_t size_ = 0 )
	:	size( size_ )
	,	capacity( size + SPACE_CAPACITY )
	{
		objects = new Object[ capacity ];
	}
	Vector( Vector& rhs )
		:	objects( nullptr )
	{
		operator=( rhs );
	}
	~Vector( )
	{
		delete [] objects;
	}
	const Vector &operator=( const Vector &rhs )
	{
		if ( this != &rhs )
		{
			delete [] objects;
			capacity = GetCapacity();
			size = GetSize();

			objects = new Object[ capacity ];
			for ( int i = 0; i < size( ) ; ++i )
				objects[ i ] = GetObject( i );//rhs.objects[ i ];
		}

		return *this;
	}
	void Reserve( int32_t newCapacity )
	{
		Vector newVec( newCapacity );

		capacity = newCapacity;

		Object* oldObjects = objects;
		objects = new Object[ capacity ];

		for ( int i = 0 ; i < size ; ++i )
			objects[i] = oldObjects[ i ];

		delete[] oldObjects;
	}
	int32_t GetSize()
	{
		return size;
	}
	int32_t GetCapacity()
	{
		return capacity;
	}
	Object GetObject( int32_t index )
	{
		if ( CheckIndexValid( index ) )
			return Object();

		return objects[index];
	}
	Object SetObject( int32_t index, Object value  )
	{
		if ( CheckIndexValid( index ) )
			return Object();

		objects[index] = value;
	}
	Object &operator[]( int index )
	{
		return objects[ index ];
	}
	const Object &operator[]( int index ) const
	{
		if ( CheckIndexValid( index ) )
			return Object();

		return objects[ index ];
	}
	bool CheckIndexValid( int32_t index )
	{
		return !( index >= 0 && index < size );
	}
	void CheckCapacity( )
	{
		if ( size == capacity )
			Reserve( ( capacity * 2 ) + 1 );
	}
	void PushBack( Object obj )
	{
		CheckCapacity();

		objects[ size++ ] = obj;
	}
	void PopBack()
	{
		--size;
	}
	void Erase( int32_t index )
	{
		if ( CheckIndexValid( index ) )
			return;

		for ( int32_t i = index ; i < size  ; ++i )
		{
			if ( index == ( size - 1 ) )
				objects[ i ] = 0;
			else
				objects[ i ] = objects[ i + 1 ];
		}

		--size;
	}
	void Insert( Object obj, int32_t index )
	{
		std::cout << "Adding " << obj << " @ " << index << std::endl;

		if ( CheckIndexValid( index ) )
			return;

		CheckCapacity( );

		// Start in the first empty pos, move all items back
		for ( int32_t i = size; i >= index; --i )
		{
			objects[ i ] = objects[ i - 1 ];
		}
		
		objects[index] = obj;

		++size;
	}
	Object& Back()
	{
		objects[ size - 1 ];
	}
	void Print()
	{
		for( int i = 0; i < size ; ++i )
			std::cout << objects[i] << std::endl;
	}
	bool IsEmpty()
	{
		return ( size == 0 );
	}

	Object* begin()
	{
		return &objects[ 0 ];
	}

	Object* end()
	{
		return &objects[ size ];
	}
	private:
		int32_t size;
		int32_t capacity;
		Object* objects;
};
