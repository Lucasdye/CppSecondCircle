/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbouguet <lucasbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 30/03/2024 18:25:16 by lucasbouguet          #+#    #+#             */
/*   Updated: 30/03/2024 18:25:16 by lucasbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/base.hpp"

//-------------------- funcs ------------------------------------------------//
void	AForm::beSigned(Bureaucrat& bur)
{
	if (bur.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	else
		_isSigned = true;
}

void	AForm::execute(Bureaucrat const& executor)
{
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	return ;
}

//-------------------- Set/Get ----------------------------------------------//
std::string 		AForm::getName() const
{
	return (_name);
}

int					AForm::getSignGrade() const
{
	return (_signGrade);
}

int					AForm::getExecGrade() const
{
	return (_execGrade);
}

bool				AForm::getIsSigned() const
{
	return (_isSigned);
}


//-------------------- Constructor/Destructor -------------------------------//
AForm::AForm(): _name("noNameAForm"), _isSigned(0), _signGrade(1), _execGrade(1)
{
	std::cout << ITALIC << "Default constructor called for AForm " << _name << END_C << std::endl;
	return ;
}

AForm::AForm(std::string name, int signGrade, int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << ITALIC << "Parametric constructor called for AForm " << _name << END_C << std::endl;
	return ;
}

AForm::AForm(AForm const &src): _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	std::cout << ITALIC << "Copy constructor called for AForm " << _name << END_C << std::endl;
	return ;
}

AForm::~AForm()
{
	std::cout << ITALIC << "Destructor called for AForm " << _name << END_C << std::endl;
	return ;
}

//-------------------- Exceptions -------------------------------------------//
const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("The grade's too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("The grade's too low");
}

//-------------------- Operators --------------------------------------------//
std::ostream&   operator<<(std::ostream& out, const AForm& inst)
{
	out << BOLD << "AForm " << inst.getName() << " signing" << "'s grade's " <<  inst.getSignGrade() << " and execution's grade's " << inst.getExecGrade() << "." << std::endl << "This Aform statu's " << inst.getIsSigned() << "." <<END_C << std::endl;
	return (out);
}

AForm&	AForm::operator=(AForm const & instance)
{
	std::cout << "Assignment operator called for AForm" << std::endl;
	if (this != &instance)
	{
		_isSigned = instance._isSigned;
	}
	return *this;
}



