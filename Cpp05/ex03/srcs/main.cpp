/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2029/03/20 10:54:43 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/10 16:54:55 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//----- Class headers
#include "../incs/Bureaucrat.hpp"
#include "../incs/PresidentialPardonForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/ShrubberyCreationForm.hpp"
#include "../incs/Form.hpp"
#include "../incs/Intern.hpp"

//----- CPP library headers
#include <string>
#include <iostream>

int	main()
{
	{	
		std::cout  << "TESTING INTERN FOR ROBOTOMY" << std::endl;
		std::string name;
		
		name = "Alphonse";
		Bureaucrat Alphonse(name, 1);
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{	
			Alphonse.signForm(*rrf);
			Alphonse.executeForm(*rrf);
		}
	}
	{	
		std::cout << std::endl;
		std::cout  << "TESTING INTERN FOR PRESIDENTIAL" << std::endl;
		std::string name;
		
		name = "Alphonse";
		Bureaucrat Alphonse(name, 1);
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		if (rrf)
		{	
			Alphonse.signForm(*rrf);
			Alphonse.executeForm(*rrf);
		}
	}
	{	
		std::cout << std::endl;
		std::cout  << "TESTING INTERN FOR SHRUBBERY" << std::endl;
		std::string name;
		
		name = "Alphonse";
		Bureaucrat Alphonse(name, 1);
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("Shrubb request", "Bender");
		if (rrf)
		{	
			Alphonse.signForm(*rrf);
			Alphonse.executeForm(*rrf);
		}
	}
	return (SUC);
}	


