/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2004/04/20 17:44:20 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/10 18:33:16 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScalarConverter.hpp"

//-------------------- Class funcs ------------------------------------------//
void ScalarConverter::convert(std::string &str)
{
	long double	nb = 0;
	
	if (str.size() == 1)
	{
		char convChar;
		if ((str[0] > 31 && str[0] < 48) || (str[0] > 57 && str[0] < 127)) 
		{	
			convChar = str[0];
			std::cout << "char: " << convChar << std::endl;
		}
		else
			std::cout << "char: " << "non displayable" << std::endl;
		if (str[0] >= 48 && str[0] <= 57)
		{	
			nb = strToLd(str);
			int convInt = nb;
			std::cout << "int: " << convInt << std::endl;
			int convFloat = nb;
			std::cout << "float: " << convFloat << "f" << std::endl;
			double convDouble = nb;
			std::cout << "double: " << convDouble << std::endl;
		}
		else
		{
			std::cout << "int: " << "impossible" << std::endl;
    		std::cout << "float: "<< "nanf" << std::endl;
			std::cout << "double: "<< "nan" << std::endl;
		}
	}
	else if (str.find('-', 1) == std::string::npos && str.find('+', 1) == std::string::npos
			&& str.find('.') != 0 && str.find('.') != (str.size() - 1)
			&& str.find('.', str.find('.') + 1) == std::string::npos
			&& (str.find('f') == (str.size() - 1) || str.find('f') == std::string::npos)
			&& noAlphabet(str))
	{
		nb = strToLd(str);
		if (nb == DOUBLE_MAX + 1)
		{
			std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << "inf+" << std::endl;
			std::cout << "float: "<< "+inff" << std::endl;
			std::cout << "double: "<< "+inf" << std::endl;
		}
		else 
			convertAndDisplay(nb);
	}
	else
	{
   		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "nan" << std::endl;
    	std::cout << "float: "<< "nanf" << std::endl;
		std::cout << "double: "<< "nan" << std::endl;
	}
	return ;
}

//-------------------- Set/Get ----------------------------------------------//
//********************* No Set/Get ******************************************//
//-------------------- Constructor/Destructor -------------------------------//
ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called for ScalarConverter" << std::endl;
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	std::cout << "Copy constructor called for ScalarConverter" << std::endl;
	(void)src;
	return ;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called for ScalarConverter" << std::endl;
	return ;
}

//-------------------- Operators --------------------------------------------//
ScalarConverter&	ScalarConverter::operator=(ScalarConverter const & instance)
{
	std::cout << "Assignment operator called for ScalarConverter" << std::endl;
	(void)instance;
	if (this != &instance)
	{
	}
	return *this;
}

//-------------------- Exceptions -------------------------------------------//
//********************* No excpetions ***************************************//
//-------------------- Funcs 	- -------------------------------------------//

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

bool noAlphabet(std::string &str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != 'f' && str[i] != '.' && str[i] != '+' 
			&& str[i] != '-' && (str[i] < 48 || str[i] > 57))
			return (false);
	}
	return (true);
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
			std::cout << "int: " << "int overflow"<< std::endl;
	else if (nb < INT_MIN)
		std::cout << "int: " << "int underflow"<< std::endl;
	else
	{
		int convInt = nb;
		std::cout << "int: " << convInt << std::endl;
	}
	if (nb > FLOAT_MAX)
		std::cout << "float: " << "+inff"<< std::endl;
	else if (nb < - FLOAT_MAX)
		std::cout << "float: " << "-inff"<< std::endl;
	else
	{	
		float convFloat = nb;
		std::cout << "float: "<< std::fixed  << std::setprecision(8) << convFloat << "f" << std::endl;
	}
	if (nb > DOUBLE_MAX)
		std::cout << "double: " << "+inf"<< std::endl;
	else if (nb < - DOUBLE_MAX)
		std::cout << "double: " << "-inf"<< std::endl;
	else
	{
		double convDouble = nb;
		std::cout << "double: "<< std::fixed  << std::setprecision(8) << convDouble << std::endl;
	}
	return ;
}

