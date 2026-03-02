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

class	PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;

		// vector
		void				sortVector(std::vector<int>& v);
		std::vector<int> 	getBigOnes(const std::vector<std::pair<int, int> > pairs);
		std::vector<int> 	getSmallOnes(const std::vector<std::pair<int, int> > pairs);

		void				insertPending(std::vector<int>& mainChain, std::vector<int>& pending);

		// deque
		void				sortDeque(std::deque<int>& d);
		void				insertPending(std::deque<int>& mainChain, std::deque<int>& pending);
		std::deque<int> 	getBigOnes(const std::deque<std::pair<int, int> > pairs);
		std::deque<int> 	getSmallOnes(const std::deque<std::pair<int, int> > pairs);


		std::vector<int>		gen_jacobsthal(int idx);
		std::vector<int> 		getIndexOrder(int size);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &org);
		PmergeMe(const std::vector<int>& unsortedVec);
		~PmergeMe();

		PmergeMe	&operator=(const PmergeMe &org);

		const std::vector<int>&	getVector() const;
		const std::deque<int>&	getDeque() const;

		
		// hacer la jacobsthal privada

		void		sort();
		
	class	EmptyConstructorException : public std::exception
	{
		public:
		const char* what() const throw()
		{
			return "Error: empty constructor";
		}
	};
		
};
	
	// OTHER METHODS
std::vector<std::pair<int, int> > makePairs(const std::vector<int>& org);
std::deque<std::pair<int, int> > makePairs(const std::deque<int>& org);
std::vector<int>	parseInput(int argc, char **argv); 

int jacobIdx(int n);
std::vector<int> generateJacobOrder(const std::vector<int>& jac, int size);



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
