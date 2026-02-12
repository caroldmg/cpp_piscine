#include "MutantStack.hpp"

// CONSTRUCTORES Y DESTRUCTORES

template <class T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << "Default mutantStack constructor called" << std::endl;
	
}

template <class T>
MutantStack<T>::MutantStack(const MutantStack<T> &org) : std::stack<T>(org)
{
	std::cout << "copy Mutantstack constructor called" << std::endl;

}

template <class T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack destructor called " << std::endl;
}

// OPERATORS

template <class T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &org)
{
	std::stack<T>::operator=(org);
	return (*this);
}

