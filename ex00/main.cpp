#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <exception>

int main()
{
    std::cout << "--- testing with non-const std::vector<int> ---\n" <<std::endl;
    std::vector<int>    a;

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);

    try
    {
        std::vector<int>::iterator it = easyfind(a, 6);
        std::cout << "Found: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(a, 8);
        std::cout << "Found: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "--- testing with const std::vector<int> ---\n" << std::endl;
    
    const std::vector<int>  b(a);
    try
    {
        std::vector<int>::const_iterator it = easyfind(b, 3);
        std::cout << "Found in const vector: " << *it << '\n' << std::endl;
        // *it = 2; //compile error
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}