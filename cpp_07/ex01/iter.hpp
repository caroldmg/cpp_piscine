Function templates with multiple template type parameters

The root of our problem is that we’ve only defined the single template type (T) for our function template, and then specified that both parameters must be of this same type.

The best way to solve this problem is to rewrite our function template in such a way that our parameters can resolve to different types. Rather than using one template type parameter T, we’ll now use two (T and U):

#include <iostream>

template <typename T, typename U> // We're using two template type parameters named T and U
T max(T x, U y) // x can resolve to type T, and y can resolve to type U
{
    return (x < y) ? y : x; // uh oh, we have a narrowing conversion problem here
}

int main()
{
    std::cout << max(2, 3.5) << '\n'; // resolves to max<int, double>

    return 0;
}