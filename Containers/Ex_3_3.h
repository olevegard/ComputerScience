#pragma once

class Ex_3_3
{
	public:
		template <typename Iterator, typename Object >
		static Iterator find(  Iterator start, Iterator end, const Object &x )
		{
			auto p = start;

			while ( (*p) != x && p != end )
			{
				p++;
			}

			return p;
		}
		static void Solve()
		{
			std::vector< int > vec{ 0,1,2,3,4 };
			auto p =  find( vec.begin(), vec.end(), 9 );
			std::cout << "Found : " << (*p) << std::endl;
		}
};
