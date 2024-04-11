/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:27:26 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/11 12:43:23 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# ifndef SUC
#  define SUC 0
# endif

# ifndef ERR
#  define ERR -1
# endif

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

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <typeinfo>

class A;
class B;
class C;

class Base
{
	private:

	public:
		//-------------------- funcs --------------------------------------------//
		Base *generate(void);
		void identify(Base* p);
		void identify(Base& p);
		//-------------------- Set/get ------------------------------------------//
		//-------------------- Constructor/Destructor ---------------------------//
	   	Base();
	   	Base(Base const & src);
	    virtual ~Base();
		//-------------------- Operators ----------------------------------------//
	   	Base& operator=(Base const & instance);
};

#endif
