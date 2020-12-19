#pragma once

#include <exception>
#include <string>

template <typename value_t>
class list final
{
public:
    using value_type = value_t;
    using pointer = value_type*;
    using reference = value_type&;

private:
    //the storage model is doubly linked list
    struct node
    {
        value_type data;
        node *prior = nullptr;
        node *next = nullptr;
    };

    using nodeptr = node*;

    node head, tail; //head and tail node
    size_t _size = 0;

public:
    list() noexcept
    {
        head.next = &tail;
        tail.prior = &head;
    }

    ~list() noexcept
    {
        clear();
    }

    void push_front(reference x)
    {
        auto p = new node{x, &head, head.next};
        
        head.next->prior = p;
        head.next = p;

        ++_size;
    }

    void push_front(value_type&& x)
    {
        reference y = x;
        push_front(y);
    }

    void push_back(reference x)
    {  
        auto p = new node{x, tail.prior, &tail};

        tail.prior->next = p;
        tail.prior = p;

        ++_size;
    }

    void push_back(value_type&& x)
    {
        reference y = x;
        push_back(y);
    }

    void pop_front() try
    {
        if (empty())
            throw std::out_of_range("the container is empty");

        auto p = head.next;
        head.next = p->next;
        p->next->prior = &head;

        delete p;

        --_size;
    }
    catch (std::out_of_range& err)
    {
        std::cout << err.what() << std::endl;
    }

    void pop_back() try
    {
        if (empty())
            throw std::out_of_range("the container is empty");

        auto p = tail.prior;
        tail.prior = p->prior;
        p->prior->next = &tail;

        delete p;

        --_size;
    }
    catch (std::out_of_range& err)
    {
        std::cout << err.what() << std::endl;
    }

    reference front() try
    {
        if (empty())
            throw std::out_of_range("the container is empty");

        return head.next->data;
    }
    catch (std::out_of_range& err)
    {
        std::cout << err.what() << std::endl;
        static value_type x;
        return x;
    }

    reference back() try
    {
        if (empty())
            throw std::out_of_range("the container is empty");

        return tail.prior->data;
    }
    catch (std::out_of_range& err)
    {
        std::cout << err.what() << std::endl;
        static value_type x;
        return x;
    }

    bool empty()
    {
        return _size == 0;
    }

    bool full()
    {
        return false;
    }

    void clear()
    {
        nodeptr p = head.next, q;
        while (p != &tail)
        {
            q = p;
            p = p->next;
            delete q;
        }

        head.next = &tail;
        tail.prior = &head;
        _size = 0;
    }

    template <typename callback>
    void traverse(callback f)
    {
        auto p = head.next;
        while (p != &tail)
        {
            f(p->data);
            p = p->next;
        }
    }
};