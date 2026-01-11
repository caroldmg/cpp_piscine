#include "iter.hpp"

void	printStr(std::string &s)
{
	std::cout << s << std::endl;
}

void	printInt(int &i)
{
	std::cout << i << std::endl;
}

void	printWithLove(const std::string &s)
{
	std::cout << " 🩷  " << MAGENTA << s << " 🩷" << RESET << std::endl;
}

/**
 * sumar uno a cada uno de los elementos alfabeticos:
 * a = b, 
 * c = d, 
 * z = a;
 * 
 * -> std::isalpha(static_cast<unsigned char>(c))
 * isalpha recibe un valor en rango de unsigned char asiq ue casteamos para evitar valores raros
 * 
 * -> s[i] = 'a' + (c - 'a' + 1) % 26;
 * c - 'a' nos permite trabajar con números
 * + 1 le suma una posición
 * % 26 --- nos mantiene en el rango del alfabeto y asi no nos pasamos de la 'z'
 *  */
void	rotOne(std::string &s)
{
	char c;

	for (int i = 0; i < (int)s.size(); i++)
	{
		c= s[i];
		if (std::isalpha(static_cast<unsigned char>(c)))
		{
			if (c >= 'a' && c <= 'z')
				s[i] = 'a' + (c - 'a' + 1) % 26;
			else if (c >= 'A' && c <= 'Z')
				s[i] = 'A' + (c - 'A' + 1) % 26;
		}
	}

}

void	triple(int &n)
{
	n *= 3;
}