/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2029/03/20 11:04:48 by lbouguet          #+#    #+#             */
/*   Updated: 2024/03/29 13:48:28 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/GradeTooLowException.hpp"

//-------------------- funcs ------------------------------------------------//
//-------------------- Set/Get ----------------------------------------------//
//-------------------- Constructor/Destructor -------------------------------//
GradeTooLowException::GradeTooLowException()
{
	std::cout << ITALIC << "Default constructor called for GradeTooLowException" << END_C << std::endl;
	std::cout << "The grade initialization is too low (lowest is 150)" << std::endl;
	return ;
}

GradeTooLowException::~GradeTooLowException()
{
	std::cout << ITALIC << "Destructor called for GradeTooLowException" << END_C << std::endl;
	return ;
}
//-------------------- Operators --------------------------------------------//



