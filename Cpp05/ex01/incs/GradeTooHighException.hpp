/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 29/03/2024 11:04:20 by lbouguet          #+#    #+#             */
/*   Updated: 29/03/2024 11:04:20 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOHIGHEXCEPTION_HPP
# define GRADETOOHIGHEXCEPTION_HPP

#include "base.hpp"


class GradeTooHighException : public std::exception
{
	private:

	public:
		//-------------------- funcs --------------------------------------------//
		//-------------------- Set/get ------------------------------------------//
		//-------------------- Constructor/Destructor ---------------------------//
	    GradeTooHighException();
	    ~GradeTooHighException();
		//-------------------- Operators ----------------------------------------//

		
};

#endif

