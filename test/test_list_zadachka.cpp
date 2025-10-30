#include "list_zadacha.h"
#include "list.h"
#include "string.h"

#include <gtest.h>

TEST(ListZadachaTest, DetectsWhenListIfEmpty)
{
    ForwardList<int> list;
    auto result = ZadachaNumberSixteen(list.begin());

    EXPECT_EQ(result, list.begin());
    //ADD_FAILURE();
}
TEST(ListZadachaTest, DetectsSelfCycle)
{
    ForwardList<char> list;
    list.push_front('F');
    auto tmp = list.begin();
    tmp.iter->next = list.begin().iter;
    auto result = ZadachaNumberSixteen(list.begin());

    EXPECT_EQ(result, list.begin());
    EXPECT_EQ(*result, list.begin().iter->data);
    tmp.iter->next = nullptr; //DEL = MEMLEAK
    //ADD_FAILURE();
}
TEST(ListZadachaTest, DetectsCycleReturnsStartOfTheCycle)
{
    int size = 10;
    ForwardList<int> list;
    for (size_t i = 0; i < size; i++)
    {
        list.push_front(size - i - 1);
    }
    auto tmp = list.atIndex(size - 1);
    tmp.iter->next = list.atIndex(size - 1 - 2).iter; // 0 1 2 3 4 5 6 7 8 9; 9->7
    auto result = ZadachaNumberSixteen(list.begin());

    EXPECT_EQ(result, list.atIndex(size - 1 - 2));
    EXPECT_EQ(*result, list.atIndex(size - 1 - 2).iter->data);
    tmp.iter->next = nullptr; //Нам же не нужны утечки памяти)
    //ADD_FAILURE();
}
TEST(ListZadachaTest, DetectsNoCycle)
{
    int size = 10;
    ForwardList<int> list;
    for (size_t i = 0; i < size; i++)
    {
        list.push_front(size - i - 1); // 0 1 2 3 4 5 6 7 8 9
    } 
    auto result = ZadachaNumberSixteen(list.begin());

    EXPECT_EQ(result, list.end());
    //ADD_FAILURE();
}
TEST(ListZadachaTest, DetectsDifferentCyclesCorrectly)
{
    int size1 = 5;
    int size2 = 20;
    int size3 = 30;
    ForwardList<int> list1;
    for (size_t i = 0; i < size1; i++)
    {
        list1.push_front(size1 - i - 1);
    }
    ForwardList<int> list2;
    for (size_t i = 0; i < size2; i++)
    {
        list2.push_front(size2 - i - 1);
    }
    ForwardList<int> list3;
    for (size_t i = 0; i < size3; i++)
    {
        list3.push_front(size3 - i - 1);
    }

    auto SledZapomnit1 = list1.atIndex(size1 - 1 - 2 + 1);
    auto tmp1 = list1.atIndex(size1 - 1 - 2);
    tmp1.iter->next = list1.atIndex(size1 - 1 - 2).iter;
    auto result1 = ZadachaNumberSixteen(list1.begin());

    EXPECT_EQ(result1, list1.atIndex(size1 - 1 - 2));
    EXPECT_EQ(*result1, list1.atIndex(size1 - 1 - 2).iter->data);
    tmp1.iter->next = SledZapomnit1.iter; //DEL = MEMLEAK

    auto SledZapomnit2 = list2.atIndex(size2 - 1 - 8 + 1);
    auto tmp2 = list2.atIndex(size2 - 1 - 8);
    tmp2.iter->next = list2.atIndex(size2 - 1 - 13).iter;
    auto result2 = ZadachaNumberSixteen(list2.begin());

    EXPECT_EQ(result2, list2.atIndex(size2 - 1 - 13));
    EXPECT_EQ(*result2, list2.atIndex(size2 - 1 - 13).iter->data);
    tmp2.iter->next = SledZapomnit2.iter; //DEL = MEMLEAK

    auto SledZapomnit3 = list3.atIndex(size3 - 1 - 3 + 1);
    auto tmp3 = list3.atIndex(size3 - 1 - 3);
    tmp3.iter->next = list3.atIndex(size3 - 1 - 25).iter;
    auto result3 = ZadachaNumberSixteen(list3.begin());

    EXPECT_EQ(result3, list3.atIndex(size3 - 1 - 25));
    EXPECT_EQ(*result3, list3.atIndex(size3 - 1 - 25).iter->data);
    tmp3.iter->next = SledZapomnit3.iter; //DEL = MEMLEAK
    //ADD_FAILURE();
}