/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbouguet <lucasbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 08/04/2024 11:03:19 by lucasbouguet          #+#    #+#             */
/*   Updated: 08/04/2024 11:03:19 by lucasbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/baseH.hpp"

C::C(): Base()
{
	std::cout << "Default constructor called for C" << std::endl;
}

C::C(C const & src): Base(src)
{
	std::cout << "Copy constructor called for C" << std::endl;
	(void)src;
}

C&	C::operator=(C const & instance)
{
	std::cout << "Assignment operator called for C" << std::endl;
	if (this != &instance)
	{
		(void)instance;
	}
	return *this;
}

C::~C()
{
	std::cout << "Destructor called for C" << std::endl;
}


