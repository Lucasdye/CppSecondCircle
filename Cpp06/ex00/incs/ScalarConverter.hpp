/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2004/04/20 17:44:20 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/10 18:34:04 by lbouguet         ###   ########.fr       */
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

//----- Value Constants
# ifndef FLOAT_MAX
#  define FLOAT_MAX 3.4028235e38f
# endif
# ifndef FLOAT_MIN
#  define FLOAT_MIN 1.17549435e-38f
# endif
# ifndef FLOAT_TRUE_MIN
#  define FLOAT_TRUE_MIN 1.40129846432481707e-45f
# endif

# ifndef DOUBLE_MAX
#  define DOUBLE_MAX 1.7976931348623157e+308
# endif

# ifndef DOUBLE_MIN
#  define DOUBLE_MIN 2.2250738585072014e-308
# endif

# ifndef DOUBLE_TRUE_MIN
#  define DOUBLE_TRUE_MIN 4.9406564584124654e-324
# endif

//----- Cpp library
# include <iostream>
# include <string>
# include <iomanip>
# include <limits.h>

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

