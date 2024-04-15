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


class FindException : public std::exception
{
	private:
		const std::string _errMsg;
	public:
		FindException(const std::string& msg): _errMsg(msg) {};
		~FindException() throw() {};
		const char *what() const throw();
};

template <typename T> // The template typename T allows us to receive any type of contatainer of any type.
void easyFind(const T& container, int find)
{
	typename T::const_iterator it;// the container::iterator 'it' will be the type within the para 'container'.
	FindException NotFound(std::string(RED) + "The value wasn't find in the container" + std::string(END_C));
	for (it = container.begin(); it != container.end(); it++)
	{
		if (*it == find)
		{	
			std::cout << GREEN << "The value " << find << " has been found " << END_C << std::endl;
			return ;
		}
	}
	throw NotFound;
	return ;
};

#endif 