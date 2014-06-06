#include <iostream>

int64_t Pow( int64_t x, int32_t n )
{
	std::cout << "start n = " << n << ", x = " << x << std::endl;
	if ( n == 0 )
	{
		std::cout << "\t\treturning 1\n";
		return 1;
	}
	if ( n == 1 )
	{
		std::cout << "\t\treturning X ( " << x << " )\n";
		return x;
	}
	if ( ( n % 2 ) == 0 )
	{
		std::cout << "\tCalculating x * x\n";
		return Pow( x * x, n / 2 );
	}
	else
	{
		int64_t temp = Pow( x * x, n / 2 );
		std::cout << "\tCalculating " << temp << " x " << x << std::endl;
		return temp * x;
	}
}
int64_t Pow2( int64_t x, int32_t n )
{
	std::cout << "n = " << n << ", x = " << x << std::endl;
	if ( n == 0 )
		return 0;
	else
		return x * Pow2( x, n - 1);
}
int main()
{
	std::cout << "Pow 1\n=================================================\n";
	//auto x = Pow( 2, 10);
	//std::cout << "X ^ " << 10 << " = " << x << std::endl;
	

	auto x = Pow( 2, 10);
	std::cout << "X ^ " << 10 << " = " << x << std::endl;
	return 0;
}

