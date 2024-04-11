/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbouguet <lucasbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 08/04/2024 09:37:57 by lucasbouguet          #+#    #+#             */
/*   Updated: 08/04/2024 09:37:57 by lucasbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define  SERIALIZER_HPP

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
# include <stdint.h>
# include <iostream>

typedef struct s_Data
{
	int		a;
	char	b;
	float	c;
	double	d;

}				Data;

class Serializer
{
	private:


	public:
		//-------------------- funcs --------------------------------------------//
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
		//-------------------- Set/get ------------------------------------------//
		//-------------------- Constructor/Destructor ---------------------------//
	    Serializer();
	    Serializer(Serializer const & src);
	    virtual ~Serializer() = 0;
		//-------------------- Operators ----------------------------------------//
	    Serializer& operator=(Serializer const & instance);
};

#endif

