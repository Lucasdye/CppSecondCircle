/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbouguet <lucasbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 30/03/2024 18:25:16 by lucasbouguet          #+#    #+#             */
/*   Updated: 30/03/2024 18:25:16 by lucasbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "base.hpp"

class Form
{
	private:
		std::string const 	_name;
		bool				_isSigned;
		int			const 	_signGrade;
		int 		const 	_execGrade;

	public:
		//-------------------- funcs --------------------------------------------//
		bool				beSigned(Bureaucrat& bur);
		//-------------------- Set/get ------------------------------------------//
		std::string 		getName() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		bool				getIsSigned() const;
		//-------------------- Constructor/Destructor ---------------------------//
	    Form();
	   	Form(Form const & src);
		Form::Form(std::string name, bool isSigned, int signGrade, int execGrade);
	    ~Form();
		//-------------------- Operators ----------------------------------------//
	    Form& operator=(Form const & instance);
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

#endif

