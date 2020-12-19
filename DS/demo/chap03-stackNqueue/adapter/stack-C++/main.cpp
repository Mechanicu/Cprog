#include <iostream>

#include "stack.h"

int main()
{
    stack<char> s;
    auto print = [](auto& v) { std::cout << v << ' '; };

    char c;
    for (c = 'A'; c < 'Z'; ++c)
        s.push(c);
    s.push('Z');
    s.stack_walk(print);

    for (int i = 0; i < 10; ++i)
    {
        c = s.top();
        s.pop();
    }

    std::cout << "\nThe last popped: " << c << std::endl;
    s.stack_walk(print);
    std::cout << std::endl;

    return 0;
}