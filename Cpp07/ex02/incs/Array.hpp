/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2011/04/20 15:48:35 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/16 17:00:44 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

// # ifndef BOLD
// #  define BOLD "\033[1m"
// # endif

# ifndef ITALIC
#  define ITALIC "\033[3m"
# endif

// # ifndef UNDERLINE
// #  define UNDERLINE "\033[4m"
// # endif

# ifndef RED
#  define RED "\033[31m"
# endif

// # ifndef GREEN
// #  define GREEN "\033[32m"
// # endif

// # ifndef YELLOW
// #  define YELLOW "\033[33m"
// # endif

// # ifndef BLUE
// #  define BLUE "\033[34m"
// # endif

// # ifndef MAGENTA
// #  define MAGENTA "\033[35m"
// # endif

// # ifndef CYAN
// #  define CYAN "\033[36m"
// # endif

# ifndef END_C
#  define END_C "\033[0m"
# endif

# ifndef SUC
#  define SUC 0
# endif

# ifndef ERR
#  define ERR -1
# endif

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits.h>

template <typename T>
class Array
{
	private:
		T*				_tab;
		unsigned int	_size;
	
	public:
		//-------------------- funcs --------------------------------------------//
			unsigned int size();
		//-------------------- Set/get ------------------------------------------//
		//-------------------- Constructor/Destructor ---------------------------//
	    				Array();
	    				Array(unsigned int n);
	    				Array(Array const& src);
	    				~Array();
		//-------------------- Operators ----------------------------------------//
	   		Array&		operator=(Array const & instance);
	    	T& 			operator[](unsigned int idx);
		//-------------------- Exceptions ---------------------------------------//
			class ArrayExceptions: public std::exception
			{
				private:
					const std::string _errMsg;
				
				public:
					virtual const char *what() const throw();
										ArrayExceptions(const std::string errMsg);
										ArrayExceptions();
										~ArrayExceptions() throw();
			};

		
		// class OutOfBoundIdx: public std::exception
		// {
		// 	public :
		// 		virtual const char *what() const throw();
		// };
		
		// class	NullNew: public std::exception
		// {
		// 	public :
		// 		virtual const char *what() const throw();
		// };

		// class	TooHighNew: public std::exception
		// {
		// 	public :
		// 		virtual const char *what() const throw();
		// };
	
};

# include "Array.tpp"
#endif

