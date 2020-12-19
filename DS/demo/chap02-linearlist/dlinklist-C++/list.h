#include <iostream>
#include <initializer_list>
#include <exception>

//双向链表
template <typename value_t>
class list
{
protected:
    //链表相关类型声明
    struct _node
    {
        value_t data;
        _node * next = nullptr, *pre = nullptr;
    };
    using node_ptr = _node *; //类型别名

    _node head, tail; //头尾节点
    size_t _size;

    void _init()
    {
        head.next = &tail;
        head.pre = nullptr;
        tail.pre = &head;
        tail.next = nullptr;
        _size = 0;
    }

    void _link(node_ptr p)
    {
        p->next = &tail;
        p->pre = tail.pre;
        tail.pre->next = p;
        tail.pre = p;
        ++_size;
    }

    template <typename container>
    void _copy_from(container&& c)
    {
        for (auto& e : c) push_back(e);
    }

    void _swap(list&& l)
    {
        std::swap(head, l.head);
        std::swap(tail, l.tail);
        std::swap(_size, l._size);
    }

public:
    using value_type = value_t;
    using reference = value_t&;
    using pointer = value_t*;

    list() noexcept
    {
        _init();
    }
    list(const std::initializer_list<value_t>& l) : list()
    {
        _copy_from(l);
    }
    list(const list& l) : list()
    {
        _copy_from(l);
    }
    list(list&& l) noexcept
    {
       _swap(l);
    }
    ~list() noexcept
    { 
        clear(); 
    }

    constexpr list& push_back(value_t d)
    {
        _link(new _node{d});
        return *this;
    }
    
    void clear()
    {
        for (auto p = head.next; p != &tail;)
        {
            auto q = p;
            p = p->next;
            delete q;
        }
        _init();
    }
    constexpr size_t size() const 
    { 
        return _size; 
    }
    constexpr bool empty() const
    {
        return _size == 0;
    }

    list& operator=(const list& l)
    {
        clear();
        _copy_from(l);
        return *this;
    }
    list& operator=(list&& l)
    {
        _swap(l);
        return *this;
    }
    value_t front() try
    {
        if (_size == 0) throw std::out_of_range("list is empty");
        return head.next->data;
    }
    catch (std::out_of_range& e)
    {
        static value_t t;
        std::cout << e.what() << std::endl;
        return t;
    }
    void pop() try
    {
        if (_size == 0) throw std::out_of_range("list is empty");

        auto p = head.next;
        head.next = p->next;
        p->next->pre = &head;
        delete p;
        --_size;
    }
    catch (std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }

    friend class iterator;
    using range = node_ptr;
    class iterator
    {
    private:
        range p;

    public:
        using value_type = typename list::value_type;
        using reference = typename list::reference;
        using pointer = typename list::pointer;

        iterator(range origin) : p(origin) {}
        iterator(const iterator& itr) : p(itr.p) {}

        iterator& operator=(const iterator& itr) 
        { 
            p = itr.p; 
            return *this; 
        }
        constexpr bool operator!=(const iterator& itr) const 
        { 
            return p != itr.p; 
        }
        constexpr iterator& operator++() 
        { 
            p = p->next; 
            return *this; 
        }
        constexpr iterator& operator--() 
        { 
            p = p->pre; 
            return *this; 
        }
        constexpr reference operator*() const 
        { 
            return p->data; 
        }
        iterator operator+(size_t span) const
        {
            iterator temp(p);
            for (size_t i = 0; i < span && temp.p != nullptr; ++i) 
                temp.p = temp.p->next;
            return temp;
        }
        iterator operator-(size_t span) const
        {
            iterator temp(p);
            for (size_t i = 0; i < span && temp.p != nullptr; ++i) 
                temp.p = temp.p->pre;
            return temp;
        }
    };

    constexpr iterator begin() { return iterator(head.next); }
    constexpr iterator end() { return iterator(&tail); }
    constexpr iterator rbegin() { return iterator(tail.pre); }
    constexpr iterator rend() { return iterator(&head); }
};
