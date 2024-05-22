/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2004/04/20 17:44:20 by lbouguet          #+#    #+#             */
/*   Updated: 2024/05/22 14:30:33 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScalarConverter.hpp"

//-------------------- Class static funcs ------------------------------------------//
void ScalarConverter::convert(std::string& str)
{
	long double	nb = 0;
	
	//single char
	if (str.size() == 1 && std::isprint(str[0]))
			convertAndDisplay(str[0]);
	else if (str.find('-', 1) == std::string::npos && str.find('+', 1) == std::string::npos
			&& str.find('.') != 0 /*&& str.find('.') != (str.size() - 1)*/
			&& str.find('.', str.find('.') + 1) == std::string::npos
			&& (str.find('f') == (str.size() - 1) || str.find('f') == std::string::npos)
			&& noAlphabet(str))
	{
		nb = strToLd(str);
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

double		ScalarConverter::powerOfTen(int power)
{
	double nb = 1;
	for (int i = 0; i < power; i++)
		nb *= 10;
	 return (nb);  
}

long double ScalarConverter::strToLd(std::string &str)
{
	long double	nb = 0;
	int			sign = 1;
	size_t		posPoint =  std::string::npos;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
			nb = nb * 10 + (str[i] - 48);
	}
	if (str.find("-") != std::string::npos)
		sign *= -1;
	posPoint = str.find(".");
	if (posPoint != std::string::npos && str.find('f') != std::string::npos)
		posPoint += 1;
	if (posPoint != std::string::npos /*&& !onlyZeroes()*/)
		nb /= powerOfTen(((static_cast<int>(str.size()) - 1) - posPoint));
	nb *= sign;
	return (nb);
}

char 		ScalarConverter::ldToA(long double nb)
{
	char convChar = 0;
	if (nb > 57 && nb < 127)
		convChar = static_cast<char>(nb);
	return (convChar);
}

bool	ScalarConverter::noAlphabet(std::string &str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != 'f' && str[i] != '.' && str[i] != '+' 
			&& str[i] != '-' && (str[i] < 48 || str[i] > 57))
			return (false);
	}
	return (true);
}

void		ScalarConverter::convertAndDisplay(long double nb)
{
	char convChar = ldToA(nb);
	//----- Char conv
	if (convChar)
		std::cout << "char: " << convChar << std::endl;
	else
		std::cout << "char: " << "non displayable" << std::endl;
		
	//----- Int conv
	if (nb > std::numeric_limits<int>::max())
			std::cout << "int: " << "int overflow"<< std::endl;
	else if (nb < std::numeric_limits<int>::min())
		std::cout << "int: " << "int underflow"<< std::endl;
	else
	{
		int convInt = static_cast<int>(nb);
		std::cout << "int: " << convInt << std::endl;
	}
	//----- Float conv
	if (nb > std::numeric_limits<float>::max())
		std::cout << "float: " << "+inff"<< std::endl;
	else if (nb < /*std::numeric_limits<float>::min()*/ -FLT_MAX)
		std::cout << "float: " << "-inff"<< std::endl;
	else
	{	
		float convFloat = static_cast<float>(nb);
		//std::cout << "float: "<< std::fixed  << std::setprecision(8) << convFloat << "f" << std::endl;
		std::cout << "float: " << convFloat << "f" << std::endl;
	}
	//----- Double conv
	if (nb > std::numeric_limits<double>::max())
		std::cout << "double: " << "+inf"<< std::endl;
	else if (nb < /*std::numeric_limits<double>::min()*/ -DBL_MAX)
		std::cout << "double: " << "-inf"<< std::endl;
	else
	{
		double convDouble = static_cast<double>(nb);
		//std::cout << "double: "<< std::fixed  << std::setprecision(8) << convDouble << std::endl;
		std::cout << "double: " << convDouble << std::endl;
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



