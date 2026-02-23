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
#include <sstream>

class RPN
{
	private:
		std::stack<int> _data;
		bool	isValidInput(std::string argv);
		void	calculate(std::string argv);
		void	operatorHandler(char op);
		int		sum(int a, int b);
		int		substract(int a, int b);
		int		multiplication(int a, int b);
		int		division(int a, int b);
		int		getResult() const;
	public:
		RPN();
		RPN(const RPN &org);
		RPN(std::string argv);
		~RPN();

		RPN &operator=(const RPN &org);

		class EmptyConstructorException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Cannot calculate empty operation";
				}
		};

		class InvalidInputException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Invalid input";
				}
		};

		class DivisionByZeroException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "It is not possible to divide by Zero :/";
				}
		};
};

