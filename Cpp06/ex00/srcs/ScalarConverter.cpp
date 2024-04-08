/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2004/04/20 17:44:20 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/05 17:07:05 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/base.hpp"

//-------------------- funcs ------------------------------------------------//
void ScalarConverter::convert(std::string &str)
{
	long double	nb = 0;

	 if (str.find('-', 1) == std::string::npos && str.find('+', 1) == std::string::npos
			&& str.find('.') != 0 && str.find('.') != (str.size() - 1)
			&& str.find('.', str.find('.') + 1) == std::string::npos
			&& (str.find('f') == (str.size() - 1) || str.find('f') == std::string::npos))
	{
		nb = strToLd(str);
		if (nb == DOUBLE_MAX + 1)
		{
			std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << "inf+" << std::endl;
			std::cout << "float: "<< "inf+" << std::endl;
			std::cout << "double: "<< "inf+" << std::endl;
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



