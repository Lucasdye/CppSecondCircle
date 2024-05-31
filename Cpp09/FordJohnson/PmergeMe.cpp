/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:29:11 by lbouguet          #+#    #+#             */
/*   Updated: 2024/05/31 18:04:41 by lbouguet         ###   ########.fr       */
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

void					PmergeMe::pairSplit()
{
	for (size_t i = 0; i < _elements.size() - 1; i += 2)
	{
		_comparisonCount++;
		if (_elements[i].val <= _elements[i + 1].val)
		{
			_small.push_back({_elements[i].val, i});
			_big.push_back({_elements[i + 1].val, i});
		}
		else
		{	_small.push_back({_elements[i + 1].val, i});
			_big.push_back({_elements[i].val, i});
		}
	}
	if (_elements.size() % 2 != 0)
		_small.push_back({_elements[_elements.size() - 1].val, _elements.size() - 1});
}

void					PmergeMe::binarySearch(std::deque<t_nb>& big, std::deque<t_nb>& small, std::vector<int>::iterator& it)
{
	int	minBoundIdx;
	int	maxBoundIdx;

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
	if (arr.size() <= 2)
	{
		if (arr.front().val > arr.back().val)
			std::swap(arr[0], arr[1]);
		return arr; 
	}
	std::deque<t_nb> big;
	std::deque<t_nb> small;
	
	for (size_t i = 0; i < arr.size() - 1; i += 2)
	{
		_comparisonCount++;
		if (arr[i].val <= arr[i + 1].val)
		{
			small.push_back(arr[i]);
			small.back().idx_temp = i;
			big.push_back(arr[i + 1]);
			big.back().idx_temp = i;
		}
		else
		{	small.push_back(arr[i + 1]);
			small.back().idx_temp = i;
			big.push_back(arr[i]);
			big.back().idx_temp = i;
		}
	}
	if (arr.size() % 2 != 0){	
		_small.push_back(arr[arr.size() - 1]);
		_small.back().idx_temp = _small.size() - 1;
	}
	std::deque<t_nb> bigSorted = FordJohnsonSort(big);
	//std::deque<t_nb> smallSorted = FordJohnsonSort(small);
	return JacobsthalInsertion(bigSorted, small);
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
