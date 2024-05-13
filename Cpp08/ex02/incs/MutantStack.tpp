#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include <stack>
# include <deque>
# include <iostream>
# include <algorithm>
# include <list>
# include <stack>

template <typename T, class Container = std::deque <T> >
class MutantStack: public std::stack<T, Container>
{
	private:
	public:
		MutantStack() {};
		~MutantStack() {};
		MutantStack(MutantStack const &instance): std::stack<T, Container>(instance) {
		};
		MutantStack& operator=(MutantStack const &instance) {
			return (instance);
		};
		typedef typename Container::iterator iterator; // typename is essential for the compiler to understand that it's a type and not a static variable
		iterator begin() {return (this->c.begin());};
		iterator end() {return (this->c.end());};
};

#endif