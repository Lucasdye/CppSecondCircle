# include "../incs/Span.hpp"

//-------------------- Constructor/Destructor -------------------------------//
Span::Span()
{
	std::cout << "Default constructor called" << std::endl;
}

Span::Span(std::vector<int> vec)
{
	std::cout << "Parametric constructor called for Span" << std::endl;
	_span = vec;

}

Span::Span(Span const &instance): _span(instance._span)
{
	std::cout << "Copy constructor called for Span" << std::endl;
}

Span::~Span()
{
	std::cout << "Deconstructor called for Span" << std::endl;
}

//-------------------- funcs ------------------------------------------------//
int	Span::shortestSpan()
{
	int span;
	std::vector<int> cpySorted;
	 

	if (_span.empty() == false && _span.size() > 1)
	{
		cpySorted = _span;
		std::sort(cpySorted.begin(), cpySorted.end());
		span = std::numeric_limits<int>::max();
		for (size_t i = 0; i < cpySorted.size() - 1; i++)
		{
			if (abs(cpySorted[i] - cpySorted[i + 1]) < span)
				span = abs(cpySorted[i] - cpySorted[i + 1]);
		}
	}
	else
		throw Span::SpanException (std::string(YELLOW) + "The container is empty or has only one element" + END_C);
	return (span);
}

int	Span::longestSpan()
{
	int span;
	std::vector<int> cpySorted;

	span = 0;
	if (_span.empty() == false && _span.size() > 1)
	{
		std::cout << "IN condition" << std::endl;
		cpySorted = _span;
		std::sort(cpySorted.begin(), cpySorted.end());
		span = cpySorted[cpySorted.size() - 1] - cpySorted[0];
	}
	else
		throw Span::SpanException (std::string(YELLOW) + "The container is empty or has only one element" + END_C);
	return (span);
}

void	Span::addNumber(int nb)
{
	_span.push_back(nb);
	return ;
}

//-------------------- Set/Get ----------------------------------------------//
std::vector<int>& Span::getSpan()
{
	return (_span);
}

void			Span::setSpan(std::vector<int>& vec)
{
	_span = vec;
	return ;
}

//-------------------- Operators --------------------------------------------//
Span	&Span::operator=(Span const &instance)
{
	if (this != &instance)
	{
		_span.clear();
		_span = instance._span;
	}
	return (*this);
}

//-------------------- Exceptions -------------------------------------------//
Span::SpanException::SpanException()
{
	std::cout << "Default constructor called for SpanException" << std::endl;
	_errMsg = "empty";
}

Span::SpanException::SpanException(std::string errMsg): _errMsg(errMsg)
{
	std::cout << "Parametric constructor called for SpanException" << std::endl;
}

char const *Span::SpanException::what() const throw()
{
	return (_errMsg.c_str());
}