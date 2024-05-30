# include "../incs/Span.hpp"
# include <iostream>

int main()
{
	std::vector<int>	IntVec(10);
	int					longestSpan;
	int					shortestSpan;

	IntVec[0] = 12;
	IntVec[1] = 99;
	IntVec[2] = -10;
	IntVec[3] = 140;
	IntVec[4] = 6;
	IntVec[5] = 32;
	IntVec[6] = 48;
	IntVec[7] = 178;
	IntVec[8] = 42;
	IntVec[9] = 0;
	
	Span			 	Span(IntVec);
	try {
	longestSpan = Span.longestSpan();
	std::cout << "longest span: " << longestSpan << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
	shortestSpan = Span.shortestSpan();
	std::cout << "shortest span: " << shortestSpan << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}