#pragma once

class Ex_3_2_a
{
	public:
		struct Node_Single
		{
			Node_Single* next;
			int data;

			void Print()
			{
				std::cout << "\tNext pointer : " << next
					<< "\n\tData : " << data << std::endl;
			}
		};
	static void Swap( Node_Single &before, Node_Single &first, Node_Single &second )
	{
		// Set next pointer of first node ( before the two that will be swaped )
		before.next = &second;

		// Swap pointer to next node of the two nodes that will be swapped.
		first.next = second.next;
		second.next = &first;
	}
	static void PrintInfo( const Node_Single &node, const std::string &str  )
	{
		std::cout << "Nodde : " << str
			<< "\n\tAddr : " << &node
			<< "\n\tData : " << node.data
			<< "\n\tNext : " << node.next 
			<< std::endl;
	}
	static void PrintFromNode( Node_Single* node )
	{
		Node_Single* current = node;

		while ( current != nullptr )
		{
			PrintInfo( *current, "Node");
			current = (*current).next;
		}
	}
	static void Solve()
	{
		Node_Single node1;
		Node_Single node2;
		Node_Single node3;
		Node_Single node4;

		node1.next = &node2;
		node1.data = 111111;

		node2.next = &node3;
		node2.data = 222222;

		node3.next = &node4;
		node3.data = 333333;

		node4.next = nullptr;
		node4.data = 444444;

		PrintFromNode( &node1 );

		Swap( node1, node2, node3 );

		std::cout << std::endl;
		PrintFromNode( &node1 );
		/*
		   std::cout << "Node 1 nextptr : " << node1.next << std::endl;
		   std::cout << "\tValue : " << node1.data << std::endl;
		   std::cout << "Node 2 nextptr : " << node2.next << std::endl;
		   std::cout << "\tValue : " << node2.data << std::endl;
		   PrintInfo( node1, "Node_1" );
		   PrintInfo( node2, "Node_2" );

		   Swap( node1, node2 );

		   std::cout << std::endl;
		   PrintInfo( node1, "Node_1" );
		   PrintInfo( node2, "Node_2" );
		   */
	}
};
