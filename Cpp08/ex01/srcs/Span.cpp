# include "../incs/Span.hpp"

//-------------------- Constructor/Destructor -------------------------------//
Span::Span():  _maxSize(_span.capacity()), _size(_maxSize)
{
	std::cout << "Default constructor called" << std::endl;
}

Span::Span(unsigned int size): _maxSize(_span.capacity()), _size(size)
{
	std::cout << "Parametric constructor called for Span" << std::endl;
	if (_size > _maxSize)
		std::cout << RED << "The size chosen exceeds the capacity of the Span container" << END_C;
	_size = size;
}

Span::Span(Span const &instance): _span(instance._span), _size(instance._size)
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
	int tmp;

	span = std::numeric_limits<int>::max();
	if (_size != 0 && _span.empty() == false && _span.size() > 1)
	{
		for (size_t i = 0; i < _span.size(); i++)
		{
			tmp = abs(_span[i + 1] - _span[i]);
			if (tmp < span)
				span = tmp;
		}
	}
	else
		throw Span::SpanException (std::string(YELLOW) + "The container is empty or has only one element" + END_C);
	return (span);
}

int	Span::longestSpan()
{
	int span;
	int tmp;

	span = 0;
	if (_size != 0 && _span.empty() == false && _span.size() > 1)
	{
		for (size_t i = 0; i < _span.size(); i++)
		{
			tmp = abs(_span[i + 1] - _span[i]);
			if (tmp > span)
				span = tmp;
		}
	}
	else
		throw Span::SpanException (std::string(YELLOW) + "The container is empty or has only one element" + END_C);
	return (span);
}

void	Span::addNumber(int nb)
{
	if (_span.size() + 1 > _size)
		throw Span::SpanException (std::string(YELLOW) + "The container has reached its maximum size" + END_C);
	_span.push_back(nb);

}

//-------------------- Set/Get ----------------------------------------------//
//-------------------- Operators --------------------------------------------//
Span	&Span::operator=(Span const &instance)
{
	if (this != &instance)
	{
		_size = instance._size;
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