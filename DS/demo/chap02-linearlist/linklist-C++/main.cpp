#include <iostream>

#include "list.h"

//函数模板。value_type是类型参数
template <typename value_type>
void print(value_type& e)
{
   std::cout << e << ' ';
}

int main()
{
    list<int> l;
    
    for (int i = 1; i < 10; ++i)
        l.insert(i, i + 10);
    l.insert(100, 99); //这个调用会引发异常

    l.traverse(print<int>);
    std::cout << std::endl; //换行

    return 0;
}