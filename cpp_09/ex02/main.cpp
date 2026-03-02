#include "PmergeMe.hpp"

// Función de testeo

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Error: program needs numbers to sort" << std::endl;
		return (1);
	}
	try
	{
		std::vector<int> vec = parseInput(argc, argv);
		PmergeMe prueba(vec);
		prueba.sort();
		std::cout << "Vector ordenado: ";
        for (size_t i = 0; i < vec.size(); ++i)
            std::cout << prueba.getVector()[i] << " "; 
        std::cout << "\n";
		std::cout << "deque ordenado: ";
        for (size_t i = 0; i < vec.size(); ++i)
            std::cout << prueba.getDeque()[i] << " "; 
        std::cout << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
    return 0;
}