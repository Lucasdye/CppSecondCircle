/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2004/04/20 17:44:20 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/16 18:36:38 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScalarConverter.hpp"

int	main(int ac, char **argv)
{
	std::string str;
	double nb = std::numeric_limits<double>::max() * 1.01;

	std::cout << "DOUBLE MAIN " << std::fixed << std::setprecision(8) << nb << std::endl;
	std::cout << "VS" << std::endl;
	std::cout << std::fixed << std::setprecision(8) << std::numeric_limits<double>::max() << std::endl;
	
	std::cout << std::endl;
	if (ac != 2)
		return (ERR);
	std::cout << BLUE << "CHECK" << 0 << END_C << std::endl;
	str = argv[1];
	ScalarConverter::convert(str);	
	return (0);
}


