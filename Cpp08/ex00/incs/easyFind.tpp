#ifndef EASYFIND_TPP
# define EASYFIND_TPP


# ifndef RED
#  define RED "\033[31m"
# endif

# ifndef GREEN
#  define GREEN "\033[32m"
# endif

# ifndef END_C
#  define END_C "\033[0m"
# endif

# include <iostream>
# include <cstdlib>
# include <string>
# include <algorithm>


class FindException : public std::exception
{
	private:
		const std::string _errMsg;
	public:
		FindException(const std::string& msg): _errMsg(msg) {};
		virtual ~FindException() throw() {};
		const char *what() const throw();
};

template <typename T> // The template typename T allows us to receive any type of container of any type.
void easyFind(const T& container, int find)
{
	FindException NotFound(std::string(RED) + "The value wasn't find in the container" + std::string(END_C));
	if (std::find(container.begin(), container.end(), find) == container.end())
		throw NotFound;
	return ;
};

#endif 