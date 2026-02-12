#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		std::cout << BLUE << "MUTANT STACK TEST" << RESET << std::endl;
			
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << GREEN << "The first element in the list is: " << mstack.top() << RESET << std::endl;
		mstack.pop();
		std::cout << GREEN << "The size of the actual list is: " << mstack.size() << RESET << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		// //[...]
		mstack.push(0);
		MutantStack<int>::it it = mstack.begin();
		MutantStack<int>::it ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "═════════════════════════════════════════════════════════\n";
	std::cout << "-- ..- - .- - . -.. / .- -... --- -- .. -. .- - .. --- -.\n";
	std::cout << "═════════════════════════════════════════════════════════\n";
	{
		std::cout << BLUE "STD::LIST STACK TEST" << RESET << std::endl;
			
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << GREEN << "The first element in the list is: " << mstack.back() << RESET << std::endl;
		mstack.pop_back();
		std::cout << GREEN << "The size of the actual list is: " << mstack.size() << RESET << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		// //[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}
	return 0;
}