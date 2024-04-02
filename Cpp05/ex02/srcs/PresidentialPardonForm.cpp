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

#include "../incs/base.hpp"

//-------------------- funcs ------------------------------------------------//
void	PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	AForm::execute(executor);
	std::ofstream outfile(getName());
    if(outfile.is_open()) 
	{
        outfile << "SHRUBERRY" << std::endl; // Example, replace with actual ASCII art
        outfile.close();
    }
	return ;

}
//-------------------- Set/Get ----------------------------------------------//
//-------------------- Constructor/Destructor -------------------------------//
//-------------------- Operators --------------------------------------------//
//-------------------- Exceptions -------------------------------------------//

PresidentialPardonForm::PresidentialPardonForm(std::string &target) :
{
	std::cout << "Parametric constructor called for PresidentialPardonForm" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{
	std::cout << "Default constructor called for PresidentialPardonForm" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
{
	std::cout << "Copy constructor called for PresidentialPardonForm" << std::endl;
	return ;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const & instance)
{
	std::cout << "Assignment operator called for PresidentialPardonForm" << std::endl;
	if (this != &instance)
	{
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor called for PresidentialPardonForm" << std::endl;
	return ;
}


