#ifndef __Zadacha__
#define __Zadacha__

#include <iostream>
#include <algorithm>
#include "queue.h"
#include "stack.h"
#include "string.h"

using namespace std;

//Задача 1
bool skobochki(string str, Stack<char, std::vector> stack)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			stack.push(str[i]);
		}
		else
		{
			if (stack.empty() != 1 && stack.top() == '(' && str[i] == ')')
			{
				stack.pop();
			}
			else if (stack.empty() != 1 && stack.top() == '{' && str[i] == '}')
			{
				stack.pop();
			}
			else if (stack.empty() != 1 && stack.top() == '[' && str[i] == ']')
			{
				stack.pop();
			}
			else
			{
				return 0;
			}
		}
	}
	return stack.empty();
}
//Задача 2
template<class T, template<class U, typename...> class TContainer = std::vector>
class QueueFromStack
{
    Stack<T, std::vector> stack1;
    Stack<T, std::vector> stack2;
public:
    QueueFromStack() = default;
    //
    void push(const T& el)
    {
        stack1.push(el);
    }
    void pop()
    {
        if (stack1.empty() && stack2.empty())
        {
            throw out_of_range("Queue is empty");
        }
        if (stack2.empty() != 1)
        {
            stack2.pop();
        }
        else
        {
            while (stack1.empty() != 1)
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            stack2.pop();
        }
    }
    //
    T front()
    {
        if (stack2.empty())
        {
            if (stack1.empty())
            {
                throw out_of_range("stack2 is empty");
            }
            else
            {
                while (!stack1.empty())
                {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
        }
        return stack2.top();
    }
    T back()
    {
        if (stack1.empty())
        {
            if (stack2.empty())
            {
                throw out_of_range("stack1 is empty");
            }
            else
            {
                while (stack2.empty() != 1)
                {
                    stack1.push(stack2.top());
                    stack2.pop();
                }
                T dop = stack1.top();
                while (stack1.empty() != 1)
                {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
                return dop;
            }
        }
        return stack1.top();
    }
    //
    size_t size() const
    {
        return stack1.size() + stack2.size();
    }
    //
    void clear()
    {
        stack1.clear();
        stack2.clear();
    }
    bool empty() const
    {
        return stack1.empty() && stack2.empty();
    }
};
//Задача 3
template<class T, template<class U, typename...> class TContainer = std::vector>
class StackWithMin
{
    Stack<T, std::vector> stack1;
    Stack<T, std::vector> stack2;
public:
    StackWithMin() = default;
    //
    void push(const T& el)
    {
        stack1.push(el);
        if (stack2.empty())
        {
            stack2.push(el);
        }
        else
        {
            stack2.push(std::min(el, stack2.top()));
        }
    }
    void pop()
    {
        if (stack1.empty())
        {
            throw out_of_range("Stack is empty");
        }
        stack1.pop();
        stack2.pop();
    }
    //
    T& top()
    {
        if (stack1.empty())
        {
            throw out_of_range("Stack is empty");
        }
        return stack1.top();
    }
    const T& top() const
    {
        if (stack1.empty())
        {
            throw out_of_range("Stack is empty");
        }
        return stack1.top();
    }
    //
    size_t size() const
    {
        return stack1.size();
    }
    T& min()
    {
        if (stack1.empty())
        {
            throw out_of_range("Stack is empty");
        }
        return stack2.top();
    }
    //
    void clear()
    {
        stack1.clear();
        stack2.clear();
    }
    bool empty() const
    {
        return stack1.empty();
    }
};

#endif

