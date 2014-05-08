#include <iostream>

#include "Ex_3_1.h"
#include "Ex_3_2_a.h"
#include "Ex_3_2_b.h"
#include "Ex_3_3.h"
#include "Ex_3_4.h"
#include "Ex_3_5.h"

#include "LinkedList/LinkedList.h"

int main()
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


/*
	auto num444 = list.PushFront( 444 );
	list.Print();
	std::cin.ignore();

	std::cout << std::endl;
	list.PushFront( 222 );
	list.Print();
	std::cin.ignore();

	auto num333 = list.PushFront( 333 );
	list.Print();
	std::cout << std::endl;

	std::cout << std::endl << "Insert before " << num333->data << std::endl;
	list.Insert( num333, 999 );
	list.Print();
	std::cout << std::endl;
	std::cin.ignore();


	std::cout << std::endl << "Remove " << num333->data << std::endl;
	list.Erase( num333 );
	list.Print();
	std::cout << std::endl;
	std::cin.ignore();

	std::cout << std::endl << "Insert before " << num444->data << std::endl;
	list.Insert( num444, 1212 );
	list.Print();
	std::cout << std::endl;
	std::cin.ignore();

	std::cout << std::endl << "Remove " << num444->data << std::endl;
	list.Erase( num444 );
	list.Print();
	std::cout << std::endl;
	std::cin.ignore();

	list.PushBack( 121212 );
	list.Print();
	std::cout << std::endl;
	std::cin.ignore();

	list.PushFront( 42424224 );
	list.Print();
	std::cout << std::endl;
	std::cin.ignore();

	list.PopBack();
	list.Print();
	std::cout << std::endl;
	std::cin.ignore();

	list.PopFront();
	list.Print();
	std::cout << std::endl;
	std::cin.ignore();

	list.Clear();
	list.Print();
	*/
	//Ex_3_1::Solve();
	//
	//Ex_3_2::Solve();
	//Ex_3_2_b::Solve();
	//Ex_3_3::Solve();

	//Ex_3_4::Solve();
	//Ex_3_4::Solve();
	//Ex_3_5::Solve();

}

