#ifndef FUNCSTEMPLATE_HPP
# define FUNCSTEMPLATE_HPP

# include "../incs/base.hpp"

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