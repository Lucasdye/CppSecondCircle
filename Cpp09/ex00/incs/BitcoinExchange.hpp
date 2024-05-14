/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:53:25 by lbouguet          #+#    #+#             */
/*   Updated: 2024/05/14 16:51:39 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE.HPP
# define BITCOINEXCHANGE.HPP
# include <utility>
# include <cstring>
# include <string>
# include <iostream>
# include <fstream>

class BitcoinExchange
{
	private:
		std::pair<std::string, float>	_btcDaVa;
		std::string						_fileName;
		std::ifstream					_ifs;

	public:
		
	//-------------------- funcs --------------------------------------------//
		bool			openFile();
		
	//-------------------- Set/get ------------------------------------------//
		void			setIfs(int fd);	
		
	//-------------------- Constructor/Destructor ---------------------------//
						BitcoinExchange();
						BitcoinExchange(BitcoinExchange const &inst);
						~BitcoinExchange();
	//-------------------- Operators ----------------------------------------//
	BitcoinExchange&	operator=(BitcoinExchange const &inst);
		
				
};

#endif