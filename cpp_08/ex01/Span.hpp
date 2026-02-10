#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

class Span
{
	private:
		std::vector<int> v;
		unsigned int max; //max numbers that span can store
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &org);
		~Span();

		Span &operator=(const Span &org);

		void	addNumber(int n);
		void	fillSpan(int min, int max);
		int		shortestSpan();
		// find the shortes distance between al the nums stored,
		// if no numbers are stored or only one, no san -> exception
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