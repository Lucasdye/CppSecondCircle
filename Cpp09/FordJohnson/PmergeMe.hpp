/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:24:35 by lbouguet          #+#    #+#             */
/*   Updated: 2024/05/31 14:16:24 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <unistd.h>
#include "colors.hpp"


template <typename T>
void	printContainer(const T& container)
{
	typename T::const_iterator it = container.begin();
	
	while (it != container.end())
	{
		std::cout << it->val << " "; 
		it++;
	}
	std::cout << std::endl;
	return ;
};



typedef struct s_nb
{
	int		val;
	size_t	idx_pair;
	size_t	idx_temp;
}	t_nb;

class PmergeMe
{
	private:
		int					_comparisonCount;
		std::vector<int>	_Jacobsthal;
		std::deque<t_nb>	_elements;
		std::deque<t_nb>	_big;
		std::deque<t_nb>	_bigSorted;
		std::deque<t_nb>	_small;

	public:
		// void		fillArray(char **list);
	//	void		secondSplit();
		void				generateJacobsthal();
		void				pairSplit();
		void				binarySearch(std::deque<t_nb>& big, std::deque<t_nb>& small, std::vector<int>::iterator& it);
		//void				printDeq(std::deque<t_nb> deq);
		//void				printVec(std::<t_nb> deq);
		std::deque<t_nb>	FordJohnsonSort(std::deque<t_nb> arr);
		std::deque<t_nb>	JacobsthalInsertion(std::deque<t_nb> big, std::deque<t_nb> small);
		std::deque<t_nb>		getElem();
		std::deque<t_nb>	getBig();
		std::deque<t_nb>	getBigSorted();
		void				setBigSorted(std::deque<t_nb> bigSorted);
		//std::vector<t_nb>	getSmall();
		PmergeMe();
		PmergeMe(char **av);
		~PmergeMe();
		PmergeMe(const PmergeMe& inst);
		PmergeMe&	operator=(const PmergeMe& inst);
	
};