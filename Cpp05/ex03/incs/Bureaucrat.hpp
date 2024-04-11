/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2029/03/20 10:54:43 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/10 16:54:12 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

//----- Constants
# ifndef SUC
#  define SUC 0
# endif
# ifndef ERR
#  define ERR -1
# endif
# include "colors.hpp"

//----- Class headers
# include "Form.hpp"
# include "Bureaucrat.hpp"

//----- CPP library headers
# include <string>

class Form;

class Bureaucrat
{
	private:
		std::string _name;
		int 		_grade;

	public:

		//-------------------- funcs ----------------------------------------//
		void					incrGrade();
		void					decrGrade();
		void					signForm(Form&	f);
		void					executeForm(Form const & form);
		
		//-------------------- Set/get --------------------------------------//
		std::string				getName() const;
		int						getGrade() const;

		//-------------------- Constructor/Destructor -----------------------//
	    						Bureaucrat();
	    						Bureaucrat(std::string name, int grade);
	    						Bureaucrat(Bureaucrat const & src);
	    						~Bureaucrat();

		//-------------------- Operators ------------------------------------//
	    Bureaucrat& 			operator=(Bureaucrat const & instance);
		
		//-------------------- Exceptions ------------------------------------//
		class	GradeTooHighException: public std::exception
		{
			public :
				//------------ funcs -----------//
				virtual const char* what() const throw();// the throw() indicated that this method shouldn't 
		};												 //throw any exceptions !
		
		class	GradeTooLowException: public std::exception
		{
			public :
				//------------ funcs -----------//
				virtual const char* what() const throw();
		};
};

std::ostream&   operator<<(std::ostream& out, const Bureaucrat& inst);

#endif

