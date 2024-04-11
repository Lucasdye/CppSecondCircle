/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2011/04/20 15:48:35 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/11 18:05:38 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Array.hpp"

template <typename T>
Array<T>::Array(unsigned int n): _size(n)
{
	std::cout << "Parametric constructor called for Array" << std::endl;
	if (_size == 0)
		throw NullNew();
	else
		_tab = new T[n];
	return ;
}

template <typename T>
unsigned int Array<T>::size()
{
	return (_size);
}


template <typename T>
Array<T>::Array(): _tab(NULL), _size(0)
{
	std::cout << "Default constructor called for Array" << std::endl;
	return ;
}

template <typename T>
Array<T>::Array(Array<T> const & src)
{
	std::cout << "Copy constructor called for Array" << std::endl;
	_tab = new T[src._size];
	for (int i = 0; i < src._size; i++)
		_tab[i] = src._tab[i];
	_size = src._size;
	return ;
}

template <typename T>
Array<T>&	Array<T>::operator=(Array<T> const &instance)
{
	std::cout << "Assignment operator called for Array" << std::endl;
	if (this != &instance)
	{
		if (_tab != NULL)
			delete []_tab;
		_tab = new T[instance._size];
		for (int i = 0; i < instance._size; i++)
			_tab[i] = instance._tab[i];
		_size = instance._size;
	}
	return *this;
}

template <typename T>
T&	Array<T>::operator[](unsigned int idx)
{
	if (idx >= _size)
		throw OutOfBoundIdx();
	else
		return (_tab[idx]);
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Destructor called for Array" << std::endl;
	return ;
}

template <typename T>
const char *Array<T>::OutOfBoundIdx::what() const throw()
{
	return ("RED Index out of bound END_C");
}

template <typename T>
const char *Array<T>::NullNew::what() const throw()
{
	return ("RED You can't allocate 0 memory to _tab END_C");
}

template <typename T>
const char *Array<T>::TooHighNew::what() const throw()
{
	return ("Red New allocation size id to high END_C");
}
