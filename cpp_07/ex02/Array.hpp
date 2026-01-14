#pragma once

#include <iostream>

template <typename T>
class Array
{
	private:
		T* data;
		unsigned int len;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &org);
		// supongo que tambien elementos del tipo T
		~Array();
		Array&	operator=(Array const& org);
		T&		operator[](unsigned int idx);

		int		size() const;
		void	push(T element);
		void	set(unsigned int i, T val);

		class IndexOutOfBoundsException : public std::exception
		{
			public:
				const char* what() const throw();
		};

};


#include "Array.tpp"