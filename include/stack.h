#ifndef __Stack__
#define __Stack__

#include <iostream>
#include <vector>

template<class T, template<class T, typename...> class TContainer = std::vector>
class Stack
{
    TContainer<T> data;
public:
    Stack() = default;
    //
    void push(const T& el)
    {
        data.push_back(el);
    }
    void pop()
    {
        if (empty())
        {
            throw std::out_of_range("Stack is empty");
        }
        data.pop_back();
    }
    //
    T& top()
    {
        if (empty())
        {
            throw std::out_of_range("Stack is empty");
        }
        return data.back();
    }
    const T& top() const
    {
        if (empty())
        {
            throw std::out_of_range("Stack is empty");
        }
        return data.back();
    }
    //
    size_t size() const
    {
        return data.size();
    }
    //
    void clear()
    {
        data.clear();
    }
    bool empty() const
    {
        return data.empty();
    }
};

#endif

