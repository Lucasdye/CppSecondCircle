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
# define SERIALIZER_HPP

#include "base.hpp"

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
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
	//-------------------- Set/get ------------------------------------------//
	//-------------------- Constructor/Destructor ---------------------------//
    Serializer();
    Serializer(Serializer const & src);
    virtual ~Serializer() = 0;
	//-------------------- Operators ----------------------------------------//
    Serializer& operator=(Serializer const & instance);

};

#endif

