/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:53:25 by lbouguet          #+#    #+#             */
/*   Updated: 2024/05/14 17:12:03 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE.HPP
# define BITCOINEXCHANGE.HPP
# include <utility>
# include <cstring>
# include <string>
# include <iostream>
# include <fstream>

# ifndef BOLD
#  define BOLD "\033[1m"
# endif

# ifndef ITALIC
#  define ITALIC "\033[3m"
# endif

# ifndef UNDERLINE
#  define UNDERLINE "\033[4m"
# endif

# ifndef RED
#  define RED "\033[31m"
# endif

# ifndef GREEN
#  define GREEN "\033[32m"
# endif

# ifndef YELLOW
#  define YELLOW "\033[33m"
# endif

# ifndef BLUE
#  define BLUE "\033[34m"
# endif

# ifndef MAGENTA
#  define MAGENTA "\033[35m"
# endif

# ifndef CYAN
#  define CYAN "\033[36m"
# endif

# ifndef END_C
#  define END_C "\033[0m"
# endif

class BitcoinExchange
{
	private:
		std::pair<std::string, float>	_btcDaVa;
		std::string						_fileName;
		std::ifstream					_ifs;

	public:
		
	//-------------------- funcs --------------------------------------------//
		bool			openFile(std::string fileNam);
		
	//-------------------- Set/get ------------------------------------------//
	//-------------------- Constructor/Destructor ---------------------------//
						BitcoinExchange();
						BitcoinExchange(BitcoinExchange const &inst);
						~BitcoinExchange();
	//-------------------- Exception ----------------------------------------//
		class Exception: public std::exception
		{
			private:
				std::string _errMsg;
			
			public:
				virtual const char *what() const throw();
				Exception(std::string errMsg) {};
				virtual ~Exception(){};
		};
	
	//-------------------- Operators ----------------------------------------//
	BitcoinExchange&	operator=(BitcoinExchange const &inst);
		
				
};

#endif