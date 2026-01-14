#include "Array.hpp"


// para definir las funciones necesito hacerlo con templates
// CONSTRUCTORES Y DESTRUCTORES

template <typename T>
Array<T>::Array()
{
	std::cout << "Default Array construccor called" << std::endl;
	this->data = NULL;
	len = 0;
}

template <typename T>
Array<T>::Array(unsigned int n): len(n)
{
	this->data = new T[len];
	std::cout << this->len << std::endl;
}

template <typename T>
Array<T>::Array(const Array &org)
{
	if (this != &org)
	{
		this->len = org.len;
		this->data = new T[len];
		for (unsigned int i = 0; i < len; i++)
			this->data[i] = org.data[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] data;
}

// OPERATORS
template <typename T>
Array<T>& Array<T>::operator=(const Array &org)
{

	if (this != &org)
	{
		// if (this->data)
		delete[] this->data;
		this->len = org.len;
		this->data = new T[org.len];
		for (int i = 0; i < len; i++)
			this->data[i] = org.data[i];
	}
	return (*this);
}


/*  template <typename T>
Array<T>& Array<T>::operator=(Array<T> const& org)
{
	std::cout << "i" << std::endl;
	if (this == &org) {
		return *this;
	}
	delete[] this->data;
	this->data = new T[org.len];
	this->len = org.len;
	for (unsigned int i = 0; i < this->len; i++)
	{
		this->data[i] = org.data[i];
	}
	return *this;
} */

template <typename T>
T&	Array<T>::operator[](unsigned int idx)
{
	if (idx >= len)
		throw (Array::IndexOutOfBoundsException());
	return (this->data[idx]);
	
}


// CLASS METHODS

template <typename T>
int		Array<T>::size() const
{
	return (len);
}

template <typename T>
void	Array<T>::push(T element)
{
	len++;
	T* newData = new T[len];

    for (unsigned int i = 0; i < len - 1; i++)
        newData[i] = data[i];

    newData[len - 1] = element;
    delete[] data;
    data = newData;
}

template <typename T>
void	Array<T>::set(unsigned int idx, T val)
{
	this->data[idx] = val;
}

// EXCEPTIONS
template <typename T>
const char *Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return ("Index out of bounds.");
}