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
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned())
	{
		Form::execute(executor);
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
RobotomyRequestForm::RobotomyRequestForm() : Form()
{
	std::cout << ITALIC <<  "Default constructor called for RobotomyRequestForm " << Form::getName() << END_C << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string &target) : Form(target, 72, 45)
{
	std::cout << ITALIC <<  "Parametric constructor called for RobotomyRequestForm  " << Form::getName() << END_C << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src): Form(src)
{
	std::cout << ITALIC <<  "Copy constructor called for RobotomyRequestForm " << Form::getName() << END_C << std::endl;
	return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & instance)
{
	std::cout << ITALIC <<  "Assignment operator called for RobotomyRequestForm " << Form::getName() << END_C << std::endl;
	if (this != &instance)
	{	
		Form::operator=(instance);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << ITALIC <<  "Destructor called for RobotomyRequestForm" << Form::getName() << END_C << std::endl;
	return ;
}

//-------------------- Exceptions -------------------------------------------//
//******************** Managed in Abstract **********************************//
