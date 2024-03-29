/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2029/03/20 11:04:20 by lbouguet          #+#    #+#             */
/*   Updated: 2024/03/29 17:26:46 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/GradeTooHighException.hpp"

//-------------------- funcs ------------------------------------------------//
//-------------------- Set/Get ----------------------------------------------//
//-------------------- Constructor/Destructor -------------------------------//
GradeTooHighException::GradeTooHighException()
{
	std::cout << ITALIC << "Default constructor called for GradeTooHighException" << END_C << std::endl;
	std::cout << YELLOW << BOLD <<  "The grade's too high (highest is 1)" << END_C << std::endl;
	return ;
}

GradeTooHighException::~GradeTooHighException()
{
	std::cout << ITALIC << "Destructor called for GradeTooHighException" << END_C << std::endl;
	return ;
}
//-------------------- Operators --------------------------------------------//



