#include "PmergeMe.hpp"

// CONSTRUCTORS & DESTRUCTORS
PMergeMe::PMergeMe()
{
	throw EmptyConstructorException();
}

PMergeMe::PMergeMe(const PMergeMe &org)
{
	*this = org;
}

PMergeMe::PMergeMe(const std::vector<int>& unsortedVec) 
	: _vector(unsortedVec), 
	_deque(unsortedVec.begin(), unsortedVec.end()), 
	size(unsortedVec.size())
{}

PMergeMe::~PMergeMe(){}

// OPERATORS

PMergeMe &PMergeMe::operator=(const PMergeMe &org)
{
	// implementar
}

// OTHER CLASS METHODS

void	PMergeMe::sortVector(std::vector<int>& v)
{
	if (v.size() <= 1)
		return ;
	bool hasFrozen = false;
	int frozen;
	if (_vector.size() % 2 != 0)
	{
		frozen = v.back();
		v.pop_back();
		hasFrozen = true;
	}
	std::vector<std::pair<int, int> > pairs = makePairs(v);
	std::vector<int> mainChain = getBigOnesVector(pairs);
	std::vector<int> pendingChain = getSmallOnesVector(pairs);
	if (mainChain.size() > 1)
		sortVector(mainChain);
	insertPendingVector(mainChain, pendingChain);
}

void PMergeMe::sortDeque()
{}


// OUT-OF-CLASS METHODS
std::vector<int>	parseInput(int argc, char **argv)
{
	std::vector<int>	vec;
	long 				n;
	char*				endPtr;

	// 

	for (int i = 0; i < argc; i++)
	{
		n = std::strtol(argv[i], &endPtr, 10);
		if (
			*endPtr != '\0' ||
			std::string(argv[i]).empty() ||
			n < 0 ||
			n > INT_MAX ||
			(std::find(vec.begin(), vec.end(), n) != vec.end())
		)
		{
			throw std::runtime_error( RED "Error: Bad Input" RESET);
		}
		vec.push_back(static_cast<int>(n));
	}
	return (vec);
}

std::vector<int> PMergeMe::getBigOnesVector(const std::vector<std::pair<int, int>> pairs)
{
	std::vector<int> chain;
	std::vector<std::pair<int, int> >::const_iterator pair_it = pairs.begin();

	while (pair_it != pairs.end())
	{
		chain.push_back(pair_it->second);
		pair_it++;
	}
	return (chain);
}

std::vector<int> PMergeMe::getSmallOnesVector(const std::vector<std::pair<int, int>> pairs)
{
	std::vector<int> chain;
	std::vector<std::pair<int, int> >::const_iterator pair_it = pairs.begin();

	while (pair_it != pairs.end())
	{
		chain.push_back(pair_it->first);
		pair_it++;
	}
	return (chain);
}

void	PMergeMe::insertPendingVector(std::vector<int> mainChain, std::vector<int> pending)
{
	std::vector<int> j_seq = jacobsthal(pending.size());
}


std::vector<int>	PMergeMe::jacobsthal(int idx)
{
	std::vector<int> jacobsthal;
	int i = 1;
	int j = jacobIdx(i);

	while (j < idx)
	{
		jacobsthal.push_back(j);
		i++;
		j = jacobIdx(i);
	}
	return jacobsthal;
}

int jacobIdx(int n)
{
	if (n <= 0)
		return (0);
	else if (n == 1)
		return (1);
	else
		return (jacobIdx(n - 1) + (2 * jacobIdx(n - 2)));
}