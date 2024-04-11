/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2029/03/20 10:54:43 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/10 15:46:49 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../incs/base.hpp"
# include <fstream>
# include "../incs/Bureaucrat.hpp"
# include "../incs/Form.hpp"
int	main()
{
	Form		Fs10e25("fs10e25", 10, 25);
	std::cout << Fs10e25 << std::endl;
	Bureaucrat	Alice("Alice", 75);
	std::cout << Alice << std::endl;
	try
	{	
		Alice.signForm(Fs10e25);
	}
	catch (const std::exception& e)
	{
		std::cerr << YELLOW << BOLD <<  e.what() << END_C <<  std::endl;
	}
	Bureaucrat	Beatrice("Beatrice", 25);
	std::cout << Beatrice << std::endl;
	try
	{	
		Fs10e25.beSigned(Beatrice);
	}
	catch (const std::exception& e)
	{
		std::cerr << YELLOW << BOLD <<  e.what() << END_C <<  std::endl;
	}
	Bureaucrat	Charlotte("Charlotte", 10);
	std::cout << Charlotte << std::endl;
	try
	{	
		Charlotte.signForm(Fs10e25);
		std::cout << Fs10e25 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << YELLOW << BOLD <<  e.what() << END_C <<  std::endl;
	}
	return (SUC);

}


