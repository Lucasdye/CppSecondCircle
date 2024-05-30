
#include <vector>
#include <deque>
#include "../incs/easyFind.tpp"

int main(void)
{
	std::vector<int> tab(10, 4);
	std::deque<int> tab2(10, 4);

	tab.push_back(100);
	tab.push_back(200);
	try
	{
		easyFind(tab, 100022);
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	tab2.push_front(100022);
	try
	{
		easyFind(tab2, 100022);
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}