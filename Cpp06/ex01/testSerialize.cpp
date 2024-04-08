# include "./incs/base.hpp"

int main()
{
	float 			f = 1.5;
	int				i = 0;

	i = f;
	std::cout << "i1 = " << i  << std::endl;
	i = reinterpret_cast<uintptr_t>(&f);
	std::cout << "i2 = " << i << std::endl;


}