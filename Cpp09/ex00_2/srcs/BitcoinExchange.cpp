# include "../incs/BitcoinExchange.hpp"

//-------------------- Constructor/Destructor -------------------------------//
BitcoinExchange::BitcoinExchange(): _size(0), _sizeIn(0), _fileName("")
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
	_ifsCsv.close();
}

//-------------------- Set/Get ----------------------------------------------//
const std::ifstream&	BitcoinExchange::getIfsCsv() const
{
	return (_ifsCsv);
}

const std::ifstream&	BitcoinExchange::getIfsInput() const
{
	return (_ifsInput);
}

const std::map<time_t, float>&	BitcoinExchange::getCsvBtc() const
{
	return (_csvBtc);
}
//-------------------- funcs ------------------------------------------------//
void		BitcoinExchange::openFileCsv(std::string fileNam)
{
	std::string line;
	
	std::cout << fileNam << std::endl;
	// Opening file
	_ifsCsv.open(fileNam.c_str(), std::ifstream::in);// enume, defines how the file should be open (read mode)
	if (_ifsCsv.fail())
		throw BitcoinExchange::BtcExException(std::string(RED) + "The file " + fileNam + " couldn't be open" + END_C);

	//Checking it isn't empty
	while (std::getline(_ifsCsv, line))
		_size++;
	if (!_size)
		throw BitcoinExchange::BtcExException(std::string(RED) + "The file " + fileNam + " is empty" + END_C); 
	//Checking it isn't to big for container capacity
	if (_size > _csvBtc.max_size())
		throw BitcoinExchange::BtcExException(std::string(RED) + "The file " + fileNam + " is too big" + END_C); 
	_ifsCsv.clear();
	_ifsCsv.seekg(0, std::ios::beg);
	return ;
}

void		BitcoinExchange::openFileInput(std::string fileNam)
{
	std::string line;
	
	// Opening file
	_ifsInput.open(fileNam.c_str(), std::ifstream::in);// enume, defines how the file should be open (read mode)
	if (_ifsInput.fail())
		throw BitcoinExchange::BtcExException(std::string(RED) + "The file " + fileNam + " couldn't be open" + END_C);
	
	//Checking if it isn't empty
	while (std::getline(_ifsInput, line))
		_sizeIn++;
	if (_sizeIn == 0)
		throw BitcoinExchange::BtcExException(std::string(RED) + "The file " + fileNam + " is empty" + END_C);
	_ifsInput.clear();
	_ifsInput.seekg(0, std::ios::beg);
	return ;
}

time_t		BitcoinExchange::to_time_t(const std::tm& date)
{
	std::tm cpyTm;

	cpyTm = date;
	return (mktime(&cpyTm));
}

void		BitcoinExchange::defineMapCsv()
{
	std::string line;
	std::string strDate;
	std::tm		tm = {};
	time_t		msDate;
	std::string	strVal;
	float		fVal;

	std::getline(_ifsCsv, line);
	while (std::getline(_ifsCsv, line))
	{
		if (line.find(",") == std::string::npos)
			throw std::invalid_argument("Invalid csv line: " + line);
		strDate = line.substr(0, line.find(","));
		if (strptime(strDate.c_str(), "%Y-%m-%d", &tm) == NULL)
			throw std::invalid_argument("Invalid date format: " + strDate);
		msDate = to_time_t(tm);
		strVal = line.substr(line.find(",") + 1);
		char *endptr;
		fVal = std::strtof(strVal.c_str(), &endptr);
		if (*endptr != '\0')
			throw std::invalid_argument("Invalid value format: " + strVal);
		_csvBtc[msDate] = fVal;
	}
	return ;
}

std::string BitcoinExchange::time_t_to_localtime_string(time_t date)
{
 	struct tm *tm = localtime(&date);

    // Check if the conversion was successful
    if (tm == NULL) {
        return "";
    }

    // Define a buffer to hold the formatted date string
    char dateString[11];  // YYYY-MM-DD is 10 characters long + null terminator

    // Format the date as a string
    strftime(dateString, sizeof(dateString), "%Y-%m-%d", tm);

    // Return the formatted date string
    return std::string(dateString);
}

void		BitcoinExchange::outputResult(std::string date, std::string value)
{
	std::tm 	tm = {};// time structure 
	time_t		foundDate;
	std::string strFoundDate;
	float		btcVol;
	float		res;

	if (strptime(date.c_str(), "%Y-%m-%d", &tm) != NULL)// check format
	{
		foundDate = findDateInMap(to_time_t(tm));
		if (foundDate != ERR)
		{
			char *endptr;
			btcVol = strtof(value.c_str(), &endptr);
			if (*endptr != '\0')
				std::cout << "Error: bad input => " + value << std::endl;
			else if (btcVol < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (btcVol > 1000)
				std::cout << "Error: too large value" << std::endl;
			else
			{
				res = _csvBtc[foundDate] * btcVol;
				strFoundDate = time_t_to_localtime_string(foundDate);
				std::cout << strFoundDate << " => " << value << " = " << res << std::endl;; 
			}
		}
		else
			std::cout << "Error: the date is too backwards => " << date << std::endl;
	}
	else
		std::cout << "Error: bad input => " + date << std::endl;
}

time_t	BitcoinExchange::findDateInMap(std::time_t date)
{
	if (date == -1 || _csvBtc.begin()->first > date)
	{	
		return (ERR);
	}
	else if (_csvBtc.rbegin()->first <=  date)
	{
		return (_csvBtc.rbegin()->first);
	}
	else
	{
   		std::map<time_t, float>::iterator it = _csvBtc.lower_bound(date);
    	if (it != _csvBtc.end() && it->first == date)
    	{    
			return date; // Exact match found
		}
		else if (it != _csvBtc.begin()) 
		{
    	    --it; // Return the closest previous date
    	    return it->first;
    	}
	}
	return (ERR);
}

void		BitcoinExchange::readingInputFile()
{
	std::string line;
	std::string	inputDate;
	std::string	inputValue;
	size_t		pipePos;

	std::getline(_ifsInput, line);
	while (std::getline(_ifsInput, line))
	{	
		pipePos = line.find("|");
		if (pipePos == std::string::npos || line[pipePos - 1] != ' '
			|| line[pipePos + 1] != ' ' || line[pipePos + 2] == ' ' || line[pipePos - 2] == ' ')
			std::cout << "Error: bad input => " + line << std::endl;
		else 
		{	
			inputDate = line.substr(0, line.find(" "));
			inputValue = line.substr(line.find("|") + 1);
			outputResult(inputDate, inputValue);
		}
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
BitcoinExchange::BtcExException::BtcExException(std::string errMsg)
{
	_errMsg = errMsg;
}

BitcoinExchange::BtcExException::~BtcExException() throw()
{

}

const char*	BitcoinExchange::BtcExException::what() const throw()
{
	return (_errMsg.c_str());
}