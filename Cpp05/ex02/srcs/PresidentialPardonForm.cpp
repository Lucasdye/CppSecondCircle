/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbouguet <lucasbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 01/04/2024 10:56:11 by lucasbouguet          #+#    #+#             */
/*   Updated: 01/04/2024 10:56:11 by lucasbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PresidentialPardonForm.hpp"

//-------------------- funcs ------------------------------------------------//
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned())
	{
		AForm::execute(executor);
		std::cout << BOLD << executor.getName() << " has been pardoned by Zaphod Beeblebrox" << END_C <<std::endl;
	}
	else
		std::cout << MAGENTA << BOLD << "The form wasn't signed, the bureaucrat could not execute his mission." << END_C << std::endl;
	return ;

}

//-------------------- Set/Get ----------------------------------------------//
//********************* In Abstract *****************************************//

//-------------------- Constructor/Destructor -------------------------------//
PresidentialPardonForm::PresidentialPardonForm(std::string &target): AForm(target, 25, 5)
{
	std::cout << ITALIC <<"Parametric constructor called for PresidentialPardonForm" << getName() << END_C << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{
	std::cout << ITALIC <<"Default constructor called for PresidentialPardonForm" << getName() << END_C << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src)
{
	std::cout << ITALIC <<"Copy constructor called for PresidentialPardonForm" << getName() << END_C << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << ITALIC << "Destructor called for PresidentialPardonForm" << getName() << END_C << std::endl;
	return ;
}

//-------------------- Operators --------------------------------------------//
PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const & instance)
{
	std::cout << ITALIC << "Assignment operator called for PresidentialPardonForm" << getName() << END_C << std::endl;
	if (this != &instance)
	{
		AForm::operator=(instance);
	}
	return *this;
}

//-------------------- Exceptions -------------------------------------------//
//******************** Managed in Abstract **********************************//


