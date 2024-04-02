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

	if (getIsSigned())
	{	
		AForm::execute(executor);
		std::string fileName = AForm::getName();
		std::ofstream outfile;
		outfile.open(fileName.c_str());
    	if(outfile.is_open()) 
		{
    	    outfile <<  "\t                      @@@@@@ \n"
						"\t                    ooooo@OOOo\n"
						"\t                 @ ooooOO|Oooooo@o@\n"
						"\t                \\OOOOoo@o|oOooo0o/ooo\n"
						"\t            @ooooO\\OOoooo|oOooo0/0oooo00o\n"
						"\t           o\\oo0oooo@OOO@|ooOoo/o0oooo00ooo\n"
						"\t           oo\\o0ooooO\\OOO|@oo/ooo0o0@ooo00ooo\n"
						"\t            -----------\\OOO|/ooo0o-----------\n"
						"\t                     @\\OOO|/\n"
						"\t                     @\\||||||@\n"
						"\t                      \\///\\\\\\\n"

						 << std::endl; // Example, replace with actual ASCII art
    	    outfile.close();
			std::cout << BOLD << "The Form " << AForm::getName() << " was successfully executed by " << executor.getName() << END_C << std::endl;
    	}
	}
	else
		std::cout << MAGENTA << BOLD << "The form wasn't signed, the bureaucrat could not execute his mission." << END_C << std::endl;
	return ;
}

//-------------------- Set/Get ----------------------------------------------//
//********************* In Abstract *****************************************//

//-------------------- Constructor/Destructor -------------------------------//
ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
	std::cout << ITALIC << "Default constructor called for ShrubberyCreationForm " << AForm::getName() << END_C << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string& target): AForm(target + "_shrubbery", 145, 137)
{
	std::cout << ITALIC << "Parametric constructor called for ShrubberyCreationForm " << AForm::getName() << END_C << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
	std::cout << ITALIC << "Copy constructor called for ShrubberyCreationForm " << AForm::getName() << END_C << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << ITALIC << "Destructor called for ShrubberyCreationForm " << AForm::getName() << END_C << std::endl;
	return ;
}

//-------------------- Exceptions -------------------------------------------//
//******************** Managed in Abstract **********************************//

//-------------------- Operators --------------------------------------------//
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & instance)
{
	std::cout << "Assignment operator called for ShrubberyCreationForm" << std::endl;
	if (this != &instance)
	{
		AForm::operator=(instance);
	}
	return *this;
}

