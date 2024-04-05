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
// bool	ScalarConverter::checkIntOverflow(std::string &line)
// {
// 	if (line.size() > 10)
// 		return (true);
// 	else if (line.size() == 10)
// 	{	
// 		if (line.compare("2147483647") > 0)
// 			return (true);
// 	}
// 	return (false);
// }

// bool	ScalarConverter::checkIntUnderflow(std::string line)
// {
// 	line.erase(0, 1);// Erase from [0], how much ? 1.
// 	if (line.size() > 10)
// 		return (true);
// 	else if (line.size() == 10)
// 	{	
// 		if (line.compare("2147483648") > 0)
// 			return (true);
// 	}
// 	return (false);
// }


// bool ScalarConverter::strTypeCoherence(std::string &str)
// {
// 	size_t 		posSign;
// 	size_t 		posPoint;
// 	size_t 		posF;
// 	std::string	strCpy;
	
// 	strCpy = str;
// 	//---- Only affichable non numeric char
// 	if ((str[0] > 31 && str[0] < 48) || (str[0] > 57 && str[0] < 127))
// 	{
// 		// +
// 		// - 
// 		if ((str[0] == '+' || '-') && isOnlyNumeric(str))// numeric could sart by '+'
// 		{
			
// 		}
// 	}
// }

void ScalarConverter::convert(std::string &str)
{
	std::cout << BLUE << "CHECK" << 1 << END_C << std::endl;
	
	std::string	strCpy;
	double		nb = 0;
	int			sign = 1;
	size_t		posPoint = std::string::npos;
	
	if (str.size() == 1)
	{
		char convChar = str[0];
		std::cout << "char: " << convChar << std::endl;
		if (str[0] > 48 && str[0] < 57)
		{	
			int convInt = str[0] - 48;
			std::cout << "int: " << convInt << std::endl;
			float convFloat = str[0] - 48;
			std::cout << "float: "<< convFloat << std::endl;
			double convDouble = str[0] - 48;
			std::cout << "double: "<< convDouble << std::endl;
		}
		else
		{
			std::cout << "int: " << "nan" << std::endl;
			std::cout << "float: "<< "nan" << std::endl;
			std::cout << "double: "<< "nan" << std::endl;
		}
	}
	else if (str.size() < 40)// if the string is over 1, the str is a necessary a number and shouldn't contain an alphabetic char a part of one '.' '+' '-' 'f. 
	{
		//--- Parsing in one instruction
		if (str.find('-', 1) == std::string::npos && str.find('+', 1) == std::string::npos
			&& str.find('.') != 0 && str.find('.') != (str.size() - 1)
			&& str.find('.', str.find('.') + 1) == std::string::npos)
		{
			for (int i = 0; str[i]; i++)
			{
				if (str[i] >= 48 && str[i] <= 57)
					nb = nb * 10 + (str[i] - 48);
				if (str[i] == '-')
					sign *= -1;
			}
			nb *= sign;
			//---- Traitement de nb
			if (nb >= 32 && nb < 127)
			{	
				char convChar = nb;
				std::cout << "char: " << convChar << std::endl;
			}
			else
				std::cout << "char: " << "non displayable" << std::endl;
			posPoint = str.find(".");
			if (posPoint != std::string::npos)
				nb /= myPower(10, (((static_cast<int>(str.size()) - 2) - posPoint) ));
			int convInt = nb;
			std::cout << "int: " << convInt << std::endl;
			float convFloat = nb;
			std::cout << "float: "<< convFloat << std::endl;
			double convDouble = nb;
			std::cout << "double: "<< convDouble << std::endl;
			std::cout << "Nb: " << nb << std::endl;
		}
		else
		{
   			std::cout << "char: " << "nan" << std::endl;
			std::cout << "int: " << "nan" << std::endl;
    		std::cout << "float: "<< "nan" << std::endl;
			std::cout << "double: "<< "nan" << std::endl;
		}
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



