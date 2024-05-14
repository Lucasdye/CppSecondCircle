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

BitcoinExchange::~BitcoinExchange()
{
	std::cout << ITALIC << "Default constructor called for BitcoinExchange" << END_C << std::endl;
	_ifs.close();
}

//-------------------- Set/Get ----------------------------------------------//
//-------------------- funcs ------------------------------------------------//
bool		BitcoinExchange::openFile(std::string fileNam)
{
	_ifs.open(fileNam, std::ifstream::in);// enume, defines how the file should be open (read mode)
	if (_ifs.fail())
	{	
		throw BitcoinExchange::Exception(std::string(RED) + "The file couldn't be open" + END_C);
		return (true);
	}
	return (false);
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
BitcoinExchange::Exception::Exception(std::string errMsg)
{
	_errMsg = errMsg;
}