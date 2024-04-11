/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasbouguet <lucasbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 08/04/2024 11:03:17 by lucasbouguet          #+#    #+#             */
/*   Updated: 08/04/2024 11:03:17 by lucasbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP

# include <iostream>
# include "Base.hpp"

class B: public Base
{
	private:

	public:
		//-------------------- funcs --------------------------------------------//
		//-------------------- Set/get ------------------------------------------//
		//-------------------- Constructor/Destructor ---------------------------//
	    B();
	    B(B const & src);
	    ~B();
		//-------------------- Operators ----------------------------------------//
	    B& operator=(B const & instance);

};

#endif
