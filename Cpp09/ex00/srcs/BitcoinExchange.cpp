# include "../incs/BitcoinExchange.hpp"

//-------------------- Constructor/Destructor -------------------------------//
BitcoinExchange::BitcoinExchange(): _fileName("")
{
	std::cout << ITALIC << "Default constructor called for Bitcoin Exchange" << END_C << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &inst)
{
	std::cout << ITALIC << "Copy constructor called for Bitcoin Exchange" << END_C << std::endl;
	_fileName = inst._fileName;
}

//-------------------- Set/Get ----------------------------------------------//
//-------------------- funcs ------------------------------------------------//
bool		BitcoinExchange::openFile(std::string fileNam)
{
	try()
	{
		_ifs.open(fileNam, std::ifstream::in);// enume, defines how the file should be open (read mode)
	}
	catch (std::exception &e)
	{
		BitcoinExchange::Exception.what(e);
	}
}
//-------------------- Operators --------------------------------------------//

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const &inst)
{
	std::cout << ITALIC << "Copy assignement operator called for Bitcoin Exchange" << END_C << std::endl;
	if (this != &inst)
	{
		this->_fileName = inst._fileName;
	}
	return (*this);
}
//-------------------- Exceptions -------------------------------------------//