#pragma once

#include "list.h"

//stack: adapter of linear-list
//using underlying container to access element
template <typename value_t, typename container_t = list<value_t>>
class stack final
{
public:
    using value_type = container_t::value_type;
    using pointer = container_t::pointer;
    using reference = container_t::reference;

private:
    container_t c; //underlying container, usually is deque. in this case, it's a doubly linked list

public:
    stack() {}
    //copy is banned
    stack(const stack&) = delete;
    stack(stack&&) = delete;
    ~stack() {}

    void push(reference e)
    {
        c.push_back(e);
    }

    void push(value_type&& e)
    {
        c.push_back(e);
    }

    void pop()
    {
        c.pop_back();
    }

    reference top()
    {
        return c.back();
    }

    void clear()
    {
        c.clear();
    }

    bool empty() const
    {
        return c.empty();
    }

    bool full() const
    {
        return c.full();
    }

    template <typename callback>
	void stack_walk(callback f)
    {
        c.traverse(f);
    }
};