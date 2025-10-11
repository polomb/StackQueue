#ifndef __Queue__
#define __Queue__

#include <iostream>
#include <vector>

const double CONST = 2;

template<class T, template<class T, typename...> class TContainer = std::vector>
class Queue
{
    TContainer<T> data;
    size_t start;
    size_t finish;
    size_t count;

    void resizeIfItNeeds()
    {
        if (count == data.size())
        {
            size_t dopCap = (size_t)((double)data.size() * CONST);
            if (dopCap == 0) 
            {
                dopCap = 1;
            }
            TContainer<T> dopData(dopCap);

            if (start < finish)
            {
                for (size_t i = start; i < finish; ++i)
                {
                    dopData[i - start] = std::move(data[i]);
                }
            }
            else if (count > 0)
            {
                size_t fromStartToEnd = data.size() - start;
                for (size_t i = start; i < data.size(); ++i)
                {
                    dopData[i - start] = std::move(data[i]);
                }
                for (size_t i = 0; i < finish; ++i)
                {
                    dopData[fromStartToEnd + i] = std::move(data[i]);
                }
            }
            data = move(dopData);
            start = 0;
            finish = count;
        }
    }
public:
    Queue() : start(0), finish(0), count(0)
    {
        data.resize(1);
    }
    //
    void push(const T& el)
    {
        resizeIfItNeeds();
        data[finish] = el;
        finish = (finish + 1) % data.size();
        count++;
    }
    void push(T&& el)
    {
        resizeIfItNeeds();
        data[finish] = std::move(el);
        finish = (finish + 1) % data.size();
        count++;
    }
    void pop()
    {
        if (empty())
        {
            throw std::out_of_range("Queue is empty");
        }
        start = (start + 1) % data.size();
        count--;
    }
    //
    T front() const
    {
        if (empty())
        {
            throw std::out_of_range("Queue is empty");
        }
        return data[start];
    }
    T back() const
    {
        if (empty())
        {
            throw std::out_of_range("Queue is empty");
        }
        if (finish == 0)
            return data[data.size() - 1];
        return data[finish - 1];
    }
    //
    size_t size() const
    {
        return count;
    }
    void clear()
    {
        start = 0;
        finish = 0;
        count = 0;
    }
    bool empty() const
    {
        return count == 0;
    }
};

#endif

