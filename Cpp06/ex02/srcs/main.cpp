/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbouguet <lucasbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 08/04/2024 11:03:11 by lucasbouguet          #+#    #+#             */
/*   Updated: 08/04/2024 11:03:11 by lucasbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Base.hpp"


int	main()
{
	{
		Base base;
		Base *ptr = NULL;

		(void)ptr;
		ptr = base.generate();
		if (ptr)
		{	
			ptr->identify(ptr);
			delete ptr;
		}
	}
	{
		std::cout << std::endl;
		Base base;
		Base *ptr = NULL;

		(void)ptr;
		if (ptr)
		{	
			ptr = base.generate();
			Base& ref = *ptr;

			ref.identify(ref);
			delete ptr;
		}
	}
	return (0);
}


