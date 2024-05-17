/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:53:25 by lbouguet          #+#    #+#             */
/*   Updated: 2024/05/17 14:16:42 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <map>
# include <cstring>
# include <string>
# include <iostream>
# include <fstream>
# include <stdexcept>
# include <ctime>
# include <sstream>
# include <stdlib.h>
# include <iomanip>
# include <ctime>

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

# ifndef ERR
#  define ERR -1
# endif

# ifndef CSVBTC
#  define CSVBTC "data.csv"
# endif

class BitcoinExchange
{
	private:
		std::map<time_t, float>					_csvBtc;
		std::size_t								_size;
		std::size_t								_sizeIn;
		std::string								_fileName;
		std::ifstream							_ifsCsv;     
		std::ifstream							_ifsInput;     

	public:
		
	//-------------------- funcs --------------------------------------------//
		void			openFileCsv(std::string fileNam);
		void			openFileInput(std::string fileNam);
		void			defineMapCsv();
		void			readingInputFile();
		void			outputResult(std::string date, std::string value);
		time_t			to_time_t(const std::tm& date);// converts date to ms
		//std::string		time_t_to_utc_string(time_t date);
		std::string		time_t_to_localtime_string(time_t date);
		//bool 			noAlphabetInDate(std::string &str);
		//int				compareDates(std::string, )
		
	time_t				findDateInMap(std::time_t date);

	//-------------------- Set/get ------------------------------------------//
	const std::ifstream&							getIfsCsv() const;
	const std::ifstream&							getIfsInput() const;
	const std::map<time_t, float>&					getCsvBtc() const;
	//-------------------- Constructor/Destructor ---------------------------//
						BitcoinExchange();
						BitcoinExchange(BitcoinExchange const &inst);
						~BitcoinExchange();
	//-------------------- Exception ----------------------------------------//
		class BtcExException: public std::exception
		{
			private:
				std::string _errMsg;
			
			public:
				virtual const char *what() const throw();
				BtcExException(std::string errMsg);
				virtual ~BtcExException() throw();
		};
	
	//-------------------- Operators ----------------------------------------//
	BitcoinExchange&	operator=(BitcoinExchange const &inst);
		
				
};

#endif