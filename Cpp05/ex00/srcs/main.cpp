/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2029/03/20 10:54:43 by lbouguet          #+#    #+#             */
/*   Updated: 2024/03/29 17:42:13 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/base.hpp"

int	main()
{
	Bureaucrat Alphonse("Alphonse", 10);
	Bureaucrat Corrine("Corrine", 10);
	std::ofstream out;
	
	
	std::cout << Alphonse << std::endl;
	Alphonse.incrGrade();
	std::cout << Alphonse << std::endl;
	std::cout << Corrine << std::endl;
	Corrine.decrGrade();
	std::cout << Corrine << std::endl;
	
	try
	{
		Bureaucrat Beatrice = Bureaucrat("Beatrice", -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << BOLD <<  e.what() << END_C <<  std::endl;
	}
	
	try
	{
		Bureaucrat Beatrice = Bureaucrat("Beatrice", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << BOLD <<  e.what() << END_C <<  std::endl;
	}
	
	return (0);
}


