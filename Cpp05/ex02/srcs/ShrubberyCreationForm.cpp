/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbouguet <lucasbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 01/04/2024 10:55:34 by lucasbouguet          #+#    #+#             */
/*   Updated: 01/04/2024 10:55:34 by lucasbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/base.hpp"

//-------------------- funcs ------------------------------------------------//
void	ShrubberyCreationForm::execute(Bureaucrat const &executor)
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
ShrubberyCreationForm::ShrubberyCreationForm(std::string &target) :  AForm(target + "_shrubbery", 145, 137)
{
	std::cout << "Default constructor called for ShrubberyCreationForm" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
{
	std::cout << "Copy constructor called for ShrubberyCreationForm" << std::endl;
	return ;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & instance)
{
	std::cout << "Assignment operator called for ShrubberyCreationForm" << std::endl;
	if (this != &instance)
	{

	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called for ShrubberyCreationForm" << std::endl;
	return ;
}


