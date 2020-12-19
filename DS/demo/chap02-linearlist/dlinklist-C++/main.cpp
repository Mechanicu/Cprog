#include <iostream>
#include "list.h"

int main()
{
    list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto e : l) std::cout << e << ' ';
    std::cout << std::endl;
    
    for (auto itr = l.begin() + 2; itr != l.begin() + 7; ++itr)
        std::cout << *itr << ' ';
    std::cout << std::endl;

    std::cout << l.front() << std::endl;
    l.pop();

    for (auto itr = l.rbegin() - 2; itr != l.rend(); --itr)
        std::cout << *itr << ' ';
    std::cout << std::endl;

    return 0;
}
