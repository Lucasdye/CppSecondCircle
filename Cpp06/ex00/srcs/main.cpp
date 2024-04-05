/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2004/04/20 17:44:20 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/05 12:38:28 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ScalarConverter.hpp"

int	main(int ac, char **argv)
{
	std::string str;

	if (ac != 2)
		return (ERR);
	std::cout << BLUE << "CHECK" << 0 << END_C << std::endl;
	str = argv[1];
	ScalarConverter::convert(str);	
	return (0);
}


