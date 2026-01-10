#include <iostream>


template<class T> void swap(T& a, T& b)
{
	T c(a);
	a = b;
	b = c;
}

template<class T> T min(T& a, T& b)
{
	if (a > b)
		return (b);
	return (a);
}

template<class T> T max(T& a, T& b)
{
	if (a > b)
		return (a);
	return (b);
}