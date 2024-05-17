/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:14:49 by lbouguet          #+#    #+#             */
/*   Updated: 2024/05/17 17:20:31 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <string>
# include <limits>

class Rpn
{
	private:
		std::stack<int> objS;
		
			
	public:
		std::stack<int>& getObjS();
		Rpn();
		~Rpn();
		Rpn(Rpn const& instance);
		Rpn&	operator=(Rpn const& instance);
	
};

#endif 