#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>

#define BLACK   "\033[1m\033[30m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define RESET   "\033[0m"

class Base
{
	public:
		virtual ~Base();
};

// other methods

Base	*generate();
void	identify(Base* p);
void	identify(Base& p);