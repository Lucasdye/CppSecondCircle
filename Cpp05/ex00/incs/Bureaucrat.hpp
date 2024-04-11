/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2029/03/20 10:54:43 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/11 14:09:20 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

//----- Constants
# include "colors.hpp"
# ifndef SUC
#  define SUC 0
# endif
# ifndef ERR
#  define ERR -1
# endif

//----- Cpp library headers
# include <iostream>
# include <exception>

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		//-------------------- funcs ----------------------------------------//
		void					incrGrade();
		void					decrGrade();

		//-------------------- Set/get --------------------------------------//
		std::string				getName() const;
		int						getGrade() const;

		//-------------------- Constructor/Destructor -----------------------//
	    Bureaucrat();
	    Bureaucrat(std::string name, int grade);
	    Bureaucrat(Bureaucrat const & src);
	    ~Bureaucrat();

		//-------------------- Operators ------------------------------------//
	    Bureaucrat& operator=(Bureaucrat const & instance);
		
		//-------------------- Exceptions ------------------------------------//
		class	GradeTooHighException: public std::exception
		{
			public :
				//------------ funcs -----------//
				virtual const char* what() const throw();// the throw() indicated that this method shouldn't throw any exceptions !
		};

		class	GradeTooLowException: public std::exception
		{
			public :
				//------------ funcs -----------//
				virtual const char* what() const throw();// the throw() indicated that this method shouldn't throw any exceptions !
		};
};

std::ostream&   operator<<(std::ostream& out, const Bureaucrat& inst);

#endif

