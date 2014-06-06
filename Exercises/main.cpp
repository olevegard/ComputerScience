#include <iostream>

#include "Ex_3_1.h"
#include "Ex_3_2_a.h"
#include "Ex_3_2_b.h"
#include "Ex_3_3.h"
#include "Ex_3_4.h"
#include "Ex_3_5.h"
#include "Ex_3_6.h"

#include "BinarySearchTree/BinarySearchTree.h"
#include "LinkedList/LinkedList.h"
#include "HashTable/HashTable.h"
#include "Sorting/Sorting2.h"
#include "Vector/Vector.h"
#include "Graph/Graph.h"
#include "Heap/Heap.h"
#include "Set/Set.h"

void PrintList();

int main()
{
	Sorting2 sorting;

/*
	HashTable hashTable;
	Graph_Matrix graph;

	graph.InsertEdge( 2, 3);
	graph.IsConnected( 2, 3);
	graph.IsConnected( 3, 3);
	graph.IsConnected( 3, 2);
	graph.IsConnected( 2, 2);
	*/

	//Graph_AdjList graph_adjlist;

	//BinaryTreeTester btt;
	//btt.Print();

	//BinarySearchTree< int32_t > bst;
	//bst.PrintTree();


	/*
	bst.BreadthFirstSearch_Quick();
	Set set;
	Heap< int32_t > heap;
	heap.Print();
	std::cout << std::endl;

	heap.Print();
	std::cout << std::endl;

	heap.DeleteMax();
	heap.Print();

	std::cout << std::endl;

	//heap.PrelocateDown( 1 );
	//heap.Print();
	//BinarySearchTree< int32_t > testTree;
	//testTree.PrintTree();
	//testTree.MakeEmpty();

	//testTree.PrintTree();
	//PrintList();
	Vector< int32_t > vec;
	vec.PushBack( 11111 );
	vec.PushBack( 22222 );
	vec.PushBack( 33333 );
	vec.PushBack( 44444 );
	vec.PushBack( 55555 );
	*/
	//vec.Insert( 0, 343434 );
	//vec.Print();
	/*
	Ex_3_6 ex_3_6;
	ex_3_6.Solve( 5, 0 );
	std::cout << "=====================================\n";
	ex_3_6.Solve( 5, 1 );
	std::cout << "=====================================\n";
	ex_3_6.Solve( 5, 2 );
	std::cout << "=====================================\n";
	ex_3_6.Solve( 5, 3 );
	std::cout << "=====================================\n";

	Vector< int32_t > vec;

	vec.PushBack( 11111 );
	vec.PushBack( 22222 );
	vec.PushBack( 33333 );
	vec.PushBack( 44444 );
	vec.PushBack( 55555 );
	std::cout << "===============================\n";
	vec.Insert( 987987, 2 );
	std::cout << "===============================\n";
	vec.Insert( 7777777, 5 );
	auto inBoth1 = rand() % 100;
	auto inBoth2 = rand() % 100;
	auto inBoth3 = rand() % 100;
	auto inBoth4 = rand() % 100;
	List< int32_t > list;
	list.PushBack( inBoth1 );
	list.PushBack( rand() % 100 );
	list.PushBack( rand() % 100 );
	list.PushBack( inBoth2 );
	list.PushBack( rand() % 100 );
	list.PushBack( rand() % 100 );
	list.PushBack( rand() % 100 );
	list.PushBack( inBoth3 );
	list.PushBack( rand() % 100 );
	list.PushBack( rand() % 100 );
	list.PushBack( inBoth4 );
	list.PushBack( rand() % 100 );

	List< int32_t > list2;
	list2.PushBack( rand() % 100 );
	list2.PushBack( rand() % 100 );
	list2.PushBack( inBoth1 );
	list2.PushBack( inBoth2 );
	list2.PushBack( rand() % 100 );
	list2.PushBack( rand() % 100 );
	list2.PushBack( rand() % 100 );
	list2.PushBack( rand() % 100 );
	list2.PushBack( inBoth3 );
	list2.PushBack( rand() % 100 );
	list2.PushBack( rand() % 100 );
	list2.PushBack( inBoth4 );

	//Ex_3_4::Intersect( list, list2 );
	Ex_3_5::Union( list, list2 );
	std::cout << "Done copying\n";

	*/
}
void PrintList()
{
	List<int32_t> list;

	auto second =  list.PushBack( 156 );
	list.Print();
	list.PushFront( 77 );
	list.Print();
	auto first = list.PushFront( 99 );
	list.Print();

	list.PushFront( 33 );
	list.Print();

	list.PushBack( 133 );
	list.Print();

	list.Erase( first, second );
	list.Print();

	list.PushBack( rand() % 100 );
	list.PushBack( rand() % 100 );
	list.PushBack( rand() % 100 );
	list.PushBack( rand() % 100 );
	list.PushBack( rand() % 100 );
	list.PushBack( rand() % 100 );
	list.PushBack( rand() % 100 );
	list.PushBack( rand() % 100 );

	list.Print();
	list.BubbleSort();
	list.Print();
}
