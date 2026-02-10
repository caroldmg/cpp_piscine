#include "Span.hpp"

Span::Span(): max(0)
{
	std::cout << "Span: default constructor called" << std::endl;
}

Span::Span(unsigned int n): max(n)
{}

Span::Span(const Span &org)
{
	this->max = org.max;
	this->v = org.v;
}

Span::~Span()
{
	std::cout << "Span: default destructor called " << std::endl;
}

// OPERATORS

Span &Span::operator=(const Span &org)
{
	std::cout << "Span: assignation operator called" << std::endl;
	if (this != &org)
	{
		this->max = org.max;
		this->v = org.v;
	}
	return (*this);
}

// MEMBER FUNCTIONS

void Span::addNumber(int n)
{
	if (v.size() == max)
		throw (Span::StoreLimitReachedException());
	v.push_back(n);
}

void Span::fillSpan(int min, int max)
{
	// int range = max - min;
	int spaceLeft = this->max - v.size();
	int num;
	// Así pues, para simular una generación de números pseudo-aleatorios entre el número A y el número B (ambos incluidos), la siguiente fórmula se cumple:
	// (rand() % (B - A + 1)) + A

	for (int i = 0; i < spaceLeft; i++)
	{
		num = (rand() % (max - min + 1)) + min; 
		this->addNumber(num);
	}
}

int Span::shortestSpan()
{
	// si no hay o solo uno, chau
	// std::sort
	int span = INT_MAX;

	if (this->v.empty() || this->v.begin() == this->v.end())
		throw (Span::NoSpanPossibleException());
	std::sort(this->v.begin(), this->v.end());

	std::vector<int>::iterator it = v.begin();
	int tmp;
	while (it + 1 != v.end())
	{
		tmp = *(it + 1) - *it;
		if (tmp < span)
			span = tmp;
		it++;
	}
	return (span);
}

int Span::longestSpan()
{
	int max = *std::max_element(this->v.begin(), this->v.end());
	int min = *std::min_element(this->v.begin(), this->v.end());
	return (max - min);
}