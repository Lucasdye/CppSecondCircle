/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbouguet <lucasbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 01/04/2024 10:55:55 by lucasbouguet          #+#    #+#             */
/*   Updated: 01/04/2024 10:55:55 by lucasbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

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

//----- CPP library headers
# include <iostream>
# include <string>
# include <cstdlib>

class Form; 

class RobotomyRequestForm : public Form
{
	private:

	public:
		//-------------------- funcs --------------------------------------------//
		void execute(Bureaucrat const &executor) const;
		//-------------------- Set/get ------------------------------------------//
		//-------------------- Constructor/Destructor ---------------------------//
	    RobotomyRequestForm();
	    RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm(std::string &target);
	    ~RobotomyRequestForm();
		//-------------------- Operators ----------------------------------------//
	    RobotomyRequestForm& operator=(RobotomyRequestForm const & instance);
};

#endif

