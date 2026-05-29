#include "MutantStack.hpp"

int main()
{
    MutantStack<int> a;
    a.push(5);
    a.push(17);

    std::cout << a.top() << std::endl;

    a.pop();
    
    std::cout << a.size() << std::endl;
    a.push(3);
    a.push(5);
    a.push(737);
    //[...]
    a.push(0);

    MutantStack<int>::iterator it = a.begin();
    MutantStack<int>::iterator ite = a.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(a);
    
    return 0;
}