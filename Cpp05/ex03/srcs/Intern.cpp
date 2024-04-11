/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2002/04/20 19:42:09 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/11 14:25:24 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Intern.hpp"

//-------------------- funcs ------------------------------------------------//
Form	*Intern::makeForm(char const *name,  char const *target)
{
	std::string  strTar(target);
	std::string  strNam(name);
	
	for (int i = 0; i < 3; i++)
	{
		if (maker[i].formType == strNam)
			   return (this->*(maker[i].ptrMethod))(strTar); // This is necessary cause ptrMethod points to member funcs
	}
	std::cout << "Invalid form type. The intern couldn't create the form." << std::endl;
	return (NULL);
}

Form 	*Intern::makePresid(std::string &name)
{
	return (new PresidentialPardonForm(name));
}

Form 	*Intern::makeRobot(std::string &name)
{
	return (new RobotomyRequestForm(name));
}

Form 	*Intern::makeShrubb(std::string &name)
{
	return (new ShrubberyCreationForm(name));
}

//-------------------- Set/Get ----------------------------------------------//
//-------------------- Constructor/Destructor -------------------------------//

Intern::Intern()
{
	std::cout << ITALIC << "Default constructor called for Intern" << END_C << std::endl;
	maker[0].formType = "presidential pardon";
	maker[0].ptrMethod = &Intern::makePresid;
	
	maker[1].formType = "robotomy request";
	maker[1].ptrMethod = &Intern::makeRobot;
	
	maker[2].formType = "Shrubb request";
	maker[2].ptrMethod = &Intern::makeShrubb;
}

Intern::Intern(Intern const & src)
{
	std::cout << ITALIC << "Copy constructor called for Intern" << END_C << std::endl;
	static_cast<void>(src);
}

Intern::~Intern()
{
	std::cout << ITALIC << "Destructor called for Intern" << END_C << std::endl;
}

//-------------------- Operators --------------------------------------------//
Intern&	Intern::operator=(Intern const &instance)
{
	std::cout << ITALIC << "Assignment operator called for Intern" << END_C << std::endl;
	
	static_cast<void>(instance);
	if (this != &instance)
	{
		//---------- Nothing to cpy -----------------------------------------//
	}
	return *this;
}

//-------------------- Exceptions -------------------------------------------//



