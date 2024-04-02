/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2002/04/20 19:42:09 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/02 20:16:38 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Intern.hpp"


//-------------------- funcs ------------------------------------------------//

Form	*Intern::makeForm(std::string name, AForm &target)
{
	
	
}
//-------------------- Set/Get ----------------------------------------------//
//-------------------- Constructor/Destructor -------------------------------//
Intern::Intern()
{
	ptrToSomeMethod = &Intern::makeShrubberyForm;
			
	std::cout << "Default constructor called for Intern" << std::endl;
}

Intern::Intern(Intern const & src)
{
	std::cout << "Copy constructor called for Intern" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Destructor called for Intern" << std::endl;
}
//-------------------- Operators --------------------------------------------//


Intern&	Intern::operator=(Intern const & instance)
{
	std::cout << "Assignment operator called for Intern" << std::endl;
	if (this != &instance)
	{
	}
	return *this;
}
//-------------------- Exceptions -------------------------------------------//



