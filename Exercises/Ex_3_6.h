#pragma once

#include "Vector/Vector.h"

// b. Running time is N, since one element will be deleted for every iteration. This is assuming vec.Erase is O( 1 ).
// 		vec.Erase( ) in this case is O( n ) since it might have to move all elements ( if an item was inserted at the beginnig )
// 		taking vec.Erase() into account, running tim wil be O( n ^ 2 )
// c. The value of m doesn't affect the running time too much since m will be added to i every iteration. And even if i < vec.size() the value will be used
//
class Ex_3_6
{
	public:
	Ex_3_6()
	{
			}
	void Solve( int32_t numberOfElements, int32_t period )
	{
		std::cout << "Solvinf for n : " << numberOfElements << " m : " << period << std::endl;
		for ( int i = 1 ; i <= numberOfElements ; ++i )
			vec.PushBack( i );

		int32_t playersToDelete = numberOfElements - 1;
		int32_t numDeleted = 0;

		for ( int32_t i = (  period ); playersToDelete != numDeleted; i += period )
		{
			if ( i >= vec.GetSize() )
				i %= vec.GetSize();

			std::cout << "Elimintating player " << i << " = " << vec[i] << std::endl;
			vec.Erase( i );
			++numDeleted;
		}

		std::cout << "Winner is player " << vec[0] << std::endl;
		vec.PopBack();
	}

	Vector< int32_t > vec;
};
