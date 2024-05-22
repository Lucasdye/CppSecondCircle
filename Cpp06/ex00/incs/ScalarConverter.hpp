/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2004/04/20 17:44:20 by lbouguet          #+#    #+#             */
/*   Updated: 2024/05/22 14:24:35 by lbouguet         ###   ########.fr       */
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
# include <cfloat>
# include <iostream>
# include <string>
# include <iomanip>
# include <limits>
#include  <cctype>
class ScalarConverter
{
	private:
	//-------------------- Constructor/Destructor ---------------------------//
	    ~ScalarConverter();
		ScalarConverter(void);
	    ScalarConverter(ScalarConverter const & src);
		//-------------------- funcs --------------------------------------------//
		static long double 	strToLd(std::string &str);
		static double		powerOfTen(int power);
		static void			convertAndDisplay(long double nb);
		static char 		ldToA(long double nb);
		static bool 		noAlphabet(std::string &str);
		//-------------------- Operators ----------------------------------------//
	    ScalarConverter& 	operator=(ScalarConverter const & instance);

	public:
		static void convert(std::string &str);
		//-------------------- Set/get ------------------------------------------//
};

#endif