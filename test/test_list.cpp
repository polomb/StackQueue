#include "list.h"

#include <gtest.h>

TEST(ListTest, DefaultConstructorCreatesEmptyList)
{
    ForwardList<int> list;

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
    //ADD_FAILURE();
}

TEST(ListTest, ConstructorWith_N_ElementCreates_N_ElementList)
{
    int N = 10;
    ForwardList<int> list(N, 5);

    EXPECT_FALSE(list.empty());
    EXPECT_EQ(list.size(), N);
    //ADD_FAILURE();
}

TEST(ListTest, PushFrontIncreasesSize)
{
    ForwardList<int> list;

    list.push_front(1);

    EXPECT_FALSE(list.empty());
    EXPECT_EQ(list.size(), 1);

    list.push_front(2);

    EXPECT_EQ(list.size(), 2);
    //ADD_FAILURE();
}

TEST(ListTest, FrontReturnsLastPushedElement)
{
    ForwardList<int> list;

    list.push_front(10);

    EXPECT_EQ(list.front(), 10);

    list.push_front(20);

    EXPECT_EQ(list.front(), 20);

    list.push_front(30);

    EXPECT_EQ(list.front(), 30);
    //ADD_FAILURE();
}

TEST(ListTest, PopFrontRemovesFrontElement)
{
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    list.pop_front();

    EXPECT_EQ(list.front(), 2);
    EXPECT_EQ(list.size(), 2);

    list.pop_front();

    EXPECT_EQ(list.front(), 1);
    EXPECT_EQ(list.size(), 1);
    //ADD_FAILURE();
}

TEST(ListTest, FrontOnEmptyListThrowsException)
{
    ForwardList<int> list;

    EXPECT_ANY_THROW(list.front());
    //ADD_FAILURE();
}

TEST(ListTest, ClearMakesListEmpty)
{
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    EXPECT_FALSE(list.empty());

    list.clear();

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
    //ADD_FAILURE();
}

TEST(ListTest, ListWorksWithDifferentDataTypes)
{
    ForwardList<std::string> list;
    list.push_front("hello");
    list.push_front("world");

    EXPECT_EQ(list.front(), "world");

    list.pop_front();

    EXPECT_EQ(list.front(), "hello");
    //ADD_FAILURE();
}

TEST(ListTest, MultiplePushFrontPopFrontOperations)
{
    ForwardList<int> list;

    for (int i = 0; i < 100; ++i)
    {
        list.push_front(i);
        EXPECT_EQ(list.front(), i);
    }
    EXPECT_EQ(list.size(), 100);

    for (int i = 99; i >= 0; --i)
    {
        EXPECT_EQ(list.front(), i);
        list.pop_front();
    }
    //ADD_FAILURE();
}

TEST(ListTest, InsertAfterIncreasesSizeAndWorksCorrectly)
{
    ForwardList<int> list;
    for (size_t i = 5; i > 0; i--)
    {
        list.push_front(i);
    }
    auto it = list.atIndex(3);
    list.insert_after(it, 10);

    EXPECT_EQ(list.size(), 6);
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 3);
    EXPECT_EQ(list[3], 4);
    EXPECT_EQ(list[4], 10);
    EXPECT_EQ(list[5], 5);
    //ADD_FAILURE();
}

TEST(ListTest, EraseAfterDecreasesSizeAndWorksCorrectly)
{
    ForwardList<int> list;
    for (size_t i = 5; i > 0; i--)
    {
        list.push_front(i);
    }
    auto it = list.atIndex(2);
    list.erase_after(it);

    EXPECT_EQ(list.size(), 4);
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 3);
    EXPECT_EQ(list[3], 5);
    //ADD_FAILURE();
}

TEST(ListTest, IteratorOperationsWorkCorrectly)
{
    ForwardList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    auto it = list.begin();

    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(it, list.end());
    //ADD_FAILURE();
}

TEST(ListTest, CopyConstructorCreatesIndependentCopy)
{
    ForwardList<int> org;
    org.push_front(3);
    org.push_front(2);
    org.push_front(1);
    ForwardList<int> cpy(org);

    EXPECT_EQ(org.size(), cpy.size());
    EXPECT_EQ(org.front(), cpy.front());

    org.pop_front();
    EXPECT_EQ(org.front(), 2);
    EXPECT_EQ(cpy.front(), 1);
    EXPECT_EQ(org.size(), 2);
    EXPECT_EQ(cpy.size(), 3);
    //ADD_FAILURE();
}

TEST(ListTest, AssignmentOperatorCreatesIndependentCopy)
{
    ForwardList<int> org;
    org.push_front(3);
    org.push_front(2);
    org.push_front(1);
    ForwardList<int> asign;
    asign = org;

    EXPECT_EQ(org.size(), asign.size());
    EXPECT_EQ(org.front(), asign.front());
    org.pop_front();
    EXPECT_EQ(org.front(), 2);
    EXPECT_EQ(asign.front(), 1);
    //ADD_FAILURE();
}

TEST(ListTest, MoveConstructorTransfersOwnership)
{
    ForwardList<int> org;
    org.push_front(3);
    org.push_front(2);
    org.push_front(1);
    size_t orgSize = org.size();
    ForwardList<int> moved(std::move(org));

    EXPECT_EQ(moved.size(), orgSize);
    EXPECT_FALSE(moved.empty());
    EXPECT_TRUE(org.empty());
    EXPECT_EQ(org.size(), 0);
    //ADD_FAILURE();
}

TEST(ListTest, MoveAssignmentOperatorTransfersOwnership)
{
    ForwardList<int> org;
    org.push_front(3);
    org.push_front(2);
    org.push_front(1);
    size_t orgSize = org.size();
    ForwardList<int> moved;
    moved = std::move(org);

    EXPECT_EQ(moved.size(), orgSize);
    EXPECT_FALSE(moved.empty());
    EXPECT_TRUE(org.empty());
    EXPECT_EQ(org.size(), 0);
    //ADD_FAILURE();
}

TEST(ListTest, AccessOperatorWorksCorrectly)
{
    ForwardList<int> list;
    for (int i = 0; i < 3; ++i)
    {
        list.push_front(i);
    }

    EXPECT_EQ(list[0], 2);
    EXPECT_EQ(list[1], 1); 
    EXPECT_EQ(list[2], 0);
    //ADD_FAILURE();
}

TEST(ListTest, AtMethodThrowsExceptionForInvalidIndex)
{
    ForwardList<int> list;
    list.push_front(1);

    EXPECT_NO_THROW(list.at(0));
    EXPECT_ANY_THROW(list.at(1));
    EXPECT_ANY_THROW(list.at(10));
    //ADD_FAILURE();
}

TEST(ListTest, ClearOnEmptyListDoesNothing)
{
    ForwardList<int> list;

    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
    EXPECT_NO_THROW(list.clear());
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
    //ADD_FAILURE();
}