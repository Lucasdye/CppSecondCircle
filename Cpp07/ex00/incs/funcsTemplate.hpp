/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcsTemplate.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:23:55 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/11 15:23:57 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCSTEMPLATE_HPP
# define FUNCSTEMPLATE_HPP

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

# ifndef SUC
#  define SUC 0
# endif

# ifndef ERR
#  define ERR -1
# endif

# include <iostream>
# include <string>

template <typename T>
void	swap(T& a, T& b)
{
	T tmp;
	
	tmp = a;
	a = b;
	b = tmp;
	return ;
}

template <typename T>
T	max(T& a, T& b)
{
	if (a > b)
		return (a);
	return (b);
}

template <typename T>
T	min(T& a, T& b)
{
	if (a < b)
		return (a);
	return (b);
}

#endif