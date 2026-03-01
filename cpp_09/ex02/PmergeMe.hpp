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
#include <vector>
#include <deque>
#include <limits.h>
#include <algorithm>

class	PMergeMe
{
	private:
		size_t				size;
		std::vector<int>	_vector;
		std::deque<int>		_deque;

		std::vector<int>	jacobsthal(int idx);
		void				sortVector();
		std::vector<int> 	getBigOnesVector(const std::vector<std::pair<int, int>> pairs);
		std::vector<int> 	getSmallOnesVector(const std::vector<std::pair<int, int>> pairs);
		void				insertPendingVector(std::vector<int> mainChain, std::vector<int> pending);


		void				sortDeque();

		// std::deque<int>		createDeque(std::vector<int> input);

	public:
		PMergeMe();
		PMergeMe(const PMergeMe &org);
		PMergeMe(const std::vector<int>& unsortedVec);
		~PMergeMe();

		PMergeMe	&operator=(const PMergeMe &org);

		
		
	class	EmptyConstructorException : public std::exception
	{
		public:
		const char* what() const throw()
		{
			return "Error: empty constructor";
		}
	};

	void	PMergeMe::sortVector(std::vector<int>& v);
		
};
	
	// OTHER METHODS
std::vector<int>	parseInput(int argc, std::string argv); //¿esta funcion tiene sentio dentro de la clase o deberia estar fuera y la paso como argumento para crear la instancia de la clase?
	/**
 * esta función comprueba que la lista esté ordenada.
 * Tenemos los iteradores prev y current para apuntar al elemento que estamos observando y el anterior y comparar sus valores.
 */
template <class T>
bool	isSorted(const T& cont)
{
	if (cont.empty() || cont.size() == 1)
		return (true);

	typename T::const_iterator prev = cont.begin();
	typename T::const_iterator current = prev + 1;

	while (current != cont.end())
	{
		if (*prev > **current)
			return (false);
		current++;
		prev++;
	}
	return (true);
}


template <template<class...> class Container>
Container<std::pair<int, int>> makePairs(const Container<int>& org)
{
	Container<std::pair<int, int>> pairs;

	for (size_t i = 0; i + 1 < org.size(); i +=2)
	{
		if (org[i] > org[i + 1])
			pairs.push_back(std::make_pair(org[i + 1], org[i]));
		else
			pairs.push_back(std::make_pair(org[i], org[i + 1]));
	}
	return (pairs);
}