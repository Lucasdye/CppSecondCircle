#include "../incs/BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	BitcoinExchange BtcEx;
	std::string inputFile;

	if (ac < 2)
		return ((void)(std::cout << YELLOW << "File is missing" << END_C << std::endl), ERR);
	inputFile = av[1];
	try	
	{
		BtcEx.openFileInput(inputFile);
		BtcEx.openFileCsv(CSVBTC);
		std::cout << "Files have been opened\n";
		BtcEx.defineMapCsv();
		std::cout << "Map has been defined\n";
	}
	catch (const std::exception &e) 
	{
		std::cout << "EXCEPTION\n";
		std::cout << e.what() << std::endl;
		return (ERR);
	}
	BtcEx.readingInputFile();
	std::cout << "END\n";
	return (0);
}