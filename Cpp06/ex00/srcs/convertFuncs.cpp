#include "../incs/funcs.hpp"

double		powerOfTen(int power)
{
	int nb = 1;
	for (int i = 0; i < power; i++)
		nb *= 10;
	 return (nb);  
}

long double strToLd(std::string &str)
{
	long double	nb = 0;
	int			sign = 1;
	size_t		posPoint =  std::string::npos;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
			nb = nb * 10 + (str[i] - 48);
		else if (str[i] == '-')
			sign *= -1;
		else if (str[i] != 'f' && str[i] != '.' && str[i] != '+' && str[i] != '-')
			return (DOUBLE_MAX + 1);
	}
	posPoint = str.find(".");
	if (posPoint != std::string::npos)
		nb /= powerOfTen(((static_cast<int>(str.size()) - 1) - posPoint));
	nb *= sign;
	return (nb);
}

char 		ldToA(long double nb)
{
	char convChar = 0;
	if (nb >= 32 && nb < 127)
		convChar = static_cast<char>(nb);

	return (convChar);
}

void		convertAndDisplay(long double nb)
{
	std::cout << RED << "nb double representation: " << std::fixed  << std::setprecision(8) << nb << END_C << std::endl; 
	std::cout << RED << "nb float representation: " << std::fixed  << std::setprecision(8) << static_cast<float>(nb) << END_C << std::endl; 

	char convChar = ldToA(nb);
	if (convChar != 0)
		std::cout << "char: " << convChar << std::endl;
	else
		std::cout << "char: " << "non displayable" << std::endl;
	if (nb > INT_MAX)
			std::cout << "int: " << "+inf"<< std::endl;
		else if (nb < INT_MIN)
			std::cout << "int: " << "-inf"<< std::endl;
		else
		{
			int convInt = nb;
			std::cout << "int: " << convInt << std::endl;
		}
		if (nb > FLOAT_MAX)
			std::cout << "float: " << "+inf"<< std::endl;
		else if (nb < FLOAT_TRUE_MIN)
			std::cout << "float: " << "-inf"<< std::endl;
		else
		{	
			float convFloat = nb;
			std::cout << "float: "<< std::fixed  << std::setprecision(8) << convFloat << "f" << std::endl;
		}
		if (nb > DOUBLE_MAX)
			std::cout << "double: " << "+inf"<< std::endl;
		else if (nb < DOUBLE_TRUE_MIN)
			std::cout << "double: " << "-inf"<< std::endl;
		else
		{
			double convDouble = nb;
			std::cout << "double: "<< std::fixed  << std::setprecision(8) << convDouble << std::endl;
		}
		return ;
}