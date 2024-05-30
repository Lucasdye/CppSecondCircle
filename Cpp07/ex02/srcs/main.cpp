/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2011/04/20 15:48:35 by lbouguet          #+#    #+#             */
/*   Updated: 2024/05/29 12:20:59 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../incs/Array.hpp"
# include "../incs/Array.tpp"
# define MAX_VAL 750

int	main()
{
	// {
	// Array<int> numbers(MAX_VAL);
    // int* mirror = new int[MAX_VAL];
    // srand(time(NULL));
    // for (int i = 0; i < MAX_VAL; i++)
    // {
	// 	std::cout << "in loop" << std::endl;
    //     const int value = rand();
    //     numbers[i] = value;
    //     mirror[i] = value;
    // }
    // //SCOPE
    // {
    //     Array<int> tmp = numbers;
    //     Array<int> test(tmp);
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     if (mirror[i] != numbers[i])
    //     {
    //         std::cerr << "didn't save the same value!!" << std::endl;
    //         return 1;
    //     }
    // }
    // try
    // {
    //     numbers[-2] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // try
    // {
    //     numbers[MAX_VAL] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     numbers[i] = rand();
    // }
    // delete [] mirror;//
	// }
	{
		Array<std::string> ArrStr(0);
		Array<std::string> ArrStrEmpty;
		Array<std::string> ArrStrEmtpy2(0);

		try {
			
		std::cout << ArrStr[0] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		// ArrStr[1] = "hello";
		
		// 	ArrStr[0]
		

		// std::cout << ArrStr[1] << std::endl;
	}
	
	return 0;
}


