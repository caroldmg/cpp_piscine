#pragma once

#include <iostream>
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define RESET   "\033[0m"

// elementos const
template<typename T, typename F> void iter(const T* array, const int len, F function)
{
	std::cout << CYAN << "const version" << RESET << std::endl;
	for (int i = 0; i < len; i++)
		function(array[i]);
}

/**
 * Sobrecarga de funciones para poder adaptar a elementos const y no const, es decir, que permitan variar
 *  */
template<typename T, typename F>void iter(T* array, const int len, F function)
{
	std::cout << CYAN << "iter non const version" << RESET << std::endl;
	for (int i = 0; i < len; i++)
		function(array[i]);
}

//OTHER METHODS
void	printStr(std::string &s);
void	printInt(int &i);
void	printWithLove(const std::string &s);
void	rotOne(std::string &s);
void	triple(int &n);