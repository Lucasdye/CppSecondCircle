#ifndef BASE_HPP
# define BASE_HPP

# pragma once
# include "baseH.hpp"

class A;
class B;
class C;

class Base
{
	private:

	public:
		//-------------------- funcs --------------------------------------------//
		Base *generate(void);
		void identify(Base* p);
		void identify(Base& p);
		//-------------------- Set/get ------------------------------------------//
		//-------------------- Constructor/Destructor ---------------------------//
	   	Base();
	   	Base(Base const & src);
	    virtual ~Base();
		//-------------------- Operators ----------------------------------------//
	   	Base& operator=(Base const & instance);
};

#endif
