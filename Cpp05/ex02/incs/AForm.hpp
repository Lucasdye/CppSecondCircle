/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbouguet <lucasbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 30/03/2024 18:25:16 by lucasbouguet          #+#    #+#             */
/*   Updated: 30/03/2024 18:25:16 by lucasbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

//----- Constants
# include "colors.hpp"
# ifndef SUC
#  define SUC 0
# endif

# ifndef ERR
#  define ERR -1
# endif

//----- Class headers
# include "Bureaucrat.hpp"

//----- Cpp library headers
# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{
	private:
		std::string const 	_name;
		bool				_isSigned;
		int			const 	_signGrade;
		int 		const 	_execGrade;

	public:
		//-------------------- funcs --------------------------------------------//
		void				beSigned(Bureaucrat& bur);
		void virtual		execute(Bureaucrat const & executor) const = 0;
		//-------------------- Set/get ------------------------------------------//
		std::string 		getName() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		bool				getIsSigned() const;
		//-------------------- Constructor/Destructor ---------------------------//
	    AForm();
	   	AForm(AForm const & src);
		AForm(std::string name, int signGrade, int execGrade);
	    virtual ~AForm();
		//-------------------- Operators ----------------------------------------//
	    AForm& operator=(AForm const & instance);
		//-------------------- Exceptions ---------------------------------------//
		class	GradeTooHighException: public std::exception
		{
			public :
				const char *what() const throw ();
		};

		class	GradeTooLowException: public std::exception
		{
			public :
				const char *what() const	throw();
		};
};

std::ostream&   operator<<(std::ostream& out, const AForm& inst);
#endif

