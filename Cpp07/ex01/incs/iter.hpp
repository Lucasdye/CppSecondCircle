/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:36:40 by lbouguet          #+#    #+#             */
/*   Updated: 2024/05/31 10:51:00 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# ifndef SUC
#  define SUC 0
# endif

# ifndef ERR
#  define ERR -1
# endif

# include <iostream>
# include <string>

template <typename T>
void myFunc(T element)
{
	std::cout << element << std::endl;
	return ;
}

template <typename T, typename U>
void	iter(T *tab, int size, void(*myFunc)(U))
{
	for (int i = 0; i < size; i++)
		myFunc(tab[i]);
	return ;
}

#endif