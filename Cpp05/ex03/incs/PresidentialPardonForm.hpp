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

#include "base.hpp"

class AForm;
class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:

	public:
		//-------------------- funcs --------------------------------------------//
		void execute(Bureaucrat const &executor);
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

