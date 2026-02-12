#pragma once

#define BLACK   "\033[1m\033[30m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define RESET   "\033[0m"

#include <iostream>
#include <stack>
#include <algorithm>

template <class T>
class MutantStack : public std::stack<T>
{
	public:
			// constructores, destructores
		MutantStack();
		MutantStack(const MutantStack &org);
		~MutantStack();
			// operadores
		MutantStack &operator=(const MutantStack &org);

		
			// variables
		typedef typename std::stack<T>::container_type::iterator it;
		/* 
			the c is a container_type defined in the stack class.
			c is the container, so c.begin() gets the first value
		*/
		it begin()
		{
			return (this->c.begin());
		}
		it end()
		{
			return (this->c.begin());
		}
		
};

#include "MutantStack.tpp"
