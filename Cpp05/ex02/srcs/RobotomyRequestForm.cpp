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
	AForm::execute(executor);
	srand(static_cast<unsigned int>(time(0)));
	int rdmNumb = rand() % 101;
	if (rdmNumb < 50)
		std::cout << "TRRrrrRRrrrRRrrrrrrrRRRRRRRRRrrRR" << std::endl;
	else 
		std::cout << "Robotomy has failed" << std::endl;
	return ;
}
//-------------------- Set/Get ----------------------------------------------//
//-------------------- Constructor/Destructor -------------------------------//
//-------------------- Operators --------------------------------------------//
//-------------------- Exceptions -------------------------------------------//

RobotomyRequestForm::RobotomyRequestForm() : AForm()
{
	std::cout << "Default constructor called for RobotomyRequestForm" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string &target) : AForm(target, 72, 45)
{
	std::cout << "Parametric constructor called for PresidentialPardonForm" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
{
	std::cout << "Copy constructor called for RobotomyRequestForm" << std::endl;
	return ;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const & instance)
{
	std::cout << "Assignment operator called for RobotomyRequestForm" << std::endl;
	if (this != &instance)
	{
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called for RobotomyRequestForm" << std::endl;
	return ;
}


