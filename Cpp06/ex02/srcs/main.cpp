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

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../incs/Base.hpp"
#include "../incs/A.hpp"
#include "../incs/B.hpp"
#include "../incs/C.hpp"

//#include "../incs/funcs.hpp"

Base *generate(void)
{
	srand(static_cast<unsigned int>(time(0)));
	int rdmNumb = rand() % 3;
	std::cout << "rdmNumb: " << rdmNumb << std::endl;
	if (rdmNumb == 0)
		return (new A);
	else if (rdmNumb == 1)
		return (new B);
	else if (rdmNumb == 2)
		return (new C);
	return (NULL);
}

void identify(Base* p)
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

void identify(Base& p) 
{
    try 
	{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } 
	catch (const std::exception &ex) {}
    try 
	{
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } 
	catch (const std::exception &ex) {}
    try 
	{
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } 
	catch (const std::exception &ex) {}
    std::cout << "Unknown class" << std::endl;
}

int	main()
{
	{
		//Base base;
		Base *ptr = NULL;

		(void)ptr;
		ptr = generate();
		if (ptr)
		{	
			identify(ptr);
			delete ptr;
		}
	}
	{
		std::cout << std::endl;
		//Base base;
		Base *ptr = NULL;

		(void)ptr;
		ptr = generate();
		if (ptr)
		{	
			identify(ptr);
			delete ptr;
		}
	}
	return (0);
}


