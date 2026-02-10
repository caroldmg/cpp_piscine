#include "easyfind.hpp"

/**
 * @brief Searches for an integer value inside a container.
 * 
 * This template function takes a container and an integer to find.
 * It uses std::find to locate the integer in the container.
 * 
 * @tparam T Container type with const_iterator and begin/end methods.
 * @param a Container instance to search within.
 * @param i Integer value to search for.
 * @return int Returns the position in which its found, -1 if not found.
 */

template <typename T> int easyfind (T cont, int i)
{
	typename T::const_iterator it = std::find(cont.begin(), cont.end(), i);

	if (it != cont.end())
		return (std::distance(cont.begin(), it));
	else
		return (-1);
}
