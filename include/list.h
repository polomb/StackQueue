#ifndef __List__
#define __List__

#include <iostream>
#include <vector>

template<class T>
class ForwardList
{
    struct Node
    {
        T data;
        Node* next = nullptr;
        //
        //Node() : data(), next() {}
        Node(const T& value) : data(value), next(nullptr) {}
        Node(T&& value) : data(std::move(value)), next(nullptr) {}
    };
    Node* first = nullptr;
public:
    ForwardList(size_t n, const T& value = T{})
    {
        if (n == 0) return;
        first = new Node(default);
        Node* cur = first;
        for (size_t i = 1; i < n; i++)
        {
            cur->next = new Node(default);
            cur = cur->next;
        }
    }
    //Правило пяти?
    ForwardList(const ForwardList& other)
    {
        if (!other.empty())
        {
            Node* cur = other.first;
            Node* last = nullptr;
            while (cur != nullptr)
            {
                Node* newNode = new Node(cur->data);
                if (last == nullptr)
                {
                    first = newNode;
                }
                else
                {
                    last->next = newNode;
                }
                last = newNode;
                cur = cur->next;
            }
        }
    }
    ForwardList& operator=(const ForwardList& other)
    {
        if (this != &other)
        {
            clear();

            Node* cur = other.first;
            Node* last = nullptr;

            while (cur != nullptr)
            {
                Node* newNode = new Node(cur->data);

                if (last == nullptr)
                {
                    first = newNode;
                }
                else
                {
                    last->next = newNode;
                }
                last = newNode;
                cur = cur->next;
            }
        }
        return *this;
    }
    ~ForwardList()
    {
        clear();
    }
    ForwardList(ForwardList&& other) noexcept : first(other.first)
    {
        other.first = nullptr;
    }
    ForwardList& operator=(ForwardList&& other) noexcept
    {
        if (this != &other)
        {
            clear();

            first = other.first;

            other.first = nullptr;
        }
        return *this;
    }
    //
    bool empty() const
    {
        return (first == nullptr);
    }
    void clear()
    {
        while (!empty())
        {
            pop_front();
        }
    }
    //
    T& front()
    {
        if (empty())
        {
            throw std::out_of_range("Error_T& front():List is empty");
        }
        return first->data;
    }
    const T& front() const
    {
        if (empty())
        {
            throw std::out_of_range("Error_const T& front() const:List is empty");
        }
        return first->data;
    }
    //
    void push_front(const T& value)
    {
        Node* newNode = new Node(value);
        newNode->next = first;
        first = newNode;
    }
    void push_front(T&& value)
    {
        Node* newNode = new Node(std::move(value));
        newNode->next = first;
        first = newNode;
    }
    void pop_front()
    {
        if (!empty())
        {
            Node* tmp = first;
            first = first->next;
            delete tmp;
        }
    }
    //
    template<class Iterator>
    Iterator insert_after(Iterator pos, const T& value)
    {
        Node* newNode = new Node(value);
        Node* cur = pos.ptr;
        newNode->next = cur->next;
        cur->next = newNode;
        return Iterator(newNode);
    }
    template<class Iterator>
    Iterator erase_after(Iterator pos)
    {
        if (pos.ptr == nullptr || pos.ptr->next == nullptr)
        {
            return Iterator(nullptr);
        }
        Node* del = pos.ptr->next;
        pos.ptr->next = del->next;
        delete del;
        return Iterator(pos.ptr->next);
    }
};

#endif

