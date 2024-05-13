/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbouguet <lucasbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 30/03/2024 18:25:16 by lucasbouguet          #+#    #+#             */
/*   Updated: 30/03/2024 18:25:16 by lucasbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Form.hpp"

//-------------------- funcs ------------------------------------------------//
void	Form::beSigned(Bureaucrat& bur)
{
	if (bur.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	else
		_isSigned = true;
}

//-------------------- Set/Get ----------------------------------------------//
std::string 		Form::getName() const
{
	return (_name);
}

int					Form::getSignGrade() const
{
	return (_signGrade);
}

int					Form::getExecGrade() const
{
	return (_execGrade);
}

bool				Form::getIsSigned() const
{
	return (_isSigned);
}

//-------------------- Constructor/Destructor -------------------------------//
Form::Form(): _name("noNameForm"), _isSigned(false), _signGrade(1), _execGrade(1)
{
	std::cout << "Default constructor called for Form" << std::endl;
	return ;
}

Form::Form(std::string name, int signGrade, int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "Parametric constructor called for Form" << std::endl;
	if (_signGrade > 150)
		throw Form::GradeTooLowException();
	else if (_signGrade < 1)
		throw Form::GradeTooHighException();
	if (_execGrade > 150)
		throw Form::GradeTooLowException();
	else if (_execGrade < 1)
		throw Form::GradeTooHighException();
	return ;
}

Form::Form(Form const& src): _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	std::cout << "Copy constructor called for Form" << std::endl;
	return ;
}

Form::~Form()
{
	std::cout << "Destructor called for Form" << std::endl;
	return ;
}

//-------------------- Exceptions -------------------------------------------//
const char	*Form::GradeTooHighException::what() const throw()
{
	return ("The grade's too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("The grade's too low");
}

//-------------------- Operators --------------------------------------------//
std::ostream&   operator<<(std::ostream& out, const Form& inst)
{
	out << BOLD << "Form " << inst.getName() << " signing" << "'s grade's " <<  inst.getSignGrade() << " and execution's grade's " << inst.getExecGrade() << "." << std::endl << "This form statu's " << inst.getIsSigned() << "." <<END_C << std::endl;
	return (out);
}

Form&	Form::operator=(Form const& instance)
{
	std::cout << "Assignment operator called for Form" << std::endl;
	if (this != &instance)
	{
		_isSigned = instance._isSigned;
	}
	return *this;
}



