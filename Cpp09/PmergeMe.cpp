/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:29:11 by lbouguet          #+#    #+#             */
/*   Updated: 2024/05/30 17:02:26 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void				PmergeMe::generateJacobsthal()
{
	int	val;
	
	_Jacobsthal.push_back(1);
	_Jacobsthal.push_back(3);
	for (int i = 2; i < 3000; i++)
	{	
		val = _Jacobsthal[i - 1] * 2 + _Jacobsthal[i];
		_Jacobsthal.push_back(val);
	}	
}

// void					PmergeMe::printVec(std::deque<t_nb> deq)
// {
// 	std::deque<t_nb>::iterator it = deq.begin();
	
// 	while (it != deq.end())
// 	{
// 		std::cout << it->val << " "; 
// 		it++;
// 	}
// 	std::cout << std::endl;
// 	return ;
// }


// void					PmergeMe::printDeq(std::deque<t_nb> deq)
// {
// 	std::deque<t_nb>::iterator it = deq.begin();
	
// 	while (it != deq.end())
// 	{
// 		std::cout << it->val << " "; 
// 		it++;
// 	}
// 	std::cout << std::endl;
// 	return ;
// }

void					PmergeMe::setBigSorted(std::deque<t_nb>	bigSorted)
{
	_bigSorted = bigSorted;
	return ;
}

std::deque<t_nb>		PmergeMe::getElem()
{
	return (_elements);
}

std::deque<t_nb>		PmergeMe::getBig()
{
	return (_big);
}

std::deque<t_nb>		PmergeMe::getBigSorted()
{
	return (_bigSorted);
}

void					PmergeMe::binarySearch(std::deque<t_nb>& big, std::deque<t_nb>& small, std::vector<int>::iterator& it)
{
	int	minBound;
	int	maxBound;

	big[*it]
	
	return ;
}

std::deque<t_nb>		PmergeMe::JacobsthalInsertion(std::deque<t_nb> big, std::deque<t_nb> small)
{
	//std::deque<t_nb> fusionList;
	std::vector<int>::iterator it = _Jacobsthal.begin();
		
	// Insert the originally paired element with the smallest big
	big.push_front(small[*it]);
	small.pop_front();
	it++;
	while (!small.empty())
	{
		binarySearch(big, small, it);
		
	}
	
	return (big);
}

std::deque<t_nb>		PmergeMe::FordJohnsonSort(std::deque<t_nb> arr)
{
	//printDeq(arr);
	if (arr.size() == 1)
	{
		return arr;
	}
	std::deque<t_nb> big;
	std::deque<t_nb> small;
	
	for (size_t i = 0; i < _elements.size() - 1; i += 2)
	{
		_comparisonCount++;
		if (_elements[i].val <= _elements[i + 1].val)
		{
			small.push_back({_elements[i].val, i});
			big.push_back({_elements[i + 1].val, i});
		}
		else
		{	small.push_back({_elements[i + 1].val, i});
			big.push_back({_elements[i].val, i});
		}
	}
	if (_elements.size() % 2 != 0)
		_small.push_back({_elements[_elements.size() - 1].val, _elements.size() - 1});
	std::deque<t_nb> bigSorted = FordJohnsonSort(big);
	std::deque<t_nb> smallSorted = FordJohnsonSort(small);
	return JacobsthalInsertion(bigSorted, smallSorted);
}


PmergeMe::PmergeMe()
{
	std::cout << "Default constructor called PmergeMe" <<std::endl;
}


PmergeMe::PmergeMe(char **av): _comparisonCount(0)
{
	std::cout << "Parametric constructor called PmergeMe" <<std::endl;
	for (size_t i = 1; av[i]; i++)
		_elements.push_back({std::atoi(av[i]), i});
}

PmergeMe::~PmergeMe()
{
	std::cout << "Default deconstructor called PmergeMe" <<std::endl;
}
