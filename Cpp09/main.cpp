/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:22:45 by lbouguet          #+#    #+#             */
/*   Updated: 2024/05/31 13:59:39 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>
#include "PmergeMe.hpp"


int	main(int ac, char **av)
{
	if (ac < 3)
		return (-1);
	PmergeMe ppm(av);
	ppm.pairSplit();
	ppm.FordJohnsonSort(ppm.getElem());
	printContainer(ppm.getBig());
	//ppm.setBigSorted(ppm.mergeSort(ppm.getBig()));
	//ppm.printDeq(ppm.getBigSorted());
	return (0);
}