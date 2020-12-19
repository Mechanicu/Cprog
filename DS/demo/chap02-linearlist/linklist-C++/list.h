#pragma once

#include <exception>

//这是一个类模板，value_t是类型参数
template <typename value_t>
class list final
{
public:
	//定义类型别名。using的功能类似于typedef
	using value_type = value_t;
	using pointer = value_t*;
	using reference = value_t&;

private:
	struct Node
	{ 
		value_type data;
		Node *next = nullptr; //C++允许在定义成员是完成初始化
	};

	using NodePtr = Node*;
	
	NodePtr L; //指向头结点的指针
	size_t length = 0;

public:
	//构造函数，功能相当于InitList()。在生成对象时自动调用
	list() noexcept
	{
		L = new Node;
	}
	//析构函数，在对象失效时自动调用
	~list() noexcept
	{
		clear();
		delete L;
	}

	//这个函数在插入位置不正确是要抛出异常，而不是返回假
	void insert(int i, reference e) try
	{
		NodePtr p = L;
		int k = 1;
		
		while (p != nullptr && k < i)
		{ 
			p = p->next;
			++k; 
		}
		
		if (p == nullptr && k < i)
			throw std::out_of_range("insertion position is out of range");

		auto q = new Node{e}; //分配内存并完成初始化
		q->next = p->next;
		p->next = q;
		
		++length;
	}
	catch (std::out_of_range& err) //捕获异常
	{
		std::cout << err.what() << std::endl;
	}

	void insert(int i, value_type&& e)
	{
		value_type& x = e;
		insert(i, x);
	}

	void erase(int i) try
	{
		NodePtr p = L, q;
		int k = 1;
		
		while (p != nullptr && k < i)
		{ 
			p = p->next;
			++k; 
		}
		
		if (p == nullptr && k < i)
			throw std::out_of_range("deletion position is out of range");

		q = p->next;
		p->next = q->next;
		delete q;

		--length;
	}
	catch (std::out_of_range& err) //捕获异常
	{
		std::cout << err.what() << std::endl;
	}

	reference top() try
	{
		if (!empty())
			return L->next->data;

		throw std::out_of_range("list is empty");
	}
	catch (std::out_of_range& err)
	{
		std::cout << err.what() << std::endl;
		//to avoid compiling warning
		static value_type v;
		return v;
	}

	bool empty() const
	{
		return length == 0;
	}

	bool full() const
	{
		return false;
	}

	void push_front(reference e)
	{
		insert(1, e);
	}

	void push_back(reference e)
	{
		insert(length + 1, e);
	}

	void pop_front()
	{
		erase(1);
	}

	void pop_back()
	{
		erase(length);
	}

	void clear()
	{
		NodePtr p = L->next, q; //类型自动推导
		while (p != nullptr)
		{
			q = p;
			p = p->next;
			delete q;
		}
		length = 0;
	}

	//类模板中的函数模板
	template <typename callback>
	void traverse(callback f)
	{
		auto p = L->next;
		while (p != nullptr)
		{
			f(p->data);
			p = p->next;
		}
	}
};