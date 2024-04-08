/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbouguet <lucasbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 08/04/2024 11:03:11 by lucasbouguet          #+#    #+#             */
/*   Updated: 08/04/2024 11:03:11 by lucasbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/baseH.hpp"

//-------------------- funcs ------------------------------------------------//
Base *Base::generate(void)
{
	srand(static_cast<unsigned int>(time(0)));
	int rdmNumb = rand() % 3;
	std::cout << "rdmNumb: " << rdmNumb << std::endl;
	if (rdmNumb == 0)
		return (new A());
	else if (rdmNumb == 1)
		return (new B());
	else if (rdmNumb == 2)
		return (new C());
	return (NULL);
}

void Base::identify(Base* p) 
{
    A* a = dynamic_cast<A*>(p);
    if (a) 
	{
        std::cout << "A" << std::endl;
        return;
    }
    B* b = dynamic_cast<B*>(p);
    if (b) 
	{
        std::cout << "B" << std::endl;
        return;
    }
    C* c = dynamic_cast<C*>(p);
    if (c) 
	{ 
        std::cout << "C" << std::endl;
        return;
    }
    std::cout << "Unknown class" << std::endl;
}

void Base::identify(Base& p) 
{
    try 
	{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } 
	catch (const std::bad_cast&) {}
    try 
	{
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } 
	catch (const std::bad_cast&) {}
    try 
	{
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } 
	catch (const std::bad_cast&) {}
    std::cout << "Unknown class" << std::endl;
}
//-------------------- Set/Get ----------------------------------------------//
//-------------------- Constructor/Destructor -------------------------------//
Base::Base()
{
	std::cout << "Default constructor called for Base" << std::endl;
}

Base::Base(Base const & src)
{
	std::cout << "Copy constructor called for Base" << std::endl;
	(void)src;
}

Base::~Base()
{
	std::cout << "Destructor called for Base" << std::endl;
}
//-------------------- Operators --------------------------------------------//
//-------------------- Exceptions -------------------------------------------//
Base&	Base::operator=(Base const & instance)
{
	std::cout << "Assignment operator called for Base" << std::endl;
	if (this != &instance)
	{
		(void)instance;
	}
	return *this;
}





