#include "../incs/base.hpp"

int main()
{
	{
	int a = 5;
	int b = 10;


	std::cout << "a was: " << a << std::endl;
	std::cout << "b was: " << b << std::endl;
	swap(a, b);
	std::cout << "a is: " << a << std::endl;
	std::cout << "b is: " << b << std::endl;

	std::cout << "the greatest value is: " << max(a, b) << std::endl;
	std::cout << "the lowest value is: " << min(a, b) << std::endl;
	}
	{
	std::cout << std::endl;
	std::string a = "Hello";
	std::string b = "Ciao";


	std::cout << "a was: " << a << std::endl;
	std::cout << "b was: " << b << std::endl;
	swap(a, b);
	std::cout << "a is: " << a << std::endl;
	std::cout << "b is: " << b << std::endl;

	std::cout << "the greatest value is: " << max(a, b) << std::endl;
	std::cout << "the lowest value is: " << min(a, b) << std::endl;

	}
	{
	std::cout << std::endl;
	float a = 1.5;
	float b = 3.45;


	std::cout << "a was: " << a << std::endl;
	std::cout << "b was: " << b << std::endl;
	swap(a, b);
	std::cout << "a is: " << a << std::endl;
	std::cout << "b is: " << b << std::endl;

	std::cout << "the greatest value is: " << max(a, b) << std::endl;
	std::cout << "the lowest value is: " << min(a, b) << std::endl;

	}
	{
		std::cout << std::endl;
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		return 0;
	}
	return (SUC);
}