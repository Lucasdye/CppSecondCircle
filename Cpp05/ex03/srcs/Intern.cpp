/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2002/04/20 19:42:09 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/04 16:02:42 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/base.hpp"

//-------------------- funcs ------------------------------------------------//
Form	*Intern::makeForm(char const *name,  char const *target)
{
	std::string  strTar(target);
	std::string  strNam(name);
	
	std::cout << "name " << strNam << std::endl;
	std::cout << "target " << strTar << std::endl;
	for (int i = 0; i < 3; i++)
	{
		if (maker[i].formType == strNam)
			   return (this->*(maker[i].ptrMethod))(strTar); // This is necessary cause ptrMethod points to member funcs
	}
	return (NULL);
}

//-------------------- Set/Get ----------------------------------------------//
//-------------------- Constructor/Destructor -------------------------------//
Intern::Intern()
{
	std::cout << "Default constructor called for Intern" << std::endl;
	maker[0].formType = "presidential pardon";
	maker[0].ptrMethod = &Intern::makePresid;
	
	maker[1].formType = "robotomy request";
	maker[1].ptrMethod = &Intern::makeRobot;
	
	maker[2].formType = "Shrubb request";
	maker[2].ptrMethod = &Intern::makeShrubb;
}

Form *Intern::makePresid(std::string &name)
{
	std::cout << BOLD << "In makePresid " << END_C << std::endl;
	return (new PresidentialPardonForm(name));
}

Form *Intern::makeRobot(std::string &name)
{
	return (new RobotomyRequestForm(name));
}

Form *Intern::makeShrubb(std::string &name)
{
	return (new ShrubberyCreationForm(name));
}

Intern::Intern(Intern const & src)
{
	static_cast<void>(src);
	std::cout << "Copy constructor called for Intern" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Destructor called for Intern" << std::endl;
}
//-------------------- Operators --------------------------------------------//

Intern&	Intern::operator=(Intern const &instance)
{
	std::cout << "Assignment operator called for Intern" << std::endl;
	
	static_cast<void>(instance);
	if (this != &instance)
	{
		//---------- Nothing to cpy -----------------------------------------//
	}
	return *this;
}

//-------------------- Exceptions -------------------------------------------//



