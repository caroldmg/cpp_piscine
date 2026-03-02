#include "PmergeMe.hpp"

// CONSTRUCTORS & DESTRUCTORS
PmergeMe::PmergeMe()
{
	throw EmptyConstructorException();
}

PmergeMe::PmergeMe(const PmergeMe &org)
{
	*this = org;
}

PmergeMe::PmergeMe(const std::vector<int>& unsortedVec) 
	: _vector(unsortedVec), 
	_deque(unsortedVec.begin(), unsortedVec.end())
{}

PmergeMe::~PmergeMe(){}

// OPERATORS

PmergeMe &PmergeMe::operator=(const PmergeMe &org)
{
    if (this == &org)
        return *this;
    this->_vector = org._vector;
    this->_deque  = org._deque;

    return *this;
}

// GETTERS
const std::vector<int>& PmergeMe::getVector() const
{
    return (_vector);
}

const std::deque<int>&	PmergeMe::getDeque() const
{
	return (_deque);
}

// OTHER CLASS METHODS

void	PmergeMe::sort()
{
	sortVector(this->_vector);
	sortDeque(this->_deque);
}

// VECTOR-RELATED METHODS

void	PmergeMe::sortVector(std::vector<int>& v)
{
	if (v.size() <= 1)
		return ;
	bool hasFrozen = false;
	int frozen;
	if (v.size() % 2 != 0)
	{
		frozen = v.back();
		v.pop_back();
		hasFrozen = true;
	}
	std::vector<std::pair<int, int> > pairs = makePairs(v);
	std::vector<int> mainChain = getBigOnes(pairs);
	std::vector<int> pendingChain = getSmallOnes(pairs);
	if (mainChain.size() > 1)
		sortVector(mainChain);
	insertPending(mainChain, pendingChain);
    
	if (hasFrozen)
		mainChain.push_back(frozen);
	v = mainChain;
}

std::vector<int> PmergeMe::getBigOnes(const std::vector<std::pair<int, int> > pairs)
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

std::vector<int> PmergeMe::getSmallOnes(const std::vector<std::pair<int, int> > pairs)
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


void	PmergeMe::insertPending(std::vector<int>& mainChain, std::vector<int>& pending)
{
	std::vector<int> order = getIndexOrder(pending.size());
	
	for (size_t i = 0; i < order.size(); ++i)
	{
		int idx = order[i];
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pending[idx]);
		mainChain.insert(it, pending[idx]);
	}
}

// DEQUE-RELATED METHODS
void PmergeMe::sortDeque(std::deque<int>& d)
{
	if (d.size() <= 1)
		return ;
	bool hasFrozen = false;
	int frozen;
	if (d.size() % 2 != 0)
	{
		frozen = d.back();
		d.pop_back();
		hasFrozen = true;
	}
	std::deque<std::pair<int, int> > pairs = makePairs(d);
	std::deque<int> mainChain = getBigOnes(pairs);
	std::deque<int> pendingChain = getSmallOnes(pairs);
	if (mainChain.size() > 1)
		sortDeque(mainChain);
	insertPending(mainChain, pendingChain);
    
	if (hasFrozen)
		mainChain.push_back(frozen);
	d = mainChain;
}

std::deque<int> PmergeMe::getBigOnes(const std::deque<std::pair<int, int> > pairs)
{
	std::deque<int> chain;
	std::deque<std::pair<int, int> >::const_iterator pair_it = pairs.begin();
	while (pair_it != pairs.end())
	{
		chain.push_back(pair_it->second);
		pair_it++;
	}
	return(chain);
}

std::deque<int> PmergeMe::getSmallOnes(const std::deque<std::pair<int, int> > pairs)
{
	std::deque<int> chain;
	std::deque<std::pair<int, int> >::const_iterator pair_it = pairs.begin();

	while (pair_it != pairs.end())
	{
		chain.push_back(pair_it->first);
		pair_it++;
	}
	return (chain);
}

void	PmergeMe::insertPending(std::deque<int>& mainChain, std::deque<int>& pending)
{
	std::vector<int> order = getIndexOrder(pending.size());
	
	for (size_t i = 0; i < order.size(); ++i)
	{
		int idx = order[i];
		std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pending[idx]);
		mainChain.insert(it, pending[idx]);
	}
}

// JACOBSTHAL SEQUENCE

std::vector<int>	PmergeMe::gen_jacobsthal(int idx)
{
	std::vector<int> seq;
	seq.push_back(0);
	seq.push_back(1);
	while (seq.back() < idx)
		seq.push_back(seq[seq.size() - 1] + 2 * seq[seq.size() - 2]);
	return seq;
}

std::vector<int> PmergeMe::getIndexOrder(int size)
{
	std::vector<int>	jacob_seq = gen_jacobsthal(size);
	std::vector<int>	order;
	int last = 0;

	for (int i = 1; i < (int)jacob_seq.size(); ++i)
	{
		int idx = jacob_seq[i];
		if (idx > size)
			idx = size;
		for (int j = idx; j > last; --j)
			order.push_back(j - 1);
		last = idx;
		if (idx == size)
			break;
	}
	return (order);
}

// FUERA DE LA CLASE

std::vector<int>	parseInput(int argc, char **argv)
{
	std::vector<int>	vec;
	long 				n;
	char*				endPtr;

	for (int i = 1; i < argc; i++)
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



std::vector<std::pair<int, int> > makePairs(const std::vector<int>& org)
{
    std::vector<std::pair<int, int> > pairs;

    for (size_t i = 0; i + 1 < org.size(); i += 2)
    {
        if (org[i] > org[i + 1])
            pairs.push_back(std::make_pair(org[i + 1], org[i]));
        else
            pairs.push_back(std::make_pair(org[i], org[i + 1]));
    }
    return pairs;
}

std::deque<std::pair<int, int> > makePairs(const std::deque<int>& org)
{
    std::deque<std::pair<int, int> > pairs;

    for (size_t i = 0; i + 1 < org.size(); i += 2)
    {
        if (org[i] > org[i + 1])
            pairs.push_back(std::make_pair(org[i + 1], org[i]));
        else
            pairs.push_back(std::make_pair(org[i], org[i + 1]));
    }
    return pairs;
}
