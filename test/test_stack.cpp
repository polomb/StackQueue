#include "stack.h"

#include <gtest.h>

TEST(StackTest, DefaultConstructorCreatesEmptyStack)
{
    Stack<int, std::vector> stack;

    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
    //ADD_FAILURE();
}

TEST(StackTest, PushIncreasesSize)
{
    Stack<int, std::vector> stack;

    stack.push(1);

    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.size(), 1);

    stack.push(2);

    EXPECT_EQ(stack.size(), 2);
    //ADD_FAILURE();
}

TEST(StackTest, TopReturnsLastPushedElement)
{
    Stack<int, std::vector> stack;

    stack.push(10);

    EXPECT_EQ(stack.top(), 10);

    stack.push(20);

    EXPECT_EQ(stack.top(), 20);

    stack.push(30);

    EXPECT_EQ(stack.top(), 30);
    //ADD_FAILURE();
}

TEST(StackTest, PopRemovesTopElement)
{
    Stack<int, std::vector> stack;
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

TEST(StackTest, PopOnEmptyStackThrowsException)
{
    Stack<int, std::vector> stack;

    EXPECT_ANY_THROW(stack.pop());
    //ADD_FAILURE();
}

TEST(StackTest, TopOnEmptyStackThrowsException)
{
    Stack<int, std::vector> stack;

    EXPECT_ANY_THROW(stack.top());
    //ADD_FAILURE();
}

TEST(StackTest, ClearMakesStackEmpty)
{
    Stack<int, std::vector> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_FALSE(stack.empty());

    stack.clear();

    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
    //ADD_FAILURE();
}

TEST(StackTest, StackWorksWithDifferentDataTypes)
{
    Stack<std::string, std::vector> stack;
    stack.push("hello");
    stack.push("world");

    EXPECT_EQ(stack.top(), "world");

    stack.pop();

    EXPECT_EQ(stack.top(), "hello");
    //ADD_FAILURE();
}

TEST(StackTest, MultiplePushPopOperations)
{
    Stack<int, std::vector> stack;

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

