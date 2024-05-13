#include "../incs/easyFind.tpp"

const char *FindException::what() const throw()
{
	return (_errMsg.c_str());
}