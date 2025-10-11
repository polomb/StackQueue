#include "zadacha.h"
#include "string.h"

#include <gtest.h>

TEST(ZadachaTest, Skobochki)
{
    Stack<char, std::vector> stack;
    string str1 = "({[]})";
    string str2 = "({[])}";
    string str3 = ")(";
    string str4 = "({[]}";


    EXPECT_TRUE(skobochki(str1, stack));
    EXPECT_FALSE(skobochki(str2, stack));
    EXPECT_FALSE(skobochki(str3, stack));
    EXPECT_FALSE(skobochki(str4, stack));
    //ADD_FAILURE();
}

//
//
//

TEST(ZadachaTest, DefaultConstructorCreatesEmptyQueue)
{
    QueueFromStack<int, std::vector> queue;

    EXPECT_TRUE(queue.empty());
    //ADD_FAILURE();
}

TEST(ZadachaTest, FrontReturnsFirstElement)
{
    QueueFromStack<int, std::vector> queue;

    queue.push(10);

    EXPECT_EQ(queue.front(), 10);

    queue.push(20);

    EXPECT_EQ(queue.front(), 10);

    queue.push(30);

    EXPECT_EQ(queue.front(), 10);
    //ADD_FAILURE();
}

TEST(ZadachaTest, BackReturnsLastElement)
{
    QueueFromStack<int, std::vector> queue;

    queue.push(10);

    EXPECT_EQ(queue.back(), 10);

    queue.push(20);

    EXPECT_EQ(queue.back(), 20);

    queue.push(30);

    EXPECT_EQ(queue.back(), 30);
    //ADD_FAILURE();
}

TEST(ZadachaTest, PopRemovesFrontElement)
{
    QueueFromStack<int, std::vector> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    EXPECT_EQ(queue.front(), 1);

    queue.pop();

    EXPECT_EQ(queue.front(), 2);

    queue.pop();

    EXPECT_EQ(queue.front(), 3);
    //ADD_FAILURE();
}

TEST(ZadachaTest, PopOnEmptyQueueThrowsException)
{
    QueueFromStack<int, std::vector> queue;

    EXPECT_ANY_THROW(queue.pop());
    //ADD_FAILURE();
}

TEST(ZadachaTest, FrontOnEmptyQueueThrowsException)
{
    QueueFromStack<int, std::vector> queue;

    EXPECT_ANY_THROW(queue.front());
    //ADD_FAILURE();
}

TEST(ZadachaTest, BackOnEmptyQueueThrowsException)
{
    QueueFromStack<int, std::vector> queue;

    EXPECT_ANY_THROW(queue.back());
    //ADD_FAILURE();
}

TEST(ZadachaTest, ClearMakesQueueEmpty)
{
    QueueFromStack<int, std::vector> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    EXPECT_FALSE(queue.empty());

    queue.clear();

    EXPECT_TRUE(queue.empty());
    //ADD_FAILURE();
}

TEST(ZadachaTest, QueueWorksWithDifferentDataTypes)
{
    QueueFromStack<std::string, std::vector> queue;
    queue.push("hello");
    queue.push("world");

    EXPECT_EQ(queue.front(), "hello");
    EXPECT_EQ(queue.back(), "world");

    queue.pop();

    EXPECT_EQ(queue.front(), "world");
    //ADD_FAILURE();
}

TEST(ZadachaTest, QueueMultiplePushPopOperations)
{
    QueueFromStack<int, std::vector> queue;

    for (int i = 0; i < 100; ++i)
    {
        queue.push(i);
        EXPECT_EQ(queue.back(), i);
        EXPECT_EQ(queue.front(), 0);
    }

    for (int i = 0; i < 100; ++i)
    {
        EXPECT_EQ(queue.front(), i);
        queue.pop();
    }
    //ADD_FAILURE();
}

TEST(ZadachaTest, QueueMaintainsFIFOOrder)
{
    QueueFromStack<int, std::vector> queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    EXPECT_EQ(queue.front(), 1);

    queue.pop();

    EXPECT_EQ(queue.front(), 2);

    queue.pop();

    EXPECT_EQ(queue.front(), 3);

    queue.pop();
    //ADD_FAILURE();
}

