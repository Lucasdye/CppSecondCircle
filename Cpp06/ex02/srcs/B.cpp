/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbouguet <lucasbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 08/04/2024 11:03:17 by lucasbouguet          #+#    #+#             */
/*   Updated: 08/04/2024 11:03:17 by lucasbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/B.hpp"

B::B(): Base()
{
	std::cout << "Default constructor called for B" << std::endl;
}

B::B(B const & src): Base(src)
{
	std::cout << "Copy constructor called for B" << std::endl;
	(void)src;
}

B&	B::operator=(B const & instance)
{
	std::cout << "Assignment operator called for B" << std::endl;
	if (this != &instance)
	{
		(void)instance;
	}
	return *this;
}

B::~B()
{
	std::cout << "Destructor called for B" << std::endl;
}


