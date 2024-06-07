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

#include "../incs/PmergeMe.hpp"

//------------------- Cons/Des ----------------------------------------------//
PmergeMe::PmergeMe()
{
	std::cout << "Default constructor called PmergeMe" <<std::endl;
}


PmergeMe::PmergeMe(char **av): _comparisonCount(0)
{
	std::cout << "Parametric constructor called PmergeMe" <<std::endl;
	for (size_t i = 1; av[i]; i++)
	{	
		t_nb nb;
		nb.val = std::atoi(av[i]);
		nb.pair.push_back(i);
		nb._newOrder = -1;
		_elements.push_back(nb);
	}
}
PmergeMe::~PmergeMe()
{
	std::cout << "Default deconstructor called PmergeMe" <<std::endl;
}

//------------------- Init --------------------------------------------------//
void				PmergeMe::generateJacobsthal()
{
	int	val;
	
	_Jacobsthal.push_back(1);
	_Jacobsthal.push_back(3);
	for (int i = 1; i < 3000; i++)
	{
		val = _Jacobsthal[i - 1] * 2 + _Jacobsthal[i];
		_Jacobsthal.push_back(val);
	}
	std::cout << std::endl ;
}

void				PmergeMe::generateJacobsthalDiff()
{
	int	val;
	
	for (size_t i = 2; i < _Jacobsthal.size(); i++)
	{	
		val = _Jacobsthal[i - 1] - _Jacobsthal[i - 2];
		_Jacobsthal_diff.push_back(val);
	}	
}

//------------------- Sorting -----------------------------------------------//
void					PmergeMe::PoppingFirstPair(std::deque<t_nb>& big, std::deque<t_nb>& small)
{
	std::deque<t_nb>::iterator 	itSmall = small.begin();

	int		small_pair_target = big.front().pair.back();
	//int		small_pair_idx = -1;

	if (small.size() == 1)
	{
		big.push_front(small.front());
		return ;
	}
	//find corresponding small node from pair
	while (itSmall != small.end())
	{
		if (itSmall->pair.back() == small_pair_target)
			break ;
		itSmall++;
	}	
		itSmall->pair.pop_back();
		big.front().pair.pop_back();
		big.push_front(*itSmall);
	return ;
}

void					PmergeMe::binarySearch(std::deque<t_nb>& big, t_nb element, int idxmax)
{
	int	minBoundIdx = 0;
	int	maxBoundIdx = idxmax;
	int	midIdx = (maxBoundIdx - minBoundIdx) / 2;

	while (maxBoundIdx - minBoundIdx != 1)
	{
		_comparisonCount++;
		if (element.val > big[midIdx].val)
			minBoundIdx = midIdx;
		else
			maxBoundIdx = midIdx;
		midIdx = (maxBoundIdx + minBoundIdx) / 2;
	}
	if (element.val > big[maxBoundIdx].val)
		big.insert(big.begin() + maxBoundIdx + 1, element);
	else if (element.val < big[minBoundIdx].val)
		big.insert(big.begin() + minBoundIdx, element);
	else
		big.insert(big.begin() + maxBoundIdx, element);
	_comparisonCount++;
	return ;
}

std::deque<t_nb>		PmergeMe::JacobsthalInsertion(std::deque<t_nb> big, std::deque<t_nb> small)
{
	bool						impair = 0;

	if (small.size() > big.size())
		impair = 1;
	PoppingFirstPair(big, small);

	// New order
	for (size_t i = 0; i < big.size(); i++)
	{
		big[i]._newOrder = i + 1;
	}
	int	size_big = big.size();
	int j = 1;
	int order = _Jacobsthal[j];
	int sequence_len = 0;
	while (order <= size_big)
	{
		order = _Jacobsthal[j];
		if ( j == 1)
			sequence_len = 1;
		else
			sequence_len =  _Jacobsthal[j] -  _Jacobsthal[j - 1];
		if (order > size_big)
		{
			order = size_big;
			sequence_len =  (_Jacobsthal[j] -  _Jacobsthal[j - 1]) - (_Jacobsthal[j] - size_big);
			if ( sequence_len <= 0)
				break;
		}
		int target_small = -1;
		int idxBig = 0;

		for (int l = 0; l < sequence_len; l++)
		{	
			for (size_t k = 0; k < big.size(); k++)// find jacobsthal order corresponding index in big 
			{
				if (big[k]._newOrder == order - l)
				{	
					idxBig = k;
					target_small = big[k].pair.back();
					big[k].pair.pop_back();
					small[target_small].pair.pop_back();
					binarySearch(big, small[target_small], idxBig);
					break ;
				}
			}
		}
		j++;
	}
	// insert non paired element
	if (impair)
	{
		small.back().pair.pop_back();
		binarySearch(big, small.back(), big.size() - 1);
	}
	return (big);
}

std::deque<t_nb>		PmergeMe::FordJohnsonSort(std::deque<t_nb> arr)
{
	if (arr.size() <= 2)
	{
		if (arr.size() > 1 && arr.front().val > arr.back().val)
			std::swap(arr[0], arr[1]);

		return arr; 
	}
	std::deque<t_nb> big;
	std::deque<t_nb> small;
	size_t pairPos = 0;
	for (size_t i = 0; i < arr.size() - 1; i += 2, pairPos++)
	{
		_comparisonCount++;
		if (arr[i].val <= arr[i + 1].val)
		{
			small.push_back(arr[i]);
			big.push_back(arr[i + 1]);
		}
		else
		{	small.push_back(arr[i + 1]);
			big.push_back(arr[i]);
		}
		small.back().pair.push_back(pairPos);
		big.back().pair.push_back(pairPos);
	}
	if (arr.size() % 2 != 0){	
		small.push_back(arr[arr.size() - 1]);
		small.back().pair.push_back(pairPos + 1);
	}
	std::deque<t_nb> bigSorted = FordJohnsonSort(big);
	return JacobsthalInsertion(bigSorted, small);
}

//------------------- Set/Get -----------------------------------------------//
void					PmergeMe::setBigSorted(std::deque<t_nb>	bigSorted)
{
	_bigSorted = bigSorted;
	return ;
}

int						PmergeMe::getComparisonCount()
{
	return (_comparisonCount);
}

std::deque<t_nb>		PmergeMe::getElem()
{
	return (_elements);
}

std::vector<int>		PmergeMe::getJaco()
{
	return (_Jacobsthal);
}

std::deque<t_nb>		PmergeMe::getBig()
{
	return (_big);
}

std::deque<t_nb>		PmergeMe::getBigSorted()
{
	return (_bigSorted);
}










