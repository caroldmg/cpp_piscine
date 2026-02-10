#include "easyfind.hpp"

int main()
{
	{
		std::cout << "--- VECTOR ---" << std::endl;
		std::vector<int> v;
		int num = 1;
		// int num = 9;
	
		for(int i = 1; i < 7; i++)
			v.push_back(i);
		int r = easyfind(v, num);
		if (r >= 0)
			std::cout << "Number " << num <<  " found in index " << r << std::endl;
		else
			std::cout << "Number " << num << " not found" << std::endl;
	}
	{
		std::cout << "--- LIST ---" << std::endl;
		std::list<int> l;
		int num = 5;
		// int num = 9;
	
		for(int i = 1; i < 7; i++)
			l.push_back(i);
		int r = easyfind(l, num);
		if (r >= 0)
			std::cout << "Number " << num <<  " found in index " << r << std::endl;
		else
			std::cout << "Number " << num << " not found" << std::endl;
	}
	{
		std::cout << "--- DEQUE ---" << std::endl;
		std::deque<int> d;
		int num = 5;
		// int num = 9;
	
		for(int i = 1; i < 7; i++)
			d.push_back(i);
		int r = easyfind(d, num);
		if (r >= 0)
			std::cout << "Number " << num <<  " found in index " << r << std::endl;
		else
			std::cout << "Number " << num << " not found" << std::endl;
	}

}
