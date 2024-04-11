/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbouguet <lucasbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 08/04/2024 11:03:15 by lucasbouguet          #+#    #+#             */
/*   Updated: 08/04/2024 11:03:15 by lucasbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/A.hpp"

A::A(): Base()
{
	std::cout << "Default constructor called for A" << std::endl;
}

A::A(A const & src): Base(src)
{
	std::cout << "Copy constructor called for A" << std::endl;
	(void)src;
}

A&	A::operator=(A const & instance)
{
	std::cout << "Assignment operator called for A" << std::endl;
	if (this != &instance)
	{
		(void)instance;
	}
	return *this;
}

A::~A()
{
	std::cout << "Destructor called for A" << std::endl;
}


