#include "queue.h"

#include <gtest.h>

TEST(QueueTest, DefaultConstructorCreatesEmptyQueue)
{
    Queue<int, std::vector> queue;

    EXPECT_TRUE(queue.empty());
    EXPECT_EQ(queue.size(), 0);
    //ADD_FAILURE();
}

TEST(QueueTest, PushIncreasesSize)
{
    Queue<int, std::vector> queue;
    queue.push(1);

    EXPECT_FALSE(queue.empty());
    EXPECT_EQ(queue.size(), 1);

    queue.push(2);

    EXPECT_EQ(queue.size(), 2);
    //ADD_FAILURE();
}

TEST(QueueTest, FrontReturnsFirstElement)
{
    Queue<int, std::vector> queue;

    queue.push(10);

    EXPECT_EQ(queue.front(), 10);

    queue.push(20);

    EXPECT_EQ(queue.front(), 10);

    queue.push(30);

    EXPECT_EQ(queue.front(), 10);
    //ADD_FAILURE();
}

TEST(QueueTest, BackReturnsLastElement)
{
    Queue<int, std::vector> queue;

    queue.push(10);

    EXPECT_EQ(queue.back(), 10);

    queue.push(20);

    EXPECT_EQ(queue.back(), 20);

    queue.push(30);

    EXPECT_EQ(queue.back(), 30);
    //ADD_FAILURE();
}

TEST(QueueTest, PopRemovesFrontElement)
{
    Queue<int, std::vector> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    EXPECT_EQ(queue.front(), 1);

    queue.pop();

    EXPECT_EQ(queue.front(), 2);
    EXPECT_EQ(queue.size(), 2);

    queue.pop();

    EXPECT_EQ(queue.front(), 3);
    EXPECT_EQ(queue.size(), 1);
    //ADD_FAILURE();
}

TEST(QueueTest, PopOnEmptyQueueThrowsException)
{
    Queue<int, std::vector> queue;

    EXPECT_ANY_THROW(queue.pop());
    //ADD_FAILURE();
}

TEST(QueueTest, FrontOnEmptyQueueThrowsException)
{
    Queue<int, std::vector> queue;

    EXPECT_ANY_THROW(queue.front());
    //ADD_FAILURE();
}

TEST(QueueTest, BackOnEmptyQueueThrowsException)
{
    Queue<int, std::vector> queue;

    EXPECT_ANY_THROW(queue.back());
    //ADD_FAILURE();
}

TEST(QueueTest, ClearMakesQueueEmpty)
{
    Queue<int, std::vector> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    EXPECT_FALSE(queue.empty());

    queue.clear();

    EXPECT_TRUE(queue.empty());
    EXPECT_EQ(queue.size(), 0);
    //ADD_FAILURE();
}

TEST(QueueTest, QueueWorksWithDifferentDataTypes)
{
    Queue<std::string, std::vector> queue;
    queue.push("hello");
    queue.push("world");

    EXPECT_EQ(queue.front(), "hello");
    EXPECT_EQ(queue.back(), "world");

    queue.pop();

    EXPECT_EQ(queue.front(), "world");
    //ADD_FAILURE();
}

TEST(QueueTest, MultiplePushPopOperations)
{
    Queue<int, std::vector> queue;

    for (int i = 0; i < 100; ++i)
    {
        queue.push(i);
        EXPECT_EQ(queue.back(), i);
        EXPECT_EQ(queue.front(), 0);
    }
    EXPECT_EQ(queue.size(), 100);

    for (int i = 0; i < 100; ++i)
    {
        EXPECT_EQ(queue.front(), i);
        queue.pop();
    }
    //ADD_FAILURE();
}

TEST(QueueTest, QueueMaintainsFIFOOrder)
{
    Queue<int, std::vector> queue;

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

TEST(QueueTest, SmenyaemiePushPopOperations)
{
    Queue<int, std::vector> queue;

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

