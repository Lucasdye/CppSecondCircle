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
#include "../incs/PmergeMe.hpp"


bool	isItSorted(std::deque<t_nb> main)
{
	for (size_t i = 1; i < main.size(); i++)
	{
		if (main[i].val < main[i - 1].val)
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac < 3)
		return (-1);
	PmergeMe pmm(av);
	pmm.generateJacobsthal();
	pmm.setBigSorted(pmm.FordJohnsonSort(pmm.getElem()));
	printContainer(pmm.getBigSorted());
	std::cout << std::endl;
	std::cout << "size sorted: " << pmm.getBigSorted().size() << std::endl;
	std::cout << "Comparison count: " << pmm.getComparisonCount() << std::endl;
	if (isItSorted(pmm.getBigSorted()) == false)
		std::cout << RED << "Not sorted !\n" << reset;
	else
		std::cout << BLU << "Sorted !\n" << reset;
	return (0);
}