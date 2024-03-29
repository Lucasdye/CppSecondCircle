/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2029/03/20 10:54:43 by lbouguet          #+#    #+#             */
/*   Updated: 2024/03/29 18:05:47 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/base.hpp"

int	main()
{
	std::ofstream out;
	Bureaucrat Alphonse("Alphonse", 10);
	std::cout << Alphonse << std::endl;
	Alphonse.incrGrade();
	std::cout << Alphonse << std::endl;
	Bureaucrat Corrine("Corrine", 10);
	std::cout << Corrine << std::endl;
	Corrine.decrGrade();
	std::cout << Corrine << std::endl;
	
	//---------- Too High grade initialization
	try
	{
		Bureaucrat Beatrice = Bureaucrat("Beatrice", -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << BOLD <<  e.what() << END_C <<  std::endl;
	}
	//---------- Too Low grade initialization
	try
	{
		Bureaucrat Beatrice = Bureaucrat("Beatrice", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << BOLD <<  e.what() << END_C <<  std::endl;
	}
	
	Bureaucrat David("David", 150);
	//---------- Too Low grade decremention
	try
	{
		David.decrGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << BOLD <<  e.what() << END_C <<  std::endl;
	}

	Bureaucrat Fabien("Fabien", 1);
	//---------- Too high grade incrementation
	try
	{
		Fabien.incrGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << BOLD <<  e.what() << END_C <<  std::endl;
	}
	return (0);
}


