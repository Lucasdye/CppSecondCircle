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

#include "../incs/ShrubberyCreationForm.hpp"

//-------------------- funcs ------------------------------------------------//
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{

	if (getIsSigned())
	{	
		Form::execute(executor);
		std::string fileName = Form::getName();
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
			std::cout << BOLD << "The Form " << Form::getName() << " was successfully executed by " << executor.getName() << END_C << std::endl;
    	}
	}
	else
		std::cout << MAGENTA << BOLD << "The form wasn't signed, the bureaucrat could not execute his mission." << END_C << std::endl;
	return ;
}

//-------------------- Set/Get ----------------------------------------------//
//********************* In Abstract *****************************************//

//-------------------- Constructor/Destructor -------------------------------//
ShrubberyCreationForm::ShrubberyCreationForm() : Form()
{
	std::cout << ITALIC << "Default constructor called for ShrubberyCreationForm " << Form::getName() << END_C << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string& target): Form(target + "_shrubbery", 145, 137)
{
	std::cout << ITALIC << "Parametric constructor called for ShrubberyCreationForm " << Form::getName() << END_C << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src)
{
	std::cout << ITALIC << "Copy constructor called for ShrubberyCreationForm " << Form::getName() << END_C << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << ITALIC << "Destructor called for ShrubberyCreationForm " << Form::getName() << END_C << std::endl;
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
		Form::operator=(instance);
	}
	return *this;
}

