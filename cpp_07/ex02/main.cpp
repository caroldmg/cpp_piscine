
#include "Array.hpp"
#include <stdlib.h>

#define MAX_VAL 750
int main(int, char**)
{
    // Array<int> numbers(MAX_VAL);
    // int* mirror = new int[MAX_VAL];
    // srand(time(NULL));
    // for (int i = 0; i < MAX_VAL; i++)
    // {
	// 	const int value = rand();
    //     numbers[i] = value;
    //     mirror[i] = value;
    // }
    // //SCOPE
    // {
	// 	Array<int> tmp = numbers;
	// 	std::cout << "hey " << std::endl;
    //     Array<int> test(numbers);
    // }
	
    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     if (mirror[i] != numbers[i])
    //     {
    //         std::cerr << "didn't save the same value!!" << std::endl;
    //         return 1;
    //     }
    // }
    // try
    // {
    //     numbers[-2] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // try
    // {
    //     numbers[MAX_VAL] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     numbers[i] = rand();
    // }

	// set
	{
		
		try
		{
			Array<int> prueba(10);
			// std::cout << prueba->size() << std::endl;
	
			for (int i = 0; i < prueba.size(); i++)
			{
				// std::cout << "hety" << std::endl;
				prueba.set(i, i); 
			}
			prueba.push(5);
			for (int i = 0; i < prueba.size(); i++)
			{
				std::cout << "posicion " << i << "---> " << prueba[i] << std::endl;
			}
			/* code */
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
    // delete [] mirror;//
    return 0;
}