TEST(ZadachaTest, SmenyaemiePushPopOperations)
{
    QueueFromStack<int, std::vector> queue;

    queue.push(1);
    queue.push(2);

    EXPECT_EQ(queue.front(), 1);

    queue.pop();

    EXPECT_EQ(queue.front(), 2);

    queue.push(3);
    queue.push(4);

    EXPECT_EQ(queue.front(), 2);
    EXPECT_EQ(queue.back(), 4);

    queue.pop();

    EXPECT_EQ(queue.front(), 3);
    EXPECT_EQ(queue.back(), 4);
    //ADD_FAILURE();
}

//
//
//

TEST(ZadachaTest, DefaultConstructorCreatesEmptyStack)
{
    StackWithMin<int, std::vector> stack;

    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
    //ADD_FAILURE();
}

TEST(ZadachaTest, PushIncreasesSize)
{
    StackWithMin<int, std::vector> stack;

    stack.push(1);

    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.size(), 1);

    stack.push(2);

    EXPECT_EQ(stack.size(), 2);
    //ADD_FAILURE();
}

TEST(ZadachaTest, TopReturnsLastPushedElement)
{
    StackWithMin<int, std::vector> stack;

    stack.push(10);

    EXPECT_EQ(stack.top(), 10);

    stack.push(20);

    EXPECT_EQ(stack.top(), 20);

    stack.push(30);

    EXPECT_EQ(stack.top(), 30);
    //ADD_FAILURE();
}

TEST(ZadachaTest, PopRemovesTopElement)
{
    StackWithMin<int, std::vector> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.pop();

    EXPECT_EQ(stack.top(), 2);
    EXPECT_EQ(stack.size(), 2);

    stack.pop();

    EXPECT_EQ(stack.top(), 1);
    EXPECT_EQ(stack.size(), 1);
    //ADD_FAILURE();
}

TEST(ZadachaTest, PopOnEmptyStackThrowsException)
{
    StackWithMin<int, std::vector> stack;

    EXPECT_ANY_THROW(stack.pop());
    //ADD_FAILURE();
}

TEST(ZadachaTest, TopOnEmptyStackThrowsException)
{
    StackWithMin<int, std::vector> stack;

    EXPECT_ANY_THROW(stack.top());
    //ADD_FAILURE();
}

TEST(ZadachaTest, ClearMakesStackEmpty)
{
    StackWithMin<int, std::vector> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_FALSE(stack.empty());

    stack.clear();

    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
    //ADD_FAILURE();
}

TEST(ZadachaTest, StackMultiplePushPopOperations)
{
    StackWithMin<int, std::vector> stack;

    for (int i = 0; i < 100; ++i)
    {
        stack.push(i);
        EXPECT_EQ(stack.top(), i);
    }
    EXPECT_EQ(stack.size(), 100);

    for (int i = 99; i >= 0; --i)
    {
        EXPECT_EQ(stack.top(), i);
        stack.pop();
    }
    //ADD_FAILURE();
}

TEST(ZadachaTest, MinWorksInEveryPossibleWay)
{
    StackWithMin<int, std::vector> stack;

    stack.push(5);
    stack.push(18);
    stack.push(2);
    stack.push(15);
    stack.push(556);
    stack.push(52);
    stack.push(88005553535);
    stack.push(1);
    
    EXPECT_EQ(stack.min(), 1);
    stack.pop();
    EXPECT_EQ(stack.min(), 2);
    stack.pop();
    EXPECT_EQ(stack.min(), 2);
    stack.pop();
    EXPECT_EQ(stack.min(), 2);
    stack.pop();
    EXPECT_EQ(stack.min(), 2);
    stack.pop();
    EXPECT_EQ(stack.min(), 2);
    stack.pop();
    EXPECT_EQ(stack.min(), 5);
    stack.pop();
    EXPECT_EQ(stack.min(), 5);
    stack.pop();

    //ADD_FAILURE();
}