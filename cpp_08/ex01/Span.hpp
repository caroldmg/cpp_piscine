#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define GREEN "\033[0;32m"
#define RESET "\033[0m"

class Span
{
	private:
		std::vector<int> v;
		unsigned int max; 
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &org);
		~Span();

		Span &operator=(const Span &org);

		void	addNumber(int n);
		void	fillSpan(int min, int max);
		int		shortestSpan();
		int		longestSpan();

		class NoSpanPossibleException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "not enough numbers to generate a span";
				}
		};

		class StoreLimitReachedException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "cannot store more numbers: limit reached";
				}
		};
};