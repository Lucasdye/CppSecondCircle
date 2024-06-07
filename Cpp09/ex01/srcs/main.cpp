/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:24:35 by lbouguet          #+#    #+#             */
/*   Updated: 2024/05/17 17:22:07 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/RPN.hpp"

int main(int ac, char **av)
{
	Rpn			Rpn;
	double 		res = 0;
	std::string str;

	if (ac < 1)
		std::cout << "ERROR: " << "invalid argument" << std::endl;
	
	for (size_t i = 1; av[i] != NULL; i++)
	{	
		str += av[i];
		str += " ";
	}
	std::cout << str << "\n";
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (Rpn.getObjS().size() < 2)
				std::cout << "ERROR: " << "not enough numbers to do the arithmetic" << std::endl;
			else
			{
				int nb1;
				int nb2;
				if (str[i] == '+')
				{
					nb1 = Rpn.getObjS().top();
					Rpn.getObjS().pop();
					nb2 = Rpn.getObjS().top();
					Rpn.getObjS().pop();
					res = nb1 + nb2;
					if (res > std::numeric_limits<int>::max() || res < std::numeric_limits<int>::min())
					{
						std::cout << "ERROR: int max or int min" << std::endl;
						return -1;
					}
					Rpn.getObjS().push(static_cast<int>(res));
				}
				if (str[i] == '-')
				{
					nb1 = Rpn.getObjS().top();
					Rpn.getObjS().pop();
					nb2 = Rpn.getObjS().top();
					Rpn.getObjS().pop();
					res = nb2 - nb1;
					if (res > std::numeric_limits<int>::max() || res < std::numeric_limits<int>::min())
					{
						std::cout << "ERROR: int max or int min" << std::endl;
						return -1;
					}
					Rpn.getObjS().push(static_cast<int>(res));
				}
				if (str[i] == '*')
				{	
					nb1 = Rpn.getObjS().top();
					Rpn.getObjS().pop();
					nb2 = Rpn.getObjS().top();
					Rpn.getObjS().pop();
					res = nb1 * nb2;
					if (res > std::numeric_limits<int>::max() || res < std::numeric_limits<int>::min())
					{
						std::cout << "ERROR: int max or int min" << std::endl;
						return -1;
					}
					Rpn.getObjS().push(static_cast<int>(res));
				}
				if (str[i] == '/' )
				{
					nb1 = Rpn.getObjS().top();
					Rpn.getObjS().pop();
					nb2 = Rpn.getObjS().top();
					Rpn.getObjS().pop();
					if (nb1 == 0 || nb2 == 0)
					{
						std::cout << "ERROR: division by 0" << std::endl;
						return 0;
					}
					res = nb2 / nb1;
					if (res > std::numeric_limits<int>::max() || res < std::numeric_limits<int>::min())
					{
						std::cout << "ERROR: int max or int min" << std::endl;
						return -1;
					}
					Rpn.getObjS().push(static_cast<int>(res));
				}
			}
		}
		if (str[i] >= 48 && str[i] <= 57)
		{
			if (i < (str.size() - 1) && (str[i + 1] >= 48 && str[i + 1] <= 57))
			{	
				std::cout << "ERROR: " << "all number value should be between 0 and 9" << std::endl;
				return -1;
			}
			else
				Rpn.getObjS().push(str[i] - 48);
		}
	}
	if (Rpn.getObjS().size() > 1)
			std::cout << "ERROR: " << "not enough arithmetic operators" << std::endl;
	else
		std::cout << Rpn.getObjS().top() << std::endl;
	return (0);
}