/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbouguet <lucasbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 08/04/2024 09:37:57 by lucasbouguet          #+#    #+#             */
/*   Updated: 08/04/2024 09:37:57 by lucasbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Serializer.hpp"

int	main()
{
	{
	float 			f = 1.5;
	int				i = 0;

	i = f;
	std::cout << "i1 = " << i  << std::endl;
	i = reinterpret_cast<uintptr_t>(&f);
	std::cout << "i2 = " << i << std::endl;
	}
	{
		std::cout << std::endl;
		Data			*data;
		Data			*dataBack = NULL;
		uintptr_t		uintptr;

		data = new Data;
		std::cout << "data addr: " << data << std::endl;
		uintptr = Serializer::serialize(data);
		std::cout << "uintptr value: " << uintptr << std::endl;
		std::cout << std::endl;

		(void)dataBack;
		dataBack = Serializer::deserialize(uintptr);
		std::cout << "dataBack addr: " << data << std::endl;
		delete data;
	}
	return (SUC);
}


