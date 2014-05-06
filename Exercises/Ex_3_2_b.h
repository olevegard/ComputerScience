#pragma once

class Ex_3_2_b
{
	public:
		struct Node
		{
			Node* next;
			Node* prev;
			int data;

			void Print()
			{
				std::cout << "\tNext pointer : " << next
					<< "\n\tData : " << data << std::endl;
			}
		};
		static void Swap( Node& first, Node& second )
		{
			// Set next pointer of first node ( before the two that will be swaped )
			first.prev->next = &second;

			// Swap pointer to next node of the two nodes that will be swapped.
			first.next = second.next;
			first.prev = &second; 

			second.next = &first;
			second.prev = first.prev;
		}
		static void PrintInfo( const Node &node, const std::string &str  )
		{
			std::cout << "Nodde : " << str
				<< "\n\tAddr : " << &node
				<< "\n\tData : " << node.data
				<< "\n\tPrev : " << node.prev 
				<< "\n\tNext : " << node.next 
				<< std::endl;
		}
		static void PrintFromNode( Node* node )
		{
			Node* current = node;

			while ( current != nullptr )
			{
				PrintInfo( *current, "Node");
				current = (*current).next;
			}
		}
		static void Solve()
		{
			Node node1;
			Node node2;
			Node node3;
			Node node4;

			node1.prev = nullptr;
			node1.next = &node2;
			node1.data = 111111;

			node2.prev = &node1;
			node2.next = &node3;
			node2.data = 222222;

			node3.prev = &node2;
			node3.next = &node4;
			node3.data = 333333;

			node4.prev = &node3;
			node4.next = nullptr;
			node4.data = 444444;

			PrintFromNode( &node1 );

			Swap( node2, node3 );

			std::cout << std::endl;
			PrintFromNode( &node1 );
		}
};
