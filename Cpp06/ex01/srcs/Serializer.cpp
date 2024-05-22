/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbouguet <lucasbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 08/04/2024 09:37:57 by lucasbouguet          #+#    #+#             */
/*   Updated: 08/04/2024 09:37:57 by lucasbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Serializer.hpp"

//-------------------- funcs ------------------------------------------------//
uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t uintptrValue = 0;

	if (ptr)
		uintptrValue = reinterpret_cast<uintptr_t>(ptr);
	return (uintptrValue);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *data;

	data = reinterpret_cast<Data*>(raw);
	if (data == NULL)
		return ((void)(std::cout << "Fail reinterpret cast" << std::endl), data);
	return (data);
}

//-------------------- Set/Get ----------------------------------------------//
//-------------------- Constructor/Destructor -------------------------------//
Serializer::Serializer()
{
	std::cout << "Default constructor called for Serializer" << std::endl;
}

Serializer::Serializer(Serializer const & src)
{
	std::cout << "Copy constructor called for Serializer" << std::endl;
	(void)src;
}

Serializer::~Serializer()
{
	std::cout << "Destructor called for Serializer" << std::endl;
}
//-------------------- Operators --------------------------------------------//
Serializer&	Serializer::operator=(Serializer const & instance)
{
	std::cout << "Assignment operator called for Serializer" << std::endl;
	if (this != &instance)
	{
		(void)instance;
	}
	return *this;
}
//-------------------- Exceptions -------------------------------------------//



