#include "Span.hpp"

int main()
{
    Span a = Span(5);

    a.addNumber(6);
    a.addNumber(3);
    a.addNumber(17);
    a.addNumber(9);
    a.addNumber(11);

    std::cout << a.shortestSpan() << std::endl;
    std::cout << a.longestSpan() << std::endl;

    return 0;
}