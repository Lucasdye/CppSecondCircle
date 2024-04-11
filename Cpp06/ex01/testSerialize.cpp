/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testSerialize.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:20:41 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/11 12:22:17 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "./incs/Serializer.hpp"

int main()
{
	float 			f = 1.5;
	int				i = 0;

	i = f;
	std::cout << "i1 = " << i  << std::endl;
	i = reinterpret_cast<uintptr_t>(&f);
	std::cout << "i2 = " << i << std::endl;
}