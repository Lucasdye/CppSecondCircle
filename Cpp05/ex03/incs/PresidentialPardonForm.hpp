/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbouguet <lucasbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 01/04/2024 10:56:11 by lucasbouguet          #+#    #+#             */
/*   Updated: 01/04/2024 10:56:11 by lucasbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

//----- Constants
# ifndef SUC
#  define SUC 0
# endif

# ifndef ERR
#  define ERR -1
# endif

//----- Class headers
# include "colors.hpp"
# include "Form.hpp"
# include "Bureaucrat.hpp"

//----- CPP library headers
# include <iostream>
# include <string>

class PresidentialPardonForm : public Form
{
	private:

	public:
		//-------------------- funcs --------------------------------------------//
		void execute(Bureaucrat const &executor) const;
		//-------------------- Set/get ------------------------------------------//
		//-------------------- Constructor/Destructor ---------------------------//
	    PresidentialPardonForm();
	    PresidentialPardonForm(std::string &target);
	    PresidentialPardonForm(PresidentialPardonForm const & src);
	    ~PresidentialPardonForm();
		//-------------------- Operators ----------------------------------------//
	    PresidentialPardonForm& operator=(PresidentialPardonForm const & instance);

};

#endif

