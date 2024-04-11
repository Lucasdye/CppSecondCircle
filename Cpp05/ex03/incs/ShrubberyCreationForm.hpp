/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbouguet <lucasbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 01/04/2024 10:55:34 by lucasbouguet          #+#    #+#             */
/*   Updated: 01/04/2024 10:55:34 by lucasbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

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
# include <fstream>
# include <string>

class ShrubberyCreationForm : public Form
{
	private:

	public:
		//-------------------- funcs --------------------------------------------//
		void	execute(Bureaucrat const &executor) const;
		//-------------------- Set/get ------------------------------------------//
		//-------------------- Constructor/Destructor ---------------------------//
		//-------------------- Operators ----------------------------------------//
	    ShrubberyCreationForm();
		ShrubberyCreationForm(std::string &target);
	    ShrubberyCreationForm(ShrubberyCreationForm const & src);
	    ShrubberyCreationForm& operator=(ShrubberyCreationForm const & instance);
	    ~ShrubberyCreationForm();

};

#endif

