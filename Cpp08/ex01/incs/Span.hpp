#ifndef SPAN_HPP
# define SPAN_HPP

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


# include <vector>
# include <iostream>
# include <cstdlib>
# include <string>
# include <algorithm>
# include <limits>

class Span
{
	private:
		std::vector<int> 	_span;
		unsigned int 		_maxSize; //specified by the compiler. 
		unsigned int		_size; //specified by the dev

	public:
	//-------------------- funcs --------------------------------------------//
		int		shortestSpan();
		int		longestSpan();
		void	addNumber(int nb);
	//-------------------- Set/get ------------------------------------------//
	//-------------------- Constructor/Destructor ---------------------------//
				Span();
				Span(unsigned int size);
				Span(Span const &instance);
				~Span();
	//-------------------- Operator -----------------------------------------//
		Span&	operator=(Span const &instance);
	//-------------------- Exception Class ----------------------------------//
		class SpanException: public std::exception
		{
			private:
				std::string	_errMsg;
			
			public:
				SpanException();
				SpanException(std::string errMsg);
				~SpanException() throw() {};
				virtual const char *what() const throw();
		};
};

#endif