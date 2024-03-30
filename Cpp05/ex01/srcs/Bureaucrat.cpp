/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2029/03/20 10:54:43 by lbouguet          #+#    #+#             */
/*   Updated: 2024/03/29 17:59:19 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"

//-------------------- funcs ------------------------------------------------//
void	Bureaucrat::decrGrade()
{
	// No int overdeflow or overflow check needed (thanks to constructors)
	std::cout << ITALIC << "Incrementing " << _name << "'s gade" << END_C << std::endl;
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
	return ;
}

void	Bureaucrat::incrGrade()
{
	// No int undeflow or overflow check needed (thanks to constructors)
	std::cout << ITALIC << "Decrementing " << _name << "'s gade" << END_C << std::endl;
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
	return ;
}

void	Bureaucrat::signForm(Form& f)
{
	if (!f.beSigned(*this))
		std::cout << _name <<  " couldn’t sign " << f.getName() << Bureaucrat::GradeTooLowException().what() << std::endl;
	else
		std::cout << BLUE << "Bureaucrat signed " <<  f.getName() << std::endl;
	return ;
} 

//-------------------- Set/Get ----------------------------------------------//
std::string		Bureaucrat::getName() const
{
	return (_name);
}

int				Bureaucrat::getGrade() const
{
	return (_grade);
}

//-------------------- Constructor/Destructor -------------------------------//
Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << ITALIC << "Parametric constructor called for Bureaucrat " << _name <<  END_C << std::endl;
	if (_grade < 1)
	{
		_grade = 1;
		throw Bureaucrat::GradeTooHighException();
	}
	else if (_grade > 150)
	{
		_grade = 150;
		throw Bureaucrat::GradeTooLowException();
	}
	return ;
}

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
	std::cout << ITALIC << "Default constructor called for Bureaucrat " << _name << END_C << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	std::cout << ITALIC << "Copy constructor called for Bureaucrat " << _name << END_C << std::endl;
	_name = src._name;
	_grade = src._grade;
	return ;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << ITALIC << "Destructor called for Bureaucrat " << _name << END_C << std::endl;
	return ;
}
//-------------------- Operators --------------------------------------------//
Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & instance)
{
	std::cout << "Assignment operator called for Bureaucrat " << _name << std::endl;
	if (this != &instance)
	{
		_name = instance._name;
		_grade = instance._grade;
	}
	return *this;
}

std::ostream&   operator<<(std::ostream& out, const Bureaucrat& inst)
{
	out << BOLD << "Bureaucrat " << inst.getName() << "'s grade's " <<  inst.getGrade() << END_C << std::endl;
	return (out);
}

//-------------------- Exceptions -------------------------------------------//

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade's too high (highest is 1)");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade's too low (lowest is 150)");
}