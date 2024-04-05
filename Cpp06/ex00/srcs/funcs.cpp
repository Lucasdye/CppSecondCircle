#include "../incs/funcs.hpp"

void 	draw_spaces(int nb)
{
	if (nb < 0)
		return ;
	for (int i = 0; i < nb; i++)
		std::cout << " ";
	return ;
}

bool	isOnlyNumeric(std::string str)
{
	if (str[0] == '-' || str[0] == '+')
		str.erase(0, 1);
	for (size_t i = 0; i < (size_t)str.size(); i++)
	{
		if (std::isdigit(str[i]) == false)
			return (false);
	}
	return (true);
}

bool	checkIntOverflow(std::string str)
{
	if (str[0] == '-' || str[0] == '+')
		str.erase(0, 1);
	if (str.size() > 10)
		return (true);
	else if (str.size() == 10)
	{	
		if (str.compare("2147483647") > 0)
			return (true);
	}
	return (false);
}

bool	checkIntUnderflow(std::string line)
{
	line.erase(0, 1);// Erase from [0], how much ? 1.
	if (line.size() > 10)
		return (true);
	else if (line.size() == 10)
	{	
		if (line.compare("2147483648") > 0)
			return (true);
	}
	return (false);
}

double	myPower(int nb, int power)
{
	for (int i = 0; power > 0 && i < power; i++)
		nb *= nb;
	return (nb);
}

