#pragma once

#include "Node.h"
#include "Iterator.h"

template< typename Object >
class List
{
	public :
		List()
			:	size( 0 )
		{
			Init();
		}
		List( const List &rhs );

		~List()
		{
			delete head;
			delete tail;
		}

		const List &operator=( const List &rhs );

		void Init()
		{
			head = new Node< Object >( 111, nullptr, nullptr  );
			tail = new Node< Object >( 222, nullptr, nullptr  );

			head->next = tail;
			tail->prev = head;
		}
		int32_t Size()
		{
			return size;
		}
		bool Empty()
		{
			return ( size == 0 );
		}
		void Clear()
		{
			std::cout << "Clearing the list\n";

			while( size != 0 )
				PopBack();
		}
		Object& Front()
		{
			return *Begin();
		}
		const Object& Front() const
		{
			return *head->next;
		}
		Object& Back()
		{
			return *(End()->prev);
		}
		const Object& Back() const
		{
			return *tail->prev;
		}
		Iterator<Object> Begin()
		{
			return Iterator< Object > ( head->next );
		}
		Iterator< Object > End()
		{
			return Iterator< Object >( tail );
		}
		// Push / Pop
		// ======================================================
		Iterator<Object> PushFront( const Object &obj )
		{
			std::cout << "PushFront " << obj << std::endl;
			return Insert( Begin(), obj );
		}
		Iterator<Object> PushBack( const Object &obj )
		{
			std::cout << "PushBack " << obj << std::endl;
			return Insert( End(), obj );
		}
		Iterator<Object> PopBack( )
		{
			std::cout << "PopBack\n";
			return Erase( --End() );
		}
		Iterator<Object> PopFront( )
		{
			std::cout << "PopFront\n";
			return Erase( Begin() );
		}

		// Insert / Erase
		// ======================================================
		Iterator<Object> Insert( Iterator< Object > iterator, const Object &obj )
		{
			std::cout << "\tInserting " << obj << std::endl;
			auto node = iterator.GetNode();
			Node< Object >* prevNode = node->prev;
			Node< Object >* newNode = new Node< Object >( obj, prevNode, node ); 

			prevNode->next = newNode;
			node->prev = newNode;

			++size;

			return Iterator< Object >(newNode);
		}
		Iterator<Object> Erase( Iterator< Object > iterator )
		{
			Node< Object >* toRemove = iterator.GetNode();
			std::cout << "\tReomving " << toRemove->data << std::endl;
			auto next = toRemove->next;
			auto prev = toRemove->prev;

			// Set next and prev of the node before and after toRemove
			prev->next = next;
			next->prev = prev;
			
			delete toRemove;

			--size;

			return Iterator< Object >(next);
		}
		Iterator<Object> Erase( Iterator< Object > iteratorStart, Iterator< Object > iteratorEnd  )
		{
			std::cout << "\tErasing : " << iteratorStart.GetNode()->data << " to " << iteratorEnd.GetNode()->data << std::endl;
			Iterator< Object > current = iteratorStart;
			Iterator< Object > end( iteratorEnd.GetNode()->next );
			//Iterator< Object > end( iteratorEnd.GetNode());

			while (  current != end )
				current = Erase( current );

			return Iterator< Object >(current);
		}
		void BubbleSort()
		{
			bool sorted = false;
			auto end = End();

			while ( !sorted )
			{
				sorted = true;

				for ( auto current = Begin(); current != end ; ++current )
				{
					Object& data1 = current.GetNode()->data;
					Object& data2 = current.GetNode()->next->data;

					if ( data1 > data2 )
					{
						std::swap( data1, data2 );
						sorted = false;
					}
				}
			}
		}
		void Print()
		{
			std::cout << "Printing list : \n";
			auto end = End();

			for ( auto current = Begin(); current != end; ++current  )
			{
				std::cout << "\t" << *current << "\n";
			}
		}

		private:
			int32_t size;
			Node< Object >* head;
			Node< Object >* tail;
};
