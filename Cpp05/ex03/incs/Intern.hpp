/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2002/04/20 19:42:09 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/10 16:54:21 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

//----- Constants
# include "colors.hpp"
# ifndef SUC
#  define SUC 0
# endif
# ifndef ERR
#  define ERR -1
# endif

//----- Class headers
# include "Form.hpp" 
# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

//----- CPP library headers
# include <string>

class Intern
{
	private:
		Form *makePresid(std::string &name);
		Form *makeRobot(std::string &name);
		Form *makeShrubb(std::string &name);
		
		typedef struct 	createFormStruc_s
		{
			std::string formType;
			Form *(Intern::*ptrMethod)(std::string &name);
			
		}				createFormStruc_t;
		createFormStruc_t maker[3];

	public:
		//-------------------- funcs --------------------------------------------//
		Form	*makeForm(char const *name, char const *target);

		//-------------------- Set/get ------------------------------------------//
		//-------------------- Constructor/Destructor ---------------------------//
	    
		Intern();
	    Intern(Intern const & src);
	    ~Intern();
		//-------------------- Operators ----------------------------------------//
	    
		Intern& operator=(Intern const & instance);
};

#endif

