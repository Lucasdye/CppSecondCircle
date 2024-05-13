/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2004/04/20 17:44:20 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/16 18:14:04 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP


//----- Color constants
# ifndef BOLD
#  define BOLD "\033[1m"
# endif

# ifndef ITALIC
#  define ITALIC "\033[3m"
# endif

# ifndef UNDERLINE
#  define UNDERLINE "\033[4m"
# endif

# ifndef RED
#  define RED "\033[31m"
# endif

# ifndef GREEN
#  define GREEN "\033[32m"
# endif

# ifndef YELLOW
#  define YELLOW "\033[33m"
# endif

# ifndef BLUE
#  define BLUE "\033[34m"
# endif

# ifndef MAGENTA
#  define MAGENTA "\033[35m"
# endif

# ifndef CYAN
#  define CYAN "\033[36m"
# endif

# ifndef END_C
#  define END_C "\033[0m"
# endif

//----- Return Constants
# ifndef SUC
#  define SUC 0
# endif

# ifndef ERR
#  define ERR -1
# endif

//----- Cpp library
# include <iostream>
# include <string>
# include <iomanip>
# include <limits>

//----- Funcs prototype
long double strToLd(std::string &str);
double		powerOfTen(int power);
char 		ldToA(long double nb);
void		convertAndDisplay(long double nb);
bool 		noAlphabet(std::string &str);

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
    virtual ~ScalarConverter() = 0;
	//-------------------- Operators ----------------------------------------//
    ScalarConverter& operator=(ScalarConverter const & instance);

};

#endif

