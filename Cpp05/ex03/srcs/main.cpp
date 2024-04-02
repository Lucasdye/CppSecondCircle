/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2029/03/20 10:54:43 by lbouguet          #+#    #+#             */
/*   Updated: 2024/04/02 19:23:11 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/base.hpp"


int	main()
{
	{
		std::string 			test = "courtyard";
		Bureaucrat				Alphonse("Alphonse", 137);
		ShrubberyCreationForm	Shrubb(test);
		
		//-------------------- SHRUBBERY FORM -----------------------------------//
		std::cout << BLUE << "\tShrubbery Form tests" << END_C << std::endl;
		//---------- Alphonse tries to execute a non signed form.
		for (int i = 0; i < 2; i++)
		{	
			
			try 
			{
				Shrubb.execute(Alphonse);
			}
			catch (const std::exception& e)
			{
				std::cerr << YELLOW << BOLD <<  e.what() << END_C <<  std::endl;
			}
			//--------- Alphonse sign the form
			try
			{
				Shrubb.beSigned(Alphonse);
			}
			catch (const std::exception &e)
			{
				std::cerr << YELLOW << BOLD <<  e.what() << " to sign" <<END_C <<  std::endl;
			}
		}
		//---------- Now that Shrubb for is signed, let's try to execute it with an undergraded bureaucrat
		Bureaucrat	Beatrice("Beatrice", 145);
		try 
		{
			Shrubb.execute(Beatrice);
		}
		catch (const std::exception &e)
		{
			std::cerr << YELLOW << BOLD << e.what() << " to execute" << END_C << std::endl;
		}
		//---------- Same idea but while using the Bureaucrat's executeForm()
		Bureaucrat	Charlotte("Charlotte", 145);
		try 
		{
			Charlotte.executeForm(Shrubb);
		}
		catch (const std::exception &e)
		{
			std::cerr << YELLOW << BOLD << e.what() << " to execute" << END_C << std::endl;
		}
		//----------  executeForm() by a valide graded Bureaucrat
		Bureaucrat	David("David", 137);
			try 
		{
			David.executeForm(Shrubb);
		}
		catch (const std::exception &e)
		{
			std::cerr << YELLOW << BOLD << e.what() << " to execute" << END_C << std::endl;
		}
	}
	//-------------------- ROBOTOMY FORM ------------------------------------//
	{
		std::cout << std::endl;
		std::cout << BLUE << "\tRobotomy Form tests" << END_C << std::endl;
		
		std::string 			test = "Robotomise_Cedric";
		Bureaucrat				Alphonse("Alphonse", 45);
		RobotomyRequestForm		Robot(test);
		
		//---------- Alphonse tries to execute a non signed form.
		for (int i = 0; i < 2; i++)
		{	
			
			try 
			{
				Robot.execute(Alphonse);
			}
			catch (const std::exception& e)
			{
				std::cerr << YELLOW << BOLD <<  e.what() << END_C <<  std::endl;
			}
			//--------- Alphonse sign the form
			try
			{
				Robot.beSigned(Alphonse);
			}
			catch (const std::exception &e)
			{
				std::cerr << YELLOW << BOLD <<  e.what() << " to sign" <<END_C <<  std::endl;
			}
		}
		//---------- Now that Robot for is signed, let's try to execute it with an undergraded bureaucrat
		Bureaucrat	Beatrice("Beatrice", 145);
		try 
		{
			Robot.execute(Beatrice);
		}
		catch (const std::exception &e)
		{
			std::cerr << YELLOW << BOLD << e.what() << " to execute" << END_C << std::endl;
		}
		//---------- Same idea but while using the Bureaucrat's executeForm()
		Bureaucrat	Charlotte("Charlotte", 70);
		try 
		{
			Charlotte.executeForm(Robot);
		}
		catch (const std::exception &e)
		{
			std::cerr << YELLOW << BOLD << e.what() << " to execute" << END_C << std::endl;
		}
		//----------  executeForm() by a valide graded Bureaucrat
		Bureaucrat	David("David", 5);
		try 
		{
			David.executeForm(Robot);
		}
		catch (const std::exception &e)
		{
			std::cerr << YELLOW << BOLD << e.what() << " to execute" << END_C << std::endl;
		}
	}
		{
		std::cout << std::endl;
		std::cout << BLUE << "\tPresidential Form tests" << END_C << std::endl;
		
		std::string 			test = "Cedric's absence for the annual meeting";
		Bureaucrat				Alphonse("Alphonse", 5);
		PresidentialPardonForm	Presid(test);
		
		//---------- Alphonse tries to execute a non signed form.
		for (int i = 0; i < 2; i++)
		{	
			try 
			{
				Presid.execute(Alphonse);
			}
			catch (const std::exception& e)
			{
				std::cerr << YELLOW << BOLD <<  e.what() << END_C <<  std::endl;
			}
			//--------- Alphonse sign the form
			try
			{
				Presid.beSigned(Alphonse);
			}
			catch (const std::exception &e)
			{
				std::cerr << YELLOW << BOLD <<  e.what() << " to sign" <<END_C <<  std::endl;
			}
		}
		//---------- Now that Presid for is signed, let's try to execute it with an undergraded bureaucrat
		Bureaucrat	Beatrice("Beatrice", 145);
		try 
		{
			Presid.execute(Beatrice);
		}
		catch (const std::exception &e)
		{
			std::cerr << YELLOW << BOLD << e.what() << " to execute" << END_C << std::endl;
		}
		//---------- Same idea but while using the Bureaucrat's executeForm()
		Bureaucrat	Charlotte("Charlotte", 145);
		try 
		{
			Charlotte.executeForm(Presid);
		}
		catch (const std::exception &e)
		{
			std::cerr << YELLOW << BOLD << e.what() << " to execute" << END_C << std::endl;
		}
		//----------  executeForm() by a valide graded Bureaucrat
		Bureaucrat	David("David", 5);
		try 
		{
			David.executeForm(Presid);
		}
		catch (const std::exception &e)
		{
			std::cerr << YELLOW << BOLD << e.what() << " to execute" << END_C << std::endl;
		}
	}
	return (SUC);
}	


