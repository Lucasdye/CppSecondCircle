/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2004/04/20 17:44:20 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/05 16:48:55 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include "base.hpp"

class ScalarConverter
{
private:



public:
	//-------------------- funcs --------------------------------------------//
	static void convert(std::string &str);
	// bool checkIntOverflow(std::string &line);
	// bool checkIntUnderflow(std::string line);
	// bool isOnlyNumeric(std::string &str);
	//-------------------- Set/get ------------------------------------------//
	//-------------------- Constructor/Destructor ---------------------------//
    ScalarConverter();
    ScalarConverter(ScalarConverter const & src);
    ~ScalarConverter();
	//-------------------- Operators ----------------------------------------//
    ScalarConverter& operator=(ScalarConverter const & instance);

};

#endif

