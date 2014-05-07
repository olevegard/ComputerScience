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
		Node<Object>* Begin()
		{
			return head->next;
		}
		Node<Object>* End()
		{
			return tail;
		}
		// Push / Pop
		// ======================================================
		Node<Object>* PushFront( const Object &obj )
		{
			std::cout << "PushFront " << obj << std::endl;
			return Insert( Begin(), obj );
		}
		Node<Object>* PushBack( const Object &obj )
		{
			std::cout << "PushBack " << obj << std::endl;
			return Insert( End(), obj );
		}
		Node<Object>* PopBack( )
		{
			std::cout << "PopBack\n";
			return Erase( End()->prev );
		}
		Node<Object>* PopFront( )
		{
			std::cout << "PopFront\n";
			return Erase( Begin() );
		}
		// Insert / Erase
		// ======================================================

		//head -> next == tail
		Node<Object>* Insert( Node< Object >* node, const Object &obj )
		{
			std::cout << "\tInserting " << obj << std::endl;
			Node< Object >* prevNode = node->prev;
			Node< Object >* newNode = new Node< Object >( obj, prevNode, node ); 

			prevNode->next = newNode;
			node->prev = newNode;

			++size;

			return newNode;
		}
		Node<Object>* Erase( Node< Object >* toRemove )
		{
			std::cout << "\tReomving " << toRemove->data << std::endl;
			auto next = toRemove->next;
			auto prev = toRemove->prev;

			// Set next and prev of the node before and after toRemove
			prev->next = next;
			next->prev = prev;
			
			delete toRemove;

			--size;

			return next;
		}
		void Print()
		{
			std::cout << "Printing list : \n";
			Node<Object>* current = head->next;

			while ( current != tail && current != nullptr )
			{
				std::cout << "\t" << current->data << "\n";
				current = current->next;
			}
		}

		private:
			int32_t size;
			Node< Object >* head;
			Node< Object >* tail;
};
