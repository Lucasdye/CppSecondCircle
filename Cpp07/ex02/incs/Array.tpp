/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2011/04/20 15:48:35 by lbouguet          #+#    #+#             */
/*   Updated: 2024/05/31 10:46:24 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define  ARRAY_TPP
#include "Array.hpp"

//-------------------- funcs ------------------------------------------------//
template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

//-------------------- Set/Get ----------------------------------------------//
//-------------------- Constructor/Destructor -------------------------------//

template <typename T>
Array<T>::Array(Array<T> const& src)
{
	std::cout << "Copy constructor called for Array" << std::endl;
	_tab = new T[src._size];
	for (unsigned int i = 0; i < src._size; i++)
		_tab[i] = src._tab[i];
	_size = src._size;
	return ;
}

template <typename T>
Array<T>::Array(): _tab(NULL), _size(0)
{
	std::cout << "Default constructor called for Array" << std::endl;
	return ;
}

template <typename T>
Array<T>::Array(unsigned int n): _size(n)
{
	std::cout << "Parametric constructor called for Array" << std::endl;
	// Array::ArrayExceptions NullSize("The size of the array can't be null");
	// 	throw NullSize;
	// else
	//if (_size > 0)
	_tab = new T[n];
	return ;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Destructor called for Array" << std::endl;
	delete [] _tab;
	return ;
}
//-------------------- Operators --------------------------------------------//
template <typename T>
Array<T>&	Array<T>::operator=(Array<T> const& instance)
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
	Array::ArrayExceptions OutOfBoundIdx("The index is out of bound");
	//int sizeInt = static_cast<int>(_size);
	if (idx >= _size)
		throw OutOfBoundIdx;
	else
		return (_tab[idx]);
	
}

//-------------------- Exceptions -------------------------------------------//
template <typename T>
Array<T>::ArrayExceptions::ArrayExceptions(const std::string errMsg): _errMsg(RED + errMsg + END_C)
{
	//std::cout << ITALIC << "Parametric constructor called for ArrayExceptions" << END_C << std::endl;
}

template <typename T>
Array<T>::ArrayExceptions::~ArrayExceptions() throw()
{
	//std::cout << ITALIC << "Deconstructor called for ArrayExceptions" << END_C << std::endl;
}

template <typename T>
Array<T>::ArrayExceptions::ArrayExceptions(): _errMsg("None")
{
	//std::cout << ITALIC << "Constructor called for ArrayExceptions" << END_C << std::endl;
}

template <typename T>
const char *Array<T>::ArrayExceptions::what() const throw()
{
	return (_errMsg.c_str());
}

#endif