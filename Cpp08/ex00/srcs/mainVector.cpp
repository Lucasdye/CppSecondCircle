
#include <vector>
#include <iostream>
#include "../incs/easyFind.tpp"

int main(void)
{
	std::vector<int> tab(10, 4);

	std::cout << "\t Accessing value by deferencing vector tab with indexes And no iterator usage" << std::endl;
	for (size_t i = 0; i < tab.size(); i++)
	{
		tab[i] += i;
		std::cout << tab[i] << std::endl;
	}
	std::cout << "Max size " << tab.max_size() << std::endl;
	std::cout << "Max capacity " << tab.capacity() << std::endl;
	tab.push_back(100);
	std::cout << "Last value " << tab.back() << std::endl; 
	std::cout << "Shrinking capacity to the minimum of what the vector contains with shrink_to_fit... " << std::endl;
	tab.shrink_to_fit();
	std::cout << "Max capacity " << tab.capacity() << std::endl;
	tab.push_back(200);
	std::cout << "New last value after shrinking " << tab.back() << std::endl;
	std::cout << "Max capacity " << tab.capacity() << std::endl;
	std::cout << "Shrinking AGAIN the capacity to the minimum of what the vector contains with shrink_to_fit... " << std::endl;
	tab.shrink_to_fit();
	std::cout << "Max capacity " << tab.capacity() << std::endl;
	std::cout << "Accessing with at(0) " << tab.at(0) << std::endl;
	std::cout << "Modifying value by indexing [0] "; tab[0] = 1000; std::cout << "Accessing with at(0) " << tab.at(0) << std::endl;
	std::cout << "Accessing underlying contiguous storage with tab.data() " << tab.data() << std::endl;
	std::cout << std::endl;
	std::cout << "\t Accessing/Modifying values with iterators vector tab with indexes And no iterator usage" << std::endl;
	std::vector<int>::const_iterator it;
	std::cout << "Erasing the third element" << std::endl;
	it = tab.begin() + 2;
	tab.erase(it);
	for (it = tab.begin(); it != tab.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "Erasing the first, befor last and last elements" << std::endl;
	it = tab.end(); it -= 1; tab.erase(it); it -= 1; tab.erase(it); it = tab.begin(); tab.erase(it);
	for (it = tab.begin(); it != tab.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "Testing easyFind()" << std::endl;
	try
	{
		easyFind(tab, 100022);
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}
	
	return 0;
}