/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:36:33 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/11 15:44:38 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/iter.hpp"

int main()
{
	int tabI[5] = {1, 2, 3, 4, 5};
	std::string tabS[5] = {"10", "20", "30", "40", "50"};
	iter(tabI, 5, myFunc);
	std::cout << std::endl;
	iter(tabS, 5, myFunc);
	return (SUC);
}