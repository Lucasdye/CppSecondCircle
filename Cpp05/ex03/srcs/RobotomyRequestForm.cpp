/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbouguet <lucasbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 01/04/2024 10:55:55 by lucasbouguet          #+#    #+#             */
/*   Updated: 01/04/2024 10:55:55 by lucasbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/RobotomyRequestForm.hpp"

//-------------------- funcs ------------------------------------------------//
void	RobotomyRequestForm::execute(Bureaucrat const &executor)
{
	if (getIsSigned())
	{
		AForm::execute(executor);
		srand(static_cast<unsigned int>(time(0)));
		int rdmNumb = rand() % 101;
		if (rdmNumb < 50)
			std::cout << BOLD << "TRRrrrRRrrrRRrrrrrrrRRRRRRRRRrrRR" << END_C << std::endl;
		else 
			std::cout << BOLD << "Robotomy has failed" << END_C << std::endl;
	}
	else
		std::cout << MAGENTA << BOLD << "The form wasn't signed, the bureaucrat could not execute his mission." << END_C << std::endl;
	return ;
}

//-------------------- Operators --------------------------------------------//

//-------------------- Set/Get ----------------------------------------------//
//********************* In Abstract *****************************************//

//-------------------- Constructor/Destructor -------------------------------//
RobotomyRequestForm::RobotomyRequestForm() : AForm()
{
	std::cout << ITALIC <<  "Default constructor called for RobotomyRequestForm " << AForm::getName() << END_C << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string &target) : AForm(target, 72, 45)
{
	std::cout << ITALIC <<  "Parametric constructor called for PresidentialPardonForm " << AForm::getName() << END_C << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src): AForm(src)
{
	std::cout << ITALIC <<  "Copy constructor called for RobotomyRequestForm " << AForm::getName() << END_C << std::endl;
	return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & instance)
{
	std::cout << ITALIC <<  "Assignment operator called for RobotomyRequestForm " << AForm::getName() << END_C << std::endl;
	if (this != &instance)
	{	
		AForm::operator=(instance);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << ITALIC <<  "Destructor called for RobotomyRequestForm" << AForm::getName() << END_C << std::endl;
	return ;
}

//-------------------- Exceptions -------------------------------------------//
//******************** Managed in Abstract **********************************//
