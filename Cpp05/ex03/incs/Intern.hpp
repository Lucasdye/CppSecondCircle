/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2002/04/20 19:42:09 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/02 20:18:30 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "base.hpp"


class Intern
{
	private:
		AForm	Intern::*ptrToSomeMethod (const std::string&);
		AForm	*makeShrubberyForm (std::string &name);
		// AForm	*makePresidentialForm (std::string &name);
		// AForm	*makeRobotomyForm (std::string &name);

	public:
	
		//-------------------- funcs --------------------------------------------//
		AForm	*makeForm(std::string name, AForm &target);
		//-------------------- Set/get ------------------------------------------//
		//-------------------- Constructor/Destructor ---------------------------//
	    Intern();
	    Intern(Intern const & src);
	    ~Intern();
		//-------------------- Operators ----------------------------------------//
	    Intern& operator=(Intern const & instance);
};

#endif

